/*
 * ���Υե������ tecsgen �ˤ�꼫ư��������ޤ���
 * ���Υե�������Խ����ƻ��Ѥ��뤳�Ȥϡ��տޤ���Ƥ��ޤ���
 */
#include "nMruby_tsMotor_Initializer_tecsgen.h"
#include "nMruby_tsMotor_Initializer_factory.h"

/* �������ǥ�������ץ��� #_EDT_# */
/* eInitialize */
struct tag_nMruby_tsMotor_Initializer_eInitialize_DES {
    const struct tag_nMruby_sInitializeTECSBridge_VMT *vmt;
    int           idx;
};

/* ������������ȥ�ؿ� #_EPSF_# */
/* eInitialize */
void           nMruby_tsMotor_Initializer_eInitialize_initializeBridge_skel( const struct tag_nMruby_sInitializeTECSBridge_VDES *epd, mrb_state* mrb, struct RClass * TECS)
{
    struct tag_nMruby_tsMotor_Initializer_eInitialize_DES *lepd
        = (struct tag_nMruby_tsMotor_Initializer_eInitialize_DES *)epd;
    nMruby_tsMotor_Initializer_eInitialize_initializeBridge( lepd->idx, mrb, TECS );
}

/* ������������ȥ�ؿ��ơ��֥� #_EPSFT_# */
/* eInitialize */
const struct tag_nMruby_sInitializeTECSBridge_VMT nMruby_tsMotor_Initializer_eInitialize_MT_ = {
    nMruby_tsMotor_Initializer_eInitialize_initializeBridge_skel,
};

/* �ƤӸ��λ��Ȥ���������ǥ�������ץ�(�ºݤη�����㤷�����) #_CPEPD_# */

/* �ƤӸ����� #_CPA_# */

/* °�����ѿ������� #_AVAI_# */
/* �������ǥ�������ץ� #_EPD_# */
extern const struct tag_nMruby_tsMotor_Initializer_eInitialize_DES VM_tsMotor_Initializer_eInitialize_des;
const struct tag_nMruby_tsMotor_Initializer_eInitialize_DES VM_tsMotor_Initializer_eInitialize_des = {
    &nMruby_tsMotor_Initializer_eInitialize_MT_,
    0,
};