;-------------------------------------------------------------------------------
; MSP430 Assembler Code Template for use with TI Code Composer Studio
;
;
;-------------------------------------------------------------------------------
            .cdecls C,LIST,"msp430.h"       ; Include device header file
            
;-------------------------------------------------------------------------------
            .def    RESET                   ; Export program entry-point to
                                            ; make it known to linker.
;-------------------------------------------------------------------------------
            .text                           ; Assemble into program memory.
            .retain                         ; Override ELF conditional linking
                                            ; and retain current section.
            .retainrefs                     ; And retain any sections that have
                                            ; references to current section.

;-------------------------------------------------------------------------------
RESET       mov.w   #__STACK_END,SP         ; Initialize stackpointer
StopWDT     mov.w   #WDTPW|WDTHOLD,&WDTCTL  ; Stop watchdog timer


;-------------------------------------------------------------------------------
; Main loop here
;-------------------------------------------------------------------------------

Lab3		mov.w 	#5, R4		;set up the initial a value in R4
			clr.w	R5
			clr.w	R6
			clr.w	R7
			clr.w	R8
			clr.w	R9
			clr.w	R10
			clr.w	R11



Xcalc		mov.w	R4, R5		;copy the a value into R5
			call 	#ABSOL		;computer the absolute value of a in R5
			mov.w #0, R8		;Moves 0 to accumulator(R8)

Summation	mov.w 	R5, R6		;starting the upper limit with value a of the summation in R6
			mov.w	R5, R7 		;Copies a into R7
			mov.w	#1, R12		;Sets up special case for 1!
			mov.w	#0, R13		;Sets up special case for 0!

SUM1		cmp.w	R6, R12
			jeq		FACT1
			cmp.w	R6, R13
			jeq		FACT1
			call 	#FACTO		;get the factorial value of R6 and save in R6
SUM2		mov.w	#2, R5
			call	#MULT		;multiply R5 * R6 (2 * a!)
			add.w	R6, R8		;Adds value calculated to accumulator (R8)
			dec R7				;Decrements a from value in R7
			jz XCalcEnd
			mov.w R7, R6		;Moves a-1 into R6 for next loop
			jmp SUM1			;Jumps to top of loop

FACT1		mov.w #1, R6
			jmp SUM2



XCalcEnd 	add.w #2, R8	;Accounts for 2*0!
			mov.w R8, R5	;Moves accumlated value to R5
			jmp Fcalc		;Jumps to Calculating F


Fcalc		mov.w 	R5, R6		;start F calculation by moving x to R6
			mov.w	R5, R8		;Saved X in R8
			mov.w 	#2, R5		;Moves 2 to R5 to make it the multiplier
			call #MULT			;calls MULT to multiple 2*X
			add.w	#55, R6		;adds constant 55
			clrc 				;Clears carry making C=0 to set up division
			rrc.w 	R6
			clrc				;Clears carry making C=0 to set up division
			rrc.w 	R6
			mov.w R6, R7		;Stores final result in R7
			mov.w R8, R5		;Stores X back in R5

loop		jmp 	loop		;loop in place



;Absolute subroutine take a value form R5 and converts it to its absolute value
ABSOL:
			tst 	R5
			jn		twoscompl
			ret
twoscompl	inv 	R5
			inc		R5
ABSOLend	ret







;Factorial subroutine takes number n form R6 and compute/save n! in R6
;You need to replace the NOP with your actual n! calculation as given in class
;You must push/pop all registers
FACTO:		;R6 already contains (n) number to find factorial of
			mov.w R6, R9	;Moves n to R9
			mov.w R6, R5	;Moves the value from R6 to R5 to set up multiplication
			inc R9

SETUP1		dec R9			;Decrements R9 by 1, making it n(number of times you need to loop), also loop counter
			jz FACTOend		;If R9 is 0, jump to end


SETUP2		dec R9
			dec R5			;Makes R5's value one less than R6
			call #MULT		;Multiplies R6 and R5 (n * n-1) and stores it in R6
			mov.w R9, R10	;Secondary Check
			dec R10
			jz SETUP1		;Jumps back to SETUP1 if 0
			jmp SETUP2

FACTOend	ret


;The multiplier subroutine based on shift and add
;It takes R5 as the multiplier and R6 as the multiplicand
;to avoid multiplication overflow, both R5 and R6 should be limited to one byte and thus ANDed with 0X00FF.
;but due to factorial calculation, we will not mask R6 to let it grow beyond 255
MULT:
			push.w	R5;
			push.w	R7;
			push.w 	R8;
			mov.w	#8, R8		;8 bit multiplication, so we loop 8 times
			clr.w	R7			;additive accumulator should start with zero
			and.w	#0x00FF, R5	;clear upper 8 bits of multiplier
			;and.w 	#0x00FF, R6	;clear upper 8 bits of multiplicand

nextbit		rrc.w	R5			;shift multiplier bits one at a time to the carry
			jnc		twice		;if no carry skip the add
addmore		add.w	R6, R7		;add a copy of the multiplicand to the accumulator
twice		add.w	R6, R6		;multiplicand times 2, (shifted 1 bit left)
			dec.w 	R8			;dec loop counter
			jnz		nextbit		;jump to check next bit of the multiplier
			mov.w 	R7, R6		;save the result in R6

			pop.w	R8;
			pop.w	R7;
			pop.w 	R5;

MULTend		ret

;-------------------------------------------------------------------------------
; Stack Pointer definition
;-------------------------------------------------------------------------------
            .global __STACK_END
            .sect   .stack
            
;-------------------------------------------------------------------------------
; Interrupt Vectors
;-------------------------------------------------------------------------------
            .sect   ".reset"                ; MSP430 RESET Vector
            .short  RESET
            
