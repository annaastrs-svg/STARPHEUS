STARPHEUS BOT
----

(foto proyecto completo)

Orpheus Bot It's a robot inspired by the Hack Club mascot (Orpheus).
Starpheus is a Wall-E type robot.
You can control it with a LogiTECH controller (you control its neck with an MG996R servo motor and the TT motors). 
It has 3 OLEDs that make up its eyes and mouth, simulates emotions with basic state machines (scared, happy, sleepy, neutral),
and uses an HC ultrasonic sensor to avoid collisions.
NOTE: this is a rlly full demo jsjjs 

Design
-------
The complete BOT is 31 cm tall, and 31 cm long counting the arms, its designed to look cool (idk if it is,for me it is), i wanted it to be like a Walle-E type.


<img width="1583" height="1025" alt="Captura de pantalla 2026-06-25 231214" src="https://github.com/user-attachments/assets/5b45980b-86ec-43b7-99fd-ab6a43da7123" />
The design was made so that our little Starpheus isn't heavy and has good mobility.

It has details to be able to put our components and hollow parts so that the chassis isn't heavy and has more mobility, as I already mentioned.

details:

holes for 3 OLED screens (2x 0.96 & 0.91 )
a reset button at the back
the ESP32-S3 connector at the back
the ultrasonic sensor in the front
and spots to attach the motors.

I'm an amateur, this is my biggest solo project so far, and I like to challenge myself.
Honestly, I struggled a lot with this project. I changed everything from one moment to the next thousands of times. It was going to have computer vision and an infrared sensor so you could pet it, it was going to be semi-autonomous, but it was very ambitious. This is the beginning of Starpheus; in the future, I’ll improve it and all these ideas will be more than just ideas. 


foto proyecto completo) 

Gallery 
--

PCB
---
<img width="650" height="642" alt="esquema" src="https://github.com/user-attachments/assets/c567d5f9-156c-44a7-b191-5b3382d18e65" />


<img width="1277" height="881" alt="esq" src="https://github.com/user-attachments/assets/304f0cc7-0606-48bf-84ae-abe0fbb28c1d" />


<img width="1918" height="1198" alt="Captura de pantalla 2026-06-24 214031" src="https://github.com/user-attachments/assets/6bb2b666-d774-465c-a368-070cd27421a1" />

CAD
---
<img width="751" height="978" alt="Captura de pantalla 2026-06-25 231259" src="https://github.com/user-attachments/assets/6189a05b-a693-42e1-bee5-32ee504c322e" />
<img width="1551" height="993" alt="Captura de pantalla 2026-06-25 225029" src="https://github.com/user-attachments/assets/bb8e06e1-9721-43c4-82b5-8ffb87222979" />
<img width="822" height="742" alt="Captura de pantalla 2026-06-25 231134" src="https://github.com/user-attachments/assets/3e80a1ba-ec18-4bc6-8048-4add605c5daa" />


I made this EXCEL with all the connections :B

BOM 
--
| Component         | Description                                | Unit | Cost    | Distibutor    | Link                                                                                                                                                                        |
|-------------------|--------------------------------------------|------|---------|---------------|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| ESP32-S3          | Micro Controler, send code to components   | 1    | $34.91  | AlliExpress        | https://es.aliexpress.com/item/1005009212121307.html?src=bing&exp_tag=pcgcp&albch=shopping&acnt=135095331&albcp=555291703&albag=1299623925852708&slnk=&trgt=pla-2333026235563924&plac=&crea=81226553419370&netw=o&device=c&mtctp=e&utm_source=Bing&utm_medium=shopping&utm_campaign=PA_Bing_MX_Pmax_3C_MAXvalue_20250206_newstore&utm_content=3C&utm_term=ESP32-S3&msclkid=053bb998d0691e21b9cbd3a79d374743&aff_fcid=c5ba799bdfd04e76ae5a24437fb695cd-1782533500453-03069-UneMJZVf&aff_fsk=UneMJZVf&aff_platform=aaf&sk=UneMJZVf&aff_trace_key=c5ba799bdfd04e76ae5a24437fb695cd-1782533500453-03069-UneMJZVf&terminal_id=5927158648684954809663ec4040b6d2&afSmartRedirect=n&gatewayAdapt=glo2esp  |
| DRV8833           | H bridge for motors and control PWM        | 1    | $111.00 | AlliExpress   | https://es.aliexpress.com/item/1005006151344347.html?src=bing&exp_tag=pcgcp&albch=shopping&acnt=135095331&albcp=555291703&albag=1299623925852708&slnk=&trgt=pla-2333026235563924&plac=&crea=81226553419370&netw=o&device=c&mtctp=e&utm_source=Bing&utm_medium=shopping&utm_campaign=PA_Bing_MX_Pmax_3C_MAXvalue_20250206_newstore&utm_content=3C&utm_term=drv8833+bateria+pinout&msclkid=bc6fd8323a4012783781b20d77d54aed&aff_fcid=9159e0ecdd304c6abaf17352f823a6c3-1782533528389-07870-UneMJZVf&aff_fsk=UneMJZVf&aff_platform=aaf&sk=UneMJZVf&aff_trace_key=9159e0ecdd304c6abaf17352f823a6c3-1782533528389-07870-UneMJZVf&terminal_id=5927158648684954809663ec4040b6d2&afSmartRedirect=n&gatewayAdapt=glo2esp |
| OLED.96           | Display, shows data (orpheus eyes)         | 2    | $4.49   | Mercado Libre | https://articulo.mercadolibre.com.mx/MLM-705156753-display-pantalla-oled-128x64-096-para-arduino-_JM?searchVariation=63044404311                                            |
| OLED.91           | Display, shows data (orpheus mouth)        | 1    | $1.31   |   MercadoLibre   |https://www.mercadolibre.com.mx/pantalla-oled-azul-128x32-i2c-091/p/MLM2068167145?pdp_filters=item_id%3AMLM1478945642&from=gshop&matt_tool=15920969&matt_word=&matt_source=microsoft&matt_campaign_id=571305430&matt_ad_group_id=1177579225794197&matt_match_type=e&matt_network=o&matt_device=c&matt_creative=&matt_keyword=&matt_ad_position=&matt_ad_type=&matt_merchant_id=50038545&matt_product_id=MLM2068167145-product&matt_product_partition_id=4577198197450241&matt_target_id=pla-4577198197450241&msclkid=9ee6e6b3969d135712098c8cd8b2aa43&utm_source=bing&utm_medium=cpc&utm_campaign=MLM_ML_BING_AO_CE-ALL-ALL_X_PLA_ALLB_TXS_ALL&utm_term=4577198197450241&utm_content=CE|
| HC-SR04           | Ultra sonic sensor, meausres distance      | 1    | $2.96   | Mercado Libre |https://www.mercadolibre.com.mx/sensor-de-distancia-hc-sr04-ultrasonico/p/MLM2039690988?pdp_filters=item_id%3AMLM571261161&from=gshop&matt_tool=15920969&matt_word=&matt_source=microsoft&matt_campaign_id=571305430&matt_ad_group_id=1177579225794197&matt_match_type=e&matt_network=o&matt_device=c&matt_creative=&matt_keyword=&matt_ad_position=&matt_ad_type=&matt_merchant_id=50038545&matt_product_id=MLM2039690988-product&matt_product_partition_id=4577198197450205&matt_target_id=pla-4577198197450205&msclkid=7707b5d9707f1734f956dfe63e3cd614&utm_source=bing&utm_medium=cpc&utm_campaign=MLM_ML_BING_AO_CE-ALL-ALL_X_PLA_ALLB_TXS_ALL&utm_term=4577198197450205&utm_content=CE|

| MG-996R           | Servo Motor, orpheus neck                  | 1    | $7.33   | Amazon | https://www.amazon.com.mx/MG996R-55G-servomotor-Helic%C3%B3ptero-Arduino/dp/B0D7M2Y2BR/ref=asc_df_B0D7M2Y2BR?tag=mxbngshpdsk-20&linkCode=df0&hvadid=82395061852819&hvnetw=o&hvqmt=e&hvbmt=be&hvdev=c&hvlocint=&hvlocphy=151131&hvtargid=pla-4585994287787208&psc=1&msclkid=e6a7df47010d115d6c8eb5784f56fd7d  |
| tt engines        | Movement or orpheus bot                    | 2    | $4.00   | AlliExpress   | https://es.aliexpress.com/item/1005010779121177.html?src=bing&exp_tag=pcgcp&albch=shopping&acnt=135095331&albcp=555291703&albag=1299623925852708&slnk=&trgt=pla-2333026235563924&plac=&crea=81226553419370&netw=o&device=c&mtctp=e&utm_source=Bing&utm_medium=shopping&utm_campaign=PA_Bing_MX_Pmax_3C_MAXvalue_20250206_newstore&utm_content=3C&utm_term=motores+tt&msclkid=4604d372fbfe14c3e344b94db561072e&aff_fcid=906d11c52e1f4a55975907ebcbe682d9-1782533793058-08454-UneMJZVf&aff_fsk=UneMJZVf&aff_platform=aaf&sk=UneMJZVf&aff_trace_key=906d11c52e1f4a55975907ebcbe682d9-1782533793058-08454-UneMJZVf&terminal_id=5927158648684954809663ec4040b6d2&afSmartRedirect=n&gatewayAdapt=glo2esp|
| buck converters   | For Voltage Protecction of the components  | 3    | $6.76   | Amazon   |  https://www.amazon.com.mx/Converter-Aumento-Ajustable-Reguladora-Conector/dp/B09Q8YTQXB/ref=sr_1_8?adgrpid=1165484206288746&dib=eyJ2IjoiMSJ9.TruDAKrU15d416ylBh8ulJJTz2d1TfT8EN7e9dJkodyHHH1od58L1fPMujRYPdf-iyD65iDMp7quqMR4rHF_oqQ558FzdXad7U6iBqxnKLUVJht0rHOsNf8Z6rRik0cXkLeRpQ79jHSn8AZXH9v3RqYukknHhFHUJGS6Di-PsSoyVzjTEjihnYqx9SSuxegqpyq5nz4iXMXztNyK1VH4imimK-kbHgfz2UMPh53j9DiQde3CUSugjy8Pt4Wz_rNj58OK0C-VWZDV5O15XB4WieNaAyq5raAqeb0MVdrpo1Y.y5zIeOKKhuF_8CNMwzP23gZmRT9i20QQBFSd3UYRtRU&dib_tag=se&hvadid=72843055995125&hvbmt=be&hvdev=c&hvlocphy=151131&hvnetw=o&hvqmt=e&hvtargid=kwd-72843484889146%3Aloc-119&hydadcr=14088_13417505&keywords=buck+converter&mcid=dc583b2887ca38368f6f683dde6ef2f0&msclkid=d19ed79b5dba1030403cbda4130e4359&qid=1782533818&sr=8-8&ufe=app_do%3Aamzn1.fos.de93fa6a-174c-4df7-be7c-5bc8e9c5a71b |
| Resistors 1k      | Kit of resistores, It helps with voltages  | 3    | $1.67   | Amazon   |https://www.amazon.com.mx/Resistencias-Metal-Film-Resistencia-Electr%C3%B3nicos/dp/B0CT529YD5/ref=sr_1_1_sspa?adgrpid=1166582601138475&dib=eyJ2IjoiMSJ9.NBcDPJqTYOjth7gdSySQirqF57sxDL8VWFTI05vC9nj6McOg-YSBZe8EXRi0eC_2E7MKzibLxM7QeVHcHB-Ko1-ebCdCLmKiHIZk1JfymyTa8jkAW23FNCHLAMJkkHtmW02T_EOZNTaL9eMtZ01eDVyzcTlr31lhvyVbtM1L0ijvk4gIRgnyGEiU9Rh7HpPkpj4SuspiLWUM5Q-W2VtRxNUT5J1G7SqDUZ1eaECu0euRlOkuUC3OyOBl_NhPJ95YzFsbwiseZHjBIxn4nGSkh16EDyRwq-q83riR1-KiOHo.1nvw0EbnL_xicWZ96wra5RXpQehdrYCikaisVadVuLE&dib_tag=se&hvadid=72911645984567&hvbmt=be&hvdev=c&hvlocphy=151131&hvnetw=o&hvqmt=e&hvtargid=kwd-72911986116600%3Aloc-119&hydadcr=11033_13513854&keywords=resistor+1k+ohm&mcid=bc221745620433ce85d0638f9c2af89e&msclkid=87cf17f18a9a186803f37dcec453b658&qid=1782533835&sr=8-1-spons&ufe=app_do%3Aamzn1.fos.de93fa6a-174c-4df7-be7c-5bc8e9c5a71b&sp_csd=d2lkZ2V0TmFtZT1zcF9hdGY&psc=1 |
| Capacitores 470uf | Kit of Capacitores, It helps with voltages | 3    | $1.21   | AlliExpress   | https://es.aliexpress.com/item/1005006079381755.html?src=bing&exp_tag=pcgcp&aff_fcid=30b0bfb162a64103b8094d08710fba9a-1782533862684-02992-UneMJZVf&aff_fsk=UneMJZVf&aff_platform=aaf&sk=UneMJZVf&aff_trace_key=30b0bfb162a64103b8094d08710fba9a-1782533862684-02992-UneMJZVf&terminal_id=5927158648684954809663ec4040b6d2&afSmartRedirect=n&gatewayAdapt=glo2esp|
| Potobard          | Helps With the wiring                      | 1    | $3.41   | Amazon   | https://www.amazon.com.mx/Protoboard-MB-102-Prototipo-soldadura-unidades/dp/B08BCLRLTQ/ref=asc_df_B08BCLRLTQ?tag=mxbngshpdsk-20&linkCode=df0&hvadid=82944817571862&hvnetw=o&hvqmt=e&hvbmt=be&hvdev=c&hvlocint=&hvlocphy=151131&hvtargid=pla-4586544042717891&psc=1&msclkid=0dd1b50556fd178a90addf3a180881ad  |
| Wires Dupont      | Kit, Conects the components                | 1    | $1.79   | Amazon   | https://www.amazon.com.mx/Cables-Pruebas-Opcionales-Surtido-Multicolor/dp/B0DKD315BQ/ref=asc_df_B0DKD315BQ?tag=mxbngshpdsk-20&linkCode=df0&hvadid=82738659152219&hvnetw=o&hvqmt=e&hvbmt=be&hvdev=c&hvlocint=&hvlocphy=151131&hvtargid=pla-4586337884680739&psc=1&msclkid=e88ac20d4e861fde514ea832018665df |
| Push Botton       | I added for a RST button of ESP32 ()       | 1    | $3.35   | Ebay |     https://www.ebay.com/itm/376667835321?chn=ps&_trkparms=ispr%3D1&amdata=enc%3A1-WCPs7ILQcmM3srRcIAPjQ30&norover=1&mkevt=1&mkrid=711-170539-829218-7&mkcid=2&itemid=376667835321&targetid=4580290580883290&device=c&mktype=&googleloc=151131&poi=&campaignid=605836810&mkgroupid=1227056202074386&rlsatarget=pla-4580290580883290&abcId=&merchantid=51291&msclkid=44e01bfe6e771c83f5b171c1217a5493 |

There are a lot of components, it's a bit tedious but worth it. I will implement an ESP32 Cam in the future and they cost 3 bucks because I have a spare one. I recommend buying lots of batteries!!

ASSEMBLY 
---

| Orpheus Connections |                 |              |              |           |   |           |                 |                 |             |              |                 |
|---------------------|-----------------|--------------|--------------|-----------|---|-----------|-----------------|-----------------|-------------|--------------|-----------------|
| Come From           |                 | Goes To      |              |           |   | Come From |                 | Goes To         |             | Goes To      |                 |
| Component           |             Pin | Component    | Pin          |           |   | Component |             Pin | Component       | Pin         | Component    |             Pin |
| ESP32 S3            | 9               | OLED 1       | SCK          |           |   | Buck 2    | out +           | Capacitor 470uf | Positive +  | MG996R       | 5V              |
| ESP32 S3            | 8               | OLED 1       | SDA          |           |   |           |                 | Capacitor 470uf | Negative -  | Protoboard 1 | Negative        |
| ESP32 S3            | 14              | MG996R       | S            |           |   | Buck 2    | out -           | Protoboard1     | Negative -  |              |                 |
| ESP32 S3            | 10              | OLED 2       | SDA          |           |   | Buck 2    | in +            | Protoboard 2    | Positive +  |              |                 |
| ESP32 S3            | 11              | OLED 2       | SCK          |           |   | Buck 2    | in -            | Protoboard1     | Negative -  |              |                 |
| ESP32 S3            | 38              | OLED 3       | SDA          |           |   |           |                 |                 |             |              |                 |
| ESP32 S3            | 39              | OLED 3       | SCK          |           |   | Buck 1    | out +           | Capacitor 470uf | Positive +  | DRV8833      | 5V              |
| ESP32 S3            | 15              | DRV8833      | IN1          | A         |   |           |                 | Capacitor 470uf | Negative -  | Protoboard 1 | Negative        |
| ESP32 S3            | 16              | DRV8833      | IN2          | A         |   | Buck 1    | out -           | Protoboard 1    | Negative    |              |                 |
| ESP32 S3            | 17              | DRV8833      | IN3          | B         |   | Buck 1    | in +            | Protoboard 2    | Positive +  |              |                 |
| ESP32 S3            | 18              | DRV8833      | IN4          | B         |   | Buck 1    | in-             | Protoboard 1    | Negative -  |              |                 |
| ESP32 S3            | 5               | HC-SR04      | TRIG         |           |   |           |                 |                 |             |              |                 |
| ESP32 S3            | 6               | R1 (1ohm)    | ECHO         | R2 (2ohm) |   | BATTERY   | OUT +           | Protoboard 2    | Positive +  |              |                 |
| MG996R              | GND             | Protoboard 1 | Negative -   |           |   | BATTERY   | OUT -           | Protoboard 1    | Negative -  |              |                 |
| OLED 0.96  (1 & 2)  | GND             | Protoboard 1 | Negative -   |           |   |           |                 |                 |             |              |                 |
| OLED 0.96  (1 & 2)  | 5V              | Protoboard 1 | Positive +   |           |   |           |                 |                 |             |              |                 |
| OLED 0.91           | GND             | Protoboard 1 | Negative -   |           |   |           |                 |                 |             |              |                 |
| OLED 0.91           | 5V              | Protoboard 1 | Positive +   |           |   |           |                 |                 |             |              |                 |
| HC-SR04             | GND             | Protoboard 1 | Negative -   |           |   |           |                 |                 |             |              |                 |
| DRV8833             | GND             | Protoboard 1 | Negative -   |           |   |           |                 |                 |             |              |                 |
| DRV8833             | OUT1            | MOTOR A      | NO POLARIDAD |           |   |           |                 |                 |             |              |                 |
| DRV8833             | OUT2            | MOTOR A      | NO POLARIDAD |           |   |           |                 |                 |             |              |                 |
| DRV8833             | OUT3            | MOTOR B      | NO POLARIDAD |           |   |           |                 |                 |             |              |                 |
| DRV8833             | OUT4            | MOTOR B      | NO POLARIDAD |           |   |           |                 |                 |             |              |                 |
|                     |                 |              |              |           |   |           |                 |                 |             |              |                 |
|                     |                 |              |              |           |   |           |                 |                 |             |              |                 |
|                     |                 |              |              |           |   |           |                 |                 |             |              |                 |
|                     |                 |              |              |           |   |           |                 |                 |             |              |                 |
|                     |                 |              |              |           |   |           |                 |                 |             |              |                 |
|                     |                 |              |              |           |   |           |                 |                 |             |              |                 |
|                     |                 |              |              |           |   |           |                 |                 |             |              |                 |


Wiring Little Tutorial, Moustly Explication
----

To build this, there are several things you need to take into account. 
First, the common GND that I implemented with my trusted protoboard: absolutely all the GNDs go to the negative of the protoboard. In the wiring table I made, it's the negative of protoboard 1.
I have divided my protoboard into two sections: the common GND and the 5V for the ESP, the OLEDs, and the ultrasonic sensor,
The second part is for connecting the battery directly and the IN+ of the buck converters, Why don't they go with the other components and get excluded? That's because if we put them together, we’ll damage the components, and that wouldn’t be good. Make sure everything is connected well because sometimes things get loose on the protoboard.  

It’s very logical; you need to make sure the circuit closes properly so it works, and what killed me the most in this project were the voltages, The recommended battery is 7.4V, but after 2 hours of testing it runs out. You can use 6 AA batteries in series or do what I did,I made a long cable by stripping one I had and adapted it to connect to Starpheus. It's like it has a strap, but it's really useful and functional if you're poor like me and can't be buying batteries every 3 hours.

Use 2 capacitors and 3 resistors, 1 capacitor of 470uF for the out+ of the two buck converters (motor and servomotor) so they don't cause power spikes. The resistors are for the ultrasonic sensor. I put a 1k resistor on the wire going from pin 5 of the ESP32S3 to the breadboard; one leg touches that wire directly and the other goes to another wire that goes to the echo of the HCSR04. On that same pin, I directly put two 1k resistors in series to make 2k, and the other leg goes to GND. This is so that the HCSR04 doesn't make too much noise since it's at 5V along with the OLEDs and the ESP32S3.  

Since we have many components drawing a lot of current, we have to consider the motors. In the math part, you need to know a bit about static friction and kinetic friction. Kinetic friction has to be greater than static friction because generally the coefficient of static friction is always higher than the kinetic one, so the motor force has to be greater than the maximum static friction force.

LICENSE
---
MIT

PS:(sorry for some gramatic errors and bad spelling, enlish is not my best lenguage)
thank you a lot hack club staff and people looking at this <3
