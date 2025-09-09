#include <xc164.h>
#include <stdio.h>
#include <stdbool.h>

// Simulación de registros para GPIO/NVRAM de Atmel
#define NVRAM_ADDR      (*(volatile unsigned char*)0xE0001000)
#define NVRAM_DATA      (*(volatile unsigned char*)0xE0001001)

// Pines ficticios, ajústalos a tu hardware
#define MOTOR_PWM_PIN      P3_0
#define TEMP_SENSOR_PIN    P4_1
#define DOOR_SWITCH_PIN    P3_2
#define EMERGENCY_STOP_PIN P3_3

// Parámetros configurables
#define MAX_SPEED          1000    // RPM
#define MIN_SPEED          0
#define ACCELERATION_RATE  100     // RPM/seg
#define DECELERATION_RATE  100     // RPM/seg
#define MAX_TEMPERATURE    80      // ºC
#define PROGRAM_COUNT      5

// Prototipos
void init_system();
void start_motor(int target_speed);
void stop_motor();
void ramp_speed(int from, int to, int rate);
int read_temperature();
bool is_door_closed();
bool is_emergency_stop_pressed();
void save_program_number(unsigned char prog_num);
unsigned char read_program_number();

void delay_ms(unsigned int ms);

// Variables globales
int current_speed = 0;
bool motor_running = false;

void main(void) {
    unsigned char program_number = 0;
    int target_speed = 800; // RPM
    int operation_time_s = 60; // segundos

    init_system();

    // Leer programa de NVRAM
    program_number = read_program_number();

    // Verificar seguridad antes de arrancar
    if (!is_door_closed()) {
        printf("Puerta abierta. No se puede iniciar el motor.\n");
        return;
    }
    if (is_emergency_stop_pressed()) {
        printf("Parada de emergencia activada. No se puede iniciar el motor.\n");
        return;
    }

    // Guardar programa en NVRAM
    save_program_number(program_number);

    // Arranque con aceleración
    start_motor(target_speed);

    // Funcionamiento durante el tiempo definido
    int elapsed = 0;
    while (elapsed < operation_time_s) {
        // Comprobar condiciones de seguridad
        if (!is_door_closed() || is_emergency_stop_pressed()) {
            printf("Seguridad activada. Parando motor!\n");
            stop_motor();
            return;
        }
        // Comprobar temperatura
        int temp = read_temperature();
        if (temp > MAX_TEMPERATURE) {
            printf("Temperatura excesiva! Parando motor!\n");
            stop_motor();
            return;
        }
        delay_ms(1000);
        elapsed++;
    }

    // Parada con rampa de desaceleración
    stop_motor();

    printf("Programa finalizado correctamente.\n");
}

void init_system() {
    // Configuración de pines, timers, ADC, etc.
    // (Omitido: depende del hardware real)
}

void start_motor(int target_speed) {
    printf("Arrancando motor hasta %d RPM...\n", target_speed);
    ramp_speed(current_speed, target_speed, ACCELERATION_RATE);
    motor_running = true;
}

void stop_motor() {
    printf("Parando motor...\n");
    ramp_speed(current_speed, 0, DECELERATION_RATE);
    motor_running = false;
}

void ramp_speed(int from, int to, int rate) {
    int step = (to > from) ? rate : -rate;
    int speed = from;
    while (speed != to) {
        speed += step;
        if ((step > 0 && speed > to) || (step < 0 && speed < to))
            speed = to;
        // Simular PWM (reemplazar por configuración real de PWM)
        MOTOR_PWM_PIN = (speed > 0) ? 1 : 0;
        current_speed = speed;
        printf("Velocidad actual: %d RPM\n", current_speed);
        delay_ms(1000); // 1 segundo por paso de rampa (ajustable)
    }
}

// Simulación de funciones de hardware
int read_temperature() {
    // Simular lectura de sensor
    return 25; // valor fijo o leer ADC real
}

bool is_door_closed() {
    return DOOR_SWITCH_PIN == 1; // 1 = cerrada
}

bool is_emergency_stop_pressed() {
    return EMERGENCY_STOP_PIN == 1; // 1 = activado
}

void save_program_number(unsigned char prog_num) {
    NVRAM_ADDR = 0x01;
    NVRAM_DATA = prog_num;
}

unsigned char read_program_number() {
    NVRAM_ADDR = 0x01;
    return NVRAM_DATA;
}

void delay_ms(unsigned int ms) {
    // Simular retardo (ajustar a temporizador real)
    volatile unsigned int i, j;
    for (i = 0; i < ms; i++)
        for (j = 0; j < 600; j++);
}
