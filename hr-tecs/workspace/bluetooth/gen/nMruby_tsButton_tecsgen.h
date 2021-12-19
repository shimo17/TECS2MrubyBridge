/*
 * ���Υե������ tecsgen �ˤ�꼫ư��������ޤ���
 * ���Υե�������Խ����ƻ��Ѥ��뤳�Ȥϡ��տޤ���Ƥ��ޤ���
 */
#ifndef nMruby_tsButton_TECSGEN_H
#define nMruby_tsButton_TECSGEN_H

/*
 * celltype          :  tsButton
 * global name       :  nMruby_tsButton
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
#include "sButton_tecsgen.h"

#ifndef TOPPERS_MACRO_ONLY

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
/* ���� CB (���ߡ�)����� #_CCDP_# */
typedef struct tag_nMruby_tsButton_CB {
    int  dummy;
} nMruby_tsButton_CB;
extern nMruby_tsButton_CB  nMruby_tsButton_CB_tab[];

/* ���륿���פ�IDX�� #_CTIX_# */
typedef int   nMruby_tsButton_IDX;
#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* TOPPERS_MACRO_ONLY */

/* ��Ŭ���Τ��Ỳ�Ȥ��륻�륿���פ� CB ������������� #_ICT_# */
#ifndef  TOPPERS_CB_TYPE_ONLY
#define  nMruby_tsButton_CB_TYPE_ONLY
#define TOPPERS_CB_TYPE_ONLY
#endif  /* TOPPERS_CB_TYPE_ONLY */
#include "tButton_tecsgen.h"
#ifdef  nMruby_tsButton_CB_TYPE_ONLY
#undef TOPPERS_CB_TYPE_ONLY
#endif /* nMruby_tsButton_CB_TYPE_ONLY */
#ifndef TOPPERS_CB_TYPE_ONLY

#define nMruby_tsButton_ID_BASE        (1)  /* ID �Υ١���  #_NIDB_# */
#define nMruby_tsButton_N_CELL        (1)  /* ����θĿ�  #_NCEL_# */

/* IDX�������������å��ޥ��� #_CVI_# */
#define nMruby_tsButton_VALID_IDX(IDX) (1)


/* ����CB������ޥ��� #_GCB_# */
#define nMruby_tsButton_GET_CELLCB(idx) ((void *)0)
 /* �ƤӸ��ؿ��ޥ��� #_CPM_# */
#define nMruby_tsButton_cTECS_isPressed( p_that, button ) \
	  tButton_eButton_isPressed( \
	   (tButton_IDX)0, (button) )

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
#define VALID_IDX(IDX)  nMruby_tsButton_VALID_IDX(IDX)


/* ����CB������ޥ���(û�̷�) #_GCBA_# */
#define GET_CELLCB(idx)  nMruby_tsButton_GET_CELLCB(idx)

/* CELLCB ��(û�̷�) #_CCT_# */
#define CELLCB	nMruby_tsButton_CB

/* ���륿���פ�IDX��(û�̷�) #_CTIXA_# */
#define CELLIDX	nMruby_tsButton_IDX

#define tsButton_IDX  nMruby_tsButton_IDX
/* �ƤӸ��ؿ��ޥ����û�̷���#_CPMA_# */
#define cTECS_isPressed( button ) \
                      ((void)p_cellcb, nMruby_tsButton_cTECS_isPressed( p_cellcb, button ))

/* ���ƥ졼�������� (FOREACH_CELL)������(CB,INIB ��¸�ߤ��ʤ�) #_NFEC_# */
#define FOREACH_CELL(i,p_cb)   \
    for((i)=0;(i)<0;(i)++){

#define END_FOREACH_CELL   }

/* CB ������ޥ��� #_CIM_# */
#endif /* TOPPERS_CB_TYPE_ONLY */

#ifndef TOPPERS_MACRO_ONLY

#endif /* TOPPERS_MACRO_ONLY */

#endif /* nMruby_tsButton_TECSGENH */
