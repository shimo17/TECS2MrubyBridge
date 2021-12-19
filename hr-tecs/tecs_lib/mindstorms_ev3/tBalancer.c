/*
 * ���Υե������ tecsgen �ˤ��ƥ�ץ졼�ȤȤ��Ƽ�ư��������ޤ���
 * ���Υե�������Խ����ƻ��Ѥ��뤳�Ȥ��տޤ���Ƥ��ޤ���
 * tecsgen �κƼ¹Ԥˤ���񤭤���Ƥ��ޤ����ᡢ�̾�
 *   gen/tBalancer_template.c => src/tBalancer.c
 * �Τ褦��̾��, �ե�������ѹ����Ƥ��齤�����ޤ�
 */
/* #[<PREAMBLE>]#
 * #[<...>]# ���� #[</...>]# �ǰϤޤ줿�����Ȥ��Խ����ʤ��Ǥ�������
 * tecsmerge �ˤ��ޡ����˻��Ѥ���ޤ�
 *
 * #[</PREAMBLE>]# */

/* �ץ�ȥ�����������ѿ�������򤳤��˽񤭤ޤ� #_PAC_# */
#include "tBalancer_tecsgen.h"
#include "balancer.h"

#ifndef E_OK
#define	E_OK	0		/* success */
#define	E_ID	(-18)	/* illegal ID */
#endif

/* �������ؿ� #_TEPF_# */
/* #[<ENTRY_PORT>]# eBalancer
 * entry port: eBalancer
 * signature:  sBalancer
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eBalancer_control
 * name:         eBalancer_control
 * global_name:  tBalancer_eBalancer_control
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eBalancer_control(float32_t forward, float32_t turn, float32_t gyro, float32_t gyroOffset, float32_t leftRevolution, float32_t rightRevolution, float32_t battery, int8_t* pwm_l, int8_t* pwm_r)
{
	balance_control(forward,
			turn,
			gyro,
			gyroOffset,
			leftRevolution,
			rightRevolution,
			battery,
			pwm_l,
			pwm_r);	
}

/* #[<ENTRY_FUNC>]# eBalancer_init
 * name:         eBalancer_init
 * global_name:  tBalancer_eBalancer_init
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eBalancer_init()
{
	// ��Ω�����ѥ饤�֥��ؿ���ƤӽФ�
	balance_init();
}

/* #[<POSTAMBLE>]#
 *   �����겼����������ؿ���񤭤ޤ�
 * #[</POSTAMBLE>]#*/
