// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Fill.asm

// Runs an infinite loop that listens to the keyboard input.
// When a key is pressed (any key), the program blackens the screen,
// i.e. writes "black" in every pixel;
// the screen should remain fully black as long as the key is pressed. 
// When no key is pressed, the program clears the screen, i.e. writes
// "white" in every pixel;
// the screen should remain fully clear as long as no key is pressed.

// Put your code here.
(BEGIN)
    @row
    M=-1

(KEYBOARD)
    @KBD
    D = M
    @IF_NOT_KEYBOARD
    D; JEQ
    @LOOP
    0; JMP

(LOOP)
    @row
    MD=M+1
    @SCREEN
    A=A+D
    M=-1
    @8192
    D = A
    @row
    D = M - D
    @BEGIN
    D;JGE
    @KEYBOARD
    0; JMP

(IF_NOT_KEYBOARD)
    @row
    MD=M+1
    @SCREEN
    A=A+D
    M=0
    @8192
    D = A
    @row
    D = M - D
    @BEGIN
    D;JGE
    @KEYBOARD
    0; JMP