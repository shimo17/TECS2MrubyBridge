/*
 * ���Υե������ tecsgen �ˤ�꼫ư��������ޤ���
 * ���Υե�������Խ����ƻ��Ѥ��뤳�Ȥϡ��տޤ���Ƥ��ޤ���
 */
#ifndef nMruby_tMruby_TECSGEN_H
#define nMruby_tMruby_TECSGEN_H

/*
 * celltype          :  tMruby
 * global name       :  nMruby_tMruby
 * idx_is_id(actual) :  no(no)
 * singleton         :  no
 * has_CB            :  false
 * has_INIB          :  true
 * rom               :  yes
 * CB initializer    :  no
 */

/* �����Х�إå� #_IGH_# */
#include "global_tecsgen.h"

/* �����˥���إå� #_ISH_# */
#include "sTaskBody_tecsgen.h"
#include "nMruby_sInitializeBridge_tecsgen.h"

#ifndef TOPPERS_MACRO_ONLY

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
/* ���� INIB ����� #_CIP_# */
typedef const struct tag_nMruby_tMruby_INIB {
    /* call port #_TCP_# */ 
    /* call port #_NEP_# */ 
    /* attribute(RO) #_ATO_# */ 
    char_t*        irep;
}  nMruby_tMruby_INIB;

/* CB ��¸�ߤ��ʤ���INIB �� CB ������˻��Ѥ��뤿��� define #_DCI_# */
#define nMruby_tMruby_CB_tab           nMruby_tMruby_INIB_tab
#define nMruby_tMruby_SINGLE_CELL_CB   nMruby_tMruby_SINGLE_CELL_INIB
#define nMruby_tMruby_CB               nMruby_tMruby_INIB
#define tag_nMruby_tMruby_CB           tag_nMruby_tMruby_INIB

extern nMruby_tMruby_CB  nMruby_tMruby_CB_tab[];

/* ���륿���פ�IDX�� #_CTIX_# */
typedef const struct tag_nMruby_tMruby_INIB *nMruby_tMruby_IDX;

/* �������ؿ��ץ�ȥ�������� #_EPP_# */
/* sTaskBody */
void         nMruby_tMruby_eMrubyBody_main(nMruby_tMruby_IDX idx);
#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* TOPPERS_MACRO_ONLY */

/* ��Ŭ���Τ��Ỳ�Ȥ��륻�륿���פ� CB ������������� #_ICT_# */
#ifndef  TOPPERS_CB_TYPE_ONLY
#define  nMruby_tMruby_CB_TYPE_ONLY
#define TOPPERS_CB_TYPE_ONLY
#endif  /* TOPPERS_CB_TYPE_ONLY */
#include "nMruby_tTECSInitializer_tecsgen.h"
#ifdef  nMruby_tMruby_CB_TYPE_ONLY
#undef TOPPERS_CB_TYPE_ONLY
#endif /* nMruby_tMruby_CB_TYPE_ONLY */
#ifndef TOPPERS_CB_TYPE_ONLY

#define nMruby_tMruby_ID_BASE        (1)  /* ID �Υ١���  #_NIDB_# */
#define nMruby_tMruby_N_CELL        (1)  /* ����θĿ�  #_NCEL_# */

/* IDX�������������å��ޥ��� #_CVI_# */
#define nMruby_tMruby_VALID_IDX(IDX) (1)

/* optional �ƤӸ���ƥ��Ȥ���ޥ��� #_TOCP_# */
#define nMruby_tMruby_is_cInit_joined(p_that) \
	  (1)

/* ����CB������ޥ��� #_GCB_# */
#define nMruby_tMruby_GET_CELLCB(idx) (idx)

/* °�����������ޥ��� #_AAM_# */
#define nMruby_tMruby_ATTR_irep( p_that )	((p_that)->irep)

#define nMruby_tMruby_GET_irep(p_that)	((p_that)->irep)



 /* �ƤӸ��ؿ��ޥ��� #_CPM_# */
#define nMruby_tMruby_cInit_initializeBridge( p_that, mrb ) \
	  nMruby_tTECSInitializer_eInitialize_initializeBridge( \
	   &nMruby_tTECSInitializer_CB_tab[0], (mrb) )

#endif /* TOPPERS_CB_TYPE_ONLY */

#ifndef TOPPERS_MACRO_ONLY

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* ������������ȥ�ؿ��ץ�ȥ����������VMT���׺�Ŭ���ˤ�껲�Ȥ����Ρ� #_EPSP_# */
/* eMrubyBody */
void           nMruby_tMruby_eMrubyBody_main_skel( const struct tag_sTaskBody_VDES *epd);

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* TOPPERS_MACRO_ONLY */

#ifndef TOPPERS_CB_TYPE_ONLY

/* IDX�������������å��ޥ����û�̷��� #_CVIA_# */
#define VALID_IDX(IDX)  nMruby_tMruby_VALID_IDX(IDX)


/* ����CB������ޥ���(û�̷�) #_GCBA_# */
#define GET_CELLCB(idx)  nMruby_tMruby_GET_CELLCB(idx)

/* CELLCB ��(û�̷�) #_CCT_# */
#define CELLCB	nMruby_tMruby_CB

/* ���륿���פ�IDX��(û�̷�) #_CTIXA_# */
#define CELLIDX	nMruby_tMruby_IDX

#define tMruby_IDX  nMruby_tMruby_IDX

/* °�����������ޥ���(û�̷�) #_AAMA_# */
#define ATTR_irep            nMruby_tMruby_ATTR_irep( p_cellcb )


/* �ƤӸ��ؿ��ޥ����û�̷���#_CPMA_# */
#define cInit_initializeBridge( mrb ) \
                      ((void)p_cellcb, nMruby_tMruby_cInit_initializeBridge( p_cellcb, mrb ))

/* optional �ƤӸ���ƥ��Ȥ���ޥ����û�̷��� #_TOCPA_# */
#define is_cInit_joined()\
		nMruby_tMruby_is_cInit_joined(p_cellcb)

/* �������ؿ��ޥ����û�̷��� #_EPM_# */
#define eMrubyBody_main  nMruby_tMruby_eMrubyBody_main

/* ���ƥ졼�������� (FOREACH_CELL)������ #_FEC_# */
#define FOREACH_CELL(i,p_cb)   \
    for( (i) = 0; (i) < nMruby_tMruby_N_CELL; (i)++ ){ \
       //(p_cb) = &nMruby_tMruby_CB_tab[i];

#define END_FOREACH_CELL   }

/* CB ������ޥ��� #_CIM_# */
#endif /* TOPPERS_CB_TYPE_ONLY */

#ifndef TOPPERS_MACRO_ONLY

#endif /* TOPPERS_MACRO_ONLY */

#endif /* nMruby_tMruby_TECSGENH */
