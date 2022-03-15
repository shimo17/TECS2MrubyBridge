/*
 * このファイルは tecsgen により自動生成されました
 * このファイルを編集して使用することは、意図されていません
 */
#ifndef GLOBAL_TECSGEN_H
#define GLOBAL_TECSGEN_H


/* import_C により import されるヘッダ #_IMP_# */
#include "tecs_kernel.h"
#include "tecs_mruby.h"
/**/

#ifndef TOPPERS_MACRO_ONLY

 extern void nTECS2Mruby_tsDynamic_CB_initialize();
 extern void tTask_CB_initialize();
 extern void tTECS2MrubyVM_CB_initialize();
 extern void tTestMain_CB_initialize();

#define INITIALIZE_TECS() \
 	nTECS2Mruby_tsDynamic_CB_initialize();\
 	tTask_CB_initialize();\
 	tTECS2MrubyVM_CB_initialize();\
 	tTestMain_CB_initialize();\
/* INITIALIZE_TECS terminator */

#define INITIALZE_TECSGEN() INITIALIZE_TECS()  /* for backward compatibility */

/* Descriptor for dynamic join */
#define Descriptor( signature_global_name )  DynDesc__ ## signature_global_name
#define is_descriptor_unjoined( desc )  ((desc).vdes==NULL)

#endif /* TOPPERS_MACRO_ONLY */

#define MRUBY_VM_STACK_SIZE ((const int32_t)81920)

#endif /* GLOBAL_TECSGEN_H */
