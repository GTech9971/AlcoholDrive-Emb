#include "alcohol_drive.h"
#include <stdint.h>

#define PIN_INPUT  1
#define PIN_OUTPUT 0

/** アルコール検知センサー初期化*/
void init_alcohol(){
    TRISAbits.TRISA5 = PIN_INPUT;
}

/**
 * アルコール検知を行う
 * @return true:アルコール未検地, false:アルコール検知
 */
bool check_alcohol(){
    bool ret = true;
    for(uint8_t i = 0; i < 100; i++){
        //0でアルコール未検地
        if(PORTAbits.RA5 == 0){
            ret = false;
            break;
        }
    }
    return ret;
}