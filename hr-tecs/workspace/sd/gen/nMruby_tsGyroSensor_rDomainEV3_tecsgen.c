/*
 * ���Υե������ tecsgen �ˤ�꼫ư��������ޤ���
 * ���Υե�������Խ����ƻ��Ѥ��뤳�Ȥϡ��տޤ���Ƥ��ޤ���
 */
#include "nMruby_tsGyroSensor_tecsgen.h"
#include "nMruby_tsGyroSensor_factory.h"


/* �ƤӸ��λ��Ȥ���������ǥ�������ץ�(�ºݤη�����㤷�����) #_CPEPD_# */
extern struct tag_sGyroSensor_VDES rDomainEV3_GyroSensor1_eGyroSensor_des;

extern struct tag_sGyroSensor_VDES rDomainEV3_GyroSensor2_eGyroSensor_des;

extern struct tag_sGyroSensor_VDES rDomainEV3_GyroSensor3_eGyroSensor_des;

extern struct tag_sGyroSensor_VDES rDomainEV3_GyroSensor4_eGyroSensor_des;

/* �ƤӸ����� #_CPA_# */




/* °�����ѿ������� #_AVAI_# */
/* ���� INIB #_INIB_# */
nMruby_tsGyroSensor_INIB nMruby_tsGyroSensor_INIB_tab[] = {
    /* cell: nMruby_tsGyroSensor_CB_tab[0]:  BridgeGyroSensor1 id=1 */
    {
        /* call port #_CP_# */ 
        &tGyroSensor_CB_tab[0],                  /* cTECS #_CCP2_# */
    },
    /* cell: nMruby_tsGyroSensor_CB_tab[1]:  BridgeGyroSensor2 id=2 */
    {
        /* call port #_CP_# */ 
        &tGyroSensor_CB_tab[1],                  /* cTECS #_CCP2_# */
    },
    /* cell: nMruby_tsGyroSensor_CB_tab[2]:  BridgeGyroSensor3 id=3 */
    {
        /* call port #_CP_# */ 
        &tGyroSensor_CB_tab[2],                  /* cTECS #_CCP2_# */
    },
    /* cell: nMruby_tsGyroSensor_CB_tab[3]:  BridgeGyroSensor4 id=4 */
    {
        /* call port #_CP_# */ 
        &tGyroSensor_CB_tab[3],                  /* cTECS #_CCP2_# */
    },
};

/* �������ǥ�������ץ� #_EPD_# */
