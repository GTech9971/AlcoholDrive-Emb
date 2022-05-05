#ifndef LEDS_H
#define LEDS_H

#include <stdbool.h>

typedef enum
{
    LED_NONE,
    LED_CONNECT,
    LED_SCANNING,
    LED_OK,
    LED_NG
} LED;

#define LED_COUNT 4

void LED_On(LED led);

void LED_Off(LED led);

void LED_Init();

#endif //LEDS_H