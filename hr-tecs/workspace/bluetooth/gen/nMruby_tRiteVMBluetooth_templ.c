/*
 * このファイルは tecsgen によりテンプレートとして自動生成されました
 * このファイルを編集して使用することが意図されていますが
 * tecsgen の再実行により上書きされてしまうため、通常
 *   gen/tRiteVMBluetooth_template.c => src/tRiteVMBluetooth.c
 * のように名前, フォルダを変更してから修正します
 */
/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * 属性アクセスマクロ #_CAAM_#
 * irepLib          uint8_t*         ATTR_irepLib    
 * irepAppSize      uint32_t         ATTR_irepAppSize
 * setptn           FLGPTN           ATTR_setptn     
 * mrb              mrb_state*       VAR_mrb         
 * context          mrbc_context*    VAR_context     
 * irepApp          uint8_t*         VAR_irepApp     
 *
 * 呼び口関数 #_TCPF_#
 * require port: signature:sKernel context:task
 *   ER             sleep( );
 *   ER             sleepTimeout( TMO timeout );
 *   ER             delay( RELTIM delayTime );
 *   ER             exitTask( );
 *   ER             getTaskId( ID* p_taskId );
 *   ER             rotateReadyQueue( PRI taskPriority );
 *   ER             getTime( SYSTIM* p_systemTime );
 *   ER             getMicroTime( SYSUTM* p_systemMicroTime );
 *   ER             lockCpu( );
 *   ER             unlockCpu( );
 *   ER             disableDispatch( );
 *   ER             enableDispatch( );
 *   ER             disableTaskException( );
 *   ER             enableTaskException( );
 *   ER             changeInterruptPriorityMask( PRI interruptPriority );
 *   ER             getInterruptPriorityMask( PRI* p_interruptPriority );
 *   ER             exitKernel( );
 *   bool_t         senseContext( );
 *   bool_t         senseLock( );
 *   bool_t         senseDispatch( );
 *   bool_t         senseDispatchPendingState( );
 *   bool_t         senseKernel( );
 * call port: cTask signature: sTask context:task
 *   ER             cTask_activate( );
 *   ER_UINT        cTask_cancelActivate( );
 *   ER             cTask_terminate( );
 *   ER             cTask_changePriority( PRI priority );
 *   ER             cTask_getPriority( PRI* p_priority );
 *   ER             cTask_refer( T_RTSK* pk_taskStatus );
 *   ER             cTask_wakeup( );
 *   ER_UINT        cTask_cancelWakeup( );
 *   ER             cTask_releaseWait( );
 *   ER             cTask_suspend( );
 *   ER             cTask_resume( );
 *   ER             cTask_raiseException( TEXPTN pattern );
 *   ER             cTask_referException( T_RTEX* pk_rtex );
 *   ER             cTask_startOverRunHandler( OVRTIM ovrtim );
 *   ER             cTask_stopOverRunHandler( );
 *   ER             cTask_referOverRunHandler( T_ROVR* pk_rovr );
 * call port: cReset signature: sReset context:task
 *   void           cReset_reset( );
 * call port: cCyclic signature: sCyclic context:task optional:true
 *   bool_t     is_cCyclic_joined()                     check if joined
 *   ER             cCyclic_start( );
 *   ER             cCyclic_stop( );
 *   ER             cCyclic_refer( T_RCYC* pk_cyclicHandlerStatus );
 * call port: cEventflag signature: sEventflag context:task optional:true
 *   bool_t     is_cEventflag_joined(int subscript)        check if joined
 *   ER             cEventflag_set( subscript, FLGPTN setPattern );
 *   ER             cEventflag_clear( subscript, FLGPTN clearPattern );
 *   ER             cEventflag_wait( subscript, FLGPTN waitPattern, MODE waitFlagMode, FLGPTN* p_flagPattern );
 *   ER             cEventflag_waitPolling( subscript, FLGPTN waitPattern, MODE waitFlagMode, FLGPTN* p_flagPattern );
 *   ER             cEventflag_waitTimeout( subscript, FLGPTN waitPattern, MODE waitFlagMode, FLGPTN* p_flagPattern, TMO timeout );
 *   ER             cEventflag_initialize( subscript );
 *   ER             cEventflag_refer( subscript, T_RFLG* pk_eventflagStatus );
 *       subscript:  0...(NCP_cEventflag-1)
 * call port: cSemaphore signature: sSemaphore context:task optional:true
 *   bool_t     is_cSemaphore_joined()                     check if joined
 *   ER             cSemaphore_signal( );
 *   ER             cSemaphore_wait( );
 *   ER             cSemaphore_waitPolling( );
 *   ER             cSemaphore_waitTimeout( TMO timeout );
 *   ER             cSemaphore_initialize( );
 *   ER             cSemaphore_refer( T_RSEM* pk_semaphoreStatus );
 * call port: cInit signature: nMruby_sInitializeBridge context:task optional:true
 *   bool_t     is_cInit_joined()                     check if joined
 *   void           cInit_initializeBridge( const mrb_state* mrb );
 *
 * #[</PREAMBLE>]# */

/* プロトタイプ宣言や変数の定義をここに書きます #_PAC_# */
#include "nMruby_tRiteVMBluetooth_tecsgen.h"

#ifndef E_OK
#define	E_OK	0		/* success */
#define	E_ID	(-18)	/* illegal ID */
#endif

/* 受け口関数 #_TEPF_# */
/* #[<ENTRY_PORT>]# eMrubyBody
 * entry port: eMrubyBody
 * signature:  sTaskBody
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eMrubyBody_main
 * name:         eMrubyBody_main
 * global_name:  nMruby_tRiteVMBluetooth_eMrubyBody_main
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eMrubyBody_main(CELLIDX idx)
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

/* #[<ENTRY_PORT>]# eRiteVM
 * entry port: eRiteVM
 * signature:  sRiteVM
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eRiteVM_reset
 * name:         eRiteVM_reset
 * global_name:  nMruby_tRiteVMBluetooth_eRiteVM_reset
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eRiteVM_reset(CELLIDX idx)
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
