/*
 * This file contains a list of all
 * initializing methods which are
 * necessary to bootstrap all gems.
 *
 * IMPORTANT:
 *   This file was generated!
 *   All manual changes will get lost.
 */

#include <mruby.h>

void GENERATED_TMP_mrb_mruby_print_gem_init(mrb_state*);
void GENERATED_TMP_mrb_mruby_print_gem_final(mrb_state*);
void GENERATED_TMP_mrb_mruby_toplevel_ext_gem_init(mrb_state*);
void GENERATED_TMP_mrb_mruby_toplevel_ext_gem_final(mrb_state*);
void GENERATED_TMP_mrb_mruby_array_ext_gem_init(mrb_state*);
void GENERATED_TMP_mrb_mruby_array_ext_gem_final(mrb_state*);
void GENERATED_TMP_mrb_mruby_ev3rt_gem_init(mrb_state*);
void GENERATED_TMP_mrb_mruby_ev3rt_gem_final(mrb_state*);

static void
mrb_final_mrbgems(mrb_state *mrb) {
  GENERATED_TMP_mrb_mruby_ev3rt_gem_final(mrb);
  GENERATED_TMP_mrb_mruby_array_ext_gem_final(mrb);
  GENERATED_TMP_mrb_mruby_toplevel_ext_gem_final(mrb);
  GENERATED_TMP_mrb_mruby_print_gem_final(mrb);
}

void
mrb_init_mrbgems(mrb_state *mrb) {
  GENERATED_TMP_mrb_mruby_print_gem_init(mrb);
  GENERATED_TMP_mrb_mruby_toplevel_ext_gem_init(mrb);
  GENERATED_TMP_mrb_mruby_array_ext_gem_init(mrb);
  GENERATED_TMP_mrb_mruby_ev3rt_gem_init(mrb);
  mrb_state_atexit(mrb, mrb_final_mrbgems);
}
