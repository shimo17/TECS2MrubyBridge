/*
 * このファイルは tecsgen により自動生成されました
 * このファイルを編集して使用することは、意図されていません
 */
#include "tTECS2MrubyVM_tecsgen.h"
#include "tTECS2MrubyVM_factory.h"

/* 受け口ディスクリプタ型 #_EDT_# */
/* eTECS2MrubyVM : omitted by entry port optimize */

/* 受け口スケルトン関数 #_EPSF_# */
/* eTECS2MrubyVM : omitted by entry port optimize */

/* 受け口スケルトン関数テーブル #_EPSFT_# */
/* eTECS2MrubyVM : omitted by entry port optimize */

/* 呼び口の参照する受け口ディスクリプタ(実際の型と相違した定義) #_CPEPD_# */

/* 呼び口配列 #_CPA_# */

/* 属性・変数の配列 #_AVAI_# */
uint8_t tTECS2MrubyVM_TECS2MrubyVM_CB_irepApp_INIT[131072];
/* セル INIB #_INIB_# */
tTECS2MrubyVM_INIB tTECS2MrubyVM_INIB_tab[] = {
    /* cell: tTECS2MrubyVM_CB_tab[0]:  TECS2MrubyVM id=1 */
    {
        /* entry port #_EP_# */ 
        /* attribute(RO) */ 
        131072,                                  /* irepAppSize */
        tTECS2MrubyVM_TECS2MrubyVM_CB_irepApp_INIT, /* irepApp */
    },
};

/* セル CB #_CB_# */
struct tag_tTECS2MrubyVM_CB tTECS2MrubyVM_CB_tab[1];
/* 受け口ディスクリプタ #_EPD_# */
/* eTECS2MrubyVM : omitted by entry port optimize */
/* CB 初期化コード #_CIC_# */
void
tTECS2MrubyVM_CB_initialize()
{
    tTECS2MrubyVM_CB	*p_cb;
    int		i;
    FOREACH_CELL(i,p_cb)
        SET_CB_INIB_POINTER(i,p_cb)
        INITIALIZE_CB(p_cb)
    END_FOREACH_CELL
}
