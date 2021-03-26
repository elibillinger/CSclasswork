# Eli Billinger
# CSCI 341
# Program 4

	.data
inital_state: .asciiz "Inital state: "
entry_prompt: .asciiz "Entry accessed: "
space: .asciiz " "
newline: .asciiz "\n"

	.text
	.globl update_state
	.globl recently_used
	.globl initalize_state
	
main:
	#output inital state prompt
	la $a0,inital_state
	li $v0,4
	syscall 
	
	#Read in integer
	li $v0,5
	syscall 
	
	#Check if value is Valid
	move $t0, $v0
	blt $t0,0,exit
	bgt $t0,7,exit
	
	move $a0,$t0
	jal initalize_state
	move $t7,$s5
	move $t8,$s6
	move $t9,$s7
	
	move $a1,$t7
	move $a2,$t8
	move $a3,$t9
	jal recently_used
	
	loop:
		#output entry accessed prompt
		la $a0,entry_prompt
		li $v0,4
		syscall 
		
		#Read in integer
		li $v0,5
		syscall 
		
		#Check if value is Valid
		move $t1, $v0
		blt $t1,0,exit
		bgt $t1,3,exit
		
		move $a0,$t1
		# 3 bits for LRU
		move $a1,$t7
		move $a2,$t8 
		move $a3,$t9
		jal update_state
		
		move $t7,$s2
		move $t8,$s1
		move $t9,$s0
		
		move $a1,$t7
		move $a2,$t8
		move $a3,$t9
		jal recently_used
		j loop
	
	exit:
		#Exit Program
		li $v0,10
		syscall
	

initalize_state:
	andi $s0,$a0,1
	andi $s1,$a0,2
	andi $s2,$a0,4
	bgtz $s2,bit1
	move $s5,$zero
	bgtz $s1,bit2
	move $s6,$zero
	bgtz $s0,bit3		
	move $s7,$zero
	jr $ra
	bit1:
		addi $s5,$zero,1
		bgtz $s1,bit2
		move $s6,$zero
		bgtz $s0,bit3
		move $s7,$zero
		jr $ra
	bit2:
		addi $s6,$zero,1
		bgtz $s0,bit3
		move $s7,$zero
		jr $ra
	bit3:
		addi $s7,$zero,1
		jr $ra
				
recently_used:
	#move LRU bits to s0-s2
	move $s2,$a1
	move $s1,$a2
	move $s0,$a3
	
	bgtz $s2,first_pair
	bgtz $s1,first_value2
	addi $s4,$zero,3
	addi $s5,$zero,2
	bgtz $s0,second_value2
	addi $s6,$zero,1
	addi $s7,$zero,0
	j print
	first_pair:
		bgtz $s1,first_value
		addi $s4,$zero,1
		addi $s5,$zero,0
		bgtz $s0,second_value
		addi $s6,$zero,3
		addi $s7,$zero,2
		j print
	first_value:
		addi $s4,$zero,0
		addi $s5,$zero,1
		bgtz $s0,second_value
		addi $s6,$zero,3
		addi $s7,$zero,2
		j print
		
	first_value2:
		addi $s4,$zero,2
		addi $s5,$zero,3
		bgtz $s0,second_value2
		addi $s6,$zero,1
		addi $s7,$zero,0
		j print
		
	second_value:
		addi $s6,$zero,2
		addi $s7,$zero,3
		j print
	
	second_value2:
		addi $s6,$zero,0
		addi $s7,$zero,1
		j print
	
	print:
		move $a0,$s4
		li $v0,1
		syscall
		la $a0,space
		li $v0,4
		syscall
		move $a0,$s5
		li $v0,1
		syscall
		la $a0,space
		li $v0,4
		syscall
		move $a0,$s6
		li $v0,1
		syscall
		la $a0,space
		li $v0,4
		syscall
		move $a0,$s7
		li $v0,1
		syscall
		la $a0,newline
		li $v0,4
		syscall
		jr $ra
		
update_state:
	#move LRU bits to s0-s2
	move $s2,$a1
	move $s1,$a2
	move $s0,$a3
	move $s3,$a0
	
	bgt $s3,1,pair2 #determine if it 0-1 or 2-3
	#if 0-1 check if it is most recent pair
	beq $s2,1,first_one
	li $s2,1
	move $t4,$s0
	move $s0,$s1
	move $s1,$t4
	j first_one
	first_one: #if 0-1 is most recent pair check if 1 is most recent and then compare to value
		beq $s1,0,compare_1
		bne $s3,0,sub_s1
		jr $ra
	compare_1:
		bne $s3,1,add_s1
		jr $ra
	pair2: # if 2-3 check if it is most recent pair else change bit
		beq $s2,0,first_two
		li $s2,0
		move $t4,$s0
		move $s0,$s1
		move $s1,$t4
		j first_two
	first_two: # if 2-3 is most recent pair if 3 is most recent check if value is 3
		beq $s1,0,compare_3
		bne $s3,2,sub_s1
		jr $ra
	compare_3:
		bne $s3,3,add_s1
		jr $ra
	add_s1:
		li $s1,1
		jr $ra
	sub_s1:
		li $s1,0
		jr $ra