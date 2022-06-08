#include "alcohol_drive.h"
#include <stdint.h>
#include <pic16f1459.h>

#define _XTAL_FREQ 48000000

#define PIN_INPUT  1
#define PIN_OUTPUT 0

/** アルコール検知センサー初期化*/
void init_alcohol(){
    TRISAbits.TRISA5 = PIN_INPUT;
    TRISAbits.TRISA4 = PIN_INPUT;
    ADCON0 = 0x00;
    ADCON1 = 0xE0; // Fosc 64
    
    start_alcohol();
}

/**
 * AD変換開始
 * @return 
 */
void start_alcohol(){
    ADCON0 = 0x0D;
    __delay_ms(5);
}

/**
 * アルコール検知を行う 3秒間ぐらい計測する
 * @return true:アルコール未検地, false:アルコール検知
 */
unsigned short check_alcohol(){
//    bool ret = true;
//    uint16_t max = 300;
//    for(uint16_t i = 0; i < max; i++){
//        //0でアルコール未検地
//        if(PORTAbits.RA5 == 0){
//            ret = false;
//        }
//        __delay_ms(10);
//    }
//    return ret;
    ADCON0bits.ADON = 1;
    
    __delay_us(5);
    ADCON0bits.GO_nDONE = 1;
    while(ADCON0bits.GO_nDONE);
    unsigned short value = (ADRESH << 8) + (ADRESL);
    return value;
}