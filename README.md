# Cellular-Automata-Project
Cellular automata simulations using arduino and java

The results of the simulation are in the file Shah_Tan_David_Cellular_Automata_Paper.pdf.

The main code file is ca.java. To run it, compile it using "javac ca.java" and run it using  "appletviewer ca.java".

The main java applet is ca.java
It has 4 modes: 1. Game of Life
                2. Spiral Wave
                3. Elementary Cellular Automata
                4. Comparison

Note about Mode 3: 
Set size by changing column size
Using rule 90 with size 64 will lead to disappering sierpinsky triangle.
Play around with both kinds of boundaries. 

RandGen.java is our own implementation of a random number generator using elementary CA rule 30, run it in terminal.

Randgen is a random number generator from scratch using rule 30.
Arduino .ino files are in the respective arduino folders. arduinoCodeRing uses an led ring to represent each state of the cellular automata. arduinoGameOfLife is an led matrix for game of life.

The programs in folders are arduino programs, they might be VERY buggy.

Have fun,
Anthony, Karan and Stanley
