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
Setup 	clr R4 	;clear the entire R4 register
		clr R5 	;clear the entire R5 register
		clr R6 	;clear the entire R6 register
		clr R7 	;clear the entire R7 register
		clr R10 ;clear the entire R10 register


		mov #04, R4
		mov #03, R5
		mov #10, R6
		mov #15, R10


Addition 	add R4, R7
			add R5, R7
			add R6, R7

Subtraction sub R10, R7

Store 		;Store the content of all Register used
		 	;into memory including results in the
			;Order R4, R5, R6, R10, R7.


			mov R4, &0200h
			mov R5, &0202h
			mov R6, &0204h
			mov R10, &0206h
			mov R7, &0208h


Mainloop jmp Mainloop ;Infinite Loop
;-------------------------------------------------------------------------------

                                            

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
            
