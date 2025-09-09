# pomacahua
# Control de Motor de Inducción con Microcontrolador XC164

Este proyecto implementa un sistema de control para motores de inducción utilizando el microcontrolador XC164. El sistema está diseñado para aplicaciones industriales y educativas, permitiendo el control eficiente y seguro de motores trifásicos de inducción.

## Tabla de Contenidos

- [Descripción](#descripción)
- [Características](#características)
- [Requisitos](#requisitos)
- [Instalación](#instalación)
- [Uso](#uso)
- [Estructura del repositorio](#estructura-del-repositorio)
- [Autores](#autores)
- [Licencia](#licencia)

## Descripción

El objetivo de este proyecto es controlar la velocidad y el sentido de giro de un motor de inducción trifásico mediante técnicas de modulación y control implementadas en el microcontrolador XC164. Incluye rutinas de sensado, generación de PWM, protección y comunicación básica para la supervisión del sistema.

## Características

- Control de velocidad y sentido de giro.
- Generación de señales PWM para el inversor.
- Lectura y monitoreo de sensores (corriente, voltaje, temperatura).
- Algoritmos de protección ante fallos.
- Interfaz de comunicación básica (UART, CAN o similar).
- Código modular y fácilmente extensible.

## Requisitos

### Hardware

- Microcontrolador Infineon XC164.
- Motor de inducción trifásico.
- Inversor de potencia compatible.
- Sensores de corriente, voltaje y temperatura.
- Fuente de alimentación adecuada.
- (Opcional) Interfaz de comunicación externa (UART, CAN, etc.).

### Software

- Entorno de desarrollo para XC164 (por ejemplo, Keil u otro IDE compatible).
- Herramientas de programación y depuración para XC164.

## Instalación

1. Clona este repositorio:
   ```bash
   git clone https://github.com/manlabman/pumacahua.git
   ```
2. Abre el proyecto en tu IDE para XC164.
3. Configura las rutas de los archivos fuente y las opciones de compilación según tu entorno.
4. Compila el código y programa el microcontrolador.

## Uso

1. Conecta el hardware según el diagrama de conexiones.
2. Alimenta el sistema y conecta el motor de inducción.
3. Utiliza la interfaz de comunicación para configurar parámetros y monitorear el estado.
4. El sistema permite ajustar la velocidad y monitorear variables en tiempo real.

## Estructura del repositorio

```
pumacahua/
├── src/               # Código fuente principal
├── include/           # Archivos de cabecera
├── docs/              # Documentación y diagramas
├── hardware/          # Esquemáticos y diagramas de conexión
├── README.md
└── ...
```

## Autores

- Equipo de desarrollo de pumacahua
- [Tu nombre o grupo]

## Licencia

Este proyecto se distribuye bajo la licencia MIT. Consulta el archivo LICENSE para más información.
