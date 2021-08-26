#	
#	
#	
	
	.data
frame:
	.space 0x80000
	.text
	addi $a0,$zero, 10
	addi $a1,$zero, 20 #square pixel height and width
	addi $a2,$zero, 10
	jal square
	
	addi $v0, $zero, 10 # exit
	syscall
	
square:
	beq  $a1, $zero, return # zero width: draw nothing
	
	addi $t0, $zero, 0x00ffffff # color: white
	la   $t1, frame
    add  $a1, $a1, $a0 # simplify loop tests by switching to first too-far value
	sll  $a0, $a0, 2 # scale x values to bytes (4 bytes per pixel)
	sll  $a1, $a1, 2
	sll  $a2, $a2, 11 # scale y values to bytes (512*4 bytes per display row)
	sll  $a1, $a1, 11
	addu $t2, $a2, $t1 # translate y values to display row starting addresses
	addu $a2, $t2, $a0 # translate y values to rectangle row starting addresses
	addu $t2, $t2, $a1 # and compute the ending address for first rectangle row
	addi $t4, $zero, 0x800 # bytes per display row

yloop:
	move $t3,$a2 # pointer to current pixel for X loop; start at left edge

xloop:
	sw $t0, 0($t3)
	addiu $t3, $t3, 2
	bne $t3, $t2, xloop # keep going if not past the right edge of the rectangle

	addu $a2, $a2, $t4 # advance one row for the left edge
	addu $t2, $t2, $t4 # and right edge pointers
	bne $a2, $a1, yloop # keep going if not off the bottom of the rectangle

return:
    jr $ra
