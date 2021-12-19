/*
 * このファイルは tecsgen により自動生成されました
 * このファイルを編集して使用することは、意図されていません
 */
#include "nMruby_tsMotor_tecsgen.h"
#include "nMruby_tsMotor_factory.h"


/* 呼び口の参照する受け口ディスクリプタ(実際の型と相違した定義) #_CPEPD_# */
extern struct tag_sMotor_VDES rDomainEV3_MotorA_eMotor_des;

extern struct tag_sMotor_VDES rDomainEV3_MotorB_eMotor_des;

extern struct tag_sMotor_VDES rDomainEV3_MotorC_eMotor_des;

extern struct tag_sMotor_VDES rDomainEV3_MotorD_eMotor_des;

/* 呼び口配列 #_CPA_# */




/* 属性・変数の配列 #_AVAI_# */
/* セル INIB #_INIB_# */
nMruby_tsMotor_INIB nMruby_tsMotor_INIB_tab[] = {
    /* cell: nMruby_tsMotor_CB_tab[0]:  BridgeMotorA id=1 */
    {
        /* call port #_CP_# */ 
        &tMotor_CB_tab[0],                       /* cTECS #_CCP2_# */
    },
    /* cell: nMruby_tsMotor_CB_tab[1]:  BridgeMotorB id=2 */
    {
        /* call port #_CP_# */ 
        &tMotor_CB_tab[1],                       /* cTECS #_CCP2_# */
    },
    /* cell: nMruby_tsMotor_CB_tab[2]:  BridgeMotorC id=3 */
    {
        /* call port #_CP_# */ 
        &tMotor_CB_tab[2],                       /* cTECS #_CCP2_# */
    },
    /* cell: nMruby_tsMotor_CB_tab[3]:  BridgeMotorD id=4 */
    {
        /* call port #_CP_# */ 
        &tMotor_CB_tab[3],                       /* cTECS #_CCP2_# */
    },
};

/* 受け口ディスクリプタ #_EPD_# */
