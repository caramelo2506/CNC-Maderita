#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "Grbl_Esp32.h"
#include "machine.h"

// Configuración de los sensores de fin de carrera
void config_limit_switches(void) {
    gpio_set_direction(X_LIMIT_MIN_PIN, GPIO_MODE_INPUT);
    gpio_set_direction(X_LIMIT_MAX_PIN, GPIO_MODE_INPUT);
    gpio_set_direction(Y_LIMIT_MIN_PIN, GPIO_MODE_INPUT);
    gpio_set_direction(Y_LIMIT_MAX_PIN, GPIO_MODE_INPUT);
}

// Comprobar el estado de los sensores de fin de carrera
void check_limit_switches(void) {
    if (gpio_get_level(X_LIMIT_MIN_PIN) == 0) {
        printf("Fin de carrera X MIN alcanzado\n");
    }
    if (gpio_get_level(X_LIMIT_MAX_PIN) == 0) {
        printf("Fin de carrera X MAX alcanzado\n");
    }
    if (gpio_get_level(Y_LIMIT_MIN_PIN) == 0) {
        printf("Fin de carrera Y MIN alcanzado\n");
    }
    if (gpio_get_level(Y_LIMIT_MAX_PIN) == 0) {
        printf("Fin de carrera Y MAX alcanzado\n");
    }
}

void app_main(void) {
    // Imprimir mensaje de inicio
    printf("Inicializando Grbl CNC...\n");

    // Configurar los pines de los sensores de fin de carrera
    config_limit_switches();

    // Inicializa Grbl
    grbl_esp32_init();

    // Bucle principal
    while (1) {
        // Comprobar el estado de los sensores de fin de carrera
        check_limit_switches();

        // Llamar al ciclo principal de Grbl para procesar comandos G-code
        grbl_esp32_loop();

        // Retraso para no saturar el procesador
        vTaskDelay(10 / portTICK_PERIOD_MS);
    }
}

