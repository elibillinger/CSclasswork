	.data
	
string:
	.space 128
prompt: .asciiz "Enter a string: "
newline: .asciiz "\n"
integer_prompt: .asciiz "Enter an integer: "

	.text
	.globl rotate
	.globl replace
	.globl atoi
	
main:

	#Ask user to enter a string
	la $a0, prompt 
	li $v0, 4
	syscall
	
	# Read in the String
	li $v0, 8
	la $a0, string
	li $a1, 128
	syscall 
	
	# Call replace and set parameters
	li $a1, '\n'
	li $a2, '\0'
	jal replace
	
	# Print String
	move $t0, $a0
	li $v0,4
	syscall
	
	#Print newline
	la $a0, newline
	li $v0,4
	syscall
	
	#Ask user to integer
	la $a0, integer_prompt
	li $v0,4
	syscall
	
	#Read in integer
	li $v0,5
	syscall 
	
	#call rotate and set parameters
	move $a0,$t0
	move $a1,$v0
	jal rotate
	
	#print string
	move $t0, $a0
	li $v0,4
	syscall
	
	#print newline
	la $a0, newline
	li $v0,4
	syscall
	
	#Ask User to input integer
	la $a0, integer_prompt
	li $v0,4
	syscall
	
	# Read in user integer as a string
	li $v0, 8
	la $a0, string
	li $a1, 128
	syscall 
	
	# call replace and set parameters
	li $a1, '\n'
	li $a2, '\0'
	jal replace
	
	#Call atoi procedure 
	move $t0,$a0
	move $a0,$t0
	jal atoi
	
	#Print Integer
	move $a0,$t4
	li $v0,1
	syscall
	
	#print newline
	la $a0, newline
	li $v0,4
	syscall
	
	#Exit Program
	li $v0,10
	syscall
	
	
replace:
	move $s1,$zero #initalize iterator
	move $s2,$zero #initlize counter
	loop:
		add $t1,$a0,$s1 #add iterator to string address 
		lb $t2,($t1) #load byte
		bne $t2,$a1,continue #if the t2 is not equall to a1 then go to continue
		addi $s2,$s2,1 #add one to iterator
		sb $a2, ($t1) #store it in the string
		continue:
			addi $s1,$s1,1 #add one to iterator
			bne $t2, $zero, loop #if the end of the string has not been reached then jump to loop
	jr $ra #retrun
	
rotate:
	move $s1,$zero #initalize iterator
	li $t6,26 
	div $a1,$t6 #divide integer by 26 to get one rotation since alphabet is 26
	mfhi $a1
	loop1:
		add $t1,$a0,$s1 #add iterator to string address
		lb $t2,0($t1) #load byte
		li $t3,'A' 
		bge $t2,$t3,uppercaseTest # if the character is greater than or equal to A then jump to uppercaseTest
		j continue1 
		uppercaseTest:
			li $t3, 'Z'
			ble $t2,$t3,rotateUpperCase #if the character is lower than or equal to Z then jump to rotateUpperCase
			li $t3,'a'
			bge $t2,$t3,rotateLowerCase
			j continue1
		rotateUpperCase:
			add $t2,$t2,$a1 #add integer to byte
			li $t3, 'Z'
			bgt $t2,$t3,restartAlphabetUpper #if the ascii value is greater than the value of Z then jump to restartAlphabetUpper
			sb $t2, 0($t1)
			j continue1
		restartAlphabetUpper: #have the rotate value jump to begining of uppercase alphabet
			subi $t7,$t2,90
			addi $t2,$t7,64
			sb $t2,0($t1)
			j continue1
		rotateLowerCase:
			li $t3, 'z'
			add $t2,$t2,$a1
			bgt $t2,$t3,restartAlphabetLower #if the ascii value is greater than the value of z then jump to restartAlphabetLower
			sb $t2,0($t1)
			j continue1
		restartAlphabetLower: #have the rotate value jump to begining of lowercase alphabet
			subi $t7,$t2,122
			addi $t2,$t7,96
			sb $t2,0($t1)
			j continue1
		continue1:
			addi $s1,$s1,1 #add one to iterator
			bne $t2, $zero, loop1
	jr $ra
	
	
atoi:
	move $s1,$zero #initalize iterator
	move $t7,$zero
	move $t4,$zero #initalize integer as zero
	loop2:
		add $t1,$a0,$s1 #add inerator to string address
		lb $t2,($t1)
		li $t5, '\0'
		beq $t2,$t5,end #check if end of string has been reached
		li $t3,48
		bge $t2,$t3,checkHigh #if ascii value is greater than or equal to 48 then jump to checkHigh
		addi $s1, $s1,1
		mul $t4,$s1,-1
		j end
		checkHigh:
			li $t3,57
			ble $t2,$t3,convert #if ascii value is less than or equal to 57 then jump to convert
			addi $s1, $s1,1
			mul $t4,$s1,-1
			j end
		convert: #convert ascii value to corresponding integer and check for another digit
			sub $t7, $t2,48
			bgt $s1,0,timesTen #if counter over zero then jump to timesTen
			add $t4, $t4,$t7 #add integer to t4
			j continue2
		timesTen: #multiply t4 by ten then add integer to t4
			mul $t4, $t4, 10
			add $t4, $t4,$t7
			j continue2
		continue2:
			addi $s1,$s1,1 #add one to iterator
			bne $t2, $zero, loop2
			j end
		end:
			jr $ra
	