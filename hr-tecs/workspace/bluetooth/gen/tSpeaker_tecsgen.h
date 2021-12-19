/*
 * ���Υե������ tecsgen �ˤ�꼫ư��������ޤ���
 * ���Υե�������Խ����ƻ��Ѥ��뤳�Ȥϡ��տޤ���Ƥ��ޤ���
 */
#ifndef tSpeaker_TECSGEN_H
#define tSpeaker_TECSGEN_H

/*
 * celltype          :  tSpeaker
 * global name       :  tSpeaker
 * idx_is_id(actual) :  no(no)
 * singleton         :  yes
 * has_CB            :  false
 * has_INIB          :  false
 * rom               :  yes
 * CB initializer    :  no
 */

/* �����Х�إå� #_IGH_# */
#include "global_tecsgen.h"

/* �����˥���إå� #_ISH_# */
#include "sSpeaker_tecsgen.h"

#ifndef TOPPERS_MACRO_ONLY

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
/* ���� CB (���ߡ�)����� #_CCDP_# */
typedef struct tag_tSpeaker_CB {
    int  dummy;
} tSpeaker_CB;
/* ���󥰥�ȥ󥻥� CB �ץ�ȥ�������� #_SCP_# */


/* ���륿���פ�IDX�� #_CTIX_# */
typedef int   tSpeaker_IDX;

/* �������ؿ��ץ�ȥ�������� #_EPP_# */
/* sSpeaker */
ER           tSpeaker_eSpeaker_setVolume( uint8_t volume);
ER           tSpeaker_eSpeaker_playTone( uint16_t frequency, int32_t duration);
ER           tSpeaker_eSpeaker_stop();
#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* TOPPERS_MACRO_ONLY */

#ifndef TOPPERS_CB_TYPE_ONLY


/* ����CB������ޥ��� #_GCB_# */
#define tSpeaker_GET_CELLCB(idx) ((void *)0)
#endif /* TOPPERS_CB_TYPE_ONLY */

#ifndef TOPPERS_MACRO_ONLY

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* ������������ȥ�ؿ��ץ�ȥ����������VMT���׺�Ŭ���ˤ�껲�Ȥ����Ρ� #_EPSP_# */

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* TOPPERS_MACRO_ONLY */

#ifndef TOPPERS_CB_TYPE_ONLY


/* ����CB������ޥ���(û�̷�) #_GCBA_# */
#define GET_CELLCB(idx)  tSpeaker_GET_CELLCB(idx)

/* CELLCB ��(û�̷�) #_CCT_# */
#define CELLCB	tSpeaker_CB

/* ���륿���פ�IDX��(û�̷�) #_CTIXA_# */
#define CELLIDX	tSpeaker_IDX


/* �������ؿ��ޥ����û�̷��� #_EPM_# */
#define eSpeaker_setVolume tSpeaker_eSpeaker_setVolume
#define eSpeaker_playTone tSpeaker_eSpeaker_playTone
#define eSpeaker_stop    tSpeaker_eSpeaker_stop

/* CB ������ޥ��� #_CIM_# */
#endif /* TOPPERS_CB_TYPE_ONLY */

#ifndef TOPPERS_MACRO_ONLY

#endif /* TOPPERS_MACRO_ONLY */

#endif /* tSpeaker_TECSGENH */
