/*
 * このファイルは tecsgen により自動生成されました
 * このファイルを編集して使用することは、意図されていません
 */
#ifndef GLOBAL_TECSGEN_H
#define GLOBAL_TECSGEN_H


/* import_C により import されるヘッダ #_IMP_# */
#include "tecs_kernel.h"
#include "tecs_mruby.h"
#include "ev3api_sensor.h"
#include "ev3api_motor.h"
#include "ev3api_button.h"
#include "ev3api_fs.h"
#include "ev3api_lcd.h"
#include "ev3api_led.h"
#include "ev3api_battery.h"
#include "tEV3Platform.h"
/**/

#ifndef TOPPERS_MACRO_ONLY

 extern void tLCD_CB_initialize();
 extern void nMruby_tTECSInitializer_CB_initialize();

#define INITIALIZE_TECS() \
 	tLCD_CB_initialize();\
 	nMruby_tTECSInitializer_CB_initialize();\
/* INITIALIZE_TECS terminator */

#define INITIALZE_TECSGEN() INITIALIZE_TECS()  /* for backward compatibility */

/* Descriptor for dynamic join */
#define Descriptor( signature_global_name )  DynDesc__ ## signature_global_name

#endif /* TOPPERS_MACRO_ONLY */


#endif /* GLOBAL_TECSGEN_H */
