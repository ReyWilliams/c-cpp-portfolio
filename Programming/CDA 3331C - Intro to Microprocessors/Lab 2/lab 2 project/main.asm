;-------------------------------------------------------------------------------
; MSP430 Assembler Code Template for use with TI Code Composer Studio
;-------------------------------------------------------------------------------
           	.cdecls C,LIST,"msp430.h"       ; Include device header file
			.def RESET
           	.text                   ; Assemble into program memory
           	.retain                 ; Override ELF conditional linking and retain current section
           	.retainrefs             ; Additionally retain any sections that have references to current section

;-------------------------------------------------------------------------------
RESET       mov.w   #__STACK_END,SP         ; Initialize stackpointer
StopWDT     mov.w   #WDTPW|WDTHOLD,&WDTCTL  ; Stop watchdog timer

;-------------------------------------------------------------------------------
;-----  Your Sorting lab starts here -------------------------------------------

;Memory allocation of arrays must be done prior to the RESET & StopWDT
ARY1		.set	0x0200			;Memory allocation 	ARY1
ARY1S		.set	0x0210			;Memory allocation 	ARYS
ARY2		.set	0x0220			;Memory allocation 	ARY2
ARY2S		.set	0x0230			;Memory allocation 	AR2S

			clr	R4					;Clear Register
			clr	R5					;Clear Register
			clr	R6					;Clear Register

			clr &0210h				;Clears the memeory locations
			clr &0212h
			clr &0214h
			clr &0216h
			clr &0218h
			clr &021Ah

			clr &0230h
			clr &0232h
			clr &0234h
			clr &0236h
			clr &0238h
			clr &023Ah


SORT1		mov.w	#ARY1,	R4		;Initialize R4 to point to ARY1  in the memory
			mov.w	#ARY1S,	R6		;Initialize R6 to point to ARY1S in the memory where the sorted ARY1 will be stored
			call	#ArraySetup1	;Create elements are store them in ARY1
			call 	#COPY			;Copy the elements from the ARY1 space to ARY1S space
			call	#SORT			;Calling Subroutine Sort with parameter passing in R4 abd R6

SORT2		mov.w	#ARY2,	R4		;Initialize R4 to point to ARY2  in the memory
			mov.w	#ARY2S,	R6		;Initialize R6 to point to ARY2S in the memory where the sorted ARY2 will be stored
			call	#ArraySetup2	;Create elements are store them in ARY2
			call 	#COPY			;Copy the elements from the ARY2 space to ARY1S space
			call	#SORT			;Calling Subroutine Sort with parameter passing in R4 abd R6

Mainloop	jmp	Mainloop 			;loop in place for ever to prevent garbage values from noises

;Array element initialization Subroutine
ArraySetup1	mov.b	#10,	0(R4)	;Define the number of elements in the array
			mov.b	#34, 	1(R4)	;store an element
			mov.b	#-18, 	2(R4)	;store an element
			mov.b	#87, 	3(R4)	;store an element
			mov.b	#-65, 	4(R4)	;store an element
			mov.b	#28, 	5(R4)	;store an element
			mov.b	#-15, 	6(R4)	;store an element
			mov.b	#-49, 	7(R4)	;store an element
			mov.b	#61, 	8(R4)	;store an element
			mov.b	#-77, 	9(R4)	;store an element
			mov.b	#45, 	10(R4)	;store an element
			ret

;Array element initialization Subroutine
ArraySetup2	mov.b	#10, 	0(R4)	;Define the number of elements in the array
			mov.b	#90, 	1(R4)	;store an element
			mov.b	#46, 	2(R4)	;store an element
			mov.b	#16, 	3(R4)	;store an element
			mov.b	#-55, 	4(R4)	;store an element
			mov.b	#-39, 	5(R4)	;store an element
			mov.b	#32, 	6(R4)	;store an element
			mov.b	#38, 	7(R4)	;store an element
			mov.b	#12, 	8(R4)	;store an element
			mov.b	#54, 	9(R4)	;store an element
			mov.b	#23, 	10(R4)	;store an element
			ret

;Copy original Array to allocated Array-Sorted space
COPY		mov.b	0(R4), R10		;save n (number of elements) in R10
			inc.b	R10				;increment by 1 to account for the byte n to be copied as well
			mov.w	R4, R5			;copy R4 to R5 so we keep R4 unchanged for later use
			mov.w	R6, R7			;copy R6 to R7 so we keep R6 unchanged for later use
LP			mov.b	@R5+, 0(R7)		;copy elements using R5/R7 as pointers
			inc.w 	R7
			dec		R10
			jnz	LP
			ret

;Sort the copy of Array saved in the allocated Array-Sorted space, while keeping original Array unchanged
;replace the following two lines with your actual sorting algorithm.

SORT		mov.b @R6, R8 	;Saves n(number of elements) in R8
			inc R8			;Makes it n+1
			mov.w R6, R7	;Copies the address held in R6 to R7 so R7 always points to top of array
			mov.w R6, R13	;Second pointer for addresses
			mov.b @R7, R9	;Saves n(number of elements) in R9

RUN			dec R8
			jz DONE 		;Jumps to DONE if count is 0
			mov.w R7, R6	;Sets R6 to top of array
			inc R6			;Sets R6 one off from
			mov.w R6, R13	;Sets R13 to R6's value
			inc R13			;offsets that by 1
			mov.b R8, R9	;Sets up secondary check

RUN2		dec R9			;Does secondary check
			jz RUN			;If second check is zero, go back to running

SCAN		mov.b @R6, R11 	;Gets current value from the array and moves it into R11 and then increments pointer
			mov.b @R13, R12	;Gets next value from the array and moves it into R12
			cmp.b R11, R12	;Compare values
			jl SWAP			;If the first value is more than the second, SWAP THEM
			inc R6			;IF values are already sorted then go ahead and run again
			inc R13
			jmp RUN2

SWAP		mov.b R12, 0(R6) 	;Places lesser value in R6's address
			mov.b R11, 0(R13) 	;Places higher value in R13's address
			inc R6				;If values are already sorted then go ahead and run again
			inc R13
			jmp RUN2


DONE		ret				;Places you back in the mainloop

;To bubble sort, you need to scan the array n-1 times,
;In every scan, you compare from top down each two consecutive elements, and you swap them if they are not in ascending order.
;Notice that in the first scan you get the largest element (no matter where it is in the array) pushed all the way to the bottom.
;So your next scan should be n-1 iterations, and then n-2 and so on.
;So every time you come back to the top of the array for a new scan, your n (the number of comparisons) must be decremented by 1.
;In the last scan, you need only one comparison.

;Hints:
;Your sorting algorithm starts with R6 as a pointer to the array
;you need to save n (number of elements) in R8, then decrement it by 1 (n-1) to become the number of comparisons.
;Copy R6 to R7 so you keep R6 unchanged as it points to the top of the array for every new scan.
;Copy n-1 to R9 and use R9 as a loop counter, while keeping the current n-1 value in R8 for the next scan.
;In the scan loop get an element and auto increment pointer R7, then get next element without changing R7.
;Compare the two elements, if not in ascending order, swap them.
;Repeat the scan from the top as pointed to by (R6), and every time decrement the number of comparisons (R8).


;-----  Your Sorting lab ends here   -------------------------------------------
;-------------------------------------------------------------------------------


;-------------------------------------------------------------------------------
;Stack Pointer definition
            	.global __STACK_END
            	.sect 	.stack
;-------------------------------------------------------------------------------
;Interrupt Vectors
            	.sect   ".reset"    ;MSP430 RESET Vector
            	.short  RESET

