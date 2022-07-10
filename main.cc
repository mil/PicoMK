#include <stdio.h>

#include "FreeRTOS.h"
// #include "hardware/clocks.h"
// #include "hardware/i2c.h"
// #include "hardware/watchdog.h"
#include "runner.h"
#include "pico/stdlib.h"
#include "utils.h"

// I2C defines
// This example will use I2C0 on GPIO8 (SDA) and GPIO9 (SCL) running at 400KHz.
// Pins can be changed, see the GPIO function select table in the datasheet for
// information on GPIO assignments
// #define I2C_PORT i2c0
// #define I2C_SDA 8
// #define I2C_SCL 9

extern "C" void vApplicationMallocFailedHook(void) {
  LOG_ERROR("Failed malloc. OOM");
}
extern "C" void vApplicationIdleHook(void) {}
extern "C" void vApplicationStackOverflowHook(TaskHandle_t pxTask,
                                              char *pcTaskName) {
  LOG_ERROR("Stack overflow for task %s", pcTaskName);
}
extern "C" void vApplicationTickHook(void) {}

int main() {
  // // I2C Initialisation. Using it at 400Khz.
  // i2c_init(I2C_PORT, 400 * 1000);
  // gpio_set_function(I2C_SDA, GPIO_FUNC_I2C);
  // gpio_set_function(I2C_SCL, GPIO_FUNC_I2C);
  // gpio_pull_up(I2C_SDA);
  // gpio_pull_up(I2C_SCL);

  RunnerInit();
  RunnerStart();

  vTaskStartScheduler();

  while (true)
    ;

  return 0;
}
