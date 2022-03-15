/*
 * このファイルは tecsgen により自動生成されました
 * このファイルを編集して使用することは、意図されていません
 */
#ifndef sDynamic_TECSGEN_H
#define sDynamic_TECSGEN_H

/*
 * signature   :  sDynamic
 * global name :  sDynamic
 * context     :  task
 */

#ifndef TOPPERS_MACRO_ONLY

/* シグニチャディスクリプタ #_SD_# */
struct tag_sDynamic_VDES {
    struct tag_sDynamic_VMT *VMT;
};

/* シグニチャ関数テーブル #_SFT_# */
struct tag_sDynamic_VMT {
    void           (*dynamic_change__T)( const struct tag_sDynamic_VDES *edp, int32_t x );
};

/* シグニチャディスクリプタ(動的結合用) #_SDES_# */
#ifndef Descriptor_of_sDynamic_Defined
#define  Descriptor_of_sDynamic_Defined
typedef struct { struct tag_sDynamic_VDES *vdes; } Descriptor( sDynamic );
#endif
#endif /* TOPPERS_MACRO_ONLY */

/* function id */
#define	FUNCID_SDYNAMIC_DYNAMIC_CHANGE         (1)

#endif /* sDynamic_TECSGEN_H */
