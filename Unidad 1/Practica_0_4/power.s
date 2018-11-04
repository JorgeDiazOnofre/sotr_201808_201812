#Purpose: Program to ilustrate how functions work

#this program will compute the value of 2^3 + 5^2

#everything in teh main program is stored in regosters, so de data section doesn't have anything

.section .data

.section .text

.globl _start
_start:
pushl $3
pushl $2
call power
addl $8, %esp
pushl %eax

pushl $2
pushl $5
call power
addl $8, %esp
popl %ebx

addl %eax, %ebx

movl $1, %eax
int $0x80

#Purpose: This function is used to compute the value of a number raised to a power

#INPUT: First argument, the base number. Second argument, the power to raise it to

#OUTPUT: Will give the result as a return value

#Notes: the power must be 1 or greater

#Variables: 

#	%ebx- Holds the base number
#	%ecx- holds the power
.type power, @function
power:
pushl %ebp
movl %esp, %ebp
subl $4, %esp
movl 8(%ebp), %ebx
movl 12(%ebp), %ecx
movl %ebx, -4(%ebp)
power_loop_start:
cmpl $1, %ecx
je end_power
movl -4(%ebp), %eax
imull %ebx, %eax

movl %eax, -4(%ebp)
decl %ecx
jmp power_loop_start
end_power:
movl -4(%ebp),%eax
movl %ebp,%esp
popl %ebp
ret
