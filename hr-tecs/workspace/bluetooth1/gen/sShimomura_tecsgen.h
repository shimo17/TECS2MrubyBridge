/*
 * このファイルは tecsgen により自動生成されました
 * このファイルを編集して使用することは、意図されていません
 */
#ifndef sShimomura_TECSGEN_H
#define sShimomura_TECSGEN_H

/*
 * signature   :  sShimomura
 * global name :  sShimomura
 * context     :  task
 */

#ifndef TOPPERS_MACRO_ONLY

/* シグニチャディスクリプタ #_SD_# */
struct tag_sShimomura_VDES {
    struct tag_sShimomura_VMT *VMT;
};

/* シグニチャ関数テーブル #_SFT_# */
struct tag_sShimomura_VMT {
    void           (*mcall_lcd__T)( const struct tag_sShimomura_VDES *edp, const char* x );
};

/* シグニチャディスクリプタ(動的結合用) #_SDES_# */
#ifndef Descriptor_of_sShimomura_Defined
#define  Descriptor_of_sShimomura_Defined
typedef struct { struct tag_sShimomura_VDES *vdes; } Descriptor( sShimomura );
#endif
#endif /* TOPPERS_MACRO_ONLY */

/* function id */
#define	FUNCID_SSHIMOMURA_MCALL_LCD            (1)

#endif /* sShimomura_TECSGEN_H */
