
#ifndef XC_HEADER_TEMPLATE_H
#define	XC_HEADER_TEMPLATE_H

#include <xc.h> // include processor files - each processor file is guarded.  
#include <stdbool.h>

typedef enum{
    /** アルコール未検地(送信) */
    ALCOHOL_OK = 0x81,
    /** アルコール検知(送信)*/
    ALCOHOL_NG = 0x82,
    /** スキャン開始(受信)*/
    START_SCANNING = 0x80,
    /** スキャン停止(受信)*/
    STOP_SCANNING = 0x70,
    /** アルコール値を読み取る */
    READING_ALCOHOL_VALUE = 0x60
} ALCOHOL_DRIVE_COMMANDS;

/** アルコール検知センサー初期化*/
void init_alcohol();

/** AD変換初期化 */
void start_alcohol();

/**
 * アルコール検知を行う
 * @return true:アルコール未検地, false:アルコール検知
 */
unsigned short check_alcohol();

#endif	/* XC_HEADER_TEMPLATE_H */

