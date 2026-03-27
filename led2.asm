;=====================================
; PIC16F877A - Blink LED en RB0
; Oscilador: HS (High Speed)
; Propósito: Parpadeo simple de LED
;=====================================

LIST P=PIC16F877A
INCLUDE "P16F877A.INC"

;---- Variables en RAM ----
CBLOCK 0x20
    DELAY_OUTER    ; Contador externo de delay
    DELAY_INNER    ; Contador interno de delay
ENDC

;---- Configuración ----
__CONFIG _FOSC_HS & _WDTE_OFF & _PWRTE_ON & _BOREN_OFF & _LVP_OFF & _CPD_OFF & _WRT_OFF & _CP_OFF

;---- Inicio del programa ----
ORG 0x0000
    GOTO    INICIO

;---- Tabla de interrupciones (no usada en este caso) ----
ORG 0x0004
    RETFIE

;---- Programa principal ----
INICIO:
    ; Configurar banco 1
    BSF     STATUS, RP0     ; Banco 1
    BCF     STATUS, RP1     ; (RP0=1, RP1=0)
    
    ; Configurar RB0 como salida
    BCF     TRISB, RB0      ; RB0 = salida
    
    ; Volver a banco 0
    BCF     STATUS, RP0
    
    ; Limpiar PORTB
    CLRF    PORTB

;---- Loop principal ----
LOOP:
    ; Apagar LED
    BCF     PORTB, RB0
    CALL    DELAY_MS        ; ~1000ms (ajustable)
    
    ; Encender LED
    BSF     PORTB, RB0
    CALL    DELAY_MS        ; ~1000ms (ajustable)
    
    GOTO    LOOP

;=====================================
; Subrutina: Delay de ~1000ms
; (Ajustable según necesidad)
;=====================================
DELAY_MS:
    MOVLW   0x08            ; 8 iteraciones externas
    MOVWF   DELAY_OUTER

LOOP_OUT:
    MOVLW   0xFF            ; 255 iteraciones internas
    MOVWF   DELAY_INNER

LOOP_IN:
    DECFSZ  DELAY_INNER, F  ; Decrementa y salta si es 0
    GOTO    LOOP_IN
    
    NOP                     ; Ajuste fino de timing
    NOP
    
    DECFSZ  DELAY_OUTER, F  ; Decrementa contador externo
    GOTO    LOOP_OUT
    
    RETURN

;---- Fin del programa ----
END
