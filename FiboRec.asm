.data
msg1: .asciiz "Give a number: "
p1: .asciiz "F("
p2: .asciiz "): "
.text
main:
	la $a0, msg1
	li $v0, 4
	syscall

	li $v0, 5 
	syscall
	move $t2, $v0
	move $t0, $t2
	jal func
	j printNexit
func:
	ble $t0, 1, oNz
	sub $t0, $t0, 1 
	sub $sp, $sp, 4
	sw $ra, 0($sp) 
	jal func  
	add $t0, $t0, 1
	lw $ra, 0($sp) 
	add $sp, $sp, 4

	sub $sp, $sp, 4
	sw $v0, 0($sp)
	sub $sp, $sp, 4
	sw $ra, 0($sp)
	sub $t0, $t0, 2
	jal func
	add $t0, $t0, 2
	lw $ra, 0($sp)
	add $sp, $sp, 4
	lw $s7, 0($sp)
	add $sp, $sp, 4

	add $v0, $v0, $s7
	move $t3,$v0
	jr $ra

oNz:
	move $v0, $t0
	move $t3,$v0
	jr $ra

printNexit:
	la $a0, p1 
    	li $v0, 4    
    	syscall
	li $v0, 1
	move $a0, $t2
	syscall			
	la $a0, p2
    	li $v0, 4           
    	syscall
    	li $v0, 1
	move $a0, $t3
	syscall
	li $v0, 10      #exit program   
    	syscall 
