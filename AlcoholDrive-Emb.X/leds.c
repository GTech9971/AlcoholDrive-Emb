#include "leds.h"
#include <stdbool.h>
#include <xc.h>

#define LED_CONNECT_LAT LATCbits.LATC5
#define LED_SCANNING_LAT LATCbits.LATC4
#define LED_OK_LAT LATCbits.LATC3
#define LED_NG_LAT LATCbits.LATC6

#define LED_CONNECT_TRIS TRISCbits.TRISC5
#define LED_SCANNING_TRIS TRISCbits.TRISC4
#define LED_OK_TRIS TRISCbits.TRISC3
#define LED_NG_TRIS TRISCbits.TRISC6

#define LED_ON  1
#define LED_OFF 0

#define PIN_INPUT  1
#define PIN_OUTPUT 0


/**
 * LEDをオンにする
 * @param led オンにするLED
 */
void LED_On(LED led)
{
    switch(led)
    {
        case LED_CONNECT:
            LED_CONNECT_LAT = LED_ON;
            break;
        case LED_SCANNING:
            LED_SCANNING_LAT = LED_ON;
            break;
        case LED_OK:
            LED_OK_LAT = LED_ON;
            break;
        case LED_NG:
            LED_NG_LAT = LED_ON;
            break;
        case LED_NONE:
            break;
    }
}

/**
 * LEDをオフにする
 * @param led オフにするLED
 */
void LED_Off(LED led)
{
    switch(led)
    {
        case LED_CONNECT:
            LED_CONNECT_LAT = LED_OFF;
            break;
        case LED_SCANNING:
            LED_SCANNING_LAT = LED_OFF;
            break;
        case LED_OK:
            LED_OK_LAT = LED_OFF;
            break;
        case LED_NG:
            LED_NG_LAT = LED_OFF;
            break;
        case LED_NONE:
            break;
    }
}

/**
 * LEDを初期化する
 */
void LED_Init()
{
    LED_CONNECT_TRIS     = PIN_OUTPUT;
    LED_SCANNING_TRIS    = PIN_OUTPUT;
    LED_OK_TRIS          = PIN_OUTPUT;
    LED_NG_TRIS          = PIN_OUTPUT;
    
    LED_CONNECT_LAT     = LED_OFF;
    LED_SCANNING_LAT    = LED_OFF;
    LED_OK_LAT          = LED_OFF;
    LED_NG_LAT          = LED_OFF;
}
