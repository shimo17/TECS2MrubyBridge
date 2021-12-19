/*
 * このファイルは tecsgen によりテンプレートとして自動生成されました
 * このファイルを編集して使用することが意図されていますが
 * tecsgen の再実行により上書きされてしまうため、通常
 *   gen/tTECS2MrubyVM_template.c => src/tTECS2MrubyVM.c
 * のように名前, フォルダを変更してから修正します
 */
/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * 属性アクセスマクロ #_CAAM_#
 * irepAppSize      uint32_t         ATTR_irepAppSize
 * irepApp          uint8_t*         VAR_irepApp     
 * mrb              mrb_state*       VAR_mrb         
 * context          mrbc_context*    VAR_context     
 *
 * #[</PREAMBLE>]# */

/* プロトタイプ宣言や変数の定義をここに書きます #_PAC_# */
#include "tTECS2MrubyVM_tecsgen.h"

#ifndef E_OK
#define	E_OK	0		/* success */
#define	E_ID	(-18)	/* illegal ID */
#endif

/* 受け口関数 #_TEPF_# */
/* #[<ENTRY_PORT>]# eTECS2MrubyVM
 * entry port: eTECS2MrubyVM
 * signature:  sTECS2MrubyVM
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eTECS2MrubyVM_init
 * name:         eTECS2MrubyVM_init
 * global_name:  tTECS2MrubyVM_eTECS2MrubyVM_init
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eTECS2MrubyVM_init(CELLIDX idx)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* エラー処理コードをここに記述します */
	} /* end if VALID_IDX(idx) */

	/* ここに処理本体を記述します #_TEFB_# */

}

/* #[<ENTRY_FUNC>]# eTECS2MrubyVM_get_mrb
 * name:         eTECS2MrubyVM_get_mrb
 * global_name:  tTECS2MrubyVM_eTECS2MrubyVM_get_mrb
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
mrb_state*
eTECS2MrubyVM_get_mrb(CELLIDX idx)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* エラー処理コードをここに記述します */
	} /* end if VALID_IDX(idx) */

	/* ここに処理本体を記述します #_TEFB_# */

}

/* #[<ENTRY_FUNC>]# eTECS2MrubyVM_fin
 * name:         eTECS2MrubyVM_fin
 * global_name:  tTECS2MrubyVM_eTECS2MrubyVM_fin
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eTECS2MrubyVM_fin(CELLIDX idx)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* エラー処理コードをここに記述します */
	} /* end if VALID_IDX(idx) */

	/* ここに処理本体を記述します #_TEFB_# */

}

/* #[<POSTAMBLE>]#
 *   これより下に非受け口関数を書きます
 * #[</POSTAMBLE>]#*/
