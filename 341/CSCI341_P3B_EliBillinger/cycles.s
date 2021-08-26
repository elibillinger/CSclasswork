# Eli Billinger
# CSCI 341
# Program 3B
	.data
array: .space 20
newline: .asciiz "\n"
cycle_prompt: .asciiz "Enter the length of cycle "
prompt2: .asciiz ": "
longest_cycle: .asciiz "Longest cycle is "
overhead_output: .asciiz "Average overhead is "
array_bracket_one: .asciiz "["
array_bracket_two: .asciiz "]"
comma: .asciiz ", "
	
	.text
	.globl longest
	.globl overhead
	.globl tostring
	
main:
	add $t0, $zero,1 #set counter
	move $t1, $zero #set 
	add $t6,$t6,20
	loop:
		beq $t0,6,outputs #check counter
		
		#output first part of prompt
		la $a0,cycle_prompt
		li $v0,4
		syscall 
		
		#output which cycle using the counter
		la $a0,($t0)
		li $v0,1
		syscall
		
		#output secound part of prompt
		la $a0,prompt2
		li $v0,4
		syscall
		
		#Read in integer
		li $v0,5
		syscall 
		
		blt $v0,0,end
		
		la $t2, array
		mul $t3,$t1,4
		add $t4,$t3,$t2
		move $t5,$v0
		sw $t5,($t4)
		add $t1,$t1,1
		
		add $t0,$t0,1 # add one to counter
		
		j loop #jump to beginning of loop
	outputs:
		#call tostring
		la $a0,array
		jal tostring
		
		#print newline
		la $a0, newline
		li $v0,4
		syscall
		
		#print longest_cycle
		la $a0,longest_cycle
		li $v0,4
		syscall
		
		#call longest
		la $a0,array
		jal longest
		
		#print integer from longest
		move $a0,$v0
		li $v0,1
		syscall
		
		#print out newline
		la $a0, newline
		li $v0,4
		syscall
		
		#print out the output prompt
		la $a0,overhead_output
		li $v0,4
		syscall
		
		#call overhead
		la $a0,array
		jal overhead
		
		#print out the overhead
		move $a0,$v0
		li $v0, 1
		syscall
		
		#print out newline
		la $a0, newline
		li $v0,4
		syscall
		
		#reset values and start loop over
		li $t0,1
		li $t1,0
		j loop
		
	end:
		#Exit Program
		li $v0,10
		syscall
		
		
tostring:
	add $s3, $zero,5
	move $s1, $a0 # get array address
	move $s2, $zero # set loop counter
	
	#print the beginning bracket
	la $a0,array_bracket_one
	li $v0,4
	syscall
	
	loop2:
		#print element in array
		lw $a0, ($s1) 
		li $v0, 1
		syscall
		
		#advance loop counter and array pointer
		add $s2, $s2, 1 
		add $s1, $s1, 4 
		
		beq $s2, $s3, end2 # branch if end of array has been reached
		
		#print out comma
		la $a0,comma
		li $v0,4
		syscall
		
		j loop2 
		
	end2:
		#print the end bracket
		la $a0,array_bracket_two
		li $v0,4
		syscall
		
		jr $ra

longest:
	#initalize values
	add $s3, $zero,6
	move $s1, $a0 
	add $s2, $zero, 1 
	move $s5,$zero
	loop3:
		lw $s4, ($s1) 
		bgt $s4,$s5, large
		#advance loop counter and array pointer
		add $s2, $s2, 1 
		add $s1, $s1, 4 
		
		beq $s2, $s3, end3 #branch if end of array has been reached
		j loop3
		
	large:
		move $s5,$s4
		#advance loop counter and array pointer
		add $s2, $s2, 1 
		add $s1, $s1, 4 
		
		beq $s2, $s3, end3 # branch if end of array has been reached
		j loop3
		
	end3:
		move $v0,$s5
		jr $ra
		
		
overhead:
	#save ra and array pointer
	move $t8, $a0
	move $s0,$ra
	# call longest
	la $a0,array
	jal  longest 
	#move longest value to t5 
	move $t5,$v0
	
	#initilaze values for overhead
	move $t4,$zero
	add $t3, $zero,6
	move $t2,$zero
	add $t2, $zero,1
	move $t7,$zero
	
	loop4:
		lw $t4, ($t8) 
		sub $t6,$t5,$t4 
		add $t7,$t7,$t6
		
		#advance loop counter and array pointer
		add $t2, $t2, 1 
		add $t8, $t8, 4 
		
		beq $t2, $t3, end4 # break if end of array has been reached
		j loop4
		
	end4:
		div $t7,$t7,5 #find average
		
		move $v0,$t7
		
		jr $s0

			
