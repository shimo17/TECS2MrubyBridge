/*
 * ���Υե������ tecsgen �ˤ�꼫ư��������ޤ���
 * ���Υե�������Խ����ƻ��Ѥ��뤳�Ȥϡ��տޤ���Ƥ��ޤ���
 */
#include "nMruby_tMruby_tecsgen.h"
#include "nMruby_tMruby_factory.h"

/* �������ǥ�������ץ��� #_EDT_# */
/* eMrubyBody */
struct tag_nMruby_tMruby_eMrubyBody_DES {
    const struct tag_sTaskBody_VMT *vmt;
    tMruby_IDX  idx;
};

/* ������������ȥ�ؿ� #_EPSF_# */
/* eMrubyBody */
void           nMruby_tMruby_eMrubyBody_main_skel( const struct tag_sTaskBody_VDES *epd)
{
    struct tag_nMruby_tMruby_eMrubyBody_DES *lepd
        = (struct tag_nMruby_tMruby_eMrubyBody_DES *)epd;
    nMruby_tMruby_eMrubyBody_main( lepd->idx );
}

/* ������������ȥ�ؿ��ơ��֥� #_EPSFT_# */
/* eMrubyBody */
const struct tag_sTaskBody_VMT nMruby_tMruby_eMrubyBody_MT_ = {
    nMruby_tMruby_eMrubyBody_main_skel,
};

/* �ƤӸ��λ��Ȥ���������ǥ�������ץ�(�ºݤη�����㤷�����) #_CPEPD_# */

/* �ƤӸ����� #_CPA_# */

/* °�����ѿ������� #_AVAI_# */
/* ���� INIB #_INIB_# */
nMruby_tMruby_INIB nMruby_tMruby_INIB_tab[] = {
    /* cell: nMruby_tMruby_CB_tab[0]:  Mruby id=1 */
    {
        /* call port #_CP_# */ 
        /* entry port #_EP_# */ 
        /* attribute(RO) */ 
        &rDomainEV3_Mruby_irep,                  /* irep */
    },
};

extern const struct tag_sTaskBody_VMT nMruby_tMruby_eMrubyBody_MT_;
/* �������ǥ�������ץ� #_EPD_# */
extern const struct tag_nMruby_tMruby_eMrubyBody_DES rDomainEV3_Mruby_eMrubyBody_des;
const struct tag_nMruby_tMruby_eMrubyBody_DES rDomainEV3_Mruby_eMrubyBody_des = {
    &nMruby_tMruby_eMrubyBody_MT_,
    &nMruby_tMruby_INIB_tab[0],   /* INIB */
};
