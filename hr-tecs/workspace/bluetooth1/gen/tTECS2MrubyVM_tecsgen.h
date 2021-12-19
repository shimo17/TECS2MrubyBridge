/*
 * このファイルは tecsgen により自動生成されました
 * このファイルを編集して使用することは、意図されていません
 */
#ifndef tTECS2MrubyVM_TECSGEN_H
#define tTECS2MrubyVM_TECSGEN_H

/*
 * celltype          :  tTECS2MrubyVM
 * global name       :  tTECS2MrubyVM
 * idx_is_id(actual) :  no(no)
 * singleton         :  no
 * has_CB            :  true
 * has_INIB          :  true
 * rom               :  yes
 * CB initializer    :  yes
 */

/* グローバルヘッダ #_IGH_# */
#include "global_tecsgen.h"

/* シグニチャヘッダ #_ISH_# */
#include "sTECS2MrubyVM_tecsgen.h"

#ifndef TOPPERS_MACRO_ONLY

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
/* セル INIB 型宣言 #_CIP_# */
typedef const struct tag_tTECS2MrubyVM_INIB {
    /* call port #_NEP_# */ 
    /* attribute(RO) #_ATO_# */ 
    uint32_t       irepAppSize;
    uint8_t*       irepApp;
}  tTECS2MrubyVM_INIB;
/* セル CB 型宣言 #_CCTPA_# */
typedef struct tag_tTECS2MrubyVM_CB {
    tTECS2MrubyVM_INIB  *_inib;
    /* call port #_NEP_# */ 
    /* var #_VA_# */ 
    mrb_state*     mrb;
    mrbc_context*  context;
}  tTECS2MrubyVM_CB;
extern tTECS2MrubyVM_CB  tTECS2MrubyVM_CB_tab[];

/* セルタイプのIDX型 #_CTIX_# */
typedef struct tag_tTECS2MrubyVM_CB *tTECS2MrubyVM_IDX;

/* 受け口関数プロトタイプ宣言 #_EPP_# */
/* sTECS2MrubyVM */
void         tTECS2MrubyVM_eTECS2MrubyVM_init(tTECS2MrubyVM_IDX idx);
mrb_state*   tTECS2MrubyVM_eTECS2MrubyVM_get_mrb(tTECS2MrubyVM_IDX idx);
void         tTECS2MrubyVM_eTECS2MrubyVM_fin(tTECS2MrubyVM_IDX idx);
#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* TOPPERS_MACRO_ONLY */

#ifndef TOPPERS_CB_TYPE_ONLY

#define tTECS2MrubyVM_ID_BASE        (1)  /* ID のベース  #_NIDB_# */
#define tTECS2MrubyVM_N_CELL        (1)  /* セルの個数  #_NCEL_# */

/* IDXの正当性チェックマクロ #_CVI_# */
#define tTECS2MrubyVM_VALID_IDX(IDX) (1)


/* セルCBを得るマクロ #_GCB_# */
#define tTECS2MrubyVM_GET_CELLCB(idx) (idx)

/* 属性アクセスマクロ #_AAM_# */
#define tTECS2MrubyVM_ATTR_irepAppSize( p_that )	((p_that)->_inib->irepAppSize)

#define tTECS2MrubyVM_GET_irepAppSize(p_that)	((p_that)->_inib->irepAppSize)


/* var アクセスマクロ #_VAM_# */
#define tTECS2MrubyVM_VAR_irepApp(p_that)	((p_that)->_inib->irepApp)
#define tTECS2MrubyVM_VAR_mrb(p_that)	((p_that)->mrb)
#define tTECS2MrubyVM_VAR_context(p_that)	((p_that)->context)

#define tTECS2MrubyVM_GET_irepApp(p_that)	((p_that)->irepApp)
#define tTECS2MrubyVM_SET_irepApp(p_that,val)	((p_that)->irepApp=(val))
#define tTECS2MrubyVM_GET_mrb(p_that)	((p_that)->mrb)
#define tTECS2MrubyVM_SET_mrb(p_that,val)	((p_that)->mrb=(val))
#define tTECS2MrubyVM_GET_context(p_that)	((p_that)->context)
#define tTECS2MrubyVM_SET_context(p_that,val)	((p_that)->context=(val))

#endif /* TOPPERS_CB_TYPE_ONLY */

#ifndef TOPPERS_MACRO_ONLY

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* 受け口スケルトン関数プロトタイプ宣言（VMT不要最適化により参照するもの） #_EPSP_# */

#ifndef TOPPERS_CB_TYPE_ONLY

#endif /* TOPPERS_CB_TYPE_ONLY */

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* TOPPERS_MACRO_ONLY */

#ifndef TOPPERS_CB_TYPE_ONLY

/* IDXの正当性チェックマクロ（短縮形） #_CVIA_# */
#define VALID_IDX(IDX)  tTECS2MrubyVM_VALID_IDX(IDX)


/* セルCBを得るマクロ(短縮形) #_GCBA_# */
#define GET_CELLCB(idx)  tTECS2MrubyVM_GET_CELLCB(idx)

/* CELLCB 型(短縮形) #_CCT_# */
#define CELLCB	tTECS2MrubyVM_CB

/* セルタイプのIDX型(短縮形) #_CTIXA_# */
#define CELLIDX	tTECS2MrubyVM_IDX


/* 属性アクセスマクロ(短縮形) #_AAMA_# */
#define ATTR_irepAppSize     tTECS2MrubyVM_ATTR_irepAppSize( p_cellcb )


/* var アクセスマクロ(短縮形) #_VAMA_# */
#define VAR_irepApp          tTECS2MrubyVM_VAR_irepApp( p_cellcb )
#define VAR_mrb              tTECS2MrubyVM_VAR_mrb( p_cellcb )
#define VAR_context          tTECS2MrubyVM_VAR_context( p_cellcb )




/* 受け口関数マクロ（短縮形） #_EPM_# */
#define eTECS2MrubyVM_init tTECS2MrubyVM_eTECS2MrubyVM_init
#define eTECS2MrubyVM_get_mrb tTECS2MrubyVM_eTECS2MrubyVM_get_mrb
#define eTECS2MrubyVM_fin tTECS2MrubyVM_eTECS2MrubyVM_fin

/* イテレータコード (FOREACH_CELL)の生成 #_FEC_# */
#define FOREACH_CELL(i,p_cb)   \
    for( (i) = 0; (i) < tTECS2MrubyVM_N_CELL; (i)++ ){ \
       (p_cb) = &tTECS2MrubyVM_CB_tab[i];

#define END_FOREACH_CELL   }

/* CB 初期化マクロ #_CIM_# */
#define INITIALIZE_CB(p_that)	(void)(p_that);
#define SET_CB_INIB_POINTER(i,p_that)\
	(p_that)->_inib = &tTECS2MrubyVM_INIB_tab[(i)];

#endif /* TOPPERS_CB_TYPE_ONLY */

#ifndef TOPPERS_MACRO_ONLY

#endif /* TOPPERS_MACRO_ONLY */

#endif /* tTECS2MrubyVM_TECSGENH */
