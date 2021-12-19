/*
 * §≥§Œ•’•°•§•Î§œ tecsgen §À§Ë§Íº´∆∞¿∏¿Æ§µ§Ï§ﬁ§∑§ø
 * §≥§Œ•’•°•§•Î§Ú ‘Ω∏§∑§∆ª»Õ—§π§Î§≥§»§œ°¢∞’øﬁ§µ§Ï§∆§§§ﬁ§ª§Û
 */
/* #[<PREAMBLE>]#
 * #[<...>]# §´§È #[</...>]# §«∞œ§ﬁ§Ï§ø•≥•·•Û•»§œ ‘Ω∏§∑§ §§§«§Ø§¿§µ§§
 * tecsmerge §À§Ë§Î•ﬁ°º•∏§Àª»Õ—§µ§Ï§ﬁ§π
 *
 * ∏∆§”∏˝¥ÿøÙ #_TCPF_#
 * call port: cMethodCall signature: sTECS2MrubyVM context:task
 *   void           cMethodCall_init( );
 *   mrb_state*     cMethodCall_get_mrb( );
 *   void           cMethodCall_fin( );
 *
 * #[</PREAMBLE>]# */

/* •◊•Ì•»•ø•§•◊¿Î∏¿§‰ —øÙ§ŒƒÍµ¡§Ú§≥§≥§ÀΩÒ§≠§ﬁ§π #_PAC_# */
#include "nTECS2Mruby_tsShimomura_tecsgen.h"

#ifndef E_OK
#define	E_OK	0		/* success */
#define	E_ID	(-18)	/* illegal ID */
#endif

/* ºı§±∏˝¥ÿøÙ #_TEPF_# */
/* #[<ENTRY_PORT>]# eEnt
 * entry port: eEnt
 * signature:  sShimomura
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eEnt_mcall_lcd
 * name:         eEnt_mcall_lcd
 * global_name:  nTECS2Mruby_tsShimomura_eEnt_mcall_lcd
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eEnt_mcall_lcd(CELLIDX idx, const char* x)
{
  CELLCB    *p_cellcb;
  mrb_state *mrb = cMethodCall_get_mrb();
  if( VALID_IDX( idx ) ){
    p_cellcb = GET_CELLCB(idx);
  }else{
     /* „Ç®„É©„ÉºÂá¶ÁêÜ„Ç≥„Éº„Éâ„Çí„Åì„Åì„Å´Ë®òËø∞*/
  }

  

  struct RClass *shimo = mrb_class_get(mrb, "Shimomura");
  mrb_value shimo_value = mrb_obj_value(shimo);
  mrb_value x_params = mrb_str_new_cstr(mrb, x);  
  mrb_value  yamashina = mrb_funcall(mrb, shimo_value, "new", 0);  
  mrb_funcall(mrb ,yamashina, "mcall_lcd", 1, x_params);
}

/* #[<POSTAMBLE>]#
 *   §≥§Ï§Ë§Í≤º§À»Ûºı§±∏˝¥ÿøÙ§ÚΩÒ§≠§ﬁ§π
 * #[</POSTAMBLE>]#*/
