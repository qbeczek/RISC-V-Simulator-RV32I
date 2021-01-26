         .text
         .align	1
         .globl _start
         .globl	main
         .type	main, @function
_start:  
         call	subroutine
         j	main
main:    
         mv	a4,a0
         mv	a5,a0
         sll a5,a5,1
         nop
petla1:  
         lw	a5,-20(s0)	
         addi	a5,a5,1
         j	petla1
subroutine:
         nop
         ret
