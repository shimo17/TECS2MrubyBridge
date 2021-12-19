/*
 * ���Υե������ tecsgen �ˤ�꼫ư��������ޤ���
 * ���Υե�������Խ����ƻ��Ѥ��뤳�Ȥϡ��տޤ���Ƥ��ޤ���
 */
#include "nMruby_tRiteVMBluetooth_tecsgen.h"
#include "nMruby_tRiteVMBluetooth_factory.h"

/* �������ǥ�������ץ��� #_EDT_# */
/* eMrubyBody */
struct tag_nMruby_tRiteVMBluetooth_eMrubyBody_DES {
    const struct tag_sTaskBody_VMT *vmt;
    tRiteVMBluetooth_IDX  idx;
};

/* eRiteVM */
struct tag_nMruby_tRiteVMBluetooth_eRiteVM_DES {
    const struct tag_sRiteVM_VMT *vmt;
    tRiteVMBluetooth_IDX  idx;
};

/* ������������ȥ�ؿ� #_EPSF_# */
/* eMrubyBody */
void           nMruby_tRiteVMBluetooth_eMrubyBody_main_skel( const struct tag_sTaskBody_VDES *epd)
{
    struct tag_nMruby_tRiteVMBluetooth_eMrubyBody_DES *lepd
        = (struct tag_nMruby_tRiteVMBluetooth_eMrubyBody_DES *)epd;
    nMruby_tRiteVMBluetooth_eMrubyBody_main( lepd->idx );
}
/* eRiteVM */
void           nMruby_tRiteVMBluetooth_eRiteVM_reset_skel( const struct tag_sRiteVM_VDES *epd)
{
    struct tag_nMruby_tRiteVMBluetooth_eRiteVM_DES *lepd
        = (struct tag_nMruby_tRiteVMBluetooth_eRiteVM_DES *)epd;
    nMruby_tRiteVMBluetooth_eRiteVM_reset( lepd->idx );
}

/* ������������ȥ�ؿ��ơ��֥� #_EPSFT_# */
/* eMrubyBody */
const struct tag_sTaskBody_VMT nMruby_tRiteVMBluetooth_eMrubyBody_MT_ = {
    nMruby_tRiteVMBluetooth_eMrubyBody_main_skel,
};
/* eRiteVM */
const struct tag_sRiteVM_VMT nMruby_tRiteVMBluetooth_eRiteVM_MT_ = {
    nMruby_tRiteVMBluetooth_eRiteVM_reset_skel,
};

/* �ƤӸ��λ��Ȥ���������ǥ�������ץ�(�ºݤη�����㤷�����) #_CPEPD_# */

/* �ƤӸ����� #_CPA_# */

/* °�����ѿ������� #_AVAI_# */
uint8_t nMruby_tRiteVMBluetooth_RiteVMBluetooth_CB_irepApp_INIT[131072];
/* ���� INIB #_INIB_# */
nMruby_tRiteVMBluetooth_INIB nMruby_tRiteVMBluetooth_INIB_tab[] = {
    /* cell: nMruby_tRiteVMBluetooth_CB_tab[0]:  RiteVMBluetooth id=1 */
    {
        /* call port #_CP_# */ 
        0,                                       /* #_CCP5_# */
        0,                                       /* length of cEventflag (n_cEventflag) #_CCP6_# */
        /* entry port #_EP_# */ 
        /* attribute(RO) */ 
        &rDomainEV3_RiteVMBluetooth_irep,        /* irepLib */
        131072,                                  /* irepAppSize */
        0x01,                                    /* setptn */
        nMruby_tRiteVMBluetooth_RiteVMBluetooth_CB_irepApp_INIT, /* irepApp */
    },
};

/* ���� CB #_CB_# */
struct tag_nMruby_tRiteVMBluetooth_CB nMruby_tRiteVMBluetooth_CB_tab[1];
extern const struct tag_sTaskBody_VMT nMruby_tRiteVMBluetooth_eMrubyBody_MT_;
extern const struct tag_sRiteVM_VMT nMruby_tRiteVMBluetooth_eRiteVM_MT_;
/* �������ǥ�������ץ� #_EPD_# */
extern const struct tag_nMruby_tRiteVMBluetooth_eMrubyBody_DES rDomainEV3_RiteVMBluetooth_eMrubyBody_des;
const struct tag_nMruby_tRiteVMBluetooth_eMrubyBody_DES rDomainEV3_RiteVMBluetooth_eMrubyBody_des = {
    &nMruby_tRiteVMBluetooth_eMrubyBody_MT_,
    &nMruby_tRiteVMBluetooth_CB_tab[0],     /* CB */
};
extern const struct tag_nMruby_tRiteVMBluetooth_eRiteVM_DES rDomainEV3_RiteVMBluetooth_eRiteVM_des;
const struct tag_nMruby_tRiteVMBluetooth_eRiteVM_DES rDomainEV3_RiteVMBluetooth_eRiteVM_des = {
    &nMruby_tRiteVMBluetooth_eRiteVM_MT_,
    &nMruby_tRiteVMBluetooth_CB_tab[0],     /* CB */
};
/* CB ����������� #_CIC_# */
void
nMruby_tRiteVMBluetooth_CB_initialize()
{
    nMruby_tRiteVMBluetooth_CB	*p_cb;
    int		i;
    FOREACH_CELL(i,p_cb)
        SET_CB_INIB_POINTER(i,p_cb)
        INITIALIZE_CB(p_cb)
    END_FOREACH_CELL
}
