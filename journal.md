A Walle-Etype companion robot inpired by Orpheus, the Hack Club mascot.
face, emotions, ultrasonic sensing and Logitech control.

STARPHEUS 
----
Anna Strs (annaastrs-svg)

2026-06-01

STARPHEUS JOURNAL !
---

starpheus bot is a robot inpired by orpheus, you can controll it, but he reacts to his enviroment with his face made by 3 OLEDS (1 per eye and 1 for mouth).

total time spent so far: ~70 hrs

THE IDEA
---

i love to build cute things that have its own "life" starpheus is interactive and has mobility. 
I dont remember exactly how or why i thought about orpheus.
The complete plan with starpheus was: computer vision, autonomus, curious and infrared sensors. 

STARPHEUS first sketchs:
---
<img width="652" height="876" alt="Captura de pantalla 2026-06-20 233143" src="https://github.com/user-attachments/assets/d101331e-7665-4d96-9c49-d91763c2d7b0" />
<img width="977" height="612" alt="Captura de pantalla 2026-06-21 210439" src="https://github.com/user-attachments/assets/0872a428-8367-4ea6-9feb-97c167a75056" />

The emotional Face
----

first thing i built was the face, two oleds were the start, one for mouth and other one for eyes, (I changed it cus it was too small)
the first state machine for emotions : neutral, sleepy, angry, heart face.

the challenge of this came after, the oleds share the same I2C adress (0x3C) so they fight if you put thwm on the same bus. i had to separate I2C buses. 

<img width="1125" height="816" alt="WhatsApp Image 2026-06-19 at 2 52 02 PM" src="https://github.com/user-attachments/assets/dc50aba2-7fa7-40b4-8e8c-c2011cced254" />

The neck servomotor
----

the mg9963 for the neck gave me SO much touble. It wouldnt move with low current, some thimes he dont even move...
i learned after 2 hours that:
it needs enough current 
it needs a capacitor 470uf or it browns out
loose wires ruin evrything....



The worst decision of my life (ESP32 CAM)
----

the idea of starpheus was to SEE YOU. computer vision was the goal. 
but it nnever worked at any point, because the camera I got was  CLONE, and it didnt work with any library,
I really tryed SO MUCH 😿 
in the end i made a hard decision. drop the camera and ude a ultrasonic sensor to detect presence instead.
the computer vision idea STAYS for future improvement.
<img width="582" height="610" alt="Captura de pantalla 2026-06-19 183814" src="https://github.com/user-attachments/assets/a4e278e0-b121-4a6a-bae8-b2b6fb228f66" />
<img width="338" height="215" alt="Captura de pantalla 2026-06-19 173344" src="https://github.com/user-attachments/assets/1e82aca4-f83c-4dba-8736-5e0d5c592c14" />
the camera detected the face position in Y and X nut never send the info to my ESP32S3  


PCB!!
--
I designed a costum PCB in KiCAD, to make conecctions cleaner instead of the mess i have, unfortunetly i dont have the money for buying it...

<img width="1257" height="877" alt="Captura de pantalla 2026-06-24 195610" src="https://github.com/user-attachments/assets/8c835290-466b-4ac2-8f12-c65b4a474d61" />
<img width="650" height="642" alt="esquema" src="https://github.com/user-attachments/assets/aed5a939-6c2e-445d-b1a1-459370c19fd6" />
<img width="1918" height="1198" alt="Captura de pantalla 2026-06-24 214031" src="https://github.com/user-attachments/assets/27f414c6-1222-4031-ac37-e34c6064246e" />


The body CAD 3D
----
I designed the chassis, a complete bot 31 cm tall and 31 cm long counting the arms. 
it have a lot of details and is thinked for it to dont being heavy, so the movement can be better.
<img width="751" height="978" alt="Captura de pantalla 2026-06-25 231259" src="https://github.com/user-attachments/assets/2e0b64d0-6619-4c6c-a3d6-8c526b44a1f2" />
<img width="1486" height="1002" alt="Captura de pantalla 2026-06-25 231148" src="https://github.com/user-attachments/assets/91b8fc6e-b285-44a5-9d44-64369ea47800" />
<img width="1583" height="1025" alt="Captura de pantalla 2026-06-25 231214" src="https://github.com/user-attachments/assets/5686ba1e-45cb-421a-8058-5e6faa753302" />

have details so u can put ur ESP32S3
a botton for RST the esp32s3 
the oled holes
ultrasonic hole
and to attach the motors.


Power struggles
----
The power was the thing that killed me the most.
the recommend batterry is 7.4V 2S LiPo but i cant afford it lol
and i learned that 9V battery DONT WORK OUT they give voltage but they dont give enough current
so that makes the motors drown it.

I made my own stripping one, I had and adapted it so Starpheus can run from a wall, its like it has a strap but is really usefull and functional if u are poor just like me.
you can also use a 6AA baterries in series, I tryed but i think i did it wrong cus they started overheating
REMEMBER this is a really worked out demo so eventually ill add a 7.4V battery.



Putting it all together
-----
I made a really complete excel with all the wires you need to make.
<img width="1482" height="800" alt="Captura de pantalla 2026-06-24 170230" src="https://github.com/user-attachments/assets/d332ddce-01be-4395-a856-c96f633d32db" />
Honestly i struggled a lot with this, my head still hurts thinking about this...


What I learned 
---

I learned a lot with this project. 
sometimes u dont notices evrything has to do with math, the friction maths for the motor are soo cool 
its hard sometimes cus you dont know were to start or ypu are scared of trying and not making it "that good" 
but i guess we all start somewhere, u just need to dont make it with fear 



Future improvements
---
COMPUTER VISION! with a no clone camarra that actually follows ur face with the neck.
a proper battery...
audio and sound expressions 
a more complete control app

Photos i like about starpheus construction}
---

<img width="1917" height="1198" alt="Captura de pantalla 2026-06-26 234659" src="https://github.com/user-attachments/assets/852b41ba-32d6-493b-8e03-fbf7201f66c8" />
Controll pag is complete FIREEE 
<img width="431" height="155" alt="Captura de pantalla 2026-06-26 234435" src="https://github.com/user-attachments/assets/9a4b47d4-57ef-4652-bc38-bb6b8ff9587d" />
i was so happy, looks amazing that starpheus have internet its so cute 
<img width="595" height="800" alt="Captura de pantalla 2026-06-25 225412" src="https://github.com/user-attachments/assets/13057666-0fe9-4736-83d3-5e9cc63e0b60" />
AJJSSJSJS HE LOOKS SO TIRED HELL NAAA
<img width="600" height="791" alt="Captura de pantalla 2026-06-25 225356" src="https://github.com/user-attachments/assets/25051666-2c2a-4da9-a11a-2c5d378edc16" />
I tried making a serie of AA batterys but i lit burn my finger, still hurts...a lot 
<img width="852" height="845" alt="Captura de pantalla 2026-06-22 150748" src="https://github.com/user-attachments/assets/59ba872c-77c0-43dd-b06d-b7fe6b4f6d5a" />
Bro dont event exist but exist for me :octocat:

<img width="532" height="793" alt="Captura de pantalla 2026-06-22 215209" src="https://github.com/user-attachments/assets/66ee15f9-9283-43f9-8e17-41c192e975cb" />
AWWWA the start of all... 

PS:Thanks u all for looking at these im rlly greatfull <3
