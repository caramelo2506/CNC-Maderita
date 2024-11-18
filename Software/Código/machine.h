#ifndef MACHINE_H 
#define MACHINE_H 
// Nombre de la máquina 
#define MACHINE_NAME "CNC_Laser" 
// Pines para motores paso a paso 
#define X_STEP_PIN GPIO_NUM_25 #define X_DIR_PIN GPIO_NUM_26 #define Y_STEP_PIN GPIO_NUM_27 #define Y_DIR_PIN GPIO_NUM_14 
// Pines para sensores de fin de carrera #define X_LIMIT_PIN GPIO_NUM_32 #define Y_LIMIT_PIN GPIO_NUM_33 
// Control del láser (opcional) 
#define LASER_OUTPUT_PIN GPIO_NUM_12 #endif // MACHINE_H 
