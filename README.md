# **PROIECT SMP 2021**
# SMART PARKING ARDUINO

## **REALIZAT DE:**
* [MATEO BODE](https://github.com/mateobode)
---

## **DESCRIERE:**
---
O parcare de tip Smart-Parking (parcare inteligenta), se refera la un loc de parcare unde nu este nevoia de oamenii care actioneaza functionalitatile acestuia, ci doar de instrumente hardware care pot fi controlate in mod automat folosind metodele necesare. Pornind la aceasta idee, m-am gandit sa implementez un astfel de parcare folosind o placa **Arduino UNO R3**, care va deschida bara in mod automat pana cand nu mai sunt locuri in parcare si toate informatiile se vor vizualiza pe un LCD.

## **FUNCTIONALITATILE:**
---
* Aplicatie hardware pentru simularea Smart Parking-ului.
* Deschidere/Inchidere automata a barei.
* Stingere/Aprindere LED-ului.
* Citirea datelor de la senzorii infrared.
* Afisarea informatiilor pe LCD.

## **COMPONENTE HARDWARE:**
---
* Placa Arduino UNO R3
* Breadbord
* Fire
* LCD 16x2
* I2C Bus Module
* Micro-ServoMotor
* 6 Senzorii IR-obstacle
* 4 LED-uri galbene
* 4 rezistente de 100[Ohm]

## **IMPLEMENTARE:**
---
Ca inceput, am luat un bazament de carton pentru a creea locul de parcare asa cum se vede la poza de mai jos.

![carton]()

 Pentru a face legatura cu Arduino am folosit doua fire, unul l-am folosit pentru a conecta breadboard-ul cu pinul de Vin(input de 5V) de la Arduino, si altul pentru a conecta breadboard-ul cu Ground-ul de la Arduino. Fiind 4 locuri de parcare, am folosit 4 senzori IR conectati in paralel avand aceasi Vin si GND. Pe GND comun am conectat si 4 LED-uri galbene care va aprinde cand un loc este ocupat si stinge cand locul este liber. Ca LED-urile sa aiba un curent maxim recomandat de 20mA, am conectat in fiecare catoda o rezistenta de 100ohm pentru a nu reduce viata utilizabila a LED-urilor. Fara rezistenta de 100ohm, curentul maxim care circula prin un LED este 53.5mA si nu este recomandat.

 ![senzori+led]()

 Dupa aceasta am conectat inca doua senzorii separat, unul pentru intrarea in parcare si altul pentru iesirea de la parcare. Aceste doi senzorii va stimula si deschiderea/inchiderea barei de parcare. Pentru bara de parcare am folosit micro-ServoMotor. Senzorii si micro-ServoMotor-ul sunt conectatii pe breadboard-ul avand Vin=5V si GND.

 ![Entrance](https://gitlab.com/smp2021/334ab/parcare-inteligenta/-/blob/master/Entrance.jpeg?raw=true)
 ![exit]()
 ![servo]()

 Ultima componenta hardware conectata este LCD-ul 16x2. Pentru a conecta cu UNO R3 acest LCD, am folosit un Bus Module I2C. Modulul Bus este conectat cu LCD-ul in fiecare port al acestuia. Pin-ul SCL am conectat la portul SCL pe Arduino, pin-ul SDA am conectat la portul SDA pe Arduino, si Vin pe al doilea port 5V (nu cel folosit pentru senzorii si LED-uri), si GND pe al doilea port GND (nu cel folosit pentru senzorii si LED-uri).

 ![LCD]()

 Montajul final realizat pentru acest proiect este ca la poza de mai jos.

## **SCHEMA ELECTRICA:**
---
Pentru a crea schema electrica am folosit un program numit Fritzing.

![schema]()

## **VIDEOCLIP:**
---
Am realizat un videoclip scurt ca sa demonstrez functionalitatile descrise mai sus [VideoClip](https://youtu.be/utcOyGihxsY).

## **SURSE:**
---
Am luat ca surse pentru a avea o idee de implementare:
* [Link1](https://www.youtube.com/watch?v=2bl_0mLAJJA)
* [Link2](https://www.youtube.com/watch?v=6gccSyp_uJQ&t=77s)
* [Link3](https://www.youtube.com/watch?v=vZ08Y5aqdpM&t=27s)
