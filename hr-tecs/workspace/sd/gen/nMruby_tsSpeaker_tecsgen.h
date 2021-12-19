/*
 * ���Υե������ tecsgen �ˤ�꼫ư��������ޤ���
 * ���Υե�������Խ����ƻ��Ѥ��뤳�Ȥϡ��տޤ���Ƥ��ޤ���
 */
#ifndef nMruby_tsSpeaker_TECSGEN_H
#define nMruby_tsSpeaker_TECSGEN_H

/*
 * celltype          :  tsSpeaker
 * global name       :  nMruby_tsSpeaker
 * idx_is_id(actual) :  yes(no)
 * singleton         :  no
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
typedef struct tag_nMruby_tsSpeaker_CB {
    int  dummy;
} nMruby_tsSpeaker_CB;
extern nMruby_tsSpeaker_CB  nMruby_tsSpeaker_CB_tab[];

/* ���륿���פ�IDX�� #_CTIX_# */
typedef int   nMruby_tsSpeaker_IDX;
#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* TOPPERS_MACRO_ONLY */

/* ��Ŭ���Τ��Ỳ�Ȥ��륻�륿���פ� CB ������������� #_ICT_# */
#ifndef  TOPPERS_CB_TYPE_ONLY
#define  nMruby_tsSpeaker_CB_TYPE_ONLY
#define TOPPERS_CB_TYPE_ONLY
#endif  /* TOPPERS_CB_TYPE_ONLY */
#include "tSpeaker_tecsgen.h"
#ifdef  nMruby_tsSpeaker_CB_TYPE_ONLY
#undef TOPPERS_CB_TYPE_ONLY
#endif /* nMruby_tsSpeaker_CB_TYPE_ONLY */
#ifndef TOPPERS_CB_TYPE_ONLY

#define nMruby_tsSpeaker_ID_BASE        (1)  /* ID �Υ١���  #_NIDB_# */
#define nMruby_tsSpeaker_N_CELL        (1)  /* ����θĿ�  #_NCEL_# */

/* IDX�������������å��ޥ��� #_CVI_# */
#define nMruby_tsSpeaker_VALID_IDX(IDX) (1)


/* ����CB������ޥ��� #_GCB_# */
#define nMruby_tsSpeaker_GET_CELLCB(idx) ((void *)0)
 /* �ƤӸ��ؿ��ޥ��� #_CPM_# */
#define nMruby_tsSpeaker_cTECS_setVolume( p_that, volume ) \
	  tSpeaker_eSpeaker_setVolume( \
	    (volume) )
#define nMruby_tsSpeaker_cTECS_playTone( p_that, frequency, duration ) \
	  tSpeaker_eSpeaker_playTone( \
	    (frequency), (duration) )
#define nMruby_tsSpeaker_cTECS_stop( p_that ) \
	  tSpeaker_eSpeaker_stop( \
	    )

#endif /* TOPPERS_CB_TYPE_ONLY */

#ifndef TOPPERS_MACRO_ONLY

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* TOPPERS_MACRO_ONLY */

#ifndef TOPPERS_CB_TYPE_ONLY

/* IDX�������������å��ޥ����û�̷��� #_CVIA_# */
#define VALID_IDX(IDX)  nMruby_tsSpeaker_VALID_IDX(IDX)


/* ����CB������ޥ���(û�̷�) #_GCBA_# */
#define GET_CELLCB(idx)  nMruby_tsSpeaker_GET_CELLCB(idx)

/* CELLCB ��(û�̷�) #_CCT_# */
#define CELLCB	nMruby_tsSpeaker_CB

/* ���륿���פ�IDX��(û�̷�) #_CTIXA_# */
#define CELLIDX	nMruby_tsSpeaker_IDX

#define tsSpeaker_IDX  nMruby_tsSpeaker_IDX
/* �ƤӸ��ؿ��ޥ����û�̷���#_CPMA_# */
#define cTECS_setVolume( volume ) \
                      ((void)p_cellcb, nMruby_tsSpeaker_cTECS_setVolume( p_cellcb, volume ))
#define cTECS_playTone( frequency, duration ) \
                      ((void)p_cellcb, nMruby_tsSpeaker_cTECS_playTone( p_cellcb, frequency, duration ))
#define cTECS_stop( ) \
                      ((void)p_cellcb, nMruby_tsSpeaker_cTECS_stop( p_cellcb ))

/* ���ƥ졼�������� (FOREACH_CELL)������(CB,INIB ��¸�ߤ��ʤ�) #_NFEC_# */
#define FOREACH_CELL(i,p_cb)   \
    for((i)=0;(i)<0;(i)++){

#define END_FOREACH_CELL   }

/* CB ������ޥ��� #_CIM_# */
#endif /* TOPPERS_CB_TYPE_ONLY */

#ifndef TOPPERS_MACRO_ONLY

#endif /* TOPPERS_MACRO_ONLY */

#endif /* nMruby_tsSpeaker_TECSGENH */
