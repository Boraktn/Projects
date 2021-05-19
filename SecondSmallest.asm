.data
values: .word 3, 3, 3,5,5
size:   .word 5
msg:    .asciiz    "There is No Second Smallest \n"
.text
la $a0, values
lw $a1, size
li $t1, 4
lw $t2, values($zero)
lw $t3, values($zero)
mul $t4, $a1, 4
smallest: bge $t1, $t4, reset
	lw $a0, values($t1)
	blt $a0, $t2, min
	j counter

	min: move $t2, $a0

	counter: addi $t1, $t1, 4
	b smallest
reset: sub $t1, $t1, $t1
	add $t1, $t1, 4
	j secsmallest
	
secsmallest: bge $t1, $t4, final
	lw $a0, values($t1)
	bne $t2, $t3, check
	j secmin
	check:blt $a0, $t3, check2
	j counter2
	check2: bne $t2, $a0, secmin
		j counter2

	secmin: move $t3, $a0

	counter2: addi $t1, $t1, 4
	b secsmallest
final:
	bne  $t3, $t2, yeap
	j nope
	
	yeap:li $v0, 1
	move $a0, $t3
	syscall
	li $v0, 10
	syscall
	
	nope:	li $v0,4     
	la $a0, msg   
	syscall
	li $v0, 10
	syscall
