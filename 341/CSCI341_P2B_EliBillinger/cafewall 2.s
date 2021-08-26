#	Eli Billinger
#	CSCI341 Program 2B 9/23/2020
#	Creating the cafewall illusion
#	Used code from rectangle.s to create square procedure

	
	.data
	
frame:
	.space 0x80000
	size: .asciiz "Enter a size for the square in pixels: "
	pairs: .asciiz "Enter the number of paris of squares/rows: "
	.text
	la $a0, size # put sting into a0
	li $v0, 4     # set syscall to print integer instructions
	syscall  
	li $v0, 5 #set syscall to get int
	syscall 
	move $s4,$v0 #move int to a1
	
	la $a0, pairs # put sting into a0
	li $v0, 4     # set syscall to print integer instructions
	syscall  
	li $v0, 5 #set syscall to get int
	syscall 
	move $s7,$v0 #move int to a3
	
	addi $a0, $zero, 10
	add $a1, $zero, $s4
	addi $a2, $zero, 10
	add $a3, $zero ,$s7
	jal lineSquares
	addi $v0, $zero, 10 # exit
	syscall
	
	
	
	
lineSquares:
	move $s7, $a3 # move number of pairs to s7
	move $t0,$a3
	mul $t0,$t0,2
	move $t7, $zero # set counter to zero
	move $t6,$zero # set counter to zero
	move $s6,$a0 # set s6 to starting x value
	move $s5, $a1 # set s5 to width and height for furhter use
	move $s2,$a2 # set s2 to starting y postion
	
	
	looprows:
		beq $t0, $t6, end_looprows
	lineloop:
		beq $s7, $t7, end_lineloop
		add $a0,$s6, $zero
		add $a1, $zero, $s4
		move $a2,$s2
		addi $a3,$zero, 0x000000ff
		jal square
		move $a0, $zero #reset a0 value
		add $s6, $s6, $s5
		add $a0, $s6, $zero
		add $a1, $zero, $s4
		move $a2,$s2
		addi $a3, $zero, 0x00ffffff
		jal square	
		add $t7, $t7, 1 # add one to counter
		move $a0, $zero #reset a0 value
		add $s6, $s6, $s5
		b lineloop
	end_lineloop:
		move $t7, $zero # reset counter to zero
		move $s6,$a0 #reset s6 to 10
		add $t6, $t6, 1 # add one to counter
		
		add $t9, $zero,2
		div $t6,$t9 # take division of t6 mod stored in HI
		mfhi $t9 # mod of division is in HI and now put HI into t5
		bne $t9,0,else
		add $s6,$zero,10 #reset a0 to 10
		j continue
		else: 
			add $s6,$zero,20 #reset a0 to 15
		continue:
			add $s2, $s2, $s5
			add $s2,$s2,2 # add 2 create line inbetween rows
			b looprows
end_looprows:
	
	
	
square:

	la   $t1, frame
	add $s3, $a1, $zero #put a1 value to s3 to switch to first too-far value for y
    add  $a1, $a1, $a0 # switch to first too-far value for x
	sll  $a0, $a0, 2 # scale x values to bytes (4 bytes per pixel)
	sll  $s0, $a1, 2
	add $s3, $s3, $a2 # switch to first too-far value for y
	sll  $a2, $a2, 11 # scale y values to bytes (512*4 bytes per display row)
	sll  $s1, $s3, 11
	addu $t2, $a2, $t1 # translate y values to display row starting addresses
	addu $s1, $s1, $t1
	addu $a2, $t2, $a0 # translate y values to rectangle row starting addresses
	addu $s1, $s1, $a0
	addu $t2, $t2, $s0 # and compute the ending address for first rectangle row
	addi $t4, $zero, 0x800 # bytes per display row
	
	yloop:
		move $t3,$a2
	xloop:
		sw $a3, 0($t3)
		addiu $t3, $t3, 4
		bne $t3, $t2, xloop # keep going if not past the right edge of the rectangle

		addu $a2, $a2, $t4 # advance one row for the left edge
		addu $t2, $t2, $t4 # and right edge pointers
		bne $a2, $s1, yloop # keep going if not off the bottom of the rectangle
	return:
	jr $ra