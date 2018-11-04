#purpose

#simple program that exits and returns a status code back to the linux kernel

#INPUT:
#none

#OUTPUT: returns a status code that can be viewed by typing 

#echo $___
#after running the program

#Variables

# %eax holds the systm call number
#%ebx holds the return status

.section .data

.section .text
.globl _start
_start:

movl $1, %eax

movl $0, %ebx

int $0x80
