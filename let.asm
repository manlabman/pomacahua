	    LIST P=PIC16F877A
	    INCLUDE "P16F877A.INC"
	    CBLOCK 0X20
	    T1
	    T2
	    __CONFIG _FOSC_HS & _WDTE_OFF & _PWRTE_ON & _BOREN_OFF & _LVP_OFF & CPD_OFF & WRT_OFF & _CP_OFF
	    ORG OX0000
	    BSF		    STATUS, RP0
	    BCF		    STATUS, RP1
	    BCF		    TRISB,  RB0
	    BCF		    STATUS, RP0
END
	    BCF		    PORTB, RB0
	    CALL	    RETARDO
	    BSF		    PORTB, RB0
	    CALL	    RETARDO
	    GOTO	    FIN
	    
RETARDO	    MOVLW	    0xFF
	    MOVWF	    T1
X1	    CALL	    RETARDO2
	    DECFSZ	    T1
	    GOTO	    X1
	    RETURN
RETARDO2    MOVLW	    0XFF
	    MOVWF	    T2
X2	    DECFSZ	    T2
	    GOTO	    X2
	    RETURN
	    END
