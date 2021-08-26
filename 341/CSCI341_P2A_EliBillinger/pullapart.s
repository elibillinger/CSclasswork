	.data 
integerInstruc: .asciiz "Enter an integer: "
signBitOutput: .asciiz "Sign bit is: "
byteOutput: .asciiz "\nBytes are: "
space: .asciiz " "

	.text 
main:
	la $a0, integerInstruc # put sting into a0
	li $v0, 4     # set syscall to print integer instructions
	syscall  
	
	li $v0, 5 #set syscall to get int
	syscall 
	
	move $s0,$v0 #move int to s0
	
	srl $t1,$s0,31 #shift right 31 bits to have only the sign bit
	
	la $a0, signBitOutput # put string into a0
	li $v0, 4     # set syscall to print string sign bit output
	syscall
	
	la $a0,($t1) # put sign bit into a0
	li $v0, 1 # set syscall to print integer of sign bit
	syscall
	
	srl $t2, $s0, 24  #shifting to isolate each byte and store it in a seperte register
	sll $t3, $s0, 8
	srl $t3, $t3, 24
	sll $t4, $s0, 16
	srl $t4, $t4, 24
	sll $t5, $s0, 24
	srl $t5, $t5, 24
	
	la $a0, byteOutput # put sting into a0
	li $v0, 4     # set syscall to print byte output
	syscall 
	
	la $a0,($t2) #put t2 into a0 to print
	li $v0, 1 # set syscall to print byte
	syscall
	
	la $a0, space #use syscall to print out space
	li $v0, 4
	syscall
	
	la $a0,($t3) #put t3 into a0 to print
	li $v0, 1 # set syscall to print byte
	syscall
	
	la $a0, space #use syscall to print out space
	li $v0, 4
	syscall
	
	la $a0,($t4) #put t4 into a0 to print
	li $v0, 1 # set syscall to print byte
	syscall
	
	la $a0, space #use syscall to print out space
	li $v0, 4
	syscall
	
	la $a0,($t5) #put t5 into a0 to print
	li $v0, 1 # set syscall to print byte
	syscall
	
	li $v0, 10    # set the syscall to exit
	syscall