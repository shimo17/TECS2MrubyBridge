/*
 * ���Υե������ tecsgen �ˤ�꼫ư��������ޤ���
 * ���Υե�������Խ����ƻ��Ѥ��뤳�Ȥϡ��տޤ���Ƥ��ޤ���
 */
#ifndef nMruby_tsBattery_TECSGEN_H
#define nMruby_tsBattery_TECSGEN_H

/*
 * celltype          :  tsBattery
 * global name       :  nMruby_tsBattery
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
#include "sBattery_tecsgen.h"

#ifndef TOPPERS_MACRO_ONLY

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
/* ���� CB (���ߡ�)����� #_CCDP_# */
typedef struct tag_nMruby_tsBattery_CB {
    int  dummy;
} nMruby_tsBattery_CB;
extern nMruby_tsBattery_CB  nMruby_tsBattery_CB_tab[];

/* ���륿���פ�IDX�� #_CTIX_# */
typedef int   nMruby_tsBattery_IDX;
#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* TOPPERS_MACRO_ONLY */

/* ��Ŭ���Τ��Ỳ�Ȥ��륻�륿���פ� CB ������������� #_ICT_# */
#ifndef  TOPPERS_CB_TYPE_ONLY
#define  nMruby_tsBattery_CB_TYPE_ONLY
#define TOPPERS_CB_TYPE_ONLY
#endif  /* TOPPERS_CB_TYPE_ONLY */
#include "tBattery_tecsgen.h"
#ifdef  nMruby_tsBattery_CB_TYPE_ONLY
#undef TOPPERS_CB_TYPE_ONLY
#endif /* nMruby_tsBattery_CB_TYPE_ONLY */
#ifndef TOPPERS_CB_TYPE_ONLY

#define nMruby_tsBattery_ID_BASE        (1)  /* ID �Υ١���  #_NIDB_# */
#define nMruby_tsBattery_N_CELL        (1)  /* ����θĿ�  #_NCEL_# */

/* IDX�������������å��ޥ��� #_CVI_# */
#define nMruby_tsBattery_VALID_IDX(IDX) (1)


/* ����CB������ޥ��� #_GCB_# */
#define nMruby_tsBattery_GET_CELLCB(idx) ((void *)0)
 /* �ƤӸ��ؿ��ޥ��� #_CPM_# */
#define nMruby_tsBattery_cTECS_current_mA( p_that ) \
	  tBattery_eBattery_current_mA( \
	   (tBattery_IDX)0 )
#define nMruby_tsBattery_cTECS_voltage_mV( p_that ) \
	  tBattery_eBattery_voltage_mV( \
	   (tBattery_IDX)0 )

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
#define VALID_IDX(IDX)  nMruby_tsBattery_VALID_IDX(IDX)


/* ����CB������ޥ���(û�̷�) #_GCBA_# */
#define GET_CELLCB(idx)  nMruby_tsBattery_GET_CELLCB(idx)

/* CELLCB ��(û�̷�) #_CCT_# */
#define CELLCB	nMruby_tsBattery_CB

/* ���륿���פ�IDX��(û�̷�) #_CTIXA_# */
#define CELLIDX	nMruby_tsBattery_IDX

#define tsBattery_IDX  nMruby_tsBattery_IDX
/* �ƤӸ��ؿ��ޥ����û�̷���#_CPMA_# */
#define cTECS_current_mA( ) \
                      ((void)p_cellcb, nMruby_tsBattery_cTECS_current_mA( p_cellcb ))
#define cTECS_voltage_mV( ) \
                      ((void)p_cellcb, nMruby_tsBattery_cTECS_voltage_mV( p_cellcb ))

/* ���ƥ졼�������� (FOREACH_CELL)������(CB,INIB ��¸�ߤ��ʤ�) #_NFEC_# */
#define FOREACH_CELL(i,p_cb)   \
    for((i)=0;(i)<0;(i)++){

#define END_FOREACH_CELL   }

/* CB ������ޥ��� #_CIM_# */
#endif /* TOPPERS_CB_TYPE_ONLY */

#ifndef TOPPERS_MACRO_ONLY

#endif /* TOPPERS_MACRO_ONLY */

#endif /* nMruby_tsBattery_TECSGENH */
