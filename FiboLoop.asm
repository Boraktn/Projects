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
	move $t4, $v0
	
	jal func
	la $a0, p1 
    	li $v0, 4          
    	syscall
	li $v0, 1
	move $a0, $t4
	syscall			
	la $a0, p2
    	li $v0, 4           
    	syscall
    	li $v0, 1
	move $a0, $t0
	syscall
	li $v0, 10      #exit program   
    	syscall 
func:
	li $t0, 0
	li $t1, 1
	li $t2, 0
	loop:
	beq $t2, $t4, exit
	addi $t2, $t2, 1
	add $t3, $t0, $t1
	move $t0 ,$t1
	move $t1 ,$t3
	j loop
	exit:
	jr $ra
	
