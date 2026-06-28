/*
 * STARPHEUS CONTROL - V2.0 Emociones y Arcade Drive
 * Control Arcade (Logitech) + Anti-friccion + Sistema de Emociones
 *
 * Trig=5 | Echo=6 | Motores DRV8833: 15, 16, 17, 18
 * Ojo izq: SDA=10 SCL=11 | Ojo der: SDA=38 SCL=39 | Boca: SDA=8 SCL=9
 */

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <U8g2lib.h>
#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "Starpheus_Bot";
const char* password = "123456789";
WebServer server(80);

// ===== Pantallas =====
TwoWire I2Cboca = TwoWire(0);
Adafruit_SSD1306 boca(128, 32, &I2Cboca, -1);
U8G2_SSD1306_128X64_NONAME_F_SW_I2C ojoIzq(U8G2_R0, 11, 10, U8X8_PIN_NONE);
U8G2_SSD1306_128X64_NONAME_F_SW_I2C ojoDer(U8G2_R0, 39, 38, U8X8_PIN_NONE);

// ===== Pines =====
#define IN1 15   // Motor IZQ adelante
#define IN2 16   // Motor IZQ atras
#define IN3 17   // Motor DER adelante
#define IN4 18   // Motor DER atras

#define TRIG_PIN 5
#define ECHO_PIN 6

// ===== Parametros de movimiento =====
const int PWM_FREQ = 5000;
const int PWM_RES = 8;              
const int JALON_PWM = 255;          
const unsigned long JALON_MS = 120; 

// ===== Anti-choque =====
const int DIST_PELIGRO = 12;        
const int DIST_DESPERTAR = 40;

// ===== Estado de control =====
int targetIzq = 0;     
int targetDer = 0;     
unsigned long ultimoComando = 0;
const unsigned long TIMEOUT_CTRL = 600;  

// ===== Variables de Logica =====
bool izqEnMovimiento = false;
bool derEnMovimiento = false;
unsigned long jalonIzqInicio = 0;
unsigned long jalonDerInicio = 0;

long distanciaActual = 999;
unsigned long ultimaMedicion = 0;

// ===== Temporizadores de Emocion =====
unsigned long tiempoQuieto = 0;
unsigned long tiempoRapido = 0;
unsigned long ultimoParpadeo = 0;

// Estados: 0=Idle, 1=Manual, 2=Dormido, 3=Asustado, 4=Euforico
int estadoActual = -1; 

void configMotores() {
  ledcAttach(IN1, PWM_FREQ, PWM_RES);
  ledcAttach(IN2, PWM_FREQ, PWM_RES);
  ledcAttach(IN3, PWM_FREQ, PWM_RES);
  ledcAttach(IN4, PWM_FREQ, PWM_RES);
}

long medirDistancia() {
  digitalWrite(TRIG_PIN, LOW); delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH); delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  uint32_t t = micros();
  while (digitalRead(ECHO_PIN) == LOW) { if (micros() - t > 8000) return 999; }
  uint32_t s = micros();
  while (digitalRead(ECHO_PIN) == HIGH) { if (micros() - s > 8000) return 999; }
  long d = (micros() - s) * 0.034 / 2;
  return (d < 2 || d > 300) ? 999 : d;
}

// Control seguro del motor con Jalón
void moverMotor(int potencia, int pinAdel, int pinAtras, bool &enMov, unsigned long &jalonInicio) {
  if (potencia == 0) {
    ledcWrite(pinAdel, 0);
    ledcWrite(pinAtras, 0);
    enMov = false;
    return;
  }

  if (!enMov) { enMov = true; jalonInicio = millis(); }
  
  bool enJalon = (millis() - jalonInicio < JALON_MS);
  int pwm = enJalon ? JALON_PWM : abs(potencia);

  if (potencia > 0) {
    ledcWrite(pinAtras, 0); // Apagar estricto el contrario primero
    ledcWrite(pinAdel, pwm);
  } else {
    ledcWrite(pinAdel, 0); // Apagar estricto el contrario primero
    ledcWrite(pinAtras, pwm);
  }
}

// ===== DIBUJOS DE OJOS =====
void dibujarOjo(U8G2 &o, int tipo) {
  o.clearBuffer(); o.setDrawColor(1);
  if (tipo == 0) { // Normal/Idle
    o.drawDisc(64,32,26); o.setDrawColor(0); o.drawDisc(72,24,9); o.drawDisc(56,40,4);
  } else if (tipo == 1) { // Manual/Atento
    o.drawBox(38,18,52,6); o.drawDisc(64,38,16); o.setDrawColor(0); o.drawDisc(64,38,7);
  } else if (tipo == 2) { // Dormido
    o.drawLine(34, 40, 94, 40); o.drawLine(34, 41, 94, 41);
  } else if (tipo == 3) { // Asustado (Pupila pequeñita)
    o.drawDisc(64, 32, 28); o.setDrawColor(0); o.drawDisc(64, 32, 24); 
    o.setDrawColor(1); o.drawDisc(64, 32, 5);
  } else if (tipo == 4) { // Euforico (Arcos felices ^_^)
    o.drawDisc(64, 40, 26); o.setDrawColor(0); o.drawDisc(64, 48, 26); 
  } else if (tipo == 5) { // Parpadeo
    o.drawBox(34,30,60,5);
  }
  o.sendBuffer();
}

// ===== DIBUJOS DE BOCA =====
void dibujarBoca(int tipo) {
  boca.clearDisplay();
  if (tipo == 0) { // Idle (V pequeña)
    boca.drawLine(54,12,64,22,SSD1306_WHITE); boca.drawLine(64,22,74,12,SSD1306_WHITE);
  } else if (tipo == 1) { // Manual (Linea concentrada)
    boca.fillRect(48,15,32,4,SSD1306_WHITE);
  } else if (tipo == 2) { // Dormido (Zzz)
    boca.setTextSize(2); boca.setTextColor(SSD1306_WHITE);
    boca.setCursor(44, 10); boca.print("Zzz");
  } else if (tipo == 3) { // Asustado (O perfecta)
    boca.drawCircle(64, 16, 12, SSD1306_WHITE);
  } else if (tipo == 4) { // Euforico (Sonrisa grande)
    boca.fillRoundRect(40, 8, 48, 16, 8, SSD1306_WHITE);
  }
  boca.display();
}

// Cambiador de estados
void cambiarCara(int nuevoEstado) {
  if (estadoActual == nuevoEstado) return;
  estadoActual = nuevoEstado;
  dibujarOjo(ojoIzq, nuevoEstado); dibujarOjo(ojoDer, nuevoEstado);
  dibujarBoca(nuevoEstado);
}

// ===== WEB Y CONTROL (ARCADE DRIVE JS) =====
void manejarControl() {
  if (server.hasArg("izq")) targetIzq = constrain(server.arg("izq").toInt(), -255, 255);
  if (server.hasArg("der")) targetDer = constrain(server.arg("der").toInt(), -255, 255);
  ultimoComando = millis();
  server.send(200, "text/plain", "OK");
}

void manejarRaiz() {
  String h = "<!DOCTYPE html><html lang='es'><head><meta charset='UTF-8'>";
  h += "<meta name='viewport' content='width=device-width,initial-scale=1,user-scalable=no'>";
  h += "<title>STARPHEUS</title><style>";
  h += "*{margin:0;padding:0;box-sizing:border-box;-webkit-tap-highlight-color:transparent;}";
  h += "body{background:#05070d;color:#d7e6ff;font-family:monospace;min-height:100vh;overflow:hidden;}";
  h += "h1{text-align:center;color:#2f8fff;padding:20px; font-size:2rem;}";
  h += "button{background:#0c1320;color:#d7e6ff;border:1px solid #26426e;font-size:1.3rem;border-radius:12px;cursor:pointer;}";
  h += "button:active{background:#2f8fff;}";
  h += ".pad{display:flex;flex-direction:column;align-items:center;gap:15px;padding:20px;}";
  h += ".dir{width:120px;height:80px;} .dpad{display:flex;gap:15px;}";
  h += ".stop{width:255px;height:70px;background:#ff4757;color:#fff;}";
  h += ".gp{text-align:center;color:#2f8fff;padding:20px; font-size: 0.8rem;}";
  h += "</style></head><body>";
  h += "<h1>STARPHEUS</h1>";
  h += "<div class='pad'>";
  h += "<button class='dir' ontouchstart='mover(180,180)' ontouchend='mover(0,0)'>Avanzar</button>";
  h += "<div class='dpad'>";
  h += "<button class='dir' ontouchstart='mover(-160,160)' ontouchend='mover(0,0)'>Izquierda</button>";
  h += "<button class='dir' ontouchstart='mover(160,-160)' ontouchend='mover(0,0)'>Derecha</button>";
  h += "</div>";
  h += "<button class='dir' ontouchstart='mover(-160,-160)' ontouchend='mover(0,0)'>Atras</button>";
  h += "<button class='stop' ontouchstart='mover(0,0)'>FRENAR</button>";
  h += "</div><div class='gp' id='gpinfo'>Conecta un mando Logitech</div>";

  h += "<script>";
  h += "let lastSend=0; function enviar(i,d){let now=Date.now();if(now-lastSend<40)return;lastSend=now;fetch('/control?izq='+i+'&der='+d).catch(e=>{});}";
  h += "function mover(i,d){enviar(i,d);} let gpActivo=false;";
  h += "window.addEventListener('gamepadconnected',(e)=>{gpActivo=true;document.getElementById('gpinfo').innerText='Gamepad: '+e.gamepad.id.substring(0,25);bucle();});";
  h += "function bucle(){if(!gpActivo)return;const gp=navigator.getGamepads()[0];if(gp){";
  h += "let y=-gp.axes[1]; let x=gp.axes[0];"; // Arcade Drive Logic
  h += "if(Math.abs(y)<0.15)y=0; if(Math.abs(x)<0.15)x=0;"; // Deadzone
  h += "let li=y+x; let ld=y-x;";
  h += "let mx=Math.max(1, Math.max(Math.abs(li), Math.abs(ld))); li/=mx; ld/=mx;";
  h += "enviar(Math.round(li*255), Math.round(ld*255));";
  h += "}requestAnimationFrame(bucle);}</script></body></html>";
  server.send(200, "text/html", h);
}

void setup() {
  Serial.begin(115200);
  pinMode(38, OUTPUT); digitalWrite(38, LOW); delay(10); pinMode(38, INPUT); // Liberar pin 38
  pinMode(TRIG_PIN, OUTPUT); pinMode(ECHO_PIN, INPUT);
  digitalWrite(TRIG_PIN, LOW);

  configMotores();
  
  I2Cboca.begin(8, 9);
  boca.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  ojoIzq.begin(); ojoDer.begin();

  WiFi.softAP(ssid, password);
  server.on("/", manejarRaiz); server.on("/control", manejarControl);
  server.begin();
  
  cambiarCara(0); // Inicia Idle
  tiempoQuieto = millis();
}

void loop() {
  server.handleClient();

  if (millis() - ultimaMedicion > 60) {
    distanciaActual = medirDistancia();
    ultimaMedicion = millis();
  }

  bool ctrlVivo = (millis() - ultimoComando < TIMEOUT_CTRL);
  int izq = ctrlVivo ? targetIzq : 0;
  int der = ctrlVivo ? targetDer : 0;

  bool peligro = (distanciaActual < DIST_PELIGRO);
  bool moviendo = (izq != 0 || der != 0);
  bool rapido = (abs(izq) >= 200 && abs(der) >= 200);

  // LOGICA ANTI-CHOQUE FRONTAL
  if (peligro && izq > 0 && der > 0) {
    izq = 0; der = 0; 
  }

  // APLICAR MOTORES
  moverMotor(izq, IN1, IN2, izqEnMovimiento, jalonIzqInicio);
  moverMotor(der, IN3, IN4, derEnMovimiento, jalonDerInicio);

  // ===== MAQUINA DE ESTADOS EMOCIONALES =====
  if (moviendo) {
    tiempoQuieto = millis(); // Resetea temporizador de sueño
    if (!rapido) tiempoRapido = millis(); // Solo acumula tiempo si va rapido
  } else {
    tiempoRapido = millis(); // Si se detiene, pierde la euforia
  }

  if (peligro) {
    cambiarCara(3); // Asustado
  } else if (moviendo && (millis() - tiempoRapido > 3000)) {
    cambiarCara(4); // Euforico despues de 3 seg rapido
  } else if (moviendo) {
    cambiarCara(1); // Manual/Atento
  } else {
    // Si no se esta moviendo
    if (millis() - tiempoQuieto > 5000) {
      if (distanciaActual > 0 && distanciaActual < DIST_DESPERTAR) {
        cambiarCara(0); // Alguien paso cerca, despierta a Idle
        tiempoQuieto = millis(); // Resetea el tiempo para que no se vuelva a dormir al instante
      } else {
        cambiarCara(2); // Dormido
      }
    } else {
      cambiarCara(0); // Idle normal
      
      // Parpadeo solo en Idle
      if (estadoActual == 0 && millis() - ultimoParpadeo > 3500 && random(0,100) < 30) {
        dibujarOjo(ojoIzq, 5); dibujarOjo(ojoDer, 5);
        delay(100);
        dibujarOjo(ojoIzq, 0); dibujarOjo(ojoDer, 0);
        ultimoParpadeo = millis();
      }
    }
  }
}
