/*
 * このファイルは tecsgen により自動生成されました
 * このファイルを編集して使用することは、意図されていません
 */
#ifndef sTECS2MrubyVM_TECSGEN_H
#define sTECS2MrubyVM_TECSGEN_H

/*
 * signature   :  sTECS2MrubyVM
 * global name :  sTECS2MrubyVM
 * context     :  task
 */

#ifndef TOPPERS_MACRO_ONLY

/* シグニチャディスクリプタ #_SD_# */
struct tag_sTECS2MrubyVM_VDES {
    struct tag_sTECS2MrubyVM_VMT *VMT;
};

/* シグニチャ関数テーブル #_SFT_# */
struct tag_sTECS2MrubyVM_VMT {
    void           (*init__T)( const struct tag_sTECS2MrubyVM_VDES *edp );
    mrb_state*     (*get_mrb__T)( const struct tag_sTECS2MrubyVM_VDES *edp );
    void           (*fin__T)( const struct tag_sTECS2MrubyVM_VDES *edp );
};

/* シグニチャディスクリプタ(動的結合用) #_SDES_# */
#ifndef Descriptor_of_sTECS2MrubyVM_Defined
#define  Descriptor_of_sTECS2MrubyVM_Defined
typedef struct { struct tag_sTECS2MrubyVM_VDES *vdes; } Descriptor( sTECS2MrubyVM );
#endif
#endif /* TOPPERS_MACRO_ONLY */

/* function id */
#define	FUNCID_STECS2MRUBYVM_INIT              (1)
#define	FUNCID_STECS2MRUBYVM_GET_MRB           (2)
#define	FUNCID_STECS2MRUBYVM_FIN               (3)

#endif /* sTECS2MrubyVM_TECSGEN_H */
