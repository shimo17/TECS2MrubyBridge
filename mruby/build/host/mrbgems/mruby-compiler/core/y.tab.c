/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 7 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:339  */

#undef PARSER_DEBUG
#ifdef PARSER_DEBUG
# define YYDEBUG 1
#endif
#define YYERROR_VERBOSE 1
/*
 * Force yacc to use our memory management.  This is a little evil because
 * the macros assume that "parser_state *p" is in scope
 */
#define YYMALLOC(n)    mrb_malloc(p->mrb, (n))
#define YYFREE(o)      mrb_free(p->mrb, (o))
#define YYSTACK_USE_ALLOCA 0

#include <ctype.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <mruby.h>
#include <mruby/compile.h>
#include <mruby/proc.h>
#include <mruby/error.h>
#include <mruby/throw.h>
#include "node.h"

#define YYLEX_PARAM p

typedef mrb_ast_node node;
typedef struct mrb_parser_state parser_state;
typedef struct mrb_parser_heredoc_info parser_heredoc_info;

static int yyparse(parser_state *p);
static int yylex(void *lval, parser_state *p);
static void yyerror(parser_state *p, const char *s);
static void yywarn(parser_state *p, const char *s);
static void yywarning(parser_state *p, const char *s);
static void backref_error(parser_state *p, node *n);
static void void_expr_error(parser_state *p, node *n);
static void tokadd(parser_state *p, int32_t c);

#define identchar(c) (ISALNUM(c) || (c) == '_' || !ISASCII(c))

typedef unsigned int stack_type;

#define BITSTACK_PUSH(stack, n) ((stack) = ((stack)<<1)|((n)&1))
#define BITSTACK_POP(stack)     ((stack) = (stack) >> 1)
#define BITSTACK_LEXPOP(stack)  ((stack) = ((stack) >> 1) | ((stack) & 1))
#define BITSTACK_SET_P(stack)   ((stack)&1)

#define COND_PUSH(n)    BITSTACK_PUSH(p->cond_stack, (n))
#define COND_POP()      BITSTACK_POP(p->cond_stack)
#define COND_LEXPOP()   BITSTACK_LEXPOP(p->cond_stack)
#define COND_P()        BITSTACK_SET_P(p->cond_stack)

#define CMDARG_PUSH(n)  BITSTACK_PUSH(p->cmdarg_stack, (n))
#define CMDARG_POP()    BITSTACK_POP(p->cmdarg_stack)
#define CMDARG_LEXPOP() BITSTACK_LEXPOP(p->cmdarg_stack)
#define CMDARG_P()      BITSTACK_SET_P(p->cmdarg_stack)

#define SET_LINENO(c,n) ((c)->lineno = (n))
#define NODE_LINENO(c,n) do {\
  if (n) {\
     (c)->filename_index = (n)->filename_index;\
     (c)->lineno = (n)->lineno;\
  }\
} while (0)

#define sym(x) ((mrb_sym)(intptr_t)(x))
#define nsym(x) ((node*)(intptr_t)(x))
#define nint(x) ((node*)(intptr_t)(x))
#define intn(x) ((int)(intptr_t)(x))

static inline mrb_sym
intern_cstr_gen(parser_state *p, const char *s)
{
  return mrb_intern_cstr(p->mrb, s);
}
#define intern_cstr(s) intern_cstr_gen(p,(s))

static inline mrb_sym
intern_gen(parser_state *p, const char *s, size_t len)
{
  return mrb_intern(p->mrb, s, len);
}
#define intern(s,len) intern_gen(p,(s),(len))

static inline mrb_sym
intern_gen_c(parser_state *p, const char c)
{
  return mrb_intern(p->mrb, &c, 1);
}
#define intern_c(c) intern_gen_c(p,(c))

static void
cons_free_gen(parser_state *p, node *cons)
{
  cons->cdr = p->cells;
  p->cells = cons;
}
#define cons_free(c) cons_free_gen(p, (c))

static void*
parser_palloc(parser_state *p, size_t size)
{
  void *m = mrb_pool_alloc(p->pool, size);

  if (!m) {
    MRB_THROW(p->jmp);
  }
  return m;
}

static node*
cons_gen(parser_state *p, node *car, node *cdr)
{
  node *c;

  if (p->cells) {
    c = p->cells;
    p->cells = p->cells->cdr;
  }
  else {
    c = (node *)parser_palloc(p, sizeof(mrb_ast_node));
  }

  c->car = car;
  c->cdr = cdr;
  c->lineno = p->lineno;
  c->filename_index = p->current_filename_index;
  /* beginning of next partial file; need to point the previous file */
  if (p->lineno == 0 && p->current_filename_index > 0) {
    c->filename_index-- ;
  }
  return c;
}
#define cons(a,b) cons_gen(p,(a),(b))

static node*
list1_gen(parser_state *p, node *a)
{
  return cons(a, 0);
}
#define list1(a) list1_gen(p, (a))

static node*
list2_gen(parser_state *p, node *a, node *b)
{
  return cons(a, cons(b,0));
}
#define list2(a,b) list2_gen(p, (a),(b))

static node*
list3_gen(parser_state *p, node *a, node *b, node *c)
{
  return cons(a, cons(b, cons(c,0)));
}
#define list3(a,b,c) list3_gen(p, (a),(b),(c))

static node*
list4_gen(parser_state *p, node *a, node *b, node *c, node *d)
{
  return cons(a, cons(b, cons(c, cons(d, 0))));
}
#define list4(a,b,c,d) list4_gen(p, (a),(b),(c),(d))

static node*
list5_gen(parser_state *p, node *a, node *b, node *c, node *d, node *e)
{
  return cons(a, cons(b, cons(c, cons(d, cons(e, 0)))));
}
#define list5(a,b,c,d,e) list5_gen(p, (a),(b),(c),(d),(e))

static node*
list6_gen(parser_state *p, node *a, node *b, node *c, node *d, node *e, node *f)
{
  return cons(a, cons(b, cons(c, cons(d, cons(e, cons(f, 0))))));
}
#define list6(a,b,c,d,e,f) list6_gen(p, (a),(b),(c),(d),(e),(f))

static node*
append_gen(parser_state *p, node *a, node *b)
{
  node *c = a;

  if (!a) return b;
  while (c->cdr) {
    c = c->cdr;
  }
  if (b) {
    c->cdr = b;
  }
  return a;
}
#define append(a,b) append_gen(p,(a),(b))
#define push(a,b) append_gen(p,(a),list1(b))

static char*
parser_strndup(parser_state *p, const char *s, size_t len)
{
  char *b = (char *)parser_palloc(p, len+1);

  memcpy(b, s, len);
  b[len] = '\0';
  return b;
}
#undef strndup
#define strndup(s,len) parser_strndup(p, s, len)

static char*
parser_strdup(parser_state *p, const char *s)
{
  return parser_strndup(p, s, strlen(s));
}
#undef strdup
#define strdup(s) parser_strdup(p, s)

/* xxx ----------------------------- */

static node*
local_switch(parser_state *p)
{
  node *prev = p->locals;

  p->locals = cons(0, 0);
  return prev;
}

static void
local_resume(parser_state *p, node *prev)
{
  p->locals = prev;
}

static void
local_nest(parser_state *p)
{
  p->locals = cons(0, p->locals);
}

static void
local_unnest(parser_state *p)
{
  if (p->locals) {
    p->locals = p->locals->cdr;
  }
}

static mrb_bool
local_var_p(parser_state *p, mrb_sym sym)
{
  node *l = p->locals;

  while (l) {
    node *n = l->car;
    while (n) {
      if (sym(n->car) == sym) return TRUE;
      n = n->cdr;
    }
    l = l->cdr;
  }
  return FALSE;
}

static void
local_add_f(parser_state *p, mrb_sym sym)
{
  if (p->locals) {
    p->locals->car = push(p->locals->car, nsym(sym));
  }
}

static void
local_add(parser_state *p, mrb_sym sym)
{
  if (!local_var_p(p, sym)) {
    local_add_f(p, sym);
  }
}

static node*
locals_node(parser_state *p)
{
  return p->locals ? p->locals->car : NULL;
}

/* (:scope (vars..) (prog...)) */
static node*
new_scope(parser_state *p, node *body)
{
  return cons((node*)NODE_SCOPE, cons(locals_node(p), body));
}

/* (:begin prog...) */
static node*
new_begin(parser_state *p, node *body)
{
  if (body) {
    return list2((node*)NODE_BEGIN, body);
  }
  return cons((node*)NODE_BEGIN, 0);
}

#define newline_node(n) (n)

/* (:rescue body rescue else) */
static node*
new_rescue(parser_state *p, node *body, node *resq, node *els)
{
  return list4((node*)NODE_RESCUE, body, resq, els);
}

static node*
new_mod_rescue(parser_state *p, node *body, node *resq)
{
  return new_rescue(p, body, list1(list3(0, 0, resq)), 0);
}

/* (:ensure body ensure) */
static node*
new_ensure(parser_state *p, node *a, node *b)
{
  return cons((node*)NODE_ENSURE, cons(a, cons(0, b)));
}

/* (:nil) */
static node*
new_nil(parser_state *p)
{
  return list1((node*)NODE_NIL);
}

/* (:true) */
static node*
new_true(parser_state *p)
{
  return list1((node*)NODE_TRUE);
}

/* (:false) */
static node*
new_false(parser_state *p)
{
  return list1((node*)NODE_FALSE);
}

/* (:alias new old) */
static node*
new_alias(parser_state *p, mrb_sym a, mrb_sym b)
{
  return cons((node*)NODE_ALIAS, cons(nsym(a), nsym(b)));
}

/* (:if cond then else) */
static node*
new_if(parser_state *p, node *a, node *b, node *c)
{
  void_expr_error(p, a);
  return list4((node*)NODE_IF, a, b, c);
}

/* (:unless cond then else) */
static node*
new_unless(parser_state *p, node *a, node *b, node *c)
{
  void_expr_error(p, a);
  return list4((node*)NODE_IF, a, c, b);
}

/* (:while cond body) */
static node*
new_while(parser_state *p, node *a, node *b)
{
  void_expr_error(p, a);
  return cons((node*)NODE_WHILE, cons(a, b));
}

/* (:until cond body) */
static node*
new_until(parser_state *p, node *a, node *b)
{
  void_expr_error(p, a);
  return cons((node*)NODE_UNTIL, cons(a, b));
}

/* (:for var obj body) */
static node*
new_for(parser_state *p, node *v, node *o, node *b)
{
  void_expr_error(p, o);
  return list4((node*)NODE_FOR, v, o, b);
}

/* (:case a ((when ...) body) ((when...) body)) */
static node*
new_case(parser_state *p, node *a, node *b)
{
  node *n = list2((node*)NODE_CASE, a);
  node *n2 = n;

  void_expr_error(p, a);
  while (n2->cdr) {
    n2 = n2->cdr;
  }
  n2->cdr = b;
  return n;
}

/* (:postexe a) */
static node*
new_postexe(parser_state *p, node *a)
{
  return cons((node*)NODE_POSTEXE, a);
}

/* (:self) */
static node*
new_self(parser_state *p)
{
  return list1((node*)NODE_SELF);
}

/* (:call a b c) */
static node*
new_call(parser_state *p, node *a, mrb_sym b, node *c, int pass)
{
  node *n = list4(nint(pass?NODE_CALL:NODE_SCALL), a, nsym(b), c);
  void_expr_error(p, a);
  NODE_LINENO(n, a);
  return n;
}

/* (:fcall self mid args) */
static node*
new_fcall(parser_state *p, mrb_sym b, node *c)
{
  node *n = new_self(p);
  NODE_LINENO(n, c);
  n = list4((node*)NODE_FCALL, n, nsym(b), c);
  NODE_LINENO(n, c);
  return n;
}

/* (:super . c) */
static node*
new_super(parser_state *p, node *c)
{
  return cons((node*)NODE_SUPER, c);
}

/* (:zsuper) */
static node*
new_zsuper(parser_state *p)
{
  return list1((node*)NODE_ZSUPER);
}

/* (:yield . c) */
static node*
new_yield(parser_state *p, node *c)
{
  if (c) {
    if (c->cdr) {
      yyerror(p, "both block arg and actual block given");
    }
    return cons((node*)NODE_YIELD, c->car);
  }
  return cons((node*)NODE_YIELD, 0);
}

/* (:return . c) */
static node*
new_return(parser_state *p, node *c)
{
  return cons((node*)NODE_RETURN, c);
}

/* (:break . c) */
static node*
new_break(parser_state *p, node *c)
{
  return cons((node*)NODE_BREAK, c);
}

/* (:next . c) */
static node*
new_next(parser_state *p, node *c)
{
  return cons((node*)NODE_NEXT, c);
}

/* (:redo) */
static node*
new_redo(parser_state *p)
{
  return list1((node*)NODE_REDO);
}

/* (:retry) */
static node*
new_retry(parser_state *p)
{
  return list1((node*)NODE_RETRY);
}

/* (:dot2 a b) */
static node*
new_dot2(parser_state *p, node *a, node *b)
{
  return cons((node*)NODE_DOT2, cons(a, b));
}

/* (:dot3 a b) */
static node*
new_dot3(parser_state *p, node *a, node *b)
{
  return cons((node*)NODE_DOT3, cons(a, b));
}

/* (:colon2 b c) */
static node*
new_colon2(parser_state *p, node *b, mrb_sym c)
{
  void_expr_error(p, b);
  return cons((node*)NODE_COLON2, cons(b, nsym(c)));
}

/* (:colon3 . c) */
static node*
new_colon3(parser_state *p, mrb_sym c)
{
  return cons((node*)NODE_COLON3, nsym(c));
}

/* (:and a b) */
static node*
new_and(parser_state *p, node *a, node *b)
{
  return cons((node*)NODE_AND, cons(a, b));
}

/* (:or a b) */
static node*
new_or(parser_state *p, node *a, node *b)
{
  return cons((node*)NODE_OR, cons(a, b));
}

/* (:array a...) */
static node*
new_array(parser_state *p, node *a)
{
  return cons((node*)NODE_ARRAY, a);
}

/* (:splat . a) */
static node*
new_splat(parser_state *p, node *a)
{
  return cons((node*)NODE_SPLAT, a);
}

/* (:hash (k . v) (k . v)...) */
static node*
new_hash(parser_state *p, node *a)
{
  return cons((node*)NODE_HASH, a);
}

/* (:kw_hash (k . v) (k . v)...) */
static node*
new_kw_hash(parser_state *p, node *a)
{
  return cons((node*)NODE_KW_HASH, a);
}

/* (:sym . a) */
static node*
new_sym(parser_state *p, mrb_sym sym)
{
  return cons((node*)NODE_SYM, nsym(sym));
}

static mrb_sym
new_strsym(parser_state *p, node* str)
{
  const char *s = (const char*)str->cdr->car;
  size_t len = (size_t)str->cdr->cdr;

  return mrb_intern(p->mrb, s, len);
}

/* (:lvar . a) */
static node*
new_lvar(parser_state *p, mrb_sym sym)
{
  return cons((node*)NODE_LVAR, nsym(sym));
}

/* (:gvar . a) */
static node*
new_gvar(parser_state *p, mrb_sym sym)
{
  return cons((node*)NODE_GVAR, nsym(sym));
}

/* (:ivar . a) */
static node*
new_ivar(parser_state *p, mrb_sym sym)
{
  return cons((node*)NODE_IVAR, nsym(sym));
}

/* (:cvar . a) */
static node*
new_cvar(parser_state *p, mrb_sym sym)
{
  return cons((node*)NODE_CVAR, nsym(sym));
}

/* (:const . a) */
static node*
new_const(parser_state *p, mrb_sym sym)
{
  return cons((node*)NODE_CONST, nsym(sym));
}

/* (:undef a...) */
static node*
new_undef(parser_state *p, mrb_sym sym)
{
  return list2((node*)NODE_UNDEF, nsym(sym));
}

/* (:class class super body) */
static node*
new_class(parser_state *p, node *c, node *s, node *b)
{
  void_expr_error(p, s);
  return list4((node*)NODE_CLASS, c, s, cons(locals_node(p), b));
}

/* (:sclass obj body) */
static node*
new_sclass(parser_state *p, node *o, node *b)
{
  void_expr_error(p, o);
  return list3((node*)NODE_SCLASS, o, cons(locals_node(p), b));
}

/* (:module module body) */
static node*
new_module(parser_state *p, node *m, node *b)
{
  return list3((node*)NODE_MODULE, m, cons(locals_node(p), b));
}

/* (:def m lv (arg . body)) */
static node*
new_def(parser_state *p, mrb_sym m, node *a, node *b)
{
  return list5((node*)NODE_DEF, nsym(m), locals_node(p), a, b);
}

/* (:sdef obj m lv (arg . body)) */
static node*
new_sdef(parser_state *p, node *o, mrb_sym m, node *a, node *b)
{
  void_expr_error(p, o);
  return list6((node*)NODE_SDEF, o, nsym(m), locals_node(p), a, b);
}

/* (:arg . sym) */
static node*
new_arg(parser_state *p, mrb_sym sym)
{
  return cons((node*)NODE_ARG, nsym(sym));
}

static void
local_add_margs(parser_state *p, node *n)
{
  while (n) {
    if (n->car->car == (node*)NODE_MASGN) {
      node *t = n->car->cdr->cdr;

      n->car->cdr->cdr = NULL;
      while (t) {
        local_add_f(p, sym(t->car));
        t = t->cdr;
      }
      local_add_margs(p, n->car->cdr->car->car);
      local_add_margs(p, n->car->cdr->car->cdr->cdr->car);
    }
    n = n->cdr;
  }
}

/* (m o r m2 tail) */
/* m: (a b c) */
/* o: ((a . e1) (b . e2)) */
/* r: a */
/* m2: (a b c) */
/* b: a */
static node*
new_args(parser_state *p, node *m, node *opt, mrb_sym rest, node *m2, node *tail)
{
  node *n;

  local_add_margs(p, m);
  local_add_margs(p, m2);
  n = cons(m2, tail);
  n = cons(nsym(rest), n);
  n = cons(opt, n);
  return cons(m, n);
}

/* (:args_tail keywords rest_keywords_sym block_sym) */
static node*
new_args_tail(parser_state *p, node *kws, node *kwrest, mrb_sym blk)
{
  node *k;

  /* allocate register for keywords hash */
  if (kws || kwrest) {
    local_add_f(p, (kwrest && kwrest->cdr)? sym(kwrest->cdr) :  mrb_intern_lit(p->mrb, "**"));
  }

  /* allocate register for block */
  local_add_f(p, blk? blk : mrb_intern_lit(p->mrb, "&"));

  // allocate register for keywords arguments
  // order is for Proc#parameters
  for (k = kws; k; k = k->cdr) {
    if (!k->car->cdr->cdr->car) { // allocate required keywords
      local_add_f(p, sym(k->car->cdr->car));
    }
  }
  for (k = kws; k; k = k->cdr) {
    if (k->car->cdr->cdr->car) { // allocate keywords with default
      local_add_f(p, sym(k->car->cdr->car));
    }
  }

  return list4((node*)NODE_ARGS_TAIL, kws, kwrest, nsym(blk));
}

/* (:kw_arg kw_sym def_arg) */
static node*
new_kw_arg(parser_state *p, mrb_sym kw, node *def_arg)
{
  mrb_assert(kw);
  return list3((node*)NODE_KW_ARG, nsym(kw), def_arg);
}

/* (:block_arg . a) */
static node*
new_block_arg(parser_state *p, node *a)
{
  return cons((node*)NODE_BLOCK_ARG, a);
}

/* (:block arg body) */
static node*
new_block(parser_state *p, node *a, node *b)
{
  return list4((node*)NODE_BLOCK, locals_node(p), a, b);
}

/* (:lambda arg body) */
static node*
new_lambda(parser_state *p, node *a, node *b)
{
  return list4((node*)NODE_LAMBDA, locals_node(p), a, b);
}

/* (:asgn lhs rhs) */
static node*
new_asgn(parser_state *p, node *a, node *b)
{
  void_expr_error(p, b);
  return cons((node*)NODE_ASGN, cons(a, b));
}

/* (:masgn mlhs=(pre rest post)  mrhs) */
static node*
new_masgn(parser_state *p, node *a, node *b)
{
  void_expr_error(p, b);
  return cons((node*)NODE_MASGN, cons(a, b));
}

/* (:asgn lhs rhs) */
static node*
new_op_asgn(parser_state *p, node *a, mrb_sym op, node *b)
{
  void_expr_error(p, b);
  return list4((node*)NODE_OP_ASGN, a, nsym(op), b);
}

/* (:int . i) */
static node*
new_int(parser_state *p, const char *s, int base)
{
  return list3((node*)NODE_INT, (node*)strdup(s), nint(base));
}

#ifndef MRB_WITHOUT_FLOAT
/* (:float . i) */
static node*
new_float(parser_state *p, const char *s)
{
  return cons((node*)NODE_FLOAT, (node*)strdup(s));
}
#endif

/* (:str . (s . len)) */
static node*
new_str(parser_state *p, const char *s, size_t len)
{
  return cons((node*)NODE_STR, cons((node*)strndup(s, len), nint(len)));
}

/* (:dstr . a) */
static node*
new_dstr(parser_state *p, node *a)
{
  return cons((node*)NODE_DSTR, a);
}

/* (:str . (s . len)) */
static node*
new_xstr(parser_state *p, const char *s, int len)
{
  return cons((node*)NODE_XSTR, cons((node*)strndup(s, len), nint(len)));
}

/* (:xstr . a) */
static node*
new_dxstr(parser_state *p, node *a)
{
  return cons((node*)NODE_DXSTR, a);
}

/* (:dsym . a) */
static node*
new_dsym(parser_state *p, node *a)
{
  return cons((node*)NODE_DSYM, a);
}

/* (:regx . (s . (opt . enc))) */
static node*
new_regx(parser_state *p, const char *p1, const char* p2, const char* p3)
{
  return cons((node*)NODE_REGX, cons((node*)p1, cons((node*)p2, (node*)p3)));
}

/* (:dregx . (a . b)) */
static node*
new_dregx(parser_state *p, node *a, node *b)
{
  return cons((node*)NODE_DREGX, cons(a, b));
}

/* (:backref . n) */
static node*
new_back_ref(parser_state *p, int n)
{
  return cons((node*)NODE_BACK_REF, nint(n));
}

/* (:nthref . n) */
static node*
new_nth_ref(parser_state *p, int n)
{
  return cons((node*)NODE_NTH_REF, nint(n));
}

/* (:heredoc . a) */
static node*
new_heredoc(parser_state *p)
{
  parser_heredoc_info *inf = (parser_heredoc_info *)parser_palloc(p, sizeof(parser_heredoc_info));
  return cons((node*)NODE_HEREDOC, (node*)inf);
}

static void
new_bv(parser_state *p, mrb_sym id)
{
}

static node*
new_literal_delim(parser_state *p)
{
  return cons((node*)NODE_LITERAL_DELIM, 0);
}

/* (:words . a) */
static node*
new_words(parser_state *p, node *a)
{
  return cons((node*)NODE_WORDS, a);
}

/* (:symbols . a) */
static node*
new_symbols(parser_state *p, node *a)
{
  return cons((node*)NODE_SYMBOLS, a);
}

/* xxx ----------------------------- */

/* (:call a op) */
static node*
call_uni_op(parser_state *p, node *recv, const char *m)
{
  void_expr_error(p, recv);
  return new_call(p, recv, intern_cstr(m), 0, 1);
}

/* (:call a op b) */
static node*
call_bin_op(parser_state *p, node *recv, const char *m, node *arg1)
{
  return new_call(p, recv, intern_cstr(m), list1(list1(arg1)), 1);
}

static void
args_with_block(parser_state *p, node *a, node *b)
{
  if (b) {
    if (a->cdr) {
      yyerror(p, "both block arg and actual block given");
    }
    a->cdr = b;
  }
}

static void
call_with_block(parser_state *p, node *a, node *b)
{
  node *n;

  switch ((enum node_type)intn(a->car)) {
  case NODE_SUPER:
  case NODE_ZSUPER:
    if (!a->cdr) a->cdr = cons(0, b);
    else {
      args_with_block(p, a->cdr, b);
    }
    break;
  case NODE_CALL:
  case NODE_FCALL:
  case NODE_SCALL:
    n = a->cdr->cdr->cdr;
    if (!n->car) n->car = cons(0, b);
    else {
      args_with_block(p, n->car, b);
    }
    break;
  default:
    break;
  }
}

static node*
negate_lit(parser_state *p, node *n)
{
  return cons((node*)NODE_NEGATE, n);
}

static node*
cond(node *n)
{
  return n;
}

static node*
ret_args(parser_state *p, node *n)
{
  if (n->cdr) {
    yyerror(p, "block argument should not be given");
    return NULL;
  }
  if (!n->car->cdr) return n->car->car;
  return new_array(p, n->car);
}

static void
assignable(parser_state *p, node *lhs)
{
  if (intn(lhs->car) == NODE_LVAR) {
    local_add(p, sym(lhs->cdr));
  }
}

static node*
var_reference(parser_state *p, node *lhs)
{
  node *n;

  if (intn(lhs->car) == NODE_LVAR) {
    if (!local_var_p(p, sym(lhs->cdr))) {
      n = new_fcall(p, sym(lhs->cdr), 0);
      cons_free(lhs);
      return n;
    }
  }

  return lhs;
}

typedef enum mrb_string_type  string_type;

static node*
new_strterm(parser_state *p, string_type type, int term, int paren)
{
  return cons(nint(type), cons((node*)0, cons(nint(paren), nint(term))));
}

static void
end_strterm(parser_state *p)
{
  cons_free(p->lex_strterm->cdr->cdr);
  cons_free(p->lex_strterm->cdr);
  cons_free(p->lex_strterm);
  p->lex_strterm = NULL;
}

static parser_heredoc_info *
parsing_heredoc_inf(parser_state *p)
{
  node *nd = p->parsing_heredoc;
  if (nd == NULL)
    return NULL;
  /* mrb_assert(nd->car->car == NODE_HEREDOC); */
  return (parser_heredoc_info*)nd->car->cdr;
}

static void
heredoc_treat_nextline(parser_state *p)
{
  if (p->heredocs_from_nextline == NULL)
    return;
  if (p->parsing_heredoc == NULL) {
    node *n;
    p->parsing_heredoc = p->heredocs_from_nextline;
    p->lex_strterm_before_heredoc = p->lex_strterm;
    p->lex_strterm = new_strterm(p, parsing_heredoc_inf(p)->type, 0, 0);
    n = p->all_heredocs;
    if (n) {
      while (n->cdr)
        n = n->cdr;
      n->cdr = p->parsing_heredoc;
    }
    else {
      p->all_heredocs = p->parsing_heredoc;
    }
  }
  else {
    node *n, *m;
    m = p->heredocs_from_nextline;
    while (m->cdr)
      m = m->cdr;
    n = p->all_heredocs;
    mrb_assert(n != NULL);
    if (n == p->parsing_heredoc) {
      m->cdr = n;
      p->all_heredocs = p->heredocs_from_nextline;
      p->parsing_heredoc = p->heredocs_from_nextline;
    }
    else {
      while (n->cdr != p->parsing_heredoc) {
        n = n->cdr;
        mrb_assert(n != NULL);
      }
      m->cdr = n->cdr;
      n->cdr = p->heredocs_from_nextline;
      p->parsing_heredoc = p->heredocs_from_nextline;
    }
  }
  p->heredocs_from_nextline = NULL;
}

static void
heredoc_end(parser_state *p)
{
  p->parsing_heredoc = p->parsing_heredoc->cdr;
  if (p->parsing_heredoc == NULL) {
    p->lstate = EXPR_BEG;
    p->cmd_start = TRUE;
    end_strterm(p);
    p->lex_strterm = p->lex_strterm_before_heredoc;
    p->lex_strterm_before_heredoc = NULL;
  }
  else {
    /* next heredoc */
    p->lex_strterm->car = nint(parsing_heredoc_inf(p)->type);
  }
}
#define is_strterm_type(p,str_func) (intn((p)->lex_strterm->car) & (str_func))

/* xxx ----------------------------- */


#line 1173 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    keyword_class = 258,
    keyword_module = 259,
    keyword_def = 260,
    keyword_begin = 261,
    keyword_if = 262,
    keyword_unless = 263,
    keyword_while = 264,
    keyword_until = 265,
    keyword_for = 266,
    keyword_undef = 267,
    keyword_rescue = 268,
    keyword_ensure = 269,
    keyword_end = 270,
    keyword_then = 271,
    keyword_elsif = 272,
    keyword_else = 273,
    keyword_case = 274,
    keyword_when = 275,
    keyword_break = 276,
    keyword_next = 277,
    keyword_redo = 278,
    keyword_retry = 279,
    keyword_in = 280,
    keyword_do = 281,
    keyword_do_cond = 282,
    keyword_do_block = 283,
    keyword_do_LAMBDA = 284,
    keyword_return = 285,
    keyword_yield = 286,
    keyword_super = 287,
    keyword_self = 288,
    keyword_nil = 289,
    keyword_true = 290,
    keyword_false = 291,
    keyword_and = 292,
    keyword_or = 293,
    keyword_not = 294,
    modifier_if = 295,
    modifier_unless = 296,
    modifier_while = 297,
    modifier_until = 298,
    modifier_rescue = 299,
    keyword_alias = 300,
    keyword_BEGIN = 301,
    keyword_END = 302,
    keyword__LINE__ = 303,
    keyword__FILE__ = 304,
    keyword__ENCODING__ = 305,
    tIDENTIFIER = 306,
    tFID = 307,
    tGVAR = 308,
    tIVAR = 309,
    tCONSTANT = 310,
    tCVAR = 311,
    tLABEL_TAG = 312,
    tINTEGER = 313,
    tFLOAT = 314,
    tCHAR = 315,
    tXSTRING = 316,
    tREGEXP = 317,
    tSTRING = 318,
    tSTRING_PART = 319,
    tSTRING_MID = 320,
    tNTH_REF = 321,
    tBACK_REF = 322,
    tREGEXP_END = 323,
    tUPLUS = 324,
    tUMINUS = 325,
    tPOW = 326,
    tCMP = 327,
    tEQ = 328,
    tEQQ = 329,
    tNEQ = 330,
    tGEQ = 331,
    tLEQ = 332,
    tANDOP = 333,
    tOROP = 334,
    tMATCH = 335,
    tNMATCH = 336,
    tDOT2 = 337,
    tDOT3 = 338,
    tAREF = 339,
    tASET = 340,
    tLSHFT = 341,
    tRSHFT = 342,
    tCOLON2 = 343,
    tCOLON3 = 344,
    tOP_ASGN = 345,
    tASSOC = 346,
    tLPAREN = 347,
    tLPAREN_ARG = 348,
    tRPAREN = 349,
    tLBRACK = 350,
    tLBRACE = 351,
    tLBRACE_ARG = 352,
    tSTAR = 353,
    tDSTAR = 354,
    tAMPER = 355,
    tLAMBDA = 356,
    tANDDOT = 357,
    tSYMBEG = 358,
    tREGEXP_BEG = 359,
    tWORDS_BEG = 360,
    tSYMBOLS_BEG = 361,
    tSTRING_BEG = 362,
    tXSTRING_BEG = 363,
    tSTRING_DVAR = 364,
    tLAMBEG = 365,
    tHEREDOC_BEG = 366,
    tHEREDOC_END = 367,
    tLITERAL_DELIM = 368,
    tHD_LITERAL_DELIM = 369,
    tHD_STRING_PART = 370,
    tHD_STRING_MID = 371,
    tLOWEST = 372,
    tUMINUS_NUM = 373,
    tLAST_TOKEN = 374
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 1118 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:355  */

    node *nd;
    mrb_sym id;
    int num;
    stack_type stack;
    const struct vtable *vars;

#line 1338 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif



int yyparse (parser_state *p);



/* Copy the second part of user declarations.  */

#line 1354 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   11679

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  146
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  174
/* YYNRULES -- Number of rules.  */
#define YYNRULES  584
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1021

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   374

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     145,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   132,     2,     2,     2,   130,   125,     2,
     140,   141,   128,   126,   138,   127,   144,   129,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   120,   143,
     122,   118,   121,   119,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   137,     2,   142,   124,     2,   139,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   135,   123,   136,   133,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   131,   134
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,  1275,  1275,  1275,  1286,  1292,  1296,  1301,  1305,  1311,
    1313,  1312,  1324,  1351,  1357,  1361,  1366,  1370,  1376,  1376,
    1380,  1384,  1388,  1392,  1396,  1400,  1404,  1409,  1410,  1414,
    1418,  1422,  1426,  1429,  1433,  1437,  1441,  1445,  1449,  1454,
    1458,  1465,  1466,  1470,  1474,  1475,  1479,  1483,  1487,  1491,
    1494,  1503,  1504,  1507,  1508,  1515,  1514,  1527,  1531,  1536,
    1540,  1545,  1549,  1554,  1558,  1562,  1566,  1570,  1576,  1580,
    1586,  1587,  1593,  1597,  1601,  1605,  1609,  1613,  1617,  1621,
    1625,  1629,  1635,  1636,  1642,  1646,  1652,  1656,  1662,  1666,
    1670,  1674,  1678,  1682,  1688,  1694,  1701,  1705,  1709,  1713,
    1717,  1721,  1727,  1733,  1740,  1744,  1747,  1751,  1755,  1762,
    1763,  1764,  1765,  1770,  1777,  1778,  1781,  1785,  1785,  1791,
    1792,  1793,  1794,  1795,  1796,  1797,  1798,  1799,  1800,  1801,
    1802,  1803,  1804,  1805,  1806,  1807,  1808,  1809,  1810,  1811,
    1812,  1813,  1814,  1815,  1816,  1817,  1818,  1819,  1820,  1823,
    1823,  1823,  1824,  1824,  1825,  1825,  1825,  1826,  1826,  1826,
    1826,  1827,  1827,  1827,  1828,  1828,  1828,  1829,  1829,  1829,
    1829,  1830,  1830,  1830,  1830,  1831,  1831,  1831,  1831,  1832,
    1832,  1832,  1832,  1833,  1833,  1833,  1833,  1834,  1834,  1837,
    1841,  1845,  1849,  1853,  1857,  1861,  1866,  1871,  1876,  1880,
    1884,  1888,  1892,  1896,  1900,  1904,  1908,  1912,  1916,  1920,
    1924,  1928,  1932,  1936,  1940,  1944,  1948,  1952,  1956,  1960,
    1964,  1968,  1972,  1976,  1980,  1984,  1988,  1992,  1996,  2000,
    2004,  2008,  2014,  2015,  2020,  2024,  2031,  2035,  2043,  2049,
    2050,  2053,  2054,  2055,  2060,  2065,  2072,  2078,  2083,  2088,
    2093,  2100,  2100,  2111,  2117,  2121,  2127,  2128,  2131,  2137,
    2143,  2148,  2155,  2160,  2165,  2172,  2173,  2174,  2175,  2176,
    2177,  2178,  2179,  2184,  2183,  2195,  2199,  2194,  2204,  2204,
    2208,  2212,  2216,  2220,  2225,  2230,  2234,  2238,  2242,  2246,
    2250,  2251,  2257,  2263,  2256,  2275,  2283,  2291,  2291,  2291,
    2298,  2298,  2298,  2305,  2311,  2316,  2318,  2315,  2327,  2325,
    2341,  2346,  2339,  2361,  2359,  2374,  2378,  2373,  2393,  2399,
    2392,  2414,  2418,  2422,  2426,  2432,  2439,  2440,  2441,  2444,
    2445,  2448,  2449,  2457,  2458,  2464,  2468,  2471,  2475,  2479,
    2483,  2488,  2492,  2496,  2500,  2506,  2505,  2515,  2519,  2523,
    2527,  2533,  2538,  2543,  2547,  2551,  2555,  2559,  2563,  2567,
    2571,  2575,  2579,  2583,  2587,  2591,  2595,  2599,  2605,  2606,
    2613,  2617,  2621,  2628,  2632,  2638,  2639,  2642,  2647,  2650,
    2654,  2660,  2664,  2671,  2670,  2683,  2693,  2697,  2702,  2709,
    2713,  2717,  2721,  2725,  2729,  2733,  2737,  2741,  2748,  2747,
    2760,  2759,  2773,  2781,  2790,  2793,  2800,  2803,  2807,  2808,
    2811,  2815,  2818,  2822,  2825,  2826,  2827,  2828,  2831,  2832,
    2833,  2837,  2843,  2844,  2850,  2855,  2854,  2865,  2869,  2875,
    2879,  2885,  2889,  2895,  2898,  2899,  2902,  2908,  2914,  2915,
    2918,  2925,  2924,  2938,  2942,  2949,  2954,  2961,  2967,  2968,
    2969,  2970,  2971,  2975,  2981,  2985,  2991,  2992,  2993,  2997,
    3003,  3007,  3011,  3015,  3019,  3025,  3031,  3035,  3039,  3043,
    3047,  3051,  3059,  3066,  3077,  3078,  3082,  3086,  3085,  3101,
    3107,  3113,  3116,  3121,  3127,  3131,  3137,  3141,  3147,  3151,
    3157,  3158,  3161,  3165,  3171,  3175,  3179,  3183,  3189,  3194,
    3199,  3203,  3207,  3211,  3215,  3219,  3223,  3227,  3231,  3235,
    3239,  3243,  3247,  3251,  3256,  3262,  3267,  3272,  3277,  3284,
    3288,  3295,  3300,  3299,  3311,  3315,  3321,  3328,  3335,  3342,
    3346,  3352,  3356,  3362,  3363,  3366,  3371,  3378,  3379,  3382,
    3388,  3392,  3398,  3403,  3403,  3428,  3429,  3435,  3440,  3446,
    3452,  3457,  3467,  3474,  3475,  3476,  3479,  3480,  3481,  3482,
    3485,  3486,  3487,  3490,  3491,  3494,  3498,  3504,  3505,  3511,
    3512,  3515,  3516,  3519,  3522,  3525,  3526,  3527,  3530,  3531,
    3532,  3535,  3542,  3543,  3547
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "keyword_class", "keyword_module",
  "keyword_def", "keyword_begin", "keyword_if", "keyword_unless",
  "keyword_while", "keyword_until", "keyword_for", "keyword_undef",
  "keyword_rescue", "keyword_ensure", "keyword_end", "keyword_then",
  "keyword_elsif", "keyword_else", "keyword_case", "keyword_when",
  "keyword_break", "keyword_next", "keyword_redo", "keyword_retry",
  "keyword_in", "keyword_do", "keyword_do_cond", "keyword_do_block",
  "keyword_do_LAMBDA", "keyword_return", "keyword_yield", "keyword_super",
  "keyword_self", "keyword_nil", "keyword_true", "keyword_false",
  "keyword_and", "keyword_or", "keyword_not", "modifier_if",
  "modifier_unless", "modifier_while", "modifier_until", "modifier_rescue",
  "keyword_alias", "keyword_BEGIN", "keyword_END", "keyword__LINE__",
  "keyword__FILE__", "keyword__ENCODING__", "tIDENTIFIER", "tFID", "tGVAR",
  "tIVAR", "tCONSTANT", "tCVAR", "tLABEL_TAG", "tINTEGER", "tFLOAT",
  "tCHAR", "tXSTRING", "tREGEXP", "tSTRING", "tSTRING_PART", "tSTRING_MID",
  "tNTH_REF", "tBACK_REF", "tREGEXP_END", "tUPLUS", "tUMINUS", "tPOW",
  "tCMP", "tEQ", "tEQQ", "tNEQ", "tGEQ", "tLEQ", "tANDOP", "tOROP",
  "tMATCH", "tNMATCH", "tDOT2", "tDOT3", "tAREF", "tASET", "tLSHFT",
  "tRSHFT", "tCOLON2", "tCOLON3", "tOP_ASGN", "tASSOC", "tLPAREN",
  "tLPAREN_ARG", "tRPAREN", "tLBRACK", "tLBRACE", "tLBRACE_ARG", "tSTAR",
  "tDSTAR", "tAMPER", "tLAMBDA", "tANDDOT", "tSYMBEG", "tREGEXP_BEG",
  "tWORDS_BEG", "tSYMBOLS_BEG", "tSTRING_BEG", "tXSTRING_BEG",
  "tSTRING_DVAR", "tLAMBEG", "tHEREDOC_BEG", "tHEREDOC_END",
  "tLITERAL_DELIM", "tHD_LITERAL_DELIM", "tHD_STRING_PART",
  "tHD_STRING_MID", "tLOWEST", "'='", "'?'", "':'", "'>'", "'<'", "'|'",
  "'^'", "'&'", "'+'", "'-'", "'*'", "'/'", "'%'", "tUMINUS_NUM", "'!'",
  "'~'", "tLAST_TOKEN", "'{'", "'}'", "'['", "','", "'`'", "'('", "')'",
  "']'", "';'", "'.'", "'\\n'", "$accept", "program", "$@1",
  "top_compstmt", "top_stmts", "top_stmt", "@2", "bodystmt", "compstmt",
  "stmts", "stmt", "$@3", "command_asgn", "command_rhs", "expr",
  "expr_value", "command_call", "block_command", "cmd_brace_block", "$@4",
  "command", "mlhs", "mlhs_inner", "mlhs_basic", "mlhs_item", "mlhs_list",
  "mlhs_post", "mlhs_node", "lhs", "cname", "cpath", "fname", "fsym",
  "undef_list", "$@5", "op", "reswords", "arg", "aref_args", "arg_rhs",
  "paren_args", "opt_paren_args", "opt_call_args", "call_args",
  "command_args", "@6", "block_arg", "opt_block_arg", "comma", "args",
  "mrhs", "primary", "@7", "@8", "$@9", "$@10", "@11", "@12", "$@13",
  "$@14", "$@15", "$@16", "$@17", "$@18", "@19", "@20", "@21", "@22",
  "@23", "@24", "@25", "@26", "primary_value", "then", "do", "if_tail",
  "opt_else", "for_var", "f_margs", "$@27", "block_args_tail",
  "opt_block_args_tail", "block_param", "opt_block_param",
  "block_param_def", "opt_bv_decl", "bv_decls", "bvar", "f_larglist",
  "lambda_body", "do_block", "$@28", "block_call", "method_call",
  "brace_block", "@29", "@30", "case_body", "cases", "opt_rescue",
  "exc_list", "exc_var", "opt_ensure", "literal", "string", "string_rep",
  "string_interp", "@31", "xstring", "regexp", "heredoc", "heredoc_bodies",
  "heredoc_body", "heredoc_string_rep", "heredoc_string_interp", "@32",
  "words", "symbol", "basic_symbol", "sym", "symbols", "numeric",
  "variable", "var_lhs", "var_ref", "backref", "superclass", "$@33",
  "f_arglist", "f_label", "f_kw", "f_block_kw", "f_block_kwarg", "f_kwarg",
  "kwrest_mark", "f_kwrest", "args_tail", "opt_args_tail", "f_args",
  "f_bad_arg", "f_norm_arg", "f_arg_item", "@34", "f_arg", "f_opt_asgn",
  "f_opt", "f_block_opt", "f_block_optarg", "f_optarg", "restarg_mark",
  "f_rest_arg", "blkarg_mark", "f_block_arg", "opt_f_block_arg",
  "singleton", "$@35", "assoc_list", "assocs", "assoc", "operation",
  "operation2", "operation3", "dot_or_colon", "call_op", "call_op2",
  "opt_terms", "opt_nl", "rparen", "rbracket", "trailer", "term", "nl",
  "terms", "none", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,    61,    63,
      58,    62,    60,   124,    94,    38,    43,    45,    42,    47,
      37,   373,    33,   126,   374,   123,   125,    91,    44,    96,
      40,    41,    93,    59,    46,    10
};
# endif

#define YYPACT_NINF -818

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-818)))

#define YYTABLE_NINF -585

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-585)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -818,   108,  2800,  -818,  7504,  9459,  9792,  5607,  -818,  9114,
    9114,  -818,  -818,  9570,  7008,  5348,  7964,  7964,  -818,  -818,
    7964,  3144,  6366,  -818,  -818,  -818,  -818,    49,  7008,  -818,
     -40,  -818,  -818,  -818,  5745,  5860,  -818,  -818,  5975,  -818,
    -818,  -818,  -818,  -818,  -818,  -818,  9229,  9229,    56,  4625,
     326,  8194,  8424,  7282,  -818,  6734,  1058,   772,   968,  1146,
     520,  -818,   230,  9344,  9229,  -818,   699,  -818,  1125,  -818,
     105,  -818,  -818,   153,    75,  -818,   137,  9681,  -818,    77,
   11549,   284,   359,   240,    35,  -818,  -818,  -818,  -818,  -818,
    -818,  -818,  -818,  -818,  -818,   382,   201,  -818,   451,    34,
    -818,  -818,  -818,  -818,  -818,   185,   185,   187,   104,   744,
    9114,   544,  4741,   519,  -818,   219,  -818,   648,  -818,  -818,
      34,  -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,
    -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,
    -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,    52,
     172,   178,   207,  -818,  -818,  -818,  -818,  -818,  -818,   241,
     250,   261,   267,  -818,   285,  -818,  -818,  -818,  -818,  -818,
    -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,
    -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,
    -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,
     349,  3821,   341,   105,    72,   302,   684,    41,   342,   242,
      72,  9114,  9114,   383,  -818,  -818,   703,   416,    87,    90,
    -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,  6871,
    -818,  -818,   321,  -818,  -818,  -818,  -818,  -818,  -818,   699,
    -818,   571,  -818,   459,  -818,  -818,   699,  2994,  9229,  9229,
    9229,  9229,  -818, 11528,  -818,  -818,   343,   437,   354,  -818,
    -818,  -818,  7964,  -818,  -818,  -818,  7964,  -818,  -818,  -818,
    5464,  9114,  -818,  -818,   381,  4857,  -818,   826,   458,   469,
    7734,  4625,   391,   699,  1125,   390,   438,  -818,  7734,   390,
     420,   198,   269,  -818, 11528,   439,   269,  -818,   525,  9903,
     454,   834,   866,   886,  1216,  -818,  -818,  -818,  -818,  1164,
    -818,  -818,  -818,  -818,  -818,  -818,   616,  1076,  -818,  -818,
    1236,  -818,  1240,  -818,  1256,  -818,   895,   531,   574,  -818,
    -818,  -818,  -818,  5116,  9114,  9114,  9114,  9114,  7734,  9114,
    9114,  -818,  -818,  8539,  -818,  4625,  7393,   509,  8539,  9229,
    9229,  9229,  9229,  9229,  9229,  9229,  9229,  9229,  9229,  9229,
    9229,  9229,  9229,  9229,  9229,  9229,  9229,  9229,  9229,  9229,
    9229,  9229,  9229,  9229,  9229,  2341,  -818,  7964,  -818,  3674,
    -818,  -818, 11267,  -818,  -818,  -818,  9344,  9344,  -818,   554,
    -818,   105,  -818,   898,  -818,  -818,  -818,  -818,  -818, 10188,
    7964, 10271,  3821,  9114,  -818,  -818,  -818,  -818,   638,   653,
     280,  -818,  3964,   659,  9229, 10354,  7964, 10437,  9229,  9229,
    4250,   528,   528,    98, 10520,  7964, 10603,  -818,   613,  -818,
    4857,   459,  -818,  -818,  8654,   667,  -818,  9229, 11549, 11549,
   11549,  9229,   616,  -818,  8079,  -818,  9229,  7849,  -818,   591,
     390,  -818,   561,   566,  -818,  -818,   140,   568,  -818,  -818,
    7008,  4366,   579, 10354, 10437,  9229,  1125,   390,  -818,  -818,
    5232,   572,  1125,  -818,  -818,  8309,  -818,  -818,  -818,  -818,
    -818,  -818,   898,   137,  9903,  -818,  9903, 10686,  7964, 10769,
      68,  -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,
    -818,  -818,  1732,  -818,  9229,  -818,   585,   682,   596,  -818,
    -818,  -818,  -818,  -818,   599,  9229,  -818,   601,   692,   606,
     694,  -818,  -818,  1263,  4857,   616,  -818,  -818,  -818,  -818,
    -818,  -818,  -818,  9229,  9229,  -818,  -818,  -818,  -818,  -818,
    -818,  -818,  -818,    38,  9229,  -818, 11356,   343,  -818,   390,
    9903,   617,  -818,  -818,  -818,   707,   644,  1885,  -818,  -818,
     953,   340,   458, 10208, 10208, 10208, 10208,  1166,  1166, 10291,
    2600, 10208, 10208,  2439,  2439,   781,   781, 11296,  1166,  1166,
     739,   739,   986,    84,    84,   458,   458,   458,  3277,  6481,
    1322,  6596,  -818,   185,  -818,   390,   560,  -818,   622,  -818,
    -818,  6366,  -818,  -818,  3676,    38,    38,  -818, 10123,  -818,
    -818,  -818,  -818,  -818,   699,  9114,  3821,   794,   795,  -818,
     185,   390,   185,   753,   140,  1664,  7145,  -818,  8769,   751,
    -818,   614,  -818,  6090,  6228,   390,   366,   401,   751,  -818,
    -818,  -818,  -818,    95,   109,   390,   112,   114,  9114,  7008,
     641,   763, 11549,    60,  -818, 11549, 11549,   616,  9229, 11528,
    -818,   354, 11549,  -818,  -818,   963,  8079,  7619,  -818,  -818,
    -818,   657,  -818,  -818,    73,  1125,   390,   269,   509,  -818,
     113,   795,   390,   127,   611,  -818,  -818,  1327,   390,    55,
   11549,   411,  -818,  -818,  -818,   101,  -818,  1732,  -818, 11549,
    1732,  -818,  -818,  1336,  -818,  -818,  -818,   660,  -818,   458,
     458,  -818,  1452,  3821,  -818,  -818, 11374,  8884,  -818,  -818,
    9903,  7734,  9344,  9229, 10852,  7964, 10935,    65,  9344,  9344,
    -818,   554,   642,   635,  9344,  9344,  -818,   554,    35,   153,
    3821,  4857,    38,  -818,   699,   765,  -818,  -818,  -818,  1732,
    3821,   699,  -818, 11356,  -818,   698,  -818,  4509,   783,  -818,
    9114,   784,  -818,  9229,  9229,   427,  9229,  9229,   792,  5000,
    5000,   146,   528,  -818,  -818,  -818,  8999,  4107, 11549,  -818,
     670,  -818,  -818,  -818,   649,  -818,   257,   390,   671,   676,
     655,  3821,  4857,  -818,   762,  -818,   596,  -818,  -818,  -818,
     710,   715,   718,  -818,   720,   762,   718,  -818,  -818,   390,
     722, 10014,  -818,   721,   596,   723, 10014,  -818,   735,   736,
    -818,   807,  9229, 11442,  -818,  -818, 11549,  3410,  3543,   390,
     435,   456,  9229,  9229,  -818,  -818,  -818,  -818,  -818,  -818,
    9344,  -818,  -818,  -818,  -818,  -818,  -818,  -818,   860,   705,
    4857,  3821,  -818,  -818,   390,   861,  -818,  1664, 10125,    72,
    -818,  -818,  5000,  -818,  -818,    72,  -818,  9229,  -818,   863,
     872,  -818, 11549,   182,  7619,  -818,   752,  -818,  1439,  -818,
    1169,   874,   755,  -818,  1732,  -818,  1336,  -818,  1336,  -818,
    1336,  -818,  -818,   771,  -818,   844,   999,   411,  -818,  -818,
    1732,  -818,   999,  1732,  -818,  1336,  -818,  -818, 11460,   501,
   11549, 11549,  -818,  -818,  -818,  -818,   759,   885,  -818,  -818,
    3821,   850,  -818,  1019,   866,   886,  3821,  -818,  3964,  -818,
    -818,  5000,  -818,  -818,  -818,  1362,  1362,   665,  -818,   448,
    -818,  -818,  -818,  -818,   718,   778,   718,   718,  -818,  -818,
   11018,  -818,   596,  -818,   780,   785,   789,  -818,   799,   789,
    -818,  -818,   906,   898, 11101,  7964, 11184,   653,   614,   915,
     802,   802,  1362,   804,  1169,  -818,  -818,  1336,  -818,  -818,
    -818,   793,   806,  -818,  1732,  -818,  1336,  -818,  1336,  -818,
    1336,  -818,  -818,  -818,   794,   795,   390,   188,   418,  -818,
    -818,  -818,  1362,   802,  1362,  -818,   718,   789,   810,   789,
     789,   132,   802,  -818,  -818,  1336,  -818,  -818,  -818,   789,
    -818
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       2,     0,     0,     1,     0,     0,     0,     0,   273,     0,
       0,   297,   300,     0,     0,   569,   321,   322,   323,   324,
     285,   251,   396,   468,   467,   469,   470,   571,     0,    10,
       0,   472,   471,   473,   460,   272,   462,   461,   464,   463,
     456,   457,   418,   419,   474,   475,     0,     0,     0,     0,
     275,   584,   584,    80,   292,     0,     0,     0,     0,     0,
       0,   433,     0,     0,     0,     3,   569,     6,     9,    27,
      32,    44,    52,    51,     0,    68,     0,    72,    82,     0,
      49,   231,     0,    53,   290,   265,   266,   267,   268,   269,
     416,   415,   445,   417,   414,   466,     0,   270,   271,   251,
       5,     8,   321,   322,   285,   584,   396,     0,   104,   105,
       0,     0,     0,     0,   107,   476,   325,     0,   466,   271,
       0,   313,   159,   169,   160,   156,   185,   186,   187,   188,
     167,   182,   175,   165,   164,   180,   163,   162,   158,   183,
     157,   170,   174,   176,   168,   161,   177,   184,   179,   178,
     171,   181,   166,   155,   173,   172,   154,   152,   153,   149,
     150,   151,   109,   111,   110,   144,   145,   140,   122,   123,
     124,   131,   128,   130,   125,   126,   146,   147,   132,   133,
     137,   141,   127,   129,   119,   120,   121,   134,   135,   136,
     138,   139,   142,   143,   148,   543,   315,   112,   113,   542,
       0,     0,     0,    50,     0,     0,     0,   466,     0,   271,
       0,     0,     0,     0,   336,   335,     0,     0,   466,   271,
     178,   171,   181,   166,   149,   150,   151,   109,   110,     0,
     114,   116,    20,   115,   436,   441,   440,   578,   581,   569,
     580,     0,   438,     0,   582,   579,   570,   553,     0,     0,
       0,     0,   246,   258,    66,   250,   584,   266,   584,   547,
      67,    65,   584,   240,   286,    64,     0,   239,   395,    63,
     571,     0,   572,    18,     0,     0,   208,     0,   209,   282,
       0,     0,     0,   569,    15,   571,    70,    14,     0,   571,
       0,   575,   575,   232,     0,     0,   575,   545,     0,     0,
      78,     0,    88,    95,   514,   450,   449,   451,   452,     0,
     448,   447,   431,   425,   424,   427,     0,     0,   422,   443,
       0,   454,     0,   420,     0,   429,     0,   458,   459,    48,
     223,   224,     4,   570,     0,     0,     0,     0,     0,     0,
       0,   383,   385,     0,    84,     0,    76,    73,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   566,   584,   565,     0,
     568,   567,     0,   400,   398,   291,     0,     0,   389,    57,
     289,   310,   104,   105,   106,   458,   459,   477,   308,     0,
     584,     0,     0,     0,   316,   564,   563,   318,     0,   584,
     282,   327,     0,   326,     0,     0,   584,     0,     0,     0,
       0,     0,     0,   282,     0,   584,     0,   305,     0,   117,
       0,     0,   437,   439,     0,     0,   583,     0,   259,   552,
     253,     0,   256,   247,     0,   255,     0,   256,   248,     0,
     571,   242,   584,   584,   241,   252,   571,     0,   288,    47,
       0,     0,     0,     0,     0,     0,    17,   571,   280,    13,
     570,    69,   276,   279,   283,   577,   233,   576,   577,   235,
     284,   546,    94,    86,     0,    81,     0,     0,   584,     0,
     520,   517,   516,   515,   518,   490,   522,   534,   491,   538,
     537,   533,   514,   293,   483,   488,   584,   493,   584,   513,
     380,   519,   521,   524,   499,     0,   531,   499,   536,   499,
       0,   497,   453,     0,     0,   428,   434,   432,   423,   444,
     455,   421,   430,     0,     0,     7,    21,    22,    23,    24,
      25,    45,    46,   584,     0,    28,    30,     0,    31,   571,
       0,    74,    85,    43,    33,    41,     0,   236,   189,    29,
       0,   271,   205,   213,   218,   219,   220,   215,   217,   227,
     228,   221,   222,   198,   199,   225,   226,   571,   214,   216,
     210,   211,   212,   200,   201,   202,   203,   204,   556,   561,
     557,   562,   394,   251,   392,   571,   556,   558,   557,   559,
     393,   584,   556,   557,   251,   584,   584,    34,   236,   190,
      40,   197,    55,    58,     0,     0,     0,   104,   105,   108,
       0,   571,   584,     0,   571,   514,     0,   274,   584,   584,
     406,   584,   328,   560,   281,   571,   556,   557,   584,   330,
     298,   329,   301,   560,   281,   571,   556,   557,     0,     0,
       0,     0,   258,     0,   304,   550,   549,   257,     0,   260,
     254,   584,   551,   548,   238,   256,     0,   245,   287,   573,
      19,     0,    26,   196,    71,    16,   571,   575,    87,    79,
     560,    93,   571,   556,   557,   481,   526,     0,   571,     0,
     482,     0,   495,   541,   492,     0,   496,     0,   506,   527,
       0,   509,   535,     0,   511,   539,   446,     0,   435,   206,
     207,   371,   571,     0,   369,   368,   264,     0,    83,    77,
       0,     0,     0,     0,     0,   584,     0,     0,     0,     0,
     391,    61,     0,   397,     0,     0,   390,    59,   386,    54,
       0,     0,   584,   311,     0,     0,   397,   314,   544,   514,
       0,     0,   319,   407,   408,   584,   409,     0,   584,   333,
       0,     0,   331,     0,     0,   397,     0,     0,     0,     0,
       0,   397,     0,   118,   442,   303,     0,     0,   261,   249,
     584,    11,   277,   234,   397,   520,   344,   571,   337,     0,
     373,     0,     0,   294,     0,   489,   584,   540,   498,   525,
     499,   499,   499,   532,   499,   520,   499,   426,   367,   571,
       0,   485,   486,   584,   584,   352,     0,   529,   352,   352,
     350,     0,     0,   262,    75,    42,   237,   556,   557,   571,
     556,   557,     0,     0,    39,   194,    38,   195,    62,   574,
       0,    36,   192,    37,   193,    60,   387,   388,     0,     0,
       0,     0,   478,   309,   571,     0,   480,   514,     0,     0,
     411,   334,     0,    12,   413,     0,   295,     0,   296,     0,
       0,   306,   260,   584,   244,   345,   342,   523,     0,   379,
       0,     0,     0,   494,     0,   502,     0,   504,     0,   510,
       0,   507,   512,     0,   370,     0,   484,     0,   348,   349,
     358,   360,   528,     0,   363,     0,   365,   384,   263,   397,
     230,   229,    35,   191,   401,   399,     0,     0,   479,   317,
       0,     0,   410,     0,    96,   103,     0,   412,     0,   299,
     302,     0,   403,   404,   402,     0,     0,   340,   377,   571,
     375,   378,   382,   381,   499,   499,   499,   499,   372,   282,
       0,   487,   584,   351,   352,   352,   352,   530,   352,   352,
      56,   312,     0,   102,     0,   584,     0,   584,   584,     0,
     346,   343,     0,   338,     0,   374,   503,     0,   500,   505,
     508,   560,   281,   347,     0,   355,     0,   357,     0,   364,
       0,   361,   366,   320,    99,   101,   571,   556,   557,   405,
     332,   307,     0,   341,     0,   376,   499,   352,   352,   352,
     352,    97,   339,   501,   356,     0,   353,   359,   362,   352,
     354
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -818,  -818,  -818,   483,  -818,     2,  -818,  -212,   -11,  -818,
      79,  -818,  -168,  -258,   840,    11,   -34,  -818,  -621,  -818,
      -3,   939,  -189,    -8,   -53,  -254,  -443,   -28,  2022,   -92,
     947,    -2,   -20,  -818,  -818,     9,  -818,  1266,  -818,   484,
      48,  -477,  -367,    57,   110,  -818,  -364,  -216,  -178,    14,
    -309,    22,  -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,
    -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,
    -818,  -818,   277,  -203,  -390,   -13,  -575,  -818,  -818,  -818,
     245,   175,  -818,  -500,  -818,  -646,  -818,    -9,  -818,  -818,
     222,  -818,  -818,  -818,   -73,  -818,  -818,  -427,  -818,    10,
    -818,  -818,  -818,  -818,    39,    91,  -160,  -818,  -818,  -818,
    -818,   664,  -301,  -818,   742,  -818,  -818,  -818,     8,  -818,
    -818,  -818,  1838,  2249,   977,  1469,  -818,  -818,   135,    76,
     304,    99,  -818,  -818,  -818,   -43,  -286,  -423,  -292,  -801,
    -729,  -498,  -818,   371,  -660,  -654,  -817,   107,   316,  -818,
    -294,  -818,     1,  -421,  -818,  -818,  -818,    51,  -438,   814,
    -282,  -818,  -818,   -80,  -818,    23,   -27,  -106,  -573,  -252,
      32,   305,    16,    -1
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    65,    66,    67,   274,   408,   409,   283,
     284,   460,    69,   554,    70,   204,    71,    72,   613,   742,
      73,    74,   285,    75,    76,    77,   485,    78,   205,   114,
     115,   230,   231,   232,   649,   591,   198,    80,   290,   558,
     592,   264,   450,   451,   265,   266,   255,   443,   449,   452,
     548,    81,   201,   288,   676,   289,   304,   689,   211,   769,
     212,   770,   648,   931,   616,   614,   851,   402,   404,   625,
     626,   857,   277,   412,   640,   761,   762,   217,   787,   935,
     953,   901,   809,   713,   714,   789,   939,   940,   503,   793,
     342,   543,    83,    84,   390,   606,   605,   435,   934,   629,
     755,   859,   863,    85,    86,   317,   318,   524,    87,    88,
      89,   657,   240,   241,   242,   430,    90,    91,    92,   311,
      93,    94,   207,   208,    97,   209,   398,   615,   750,   504,
     505,   812,   813,   506,   507,   508,   798,   698,   751,   511,
     512,   513,   687,   514,   515,   516,   817,   818,   517,   518,
     519,   520,   521,   692,   200,   403,   295,   453,   259,   120,
     620,   594,   407,   401,   382,   243,   457,   458,   733,   476,
     413,   272,   246,   287
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     271,   100,   379,   381,   651,   196,   101,   420,   273,   663,
     595,   385,   510,   252,   252,   526,   197,   252,   509,   394,
     267,   210,   233,   197,   347,   300,   239,   116,   116,   329,
     256,   256,   642,   621,   256,   116,   233,   197,   282,   559,
     479,   286,   448,   679,   481,   484,   803,   244,   746,   635,
     293,   297,   816,   310,   758,   257,   257,   876,   645,   257,
     383,   383,   765,   768,   197,   291,   810,   258,   258,   263,
     268,   258,   771,   254,   260,   116,   411,   261,   444,   941,
     660,    68,   333,    68,   791,   660,   957,   696,   411,   332,
     257,   257,   467,   593,   701,   275,   704,   601,   244,   116,
     604,   282,   292,   296,   267,   740,   741,   719,     3,   784,
     838,   279,   -96,   475,   478,  -103,   845,   711,   478,   622,
     -99,   682,   832,  -102,   736,   685,   417,   738,   607,   610,
    -553,  -465,   269,   593,  -101,   601,   426,   -98,   -91,  -100,
    -468,   526,   339,   340,   622,   736,   526,   388,   320,   322,
     324,   326,   -90,   263,   268,   349,   549,   528,  -397,   -96,
     528,   712,   528,   893,   528,   792,   528,   957,   388,   384,
     384,   -97,   234,   941,   262,   235,   236,   339,   340,   471,
     553,   341,   622,   473,   234,   833,   686,   235,   236,   270,
     623,   -69,  -460,   343,   238,   348,  -468,   464,   442,   799,
     757,   499,   434,   237,   -98,   238,  -460,   622,   973,   389,
     688,   -83,   372,   373,   374,   237,   509,   238,   553,   553,
    -397,   489,   421,   422,   708,   -88,   500,   310,   -95,   663,
     803,   -91,   484,   -91,  -397,  -556,   -94,   448,   197,  -553,
     816,  -460,   850,   816,  -553,   -90,   483,   -93,  -460,  -557,
     -90,   -91,   -92,  -556,   -91,   445,   909,   445,   -91,   252,
    -467,   454,   431,   252,   462,   -90,  -469,  -397,   -90,  -397,
     282,   244,   -90,   286,   666,   344,  -397,   824,   436,    82,
     256,    82,   117,   117,   -89,   238,   206,   206,   327,   328,
     216,   386,   206,   206,   206,  -470,   484,   206,   932,   470,
     -98,   257,   660,   -98,   -98,   257,   469,   619,   785,   545,
     491,   492,   493,   494,   555,   244,  -467,   258,   551,   754,
     245,   116,  -469,   455,   816,   262,    82,   270,   380,  -472,
     301,   -98,   419,   -98,   282,   535,   442,   286,  -471,   509,
     206,   397,   376,   238,   664,   536,   537,   538,   539,  -473,
     668,  -470,   555,   555,   301,  -460,   708,   547,   829,   466,
    -103,   674,   547,   528,   526,   436,   526,   472,   116,   717,
     465,   245,  -325,  -464,   252,   883,   454,   885,   887,   889,
     799,   891,   871,   892,   378,  -472,  -325,   206,   599,    82,
     799,   599,   898,   899,  -471,   875,   410,   252,  -102,   454,
     523,   631,   799,   801,   745,  -473,   804,   447,   630,   638,
     599,  -460,    68,   252,   238,   454,   257,   540,   819,   650,
     414,  -325,   252,  1011,   454,   783,   599,   600,  -325,  -464,
     387,   678,   418,   483,  -100,   599,   663,   405,   423,   257,
     670,   427,   593,   718,   601,   779,   933,   375,   653,   600,
     777,   445,   445,   641,   641,   257,   766,   854,  -103,   429,
     100,   376,   794,   509,   257,   600,   484,  -278,   233,   197,
     834,  -278,  -465,   599,   600,   776,   841,   843,    82,   434,
     726,   442,   495,   257,   -98,   252,   257,   454,   206,   206,
     799,   767,   447,   406,   446,   661,   377,   483,   599,   478,
     -96,   821,   436,   378,   799,   693,   116,   693,   116,   245,
     498,   499,   600,   707,   257,   245,   461,   867,   748,  -100,
     -88,   976,   978,   979,   980,   734,   677,   257,   848,   349,
    -100,   983,   468,  -100,  -100,   238,   500,   600,   855,   206,
      68,   387,   715,   206,   245,   -97,   735,   206,   206,   675,
     727,   245,    82,   -98,   553,   639,   -68,    82,    82,   465,
     553,  -100,   474,  -100,   779,    82,   553,   553,   732,  -103,
     782,   509,   116,   526,  -100,   480,   301,   395,   396,   881,
     482,   325,   912,  1013,   313,   314,   974,  -102,   245,   -95,
     945,   840,   486,   238,   732,   392,   477,   477,   996,   393,
     267,   477,   533,   267,   715,   715,   955,   -94,   732,   958,
      82,   206,   206,   206,   206,    82,   206,   206,   732,   -97,
     206,   267,    82,   301,   752,   560,   744,   756,   759,   773,
     759,   760,   757,   315,   316,   197,   -92,   759,   245,   917,
     234,   730,   547,   235,   236,   534,   743,   552,   796,   263,
     734,   612,   263,   627,   206,   732,   926,   233,   197,   772,
     445,   790,   928,   560,   560,   846,   628,   483,   730,   814,
     263,   237,   553,   238,   -89,   632,   522,   206,   -98,    82,
     206,   877,   654,   432,   622,   790,   235,   236,   555,    82,
    1008,   250,   797,   206,   555,   836,   797,    82,   -90,   665,
     555,   555,   206,   731,   667,   257,   257,    82,   962,   669,
     -83,   737,   735,   820,   739,   672,   785,   780,   491,   492,
     493,   494,   252,   691,   454,   840,   245,   245,   234,   -92,
     849,   235,   236,   694,   695,   599,   399,   697,    82,   700,
    -100,   715,   116,   702,   703,   705,   861,    82,   918,   -92,
     376,   721,   -92,   -97,   860,   720,   -92,   864,   869,   870,
     -92,   301,   722,   301,   257,   206,   873,   -89,   747,   757,
    -554,   865,   415,   -89,   600,   245,   852,   774,   775,   445,
     853,   882,   790,   856,   839,   400,   376,   -89,   811,   858,
     -89,   424,   378,   781,   -89,   693,   807,   862,   880,   866,
     825,    82,   732,   972,   641,   376,   555,   868,   874,   878,
     349,   234,   693,   693,   235,   236,    99,   879,    99,   685,
    -560,   416,   907,    99,    99,   362,   363,   301,   378,    99,
      99,    99,  -464,   116,    99,   319,   313,   314,   116,   916,
     425,   915,   237,   966,   238,   894,  -464,   378,   884,   203,
     203,   927,   349,   886,   952,   203,   888,   814,   890,   897,
     814,   900,   814,    99,   369,   370,   371,   372,   373,   374,
     609,   611,   759,   903,   905,   914,   919,    99,   929,  -554,
     116,  -464,  -560,  -281,  -554,   315,   316,   930,  -464,   942,
     936,   943,   206,    82,   948,   960,  -560,  -281,   797,   949,
     961,   820,   609,   611,   820,   963,   820,   370,   371,   372,
     373,   374,   975,   257,   463,   967,   977,   968,   984,   245,
     969,   993,   487,   986,    99,   206,    99,   988,   376,  -560,
    1001,  -560,  -281,  -556,  -556,  -557,   376,   990,  -560,  -281,
    1002,   814,  1004,   814,   671,   814,  -557,   814,  1015,   673,
     391,   693,   214,   121,  -466,  1000,   532,   808,   245,   313,
     314,   847,   252,   416,   454,  1005,   630,   759,  -466,   732,
     378,   488,   814,   811,  -271,   599,   811,   999,   378,   811,
     525,   811,   477,   433,   199,   820,  -282,   820,  -271,   820,
      82,   820,   920,   904,   906,   795,   951,   301,    82,   560,
    -282,     0,   206,  -466,   257,   560,   206,   954,   315,   316,
    -466,   560,   560,   800,   600,    99,   820,    82,    82,     0,
       0,     0,     0,  -271,     0,    99,    99,    82,     0,     0,
    -271,   321,   313,   314,    82,  -282,     0,   206,     0,     0,
       0,   724,  -282,     0,     0,     0,    82,    82,     0,   245,
       0,   203,   203,     0,    82,   376,   245,   349,   788,     0,
     811,     0,   811,     0,   811,     0,   811,     0,    82,    82,
       0,   802,   362,   363,   806,   234,    99,   245,   235,   236,
      99,   315,   316,   815,    99,    99,     0,   950,   896,    99,
     725,   811,     0,   902,    99,    99,     0,   378,     0,     0,
       0,   376,    99,     0,  -243,  -243,     0,   964,  -243,     0,
     456,   459,   370,   371,   372,   373,   374,   560,     0,     0,
     312,   376,   313,   314,     0,     0,     0,    82,    82,   985,
     987,   989,     0,   991,   992,   923,   400,     0,   527,    82,
     313,   314,     0,   378,     0,     0,     0,    99,    99,    99,
      99,    99,    99,    99,    99,     0,   965,    99,     0,    99,
       0,     0,    99,   378,   245,   334,   335,   336,   337,   338,
     245,   315,   316,     0,   203,   203,   203,   203,     0,   541,
     542,     0,  1014,  1016,  1017,  1018,     0,     0,     0,   315,
     316,    99,     0,     0,  1020,     0,     0,    82,     0,     0,
      99,    99,     0,    82,     0,    82,     0,     0,    82,   323,
     313,   314,   835,   837,    99,     0,    99,    99,   842,   844,
     938,     0,   491,   492,   493,   494,    99,   522,   313,   314,
      99,     0,     0,     0,    99,     0,     0,   349,     0,    99,
       0,     0,   206,   624,    99,     0,     0,   835,   837,     0,
     842,   844,   362,   363,     0,   944,     0,   946,     0,   315,
     316,   947,     0,     0,     0,     0,     0,   490,     0,   491,
     492,   493,   494,     0,   956,    99,   959,   315,   316,     0,
       0,     0,   253,   253,    99,     0,   253,   495,     0,   367,
     368,   369,   370,   371,   372,   373,   374,     0,     0,   529,
     313,   314,    99,   530,   313,   314,   970,   971,   496,     0,
       0,     0,   276,   278,   497,   498,   499,   253,   294,   531,
     313,   314,  -281,     0,   913,     0,   706,   313,   314,   330,
     331,     0,     0,     0,     0,  -281,  -281,  -281,    99,  -281,
    -281,   500,  -281,  1003,   501,     0,     0,     0,  1006,   315,
     316,   913,     0,   315,   316,  1007,   502,  1009,     0,  -281,
    -281,  1010,  -281,  -281,  -281,  -281,  -281,     0,     0,   315,
     316,     0,     0,     0,     0,  1012,   315,   316,   785,     0,
     491,   492,   493,   494,     0,     0,  1019,   805,     0,   491,
     492,   493,   494,  -281,  -281,  -281,  -281,  -281,  -281,  -281,
    -281,  -281,  -281,  -281,  -281,  -281,     0,   495,  -281,  -281,
    -281,     0,   729,   785,     0,   491,   492,   493,   494,   496,
       0,     0,     0,     0,  -281,   786,     0,     0,   496,    99,
      99,     0,     0,     0,  -281,   498,   499,  -281,  -281,     0,
    -101,  -281,     0,  -281,  -281,  -281,  -281,  -281,  -281,  -281,
    -281,  -281,  -281,     0,   496,   203,     0,     0,  -281,  -281,
     -93,   500,    99,  -281,     0,  -281,  -281,  -281,     0,     0,
       0,    98,     0,    98,   119,   119,     0,     0,     0,     0,
       0,     0,   219,     0,     0,     0,     0,     0,   203,     0,
     785,     0,   491,   492,   493,   494,     0,     0,     0,     0,
       0,     0,     0,   490,     0,   491,   492,   493,   494,     0,
       0,     0,     0,     0,   438,   439,   440,   330,    98,     0,
       0,     0,   303,   495,     0,     0,     0,    99,   253,     0,
       0,   496,   253,     0,     0,    99,    99,   937,     0,    99,
       0,     0,    99,    99,   496,     0,   303,     0,    99,    99,
     497,   498,   499,     0,    99,    99,     0,     0,     0,     0,
       0,     0,     0,     0,    99,     0,     0,     0,     0,     0,
       0,    99,     0,     0,    99,     0,     0,   500,     0,     0,
     501,    98,     0,    99,    99,     0,     0,     0,     0,     0,
       0,    99,     0,     0,     0,     0,     0,   238,     0,     0,
     203,     0,     0,     0,     0,    99,    99,     0,     0,   546,
       0,     0,     0,     0,   557,   562,   563,   564,   565,   566,
     567,   568,   569,   570,   571,   572,   573,   574,   575,   576,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     587,     0,     0,   253,     0,     0,     0,     0,     0,     0,
       0,     0,   608,   608,    99,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    99,    99,   253,     0,     0,     0,
      98,     0,     0,     0,     0,     0,    99,     0,     0,     0,
     608,     0,   253,     0,   608,   608,     0,     0,     0,     0,
       0,   253,     0,     0,     0,     0,     0,     0,     0,     0,
     652,     0,     0,   655,     0,     0,     0,   656,     0,     0,
     659,     0,   662,   294,     0,   490,     0,   491,   492,   493,
     494,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   608,     0,     0,    99,   495,     0,     0,     0,     0,
      99,   659,    99,     0,    98,    99,     0,     0,     0,    98,
      98,     0,     0,     0,   253,     0,   496,    98,     0,     0,
       0,     0,   497,   498,   499,     0,     0,     0,   303,     0,
     690,     0,     0,     0,     0,     0,     0,     0,     0,    99,
       0,   699,     0,   490,     0,   491,   492,   493,   494,   500,
       0,     0,   501,     0,     0,     0,     0,     0,     0,   709,
     710,     0,    98,   495,   749,     0,     0,    98,     0,     0,
     716,     0,     0,     0,    98,   303,     0,   561,     0,     0,
       0,     0,     0,     0,   496,     0,     0,     0,     0,     0,
     497,   498,   499,     0,     0,     0,     0,     0,     0,     0,
      95,     0,    95,   118,   118,   118,     0,     0,     0,     0,
       0,   218,     0,     0,     0,   561,   561,   500,     0,     0,
     501,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    98,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    98,     0,     0,     0,     0,     0,    95,     0,    98,
       0,   302,     0,     0,   753,     0,     0,     0,     0,    98,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   302,     0,     0,     0,     0,
       0,     0,     0,     0,   778,     0,     0,     0,     0,   723,
      98,     0,   659,   294,     0,     0,     0,     0,     0,    98,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      95,     0,     0,   303,     0,   303,   349,   350,   351,   352,
     353,   354,   355,   356,   357,   358,   359,   360,   361,     0,
       0,   362,   363,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   823,     0,     0,     0,     0,   608,   826,
       0,   253,     0,    98,   608,   608,     0,     0,     0,     0,
     608,   608,     0,     0,   364,     0,   365,   366,   367,   368,
     369,   370,   371,   372,   373,   374,     0,     0,     0,   303,
       0,     0,     0,  -258,    79,     0,    79,     0,     0,   608,
     608,     0,   608,   608,     0,   215,     0,     0,     0,    95,
       0,     0,   872,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    79,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    98,     0,     0,   908,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   910,   911,
       0,     0,     0,     0,     0,     0,   608,     0,     0,     0,
       0,     0,     0,    95,     0,     0,     0,     0,    95,    95,
       0,     0,     0,     0,     0,     0,    95,     0,     0,     0,
       0,     0,     0,   608,    79,     0,     0,   302,     0,     0,
     294,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    95,     0,     0,     0,     0,    95,     0,     0,     0,
       0,     0,    98,    95,   302,     0,     0,     0,     0,   303,
      98,   561,     0,     0,     0,     0,     0,   561,     0,     0,
       0,     0,     0,   561,   561,     0,     0,     0,     0,    98,
      98,     0,     0,     0,     0,     0,     0,     0,     0,    98,
       0,     0,     0,    79,     0,     0,    98,     0,     0,     0,
       0,   253,     0,     0,     0,     0,     0,     0,    98,    98,
      95,     0,     0,     0,     0,     0,    98,     0,     0,     0,
      95,    96,     0,    96,     0,     0,     0,     0,    95,     0,
      98,    98,     0,     0,     0,     0,     0,     0,    95,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     119,     0,     0,     0,     0,   119,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    79,    96,    95,
       0,     0,    79,    79,     0,     0,     0,     0,    95,   561,
      79,     0,     0,     0,     0,     0,     0,     0,     0,    98,
      98,     0,   302,     0,   302,     0,     0,   925,     0,     0,
       0,    98,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    79,     0,     0,     0,     0,
      79,    96,    95,     0,     0,     0,     0,    79,     0,     0,
     556,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   302,    98,
       0,     0,   588,   589,     0,    98,   590,    98,     0,     0,
      98,     0,     0,     0,     0,     0,     0,     0,   556,   556,
     165,   166,   167,   168,   169,   170,   171,   172,   173,     0,
       0,   174,   175,     0,    79,   176,   177,   178,   179,     0,
       0,     0,     0,     0,    79,     0,     0,     0,     0,   180,
     181,     0,    79,     0,     0,     0,     0,     0,     0,     0,
      96,     0,    79,     0,    95,     0,     0,     0,     0,     0,
       0,     0,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,     0,   192,   193,     0,     0,     0,     0,     0,
     194,   262,     0,    79,     0,     0,     0,     0,     0,     0,
       0,     0,    79,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     349,   350,   351,   352,   353,   354,   355,   356,   357,   358,
     359,  -585,  -585,     0,    96,   362,   363,     0,     0,    96,
      96,     0,     0,     0,     0,     0,     0,    96,     0,     0,
       0,     0,     0,     0,     0,     0,    79,     0,     0,     0,
       0,    95,     0,     0,     0,     0,     0,     0,   302,    95,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
       0,     0,     0,     0,     0,     0,     0,     0,    95,    95,
       0,     0,    96,     0,     0,     0,     0,    96,    95,     0,
       0,     0,     0,     0,    96,    95,     0,    96,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    95,    95,     0,
       0,     0,     0,     0,     0,    95,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    95,
      95,     0,     0,     0,     0,    96,    96,     0,    79,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   118,
       0,    96,     0,     0,   118,     0,     0,     0,     0,     0,
       0,    96,     0,     0,     0,     0,     0,     0,     0,    96,
       0,   349,   350,   351,   352,   353,   354,   355,   356,    96,
     358,   359,     0,     0,     0,     0,   362,   363,    95,    95,
       0,     0,     0,     0,     0,     0,   924,     0,     0,     0,
      95,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      96,     0,     0,     0,     0,     0,     0,     0,     0,    96,
       0,   365,   366,   367,   368,   369,   370,   371,   372,   373,
     374,     0,     0,     0,     0,    79,     0,     0,     0,     0,
       0,     0,     0,    79,   556,     0,     0,     0,     0,     0,
     556,     0,     0,     0,     0,     0,   556,   556,    95,     0,
       0,     0,    79,    79,    95,     0,    95,     0,     0,    95,
       0,     0,    79,    96,     0,     0,     0,     0,     0,    79,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    79,    79,     0,     0,     0,     0,     0,     0,    79,
    -584,     4,     0,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    79,    79,     0,     0,     0,     0,    15,
       0,    16,    17,    18,    19,     0,     0,     0,     0,     0,
      20,    21,    22,    23,    24,    25,    26,     0,     0,    27,
       0,     0,     0,     0,     0,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,     0,    40,    41,
      42,     0,   556,    43,     0,    96,    44,    45,     0,    46,
      47,     0,    79,    79,     0,     0,     0,     0,     0,     0,
     922,     0,     0,     0,    79,     0,     0,     0,     0,    48,
       0,     0,    49,    50,     0,    51,    52,     0,    53,     0,
       0,    54,     0,    55,    56,    57,    58,    59,    60,     0,
       0,    61,  -584,     0,     0,  -584,  -584,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    62,    63,    64,     0,     0,     0,     0,     0,     0,
       0,     0,    79,  -584,     0,  -584,     0,     0,    79,     0,
      79,     0,     0,    79,     0,     0,     0,     0,     0,     0,
       0,     0,    96,     0,     0,     0,     0,     0,     0,     0,
      96,    96,     0,     0,     0,     0,     0,    96,     0,     0,
       0,     0,     0,    96,    96,     0,     0,     0,     0,    96,
      96,     0,     0,     0,  -460,     0,     0,     0,     0,    96,
       0,     0,     0,     0,     0,     0,    96,  -460,  -460,  -460,
    -460,  -460,  -460,     0,  -460,     0,     0,     0,    96,    96,
       0,  -460,  -460,     0,     0,     0,    96,     0,     0,     0,
       0,  -460,  -460,     0,  -460,  -460,  -460,  -460,  -460,     0,
      96,    96,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   437,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  -460,  -460,  -460,  -460,  -460,
    -460,  -460,  -460,  -460,  -460,  -460,  -460,  -460,     0,     0,
    -460,  -460,  -460,     0,  -460,  -460,     0,     0,     0,    96,
       0,  -460,     0,     0,     0,     0,  -460,     0,     0,    96,
      96,     0,     0,     0,     0,     0,  -460,     0,     0,  -460,
    -460,    96,  -460,  -460,     0,  -460,  -460,  -460,  -460,  -460,
    -460,  -460,  -460,  -460,  -460,     0,     0,     0,     0,     0,
    -460,  -460,  -460,     0,     0,  -460,  -460,  -460,  -460,  -460,
       0,     0,     0,     0,  -584,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  -584,  -584,  -584,
    -584,  -584,  -584,     0,  -584,     0,     0,     0,     0,    96,
       0,  -584,  -584,     0,     0,    96,     0,    96,     0,     0,
      96,  -584,  -584,     0,  -584,  -584,  -584,  -584,  -584,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  -584,  -584,  -584,  -584,  -584,
    -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,     0,     0,
    -584,  -584,  -584,     0,     0,  -584,     0,     0,     0,     0,
       0,  -584,     0,     0,     0,     0,  -584,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  -584,     0,     0,  -584,
    -584,     0,     0,  -584,     0,  -584,  -584,  -584,  -584,  -584,
    -584,  -584,  -584,  -584,  -584,     0,     0,  -560,     0,     0,
    -584,  -584,  -584,     0,   262,  -584,  -584,  -584,  -584,  -584,
    -560,  -560,  -560,     0,  -560,  -560,     0,  -560,     0,     0,
       0,     0,     0,  -560,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  -560,  -560,     0,  -560,  -560,  -560,
    -560,  -560,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  -560,  -560,
    -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,
    -560,     0,     0,  -560,  -560,  -560,     0,   728,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  -560,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  -560,
       0,     0,  -560,  -560,     0,   -99,  -560,     0,  -560,  -560,
    -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,     0,     0,
    -560,     0,  -560,  -560,  -560,   -91,     0,     0,  -560,     0,
    -560,  -560,  -560,  -560,  -560,  -560,     0,  -560,  -560,     0,
    -560,     0,     0,     0,     0,     0,  -560,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  -560,  -560,     0,
    -560,  -560,  -560,  -560,  -560,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,
    -560,  -560,  -560,  -560,     0,     0,  -560,  -560,  -560,     0,
     728,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  -560,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  -560,     0,     0,  -560,  -560,     0,   -99,  -560,
       0,  -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,
    -560,     0,     0,  -281,     0,  -560,  -560,  -560,  -560,     0,
       0,  -560,     0,  -560,  -560,  -560,  -281,  -281,  -281,     0,
    -281,  -281,     0,  -281,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    -281,  -281,     0,  -281,  -281,  -281,  -281,  -281,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  -281,  -281,  -281,  -281,  -281,  -281,
    -281,  -281,  -281,  -281,  -281,  -281,  -281,     0,     0,  -281,
    -281,  -281,     0,   729,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  -281,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  -281,     0,     0,  -281,  -281,
       0,  -101,  -281,     0,  -281,  -281,  -281,  -281,  -281,  -281,
    -281,  -281,  -281,  -281,     0,     0,  -584,     0,     0,  -281,
    -281,  -281,     0,     0,  -281,     0,  -281,  -281,  -281,  -584,
    -584,  -584,  -584,  -584,  -584,     0,  -584,     0,     0,     0,
       0,     0,  -584,  -584,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  -584,  -584,     0,  -584,  -584,  -584,  -584,
    -584,     0,     0,     0,     0,   596,   597,     0,     0,   598,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   165,   166,   167,   168,   169,   170,   171,
     172,   173,     0,     0,   174,   175,     0,     0,   176,   177,
     178,   179,     0,     0,  -584,     0,     0,     0,     0,     0,
       0,     0,   180,   181,     0,     0,     0,     0,  -584,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  -584,     0,
       0,  -584,  -584,     0,     0,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,     0,   192,   193,     0,     0,
       0,  -584,  -584,   194,   262,     0,   262,  -584,     0,  -584,
    -584,  -584,   280,     0,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,  -584,  -584,  -584,     0,     0,  -584,
      15,     0,    16,    17,    18,    19,     0,     0,     0,     0,
       0,    20,    21,    22,    23,    24,    25,    26,     0,     0,
      27,     0,     0,     0,     0,     0,    28,     0,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,     0,    40,
      41,    42,     0,     0,    43,     0,     0,    44,    45,     0,
      46,    47,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      48,     0,     0,    49,    50,     0,    51,    52,     0,    53,
       0,     0,    54,     0,    55,    56,    57,    58,    59,    60,
       0,     0,    61,  -584,     0,     0,  -584,  -584,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    62,    63,    64,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  -584,   280,  -584,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,     0,     0,  -584,
       0,  -584,  -584,    15,     0,    16,    17,    18,    19,     0,
       0,     0,     0,     0,    20,    21,    22,    23,    24,    25,
      26,     0,     0,    27,     0,     0,     0,     0,     0,    28,
       0,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,     0,    40,    41,    42,     0,     0,    43,     0,     0,
      44,    45,     0,    46,    47,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    48,     0,     0,    49,    50,     0,    51,
      52,     0,    53,     0,     0,    54,     0,    55,    56,    57,
      58,    59,    60,     0,     0,    61,  -584,     0,     0,  -584,
    -584,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    62,    63,    64,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  -584,   280,  -584,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
       0,     0,  -584,     0,     0,  -584,    15,  -584,    16,    17,
      18,    19,     0,     0,     0,     0,     0,    20,    21,    22,
      23,    24,    25,    26,     0,     0,    27,     0,     0,     0,
       0,     0,    28,     0,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,     0,    40,    41,    42,     0,     0,
      43,     0,     0,    44,    45,     0,    46,    47,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    48,     0,     0,    49,
      50,     0,    51,    52,     0,    53,     0,     0,    54,     0,
      55,    56,    57,    58,    59,    60,     0,     0,    61,  -584,
       0,     0,  -584,  -584,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    62,    63,
      64,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    -584,   280,  -584,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,     0,     0,  -584,     0,     0,  -584,    15,
       0,    16,    17,    18,    19,     0,     0,     0,     0,     0,
      20,    21,    22,    23,    24,    25,    26,     0,     0,    27,
       0,     0,     0,     0,     0,    28,     0,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,     0,    40,    41,
      42,     0,     0,    43,     0,     0,    44,    45,     0,    46,
      47,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    48,
       0,     0,    49,    50,     0,    51,    52,     0,    53,     0,
       0,    54,     0,    55,    56,    57,    58,    59,    60,     0,
       0,    61,  -584,     0,     0,  -584,  -584,     4,     0,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,     0,
       0,    62,    63,    64,     0,    15,     0,    16,    17,    18,
      19,     0,     0,  -584,     0,  -584,    20,    21,    22,    23,
      24,    25,    26,     0,     0,    27,     0,     0,     0,     0,
       0,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,     0,    40,    41,    42,     0,     0,    43,
       0,     0,    44,    45,     0,    46,    47,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    48,     0,     0,    49,    50,
       0,    51,    52,     0,    53,     0,     0,    54,     0,    55,
      56,    57,    58,    59,    60,     0,     0,    61,  -584,     0,
       0,  -584,  -584,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    62,    63,    64,
       0,     0,  -584,     0,     0,     0,     0,     0,     0,  -584,
     280,  -584,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,     0,  -584,  -584,     0,     0,     0,    15,     0,
      16,    17,    18,    19,     0,     0,     0,     0,     0,    20,
      21,    22,    23,    24,    25,    26,     0,     0,    27,     0,
       0,     0,     0,     0,    28,     0,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,     0,    40,    41,    42,
       0,     0,    43,     0,     0,    44,    45,     0,    46,    47,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    48,     0,
       0,    49,    50,     0,    51,    52,     0,    53,     0,     0,
      54,     0,    55,    56,    57,    58,    59,    60,     0,     0,
      61,  -584,     0,     0,  -584,  -584,   280,     0,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,     0,     0,
      62,    63,    64,     0,    15,     0,    16,    17,    18,    19,
       0,     0,  -584,     0,  -584,    20,    21,    22,    23,    24,
      25,    26,     0,     0,    27,     0,     0,     0,     0,     0,
      28,     0,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,     0,    40,    41,    42,     0,     0,    43,     0,
       0,    44,    45,     0,    46,    47,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    48,     0,     0,   281,    50,     0,
      51,    52,     0,    53,     0,     0,    54,     0,    55,    56,
      57,    58,    59,    60,     0,     0,    61,  -584,     0,     0,
    -584,  -584,   280,     0,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,     0,     0,    62,    63,    64,     0,
      15,     0,    16,    17,    18,    19,  -584,     0,  -584,     0,
    -584,    20,    21,    22,    23,    24,    25,    26,     0,     0,
      27,     0,     0,     0,     0,     0,    28,     0,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,     0,    40,
      41,    42,     0,     0,    43,     0,     0,    44,    45,     0,
      46,    47,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      48,     0,     0,    49,    50,     0,    51,    52,     0,    53,
       0,     0,    54,     0,    55,    56,    57,    58,    59,    60,
       0,     0,    61,  -584,     0,     0,  -584,  -584,   280,     0,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
       0,     0,    62,    63,    64,     0,    15,     0,    16,    17,
      18,    19,  -584,     0,  -584,     0,  -584,    20,    21,    22,
      23,    24,    25,    26,     0,     0,    27,     0,     0,     0,
       0,     0,    28,     0,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,     0,    40,    41,    42,     0,     0,
      43,     0,     0,    44,    45,     0,    46,    47,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    48,     0,     0,    49,
      50,     0,    51,    52,     0,    53,     0,     0,    54,     0,
      55,    56,    57,    58,    59,    60,     0,     0,    61,  -584,
       0,     0,  -584,  -584,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    62,    63,
      64,     0,     0,  -584,     0,     0,     0,     0,     0,     0,
    -584,   280,  -584,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,     0,     0,  -584,     0,     0,     0,    15,
       0,    16,    17,    18,    19,     0,     0,     0,     0,     0,
      20,    21,    22,    23,    24,    25,    26,     0,     0,    27,
       0,     0,     0,     0,     0,    28,     0,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,     0,    40,    41,
      42,     0,     0,    43,     0,     0,    44,    45,     0,    46,
      47,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    48,
       0,     0,    49,    50,     0,    51,    52,     0,    53,     0,
       0,    54,     0,    55,    56,    57,    58,    59,    60,     0,
       0,    61,  -584,     0,     0,  -584,  -584,     0,     0,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,     0,
       0,    62,    63,    64,     0,    15,     0,    16,    17,    18,
      19,     0,     0,  -584,     0,  -584,    20,    21,    22,    23,
      24,    25,    26,     0,     0,    27,     0,     0,     0,     0,
       0,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,     0,    40,    41,    42,     0,     0,    43,
       0,     0,    44,    45,     0,    46,    47,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    48,     0,     0,    49,    50,
       0,    51,    52,     0,    53,     0,     0,    54,     0,    55,
      56,    57,    58,    59,    60,     0,     0,    61,   234,     0,
       0,   235,   236,     0,     0,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,     0,     0,    62,    63,    64,
       0,    15,     0,    16,    17,    18,    19,     0,     0,   237,
       0,   238,    20,    21,    22,    23,    24,    25,    26,     0,
       0,    27,     0,     0,     0,     0,     0,    28,     0,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,     0,
      40,    41,    42,     0,     0,    43,     0,     0,    44,    45,
       0,    46,    47,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    48,     0,     0,    49,    50,     0,    51,    52,     0,
      53,     0,     0,    54,     0,    55,    56,    57,    58,    59,
      60,     0,     0,    61,   234,     0,     0,   235,   236,     0,
       0,     5,     6,     7,     8,     9,    10,    11,    12,    13,
       0,     0,     0,    62,    63,    64,     0,    15,     0,    16,
      17,    18,    19,     0,     0,   237,     0,   238,    20,    21,
      22,    23,    24,    25,    26,     0,     0,    27,     0,     0,
       0,     0,     0,     0,     0,     0,    31,    32,    33,    34,
      35,    36,    37,    38,    39,     0,    40,    41,    42,     0,
       0,    43,     0,     0,    44,    45,     0,    46,    47,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   202,     0,     0,
     112,    50,     0,    51,    52,     0,     0,     0,     0,    54,
       0,    55,    56,    57,    58,    59,    60,     0,     0,    61,
     234,     0,     0,   235,   236,     0,     0,     5,     6,     7,
       8,     9,    10,    11,    12,    13,     0,     0,     0,    62,
      63,    64,     0,    15,     0,    16,    17,    18,    19,     0,
       0,   237,     0,   238,    20,    21,    22,    23,    24,    25,
      26,     0,     0,    27,     0,     0,     0,     0,     0,     0,
       0,     0,    31,    32,    33,    34,    35,    36,    37,    38,
      39,     0,    40,    41,    42,     0,     0,    43,     0,     0,
      44,    45,     0,    46,    47,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   202,     0,     0,   112,    50,     0,    51,
      52,     0,     0,     0,     0,    54,     0,    55,    56,    57,
      58,    59,    60,     0,     0,    61,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    62,    63,    64,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   238,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,     0,     0,     0,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,     0,     0,     0,
       0,     0,   156,   157,   158,   159,   160,   161,   162,   163,
      36,    37,   164,    39,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   165,   166,   167,   168,
     169,   170,   171,   172,   173,     0,     0,   174,   175,     0,
       0,   176,   177,   178,   179,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   180,   181,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,     0,   192,
     193,     0,     0,     0,     0,     0,   194,   195,  -553,  -553,
    -553,  -553,  -553,  -553,  -553,  -553,  -553,     0,     0,     0,
       0,     0,     0,     0,  -553,     0,  -553,  -553,  -553,  -553,
       0,  -553,     0,     0,     0,  -553,  -553,  -553,  -553,  -553,
    -553,  -553,     0,     0,  -553,     0,     0,     0,     0,     0,
       0,     0,     0,  -553,  -553,  -553,  -553,  -553,  -553,  -553,
    -553,  -553,     0,  -553,  -553,  -553,     0,     0,  -553,     0,
       0,  -553,  -553,     0,  -553,  -553,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  -553,     0,     0,  -553,  -553,     0,
    -553,  -553,     0,  -553,  -553,  -553,  -553,     0,  -553,  -553,
    -553,  -553,  -553,  -553,     0,     0,  -553,     0,     0,     0,
       0,     0,     0,  -555,  -555,  -555,  -555,  -555,  -555,  -555,
    -555,  -555,     0,     0,     0,     0,  -553,  -553,  -553,  -555,
    -553,  -555,  -555,  -555,  -555,  -553,  -555,     0,     0,     0,
    -555,  -555,  -555,  -555,  -555,  -555,  -555,     0,     0,  -555,
       0,     0,     0,     0,     0,     0,     0,     0,  -555,  -555,
    -555,  -555,  -555,  -555,  -555,  -555,  -555,     0,  -555,  -555,
    -555,     0,     0,  -555,     0,     0,  -555,  -555,     0,  -555,
    -555,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  -555,
       0,     0,  -555,  -555,     0,  -555,  -555,     0,  -555,  -555,
    -555,  -555,     0,  -555,  -555,  -555,  -555,  -555,  -555,     0,
       0,  -555,     0,     0,     0,     0,     0,     0,  -554,  -554,
    -554,  -554,  -554,  -554,  -554,  -554,  -554,     0,     0,     0,
       0,  -555,  -555,  -555,  -554,  -555,  -554,  -554,  -554,  -554,
    -555,  -554,     0,     0,     0,  -554,  -554,  -554,  -554,  -554,
    -554,  -554,     0,     0,  -554,     0,     0,     0,     0,     0,
       0,     0,     0,  -554,  -554,  -554,  -554,  -554,  -554,  -554,
    -554,  -554,     0,  -554,  -554,  -554,     0,     0,  -554,     0,
       0,  -554,  -554,     0,  -554,  -554,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  -554,     0,     0,  -554,  -554,     0,
    -554,  -554,     0,  -554,  -554,  -554,  -554,     0,  -554,  -554,
    -554,  -554,  -554,  -554,     0,     0,  -554,     0,     0,     0,
       0,     0,     0,  -556,  -556,  -556,  -556,  -556,  -556,  -556,
    -556,  -556,     0,     0,     0,     0,  -554,  -554,  -554,  -556,
    -554,  -556,  -556,  -556,  -556,  -554,     0,     0,     0,     0,
    -556,  -556,  -556,  -556,  -556,  -556,  -556,     0,     0,  -556,
       0,     0,     0,     0,     0,     0,     0,     0,  -556,  -556,
    -556,  -556,  -556,  -556,  -556,  -556,  -556,     0,  -556,  -556,
    -556,     0,     0,  -556,     0,     0,  -556,  -556,     0,  -556,
    -556,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  -556,
     763,     0,  -556,  -556,     0,  -556,  -556,     0,  -556,  -556,
    -556,  -556,     0,  -556,  -556,  -556,  -556,  -556,  -556,     0,
       0,  -556,     0,     0,     0,     0,     0,     0,   -99,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  -556,  -556,  -556,     0,     0,     0,     0,     0,     0,
    -556,  -557,  -557,  -557,  -557,  -557,  -557,  -557,  -557,  -557,
       0,     0,     0,     0,     0,     0,     0,  -557,     0,  -557,
    -557,  -557,  -557,     0,     0,     0,     0,     0,  -557,  -557,
    -557,  -557,  -557,  -557,  -557,     0,     0,  -557,     0,     0,
       0,     0,     0,     0,     0,     0,  -557,  -557,  -557,  -557,
    -557,  -557,  -557,  -557,  -557,     0,  -557,  -557,  -557,     0,
       0,  -557,     0,     0,  -557,  -557,     0,  -557,  -557,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  -557,   764,     0,
    -557,  -557,     0,  -557,  -557,     0,  -557,  -557,  -557,  -557,
       0,  -557,  -557,  -557,  -557,  -557,  -557,     0,     0,  -557,
       0,     0,     0,     0,     0,     0,  -101,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  -557,
    -557,  -557,     0,     0,     0,     0,     0,     0,  -557,  -251,
    -251,  -251,  -251,  -251,  -251,  -251,  -251,  -251,     0,     0,
       0,     0,     0,     0,     0,  -251,     0,  -251,  -251,  -251,
    -251,     0,     0,     0,     0,     0,  -251,  -251,  -251,  -251,
    -251,  -251,  -251,     0,     0,  -251,     0,     0,     0,     0,
       0,     0,     0,     0,  -251,  -251,  -251,  -251,  -251,  -251,
    -251,  -251,  -251,     0,  -251,  -251,  -251,     0,     0,  -251,
       0,     0,  -251,  -251,     0,  -251,  -251,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  -251,     0,     0,  -251,  -251,
       0,  -251,  -251,     0,  -251,  -251,  -251,  -251,     0,  -251,
    -251,  -251,  -251,  -251,  -251,     0,     0,  -251,     0,     0,
       0,     0,     0,     0,  -558,  -558,  -558,  -558,  -558,  -558,
    -558,  -558,  -558,     0,     0,     0,     0,  -251,  -251,  -251,
    -558,     0,  -558,  -558,  -558,  -558,   262,     0,     0,     0,
       0,  -558,  -558,  -558,  -558,  -558,  -558,  -558,     0,     0,
    -558,     0,     0,     0,     0,     0,     0,     0,     0,  -558,
    -558,  -558,  -558,  -558,  -558,  -558,  -558,  -558,     0,  -558,
    -558,  -558,     0,     0,  -558,     0,     0,  -558,  -558,     0,
    -558,  -558,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    -558,     0,     0,  -558,  -558,     0,  -558,  -558,     0,  -558,
    -558,  -558,  -558,     0,  -558,  -558,  -558,  -558,  -558,  -558,
       0,     0,  -558,     0,     0,     0,     0,     0,     0,  -559,
    -559,  -559,  -559,  -559,  -559,  -559,  -559,  -559,     0,     0,
       0,     0,  -558,  -558,  -558,  -559,     0,  -559,  -559,  -559,
    -559,  -558,     0,     0,     0,     0,  -559,  -559,  -559,  -559,
    -559,  -559,  -559,     0,     0,  -559,     0,     0,     0,     0,
       0,     0,     0,     0,  -559,  -559,  -559,  -559,  -559,  -559,
    -559,  -559,  -559,     0,  -559,  -559,  -559,     0,     0,  -559,
       0,     0,  -559,  -559,     0,  -559,  -559,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  -559,     0,     0,  -559,  -559,
       0,  -559,  -559,     0,  -559,  -559,  -559,  -559,     0,  -559,
    -559,  -559,  -559,  -559,  -559,     0,     0,  -559,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  -559,  -559,  -559,
       0,     0,     0,     0,     0,     0,  -559,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,     0,     0,     0,   146,   147,   148,   220,   221,   222,
     223,   153,   154,   155,     0,     0,     0,     0,     0,   156,
     157,   158,   224,   225,   226,   227,   163,   305,   306,   228,
     307,     0,     0,     0,     0,     0,     0,   308,     0,     0,
       0,     0,     0,   165,   166,   167,   168,   169,   170,   171,
     172,   173,     0,     0,   174,   175,     0,     0,   176,   177,
     178,   179,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   180,   181,     0,     0,     0,     0,     0,     0,
       0,   309,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,     0,   192,   193,     0,     0,
       0,     0,     0,   194,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,     0,     0,
       0,   146,   147,   148,   220,   221,   222,   223,   153,   154,
     155,     0,     0,     0,     0,     0,   156,   157,   158,   224,
     225,   226,   227,   163,   305,   306,   228,   307,     0,     0,
       0,     0,     0,     0,   308,     0,     0,     0,     0,     0,
     165,   166,   167,   168,   169,   170,   171,   172,   173,     0,
       0,   174,   175,     0,     0,   176,   177,   178,   179,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   180,
     181,     0,     0,     0,     0,     0,     0,     0,   428,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,     0,   192,   193,     0,     0,     0,     0,     0,
     194,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,     0,     0,     0,   146,   147,
     148,   220,   221,   222,   223,   153,   154,   155,     0,     0,
       0,     0,     0,   156,   157,   158,   224,   225,   226,   227,
     163,     0,     0,   228,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   165,   166,   167,
     168,   169,   170,   171,   172,   173,     0,     0,   174,   175,
       0,     0,   176,   177,   178,   179,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   180,   181,     0,     0,
       0,   229,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,     0,
     192,   193,     0,     0,     0,     0,     0,   194,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,     0,     0,     0,   146,   147,   148,   220,   221,
     222,   223,   153,   154,   155,     0,     0,     0,     0,     0,
     156,   157,   158,   224,   225,   226,   227,   163,     0,     0,
     228,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   165,   166,   167,   168,   169,   170,
     171,   172,   173,     0,     0,   174,   175,     0,     0,   176,
     177,   178,   179,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   180,   181,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,     0,   192,   193,     0,
       0,     0,     0,     0,   194,     5,     6,     7,     8,     9,
      10,    11,    12,    13,     0,     0,     0,     0,     0,     0,
       0,    15,     0,   102,   103,    18,    19,     0,     0,     0,
       0,     0,   104,   105,   106,    23,    24,    25,    26,     0,
       0,   107,     0,     0,     0,     0,     0,     0,     0,     0,
      31,    32,    33,    34,    35,    36,    37,    38,    39,     0,
      40,    41,    42,     0,     0,    43,     0,     0,    44,    45,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   298,     0,     0,   112,    50,     0,    51,    52,     0,
       0,     0,     0,    54,     0,    55,    56,    57,    58,    59,
      60,     0,     0,    61,     0,     0,     5,     6,     7,     8,
       9,    10,    11,    12,    13,     0,     0,     0,     0,     0,
       0,     0,    15,   113,   102,   103,    18,    19,     0,     0,
     299,     0,     0,   104,   105,   106,    23,    24,    25,    26,
       0,     0,   107,     0,     0,     0,     0,     0,     0,     0,
       0,    31,    32,    33,    34,    35,    36,    37,    38,    39,
       0,    40,    41,    42,     0,     0,    43,     0,     0,    44,
      45,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   298,     0,     0,   112,    50,     0,    51,    52,
       0,     0,     0,     0,    54,     0,    55,    56,    57,    58,
      59,    60,     0,     0,    61,     0,     0,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,     0,     0,     0,
       0,     0,     0,    15,   113,    16,    17,    18,    19,     0,
       0,   550,     0,     0,    20,    21,    22,    23,    24,    25,
      26,     0,     0,    27,     0,     0,     0,     0,     0,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,     0,    40,    41,    42,     0,     0,    43,     0,     0,
      44,    45,     0,    46,    47,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    48,     0,     0,    49,    50,     0,    51,
      52,     0,    53,     0,     0,    54,     0,    55,    56,    57,
      58,    59,    60,     0,     0,    61,     0,     0,     0,     0,
       0,     0,     5,     6,     7,     8,     9,    10,    11,    12,
      13,     0,     0,     0,     0,    62,    63,    64,    15,     0,
     102,   103,    18,    19,     0,     0,     0,     0,     0,   104,
     105,   106,    23,    24,    25,    26,     0,     0,   107,     0,
       0,     0,     0,     0,     0,     0,     0,    31,    32,    33,
     247,    35,    36,    37,    38,    39,     0,    40,    41,    42,
       0,     0,    43,     0,     0,    44,    45,     0,    46,    47,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   202,     0,
       0,   112,    50,     0,    51,    52,     0,     0,   249,  -256,
      54,     0,    55,    56,    57,    58,    59,    60,     0,     0,
      61,   234,     0,     0,   235,   236,     0,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,     0,     0,     0,
      62,   251,    64,    15,     0,    16,    17,    18,    19,     0,
       0,     0,     0,     0,    20,    21,    22,    23,    24,    25,
      26,     0,     0,    27,     0,     0,     0,     0,     0,    28,
       0,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,     0,    40,    41,    42,     0,     0,    43,     0,     0,
      44,    45,     0,    46,    47,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    48,     0,     0,    49,    50,     0,    51,
      52,     0,    53,     0,     0,    54,     0,    55,    56,    57,
      58,    59,    60,     0,     0,    61,     0,     0,     0,     0,
       0,     0,     5,     6,     7,     8,     9,    10,    11,    12,
      13,     0,     0,     0,     0,    62,    63,    64,    15,     0,
     102,   103,    18,    19,     0,     0,     0,     0,     0,   104,
     105,   106,    23,    24,    25,    26,     0,     0,   107,     0,
       0,     0,     0,     0,     0,     0,     0,    31,    32,    33,
     247,    35,    36,    37,    38,    39,     0,    40,    41,    42,
       0,     0,    43,     0,     0,    44,    45,     0,    46,    47,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   202,     0,
       0,   112,    50,     0,    51,    52,     0,     0,   249,     0,
      54,     0,    55,    56,    57,    58,    59,    60,     0,     0,
      61,   234,     0,     0,   235,   236,     0,     5,     6,     7,
       8,     9,    10,    11,    12,    13,     0,     0,     0,     0,
      62,   251,    64,    15,     0,    16,    17,    18,    19,     0,
       0,     0,     0,     0,    20,    21,    22,    23,    24,    25,
      26,     0,     0,   107,     0,     0,     0,     0,     0,     0,
       0,     0,    31,    32,    33,   247,    35,    36,    37,    38,
      39,     0,    40,    41,    42,     0,     0,    43,     0,     0,
      44,    45,     0,    46,    47,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   202,     0,     0,   112,    50,     0,    51,
      52,     0,   248,   249,   250,    54,     0,    55,    56,    57,
      58,    59,    60,     0,     0,    61,     0,     0,     0,     0,
       0,     0,     5,     6,     7,     8,     9,    10,    11,    12,
      13,     0,     0,     0,     0,    62,   251,    64,    15,     0,
     102,   103,    18,    19,     0,     0,     0,     0,     0,   104,
     105,   106,    23,    24,    25,    26,     0,     0,   107,     0,
       0,     0,     0,     0,     0,     0,     0,    31,    32,    33,
     247,    35,    36,    37,    38,    39,     0,    40,    41,    42,
       0,     0,    43,     0,     0,    44,    45,     0,    46,    47,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   202,     0,
       0,   112,    50,     0,    51,    52,     0,   658,   249,   250,
      54,     0,    55,    56,    57,    58,    59,    60,     0,     0,
      61,     0,     0,     0,     0,     0,     0,     5,     6,     7,
       8,     9,    10,    11,    12,    13,     0,     0,     0,     0,
      62,   251,    64,    15,     0,   102,   103,    18,    19,     0,
       0,     0,     0,     0,   104,   105,   106,    23,    24,    25,
      26,     0,     0,   107,     0,     0,     0,     0,     0,     0,
       0,     0,    31,    32,    33,   247,    35,    36,    37,    38,
      39,     0,    40,    41,    42,     0,     0,    43,     0,     0,
      44,    45,     0,    46,    47,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   202,     0,     0,   112,    50,     0,    51,
      52,     0,   248,   249,     0,    54,     0,    55,    56,    57,
      58,    59,    60,     0,     0,    61,     0,     0,     0,     0,
       0,     0,     5,     6,     7,     8,     9,    10,    11,    12,
      13,     0,     0,     0,     0,    62,   251,    64,    15,     0,
     102,   103,    18,    19,     0,     0,     0,     0,     0,   104,
     105,   106,    23,    24,    25,    26,     0,     0,   107,     0,
       0,     0,     0,     0,     0,     0,     0,    31,    32,    33,
     247,    35,    36,    37,    38,    39,     0,    40,    41,    42,
       0,     0,    43,     0,     0,    44,    45,     0,    46,    47,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   202,     0,
       0,   112,    50,     0,    51,    52,     0,   658,   249,     0,
      54,     0,    55,    56,    57,    58,    59,    60,     0,     0,
      61,     0,     0,     0,     0,     0,     0,     5,     6,     7,
       8,     9,    10,    11,    12,    13,     0,     0,     0,     0,
      62,   251,    64,    15,     0,   102,   103,    18,    19,     0,
       0,     0,     0,     0,   104,   105,   106,    23,    24,    25,
      26,     0,     0,   107,     0,     0,     0,     0,     0,     0,
       0,     0,    31,    32,    33,   247,    35,    36,    37,    38,
      39,     0,    40,    41,    42,     0,     0,    43,     0,     0,
      44,    45,     0,    46,    47,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   202,     0,     0,   112,    50,     0,    51,
      52,     0,     0,   249,     0,    54,     0,    55,    56,    57,
      58,    59,    60,     0,     0,    61,     0,     0,     0,     0,
       0,     0,     5,     6,     7,     8,     9,    10,    11,    12,
      13,     0,     0,     0,     0,    62,   251,    64,    15,     0,
      16,    17,    18,    19,     0,     0,     0,     0,     0,    20,
      21,    22,    23,    24,    25,    26,     0,     0,   107,     0,
       0,     0,     0,     0,     0,     0,     0,    31,    32,    33,
      34,    35,    36,    37,    38,    39,     0,    40,    41,    42,
       0,     0,    43,     0,     0,    44,    45,     0,    46,    47,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   202,     0,
       0,   112,    50,     0,    51,    52,     0,   544,     0,     0,
      54,     0,    55,    56,    57,    58,    59,    60,     0,     0,
      61,     0,     0,     0,     0,     0,     0,     5,     6,     7,
       8,     9,    10,    11,    12,    13,     0,     0,     0,     0,
      62,   251,    64,    15,     0,   102,   103,    18,    19,     0,
       0,     0,     0,     0,   104,   105,   106,    23,    24,    25,
      26,     0,     0,   107,     0,     0,     0,     0,     0,     0,
       0,     0,    31,    32,    33,    34,    35,    36,    37,    38,
      39,     0,    40,    41,    42,     0,     0,    43,     0,     0,
      44,    45,     0,    46,    47,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   202,     0,     0,   112,    50,     0,    51,
      52,     0,   248,     0,     0,    54,     0,    55,    56,    57,
      58,    59,    60,     0,     0,    61,     0,     0,     0,     0,
       0,     0,     5,     6,     7,     8,     9,    10,    11,    12,
      13,     0,     0,     0,     0,    62,   251,    64,    15,     0,
     102,   103,    18,    19,     0,     0,     0,     0,     0,   104,
     105,   106,    23,    24,    25,    26,     0,     0,   107,     0,
       0,     0,     0,     0,     0,     0,     0,    31,    32,    33,
      34,    35,    36,    37,    38,    39,     0,    40,    41,    42,
       0,     0,    43,     0,     0,    44,    45,     0,    46,    47,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   202,     0,
       0,   112,    50,     0,    51,    52,     0,   544,     0,     0,
      54,     0,    55,    56,    57,    58,    59,    60,     0,     0,
      61,     0,     0,     0,     0,     0,     0,     5,     6,     7,
       8,     9,    10,    11,    12,    13,     0,     0,     0,     0,
      62,   251,    64,    15,     0,   102,   103,    18,    19,     0,
       0,     0,     0,     0,   104,   105,   106,    23,    24,    25,
      26,     0,     0,   107,     0,     0,     0,     0,     0,     0,
       0,     0,    31,    32,    33,    34,    35,    36,    37,    38,
      39,     0,    40,    41,    42,     0,     0,    43,     0,     0,
      44,    45,     0,    46,    47,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   202,     0,     0,   112,    50,     0,    51,
      52,     0,   822,     0,     0,    54,     0,    55,    56,    57,
      58,    59,    60,     0,     0,    61,     0,     0,     0,     0,
       0,     0,     5,     6,     7,     8,     9,    10,    11,    12,
      13,     0,     0,     0,     0,    62,   251,    64,    15,     0,
     102,   103,    18,    19,     0,     0,     0,     0,     0,   104,
     105,   106,    23,    24,    25,    26,     0,     0,   107,     0,
       0,     0,     0,     0,     0,     0,     0,    31,    32,    33,
      34,    35,    36,    37,    38,    39,     0,    40,    41,    42,
       0,     0,    43,     0,     0,    44,    45,     0,    46,    47,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   202,     0,
       0,   112,    50,     0,    51,    52,     0,   658,     0,     0,
      54,     0,    55,    56,    57,    58,    59,    60,     0,     0,
      61,     0,     0,     0,     0,     0,     0,     5,     6,     7,
       8,     9,    10,    11,    12,    13,     0,     0,     0,     0,
      62,   251,    64,    15,     0,    16,    17,    18,    19,     0,
       0,     0,     0,     0,    20,    21,    22,    23,    24,    25,
      26,     0,     0,    27,     0,     0,     0,     0,     0,     0,
       0,     0,    31,    32,    33,    34,    35,    36,    37,    38,
      39,     0,    40,    41,    42,     0,     0,    43,     0,     0,
      44,    45,     0,    46,    47,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   202,     0,     0,   112,    50,     0,    51,
      52,     0,     0,     0,     0,    54,     0,    55,    56,    57,
      58,    59,    60,     0,     0,    61,     0,     0,     0,     0,
       0,     0,     5,     6,     7,     8,     9,    10,    11,    12,
      13,     0,     0,     0,     0,    62,    63,    64,    15,     0,
     102,   103,    18,    19,     0,     0,     0,     0,     0,   104,
     105,   106,    23,    24,    25,    26,     0,     0,   107,     0,
       0,     0,     0,     0,     0,     0,     0,    31,    32,    33,
      34,    35,    36,    37,    38,    39,     0,    40,    41,    42,
       0,     0,    43,     0,     0,    44,    45,     0,    46,    47,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   202,     0,
       0,   112,    50,     0,    51,    52,     0,     0,     0,     0,
      54,     0,    55,    56,    57,    58,    59,    60,     0,     0,
      61,     0,     0,     0,     0,     0,     0,     5,     6,     7,
       8,     9,    10,    11,    12,    13,     0,     0,     0,     0,
      62,   251,    64,    15,     0,    16,    17,    18,    19,     0,
       0,     0,     0,     0,    20,    21,    22,    23,    24,    25,
      26,     0,     0,   107,     0,     0,     0,     0,     0,     0,
       0,     0,    31,    32,    33,    34,    35,    36,    37,    38,
      39,     0,    40,    41,    42,     0,     0,    43,     0,     0,
      44,    45,     0,    46,    47,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   202,     0,     0,   112,    50,     0,    51,
      52,     0,     0,     0,     0,    54,     0,    55,    56,    57,
      58,    59,    60,     0,     0,    61,     0,     0,     0,     0,
       0,     0,     5,     6,     7,     8,     9,    10,    11,    12,
      13,     0,     0,     0,     0,    62,   251,    64,    15,     0,
     102,   103,    18,    19,     0,     0,     0,     0,     0,   104,
     105,   106,    23,    24,    25,    26,     0,     0,   107,     0,
       0,     0,     0,     0,     0,     0,     0,    31,    32,    33,
     108,    35,    36,    37,   109,    39,     0,    40,    41,    42,
       0,     0,    43,     0,     0,    44,    45,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   110,     0,     0,   111,     0,
       0,   112,    50,     0,    51,    52,     0,     0,     0,     0,
      54,     0,    55,    56,    57,    58,    59,    60,     0,     0,
      61,     0,     0,     5,     6,     7,     8,     9,    10,    11,
      12,    13,     0,     0,     0,     0,     0,     0,     0,    15,
     113,   102,   103,    18,    19,     0,     0,     0,     0,     0,
     104,   105,   106,    23,    24,    25,    26,     0,     0,   107,
       0,     0,     0,     0,     0,     0,     0,     0,    31,    32,
      33,    34,    35,    36,    37,    38,    39,     0,    40,    41,
      42,     0,     0,    43,     0,     0,    44,    45,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   213,
       0,     0,    49,    50,     0,    51,    52,     0,    53,     0,
       0,    54,     0,    55,    56,    57,    58,    59,    60,     0,
       0,    61,     0,     0,     5,     6,     7,     8,     9,    10,
      11,    12,    13,     0,     0,     0,     0,     0,     0,     0,
      15,   113,   102,   103,    18,    19,     0,     0,     0,     0,
       0,   104,   105,   106,    23,    24,    25,    26,     0,     0,
     107,     0,     0,     0,     0,     0,     0,     0,     0,    31,
      32,    33,    34,    35,    36,    37,    38,    39,     0,    40,
      41,    42,     0,     0,    43,     0,     0,    44,    45,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     298,     0,     0,   345,    50,     0,    51,    52,     0,   346,
       0,     0,    54,     0,    55,    56,    57,    58,    59,    60,
       0,     0,    61,     0,     0,     5,     6,     7,     8,     9,
      10,    11,    12,    13,     0,     0,     0,     0,     0,     0,
       0,    15,   113,   102,   103,    18,    19,     0,     0,     0,
       0,     0,   104,   105,   106,    23,    24,    25,    26,     0,
       0,   107,     0,     0,     0,     0,     0,     0,     0,     0,
      31,    32,    33,   108,    35,    36,    37,   109,    39,     0,
      40,    41,    42,     0,     0,    43,     0,     0,    44,    45,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   111,     0,     0,   112,    50,     0,    51,    52,     0,
       0,     0,     0,    54,     0,    55,    56,    57,    58,    59,
      60,     0,     0,    61,     0,     0,     5,     6,     7,     8,
       9,    10,    11,    12,    13,     0,     0,     0,     0,     0,
       0,     0,    15,   113,   102,   103,    18,    19,     0,     0,
       0,     0,     0,   104,   105,   106,    23,    24,    25,    26,
       0,     0,   107,     0,     0,     0,     0,     0,     0,     0,
       0,    31,    32,    33,    34,    35,    36,    37,    38,    39,
       0,    40,    41,    42,     0,     0,    43,     0,     0,    44,
      45,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   298,     0,     0,   345,    50,     0,    51,    52,
       0,     0,     0,     0,    54,     0,    55,    56,    57,    58,
      59,    60,     0,     0,    61,     0,     0,     5,     6,     7,
       8,     9,    10,    11,    12,    13,     0,     0,     0,     0,
       0,     0,     0,    15,   113,   102,   103,    18,    19,     0,
       0,     0,     0,     0,   104,   105,   106,    23,    24,    25,
      26,     0,     0,   107,     0,     0,     0,     0,     0,     0,
       0,     0,    31,    32,    33,    34,    35,    36,    37,    38,
      39,     0,    40,    41,    42,     0,     0,    43,     0,     0,
      44,    45,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   895,     0,     0,   112,    50,     0,    51,
      52,     0,     0,     0,     0,    54,     0,    55,    56,    57,
      58,    59,    60,     0,     0,    61,     0,     0,     5,     6,
       7,     8,     9,    10,    11,    12,    13,     0,     0,     0,
       0,     0,     0,     0,    15,   113,   102,   103,    18,    19,
       0,     0,     0,     0,     0,   104,   105,   106,    23,    24,
      25,    26,     0,     0,   107,     0,     0,   723,     0,     0,
       0,     0,     0,    31,    32,    33,    34,    35,    36,    37,
      38,    39,     0,    40,    41,    42,     0,     0,    43,     0,
       0,    44,    45,     0,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,     0,     0,   362,
     363,     0,     0,     0,   921,     0,     0,   112,    50,     0,
      51,    52,     0,     0,     0,     0,    54,     0,    55,    56,
      57,    58,    59,    60,     0,     0,    61,     0,     0,   617,
     589,     0,   364,   618,   365,   366,   367,   368,   369,   370,
     371,   372,   373,   374,     0,     0,   113,   165,   166,   167,
     168,   169,   170,   171,   172,   173,     0,     0,   174,   175,
       0,     0,   176,   177,   178,   179,     0,     0,     0,   349,
    -585,  -585,  -585,  -585,   354,   355,   180,   181,  -585,  -585,
       0,     0,     0,     0,   362,   363,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,     0,
     192,   193,   602,   597,     0,     0,   603,   194,   262,   365,
     366,   367,   368,   369,   370,   371,   372,   373,   374,     0,
     165,   166,   167,   168,   169,   170,   171,   172,   173,     0,
       0,   174,   175,     0,     0,   176,   177,   178,   179,     0,
       0,     0,   349,   350,   351,   352,   353,   354,   355,   180,
     181,   358,   359,     0,     0,     0,     0,   362,   363,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,     0,   192,   193,   633,   589,     0,     0,   634,
     194,   262,   365,   366,   367,   368,   369,   370,   371,   372,
     373,   374,     0,   165,   166,   167,   168,   169,   170,   171,
     172,   173,     0,     0,   174,   175,     0,     0,   176,   177,
     178,   179,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   180,   181,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,     0,   192,   193,   636,   597,
       0,     0,   637,   194,   262,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   165,   166,   167,   168,
     169,   170,   171,   172,   173,     0,     0,   174,   175,     0,
       0,   176,   177,   178,   179,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   180,   181,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,     0,   192,
     193,   643,   589,     0,     0,   644,   194,   262,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   165,
     166,   167,   168,   169,   170,   171,   172,   173,     0,     0,
     174,   175,     0,     0,   176,   177,   178,   179,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   180,   181,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,     0,   192,   193,   646,   597,     0,     0,   647,   194,
     262,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   165,   166,   167,   168,   169,   170,   171,   172,
     173,     0,     0,   174,   175,     0,     0,   176,   177,   178,
     179,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   180,   181,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,     0,   192,   193,   680,   589,     0,
       0,   681,   194,   262,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   165,   166,   167,   168,   169,
     170,   171,   172,   173,     0,     0,   174,   175,     0,     0,
     176,   177,   178,   179,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   180,   181,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,     0,   192,   193,
     683,   597,     0,     0,   684,   194,   262,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   165,   166,
     167,   168,   169,   170,   171,   172,   173,     0,     0,   174,
     175,     0,     0,   176,   177,   178,   179,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   180,   181,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
       0,   192,   193,   827,   589,     0,     0,   828,   194,   262,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   165,   166,   167,   168,   169,   170,   171,   172,   173,
       0,     0,   174,   175,     0,     0,   176,   177,   178,   179,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     180,   181,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,     0,   192,   193,   830,   597,     0,     0,
     831,   194,   262,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   165,   166,   167,   168,   169,   170,
     171,   172,   173,     0,     0,   174,   175,     0,     0,   176,
     177,   178,   179,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   180,   181,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,     0,   192,   193,   981,
     589,     0,     0,   982,   194,   262,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   165,   166,   167,
     168,   169,   170,   171,   172,   173,     0,     0,   174,   175,
       0,     0,   176,   177,   178,   179,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   180,   181,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,     0,
     192,   193,   994,   589,     0,     0,   995,   194,   262,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     165,   166,   167,   168,   169,   170,   171,   172,   173,     0,
       0,   174,   175,     0,     0,   176,   177,   178,   179,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   180,
     181,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,     0,   192,   193,   997,   597,     0,     0,   998,
     194,   262,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   165,   166,   167,   168,   169,   170,   171,
     172,   173,     0,     0,   174,   175,     0,     0,   176,   177,
     178,   179,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   180,   181,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,     0,   192,   193,   602,   597,
       0,     0,   603,   194,   262,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   165,   166,   167,   168,
     169,   170,   171,   172,   173,     0,     0,   174,   175,     0,
       0,   176,   177,   178,   179,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   180,   181,   349,   350,   351,
     352,   353,   354,   355,   356,   357,   358,   359,   360,   361,
       0,     0,   362,   363,     0,     0,     0,     0,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,     0,   192,
     193,     0,     0,     0,     0,     0,   194,     0,     0,     0,
       0,     0,     0,     0,     0,   364,     0,   365,   366,   367,
     368,   369,   370,   371,   372,   373,   374,   349,   350,   351,
     352,   353,   354,   355,   356,   357,   358,   359,   360,   361,
       0,   238,   362,   363,     0,   349,   350,   351,   352,   353,
     354,   355,   356,   357,   358,   359,   360,   361,     0,     0,
     362,   363,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   364,     0,   365,   366,   367,
     368,   369,   370,   371,   372,   373,   374,     0,     0,     0,
       0,     0,     0,   364,  -258,   365,   366,   367,   368,   369,
     370,   371,   372,   373,   374,     0,     0,     0,     0,     0,
       0,     0,  -259,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   358,   359,   360,   361,     0,     0,   362,   363,
       0,   349,   350,   351,   352,   353,   354,   355,   356,   357,
     358,   359,   360,   361,     0,     0,   362,   363,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   364,     0,   365,   366,   367,   368,   369,   370,   371,
     372,   373,   374,     0,     0,     0,     0,     0,     0,   364,
    -260,   365,   366,   367,   368,   369,   370,   371,   372,   373,
     374,     0,     0,     0,     0,     0,     0,     0,  -261,   349,
     350,   351,   352,   353,   354,   355,   356,   357,   358,   359,
     360,   361,     0,     0,   362,   363,     0,     0,     0,   441,
     349,   350,   351,   352,   353,   354,   355,   356,   357,   358,
     359,   360,   361,     0,     0,   362,   363,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   364,     0,   365,
     366,   367,   368,   369,   370,   371,   372,   373,   374,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   364,     0,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374
};

static const yytype_int16 yycheck[] =
{
      27,     2,    82,    83,   431,     7,     4,   210,    28,   447,
     377,    84,   304,    16,    17,   316,     7,    20,   304,   111,
      21,    10,    14,    14,    77,    53,    15,     5,     6,    63,
      16,    17,   422,   400,    20,    13,    28,    28,    49,   348,
     292,    49,   258,   486,   296,   299,   700,    15,   621,   416,
      51,    52,   712,    55,   629,    16,    17,   786,   425,    20,
      26,    26,   635,   638,    55,    51,   712,    16,    17,    21,
      22,    20,   645,    16,    17,    53,    16,    20,   256,   880,
     444,     2,    66,     4,    29,   449,   903,   508,    16,    66,
      51,    52,   281,   375,   517,   135,   519,   379,    66,    77,
     382,   112,    51,    52,   105,   605,   606,   550,     0,   682,
     731,    55,    25,   291,   292,    25,   737,    79,   296,   401,
      25,   488,    57,    25,   601,    57,   206,   604,   386,   387,
      26,    90,    22,   415,    25,   417,   216,    25,    25,    25,
      88,   442,    37,    38,   426,   622,   447,    99,    57,    58,
      59,    60,    25,   105,   106,    71,   345,   317,    26,   118,
     320,   123,   322,   809,   324,   110,   326,   984,   120,   135,
     135,    25,   112,   974,   140,   115,   116,    37,    38,   285,
     348,    28,   464,   289,   112,   120,   118,   115,   116,   140,
     402,   118,    88,   118,   145,   118,   144,   277,   138,   697,
      18,   100,    20,   143,    16,   145,   102,   489,   937,    99,
     502,   138,   128,   129,   130,   143,   502,   145,   386,   387,
      88,   301,   211,   212,   525,   138,   125,   229,   138,   667,
     884,   118,   486,   138,   102,   140,   138,   453,   229,   135,
     900,   137,   742,   903,   140,   118,   299,   138,   144,   140,
     138,   138,   138,   140,   141,   256,   829,   258,   145,   262,
      88,   262,   239,   266,   275,   138,    88,   135,   141,   137,
     281,   239,   145,   281,   452,   138,   144,   720,   246,     2,
     266,     4,     5,     6,   138,   145,     9,    10,    58,    59,
      13,    90,    15,    16,    17,    88,   550,    20,   873,   283,
     112,   262,   666,   115,   116,   266,   283,   399,    51,   343,
      53,    54,    55,    56,   348,   283,   144,   266,   346,   628,
      15,   299,   144,   266,   984,   140,    49,   140,    88,    88,
      53,   143,    90,   145,   345,   333,   138,   345,    88,   625,
      63,   122,   102,   145,   450,   334,   335,   336,   337,    88,
     456,   144,   386,   387,    77,    88,   657,   343,   725,   280,
     118,   467,   348,   523,   665,   333,   667,   288,   346,   547,
      90,    66,    88,    88,   377,   796,   377,   800,   801,   802,
     878,   804,   772,   806,   144,   144,   102,   110,   379,   112,
     888,   382,   813,   814,   144,   138,    55,   400,   118,   400,
     309,   412,   900,   697,   616,   144,   700,   138,   409,   420,
     401,   144,   333,   416,   145,   416,   377,   338,   712,   430,
     118,   137,   425,   996,   425,   677,   417,   379,   144,   144,
      90,   484,    90,   486,    16,   426,   874,    88,    55,   400,
     460,    25,   724,   549,   726,   661,   873,    88,   434,   401,
     653,   452,   453,   421,   422,   416,    90,   749,   118,   138,
     461,   102,    51,   749,   425,   417,   720,   141,   460,   460,
     728,   145,    90,   464,   426,   653,   734,   735,   201,    20,
     560,   138,    71,   444,   118,   488,   447,   488,   211,   212,
     988,    90,   138,   144,    57,   444,   137,   550,   489,   677,
     118,   713,   470,   144,  1002,   506,   484,   508,   486,   204,
      99,   100,   464,   524,   475,   210,   135,    90,   624,   118,
     138,   944,   945,   946,   947,    90,   475,   488,   740,    71,
     112,   952,   141,   115,   116,   145,   125,   489,   750,   262,
     461,    90,   543,   266,   239,   118,    90,   270,   271,   470,
     577,   246,   275,   118,   722,    27,   118,   280,   281,    90,
     728,   143,   142,   145,   780,   288,   734,   735,   595,   118,
     676,   857,   550,   874,   118,   136,   299,    58,    59,   791,
      55,    61,   840,  1006,    64,    65,   138,   118,   283,   138,
     884,    90,   138,   145,   621,    51,   291,   292,   965,    55,
     601,   296,    71,   604,   605,   606,   900,   138,   635,   903,
     333,   334,   335,   336,   337,   338,   339,   340,   645,   118,
     343,   622,   345,   346,   626,   348,   615,   628,   629,   649,
     631,    17,    18,   113,   114,   626,    25,   638,   333,   851,
     112,   593,   628,   115,   116,    71,   614,   138,   691,   601,
      90,    97,   604,    15,   377,   682,   859,   649,   649,   648,
     661,   688,   865,   386,   387,   738,    13,   720,   620,   712,
     622,   143,   840,   145,    25,    16,    63,   400,   118,   402,
     403,   787,    15,   112,   966,   712,   115,   116,   722,   412,
     984,   100,   691,   416,   728,   729,   695,   420,   138,   138,
     734,   735,   425,   593,   138,   666,   667,   430,   920,   141,
     138,   601,    90,   712,   604,   136,    51,   666,    53,    54,
      55,    56,   725,   138,   725,    90,   421,   422,   112,   118,
     741,   115,   116,    51,   138,   726,    88,   138,   461,   138,
     118,   742,   720,    51,   138,    51,   757,   470,   854,   138,
     102,    44,   141,   118,   755,   138,   145,   758,   769,   770,
     138,   484,   118,   486,   725,   488,   777,   118,    15,    18,
      26,   760,    88,   138,   726,   470,   744,   136,    15,   780,
      15,   792,   809,   751,   142,   137,   102,   138,   712,    91,
     141,    88,   144,   136,   145,   796,   136,    14,   143,    15,
     721,   524,   829,   138,   772,   102,   840,    15,   138,   138,
      71,   112,   813,   814,   115,   116,     2,   141,     4,    57,
      26,   137,    15,     9,    10,    86,    87,   550,   144,    15,
      16,    17,    88,   811,    20,    63,    64,    65,   816,   850,
     137,   136,   143,   923,   145,   123,   102,   144,   138,     9,
      10,   862,    71,   138,   897,    15,   138,   900,   138,   138,
     903,   138,   905,    49,   125,   126,   127,   128,   129,   130,
     386,   387,   873,   138,   138,    15,    15,    63,    15,   135,
     858,   137,    88,    88,   140,   113,   114,    15,   144,    15,
     138,   136,   615,   616,   123,   136,   102,   102,   897,    55,
      15,   900,   418,   419,   903,    55,   905,   126,   127,   128,
     129,   130,   939,   874,    88,   926,   138,   928,   138,   614,
     931,    15,    88,   138,   110,   648,   112,   138,   102,   135,
      15,   137,   137,   140,   140,   140,   102,   138,   144,   144,
     138,   984,   138,   986,   461,   988,   140,   990,   138,   465,
     110,   952,    13,     6,    88,   968,    61,   712,   653,    64,
      65,   739,   965,   137,   965,   974,   967,   968,   102,   996,
     144,   137,  1015,   897,    88,   966,   900,   967,   144,   903,
     316,   905,   677,   241,     7,   984,    88,   986,   102,   988,
     713,   990,   857,   818,   819,   691,   897,   720,   721,   722,
     102,    -1,   725,   137,   965,   728,   729,   900,   113,   114,
     144,   734,   735,   697,   966,   201,  1015,   740,   741,    -1,
      -1,    -1,    -1,   137,    -1,   211,   212,   750,    -1,    -1,
     144,    63,    64,    65,   757,   137,    -1,   760,    -1,    -1,
      -1,    88,   144,    -1,    -1,    -1,   769,   770,    -1,   744,
      -1,   211,   212,    -1,   777,   102,   751,    71,   687,    -1,
     984,    -1,   986,    -1,   988,    -1,   990,    -1,   791,   792,
      -1,   700,    86,    87,   703,   112,   262,   772,   115,   116,
     266,   113,   114,   712,   270,   271,    -1,    88,   811,   275,
     137,  1015,    -1,   816,   280,   281,    -1,   144,    -1,    -1,
      -1,   102,   288,    -1,   141,   142,    -1,    88,   145,    -1,
     270,   271,   126,   127,   128,   129,   130,   840,    -1,    -1,
      62,   102,    64,    65,    -1,    -1,    -1,   850,   851,   954,
     955,   956,    -1,   958,   959,   858,   137,    -1,    62,   862,
      64,    65,    -1,   144,    -1,    -1,    -1,   333,   334,   335,
     336,   337,   338,   339,   340,    -1,   137,   343,    -1,   345,
      -1,    -1,   348,   144,   859,    40,    41,    42,    43,    44,
     865,   113,   114,    -1,   334,   335,   336,   337,    -1,   339,
     340,    -1,  1007,  1008,  1009,  1010,    -1,    -1,    -1,   113,
     114,   377,    -1,    -1,  1019,    -1,    -1,   920,    -1,    -1,
     386,   387,    -1,   926,    -1,   928,    -1,    -1,   931,    63,
      64,    65,   728,   729,   400,    -1,   402,   403,   734,   735,
      51,    -1,    53,    54,    55,    56,   412,    63,    64,    65,
     416,    -1,    -1,    -1,   420,    -1,    -1,    71,    -1,   425,
      -1,    -1,   965,   403,   430,    -1,    -1,   763,   764,    -1,
     766,   767,    86,    87,    -1,   884,    -1,   886,    -1,   113,
     114,   890,    -1,    -1,    -1,    -1,    -1,    51,    -1,    53,
      54,    55,    56,    -1,   903,   461,   905,   113,   114,    -1,
      -1,    -1,    16,    17,   470,    -1,    20,    71,    -1,   123,
     124,   125,   126,   127,   128,   129,   130,    -1,    -1,    63,
      64,    65,   488,    63,    64,    65,   935,   936,    92,    -1,
      -1,    -1,    46,    47,    98,    99,   100,    51,    52,    63,
      64,    65,     0,    -1,   840,    -1,    63,    64,    65,    63,
      64,    -1,    -1,    -1,    -1,    13,    14,    15,   524,    17,
      18,   125,    20,   972,   128,    -1,    -1,    -1,   977,   113,
     114,   867,    -1,   113,   114,   984,   140,   986,    -1,    37,
      38,   990,    40,    41,    42,    43,    44,    -1,    -1,   113,
     114,    -1,    -1,    -1,    -1,  1004,   113,   114,    51,    -1,
      53,    54,    55,    56,    -1,    -1,  1015,    51,    -1,    53,
      54,    55,    56,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    -1,    71,    86,    87,
      88,    -1,    90,    51,    -1,    53,    54,    55,    56,    92,
      -1,    -1,    -1,    -1,   102,    98,    -1,    -1,    92,   615,
     616,    -1,    -1,    -1,   112,    99,   100,   115,   116,    -1,
     118,   119,    -1,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,    -1,    92,   615,    -1,    -1,   136,   137,
     138,   125,   648,   141,    -1,   143,   144,   145,    -1,    -1,
      -1,     2,    -1,     4,     5,     6,    -1,    -1,    -1,    -1,
      -1,    -1,    13,    -1,    -1,    -1,    -1,    -1,   648,    -1,
      51,    -1,    53,    54,    55,    56,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    51,    -1,    53,    54,    55,    56,    -1,
      -1,    -1,    -1,    -1,   248,   249,   250,   251,    49,    -1,
      -1,    -1,    53,    71,    -1,    -1,    -1,   713,   262,    -1,
      -1,    92,   266,    -1,    -1,   721,   722,    98,    -1,   725,
      -1,    -1,   728,   729,    92,    -1,    77,    -1,   734,   735,
      98,    99,   100,    -1,   740,   741,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   750,    -1,    -1,    -1,    -1,    -1,
      -1,   757,    -1,    -1,   760,    -1,    -1,   125,    -1,    -1,
     128,   112,    -1,   769,   770,    -1,    -1,    -1,    -1,    -1,
      -1,   777,    -1,    -1,    -1,    -1,    -1,   145,    -1,    -1,
     760,    -1,    -1,    -1,    -1,   791,   792,    -1,    -1,   343,
      -1,    -1,    -1,    -1,   348,   349,   350,   351,   352,   353,
     354,   355,   356,   357,   358,   359,   360,   361,   362,   363,
     364,   365,   366,   367,   368,   369,   370,   371,   372,   373,
     374,    -1,    -1,   377,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   386,   387,   840,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   850,   851,   400,    -1,    -1,    -1,
     201,    -1,    -1,    -1,    -1,    -1,   862,    -1,    -1,    -1,
     414,    -1,   416,    -1,   418,   419,    -1,    -1,    -1,    -1,
      -1,   425,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     434,    -1,    -1,   437,    -1,    -1,    -1,   441,    -1,    -1,
     444,    -1,   446,   447,    -1,    51,    -1,    53,    54,    55,
      56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   465,    -1,    -1,   920,    71,    -1,    -1,    -1,    -1,
     926,   475,   928,    -1,   275,   931,    -1,    -1,    -1,   280,
     281,    -1,    -1,    -1,   488,    -1,    92,   288,    -1,    -1,
      -1,    -1,    98,    99,   100,    -1,    -1,    -1,   299,    -1,
     504,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   965,
      -1,   515,    -1,    51,    -1,    53,    54,    55,    56,   125,
      -1,    -1,   128,    -1,    -1,    -1,    -1,    -1,    -1,   533,
     534,    -1,   333,    71,   140,    -1,    -1,   338,    -1,    -1,
     544,    -1,    -1,    -1,   345,   346,    -1,   348,    -1,    -1,
      -1,    -1,    -1,    -1,    92,    -1,    -1,    -1,    -1,    -1,
      98,    99,   100,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       2,    -1,     4,     5,     6,     7,    -1,    -1,    -1,    -1,
      -1,    13,    -1,    -1,    -1,   386,   387,   125,    -1,    -1,
     128,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   402,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   412,    -1,    -1,    -1,    -1,    -1,    49,    -1,   420,
      -1,    53,    -1,    -1,   628,    -1,    -1,    -1,    -1,   430,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    77,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   658,    -1,    -1,    -1,    -1,    44,
     461,    -1,   666,   667,    -1,    -1,    -1,    -1,    -1,   470,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     112,    -1,    -1,   484,    -1,   486,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    -1,
      -1,    86,    87,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   717,    -1,    -1,    -1,    -1,   722,   723,
      -1,   725,    -1,   524,   728,   729,    -1,    -1,    -1,    -1,
     734,   735,    -1,    -1,   119,    -1,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,    -1,    -1,    -1,   550,
      -1,    -1,    -1,   138,     2,    -1,     4,    -1,    -1,   763,
     764,    -1,   766,   767,    -1,    13,    -1,    -1,    -1,   201,
      -1,    -1,   776,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   616,    -1,    -1,   822,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   832,   833,
      -1,    -1,    -1,    -1,    -1,    -1,   840,    -1,    -1,    -1,
      -1,    -1,    -1,   275,    -1,    -1,    -1,    -1,   280,   281,
      -1,    -1,    -1,    -1,    -1,    -1,   288,    -1,    -1,    -1,
      -1,    -1,    -1,   867,   112,    -1,    -1,   299,    -1,    -1,
     874,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   333,    -1,    -1,    -1,    -1,   338,    -1,    -1,    -1,
      -1,    -1,   713,   345,   346,    -1,    -1,    -1,    -1,   720,
     721,   722,    -1,    -1,    -1,    -1,    -1,   728,    -1,    -1,
      -1,    -1,    -1,   734,   735,    -1,    -1,    -1,    -1,   740,
     741,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   750,
      -1,    -1,    -1,   201,    -1,    -1,   757,    -1,    -1,    -1,
      -1,   965,    -1,    -1,    -1,    -1,    -1,    -1,   769,   770,
     402,    -1,    -1,    -1,    -1,    -1,   777,    -1,    -1,    -1,
     412,     2,    -1,     4,    -1,    -1,    -1,    -1,   420,    -1,
     791,   792,    -1,    -1,    -1,    -1,    -1,    -1,   430,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     811,    -1,    -1,    -1,    -1,   816,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   275,    49,   461,
      -1,    -1,   280,   281,    -1,    -1,    -1,    -1,   470,   840,
     288,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   850,
     851,    -1,   484,    -1,   486,    -1,    -1,   858,    -1,    -1,
      -1,   862,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   333,    -1,    -1,    -1,    -1,
     338,   112,   524,    -1,    -1,    -1,    -1,   345,    -1,    -1,
     348,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   550,   920,
      -1,    -1,    51,    52,    -1,   926,    55,   928,    -1,    -1,
     931,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   386,   387,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    80,    81,    -1,   402,    84,    85,    86,    87,    -1,
      -1,    -1,    -1,    -1,   412,    -1,    -1,    -1,    -1,    98,
      99,    -1,   420,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     201,    -1,   430,    -1,   616,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,    -1,   132,   133,    -1,    -1,    -1,    -1,    -1,
     139,   140,    -1,   461,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   470,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    -1,   275,    86,    87,    -1,    -1,   280,
     281,    -1,    -1,    -1,    -1,    -1,    -1,   288,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   524,    -1,    -1,    -1,
      -1,   713,    -1,    -1,    -1,    -1,    -1,    -1,   720,   721,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   740,   741,
      -1,    -1,   333,    -1,    -1,    -1,    -1,   338,   750,    -1,
      -1,    -1,    -1,    -1,   345,   757,    -1,   348,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   769,   770,    -1,
      -1,    -1,    -1,    -1,    -1,   777,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   791,
     792,    -1,    -1,    -1,    -1,   386,   387,    -1,   616,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   811,
      -1,   402,    -1,    -1,   816,    -1,    -1,    -1,    -1,    -1,
      -1,   412,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   420,
      -1,    71,    72,    73,    74,    75,    76,    77,    78,   430,
      80,    81,    -1,    -1,    -1,    -1,    86,    87,   850,   851,
      -1,    -1,    -1,    -1,    -1,    -1,   858,    -1,    -1,    -1,
     862,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     461,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   470,
      -1,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,    -1,    -1,    -1,    -1,   713,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   721,   722,    -1,    -1,    -1,    -1,    -1,
     728,    -1,    -1,    -1,    -1,    -1,   734,   735,   920,    -1,
      -1,    -1,   740,   741,   926,    -1,   928,    -1,    -1,   931,
      -1,    -1,   750,   524,    -1,    -1,    -1,    -1,    -1,   757,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   769,   770,    -1,    -1,    -1,    -1,    -1,    -1,   777,
       0,     1,    -1,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,   791,   792,    -1,    -1,    -1,    -1,    19,
      -1,    21,    22,    23,    24,    -1,    -1,    -1,    -1,    -1,
      30,    31,    32,    33,    34,    35,    36,    -1,    -1,    39,
      -1,    -1,    -1,    -1,    -1,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    -1,    58,    59,
      60,    -1,   840,    63,    -1,   616,    66,    67,    -1,    69,
      70,    -1,   850,   851,    -1,    -1,    -1,    -1,    -1,    -1,
     858,    -1,    -1,    -1,   862,    -1,    -1,    -1,    -1,    89,
      -1,    -1,    92,    93,    -1,    95,    96,    -1,    98,    -1,
      -1,   101,    -1,   103,   104,   105,   106,   107,   108,    -1,
      -1,   111,   112,    -1,    -1,   115,   116,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   131,   132,   133,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   920,   143,    -1,   145,    -1,    -1,   926,    -1,
     928,    -1,    -1,   931,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   713,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     721,   722,    -1,    -1,    -1,    -1,    -1,   728,    -1,    -1,
      -1,    -1,    -1,   734,   735,    -1,    -1,    -1,    -1,   740,
     741,    -1,    -1,    -1,     0,    -1,    -1,    -1,    -1,   750,
      -1,    -1,    -1,    -1,    -1,    -1,   757,    13,    14,    15,
      16,    17,    18,    -1,    20,    -1,    -1,    -1,   769,   770,
      -1,    27,    28,    -1,    -1,    -1,   777,    -1,    -1,    -1,
      -1,    37,    38,    -1,    40,    41,    42,    43,    44,    -1,
     791,   792,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    57,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    -1,    -1,
      86,    87,    88,    -1,    90,    91,    -1,    -1,    -1,   840,
      -1,    97,    -1,    -1,    -1,    -1,   102,    -1,    -1,   850,
     851,    -1,    -1,    -1,    -1,    -1,   112,    -1,    -1,   115,
     116,   862,   118,   119,    -1,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,    -1,    -1,    -1,    -1,    -1,
     136,   137,   138,    -1,    -1,   141,   142,   143,   144,   145,
      -1,    -1,    -1,    -1,     0,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    13,    14,    15,
      16,    17,    18,    -1,    20,    -1,    -1,    -1,    -1,   920,
      -1,    27,    28,    -1,    -1,   926,    -1,   928,    -1,    -1,
     931,    37,    38,    -1,    40,    41,    42,    43,    44,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    -1,    -1,
      86,    87,    88,    -1,    -1,    91,    -1,    -1,    -1,    -1,
      -1,    97,    -1,    -1,    -1,    -1,   102,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   112,    -1,    -1,   115,
     116,    -1,    -1,   119,    -1,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,    -1,    -1,     0,    -1,    -1,
     136,   137,   138,    -1,   140,   141,   142,   143,   144,   145,
      13,    14,    15,    -1,    17,    18,    -1,    20,    -1,    -1,
      -1,    -1,    -1,    26,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    37,    38,    -1,    40,    41,    42,
      43,    44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    -1,    -1,    86,    87,    88,    -1,    90,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   102,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   112,
      -1,    -1,   115,   116,    -1,   118,   119,    -1,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,    -1,    -1,
       0,    -1,   135,   136,   137,   138,    -1,    -1,   141,    -1,
     143,   144,   145,    13,    14,    15,    -1,    17,    18,    -1,
      20,    -1,    -1,    -1,    -1,    -1,    26,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,    38,    -1,
      40,    41,    42,    43,    44,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    -1,    -1,    86,    87,    88,    -1,
      90,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   102,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   112,    -1,    -1,   115,   116,    -1,   118,   119,
      -1,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,    -1,    -1,     0,    -1,   135,   136,   137,   138,    -1,
      -1,   141,    -1,   143,   144,   145,    13,    14,    15,    -1,
      17,    18,    -1,    20,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      37,    38,    -1,    40,    41,    42,    43,    44,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    -1,    -1,    86,
      87,    88,    -1,    90,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   102,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   112,    -1,    -1,   115,   116,
      -1,   118,   119,    -1,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,    -1,    -1,     0,    -1,    -1,   136,
     137,   138,    -1,    -1,   141,    -1,   143,   144,   145,    13,
      14,    15,    16,    17,    18,    -1,    20,    -1,    -1,    -1,
      -1,    -1,    26,    27,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    37,    38,    -1,    40,    41,    42,    43,
      44,    -1,    -1,    -1,    -1,    51,    52,    -1,    -1,    55,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    -1,    80,    81,    -1,    -1,    84,    85,
      86,    87,    -1,    -1,    88,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    98,    99,    -1,    -1,    -1,    -1,   102,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   112,    -1,
      -1,   115,   116,    -1,    -1,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,    -1,   132,   133,    -1,    -1,
      -1,   135,   136,   139,   140,    -1,   140,   141,    -1,   143,
     144,   145,     1,    -1,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    -1,    -1,    18,
      19,    -1,    21,    22,    23,    24,    -1,    -1,    -1,    -1,
      -1,    30,    31,    32,    33,    34,    35,    36,    -1,    -1,
      39,    -1,    -1,    -1,    -1,    -1,    45,    -1,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    -1,    58,
      59,    60,    -1,    -1,    63,    -1,    -1,    66,    67,    -1,
      69,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      89,    -1,    -1,    92,    93,    -1,    95,    96,    -1,    98,
      -1,    -1,   101,    -1,   103,   104,   105,   106,   107,   108,
      -1,    -1,   111,   112,    -1,    -1,   115,   116,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   131,   132,   133,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   143,     1,   145,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    -1,    -1,    15,
      -1,    17,    18,    19,    -1,    21,    22,    23,    24,    -1,
      -1,    -1,    -1,    -1,    30,    31,    32,    33,    34,    35,
      36,    -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    45,
      -1,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    -1,    58,    59,    60,    -1,    -1,    63,    -1,    -1,
      66,    67,    -1,    69,    70,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    89,    -1,    -1,    92,    93,    -1,    95,
      96,    -1,    98,    -1,    -1,   101,    -1,   103,   104,   105,
     106,   107,   108,    -1,    -1,   111,   112,    -1,    -1,   115,
     116,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   131,   132,   133,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   143,     1,   145,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      -1,    -1,    15,    -1,    -1,    18,    19,    20,    21,    22,
      23,    24,    -1,    -1,    -1,    -1,    -1,    30,    31,    32,
      33,    34,    35,    36,    -1,    -1,    39,    -1,    -1,    -1,
      -1,    -1,    45,    -1,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    -1,    58,    59,    60,    -1,    -1,
      63,    -1,    -1,    66,    67,    -1,    69,    70,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    89,    -1,    -1,    92,
      93,    -1,    95,    96,    -1,    98,    -1,    -1,   101,    -1,
     103,   104,   105,   106,   107,   108,    -1,    -1,   111,   112,
      -1,    -1,   115,   116,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   131,   132,
     133,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     143,     1,   145,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    -1,    -1,    15,    -1,    -1,    18,    19,
      -1,    21,    22,    23,    24,    -1,    -1,    -1,    -1,    -1,
      30,    31,    32,    33,    34,    35,    36,    -1,    -1,    39,
      -1,    -1,    -1,    -1,    -1,    45,    -1,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    -1,    58,    59,
      60,    -1,    -1,    63,    -1,    -1,    66,    67,    -1,    69,
      70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,
      -1,    -1,    92,    93,    -1,    95,    96,    -1,    98,    -1,
      -1,   101,    -1,   103,   104,   105,   106,   107,   108,    -1,
      -1,   111,   112,    -1,    -1,   115,   116,     1,    -1,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    -1,
      -1,   131,   132,   133,    -1,    19,    -1,    21,    22,    23,
      24,    -1,    -1,   143,    -1,   145,    30,    31,    32,    33,
      34,    35,    36,    -1,    -1,    39,    -1,    -1,    -1,    -1,
      -1,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    -1,    58,    59,    60,    -1,    -1,    63,
      -1,    -1,    66,    67,    -1,    69,    70,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    89,    -1,    -1,    92,    93,
      -1,    95,    96,    -1,    98,    -1,    -1,   101,    -1,   103,
     104,   105,   106,   107,   108,    -1,    -1,   111,   112,    -1,
      -1,   115,   116,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   131,   132,   133,
      -1,    -1,   136,    -1,    -1,    -1,    -1,    -1,    -1,   143,
       1,   145,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    -1,    14,    15,    -1,    -1,    -1,    19,    -1,
      21,    22,    23,    24,    -1,    -1,    -1,    -1,    -1,    30,
      31,    32,    33,    34,    35,    36,    -1,    -1,    39,    -1,
      -1,    -1,    -1,    -1,    45,    -1,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    -1,    58,    59,    60,
      -1,    -1,    63,    -1,    -1,    66,    67,    -1,    69,    70,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,    -1,
      -1,    92,    93,    -1,    95,    96,    -1,    98,    -1,    -1,
     101,    -1,   103,   104,   105,   106,   107,   108,    -1,    -1,
     111,   112,    -1,    -1,   115,   116,     1,    -1,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    -1,    -1,
     131,   132,   133,    -1,    19,    -1,    21,    22,    23,    24,
      -1,    -1,   143,    -1,   145,    30,    31,    32,    33,    34,
      35,    36,    -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,
      45,    -1,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    -1,    58,    59,    60,    -1,    -1,    63,    -1,
      -1,    66,    67,    -1,    69,    70,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    89,    -1,    -1,    92,    93,    -1,
      95,    96,    -1,    98,    -1,    -1,   101,    -1,   103,   104,
     105,   106,   107,   108,    -1,    -1,   111,   112,    -1,    -1,
     115,   116,     1,    -1,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    -1,    -1,   131,   132,   133,    -1,
      19,    -1,    21,    22,    23,    24,   141,    -1,   143,    -1,
     145,    30,    31,    32,    33,    34,    35,    36,    -1,    -1,
      39,    -1,    -1,    -1,    -1,    -1,    45,    -1,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    -1,    58,
      59,    60,    -1,    -1,    63,    -1,    -1,    66,    67,    -1,
      69,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      89,    -1,    -1,    92,    93,    -1,    95,    96,    -1,    98,
      -1,    -1,   101,    -1,   103,   104,   105,   106,   107,   108,
      -1,    -1,   111,   112,    -1,    -1,   115,   116,     1,    -1,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      -1,    -1,   131,   132,   133,    -1,    19,    -1,    21,    22,
      23,    24,   141,    -1,   143,    -1,   145,    30,    31,    32,
      33,    34,    35,    36,    -1,    -1,    39,    -1,    -1,    -1,
      -1,    -1,    45,    -1,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    -1,    58,    59,    60,    -1,    -1,
      63,    -1,    -1,    66,    67,    -1,    69,    70,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    89,    -1,    -1,    92,
      93,    -1,    95,    96,    -1,    98,    -1,    -1,   101,    -1,
     103,   104,   105,   106,   107,   108,    -1,    -1,   111,   112,
      -1,    -1,   115,   116,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   131,   132,
     133,    -1,    -1,   136,    -1,    -1,    -1,    -1,    -1,    -1,
     143,     1,   145,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    -1,    -1,    15,    -1,    -1,    -1,    19,
      -1,    21,    22,    23,    24,    -1,    -1,    -1,    -1,    -1,
      30,    31,    32,    33,    34,    35,    36,    -1,    -1,    39,
      -1,    -1,    -1,    -1,    -1,    45,    -1,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    -1,    58,    59,
      60,    -1,    -1,    63,    -1,    -1,    66,    67,    -1,    69,
      70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,
      -1,    -1,    92,    93,    -1,    95,    96,    -1,    98,    -1,
      -1,   101,    -1,   103,   104,   105,   106,   107,   108,    -1,
      -1,   111,   112,    -1,    -1,   115,   116,    -1,    -1,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    -1,
      -1,   131,   132,   133,    -1,    19,    -1,    21,    22,    23,
      24,    -1,    -1,   143,    -1,   145,    30,    31,    32,    33,
      34,    35,    36,    -1,    -1,    39,    -1,    -1,    -1,    -1,
      -1,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    -1,    58,    59,    60,    -1,    -1,    63,
      -1,    -1,    66,    67,    -1,    69,    70,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    89,    -1,    -1,    92,    93,
      -1,    95,    96,    -1,    98,    -1,    -1,   101,    -1,   103,
     104,   105,   106,   107,   108,    -1,    -1,   111,   112,    -1,
      -1,   115,   116,    -1,    -1,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    -1,    -1,   131,   132,   133,
      -1,    19,    -1,    21,    22,    23,    24,    -1,    -1,   143,
      -1,   145,    30,    31,    32,    33,    34,    35,    36,    -1,
      -1,    39,    -1,    -1,    -1,    -1,    -1,    45,    -1,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    -1,
      58,    59,    60,    -1,    -1,    63,    -1,    -1,    66,    67,
      -1,    69,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    89,    -1,    -1,    92,    93,    -1,    95,    96,    -1,
      98,    -1,    -1,   101,    -1,   103,   104,   105,   106,   107,
     108,    -1,    -1,   111,   112,    -1,    -1,   115,   116,    -1,
      -1,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      -1,    -1,    -1,   131,   132,   133,    -1,    19,    -1,    21,
      22,    23,    24,    -1,    -1,   143,    -1,   145,    30,    31,
      32,    33,    34,    35,    36,    -1,    -1,    39,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    -1,    58,    59,    60,    -1,
      -1,    63,    -1,    -1,    66,    67,    -1,    69,    70,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,    -1,    -1,
      92,    93,    -1,    95,    96,    -1,    -1,    -1,    -1,   101,
      -1,   103,   104,   105,   106,   107,   108,    -1,    -1,   111,
     112,    -1,    -1,   115,   116,    -1,    -1,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    -1,    -1,    -1,   131,
     132,   133,    -1,    19,    -1,    21,    22,    23,    24,    -1,
      -1,   143,    -1,   145,    30,    31,    32,    33,    34,    35,
      36,    -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    -1,    58,    59,    60,    -1,    -1,    63,    -1,    -1,
      66,    67,    -1,    69,    70,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    89,    -1,    -1,    92,    93,    -1,    95,
      96,    -1,    -1,    -1,    -1,   101,    -1,   103,   104,   105,
     106,   107,   108,    -1,    -1,   111,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   131,   132,   133,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   145,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    -1,    -1,    -1,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    -1,    -1,    -1,
      -1,    -1,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,    80,    81,    -1,
      -1,    84,    85,    86,    87,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    98,    99,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,    -1,   132,
     133,    -1,    -1,    -1,    -1,    -1,   139,   140,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    19,    -1,    21,    22,    23,    24,
      -1,    26,    -1,    -1,    -1,    30,    31,    32,    33,    34,
      35,    36,    -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    -1,    58,    59,    60,    -1,    -1,    63,    -1,
      -1,    66,    67,    -1,    69,    70,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    89,    -1,    -1,    92,    93,    -1,
      95,    96,    -1,    98,    99,   100,   101,    -1,   103,   104,
     105,   106,   107,   108,    -1,    -1,   111,    -1,    -1,    -1,
      -1,    -1,    -1,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    -1,    -1,    -1,    -1,   131,   132,   133,    19,
     135,    21,    22,    23,    24,   140,    26,    -1,    -1,    -1,
      30,    31,    32,    33,    34,    35,    36,    -1,    -1,    39,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    -1,    58,    59,
      60,    -1,    -1,    63,    -1,    -1,    66,    67,    -1,    69,
      70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,
      -1,    -1,    92,    93,    -1,    95,    96,    -1,    98,    99,
     100,   101,    -1,   103,   104,   105,   106,   107,   108,    -1,
      -1,   111,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    -1,    -1,    -1,
      -1,   131,   132,   133,    19,   135,    21,    22,    23,    24,
     140,    26,    -1,    -1,    -1,    30,    31,    32,    33,    34,
      35,    36,    -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    -1,    58,    59,    60,    -1,    -1,    63,    -1,
      -1,    66,    67,    -1,    69,    70,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    89,    -1,    -1,    92,    93,    -1,
      95,    96,    -1,    98,    99,   100,   101,    -1,   103,   104,
     105,   106,   107,   108,    -1,    -1,   111,    -1,    -1,    -1,
      -1,    -1,    -1,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    -1,    -1,    -1,    -1,   131,   132,   133,    19,
     135,    21,    22,    23,    24,   140,    -1,    -1,    -1,    -1,
      30,    31,    32,    33,    34,    35,    36,    -1,    -1,    39,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    -1,    58,    59,
      60,    -1,    -1,    63,    -1,    -1,    66,    67,    -1,    69,
      70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,
      90,    -1,    92,    93,    -1,    95,    96,    -1,    98,    99,
     100,   101,    -1,   103,   104,   105,   106,   107,   108,    -1,
      -1,   111,    -1,    -1,    -1,    -1,    -1,    -1,   118,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   131,   132,   133,    -1,    -1,    -1,    -1,    -1,    -1,
     140,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    19,    -1,    21,
      22,    23,    24,    -1,    -1,    -1,    -1,    -1,    30,    31,
      32,    33,    34,    35,    36,    -1,    -1,    39,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    -1,    58,    59,    60,    -1,
      -1,    63,    -1,    -1,    66,    67,    -1,    69,    70,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,    90,    -1,
      92,    93,    -1,    95,    96,    -1,    98,    99,   100,   101,
      -1,   103,   104,   105,   106,   107,   108,    -1,    -1,   111,
      -1,    -1,    -1,    -1,    -1,    -1,   118,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   131,
     132,   133,    -1,    -1,    -1,    -1,    -1,    -1,   140,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    19,    -1,    21,    22,    23,
      24,    -1,    -1,    -1,    -1,    -1,    30,    31,    32,    33,
      34,    35,    36,    -1,    -1,    39,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    -1,    58,    59,    60,    -1,    -1,    63,
      -1,    -1,    66,    67,    -1,    69,    70,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    89,    -1,    -1,    92,    93,
      -1,    95,    96,    -1,    98,    99,   100,   101,    -1,   103,
     104,   105,   106,   107,   108,    -1,    -1,   111,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    -1,    -1,    -1,    -1,   131,   132,   133,
      19,    -1,    21,    22,    23,    24,   140,    -1,    -1,    -1,
      -1,    30,    31,    32,    33,    34,    35,    36,    -1,    -1,
      39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    -1,    58,
      59,    60,    -1,    -1,    63,    -1,    -1,    66,    67,    -1,
      69,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      89,    -1,    -1,    92,    93,    -1,    95,    96,    -1,    98,
      99,   100,   101,    -1,   103,   104,   105,   106,   107,   108,
      -1,    -1,   111,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    -1,    -1,
      -1,    -1,   131,   132,   133,    19,    -1,    21,    22,    23,
      24,   140,    -1,    -1,    -1,    -1,    30,    31,    32,    33,
      34,    35,    36,    -1,    -1,    39,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    -1,    58,    59,    60,    -1,    -1,    63,
      -1,    -1,    66,    67,    -1,    69,    70,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    89,    -1,    -1,    92,    93,
      -1,    95,    96,    -1,    98,    99,   100,   101,    -1,   103,
     104,   105,   106,   107,   108,    -1,    -1,   111,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   131,   132,   133,
      -1,    -1,    -1,    -1,    -1,    -1,   140,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    -1,    -1,    -1,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    -1,    -1,    -1,    -1,    -1,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    -1,    -1,    -1,    -1,    -1,    -1,    63,    -1,    -1,
      -1,    -1,    -1,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    -1,    80,    81,    -1,    -1,    84,    85,
      86,    87,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    98,    99,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   107,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,    -1,   132,   133,    -1,    -1,
      -1,    -1,    -1,   139,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    -1,    -1,
      -1,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    -1,    -1,
      -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    80,    81,    -1,    -1,    84,    85,    86,    87,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    98,
      99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   107,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,    -1,   132,   133,    -1,    -1,    -1,    -1,    -1,
     139,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    -1,    -1,    -1,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    -1,    -1,
      -1,    -1,    -1,    45,    46,    47,    48,    49,    50,    51,
      52,    -1,    -1,    55,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,    80,    81,
      -1,    -1,    84,    85,    86,    87,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    98,    99,    -1,    -1,
      -1,   103,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,    -1,
     132,   133,    -1,    -1,    -1,    -1,    -1,   139,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    -1,    -1,    -1,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    -1,    -1,    -1,    -1,    -1,
      45,    46,    47,    48,    49,    50,    51,    52,    -1,    -1,
      55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    -1,    80,    81,    -1,    -1,    84,
      85,    86,    87,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    98,    99,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,    -1,   132,   133,    -1,
      -1,    -1,    -1,    -1,   139,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    19,    -1,    21,    22,    23,    24,    -1,    -1,    -1,
      -1,    -1,    30,    31,    32,    33,    34,    35,    36,    -1,
      -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    -1,
      58,    59,    60,    -1,    -1,    63,    -1,    -1,    66,    67,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    89,    -1,    -1,    92,    93,    -1,    95,    96,    -1,
      -1,    -1,    -1,   101,    -1,   103,   104,   105,   106,   107,
     108,    -1,    -1,   111,    -1,    -1,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    19,   131,    21,    22,    23,    24,    -1,    -1,
     138,    -1,    -1,    30,    31,    32,    33,    34,    35,    36,
      -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      -1,    58,    59,    60,    -1,    -1,    63,    -1,    -1,    66,
      67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    89,    -1,    -1,    92,    93,    -1,    95,    96,
      -1,    -1,    -1,    -1,   101,    -1,   103,   104,   105,   106,
     107,   108,    -1,    -1,   111,    -1,    -1,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    -1,    -1,    -1,
      -1,    -1,    -1,    19,   131,    21,    22,    23,    24,    -1,
      -1,   138,    -1,    -1,    30,    31,    32,    33,    34,    35,
      36,    -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    -1,    58,    59,    60,    -1,    -1,    63,    -1,    -1,
      66,    67,    -1,    69,    70,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    89,    -1,    -1,    92,    93,    -1,    95,
      96,    -1,    98,    -1,    -1,   101,    -1,   103,   104,   105,
     106,   107,   108,    -1,    -1,   111,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    -1,    -1,    -1,    -1,   131,   132,   133,    19,    -1,
      21,    22,    23,    24,    -1,    -1,    -1,    -1,    -1,    30,
      31,    32,    33,    34,    35,    36,    -1,    -1,    39,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    -1,    58,    59,    60,
      -1,    -1,    63,    -1,    -1,    66,    67,    -1,    69,    70,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,    -1,
      -1,    92,    93,    -1,    95,    96,    -1,    -1,    99,   100,
     101,    -1,   103,   104,   105,   106,   107,   108,    -1,    -1,
     111,   112,    -1,    -1,   115,   116,    -1,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    -1,    -1,    -1,
     131,   132,   133,    19,    -1,    21,    22,    23,    24,    -1,
      -1,    -1,    -1,    -1,    30,    31,    32,    33,    34,    35,
      36,    -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    45,
      -1,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    -1,    58,    59,    60,    -1,    -1,    63,    -1,    -1,
      66,    67,    -1,    69,    70,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    89,    -1,    -1,    92,    93,    -1,    95,
      96,    -1,    98,    -1,    -1,   101,    -1,   103,   104,   105,
     106,   107,   108,    -1,    -1,   111,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    -1,    -1,    -1,    -1,   131,   132,   133,    19,    -1,
      21,    22,    23,    24,    -1,    -1,    -1,    -1,    -1,    30,
      31,    32,    33,    34,    35,    36,    -1,    -1,    39,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    -1,    58,    59,    60,
      -1,    -1,    63,    -1,    -1,    66,    67,    -1,    69,    70,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,    -1,
      -1,    92,    93,    -1,    95,    96,    -1,    -1,    99,    -1,
     101,    -1,   103,   104,   105,   106,   107,   108,    -1,    -1,
     111,   112,    -1,    -1,   115,   116,    -1,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,
     131,   132,   133,    19,    -1,    21,    22,    23,    24,    -1,
      -1,    -1,    -1,    -1,    30,    31,    32,    33,    34,    35,
      36,    -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    -1,    58,    59,    60,    -1,    -1,    63,    -1,    -1,
      66,    67,    -1,    69,    70,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    89,    -1,    -1,    92,    93,    -1,    95,
      96,    -1,    98,    99,   100,   101,    -1,   103,   104,   105,
     106,   107,   108,    -1,    -1,   111,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    -1,    -1,    -1,    -1,   131,   132,   133,    19,    -1,
      21,    22,    23,    24,    -1,    -1,    -1,    -1,    -1,    30,
      31,    32,    33,    34,    35,    36,    -1,    -1,    39,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    -1,    58,    59,    60,
      -1,    -1,    63,    -1,    -1,    66,    67,    -1,    69,    70,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,    -1,
      -1,    92,    93,    -1,    95,    96,    -1,    98,    99,   100,
     101,    -1,   103,   104,   105,   106,   107,   108,    -1,    -1,
     111,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,
     131,   132,   133,    19,    -1,    21,    22,    23,    24,    -1,
      -1,    -1,    -1,    -1,    30,    31,    32,    33,    34,    35,
      36,    -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    -1,    58,    59,    60,    -1,    -1,    63,    -1,    -1,
      66,    67,    -1,    69,    70,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    89,    -1,    -1,    92,    93,    -1,    95,
      96,    -1,    98,    99,    -1,   101,    -1,   103,   104,   105,
     106,   107,   108,    -1,    -1,   111,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    -1,    -1,    -1,    -1,   131,   132,   133,    19,    -1,
      21,    22,    23,    24,    -1,    -1,    -1,    -1,    -1,    30,
      31,    32,    33,    34,    35,    36,    -1,    -1,    39,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    -1,    58,    59,    60,
      -1,    -1,    63,    -1,    -1,    66,    67,    -1,    69,    70,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,    -1,
      -1,    92,    93,    -1,    95,    96,    -1,    98,    99,    -1,
     101,    -1,   103,   104,   105,   106,   107,   108,    -1,    -1,
     111,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,
     131,   132,   133,    19,    -1,    21,    22,    23,    24,    -1,
      -1,    -1,    -1,    -1,    30,    31,    32,    33,    34,    35,
      36,    -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    -1,    58,    59,    60,    -1,    -1,    63,    -1,    -1,
      66,    67,    -1,    69,    70,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    89,    -1,    -1,    92,    93,    -1,    95,
      96,    -1,    -1,    99,    -1,   101,    -1,   103,   104,   105,
     106,   107,   108,    -1,    -1,   111,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    -1,    -1,    -1,    -1,   131,   132,   133,    19,    -1,
      21,    22,    23,    24,    -1,    -1,    -1,    -1,    -1,    30,
      31,    32,    33,    34,    35,    36,    -1,    -1,    39,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    -1,    58,    59,    60,
      -1,    -1,    63,    -1,    -1,    66,    67,    -1,    69,    70,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,    -1,
      -1,    92,    93,    -1,    95,    96,    -1,    98,    -1,    -1,
     101,    -1,   103,   104,   105,   106,   107,   108,    -1,    -1,
     111,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,
     131,   132,   133,    19,    -1,    21,    22,    23,    24,    -1,
      -1,    -1,    -1,    -1,    30,    31,    32,    33,    34,    35,
      36,    -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    -1,    58,    59,    60,    -1,    -1,    63,    -1,    -1,
      66,    67,    -1,    69,    70,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    89,    -1,    -1,    92,    93,    -1,    95,
      96,    -1,    98,    -1,    -1,   101,    -1,   103,   104,   105,
     106,   107,   108,    -1,    -1,   111,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    -1,    -1,    -1,    -1,   131,   132,   133,    19,    -1,
      21,    22,    23,    24,    -1,    -1,    -1,    -1,    -1,    30,
      31,    32,    33,    34,    35,    36,    -1,    -1,    39,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    -1,    58,    59,    60,
      -1,    -1,    63,    -1,    -1,    66,    67,    -1,    69,    70,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,    -1,
      -1,    92,    93,    -1,    95,    96,    -1,    98,    -1,    -1,
     101,    -1,   103,   104,   105,   106,   107,   108,    -1,    -1,
     111,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,
     131,   132,   133,    19,    -1,    21,    22,    23,    24,    -1,
      -1,    -1,    -1,    -1,    30,    31,    32,    33,    34,    35,
      36,    -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    -1,    58,    59,    60,    -1,    -1,    63,    -1,    -1,
      66,    67,    -1,    69,    70,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    89,    -1,    -1,    92,    93,    -1,    95,
      96,    -1,    98,    -1,    -1,   101,    -1,   103,   104,   105,
     106,   107,   108,    -1,    -1,   111,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    -1,    -1,    -1,    -1,   131,   132,   133,    19,    -1,
      21,    22,    23,    24,    -1,    -1,    -1,    -1,    -1,    30,
      31,    32,    33,    34,    35,    36,    -1,    -1,    39,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    -1,    58,    59,    60,
      -1,    -1,    63,    -1,    -1,    66,    67,    -1,    69,    70,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,    -1,
      -1,    92,    93,    -1,    95,    96,    -1,    98,    -1,    -1,
     101,    -1,   103,   104,   105,   106,   107,   108,    -1,    -1,
     111,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,
     131,   132,   133,    19,    -1,    21,    22,    23,    24,    -1,
      -1,    -1,    -1,    -1,    30,    31,    32,    33,    34,    35,
      36,    -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    -1,    58,    59,    60,    -1,    -1,    63,    -1,    -1,
      66,    67,    -1,    69,    70,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    89,    -1,    -1,    92,    93,    -1,    95,
      96,    -1,    -1,    -1,    -1,   101,    -1,   103,   104,   105,
     106,   107,   108,    -1,    -1,   111,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    -1,    -1,    -1,    -1,   131,   132,   133,    19,    -1,
      21,    22,    23,    24,    -1,    -1,    -1,    -1,    -1,    30,
      31,    32,    33,    34,    35,    36,    -1,    -1,    39,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    -1,    58,    59,    60,
      -1,    -1,    63,    -1,    -1,    66,    67,    -1,    69,    70,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,    -1,
      -1,    92,    93,    -1,    95,    96,    -1,    -1,    -1,    -1,
     101,    -1,   103,   104,   105,   106,   107,   108,    -1,    -1,
     111,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,
     131,   132,   133,    19,    -1,    21,    22,    23,    24,    -1,
      -1,    -1,    -1,    -1,    30,    31,    32,    33,    34,    35,
      36,    -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    -1,    58,    59,    60,    -1,    -1,    63,    -1,    -1,
      66,    67,    -1,    69,    70,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    89,    -1,    -1,    92,    93,    -1,    95,
      96,    -1,    -1,    -1,    -1,   101,    -1,   103,   104,   105,
     106,   107,   108,    -1,    -1,   111,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    -1,    -1,    -1,    -1,   131,   132,   133,    19,    -1,
      21,    22,    23,    24,    -1,    -1,    -1,    -1,    -1,    30,
      31,    32,    33,    34,    35,    36,    -1,    -1,    39,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    -1,    58,    59,    60,
      -1,    -1,    63,    -1,    -1,    66,    67,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    86,    -1,    -1,    89,    -1,
      -1,    92,    93,    -1,    95,    96,    -1,    -1,    -1,    -1,
     101,    -1,   103,   104,   105,   106,   107,   108,    -1,    -1,
     111,    -1,    -1,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    19,
     131,    21,    22,    23,    24,    -1,    -1,    -1,    -1,    -1,
      30,    31,    32,    33,    34,    35,    36,    -1,    -1,    39,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    -1,    58,    59,
      60,    -1,    -1,    63,    -1,    -1,    66,    67,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,
      -1,    -1,    92,    93,    -1,    95,    96,    -1,    98,    -1,
      -1,   101,    -1,   103,   104,   105,   106,   107,   108,    -1,
      -1,   111,    -1,    -1,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      19,   131,    21,    22,    23,    24,    -1,    -1,    -1,    -1,
      -1,    30,    31,    32,    33,    34,    35,    36,    -1,    -1,
      39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    -1,    58,
      59,    60,    -1,    -1,    63,    -1,    -1,    66,    67,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      89,    -1,    -1,    92,    93,    -1,    95,    96,    -1,    98,
      -1,    -1,   101,    -1,   103,   104,   105,   106,   107,   108,
      -1,    -1,   111,    -1,    -1,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    19,   131,    21,    22,    23,    24,    -1,    -1,    -1,
      -1,    -1,    30,    31,    32,    33,    34,    35,    36,    -1,
      -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    -1,
      58,    59,    60,    -1,    -1,    63,    -1,    -1,    66,    67,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    89,    -1,    -1,    92,    93,    -1,    95,    96,    -1,
      -1,    -1,    -1,   101,    -1,   103,   104,   105,   106,   107,
     108,    -1,    -1,   111,    -1,    -1,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    19,   131,    21,    22,    23,    24,    -1,    -1,
      -1,    -1,    -1,    30,    31,    32,    33,    34,    35,    36,
      -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      -1,    58,    59,    60,    -1,    -1,    63,    -1,    -1,    66,
      67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    89,    -1,    -1,    92,    93,    -1,    95,    96,
      -1,    -1,    -1,    -1,   101,    -1,   103,   104,   105,   106,
     107,   108,    -1,    -1,   111,    -1,    -1,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    19,   131,    21,    22,    23,    24,    -1,
      -1,    -1,    -1,    -1,    30,    31,    32,    33,    34,    35,
      36,    -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    -1,    58,    59,    60,    -1,    -1,    63,    -1,    -1,
      66,    67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    89,    -1,    -1,    92,    93,    -1,    95,
      96,    -1,    -1,    -1,    -1,   101,    -1,   103,   104,   105,
     106,   107,   108,    -1,    -1,   111,    -1,    -1,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    19,   131,    21,    22,    23,    24,
      -1,    -1,    -1,    -1,    -1,    30,    31,    32,    33,    34,
      35,    36,    -1,    -1,    39,    -1,    -1,    44,    -1,    -1,
      -1,    -1,    -1,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    -1,    58,    59,    60,    -1,    -1,    63,    -1,
      -1,    66,    67,    -1,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    -1,    -1,    86,
      87,    -1,    -1,    -1,    89,    -1,    -1,    92,    93,    -1,
      95,    96,    -1,    -1,    -1,    -1,   101,    -1,   103,   104,
     105,   106,   107,   108,    -1,    -1,   111,    -1,    -1,    51,
      52,    -1,   119,    55,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,    -1,    -1,   131,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,    80,    81,
      -1,    -1,    84,    85,    86,    87,    -1,    -1,    -1,    71,
      72,    73,    74,    75,    76,    77,    98,    99,    80,    81,
      -1,    -1,    -1,    -1,    86,    87,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,    -1,
     132,   133,    51,    52,    -1,    -1,    55,   139,   140,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,    -1,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    80,    81,    -1,    -1,    84,    85,    86,    87,    -1,
      -1,    -1,    71,    72,    73,    74,    75,    76,    77,    98,
      99,    80,    81,    -1,    -1,    -1,    -1,    86,    87,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,    -1,   132,   133,    51,    52,    -1,    -1,    55,
     139,   140,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,    -1,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    -1,    80,    81,    -1,    -1,    84,    85,
      86,    87,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    98,    99,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,    -1,   132,   133,    51,    52,
      -1,    -1,    55,   139,   140,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,    80,    81,    -1,
      -1,    84,    85,    86,    87,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    98,    99,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,    -1,   132,
     133,    51,    52,    -1,    -1,    55,   139,   140,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
      80,    81,    -1,    -1,    84,    85,    86,    87,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    98,    99,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,    -1,   132,   133,    51,    52,    -1,    -1,    55,   139,
     140,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,    -1,    80,    81,    -1,    -1,    84,    85,    86,
      87,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    98,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,    -1,   132,   133,    51,    52,    -1,
      -1,    55,   139,   140,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    -1,    80,    81,    -1,    -1,
      84,    85,    86,    87,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    98,    99,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,    -1,   132,   133,
      51,    52,    -1,    -1,    55,   139,   140,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,    80,
      81,    -1,    -1,    84,    85,    86,    87,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    98,    99,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
      -1,   132,   133,    51,    52,    -1,    -1,    55,   139,   140,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    -1,    80,    81,    -1,    -1,    84,    85,    86,    87,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      98,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,    -1,   132,   133,    51,    52,    -1,    -1,
      55,   139,   140,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    -1,    80,    81,    -1,    -1,    84,
      85,    86,    87,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    98,    99,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,    -1,   132,   133,    51,
      52,    -1,    -1,    55,   139,   140,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,    80,    81,
      -1,    -1,    84,    85,    86,    87,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    98,    99,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,    -1,
     132,   133,    51,    52,    -1,    -1,    55,   139,   140,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    80,    81,    -1,    -1,    84,    85,    86,    87,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    98,
      99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,    -1,   132,   133,    51,    52,    -1,    -1,    55,
     139,   140,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    -1,    80,    81,    -1,    -1,    84,    85,
      86,    87,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    98,    99,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,    -1,   132,   133,    51,    52,
      -1,    -1,    55,   139,   140,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,    80,    81,    -1,
      -1,    84,    85,    86,    87,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    98,    99,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      -1,    -1,    86,    87,    -1,    -1,    -1,    -1,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,    -1,   132,
     133,    -1,    -1,    -1,    -1,    -1,   139,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   119,    -1,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      -1,   145,    86,    87,    -1,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    -1,    -1,
      86,    87,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   119,    -1,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,    -1,    -1,    -1,
      -1,    -1,    -1,   119,   138,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   138,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    -1,    -1,    86,    87,
      -1,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    -1,    -1,    86,    87,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   119,    -1,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,    -1,    -1,    -1,    -1,    -1,    -1,   119,
     138,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    -1,    -1,    86,    87,    -1,    -1,    -1,    91,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    -1,    -1,    86,    87,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   119,    -1,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   119,    -1,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   147,   148,     0,     1,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    19,    21,    22,    23,    24,
      30,    31,    32,    33,    34,    35,    36,    39,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      58,    59,    60,    63,    66,    67,    69,    70,    89,    92,
      93,    95,    96,    98,   101,   103,   104,   105,   106,   107,
     108,   111,   131,   132,   133,   149,   150,   151,   156,   158,
     160,   162,   163,   166,   167,   169,   170,   171,   173,   174,
     183,   197,   218,   238,   239,   249,   250,   254,   255,   256,
     262,   263,   264,   266,   267,   268,   269,   270,   271,   305,
     319,   151,    21,    22,    30,    31,    32,    39,    51,    55,
      86,    89,    92,   131,   175,   176,   197,   218,   268,   271,
     305,   176,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    45,    46,    47,    48,
      49,    50,    51,    52,    55,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    80,    81,    84,    85,    86,    87,
      98,    99,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   132,   133,   139,   140,   177,   181,   182,   270,
     300,   198,    89,   160,   161,   174,   218,   268,   269,   271,
     161,   204,   206,    89,   167,   174,   218,   223,   268,   271,
      33,    34,    35,    36,    48,    49,    50,    51,    55,   103,
     177,   178,   179,   264,   112,   115,   116,   143,   145,   161,
     258,   259,   260,   311,   316,   317,   318,    51,    98,    99,
     100,   132,   166,   183,   189,   192,   195,   250,   303,   304,
     189,   189,   140,   186,   187,   190,   191,   319,   186,   190,
     140,   312,   317,   178,   152,   135,   183,   218,   183,    55,
       1,    92,   154,   155,   156,   168,   169,   319,   199,   201,
     184,   195,   303,   319,   183,   302,   303,   319,    89,   138,
     173,   218,   268,   271,   202,    53,    54,    56,    63,   107,
     177,   265,    62,    64,    65,   113,   114,   251,   252,    63,
     251,    63,   251,    63,   251,    61,   251,    58,    59,   162,
     183,   183,   311,   318,    40,    41,    42,    43,    44,    37,
      38,    28,   236,   118,   138,    92,    98,   170,   118,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    86,    87,   119,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,    88,   102,   137,   144,   309,
      88,   309,   310,    26,   135,   240,    90,    90,   186,   190,
     240,   160,    51,    55,   175,    58,    59,   122,   272,    88,
     137,   309,   213,   301,   214,    88,   144,   308,   153,   154,
      55,    16,   219,   316,   118,    88,   137,   309,    90,    90,
     219,   161,   161,    55,    88,   137,   309,    25,   107,   138,
     261,   311,   112,   260,    20,   243,   316,    57,   183,   183,
     183,    91,   138,   193,   194,   319,    57,   138,   193,   194,
     188,   189,   195,   303,   319,   189,   160,   312,   313,   160,
     157,   135,   154,    88,   309,    90,   156,   168,   141,   311,
     318,   313,   156,   313,   142,   194,   315,   317,   194,   315,
     136,   315,    55,   170,   171,   172,   138,    88,   137,   309,
      51,    53,    54,    55,    56,    71,    92,    98,    99,   100,
     125,   128,   140,   234,   275,   276,   279,   280,   281,   282,
     284,   285,   286,   287,   289,   290,   291,   294,   295,   296,
     297,   298,    63,   251,   253,   257,   258,    62,   252,    63,
      63,    63,    61,    71,    71,   151,   161,   161,   161,   161,
     156,   160,   160,   237,    98,   162,   183,   195,   196,   168,
     138,   173,   138,   158,   159,   162,   174,   183,   185,   196,
     218,   271,   183,   183,   183,   183,   183,   183,   183,   183,
     183,   183,   183,   183,   183,   183,   183,   183,   183,   183,
     183,   183,   183,   183,   183,   183,   183,   183,    51,    52,
      55,   181,   186,   306,   307,   188,    51,    52,    55,   181,
     186,   306,    51,    55,   306,   242,   241,   159,   183,   185,
     159,   185,    97,   164,   211,   273,   210,    51,    55,   175,
     306,   188,   306,   153,   160,   215,   216,    15,    13,   245,
     319,   154,    16,    51,    55,   188,    51,    55,   154,    27,
     220,   316,   220,    51,    55,   188,    51,    55,   208,   180,
     154,   243,   183,   195,    15,   183,   183,   257,    98,   183,
     192,   303,   183,   304,   313,   138,   194,   138,   313,   141,
     178,   149,   136,   185,   313,   156,   200,   303,   170,   172,
      51,    55,   188,    51,    55,    57,   118,   288,   284,   203,
     183,   138,   299,   319,    51,   138,   299,   138,   283,   183,
     138,   283,    51,   138,   283,    51,    63,   154,   258,   183,
     183,    79,   123,   229,   230,   319,   183,   194,   313,   172,
     138,    44,   118,    44,    88,   137,   309,   312,    90,    90,
     186,   190,   312,   314,    90,    90,   187,   190,   187,   190,
     229,   229,   165,   316,   161,   153,   314,    15,   313,   140,
     274,   284,   177,   183,   196,   246,   319,    18,   222,   319,
      17,   221,   222,    90,    90,   314,    90,    90,   222,   205,
     207,   314,   161,   178,   136,    15,   194,   219,   183,   193,
     303,   136,   313,   315,   314,    51,    98,   224,   289,   231,
     312,    29,   110,   235,    51,   276,   281,   298,   282,   287,
     294,   296,   289,   291,   296,    51,   289,   136,   226,   228,
     231,   275,   277,   278,   281,   289,   290,   292,   293,   296,
     298,   153,    98,   183,   172,   156,   183,    51,    55,   188,
      51,    55,    57,   120,   159,   185,   162,   185,   164,   142,
      90,   159,   185,   159,   185,   164,   240,   236,   153,   154,
     229,   212,   316,    15,   284,   153,   316,   217,    91,   247,
     319,   154,    14,   248,   319,   161,    15,    90,    15,   154,
     154,   220,   183,   154,   138,   138,   286,   313,   138,   141,
     143,   153,   154,   299,   138,   283,   138,   283,   138,   283,
     138,   283,   283,   231,   123,    89,   218,   138,   299,   299,
     138,   227,   218,   138,   227,   138,   227,    15,   183,   314,
     183,   183,   159,   185,    15,   136,   154,   153,   313,    15,
     274,    89,   174,   218,   268,   271,   219,   154,   219,    15,
      15,   209,   222,   243,   244,   225,   138,    98,    51,   232,
     233,   285,    15,   136,   289,   296,   289,   289,   123,    55,
      88,   277,   281,   226,   293,   296,   289,   292,   296,   289,
     136,    15,   153,    55,    88,   137,   309,   154,   154,   154,
     289,   289,   138,   286,   138,   312,   283,   138,   283,   283,
     283,    51,    55,   299,   138,   227,   138,   227,   138,   227,
     138,   227,   227,    15,    51,    55,   188,    51,    55,   245,
     221,    15,   138,   289,   138,   233,   289,   289,   296,   289,
     289,   314,   289,   283,   227,   138,   227,   227,   227,   289,
     227
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   146,   148,   147,   149,   150,   150,   150,   150,   151,
     152,   151,   153,   154,   155,   155,   155,   155,   157,   156,
     156,   156,   156,   156,   156,   156,   156,   156,   156,   156,
     156,   156,   156,   158,   158,   158,   158,   158,   158,   158,
     158,   159,   159,   159,   160,   160,   160,   160,   160,   160,
     161,   162,   162,   163,   163,   165,   164,   166,   166,   166,
     166,   166,   166,   166,   166,   166,   166,   166,   167,   167,
     168,   168,   169,   169,   169,   169,   169,   169,   169,   169,
     169,   169,   170,   170,   171,   171,   172,   172,   173,   173,
     173,   173,   173,   173,   173,   173,   174,   174,   174,   174,
     174,   174,   174,   174,   175,   175,   176,   176,   176,   177,
     177,   177,   177,   177,   178,   178,   179,   180,   179,   181,
     181,   181,   181,   181,   181,   181,   181,   181,   181,   181,
     181,   181,   181,   181,   181,   181,   181,   181,   181,   181,
     181,   181,   181,   181,   181,   181,   181,   181,   181,   182,
     182,   182,   182,   182,   182,   182,   182,   182,   182,   182,
     182,   182,   182,   182,   182,   182,   182,   182,   182,   182,
     182,   182,   182,   182,   182,   182,   182,   182,   182,   182,
     182,   182,   182,   182,   182,   182,   182,   182,   182,   183,
     183,   183,   183,   183,   183,   183,   183,   183,   183,   183,
     183,   183,   183,   183,   183,   183,   183,   183,   183,   183,
     183,   183,   183,   183,   183,   183,   183,   183,   183,   183,
     183,   183,   183,   183,   183,   183,   183,   183,   183,   183,
     183,   183,   184,   184,   184,   184,   185,   185,   186,   187,
     187,   188,   188,   188,   188,   188,   189,   189,   189,   189,
     189,   191,   190,   192,   193,   193,   194,   194,   195,   195,
     195,   195,   196,   196,   196,   197,   197,   197,   197,   197,
     197,   197,   197,   198,   197,   199,   200,   197,   201,   197,
     197,   197,   197,   197,   197,   197,   197,   197,   197,   197,
     197,   197,   202,   203,   197,   197,   197,   204,   205,   197,
     206,   207,   197,   197,   197,   208,   209,   197,   210,   197,
     211,   212,   197,   213,   197,   214,   215,   197,   216,   217,
     197,   197,   197,   197,   197,   218,   219,   219,   219,   220,
     220,   221,   221,   222,   222,   223,   223,   224,   224,   224,
     224,   224,   224,   224,   224,   225,   224,   226,   226,   226,
     226,   227,   227,   228,   228,   228,   228,   228,   228,   228,
     228,   228,   228,   228,   228,   228,   228,   228,   229,   229,
     230,   230,   230,   231,   231,   232,   232,   233,   233,   234,
     234,   235,   235,   237,   236,   238,   238,   238,   238,   239,
     239,   239,   239,   239,   239,   239,   239,   239,   241,   240,
     242,   240,   243,   244,   244,   245,   245,   246,   246,   246,
     247,   247,   248,   248,   249,   249,   249,   249,   250,   250,
     250,   250,   251,   251,   252,   253,   252,   252,   252,   254,
     254,   255,   255,   256,   257,   257,   258,   258,   259,   259,
     260,   261,   260,   262,   262,   263,   263,   264,   265,   265,
     265,   265,   265,   265,   266,   266,   267,   267,   267,   267,
     268,   268,   268,   268,   268,   269,   270,   270,   270,   270,
     270,   270,   270,   270,   271,   271,   272,   273,   272,   274,
     274,   275,   276,   276,   277,   277,   278,   278,   279,   279,
     280,   280,   281,   281,   282,   282,   282,   282,   283,   283,
     284,   284,   284,   284,   284,   284,   284,   284,   284,   284,
     284,   284,   284,   284,   284,   285,   285,   285,   285,   286,
     286,   287,   288,   287,   289,   289,   290,   291,   292,   293,
     293,   294,   294,   295,   295,   296,   296,   297,   297,   298,
     299,   299,   300,   301,   300,   302,   302,   303,   303,   304,
     304,   304,   304,   305,   305,   305,   306,   306,   306,   306,
     307,   307,   307,   308,   308,   309,   309,   310,   310,   311,
     311,   312,   312,   313,   314,   315,   315,   315,   316,   316,
     316,   317,   318,   318,   319
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     2,     1,     1,     3,     2,     1,
       0,     5,     4,     2,     1,     1,     3,     2,     0,     4,
       2,     3,     3,     3,     3,     3,     4,     1,     3,     3,
       3,     3,     1,     3,     3,     6,     5,     5,     5,     5,
       3,     1,     3,     1,     1,     3,     3,     3,     2,     1,
       1,     1,     1,     1,     4,     0,     5,     2,     3,     4,
       5,     4,     5,     2,     2,     2,     2,     2,     1,     3,
       1,     3,     1,     2,     3,     5,     2,     4,     2,     4,
       1,     3,     1,     3,     2,     3,     1,     2,     1,     4,
       3,     3,     3,     3,     2,     1,     1,     4,     3,     3,
       3,     3,     2,     1,     1,     1,     2,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     4,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       3,     6,     5,     5,     5,     5,     4,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     4,     4,     2,     2,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     2,     3,     3,     3,     3,     6,
       6,     1,     1,     2,     4,     2,     1,     3,     3,     1,
       1,     1,     1,     2,     4,     2,     1,     2,     2,     4,
       1,     0,     2,     2,     2,     1,     1,     2,     1,     2,
       3,     4,     3,     4,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     4,     0,     0,     5,     0,     3,
       3,     3,     2,     3,     3,     1,     2,     4,     3,     2,
       1,     2,     0,     0,     5,     6,     6,     0,     0,     7,
       0,     0,     7,     5,     4,     0,     0,     9,     0,     6,
       0,     0,     8,     0,     5,     0,     0,     7,     0,     0,
       9,     1,     1,     1,     1,     1,     1,     1,     2,     1,
       1,     1,     5,     1,     2,     1,     1,     1,     4,     6,
       3,     5,     2,     4,     1,     0,     4,     4,     2,     2,
       1,     2,     0,     6,     8,     4,     6,     4,     2,     6,
       2,     4,     6,     2,     4,     2,     4,     1,     1,     1,
       3,     1,     4,     1,     4,     1,     3,     1,     1,     4,
       1,     3,     3,     0,     5,     2,     4,     5,     5,     2,
       4,     4,     3,     3,     3,     2,     1,     4,     0,     5,
       0,     5,     5,     1,     1,     6,     1,     1,     1,     1,
       2,     1,     2,     1,     1,     1,     1,     1,     1,     1,
       2,     3,     1,     2,     1,     0,     4,     1,     2,     2,
       3,     2,     3,     1,     1,     2,     1,     2,     1,     2,
       1,     0,     4,     2,     3,     1,     4,     2,     1,     1,
       1,     1,     1,     2,     2,     3,     1,     1,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     0,     4,     3,
       2,     2,     2,     1,     2,     1,     1,     3,     1,     3,
       1,     1,     2,     1,     4,     2,     2,     1,     2,     0,
       6,     8,     4,     6,     4,     6,     2,     4,     6,     2,
       4,     2,     4,     1,     0,     1,     1,     1,     1,     1,
       1,     1,     0,     4,     1,     3,     2,     2,     2,     1,
       3,     1,     3,     1,     1,     2,     1,     1,     1,     2,
       2,     1,     1,     0,     4,     1,     2,     1,     3,     3,
       3,     3,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       1,     0,     1,     2,     2,     0,     1,     1,     1,     1,
       1,     1,     1,     2,     0
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (p, YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, p); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, parser_state *p)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (p);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, parser_state *p)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep, p);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule, parser_state *p)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              , p);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule, p); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, parser_state *p)
{
  YYUSE (yyvaluep);
  YYUSE (p);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/*----------.
| yyparse.  |
`----------*/

int
yyparse (parser_state *p)
{
/* The lookahead symbol.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

    /* Number of syntax errors so far.  */
    int yynerrs;

    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex (&yylval, p);
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 1275 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      p->lstate = EXPR_BEG;
                      if (!p->locals) p->locals = cons(0,0);
                    }
#line 5358 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 1280 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      p->tree = new_scope(p, (yyvsp[0].nd));
                      NODE_LINENO(p->tree, (yyvsp[0].nd));
                    }
#line 5367 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 1287 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = (yyvsp[-1].nd);
                    }
#line 5375 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 1293 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_begin(p, 0);
                    }
#line 5383 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 1297 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_begin(p, (yyvsp[0].nd));
                      NODE_LINENO((yyval.nd), (yyvsp[0].nd));
                    }
#line 5392 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 1302 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = push((yyvsp[-2].nd), newline_node((yyvsp[0].nd)));
                    }
#line 5400 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 1306 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_begin(p, 0);
                    }
#line 5408 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 1313 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = local_switch(p);
                    }
#line 5416 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 1317 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      yyerror(p, "BEGIN not supported");
                      local_resume(p, (yyvsp[-3].nd));
                      (yyval.nd) = 0;
                    }
#line 5426 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 1328 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      if ((yyvsp[-2].nd)) {
                        (yyval.nd) = new_rescue(p, (yyvsp[-3].nd), (yyvsp[-2].nd), (yyvsp[-1].nd));
                        NODE_LINENO((yyval.nd), (yyvsp[-3].nd));
                      }
                      else if ((yyvsp[-1].nd)) {
                        yywarn(p, "else without rescue is useless");
                        (yyval.nd) = push((yyvsp[-3].nd), (yyvsp[-1].nd));
                      }
                      else {
                        (yyval.nd) = (yyvsp[-3].nd);
                      }
                      if ((yyvsp[0].nd)) {
                        if ((yyval.nd)) {
                          (yyval.nd) = new_ensure(p, (yyval.nd), (yyvsp[0].nd));
                        }
                        else {
                          (yyval.nd) = push((yyvsp[0].nd), new_nil(p));
                        }
                      }
                    }
#line 5452 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 1352 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = (yyvsp[-1].nd);
                    }
#line 5460 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 1358 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_begin(p, 0);
                    }
#line 5468 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 1362 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_begin(p, (yyvsp[0].nd));
                      NODE_LINENO((yyval.nd), (yyvsp[0].nd));
                    }
#line 5477 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 1367 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = push((yyvsp[-2].nd), newline_node((yyvsp[0].nd)));
                    }
#line 5485 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 1371 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_begin(p, (yyvsp[0].nd));
                    }
#line 5493 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 1376 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {p->lstate = EXPR_FNAME;}
#line 5499 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 1377 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_alias(p, (yyvsp[-2].id), (yyvsp[0].id));
                    }
#line 5507 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 1381 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = (yyvsp[0].nd);
                    }
#line 5515 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 1385 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_if(p, cond((yyvsp[0].nd)), (yyvsp[-2].nd), 0);
                    }
#line 5523 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 1389 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_unless(p, cond((yyvsp[0].nd)), (yyvsp[-2].nd), 0);
                    }
#line 5531 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 1393 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_while(p, cond((yyvsp[0].nd)), (yyvsp[-2].nd));
                    }
#line 5539 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 1397 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_until(p, cond((yyvsp[0].nd)), (yyvsp[-2].nd));
                    }
#line 5547 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 1401 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_mod_rescue(p, (yyvsp[-2].nd), (yyvsp[0].nd));
                    }
#line 5555 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 1405 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      yyerror(p, "END not supported");
                      (yyval.nd) = new_postexe(p, (yyvsp[-1].nd));
                    }
#line 5564 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 1411 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_masgn(p, (yyvsp[-2].nd), (yyvsp[0].nd));
                    }
#line 5572 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 1415 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_asgn(p, (yyvsp[-2].nd), new_array(p, (yyvsp[0].nd)));
                    }
#line 5580 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 1419 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_masgn(p, (yyvsp[-2].nd), (yyvsp[0].nd));
                    }
#line 5588 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 1423 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_masgn(p, (yyvsp[-2].nd), new_array(p, (yyvsp[0].nd)));
                    }
#line 5596 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 1430 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_asgn(p, (yyvsp[-2].nd), (yyvsp[0].nd));
                    }
#line 5604 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 1434 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_op_asgn(p, (yyvsp[-2].nd), (yyvsp[-1].id), (yyvsp[0].nd));
                    }
#line 5612 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 1438 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_op_asgn(p, new_call(p, (yyvsp[-5].nd), intern("[]",2), (yyvsp[-3].nd), '.'), (yyvsp[-1].id), (yyvsp[0].nd));
                    }
#line 5620 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 1442 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_op_asgn(p, new_call(p, (yyvsp[-4].nd), (yyvsp[-2].id), 0, (yyvsp[-3].num)), (yyvsp[-1].id), (yyvsp[0].nd));
                    }
#line 5628 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 1446 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_op_asgn(p, new_call(p, (yyvsp[-4].nd), (yyvsp[-2].id), 0, (yyvsp[-3].num)), (yyvsp[-1].id), (yyvsp[0].nd));
                    }
#line 5636 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 1450 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      yyerror(p, "constant re-assignment");
                      (yyval.nd) = 0;
                    }
#line 5645 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 1455 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_op_asgn(p, new_call(p, (yyvsp[-4].nd), (yyvsp[-2].id), 0, tCOLON2), (yyvsp[-1].id), (yyvsp[0].nd));
                    }
#line 5653 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 1459 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      backref_error(p, (yyvsp[-2].nd));
                      (yyval.nd) = new_begin(p, 0);
                    }
#line 5662 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 1467 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_mod_rescue(p, (yyvsp[-2].nd), (yyvsp[0].nd));
                    }
#line 5670 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 1476 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_and(p, (yyvsp[-2].nd), (yyvsp[0].nd));
                    }
#line 5678 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 1480 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_or(p, (yyvsp[-2].nd), (yyvsp[0].nd));
                    }
#line 5686 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 1484 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = call_uni_op(p, cond((yyvsp[0].nd)), "!");
                    }
#line 5694 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 1488 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = call_uni_op(p, cond((yyvsp[0].nd)), "!");
                    }
#line 5702 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 1495 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      if (!(yyvsp[0].nd)) (yyval.nd) = new_nil(p);
                      else {
                        (yyval.nd) = (yyvsp[0].nd);
                      }
                    }
#line 5713 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 1509 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_call(p, (yyvsp[-3].nd), (yyvsp[-1].id), (yyvsp[0].nd), (yyvsp[-2].num));
                    }
#line 5721 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 1515 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      local_nest(p);
                    }
#line 5729 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 1521 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_block(p, (yyvsp[-2].nd), (yyvsp[-1].nd));
                      local_unnest(p);
                    }
#line 5738 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 1528 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_fcall(p, (yyvsp[-1].id), (yyvsp[0].nd));
                    }
#line 5746 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 1532 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      args_with_block(p, (yyvsp[-1].nd), (yyvsp[0].nd));
                      (yyval.nd) = new_fcall(p, (yyvsp[-2].id), (yyvsp[-1].nd));
                    }
#line 5755 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 1537 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_call(p, (yyvsp[-3].nd), (yyvsp[-1].id), (yyvsp[0].nd), (yyvsp[-2].num));
                    }
#line 5763 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 1541 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      args_with_block(p, (yyvsp[-1].nd), (yyvsp[0].nd));
                      (yyval.nd) = new_call(p, (yyvsp[-4].nd), (yyvsp[-2].id), (yyvsp[-1].nd), (yyvsp[-3].num));
                   }
#line 5772 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 1546 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_call(p, (yyvsp[-3].nd), (yyvsp[-1].id), (yyvsp[0].nd), tCOLON2);
                    }
#line 5780 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 1550 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      args_with_block(p, (yyvsp[-1].nd), (yyvsp[0].nd));
                      (yyval.nd) = new_call(p, (yyvsp[-4].nd), (yyvsp[-2].id), (yyvsp[-1].nd), tCOLON2);
                    }
#line 5789 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 1555 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_super(p, (yyvsp[0].nd));
                    }
#line 5797 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 1559 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_yield(p, (yyvsp[0].nd));
                    }
#line 5805 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 1563 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_return(p, ret_args(p, (yyvsp[0].nd)));
                    }
#line 5813 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 1567 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_break(p, ret_args(p, (yyvsp[0].nd)));
                    }
#line 5821 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 1571 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_next(p, ret_args(p, (yyvsp[0].nd)));
                    }
#line 5829 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 1577 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = (yyvsp[0].nd);
                    }
#line 5837 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 1581 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = (yyvsp[-1].nd);
                    }
#line 5845 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 1588 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = (yyvsp[-1].nd);
                    }
#line 5853 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 1594 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = list1((yyvsp[0].nd));
                    }
#line 5861 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 1598 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = list1(push((yyvsp[-1].nd),(yyvsp[0].nd)));
                    }
#line 5869 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 1602 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = list2((yyvsp[-2].nd), (yyvsp[0].nd));
                    }
#line 5877 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 1606 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = list3((yyvsp[-4].nd), (yyvsp[-2].nd), (yyvsp[0].nd));
                    }
#line 5885 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 1610 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = list2((yyvsp[-1].nd), new_nil(p));
                    }
#line 5893 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 1614 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = list3((yyvsp[-3].nd), new_nil(p), (yyvsp[0].nd));
                    }
#line 5901 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 1618 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = list2(0, (yyvsp[0].nd));
                    }
#line 5909 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 1622 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = list3(0, (yyvsp[-2].nd), (yyvsp[0].nd));
                    }
#line 5917 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 1626 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = list2(0, new_nil(p));
                    }
#line 5925 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 1630 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = list3(0, new_nil(p), (yyvsp[0].nd));
                    }
#line 5933 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 1637 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_masgn(p, (yyvsp[-1].nd), NULL);
                    }
#line 5941 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 1643 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = list1((yyvsp[-1].nd));
                    }
#line 5949 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 1647 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = push((yyvsp[-2].nd), (yyvsp[-1].nd));
                    }
#line 5957 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 1653 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = list1((yyvsp[0].nd));
                    }
#line 5965 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 1657 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = push((yyvsp[-1].nd), (yyvsp[0].nd));
                    }
#line 5973 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 1663 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      assignable(p, (yyvsp[0].nd));
                    }
#line 5981 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 1667 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_call(p, (yyvsp[-3].nd), intern("[]",2), (yyvsp[-1].nd), '.');
                    }
#line 5989 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 1671 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_call(p, (yyvsp[-2].nd), (yyvsp[0].id), 0, (yyvsp[-1].num));
                    }
#line 5997 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 1675 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_call(p, (yyvsp[-2].nd), (yyvsp[0].id), 0, tCOLON2);
                    }
#line 6005 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 1679 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_call(p, (yyvsp[-2].nd), (yyvsp[0].id), 0, (yyvsp[-1].num));
                    }
#line 6013 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 1683 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      if (p->in_def || p->in_single)
                        yyerror(p, "dynamic constant assignment");
                      (yyval.nd) = new_colon2(p, (yyvsp[-2].nd), (yyvsp[0].id));
                    }
#line 6023 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 1689 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      if (p->in_def || p->in_single)
                        yyerror(p, "dynamic constant assignment");
                      (yyval.nd) = new_colon3(p, (yyvsp[0].id));
                    }
#line 6033 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 1695 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      backref_error(p, (yyvsp[0].nd));
                      (yyval.nd) = 0;
                    }
#line 6042 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 1702 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      assignable(p, (yyvsp[0].nd));
                    }
#line 6050 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 1706 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_call(p, (yyvsp[-3].nd), intern("[]",2), (yyvsp[-1].nd), '.');
                    }
#line 6058 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 1710 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_call(p, (yyvsp[-2].nd), (yyvsp[0].id), 0, (yyvsp[-1].num));
                    }
#line 6066 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 1714 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_call(p, (yyvsp[-2].nd), (yyvsp[0].id), 0, tCOLON2);
                    }
#line 6074 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 1718 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_call(p, (yyvsp[-2].nd), (yyvsp[0].id), 0, (yyvsp[-1].num));
                    }
#line 6082 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 1722 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      if (p->in_def || p->in_single)
                        yyerror(p, "dynamic constant assignment");
                      (yyval.nd) = new_colon2(p, (yyvsp[-2].nd), (yyvsp[0].id));
                    }
#line 6092 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 1728 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      if (p->in_def || p->in_single)
                        yyerror(p, "dynamic constant assignment");
                      (yyval.nd) = new_colon3(p, (yyvsp[0].id));
                    }
#line 6102 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 1734 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      backref_error(p, (yyvsp[0].nd));
                      (yyval.nd) = 0;
                    }
#line 6111 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 1741 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      yyerror(p, "class/module name must be CONSTANT");
                    }
#line 6119 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 1748 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = cons((node*)1, nsym((yyvsp[0].id)));
                    }
#line 6127 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 1752 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = cons((node*)0, nsym((yyvsp[0].id)));
                    }
#line 6135 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 1756 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      void_expr_error(p, (yyvsp[-2].nd));
                      (yyval.nd) = cons((yyvsp[-2].nd), nsym((yyvsp[0].id)));
                    }
#line 6144 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 1766 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      p->lstate = EXPR_ENDFN;
                      (yyval.id) = (yyvsp[0].id);
                    }
#line 6153 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 1771 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      p->lstate = EXPR_ENDFN;
                      (yyval.id) = (yyvsp[0].id);
                    }
#line 6162 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 1782 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_undef(p, (yyvsp[0].id));
                    }
#line 6170 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 1785 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {p->lstate = EXPR_FNAME;}
#line 6176 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 1786 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = push((yyvsp[-3].nd), nsym((yyvsp[0].id)));
                    }
#line 6184 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 1791 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    { (yyval.id) = intern_c('|');   }
#line 6190 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 1792 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    { (yyval.id) = intern_c('^');   }
#line 6196 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 1793 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    { (yyval.id) = intern_c('&');   }
#line 6202 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 1794 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    { (yyval.id) = intern("<=>",3); }
#line 6208 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 1795 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    { (yyval.id) = intern("==",2);  }
#line 6214 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 1796 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    { (yyval.id) = intern("===",3); }
#line 6220 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 1797 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    { (yyval.id) = intern("=~",2);  }
#line 6226 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 1798 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    { (yyval.id) = intern("!~",2);  }
#line 6232 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 1799 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    { (yyval.id) = intern_c('>');   }
#line 6238 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 1800 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    { (yyval.id) = intern(">=",2);  }
#line 6244 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 1801 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    { (yyval.id) = intern_c('<');   }
#line 6250 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 1802 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    { (yyval.id) = intern("<=",2);  }
#line 6256 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 1803 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    { (yyval.id) = intern("!=",2);  }
#line 6262 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 1804 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    { (yyval.id) = intern("<<",2);  }
#line 6268 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 1805 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    { (yyval.id) = intern(">>",2);  }
#line 6274 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 1806 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    { (yyval.id) = intern_c('+');   }
#line 6280 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 1807 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    { (yyval.id) = intern_c('-');   }
#line 6286 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 1808 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    { (yyval.id) = intern_c('*');   }
#line 6292 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 1809 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    { (yyval.id) = intern_c('*');   }
#line 6298 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 1810 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    { (yyval.id) = intern_c('/');   }
#line 6304 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 1811 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    { (yyval.id) = intern_c('%');   }
#line 6310 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 140:
#line 1812 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    { (yyval.id) = intern("**",2);  }
#line 6316 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 1813 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    { (yyval.id) = intern("**",2);  }
#line 6322 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 142:
#line 1814 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    { (yyval.id) = intern_c('!');   }
#line 6328 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 143:
#line 1815 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    { (yyval.id) = intern_c('~');   }
#line 6334 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 144:
#line 1816 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    { (yyval.id) = intern("+@",2);  }
#line 6340 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 145:
#line 1817 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    { (yyval.id) = intern("-@",2);  }
#line 6346 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 146:
#line 1818 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    { (yyval.id) = intern("[]",2);  }
#line 6352 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 147:
#line 1819 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    { (yyval.id) = intern("[]=",3); }
#line 6358 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 148:
#line 1820 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    { (yyval.id) = intern_c('`');   }
#line 6364 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 189:
#line 1838 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_asgn(p, (yyvsp[-2].nd), (yyvsp[0].nd));
                    }
#line 6372 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 190:
#line 1842 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_op_asgn(p, (yyvsp[-2].nd), (yyvsp[-1].id), (yyvsp[0].nd));
                    }
#line 6380 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 191:
#line 1846 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_op_asgn(p, new_call(p, (yyvsp[-5].nd), intern("[]",2), (yyvsp[-3].nd), '.'), (yyvsp[-1].id), (yyvsp[0].nd));
                    }
#line 6388 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 192:
#line 1850 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_op_asgn(p, new_call(p, (yyvsp[-4].nd), (yyvsp[-2].id), 0, (yyvsp[-3].num)), (yyvsp[-1].id), (yyvsp[0].nd));
                    }
#line 6396 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 193:
#line 1854 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_op_asgn(p, new_call(p, (yyvsp[-4].nd), (yyvsp[-2].id), 0, (yyvsp[-3].num)), (yyvsp[-1].id), (yyvsp[0].nd));
                    }
#line 6404 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 194:
#line 1858 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_op_asgn(p, new_call(p, (yyvsp[-4].nd), (yyvsp[-2].id), 0, tCOLON2), (yyvsp[-1].id), (yyvsp[0].nd));
                    }
#line 6412 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 195:
#line 1862 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      yyerror(p, "constant re-assignment");
                      (yyval.nd) = new_begin(p, 0);
                    }
#line 6421 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 196:
#line 1867 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      yyerror(p, "constant re-assignment");
                      (yyval.nd) = new_begin(p, 0);
                    }
#line 6430 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 197:
#line 1872 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      backref_error(p, (yyvsp[-2].nd));
                      (yyval.nd) = new_begin(p, 0);
                    }
#line 6439 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 198:
#line 1877 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_dot2(p, (yyvsp[-2].nd), (yyvsp[0].nd));
                    }
#line 6447 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 199:
#line 1881 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_dot3(p, (yyvsp[-2].nd), (yyvsp[0].nd));
                    }
#line 6455 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 200:
#line 1885 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = call_bin_op(p, (yyvsp[-2].nd), "+", (yyvsp[0].nd));
                    }
#line 6463 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 201:
#line 1889 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = call_bin_op(p, (yyvsp[-2].nd), "-", (yyvsp[0].nd));
                    }
#line 6471 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 202:
#line 1893 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = call_bin_op(p, (yyvsp[-2].nd), "*", (yyvsp[0].nd));
                    }
#line 6479 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 203:
#line 1897 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = call_bin_op(p, (yyvsp[-2].nd), "/", (yyvsp[0].nd));
                    }
#line 6487 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 204:
#line 1901 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = call_bin_op(p, (yyvsp[-2].nd), "%", (yyvsp[0].nd));
                    }
#line 6495 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 205:
#line 1905 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = call_bin_op(p, (yyvsp[-2].nd), "**", (yyvsp[0].nd));
                    }
#line 6503 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 206:
#line 1909 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = call_uni_op(p, call_bin_op(p, (yyvsp[-2].nd), "**", (yyvsp[0].nd)), "-@");
                    }
#line 6511 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 207:
#line 1913 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = call_uni_op(p, call_bin_op(p, (yyvsp[-2].nd), "**", (yyvsp[0].nd)), "-@");
                    }
#line 6519 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 208:
#line 1917 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = call_uni_op(p, (yyvsp[0].nd), "+@");
                    }
#line 6527 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 209:
#line 1921 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = call_uni_op(p, (yyvsp[0].nd), "-@");
                    }
#line 6535 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 210:
#line 1925 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = call_bin_op(p, (yyvsp[-2].nd), "|", (yyvsp[0].nd));
                    }
#line 6543 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 211:
#line 1929 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = call_bin_op(p, (yyvsp[-2].nd), "^", (yyvsp[0].nd));
                    }
#line 6551 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 212:
#line 1933 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = call_bin_op(p, (yyvsp[-2].nd), "&", (yyvsp[0].nd));
                    }
#line 6559 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 213:
#line 1937 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = call_bin_op(p, (yyvsp[-2].nd), "<=>", (yyvsp[0].nd));
                    }
#line 6567 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 214:
#line 1941 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = call_bin_op(p, (yyvsp[-2].nd), ">", (yyvsp[0].nd));
                    }
#line 6575 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 215:
#line 1945 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = call_bin_op(p, (yyvsp[-2].nd), ">=", (yyvsp[0].nd));
                    }
#line 6583 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 216:
#line 1949 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = call_bin_op(p, (yyvsp[-2].nd), "<", (yyvsp[0].nd));
                    }
#line 6591 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 217:
#line 1953 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = call_bin_op(p, (yyvsp[-2].nd), "<=", (yyvsp[0].nd));
                    }
#line 6599 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 218:
#line 1957 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = call_bin_op(p, (yyvsp[-2].nd), "==", (yyvsp[0].nd));
                    }
#line 6607 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 219:
#line 1961 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = call_bin_op(p, (yyvsp[-2].nd), "===", (yyvsp[0].nd));
                    }
#line 6615 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 220:
#line 1965 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = call_bin_op(p, (yyvsp[-2].nd), "!=", (yyvsp[0].nd));
                    }
#line 6623 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 221:
#line 1969 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = call_bin_op(p, (yyvsp[-2].nd), "=~", (yyvsp[0].nd));
                    }
#line 6631 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 222:
#line 1973 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = call_bin_op(p, (yyvsp[-2].nd), "!~", (yyvsp[0].nd));
                    }
#line 6639 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 223:
#line 1977 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = call_uni_op(p, cond((yyvsp[0].nd)), "!");
                    }
#line 6647 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 224:
#line 1981 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = call_uni_op(p, cond((yyvsp[0].nd)), "~");
                    }
#line 6655 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 225:
#line 1985 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = call_bin_op(p, (yyvsp[-2].nd), "<<", (yyvsp[0].nd));
                    }
#line 6663 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 226:
#line 1989 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = call_bin_op(p, (yyvsp[-2].nd), ">>", (yyvsp[0].nd));
                    }
#line 6671 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 227:
#line 1993 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_and(p, (yyvsp[-2].nd), (yyvsp[0].nd));
                    }
#line 6679 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 228:
#line 1997 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_or(p, (yyvsp[-2].nd), (yyvsp[0].nd));
                    }
#line 6687 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 229:
#line 2001 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_if(p, cond((yyvsp[-5].nd)), (yyvsp[-3].nd), (yyvsp[0].nd));
                    }
#line 6695 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 230:
#line 2005 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_if(p, cond((yyvsp[-5].nd)), (yyvsp[-3].nd), (yyvsp[0].nd));
                    }
#line 6703 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 231:
#line 2009 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = (yyvsp[0].nd);
                    }
#line 6711 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 233:
#line 2016 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = (yyvsp[-1].nd);
                      NODE_LINENO((yyval.nd), (yyvsp[-1].nd));
                    }
#line 6720 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 234:
#line 2021 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = push((yyvsp[-3].nd), new_kw_hash(p, (yyvsp[-1].nd)));
                    }
#line 6728 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 235:
#line 2025 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = cons(new_kw_hash(p, (yyvsp[-1].nd)), 0);
                      NODE_LINENO((yyval.nd), (yyvsp[-1].nd));
                    }
#line 6737 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 236:
#line 2032 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = (yyvsp[0].nd);
                    }
#line 6745 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 237:
#line 2036 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      void_expr_error(p, (yyvsp[-2].nd));
                      void_expr_error(p, (yyvsp[0].nd));
                      (yyval.nd) = new_mod_rescue(p, (yyvsp[-2].nd), (yyvsp[0].nd));
                    }
#line 6755 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 238:
#line 2044 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = (yyvsp[-1].nd);
                    }
#line 6763 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 243:
#line 2056 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = cons((yyvsp[-1].nd),0);
                      NODE_LINENO((yyval.nd), (yyvsp[-1].nd));
                    }
#line 6772 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 244:
#line 2061 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = cons(push((yyvsp[-3].nd), new_kw_hash(p, (yyvsp[-1].nd))), 0);
                      NODE_LINENO((yyval.nd), (yyvsp[-3].nd));
                    }
#line 6781 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 245:
#line 2066 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = cons(list1(new_kw_hash(p, (yyvsp[-1].nd))), 0);
                      NODE_LINENO((yyval.nd), (yyvsp[-1].nd));
                    }
#line 6790 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 246:
#line 2073 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      void_expr_error(p, (yyvsp[0].nd));
                      (yyval.nd) = cons(list1((yyvsp[0].nd)), 0);
                      NODE_LINENO((yyval.nd), (yyvsp[0].nd));
                    }
#line 6800 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 247:
#line 2079 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = cons((yyvsp[-1].nd), (yyvsp[0].nd));
                      NODE_LINENO((yyval.nd), (yyvsp[-1].nd));
                    }
#line 6809 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 248:
#line 2084 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = cons(list1(new_kw_hash(p, (yyvsp[-1].nd))), (yyvsp[0].nd));
                      NODE_LINENO((yyval.nd), (yyvsp[-1].nd));
                    }
#line 6818 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 249:
#line 2089 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = cons(push((yyvsp[-3].nd), new_kw_hash(p, (yyvsp[-1].nd))), (yyvsp[0].nd));
                      NODE_LINENO((yyval.nd), (yyvsp[-3].nd));
                    }
#line 6827 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 250:
#line 2094 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = cons(0, (yyvsp[0].nd));
                      NODE_LINENO((yyval.nd), (yyvsp[0].nd));
                    }
#line 6836 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 251:
#line 2100 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.stack) = p->cmdarg_stack;
                      CMDARG_PUSH(1);
                    }
#line 6845 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 252:
#line 2105 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      p->cmdarg_stack = (yyvsp[-1].stack);
                      (yyval.nd) = (yyvsp[0].nd);
                    }
#line 6854 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 253:
#line 2112 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_block_arg(p, (yyvsp[0].nd));
                    }
#line 6862 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 254:
#line 2118 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = (yyvsp[0].nd);
                    }
#line 6870 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 255:
#line 2122 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = 0;
                    }
#line 6878 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 258:
#line 2132 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      void_expr_error(p, (yyvsp[0].nd));
                      (yyval.nd) = cons((yyvsp[0].nd), 0);
                      NODE_LINENO((yyval.nd), (yyvsp[0].nd));
                    }
#line 6888 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 259:
#line 2138 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      void_expr_error(p, (yyvsp[0].nd));
                      (yyval.nd) = cons(new_splat(p, (yyvsp[0].nd)), 0);
                      NODE_LINENO((yyval.nd), (yyvsp[0].nd));
                    }
#line 6898 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 260:
#line 2144 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      void_expr_error(p, (yyvsp[0].nd));
                      (yyval.nd) = push((yyvsp[-2].nd), (yyvsp[0].nd));
                    }
#line 6907 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 261:
#line 2149 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      void_expr_error(p, (yyvsp[0].nd));
                      (yyval.nd) = push((yyvsp[-3].nd), new_splat(p, (yyvsp[0].nd)));
                    }
#line 6916 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 262:
#line 2156 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      void_expr_error(p, (yyvsp[0].nd));
                      (yyval.nd) = push((yyvsp[-2].nd), (yyvsp[0].nd));
                    }
#line 6925 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 263:
#line 2161 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      void_expr_error(p, (yyvsp[0].nd));
                      (yyval.nd) = push((yyvsp[-3].nd), new_splat(p, (yyvsp[0].nd)));
                    }
#line 6934 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 264:
#line 2166 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      void_expr_error(p, (yyvsp[0].nd));
                      (yyval.nd) = list1(new_splat(p, (yyvsp[0].nd)));
                    }
#line 6943 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 272:
#line 2180 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_fcall(p, (yyvsp[0].id), 0);
                    }
#line 6951 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 273:
#line 2184 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.stack) = p->cmdarg_stack;
                      p->cmdarg_stack = 0;
                    }
#line 6960 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 274:
#line 2190 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      p->cmdarg_stack = (yyvsp[-2].stack);
                      (yyval.nd) = (yyvsp[-1].nd);
                    }
#line 6969 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 275:
#line 2195 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.stack) = p->cmdarg_stack;
                      p->cmdarg_stack = 0;
                    }
#line 6978 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 276:
#line 2199 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {p->lstate = EXPR_ENDARG;}
#line 6984 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 277:
#line 2200 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      p->cmdarg_stack = (yyvsp[-3].stack);
                      (yyval.nd) = (yyvsp[-2].nd);
                    }
#line 6993 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 278:
#line 2204 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {p->lstate = EXPR_ENDARG;}
#line 6999 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 279:
#line 2205 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_nil(p);
                    }
#line 7007 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 280:
#line 2209 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = (yyvsp[-1].nd);
                    }
#line 7015 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 281:
#line 2213 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_colon2(p, (yyvsp[-2].nd), (yyvsp[0].id));
                    }
#line 7023 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 282:
#line 2217 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_colon3(p, (yyvsp[0].id));
                    }
#line 7031 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 283:
#line 2221 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_array(p, (yyvsp[-1].nd));
                      NODE_LINENO((yyval.nd), (yyvsp[-1].nd));
                    }
#line 7040 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 284:
#line 2226 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_hash(p, (yyvsp[-1].nd));
                      NODE_LINENO((yyval.nd), (yyvsp[-1].nd));
                    }
#line 7049 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 285:
#line 2231 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_return(p, 0);
                    }
#line 7057 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 286:
#line 2235 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_yield(p, (yyvsp[0].nd));
                    }
#line 7065 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 287:
#line 2239 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = call_uni_op(p, cond((yyvsp[-1].nd)), "!");
                    }
#line 7073 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 288:
#line 2243 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = call_uni_op(p, new_nil(p), "!");
                    }
#line 7081 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 289:
#line 2247 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_fcall(p, (yyvsp[-1].id), cons(0, (yyvsp[0].nd)));
                    }
#line 7089 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 291:
#line 2252 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      call_with_block(p, (yyvsp[-1].nd), (yyvsp[0].nd));
                      (yyval.nd) = (yyvsp[-1].nd);
                    }
#line 7098 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 292:
#line 2257 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      local_nest(p);
                      (yyval.num) = p->lpar_beg;
                      p->lpar_beg = ++p->paren_nest;
                    }
#line 7108 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 293:
#line 2263 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.stack) = p->cmdarg_stack;
                      p->cmdarg_stack = 0;
                    }
#line 7117 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 294:
#line 2268 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      p->lpar_beg = (yyvsp[-3].num);
                      (yyval.nd) = new_lambda(p, (yyvsp[-2].nd), (yyvsp[0].nd));
                      local_unnest(p);
                      p->cmdarg_stack = (yyvsp[-1].stack);
                      CMDARG_LEXPOP();
                    }
#line 7129 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 295:
#line 2279 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_if(p, cond((yyvsp[-4].nd)), (yyvsp[-2].nd), (yyvsp[-1].nd));
                      SET_LINENO((yyval.nd), (yyvsp[-5].num));
                    }
#line 7138 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 296:
#line 2287 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_unless(p, cond((yyvsp[-4].nd)), (yyvsp[-2].nd), (yyvsp[-1].nd));
                      SET_LINENO((yyval.nd), (yyvsp[-5].num));
                    }
#line 7147 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 297:
#line 2291 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {COND_PUSH(1);}
#line 7153 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 298:
#line 2291 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {COND_POP();}
#line 7159 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 299:
#line 2294 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_while(p, cond((yyvsp[-4].nd)), (yyvsp[-1].nd));
                      SET_LINENO((yyval.nd), (yyvsp[-6].num));
                    }
#line 7168 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 300:
#line 2298 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {COND_PUSH(1);}
#line 7174 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 301:
#line 2298 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {COND_POP();}
#line 7180 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 302:
#line 2301 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_until(p, cond((yyvsp[-4].nd)), (yyvsp[-1].nd));
                      SET_LINENO((yyval.nd), (yyvsp[-6].num));
                    }
#line 7189 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 303:
#line 2308 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_case(p, (yyvsp[-3].nd), (yyvsp[-1].nd));
                    }
#line 7197 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 304:
#line 2312 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_case(p, 0, (yyvsp[-1].nd));
                    }
#line 7205 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 305:
#line 2316 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {COND_PUSH(1);}
#line 7211 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 306:
#line 2318 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {COND_POP();}
#line 7217 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 307:
#line 2321 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_for(p, (yyvsp[-7].nd), (yyvsp[-4].nd), (yyvsp[-1].nd));
                      SET_LINENO((yyval.nd), (yyvsp[-8].num));
                    }
#line 7226 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 308:
#line 2327 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      if (p->in_def || p->in_single)
                        yyerror(p, "class definition in method body");
                      (yyval.nd) = local_switch(p);
                    }
#line 7236 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 309:
#line 2334 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_class(p, (yyvsp[-4].nd), (yyvsp[-3].nd), (yyvsp[-1].nd));
                      SET_LINENO((yyval.nd), (yyvsp[-5].num));
                      local_resume(p, (yyvsp[-2].nd));
                    }
#line 7246 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 310:
#line 2341 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.num) = p->in_def;
                      p->in_def = 0;
                    }
#line 7255 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 311:
#line 2346 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = cons(local_switch(p), nint(p->in_single));
                      p->in_single = 0;
                    }
#line 7264 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 312:
#line 2352 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_sclass(p, (yyvsp[-5].nd), (yyvsp[-1].nd));
                      SET_LINENO((yyval.nd), (yyvsp[-7].num));
                      local_resume(p, (yyvsp[-2].nd)->car);
                      p->in_def = (yyvsp[-4].num);
                      p->in_single = intn((yyvsp[-2].nd)->cdr);
                    }
#line 7276 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 313:
#line 2361 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      if (p->in_def || p->in_single)
                        yyerror(p, "module definition in method body");
                      (yyval.nd) = local_switch(p);
                    }
#line 7286 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 314:
#line 2368 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_module(p, (yyvsp[-3].nd), (yyvsp[-1].nd));
                      SET_LINENO((yyval.nd), (yyvsp[-4].num));
                      local_resume(p, (yyvsp[-2].nd));
                    }
#line 7296 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 315:
#line 2374 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.stack) = p->cmdarg_stack;
                      p->cmdarg_stack = 0;
                    }
#line 7305 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 316:
#line 2378 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      p->in_def++;
                      (yyval.nd) = local_switch(p);
                    }
#line 7314 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 317:
#line 2385 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_def(p, (yyvsp[-5].id), (yyvsp[-2].nd), (yyvsp[-1].nd));
                      SET_LINENO((yyval.nd), (yyvsp[-6].num));
                      local_resume(p, (yyvsp[-3].nd));
                      p->in_def--;
                      p->cmdarg_stack = (yyvsp[-4].stack);
                    }
#line 7326 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 318:
#line 2393 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      p->lstate = EXPR_FNAME;
                      (yyval.stack) = p->cmdarg_stack;
                      p->cmdarg_stack = 0;
                    }
#line 7336 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 319:
#line 2399 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      p->in_single++;
                      p->lstate = EXPR_ENDFN; /* force for args */
                      (yyval.nd) = local_switch(p);
                    }
#line 7346 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 320:
#line 2407 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_sdef(p, (yyvsp[-7].nd), (yyvsp[-4].id), (yyvsp[-2].nd), (yyvsp[-1].nd));
                      SET_LINENO((yyval.nd), (yyvsp[-8].num));
                      local_resume(p, (yyvsp[-3].nd));
                      p->in_single--;
                      p->cmdarg_stack = (yyvsp[-5].stack);
                    }
#line 7358 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 321:
#line 2415 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_break(p, 0);
                    }
#line 7366 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 322:
#line 2419 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_next(p, 0);
                    }
#line 7374 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 323:
#line 2423 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_redo(p);
                    }
#line 7382 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 324:
#line 2427 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_retry(p);
                    }
#line 7390 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 325:
#line 2433 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = (yyvsp[0].nd);
                      if (!(yyval.nd)) (yyval.nd) = new_nil(p);
                    }
#line 7399 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 332:
#line 2452 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_if(p, cond((yyvsp[-3].nd)), (yyvsp[-1].nd), (yyvsp[0].nd));
                    }
#line 7407 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 334:
#line 2459 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = (yyvsp[0].nd);
                    }
#line 7415 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 335:
#line 2465 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = list1(list1((yyvsp[0].nd)));
                    }
#line 7423 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 337:
#line 2472 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = list3((yyvsp[0].nd),0,0);
                    }
#line 7431 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 338:
#line 2476 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = list3((yyvsp[-3].nd), new_arg(p, (yyvsp[0].id)), 0);
                    }
#line 7439 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 339:
#line 2480 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = list3((yyvsp[-5].nd), new_arg(p, (yyvsp[-2].id)), (yyvsp[0].nd));
                    }
#line 7447 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 340:
#line 2484 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      local_add_f(p, 0);
                      (yyval.nd) = list3((yyvsp[-2].nd), (node*)-1, 0);
                    }
#line 7456 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 341:
#line 2489 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = list3((yyvsp[-4].nd), (node*)-1, (yyvsp[0].nd));
                    }
#line 7464 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 342:
#line 2493 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = list3(0, new_arg(p, (yyvsp[0].id)), 0);
                    }
#line 7472 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 343:
#line 2497 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = list3(0, new_arg(p, (yyvsp[-2].id)), (yyvsp[0].nd));
                    }
#line 7480 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 344:
#line 2501 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      local_add_f(p, 0);
                      (yyval.nd) = list3(0, (node*)-1, 0);
                    }
#line 7489 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 345:
#line 2506 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      local_add_f(p, 0);
                    }
#line 7497 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 346:
#line 2510 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = list3(0, (node*)-1, (yyvsp[0].nd));
                    }
#line 7505 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 347:
#line 2516 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_args_tail(p, (yyvsp[-3].nd), (yyvsp[-1].nd), (yyvsp[0].id));
                    }
#line 7513 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 348:
#line 2520 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_args_tail(p, (yyvsp[-1].nd), 0, (yyvsp[0].id));
                    }
#line 7521 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 349:
#line 2524 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_args_tail(p, 0, (yyvsp[-1].nd), (yyvsp[0].id));
                    }
#line 7529 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 350:
#line 2528 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_args_tail(p, 0, 0, (yyvsp[0].id));
                    }
#line 7537 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 351:
#line 2534 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = (yyvsp[0].nd);
                    }
#line 7545 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 352:
#line 2538 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_args_tail(p, 0, 0, 0);
                    }
#line 7553 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 353:
#line 2544 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_args(p, (yyvsp[-5].nd), (yyvsp[-3].nd), (yyvsp[-1].id), 0, (yyvsp[0].nd));
                    }
#line 7561 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 354:
#line 2548 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_args(p, (yyvsp[-7].nd), (yyvsp[-5].nd), (yyvsp[-3].id), (yyvsp[-1].nd), (yyvsp[0].nd));
                    }
#line 7569 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 355:
#line 2552 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_args(p, (yyvsp[-3].nd), (yyvsp[-1].nd), 0, 0, (yyvsp[0].nd));
                    }
#line 7577 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 356:
#line 2556 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_args(p, (yyvsp[-5].nd), (yyvsp[-3].nd), 0, (yyvsp[-1].nd), (yyvsp[0].nd));
                    }
#line 7585 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 357:
#line 2560 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_args(p, (yyvsp[-3].nd), 0, (yyvsp[-1].id), 0, (yyvsp[0].nd));
                    }
#line 7593 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 358:
#line 2564 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_args(p, (yyvsp[-1].nd), 0, 0, 0, 0);
                    }
#line 7601 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 359:
#line 2568 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_args(p, (yyvsp[-5].nd), 0, (yyvsp[-3].id), (yyvsp[-1].nd), (yyvsp[0].nd));
                    }
#line 7609 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 360:
#line 2572 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_args(p, (yyvsp[-1].nd), 0, 0, 0, (yyvsp[0].nd));
                    }
#line 7617 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 361:
#line 2576 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_args(p, 0, (yyvsp[-3].nd), (yyvsp[-1].id), 0, (yyvsp[0].nd));
                    }
#line 7625 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 362:
#line 2580 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_args(p, 0, (yyvsp[-5].nd), (yyvsp[-3].id), (yyvsp[-1].nd), (yyvsp[0].nd));
                    }
#line 7633 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 363:
#line 2584 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_args(p, 0, (yyvsp[-1].nd), 0, 0, (yyvsp[0].nd));
                    }
#line 7641 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 364:
#line 2588 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_args(p, 0, (yyvsp[-3].nd), 0, (yyvsp[-1].nd), (yyvsp[0].nd));
                    }
#line 7649 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 365:
#line 2592 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_args(p, 0, 0, (yyvsp[-1].id), 0, (yyvsp[0].nd));
                    }
#line 7657 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 366:
#line 2596 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_args(p, 0, 0, (yyvsp[-3].id), (yyvsp[-1].nd), (yyvsp[0].nd));
                    }
#line 7665 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 367:
#line 2600 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_args(p, 0, 0, 0, 0, (yyvsp[0].nd));
                    }
#line 7673 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 369:
#line 2607 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      p->cmd_start = TRUE;
                      (yyval.nd) = (yyvsp[0].nd);
                    }
#line 7682 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 370:
#line 2614 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = 0;
                    }
#line 7690 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 371:
#line 2618 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = 0;
                    }
#line 7698 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 372:
#line 2622 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = (yyvsp[-2].nd);
                    }
#line 7706 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 373:
#line 2629 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = 0;
                    }
#line 7714 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 374:
#line 2633 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = 0;
                    }
#line 7722 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 377:
#line 2643 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      local_add_f(p, (yyvsp[0].id));
                      new_bv(p, (yyvsp[0].id));
                    }
#line 7731 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 379:
#line 2651 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = (yyvsp[-2].nd);
                    }
#line 7739 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 380:
#line 2655 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = (yyvsp[0].nd);
                    }
#line 7747 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 381:
#line 2661 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = (yyvsp[-1].nd);
                    }
#line 7755 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 382:
#line 2665 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = (yyvsp[-1].nd);
                    }
#line 7763 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 383:
#line 2671 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      local_nest(p);
                    }
#line 7771 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 384:
#line 2677 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_block(p,(yyvsp[-2].nd),(yyvsp[-1].nd));
                      local_unnest(p);
                    }
#line 7780 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 385:
#line 2684 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      if ((yyvsp[-1].nd)->car == (node*)NODE_YIELD) {
                        yyerror(p, "block given to yield");
                      }
                      else {
                        call_with_block(p, (yyvsp[-1].nd), (yyvsp[0].nd));
                      }
                      (yyval.nd) = (yyvsp[-1].nd);
                    }
#line 7794 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 386:
#line 2694 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_call(p, (yyvsp[-3].nd), (yyvsp[-1].id), (yyvsp[0].nd), (yyvsp[-2].num));
                    }
#line 7802 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 387:
#line 2698 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_call(p, (yyvsp[-4].nd), (yyvsp[-2].id), (yyvsp[-1].nd), (yyvsp[-3].num));
                      call_with_block(p, (yyval.nd), (yyvsp[0].nd));
                    }
#line 7811 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 388:
#line 2703 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_call(p, (yyvsp[-4].nd), (yyvsp[-2].id), (yyvsp[-1].nd), (yyvsp[-3].num));
                      call_with_block(p, (yyval.nd), (yyvsp[0].nd));
                    }
#line 7820 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 389:
#line 2710 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_fcall(p, (yyvsp[-1].id), (yyvsp[0].nd));
                    }
#line 7828 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 390:
#line 2714 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_call(p, (yyvsp[-3].nd), (yyvsp[-1].id), (yyvsp[0].nd), (yyvsp[-2].num));
                    }
#line 7836 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 391:
#line 2718 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_call(p, (yyvsp[-3].nd), (yyvsp[-1].id), (yyvsp[0].nd), tCOLON2);
                    }
#line 7844 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 392:
#line 2722 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_call(p, (yyvsp[-2].nd), (yyvsp[0].id), 0, tCOLON2);
                    }
#line 7852 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 393:
#line 2726 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_call(p, (yyvsp[-2].nd), intern("call",4), (yyvsp[0].nd), (yyvsp[-1].num));
                    }
#line 7860 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 394:
#line 2730 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_call(p, (yyvsp[-2].nd), intern("call",4), (yyvsp[0].nd), tCOLON2);
                    }
#line 7868 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 395:
#line 2734 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_super(p, (yyvsp[0].nd));
                    }
#line 7876 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 396:
#line 2738 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_zsuper(p);
                    }
#line 7884 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 397:
#line 2742 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_call(p, (yyvsp[-3].nd), intern("[]",2), (yyvsp[-1].nd), '.');
                    }
#line 7892 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 398:
#line 2748 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      local_nest(p);
                      (yyval.num) = p->lineno;
                    }
#line 7901 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 399:
#line 2754 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_block(p,(yyvsp[-2].nd),(yyvsp[-1].nd));
                      SET_LINENO((yyval.nd), (yyvsp[-3].num));
                      local_unnest(p);
                    }
#line 7911 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 400:
#line 2760 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      local_nest(p);
                      (yyval.num) = p->lineno;
                    }
#line 7920 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 401:
#line 2766 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_block(p,(yyvsp[-2].nd),(yyvsp[-1].nd));
                      SET_LINENO((yyval.nd), (yyvsp[-3].num));
                      local_unnest(p);
                    }
#line 7930 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 402:
#line 2776 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = cons(cons((yyvsp[-3].nd), (yyvsp[-1].nd)), (yyvsp[0].nd));
                    }
#line 7938 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 403:
#line 2782 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      if ((yyvsp[0].nd)) {
                        (yyval.nd) = cons(cons(0, (yyvsp[0].nd)), 0);
                      }
                      else {
                        (yyval.nd) = 0;
                      }
                    }
#line 7951 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 405:
#line 2796 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = list1(list3((yyvsp[-4].nd), (yyvsp[-3].nd), (yyvsp[-1].nd)));
                      if ((yyvsp[0].nd)) (yyval.nd) = append((yyval.nd), (yyvsp[0].nd));
                    }
#line 7960 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 407:
#line 2804 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                        (yyval.nd) = list1((yyvsp[0].nd));
                    }
#line 7968 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 410:
#line 2812 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = (yyvsp[0].nd);
                    }
#line 7976 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 412:
#line 2819 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = (yyvsp[0].nd);
                    }
#line 7984 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 420:
#line 2834 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = (yyvsp[0].nd);
                    }
#line 7992 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 421:
#line 2838 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_dstr(p, push((yyvsp[-1].nd), (yyvsp[0].nd)));
                    }
#line 8000 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 423:
#line 2845 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = append((yyvsp[-1].nd), (yyvsp[0].nd));
                    }
#line 8008 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 424:
#line 2851 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = list1((yyvsp[0].nd));
                    }
#line 8016 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 425:
#line 2855 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = p->lex_strterm;
                      p->lex_strterm = NULL;
                    }
#line 8025 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 426:
#line 2861 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      p->lex_strterm = (yyvsp[-2].nd);
                      (yyval.nd) = list2((yyvsp[-3].nd), (yyvsp[-1].nd));
                    }
#line 8034 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 427:
#line 2866 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = list1(new_literal_delim(p));
                    }
#line 8042 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 428:
#line 2870 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = list1(new_literal_delim(p));
                    }
#line 8050 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 429:
#line 2876 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                        (yyval.nd) = (yyvsp[0].nd);
                    }
#line 8058 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 430:
#line 2880 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_dxstr(p, push((yyvsp[-1].nd), (yyvsp[0].nd)));
                    }
#line 8066 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 431:
#line 2886 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                        (yyval.nd) = (yyvsp[0].nd);
                    }
#line 8074 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 432:
#line 2890 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_dregx(p, (yyvsp[-1].nd), (yyvsp[0].nd));
                    }
#line 8082 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 436:
#line 2903 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      parser_heredoc_info * inf = parsing_heredoc_inf(p);
                      inf->doc = push(inf->doc, new_str(p, "", 0));
                      heredoc_end(p);
                    }
#line 8092 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 437:
#line 2909 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      heredoc_end(p);
                    }
#line 8100 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 440:
#line 2919 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      parser_heredoc_info * inf = parsing_heredoc_inf(p);
                      inf->doc = push(inf->doc, (yyvsp[0].nd));
                      heredoc_treat_nextline(p);
                    }
#line 8110 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 441:
#line 2925 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = p->lex_strterm;
                      p->lex_strterm = NULL;
                    }
#line 8119 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 442:
#line 2931 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      parser_heredoc_info * inf = parsing_heredoc_inf(p);
                      p->lex_strterm = (yyvsp[-2].nd);
                      inf->doc = push(push(inf->doc, (yyvsp[-3].nd)), (yyvsp[-1].nd));
                    }
#line 8129 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 443:
#line 2939 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_words(p, list1((yyvsp[0].nd)));
                    }
#line 8137 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 444:
#line 2943 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_words(p, push((yyvsp[-1].nd), (yyvsp[0].nd)));
                    }
#line 8145 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 445:
#line 2950 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      p->lstate = EXPR_ENDARG;
                      (yyval.nd) = new_sym(p, (yyvsp[0].id));
                    }
#line 8154 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 446:
#line 2955 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      p->lstate = EXPR_ENDARG;
                      (yyval.nd) = new_dsym(p, new_dstr(p, push((yyvsp[-1].nd), (yyvsp[0].nd))));
                    }
#line 8163 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 447:
#line 2962 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.id) = (yyvsp[0].id);
                    }
#line 8171 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 452:
#line 2972 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.id) = new_strsym(p, (yyvsp[0].nd));
                    }
#line 8179 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 453:
#line 2976 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.id) = new_strsym(p, (yyvsp[0].nd));
                    }
#line 8187 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 454:
#line 2982 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_symbols(p, list1((yyvsp[0].nd)));
                    }
#line 8195 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 455:
#line 2986 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_symbols(p, push((yyvsp[-1].nd), (yyvsp[0].nd)));
                    }
#line 8203 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 458:
#line 2994 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = negate_lit(p, (yyvsp[0].nd));
                    }
#line 8211 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 459:
#line 2998 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = negate_lit(p, (yyvsp[0].nd));
                    }
#line 8219 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 460:
#line 3004 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_lvar(p, (yyvsp[0].id));
                    }
#line 8227 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 461:
#line 3008 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_ivar(p, (yyvsp[0].id));
                    }
#line 8235 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 462:
#line 3012 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_gvar(p, (yyvsp[0].id));
                    }
#line 8243 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 463:
#line 3016 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_cvar(p, (yyvsp[0].id));
                    }
#line 8251 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 464:
#line 3020 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_const(p, (yyvsp[0].id));
                    }
#line 8259 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 465:
#line 3026 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      assignable(p, (yyvsp[0].nd));
                    }
#line 8267 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 466:
#line 3032 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = var_reference(p, (yyvsp[0].nd));
                    }
#line 8275 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 467:
#line 3036 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_nil(p);
                    }
#line 8283 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 468:
#line 3040 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_self(p);
                    }
#line 8291 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 469:
#line 3044 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_true(p);
                    }
#line 8299 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 470:
#line 3048 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_false(p);
                    }
#line 8307 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 471:
#line 3052 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      const char *fn = p->filename;
                      if (!fn) {
                        fn = "(null)";
                      }
                      (yyval.nd) = new_str(p, fn, strlen(fn));
                    }
#line 8319 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 472:
#line 3060 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      char buf[16];

                      snprintf(buf, sizeof(buf), "%d", p->lineno);
                      (yyval.nd) = new_int(p, buf, 10);
                    }
#line 8330 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 473:
#line 3067 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
#ifdef MRB_UTF8_STRING
                      const char *enc = "UTF-8";
#else
                      const char *enc = "ASCII-8BIT";
#endif
                      (yyval.nd) = new_str(p, enc, strlen(enc));
                    }
#line 8343 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 476:
#line 3082 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = 0;
                    }
#line 8351 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 477:
#line 3086 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      p->lstate = EXPR_BEG;
                      p->cmd_start = TRUE;
                    }
#line 8360 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 478:
#line 3091 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = (yyvsp[-1].nd);
                    }
#line 8368 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 479:
#line 3102 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = (yyvsp[-1].nd);
                      p->lstate = EXPR_BEG;
                      p->cmd_start = TRUE;
                    }
#line 8378 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 480:
#line 3108 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = (yyvsp[-1].nd);
                    }
#line 8386 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 482:
#line 3117 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      void_expr_error(p, (yyvsp[0].nd));
                      (yyval.nd) = new_kw_arg(p, (yyvsp[-1].id), (yyvsp[0].nd));
                    }
#line 8395 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 483:
#line 3122 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_kw_arg(p, (yyvsp[0].id), 0);
                    }
#line 8403 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 484:
#line 3128 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_kw_arg(p, (yyvsp[-1].id), (yyvsp[0].nd));
                    }
#line 8411 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 485:
#line 3132 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_kw_arg(p, (yyvsp[0].id), 0);
                    }
#line 8419 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 486:
#line 3138 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = list1((yyvsp[0].nd));
                    }
#line 8427 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 487:
#line 3142 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = push((yyvsp[-2].nd), (yyvsp[0].nd));
                    }
#line 8435 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 488:
#line 3148 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = list1((yyvsp[0].nd));
                    }
#line 8443 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 489:
#line 3152 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = push((yyvsp[-2].nd), (yyvsp[0].nd));
                    }
#line 8451 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 492:
#line 3162 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = cons((node*)NODE_KW_REST_ARGS, nsym((yyvsp[0].id)));
                    }
#line 8459 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 493:
#line 3166 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = cons((node*)NODE_KW_REST_ARGS, 0);
                    }
#line 8467 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 494:
#line 3172 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_args_tail(p, (yyvsp[-3].nd), (yyvsp[-1].nd), (yyvsp[0].id));
                    }
#line 8475 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 495:
#line 3176 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_args_tail(p, (yyvsp[-1].nd), 0, (yyvsp[0].id));
                    }
#line 8483 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 496:
#line 3180 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_args_tail(p, 0, (yyvsp[-1].nd), (yyvsp[0].id));
                    }
#line 8491 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 497:
#line 3184 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_args_tail(p, 0, 0, (yyvsp[0].id));
                    }
#line 8499 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 498:
#line 3190 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = (yyvsp[0].nd);
                    }
#line 8507 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 499:
#line 3194 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_args_tail(p, 0, 0, 0);
                    }
#line 8515 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 500:
#line 3200 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_args(p, (yyvsp[-5].nd), (yyvsp[-3].nd), (yyvsp[-1].id), 0, (yyvsp[0].nd));
                    }
#line 8523 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 501:
#line 3204 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_args(p, (yyvsp[-7].nd), (yyvsp[-5].nd), (yyvsp[-3].id), (yyvsp[-1].nd), (yyvsp[0].nd));
                    }
#line 8531 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 502:
#line 3208 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_args(p, (yyvsp[-3].nd), (yyvsp[-1].nd), 0, 0, (yyvsp[0].nd));
                    }
#line 8539 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 503:
#line 3212 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_args(p, (yyvsp[-5].nd), (yyvsp[-3].nd), 0, (yyvsp[-1].nd), (yyvsp[0].nd));
                    }
#line 8547 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 504:
#line 3216 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_args(p, (yyvsp[-3].nd), 0, (yyvsp[-1].id), 0, (yyvsp[0].nd));
                    }
#line 8555 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 505:
#line 3220 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_args(p, (yyvsp[-5].nd), 0, (yyvsp[-3].id), (yyvsp[-1].nd), (yyvsp[0].nd));
                    }
#line 8563 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 506:
#line 3224 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_args(p, (yyvsp[-1].nd), 0, 0, 0, (yyvsp[0].nd));
                    }
#line 8571 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 507:
#line 3228 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_args(p, 0, (yyvsp[-3].nd), (yyvsp[-1].id), 0, (yyvsp[0].nd));
                    }
#line 8579 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 508:
#line 3232 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_args(p, 0, (yyvsp[-5].nd), (yyvsp[-3].id), (yyvsp[-1].nd), (yyvsp[0].nd));
                    }
#line 8587 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 509:
#line 3236 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_args(p, 0, (yyvsp[-1].nd), 0, 0, (yyvsp[0].nd));
                    }
#line 8595 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 510:
#line 3240 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_args(p, 0, (yyvsp[-3].nd), 0, (yyvsp[-1].nd), (yyvsp[0].nd));
                    }
#line 8603 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 511:
#line 3244 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_args(p, 0, 0, (yyvsp[-1].id), 0, (yyvsp[0].nd));
                    }
#line 8611 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 512:
#line 3248 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_args(p, 0, 0, (yyvsp[-3].id), (yyvsp[-1].nd), (yyvsp[0].nd));
                    }
#line 8619 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 513:
#line 3252 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_args(p, 0, 0, 0, 0, (yyvsp[0].nd));
                    }
#line 8627 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 514:
#line 3256 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      local_add_f(p, mrb_intern_lit(p->mrb, "&"));
                      (yyval.nd) = new_args(p, 0, 0, 0, 0, 0);
                    }
#line 8636 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 515:
#line 3263 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      yyerror(p, "formal argument cannot be a constant");
                      (yyval.nd) = 0;
                    }
#line 8645 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 516:
#line 3268 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      yyerror(p, "formal argument cannot be an instance variable");
                      (yyval.nd) = 0;
                    }
#line 8654 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 517:
#line 3273 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      yyerror(p, "formal argument cannot be a global variable");
                      (yyval.nd) = 0;
                    }
#line 8663 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 518:
#line 3278 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      yyerror(p, "formal argument cannot be a class variable");
                      (yyval.nd) = 0;
                    }
#line 8672 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 519:
#line 3285 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.id) = 0;
                    }
#line 8680 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 520:
#line 3289 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      local_add_f(p, (yyvsp[0].id));
                      (yyval.id) = (yyvsp[0].id);
                    }
#line 8689 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 521:
#line 3296 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_arg(p, (yyvsp[0].id));
                    }
#line 8697 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 522:
#line 3300 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = local_switch(p);
                    }
#line 8705 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 523:
#line 3304 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_masgn(p, (yyvsp[-1].nd), p->locals->car);
                      local_resume(p, (yyvsp[-2].nd));
                      local_add_f(p, 0);
                    }
#line 8715 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 524:
#line 3312 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = list1((yyvsp[0].nd));
                    }
#line 8723 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 525:
#line 3316 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = push((yyvsp[-2].nd), (yyvsp[0].nd));
                    }
#line 8731 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 526:
#line 3322 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      local_add_f(p, (yyvsp[-1].id));
                      (yyval.id) = (yyvsp[-1].id);
                    }
#line 8740 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 527:
#line 3329 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      void_expr_error(p, (yyvsp[0].nd));
                      (yyval.nd) = cons(nsym((yyvsp[-1].id)), (yyvsp[0].nd));
                    }
#line 8749 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 528:
#line 3336 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      void_expr_error(p, (yyvsp[0].nd));
                      (yyval.nd) = cons(nsym((yyvsp[-1].id)), (yyvsp[0].nd));
                    }
#line 8758 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 529:
#line 3343 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = list1((yyvsp[0].nd));
                    }
#line 8766 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 530:
#line 3347 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = push((yyvsp[-2].nd), (yyvsp[0].nd));
                    }
#line 8774 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 531:
#line 3353 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = list1((yyvsp[0].nd));
                    }
#line 8782 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 532:
#line 3357 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = push((yyvsp[-2].nd), (yyvsp[0].nd));
                    }
#line 8790 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 535:
#line 3367 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      local_add_f(p, (yyvsp[0].id));
                      (yyval.id) = (yyvsp[0].id);
                    }
#line 8799 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 536:
#line 3372 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      local_add_f(p, mrb_intern_lit(p->mrb, "*"));
                      (yyval.id) = -1;
                    }
#line 8808 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 539:
#line 3383 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.id) = (yyvsp[0].id);
                    }
#line 8816 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 540:
#line 3389 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.id) = (yyvsp[0].id);
                    }
#line 8824 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 541:
#line 3393 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.id) = 0;
                    }
#line 8832 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 542:
#line 3399 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = (yyvsp[0].nd);
                      if (!(yyval.nd)) (yyval.nd) = new_nil(p);
                    }
#line 8841 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 543:
#line 3403 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {p->lstate = EXPR_BEG;}
#line 8847 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 544:
#line 3404 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      if ((yyvsp[-1].nd) == 0) {
                        yyerror(p, "can't define singleton method for ().");
                      }
                      else {
                        switch ((enum node_type)intn((yyvsp[-1].nd)->car)) {
                        case NODE_STR:
                        case NODE_DSTR:
                        case NODE_XSTR:
                        case NODE_DXSTR:
                        case NODE_DREGX:
                        case NODE_MATCH:
                        case NODE_FLOAT:
                        case NODE_ARRAY:
                        case NODE_HEREDOC:
                          yyerror(p, "can't define singleton method for literals");
                        default:
                          break;
                        }
                      }
                      (yyval.nd) = (yyvsp[-1].nd);
                    }
#line 8874 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 546:
#line 3430 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = (yyvsp[-1].nd);
                    }
#line 8882 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 547:
#line 3436 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = list1((yyvsp[0].nd));
                      NODE_LINENO((yyval.nd), (yyvsp[0].nd));
                    }
#line 8891 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 548:
#line 3441 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = push((yyvsp[-2].nd), (yyvsp[0].nd));
                    }
#line 8899 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 549:
#line 3447 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      void_expr_error(p, (yyvsp[-2].nd));
                      void_expr_error(p, (yyvsp[0].nd));
                      (yyval.nd) = cons((yyvsp[-2].nd), (yyvsp[0].nd));
                    }
#line 8909 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 550:
#line 3453 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      void_expr_error(p, (yyvsp[0].nd));
                      (yyval.nd) = cons(new_sym(p, (yyvsp[-2].id)), (yyvsp[0].nd));
                    }
#line 8918 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 551:
#line 3458 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      void_expr_error(p, (yyvsp[0].nd));
                      if ((yyvsp[-2].nd)->car == (node*)NODE_DSTR) {
                        (yyval.nd) = cons(new_dsym(p, (yyvsp[-2].nd)), (yyvsp[0].nd));
                      }
                      else {
                        (yyval.nd) = cons(new_sym(p, new_strsym(p, (yyvsp[-2].nd))), (yyvsp[0].nd));
                      }
                    }
#line 8932 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 552:
#line 3468 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      void_expr_error(p, (yyvsp[0].nd));
                      (yyval.nd) = cons(cons((node*)NODE_KW_REST_ARGS, 0), (yyvsp[0].nd));
                    }
#line 8941 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 565:
#line 3495 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.num) = '.';
                    }
#line 8949 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 566:
#line 3499 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.num) = 0;
                    }
#line 8957 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 568:
#line 3506 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.num) = tCOLON2;
                    }
#line 8965 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 578:
#line 3530 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {yyerrok;}
#line 8971 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 581:
#line 3536 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      p->lineno++;
                      p->column = 0;
                    }
#line 8980 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 584:
#line 3547 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = 0;
                    }
#line 8988 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;


#line 8992 "/home/shimo/TECS2MrubyBridhePlugin/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (p, YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (p, yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, p);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, p);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (p, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, p);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, p);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 3551 "/home/shimo/TECS2MrubyBridhePlugin/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1906  */

#define pylval  (*((YYSTYPE*)(p->ylval)))

static void
yyerror(parser_state *p, const char *s)
{
  char* c;
  size_t n;

  if (! p->capture_errors) {
#ifndef MRB_DISABLE_STDIO
    if (p->filename) {
      fprintf(stderr, "%s:%d:%d: %s\n", p->filename, p->lineno, p->column, s);
    }
    else {
      fprintf(stderr, "line %d:%d: %s\n", p->lineno, p->column, s);
    }
#endif
  }
  else if (p->nerr < sizeof(p->error_buffer) / sizeof(p->error_buffer[0])) {
    n = strlen(s);
    c = (char *)parser_palloc(p, n + 1);
    memcpy(c, s, n + 1);
    p->error_buffer[p->nerr].message = c;
    p->error_buffer[p->nerr].lineno = p->lineno;
    p->error_buffer[p->nerr].column = p->column;
  }
  p->nerr++;
}

static void
yyerror_i(parser_state *p, const char *fmt, int i)
{
  char buf[256];

  snprintf(buf, sizeof(buf), fmt, i);
  yyerror(p, buf);
}

static void
yywarn(parser_state *p, const char *s)
{
  char* c;
  size_t n;

  if (! p->capture_errors) {
#ifndef MRB_DISABLE_STDIO
    if (p->filename) {
      fprintf(stderr, "%s:%d:%d: %s\n", p->filename, p->lineno, p->column, s);
    }
    else {
      fprintf(stderr, "line %d:%d: %s\n", p->lineno, p->column, s);
    }
#endif
  }
  else if (p->nwarn < sizeof(p->warn_buffer) / sizeof(p->warn_buffer[0])) {
    n = strlen(s);
    c = (char *)parser_palloc(p, n + 1);
    memcpy(c, s, n + 1);
    p->warn_buffer[p->nwarn].message = c;
    p->warn_buffer[p->nwarn].lineno = p->lineno;
    p->warn_buffer[p->nwarn].column = p->column;
  }
  p->nwarn++;
}

static void
yywarning(parser_state *p, const char *s)
{
  yywarn(p, s);
}

static void
yywarning_s(parser_state *p, const char *fmt, const char *s)
{
  char buf[256];

  snprintf(buf, sizeof(buf), fmt, s);
  yywarning(p, buf);
}

static void
backref_error(parser_state *p, node *n)
{
  int c;

  c = intn(n->car);

  if (c == NODE_NTH_REF) {
    yyerror_i(p, "can't set variable $%" MRB_PRId, intn(n->cdr));
  }
  else if (c == NODE_BACK_REF) {
    yyerror_i(p, "can't set variable $%c", intn(n->cdr));
  }
  else {
    mrb_bug(p->mrb, "Internal error in backref_error() : n=>car == %S", mrb_fixnum_value(c));
  }
}

static void
void_expr_error(parser_state *p, node *n)
{
  int c;

  if (n == NULL) return;
  c = intn(n->car);
  switch (c) {
  case NODE_BREAK:
  case NODE_RETURN:
  case NODE_NEXT:
  case NODE_REDO:
  case NODE_RETRY:
    yyerror(p, "void value expression");
    break;
  case NODE_AND:
  case NODE_OR:
    void_expr_error(p, n->cdr->car);
    void_expr_error(p, n->cdr->cdr);
    break;
  case NODE_BEGIN:
    if (n->cdr) {
      while (n->cdr) {
        n = n->cdr;
      }
      void_expr_error(p, n->car);
    }
    break;
  default:
    break;
  }
}

static void pushback(parser_state *p, int c);
static mrb_bool peeks(parser_state *p, const char *s);
static mrb_bool skips(parser_state *p, const char *s);

static inline int
nextc(parser_state *p)
{
  int c;

  if (p->pb) {
    node *tmp;

    c = intn(p->pb->car);
    tmp = p->pb;
    p->pb = p->pb->cdr;
    cons_free(tmp);
  }
  else {
#ifndef MRB_DISABLE_STDIO
    if (p->f) {
      if (feof(p->f)) goto eof;
      c = fgetc(p->f);
      if (c == EOF) goto eof;
    }
    else
#endif
      if (!p->s || p->s >= p->send) {
        goto eof;
      }
      else {
        c = (unsigned char)*p->s++;
      }
  }
  if (c >= 0) {
    p->column++;
  }
  return c;

  eof:
  if (!p->cxt) return -1;
  else {
    if (p->cxt->partial_hook(p) < 0)
      return -1;                /* end of program(s) */
    return -2;                  /* end of a file in the program files */
  }
}

static void
pushback(parser_state *p, int c)
{
  if (c >= 0) {
    p->column--;
  }
  p->pb = cons(nint(c), p->pb);
}

static void
skip(parser_state *p, char term)
{
  int c;

  for (;;) {
    c = nextc(p);
    if (c < 0) break;
    if (c == term) break;
  }
}

static int
peekc_n(parser_state *p, int n)
{
  node *list = 0;
  int c0;

  do {
    c0 = nextc(p);
    if (c0 == -1) return c0;    /* do not skip partial EOF */
    if (c0 >= 0) --p->column;
    list = push(list, nint(c0));
  } while(n--);
  if (p->pb) {
    p->pb = append((node*)list, p->pb);
  }
  else {
    p->pb = list;
  }
  return c0;
}

static mrb_bool
peek_n(parser_state *p, int c, int n)
{
  return peekc_n(p, n) == c && c >= 0;
}
#define peek(p,c) peek_n((p), (c), 0)

static mrb_bool
peeks(parser_state *p, const char *s)
{
  size_t len = strlen(s);

#ifndef MRB_DISABLE_STDIO
  if (p->f) {
    int n = 0;
    while (*s) {
      if (!peek_n(p, *s++, n++)) return FALSE;
    }
    return TRUE;
  }
  else
#endif
    if (p->s && p->s + len <= p->send) {
      if (memcmp(p->s, s, len) == 0) return TRUE;
    }
  return FALSE;
}

static mrb_bool
skips(parser_state *p, const char *s)
{
  int c;

  for (;;) {
    /* skip until first char */
    for (;;) {
      c = nextc(p);
      if (c < 0) return FALSE;
      if (c == '\n') {
        p->lineno++;
        p->column = 0;
      }
      if (c == *s) break;
    }
    s++;
    if (peeks(p, s)) {
      size_t len = strlen(s);

      while (len--) {
        if (nextc(p) == '\n') {
          p->lineno++;
          p->column = 0;
        }
      }
      return TRUE;
    }
    else{
      s--;
    }
  }
  return FALSE;
}


static int
newtok(parser_state *p)
{
  if (p->tokbuf != p->buf) {
    mrb_free(p->mrb, p->tokbuf);
    p->tokbuf = p->buf;
    p->tsiz = MRB_PARSER_TOKBUF_SIZE;
  }
  p->tidx = 0;
  return p->column - 1;
}

static void
tokadd(parser_state *p, int32_t c)
{
  char utf8[4];
  int i, len;

  /* mrb_assert(-0x10FFFF <= c && c <= 0xFF); */
  if (c >= 0) {
    /* Single byte from source or non-Unicode escape */
    utf8[0] = (char)c;
    len = 1;
  }
  else {
    /* Unicode character */
    c = -c;
    if (c < 0x80) {
      utf8[0] = (char)c;
      len = 1;
    }
    else if (c < 0x800) {
      utf8[0] = (char)(0xC0 | (c >> 6));
      utf8[1] = (char)(0x80 | (c & 0x3F));
      len = 2;
    }
    else if (c < 0x10000) {
      utf8[0] = (char)(0xE0 |  (c >> 12)        );
      utf8[1] = (char)(0x80 | ((c >>  6) & 0x3F));
      utf8[2] = (char)(0x80 | ( c        & 0x3F));
      len = 3;
    }
    else {
      utf8[0] = (char)(0xF0 |  (c >> 18)        );
      utf8[1] = (char)(0x80 | ((c >> 12) & 0x3F));
      utf8[2] = (char)(0x80 | ((c >>  6) & 0x3F));
      utf8[3] = (char)(0x80 | ( c        & 0x3F));
      len = 4;
    }
  }
  if (p->tidx+len >= p->tsiz) {
    if (p->tsiz >= MRB_PARSER_TOKBUF_MAX) {
      p->tidx += len;
      return;
    }
    p->tsiz *= 2;
    if (p->tokbuf == p->buf) {
      p->tokbuf = (char*)mrb_malloc(p->mrb, p->tsiz);
      memcpy(p->tokbuf, p->buf, MRB_PARSER_TOKBUF_SIZE);
    }
    else {
      p->tokbuf = (char*)mrb_realloc(p->mrb, p->tokbuf, p->tsiz);
    }
  }
  for (i = 0; i < len; i++) {
    p->tokbuf[p->tidx++] = utf8[i];
  }
}

static int
toklast(parser_state *p)
{
  return p->tokbuf[p->tidx-1];
}

static void
tokfix(parser_state *p)
{
  if (p->tidx >= MRB_PARSER_TOKBUF_MAX) {
    p->tidx = MRB_PARSER_TOKBUF_MAX-1;
    yyerror(p, "string too long (truncated)");
  }
  p->tokbuf[p->tidx] = '\0';
}

static const char*
tok(parser_state *p)
{
  return p->tokbuf;
}

static int
toklen(parser_state *p)
{
  return p->tidx;
}

#define IS_ARG() (p->lstate == EXPR_ARG || p->lstate == EXPR_CMDARG)
#define IS_END() (p->lstate == EXPR_END || p->lstate == EXPR_ENDARG || p->lstate == EXPR_ENDFN)
#define IS_BEG() (p->lstate == EXPR_BEG || p->lstate == EXPR_MID || p->lstate == EXPR_VALUE || p->lstate == EXPR_CLASS)
#define IS_SPCARG(c) (IS_ARG() && space_seen && !ISSPACE(c))
#define IS_LABEL_POSSIBLE() ((p->lstate == EXPR_BEG && !cmd_state) || IS_ARG())
#define IS_LABEL_SUFFIX(n) (peek_n(p, ':',(n)) && !peek_n(p, ':', (n)+1))

static int32_t
scan_oct(const int *start, int len, int *retlen)
{
  const int *s = start;
  int32_t retval = 0;

  /* mrb_assert(len <= 3) */
  while (len-- && *s >= '0' && *s <= '7') {
    retval <<= 3;
    retval |= *s++ - '0';
  }
  *retlen = (int)(s - start);

  return retval;
}

static int32_t
scan_hex(parser_state *p, const int *start, int len, int *retlen)
{
  static const char hexdigit[] = "0123456789abcdef0123456789ABCDEF";
  const int *s = start;
  uint32_t retval = 0;
  char *tmp;

  /* mrb_assert(len <= 8) */
  while (len-- && *s && (tmp = (char*)strchr(hexdigit, *s))) {
    retval <<= 4;
    retval |= (tmp - hexdigit) & 15;
    s++;
  }
  *retlen = (int)(s - start);

  return (int32_t)retval;
}

static int32_t
read_escape_unicode(parser_state *p, int limit)
{
  int buf[9];
  int i;
  int32_t hex;

  /* Look for opening brace */
  i = 0;
  buf[0] = nextc(p);
  if (buf[0] < 0) {
  eof:
    yyerror(p, "invalid escape character syntax");
    return -1;
  }
  if (ISXDIGIT(buf[0])) {
    /* \uxxxx form */
    for (i=1; i<limit; i++) {
      buf[i] = nextc(p);
      if (buf[i] < 0) goto eof;
      if (!ISXDIGIT(buf[i])) {
        pushback(p, buf[i]);
        break;
      }
    }
  }
  else {
    pushback(p, buf[0]);
  }
  hex = scan_hex(p, buf, i, &i);
  if (i == 0 || hex > 0x10FFFF || (hex & 0xFFFFF800) == 0xD800) {
    yyerror(p, "invalid Unicode code point");
    return -1;
  }
  return hex;
}

/* Return negative to indicate Unicode code point */
static int32_t
read_escape(parser_state *p)
{
  int32_t c;

  switch (c = nextc(p)) {
  case '\\':/* Backslash */
    return c;

  case 'n':/* newline */
    return '\n';

  case 't':/* horizontal tab */
    return '\t';

  case 'r':/* carriage-return */
    return '\r';

  case 'f':/* form-feed */
    return '\f';

  case 'v':/* vertical tab */
    return '\13';

  case 'a':/* alarm(bell) */
    return '\007';

  case 'e':/* escape */
    return 033;

  case '0': case '1': case '2': case '3': /* octal constant */
  case '4': case '5': case '6': case '7':
  {
    int buf[3];
    int i;

    buf[0] = c;
    for (i=1; i<3; i++) {
      buf[i] = nextc(p);
      if (buf[i] < 0) goto eof;
      if (buf[i] < '0' || '7' < buf[i]) {
        pushback(p, buf[i]);
        break;
      }
    }
    c = scan_oct(buf, i, &i);
  }
  return c;

  case 'x':     /* hex constant */
  {
    int buf[2];
    int i;

    for (i=0; i<2; i++) {
      buf[i] = nextc(p);
      if (buf[i] < 0) goto eof;
      if (!ISXDIGIT(buf[i])) {
        pushback(p, buf[i]);
        break;
      }
    }
    if (i == 0) {
      yyerror(p, "invalid hex escape");
      return -1;
    }
    return scan_hex(p, buf, i, &i);
  }

  case 'u':     /* Unicode */
    if (peek(p, '{')) {
      /* \u{xxxxxxxx} form */
      nextc(p);
      c = read_escape_unicode(p, 8);
      if (c < 0) return 0;
      if (nextc(p) != '}') goto eof;
    }
    else {
      c = read_escape_unicode(p, 4);
      if (c < 0) return 0;
    }
  return -c;

  case 'b':/* backspace */
    return '\010';

  case 's':/* space */
    return ' ';

  case 'M':
    if ((c = nextc(p)) != '-') {
      yyerror(p, "Invalid escape character syntax");
      pushback(p, c);
      return '\0';
    }
    if ((c = nextc(p)) == '\\') {
      return read_escape(p) | 0x80;
    }
    else if (c < 0) goto eof;
    else {
      return ((c & 0xff) | 0x80);
    }

  case 'C':
    if ((c = nextc(p)) != '-') {
      yyerror(p, "Invalid escape character syntax");
      pushback(p, c);
      return '\0';
    }
  case 'c':
    if ((c = nextc(p))== '\\') {
      c = read_escape(p);
    }
    else if (c == '?')
      return 0177;
    else if (c < 0) goto eof;
    return c & 0x9f;

    eof:
  case -1:
  case -2:                      /* end of a file */
    yyerror(p, "Invalid escape character syntax");
    return '\0';

  default:
    return c;
  }
}

static int
parse_string(parser_state *p)
{
  int c;
  string_type type = (string_type)(intptr_t)p->lex_strterm->car;
  int nest_level = intn(p->lex_strterm->cdr->car);
  int beg = intn(p->lex_strterm->cdr->cdr->car);
  int end = intn(p->lex_strterm->cdr->cdr->cdr);
  parser_heredoc_info *hinf = (type & STR_FUNC_HEREDOC) ? parsing_heredoc_inf(p) : NULL;

  if (beg == 0) beg = -3;       /* should never happen */
  if (end == 0) end = -3;
  newtok(p);
  while ((c = nextc(p)) != end || nest_level != 0) {
    if (hinf && (c == '\n' || c < 0)) {
      mrb_bool line_head;
      tokadd(p, '\n');
      tokfix(p);
      p->lineno++;
      p->column = 0;
      line_head = hinf->line_head;
      hinf->line_head = TRUE;
      if (line_head) {
        /* check whether end of heredoc */
        const char *s = tok(p);
        int len = toklen(p);
        if (hinf->allow_indent) {
          while (ISSPACE(*s) && len > 0) {
            ++s;
            --len;
          }
        }
        if ((len-1 == hinf->term_len) && (strncmp(s, hinf->term, len-1) == 0)) {
          if (c < 0) {
            p->parsing_heredoc = NULL;
          }
          else {
            return tHEREDOC_END;
          }
        }
      }
      if (c < 0) {
        char buf[256];
        snprintf(buf, sizeof(buf), "can't find heredoc delimiter \"%s\" anywhere before EOF", hinf->term);
        yyerror(p, buf);
        return 0;
      }
      pylval.nd = new_str(p, tok(p), toklen(p));
      return tHD_STRING_MID;
    }
    if (c < 0) {
      yyerror(p, "unterminated string meets end of file");
      return 0;
    }
    else if (c == beg) {
      nest_level++;
      p->lex_strterm->cdr->car = nint(nest_level);
    }
    else if (c == end) {
      nest_level--;
      p->lex_strterm->cdr->car = nint(nest_level);
    }
    else if (c == '\\') {
      c = nextc(p);
      if (type & STR_FUNC_EXPAND) {
        if (c == end || c == beg) {
          tokadd(p, c);
        }
        else if (c == '\n') {
          p->lineno++;
          p->column = 0;
          if (type & STR_FUNC_ARRAY) {
            tokadd(p, '\n');
          }
        }
        else if (type & STR_FUNC_REGEXP) {
          tokadd(p, '\\');
          tokadd(p, c);
        }
        else if (c == 'u' && peek(p, '{')) {
          /* \u{xxxx xxxx xxxx} form */
          nextc(p);
          while (1) {
            do c = nextc(p); while (ISSPACE(c));
            if (c == '}') break;
            pushback(p, c);
            c = read_escape_unicode(p, 8);
            if (c < 0) break;
            tokadd(p, -c);
          }
          if (hinf)
            hinf->line_head = FALSE;
        }
        else {
          pushback(p, c);
          tokadd(p, read_escape(p));
          if (hinf)
            hinf->line_head = FALSE;
        }
      }
      else {
        if (c != beg && c != end) {
          if (c == '\n') {
            p->lineno++;
            p->column = 0;
          }
          if (!(c == '\\' || ((type & STR_FUNC_ARRAY) && ISSPACE(c)))) {
            tokadd(p, '\\');
          }
        }
        tokadd(p, c);
      }
      continue;
    }
    else if ((c == '#') && (type & STR_FUNC_EXPAND)) {
      c = nextc(p);
      if (c == '{') {
        tokfix(p);
        p->lstate = EXPR_BEG;
        p->cmd_start = TRUE;
        pylval.nd = new_str(p, tok(p), toklen(p));
        if (hinf) {
          hinf->line_head = FALSE;
          return tHD_STRING_PART;
        }
        return tSTRING_PART;
      }
      tokadd(p, '#');
      pushback(p, c);
      continue;
    }
    if ((type & STR_FUNC_ARRAY) && ISSPACE(c)) {
      if (toklen(p) == 0) {
        do {
          if (c == '\n') {
            p->lineno++;
            p->column = 0;
            heredoc_treat_nextline(p);
            if (p->parsing_heredoc != NULL) {
              return tHD_LITERAL_DELIM;
            }
          }
          c = nextc(p);
        } while (ISSPACE(c));
        pushback(p, c);
        return tLITERAL_DELIM;
      }
      else {
        pushback(p, c);
        tokfix(p);
        pylval.nd = new_str(p, tok(p), toklen(p));
        return tSTRING_MID;
      }
    }
    if (c == '\n') {
      p->lineno++;
      p->column = 0;
    }
    tokadd(p, c);
  }

  tokfix(p);
  p->lstate = EXPR_ENDARG;
  end_strterm(p);

  if (type & STR_FUNC_XQUOTE) {
    pylval.nd = new_xstr(p, tok(p), toklen(p));
    return tXSTRING;
  }

  if (type & STR_FUNC_REGEXP) {
    int f = 0;
    int re_opt;
    char *s = strndup(tok(p), toklen(p));
    char flags[3];
    char *flag = flags;
    char enc = '\0';
    char *encp;
    char *dup;

    newtok(p);
    while (re_opt = nextc(p), re_opt >= 0 && ISALPHA(re_opt)) {
      switch (re_opt) {
      case 'i': f |= 1; break;
      case 'x': f |= 2; break;
      case 'm': f |= 4; break;
      case 'u': f |= 16; break;
      case 'n': f |= 32; break;
      default: tokadd(p, re_opt); break;
      }
    }
    pushback(p, re_opt);
    if (toklen(p)) {
      char msg[128];
      tokfix(p);
      snprintf(msg, sizeof(msg), "unknown regexp option%s - %s",
          toklen(p) > 1 ? "s" : "", tok(p));
      yyerror(p, msg);
    }
    if (f != 0) {
      if (f & 1) *flag++ = 'i';
      if (f & 2) *flag++ = 'x';
      if (f & 4) *flag++ = 'm';
      if (f & 16) enc = 'u';
      if (f & 32) enc = 'n';
    }
    if (flag > flags) {
      dup = strndup(flags, (size_t)(flag - flags));
    }
    else {
      dup = NULL;
    }
    if (enc) {
      encp = strndup(&enc, 1);
    }
    else {
      encp = NULL;
    }
    pylval.nd = new_regx(p, s, dup, encp);

    return tREGEXP;
  }
  pylval.nd = new_str(p, tok(p), toklen(p));

  return tSTRING;
}


static int
heredoc_identifier(parser_state *p)
{
  int c;
  int type = str_heredoc;
  mrb_bool indent = FALSE;
  mrb_bool quote = FALSE;
  node *newnode;
  parser_heredoc_info *info;

  c = nextc(p);
  if (ISSPACE(c) || c == '=') {
    pushback(p, c);
    return 0;
  }
  if (c == '-') {
    indent = TRUE;
    c = nextc(p);
  }
  if (c == '\'' || c == '"') {
    int term = c;
    if (c == '\'')
      quote = TRUE;
    newtok(p);
    while ((c = nextc(p)) >= 0 && c != term) {
      if (c == '\n') {
        c = -1;
        break;
      }
      tokadd(p, c);
    }
    if (c < 0) {
      yyerror(p, "unterminated here document identifier");
      return 0;
    }
  }
  else {
    if (c < 0) {
      return 0;                 /* missing here document identifier */
    }
    if (! identchar(c)) {
      pushback(p, c);
      if (indent) pushback(p, '-');
      return 0;
    }
    newtok(p);
    do {
      tokadd(p, c);
    } while ((c = nextc(p)) >= 0 && identchar(c));
    pushback(p, c);
  }
  tokfix(p);
  newnode = new_heredoc(p);
  info = (parser_heredoc_info*)newnode->cdr;
  info->term = strndup(tok(p), toklen(p));
  info->term_len = toklen(p);
  if (! quote)
    type |= STR_FUNC_EXPAND;
  info->type = (string_type)type;
  info->allow_indent = indent;
  info->line_head = TRUE;
  info->doc = NULL;
  p->heredocs_from_nextline = push(p->heredocs_from_nextline, newnode);
  p->lstate = EXPR_END;

  pylval.nd = newnode;
  return tHEREDOC_BEG;
}

static int
arg_ambiguous(parser_state *p)
{
  yywarning(p, "ambiguous first argument; put parentheses or even spaces");
  return 1;
}

#include "lex.def"

static int
parser_yylex(parser_state *p)
{
  int32_t c;
  int space_seen = 0;
  int cmd_state;
  enum mrb_lex_state_enum last_state;
  int token_column;

  if (p->lex_strterm) {
    if (is_strterm_type(p, STR_FUNC_HEREDOC)) {
      if (p->parsing_heredoc != NULL)
        return parse_string(p);
    }
    else
      return parse_string(p);
  }
  cmd_state = p->cmd_start;
  p->cmd_start = FALSE;
  retry:
  last_state = p->lstate;
  switch (c = nextc(p)) {
  case '\004':  /* ^D */
  case '\032':  /* ^Z */
  case '\0':    /* NUL */
  case -1:      /* end of script. */
    if (p->heredocs_from_nextline)
      goto maybe_heredoc;
    return 0;

  /* white spaces */
  case ' ': case '\t': case '\f': case '\r':
  case '\13':   /* '\v' */
    space_seen = 1;
    goto retry;

  case '#':     /* it's a comment */
    skip(p, '\n');
    /* fall through */
  case -2:      /* end of a file */
  case '\n':
    maybe_heredoc:
    heredoc_treat_nextline(p);
  switch (p->lstate) {
  case EXPR_BEG:
  case EXPR_FNAME:
  case EXPR_DOT:
  case EXPR_CLASS:
  case EXPR_VALUE:
    p->lineno++;
    p->column = 0;
    if (p->parsing_heredoc != NULL) {
      if (p->lex_strterm) {
        return parse_string(p);
      }
    }
    goto retry;
  default:
    break;
  }
  if (p->parsing_heredoc != NULL) {
    return '\n';
  }
  while ((c = nextc(p))) {
    switch (c) {
    case ' ': case '\t': case '\f': case '\r':
    case '\13': /* '\v' */
      space_seen = 1;
      break;
    case '.':
      if ((c = nextc(p)) != '.') {
        pushback(p, c);
        pushback(p, '.');
        goto retry;
      }
    case -1:                  /* EOF */
    case -2:                  /* end of a file */
      goto normal_newline;
    default:
      pushback(p, c);
      goto normal_newline;
    }
  }
  normal_newline:
  p->cmd_start = TRUE;
  p->lstate = EXPR_BEG;
  return '\n';

  case '*':
    if ((c = nextc(p)) == '*') {
      if ((c = nextc(p)) == '=') {
        pylval.id = intern("**",2);
        p->lstate = EXPR_BEG;
        return tOP_ASGN;
      }
      pushback(p, c);
      if (IS_SPCARG(c)) {
        yywarning(p, "`**' interpreted as argument prefix");
        c = tDSTAR;
      }
      else if (IS_BEG()) {
        c = tDSTAR;
      }
      else {
        c = tPOW; /* "**", "argument prefix" */
      }
    }
    else {
      if (c == '=') {
        pylval.id = intern_c('*');
        p->lstate = EXPR_BEG;
        return tOP_ASGN;
      }
      pushback(p, c);
      if (IS_SPCARG(c)) {
        yywarning(p, "'*' interpreted as argument prefix");
        c = tSTAR;
      }
      else if (IS_BEG()) {
        c = tSTAR;
      }
      else {
        c = '*';
      }
    }
    if (p->lstate == EXPR_FNAME || p->lstate == EXPR_DOT) {
      p->lstate = EXPR_ARG;
    }
    else {
      p->lstate = EXPR_BEG;
    }
    return c;

  case '!':
    c = nextc(p);
    if (p->lstate == EXPR_FNAME || p->lstate == EXPR_DOT) {
      p->lstate = EXPR_ARG;
      if (c == '@') {
        return '!';
      }
    }
    else {
      p->lstate = EXPR_BEG;
    }
    if (c == '=') {
      return tNEQ;
    }
    if (c == '~') {
      return tNMATCH;
    }
    pushback(p, c);
    return '!';

  case '=':
    if (p->column == 1) {
      static const char begin[] = "begin";
      static const char end[] = "\n=end";
      if (peeks(p, begin)) {
        c = peekc_n(p, sizeof(begin)-1);
        if (c < 0 || ISSPACE(c)) {
          do {
            if (!skips(p, end)) {
              yyerror(p, "embedded document meets end of file");
              return 0;
            }
            c = nextc(p);
          } while (!(c < 0 || ISSPACE(c)));
          if (c != '\n') skip(p, '\n');
          p->lineno++;
          p->column = 0;
          goto retry;
        }
      }
    }
    if (p->lstate == EXPR_FNAME || p->lstate == EXPR_DOT) {
      p->lstate = EXPR_ARG;
    }
    else {
      p->lstate = EXPR_BEG;
    }
    if ((c = nextc(p)) == '=') {
      if ((c = nextc(p)) == '=') {
        return tEQQ;
      }
      pushback(p, c);
      return tEQ;
    }
    if (c == '~') {
      return tMATCH;
    }
    else if (c == '>') {
      return tASSOC;
    }
    pushback(p, c);
    return '=';

  case '<':
    c = nextc(p);
    if (c == '<' &&
        p->lstate != EXPR_DOT &&
        p->lstate != EXPR_CLASS &&
        !IS_END() &&
        (!IS_ARG() || space_seen)) {
      int token = heredoc_identifier(p);
      if (token)
        return token;
    }
    if (p->lstate == EXPR_FNAME || p->lstate == EXPR_DOT) {
      p->lstate = EXPR_ARG;
    }
    else {
      p->lstate = EXPR_BEG;
      if (p->lstate == EXPR_CLASS) {
        p->cmd_start = TRUE;
      }
    }
    if (c == '=') {
      if ((c = nextc(p)) == '>') {
        return tCMP;
      }
      pushback(p, c);
      return tLEQ;
    }
    if (c == '<') {
      if ((c = nextc(p)) == '=') {
        pylval.id = intern("<<",2);
        p->lstate = EXPR_BEG;
        return tOP_ASGN;
      }
      pushback(p, c);
      return tLSHFT;
    }
    pushback(p, c);
    return '<';

  case '>':
    if (p->lstate == EXPR_FNAME || p->lstate == EXPR_DOT) {
      p->lstate = EXPR_ARG;
    }
    else {
      p->lstate = EXPR_BEG;
    }
    if ((c = nextc(p)) == '=') {
      return tGEQ;
    }
    if (c == '>') {
      if ((c = nextc(p)) == '=') {
        pylval.id = intern(">>",2);
        p->lstate = EXPR_BEG;
        return tOP_ASGN;
      }
      pushback(p, c);
      return tRSHFT;
    }
    pushback(p, c);
    return '>';

  case '"':
    p->lex_strterm = new_strterm(p, str_dquote, '"', 0);
    return tSTRING_BEG;

  case '\'':
    p->lex_strterm = new_strterm(p, str_squote, '\'', 0);
    return parse_string(p);

  case '`':
    if (p->lstate == EXPR_FNAME) {
      p->lstate = EXPR_ENDFN;
      return '`';
    }
    if (p->lstate == EXPR_DOT) {
      if (cmd_state)
        p->lstate = EXPR_CMDARG;
      else
        p->lstate = EXPR_ARG;
      return '`';
    }
    p->lex_strterm = new_strterm(p, str_xquote, '`', 0);
    return tXSTRING_BEG;

  case '?':
    if (IS_END()) {
      p->lstate = EXPR_VALUE;
      return '?';
    }
    c = nextc(p);
    if (c < 0) {
      yyerror(p, "incomplete character syntax");
      return 0;
    }
    if (ISSPACE(c)) {
      if (!IS_ARG()) {
        int c2;
        switch (c) {
        case ' ':
          c2 = 's';
          break;
        case '\n':
          c2 = 'n';
          break;
        case '\t':
          c2 = 't';
          break;
        case '\v':
          c2 = 'v';
          break;
        case '\r':
          c2 = 'r';
          break;
        case '\f':
          c2 = 'f';
          break;
        default:
          c2 = 0;
          break;
        }
        if (c2) {
          char buf[256];
          snprintf(buf, sizeof(buf), "invalid character syntax; use ?\\%c", c2);
          yyerror(p, buf);
        }
      }
      ternary:
      pushback(p, c);
      p->lstate = EXPR_VALUE;
      return '?';
    }
    newtok(p);
    /* need support UTF-8 if configured */
    if ((isalnum(c) || c == '_')) {
      int c2 = nextc(p);
      pushback(p, c2);
      if ((isalnum(c2) || c2 == '_')) {
        goto ternary;
      }
    }
    if (c == '\\') {
      c = read_escape(p);
      tokadd(p, c);
    }
    else {
      tokadd(p, c);
    }
    tokfix(p);
    pylval.nd = new_str(p, tok(p), toklen(p));
    p->lstate = EXPR_ENDARG;
    return tCHAR;

  case '&':
    if ((c = nextc(p)) == '&') {
      p->lstate = EXPR_BEG;
      if ((c = nextc(p)) == '=') {
        pylval.id = intern("&&",2);
        p->lstate = EXPR_BEG;
        return tOP_ASGN;
      }
      pushback(p, c);
      return tANDOP;
    }
    else if (c == '.') {
      p->lstate = EXPR_DOT;
      return tANDDOT;
    }
    else if (c == '=') {
      pylval.id = intern_c('&');
      p->lstate = EXPR_BEG;
      return tOP_ASGN;
    }
    pushback(p, c);
    if (IS_SPCARG(c)) {
      yywarning(p, "'&' interpreted as argument prefix");
      c = tAMPER;
    }
    else if (IS_BEG()) {
      c = tAMPER;
    }
    else {
      c = '&';
    }
    if (p->lstate == EXPR_FNAME || p->lstate == EXPR_DOT) {
      p->lstate = EXPR_ARG;
    }
    else {
      p->lstate = EXPR_BEG;
    }
    return c;

  case '|':
    if ((c = nextc(p)) == '|') {
      p->lstate = EXPR_BEG;
      if ((c = nextc(p)) == '=') {
        pylval.id = intern("||",2);
        p->lstate = EXPR_BEG;
        return tOP_ASGN;
      }
      pushback(p, c);
      return tOROP;
    }
    if (c == '=') {
      pylval.id = intern_c('|');
      p->lstate = EXPR_BEG;
      return tOP_ASGN;
    }
    if (p->lstate == EXPR_FNAME || p->lstate == EXPR_DOT) {
      p->lstate = EXPR_ARG;
    }
    else {
      p->lstate = EXPR_BEG;
    }
    pushback(p, c);
    return '|';

  case '+':
    c = nextc(p);
    if (p->lstate == EXPR_FNAME || p->lstate == EXPR_DOT) {
      p->lstate = EXPR_ARG;
      if (c == '@') {
        return tUPLUS;
      }
      pushback(p, c);
      return '+';
    }
    if (c == '=') {
      pylval.id = intern_c('+');
      p->lstate = EXPR_BEG;
      return tOP_ASGN;
    }
    if (IS_BEG() || (IS_SPCARG(c) && arg_ambiguous(p))) {
      p->lstate = EXPR_BEG;
      pushback(p, c);
      if (c >= 0 && ISDIGIT(c)) {
        c = '+';
        goto start_num;
      }
      return tUPLUS;
    }
    p->lstate = EXPR_BEG;
    pushback(p, c);
    return '+';

  case '-':
    c = nextc(p);
    if (p->lstate == EXPR_FNAME || p->lstate == EXPR_DOT) {
      p->lstate = EXPR_ARG;
      if (c == '@') {
        return tUMINUS;
      }
      pushback(p, c);
      return '-';
    }
    if (c == '=') {
      pylval.id = intern_c('-');
      p->lstate = EXPR_BEG;
      return tOP_ASGN;
    }
    if (c == '>') {
      p->lstate = EXPR_ENDFN;
      return tLAMBDA;
    }
    if (IS_BEG() || (IS_SPCARG(c) && arg_ambiguous(p))) {
      p->lstate = EXPR_BEG;
      pushback(p, c);
      if (c >= 0 && ISDIGIT(c)) {
        return tUMINUS_NUM;
      }
      return tUMINUS;
    }
    p->lstate = EXPR_BEG;
    pushback(p, c);
    return '-';

  case '.':
    p->lstate = EXPR_BEG;
    if ((c = nextc(p)) == '.') {
      if ((c = nextc(p)) == '.') {
        return tDOT3;
      }
      pushback(p, c);
      return tDOT2;
    }
    pushback(p, c);
    if (c >= 0 && ISDIGIT(c)) {
      yyerror(p, "no .<digit> floating literal anymore; put 0 before dot");
    }
    p->lstate = EXPR_DOT;
    return '.';

    start_num:
  case '0': case '1': case '2': case '3': case '4':
  case '5': case '6': case '7': case '8': case '9':
  {
    int is_float, seen_point, seen_e, nondigit;

    is_float = seen_point = seen_e = nondigit = 0;
    p->lstate = EXPR_ENDARG;
    newtok(p);
    if (c == '-' || c == '+') {
      tokadd(p, c);
      c = nextc(p);
    }
    if (c == '0') {
#define no_digits() do {yyerror(p,"numeric literal without digits"); return 0;} while (0)
      int start = toklen(p);
      c = nextc(p);
      if (c == 'x' || c == 'X') {
        /* hexadecimal */
        c = nextc(p);
        if (c >= 0 && ISXDIGIT(c)) {
          do {
            if (c == '_') {
              if (nondigit) break;
              nondigit = c;
              continue;
            }
            if (!ISXDIGIT(c)) break;
            nondigit = 0;
            tokadd(p, tolower(c));
          } while ((c = nextc(p)) >= 0);
        }
        pushback(p, c);
        tokfix(p);
        if (toklen(p) == start) {
          no_digits();
        }
        else if (nondigit) goto trailing_uc;
        pylval.nd = new_int(p, tok(p), 16);
        return tINTEGER;
      }
      if (c == 'b' || c == 'B') {
        /* binary */
        c = nextc(p);
        if (c == '0' || c == '1') {
          do {
            if (c == '_') {
              if (nondigit) break;
              nondigit = c;
              continue;
            }
            if (c != '0' && c != '1') break;
            nondigit = 0;
            tokadd(p, c);
          } while ((c = nextc(p)) >= 0);
        }
        pushback(p, c);
        tokfix(p);
        if (toklen(p) == start) {
          no_digits();
        }
        else if (nondigit) goto trailing_uc;
        pylval.nd = new_int(p, tok(p), 2);
        return tINTEGER;
      }
      if (c == 'd' || c == 'D') {
        /* decimal */
        c = nextc(p);
        if (c >= 0 && ISDIGIT(c)) {
          do {
            if (c == '_') {
              if (nondigit) break;
              nondigit = c;
              continue;
            }
            if (!ISDIGIT(c)) break;
            nondigit = 0;
            tokadd(p, c);
          } while ((c = nextc(p)) >= 0);
        }
        pushback(p, c);
        tokfix(p);
        if (toklen(p) == start) {
          no_digits();
        }
        else if (nondigit) goto trailing_uc;
        pylval.nd = new_int(p, tok(p), 10);
        return tINTEGER;
      }
      if (c == '_') {
        /* 0_0 */
        goto octal_number;
      }
      if (c == 'o' || c == 'O') {
        /* prefixed octal */
        c = nextc(p);
        if (c < 0 || c == '_' || !ISDIGIT(c)) {
          no_digits();
        }
      }
      if (c >= '0' && c <= '7') {
        /* octal */
        octal_number:
        do {
          if (c == '_') {
            if (nondigit) break;
            nondigit = c;
            continue;
          }
          if (c < '0' || c > '9') break;
          if (c > '7') goto invalid_octal;
          nondigit = 0;
          tokadd(p, c);
        } while ((c = nextc(p)) >= 0);

        if (toklen(p) > start) {
          pushback(p, c);
          tokfix(p);
          if (nondigit) goto trailing_uc;
          pylval.nd = new_int(p, tok(p), 8);
          return tINTEGER;
        }
        if (nondigit) {
          pushback(p, c);
          goto trailing_uc;
        }
      }
      if (c > '7' && c <= '9') {
        invalid_octal:
        yyerror(p, "Invalid octal digit");
      }
      else if (c == '.' || c == 'e' || c == 'E') {
        tokadd(p, '0');
      }
      else {
        pushback(p, c);
        pylval.nd = new_int(p, "0", 10);
        return tINTEGER;
      }
    }

    for (;;) {
      switch (c) {
      case '0': case '1': case '2': case '3': case '4':
      case '5': case '6': case '7': case '8': case '9':
        nondigit = 0;
        tokadd(p, c);
        break;

      case '.':
        if (nondigit) goto trailing_uc;
        if (seen_point || seen_e) {
          goto decode_num;
        }
        else {
          int c0 = nextc(p);
          if (c0 < 0 || !ISDIGIT(c0)) {
            pushback(p, c0);
            goto decode_num;
          }
          c = c0;
        }
        tokadd(p, '.');
        tokadd(p, c);
        is_float++;
        seen_point++;
        nondigit = 0;
        break;

      case 'e':
      case 'E':
        if (nondigit) {
          pushback(p, c);
          c = nondigit;
          goto decode_num;
        }
        if (seen_e) {
          goto decode_num;
        }
        tokadd(p, c);
        seen_e++;
        is_float++;
        nondigit = c;
        c = nextc(p);
        if (c != '-' && c != '+') continue;
        tokadd(p, c);
        nondigit = c;
        break;

      case '_':       /* '_' in number just ignored */
        if (nondigit) goto decode_num;
        nondigit = c;
        break;

      default:
        goto decode_num;
      }
      c = nextc(p);
    }

    decode_num:
    pushback(p, c);
    if (nondigit) {
      trailing_uc:
      yyerror_i(p, "trailing '%c' in number", nondigit);
    }
    tokfix(p);
    if (is_float) {
#ifdef MRB_WITHOUT_FLOAT
      yywarning_s(p, "floating point numbers are not supported", tok(p));
      pylval.nd = new_int(p, "0", 10);
      return tINTEGER;
#else
      double d;
      char *endp;

      errno = 0;
      d = mrb_float_read(tok(p), &endp);
      if (d == 0 && endp == tok(p)) {
        yywarning_s(p, "corrupted float value %s", tok(p));
      }
      else if (errno == ERANGE) {
        yywarning_s(p, "float %s out of range", tok(p));
        errno = 0;
      }
      pylval.nd = new_float(p, tok(p));
      return tFLOAT;
#endif
    }
    pylval.nd = new_int(p, tok(p), 10);
    return tINTEGER;
  }

  case ')':
  case ']':
    p->paren_nest--;
    /* fall through */
  case '}':
    COND_LEXPOP();
    CMDARG_LEXPOP();
    if (c == ')')
      p->lstate = EXPR_ENDFN;
    else
      p->lstate = EXPR_END;
    return c;

  case ':':
    c = nextc(p);
    if (c == ':') {
      if (IS_BEG() || p->lstate == EXPR_CLASS || IS_SPCARG(-1)) {
        p->lstate = EXPR_BEG;
        return tCOLON3;
      }
      p->lstate = EXPR_DOT;
      return tCOLON2;
    }
    if (!space_seen && IS_END()) {
      pushback(p, c);
      p->lstate = EXPR_BEG;
      return tLABEL_TAG;
    }
    if (!ISSPACE(c) || IS_BEG()) {
      pushback(p, c);
      p->lstate = EXPR_FNAME;
      return tSYMBEG;
    }
    pushback(p, c);
    p->lstate = EXPR_BEG;
    return ':';

  case '/':
    if (IS_BEG()) {
      p->lex_strterm = new_strterm(p, str_regexp, '/', 0);
      return tREGEXP_BEG;
    }
    if ((c = nextc(p)) == '=') {
      pylval.id = intern_c('/');
      p->lstate = EXPR_BEG;
      return tOP_ASGN;
    }
    pushback(p, c);
    if (IS_SPCARG(c)) {
      p->lex_strterm = new_strterm(p, str_regexp, '/', 0);
      return tREGEXP_BEG;
    }
    if (p->lstate == EXPR_FNAME || p->lstate == EXPR_DOT) {
      p->lstate = EXPR_ARG;
    }
    else {
      p->lstate = EXPR_BEG;
    }
    return '/';

  case '^':
    if ((c = nextc(p)) == '=') {
      pylval.id = intern_c('^');
      p->lstate = EXPR_BEG;
      return tOP_ASGN;
    }
    if (p->lstate == EXPR_FNAME || p->lstate == EXPR_DOT) {
      p->lstate = EXPR_ARG;
    }
    else {
      p->lstate = EXPR_BEG;
    }
    pushback(p, c);
    return '^';

  case ';':
    p->lstate = EXPR_BEG;
    return ';';

  case ',':
    p->lstate = EXPR_BEG;
    return ',';

  case '~':
    if (p->lstate == EXPR_FNAME || p->lstate == EXPR_DOT) {
      if ((c = nextc(p)) != '@') {
        pushback(p, c);
      }
      p->lstate = EXPR_ARG;
    }
    else {
      p->lstate = EXPR_BEG;
    }
    return '~';

  case '(':
    if (IS_BEG()) {
      c = tLPAREN;
    }
    else if (IS_SPCARG(-1)) {
      c = tLPAREN_ARG;
    }
    else if (p->lstate == EXPR_END && space_seen) {
      c = tLPAREN_ARG;
    }
    p->paren_nest++;
    COND_PUSH(0);
    CMDARG_PUSH(0);
    p->lstate = EXPR_BEG;
    return c;

  case '[':
    p->paren_nest++;
    if (p->lstate == EXPR_FNAME || p->lstate == EXPR_DOT) {
      p->lstate = EXPR_ARG;
      if ((c = nextc(p)) == ']') {
        if ((c = nextc(p)) == '=') {
          return tASET;
        }
        pushback(p, c);
        return tAREF;
      }
      pushback(p, c);
      return '[';
    }
    else if (IS_BEG()) {
      c = tLBRACK;
    }
    else if (IS_ARG() && space_seen) {
      c = tLBRACK;
    }
    p->lstate = EXPR_BEG;
    COND_PUSH(0);
    CMDARG_PUSH(0);
    return c;

  case '{':
    if (p->lpar_beg && p->lpar_beg == p->paren_nest) {
      p->lstate = EXPR_BEG;
      p->lpar_beg = 0;
      p->paren_nest--;
      COND_PUSH(0);
      CMDARG_PUSH(0);
      return tLAMBEG;
    }
    if (IS_ARG() || p->lstate == EXPR_END || p->lstate == EXPR_ENDFN)
      c = '{';          /* block (primary) */
    else if (p->lstate == EXPR_ENDARG)
      c = tLBRACE_ARG;  /* block (expr) */
    else
      c = tLBRACE;      /* hash */
    COND_PUSH(0);
    CMDARG_PUSH(0);
    p->lstate = EXPR_BEG;
    return c;

  case '\\':
    c = nextc(p);
    if (c == '\n') {
      p->lineno++;
      p->column = 0;
      space_seen = 1;
      goto retry; /* skip \\n */
    }
    pushback(p, c);
    return '\\';

  case '%':
    if (IS_BEG()) {
      int term;
      int paren;

      c = nextc(p);
      quotation:
      if (c < 0 || !ISALNUM(c)) {
        term = c;
        c = 'Q';
      }
      else {
        term = nextc(p);
        if (isalnum(term)) {
          yyerror(p, "unknown type of %string");
          return 0;
        }
      }
      if (c < 0 || term < 0) {
        yyerror(p, "unterminated quoted string meets end of file");
        return 0;
      }
      paren = term;
      if (term == '(') term = ')';
      else if (term == '[') term = ']';
      else if (term == '{') term = '}';
      else if (term == '<') term = '>';
      else paren = 0;

      switch (c) {
      case 'Q':
        p->lex_strterm = new_strterm(p, str_dquote, term, paren);
        return tSTRING_BEG;

      case 'q':
        p->lex_strterm = new_strterm(p, str_squote, term, paren);
        return parse_string(p);

      case 'W':
        p->lex_strterm = new_strterm(p, str_dword, term, paren);
        return tWORDS_BEG;

      case 'w':
        p->lex_strterm = new_strterm(p, str_sword, term, paren);
        return tWORDS_BEG;

      case 'x':
        p->lex_strterm = new_strterm(p, str_xquote, term, paren);
        return tXSTRING_BEG;

      case 'r':
        p->lex_strterm = new_strterm(p, str_regexp, term, paren);
        return tREGEXP_BEG;

      case 's':
        p->lex_strterm = new_strterm(p, str_ssym, term, paren);
        return tSYMBEG;

      case 'I':
        p->lex_strterm = new_strterm(p, str_dsymbols, term, paren);
        return tSYMBOLS_BEG;

      case 'i':
        p->lex_strterm = new_strterm(p, str_ssymbols, term, paren);
        return tSYMBOLS_BEG;

      default:
        yyerror(p, "unknown type of %string");
        return 0;
      }
    }
    if ((c = nextc(p)) == '=') {
      pylval.id = intern_c('%');
      p->lstate = EXPR_BEG;
      return tOP_ASGN;
    }
    if (IS_SPCARG(c)) {
      goto quotation;
    }
    if (p->lstate == EXPR_FNAME || p->lstate == EXPR_DOT) {
      p->lstate = EXPR_ARG;
    }
    else {
      p->lstate = EXPR_BEG;
    }
    pushback(p, c);
    return '%';

  case '$':
    p->lstate = EXPR_END;
    token_column = newtok(p);
    c = nextc(p);
    if (c < 0) {
      yyerror(p, "incomplete global variable syntax");
      return 0;
    }
    switch (c) {
    case '_':     /* $_: last read line string */
      c = nextc(p);
      if (c >= 0 && identchar(c)) { /* if there is more after _ it is a variable */
        tokadd(p, '$');
        tokadd(p, c);
        break;
      }
      pushback(p, c);
      c = '_';
      /* fall through */
    case '~':     /* $~: match-data */
    case '*':     /* $*: argv */
    case '$':     /* $$: pid */
    case '?':     /* $?: last status */
    case '!':     /* $!: error string */
    case '@':     /* $@: error position */
    case '/':     /* $/: input record separator */
    case '\\':    /* $\: output record separator */
    case ';':     /* $;: field separator */
    case ',':     /* $,: output field separator */
    case '.':     /* $.: last read line number */
    case '=':     /* $=: ignorecase */
    case ':':     /* $:: load path */
    case '<':     /* $<: reading filename */
    case '>':     /* $>: default output handle */
    case '\"':    /* $": already loaded files */
      tokadd(p, '$');
      tokadd(p, c);
      tokfix(p);
      pylval.id = intern_cstr(tok(p));
      return tGVAR;

    case '-':
      tokadd(p, '$');
      tokadd(p, c);
      c = nextc(p);
      pushback(p, c);
      gvar:
      tokfix(p);
      pylval.id = intern_cstr(tok(p));
      return tGVAR;

    case '&':     /* $&: last match */
    case '`':     /* $`: string before last match */
    case '\'':    /* $': string after last match */
    case '+':     /* $+: string matches last pattern */
      if (last_state == EXPR_FNAME) {
        tokadd(p, '$');
        tokadd(p, c);
        goto gvar;
      }
      pylval.nd = new_back_ref(p, c);
      return tBACK_REF;

    case '1': case '2': case '3':
    case '4': case '5': case '6':
    case '7': case '8': case '9':
      do {
        tokadd(p, c);
        c = nextc(p);
      } while (c >= 0 && isdigit(c));
      pushback(p, c);
      if (last_state == EXPR_FNAME) goto gvar;
      tokfix(p);
      {
        unsigned long n = strtoul(tok(p), NULL, 10);
        if (n > INT_MAX) {
          yyerror_i(p, "capture group index must be <= %d", INT_MAX);
          return 0;
        }
        pylval.nd = new_nth_ref(p, (int)n);
      }
      return tNTH_REF;

    default:
      if (!identchar(c)) {
        pushback(p,  c);
        return '$';
      }
      /* fall through */
    case '0':
      tokadd(p, '$');
    }
    break;

    case '@':
      c = nextc(p);
      token_column = newtok(p);
      tokadd(p, '@');
      if (c == '@') {
        tokadd(p, '@');
        c = nextc(p);
      }
      if (c < 0) {
        if (p->tidx == 1) {
          yyerror(p, "incomplete instance variable syntax");
        }
        else {
          yyerror(p, "incomplete class variable syntax");
        }
        return 0;
      }
      else if (isdigit(c)) {
        if (p->tidx == 1) {
          yyerror_i(p, "'@%c' is not allowed as an instance variable name", c);
        }
        else {
          yyerror_i(p, "'@@%c' is not allowed as a class variable name", c);
        }
        return 0;
      }
      if (!identchar(c)) {
        pushback(p, c);
        return '@';
      }
      break;

    case '_':
      token_column = newtok(p);
      break;

    default:
      if (!identchar(c)) {
        yyerror_i(p,  "Invalid char '\\x%02X' in expression", c);
        goto retry;
      }

      token_column = newtok(p);
      break;
  }

  do {
    tokadd(p, c);
    c = nextc(p);
    if (c < 0) break;
  } while (identchar(c));
  if (token_column == 0 && toklen(p) == 7 && (c < 0 || c == '\n') &&
      strncmp(tok(p), "__END__", toklen(p)) == 0)
    return -1;

  switch (tok(p)[0]) {
  case '@': case '$':
    pushback(p, c);
    break;
  default:
    if ((c == '!' || c == '?') && !peek(p, '=')) {
      tokadd(p, c);
    }
    else {
      pushback(p, c);
    }
  }
  tokfix(p);
  {
    int result = 0;

    switch (tok(p)[0]) {
    case '$':
      p->lstate = EXPR_END;
      result = tGVAR;
      break;
    case '@':
      p->lstate = EXPR_END;
      if (tok(p)[1] == '@')
        result = tCVAR;
      else
        result = tIVAR;
      break;

    default:
      if (toklast(p) == '!' || toklast(p) == '?') {
        result = tFID;
      }
      else {
        if (p->lstate == EXPR_FNAME) {
          if ((c = nextc(p)) == '=' && !peek(p, '~') && !peek(p, '>') &&
              (!peek(p, '=') || (peek_n(p, '>', 1)))) {
            result = tIDENTIFIER;
            tokadd(p, c);
            tokfix(p);
          }
          else {
            pushback(p, c);
          }
        }
        if (result == 0 && ISUPPER(tok(p)[0])) {
          result = tCONSTANT;
        }
        else {
          result = tIDENTIFIER;
        }
      }

      if (IS_LABEL_POSSIBLE()) {
        if (IS_LABEL_SUFFIX(0)) {
          p->lstate = EXPR_END;
          tokfix(p);
          pylval.id = intern_cstr(tok(p));
          return tIDENTIFIER;
        }
      }
      if (p->lstate != EXPR_DOT) {
        const struct kwtable *kw;

        /* See if it is a reserved word.  */
        kw = mrb_reserved_word(tok(p), toklen(p));
        if (kw) {
          enum mrb_lex_state_enum state = p->lstate;
          pylval.num = p->lineno;
          p->lstate = kw->state;
          if (state == EXPR_FNAME) {
            pylval.id = intern_cstr(kw->name);
            return kw->id[0];
          }
          if (p->lstate == EXPR_BEG) {
            p->cmd_start = TRUE;
          }
          if (kw->id[0] == keyword_do) {
            if (p->lpar_beg && p->lpar_beg == p->paren_nest) {
              p->lpar_beg = 0;
              p->paren_nest--;
              return keyword_do_LAMBDA;
            }
            if (COND_P()) return keyword_do_cond;
            if (CMDARG_P() && state != EXPR_CMDARG)
              return keyword_do_block;
            if (state == EXPR_ENDARG || state == EXPR_BEG)
              return keyword_do_block;
            return keyword_do;
          }
          if (state == EXPR_BEG || state == EXPR_VALUE)
            return kw->id[0];
          else {
            if (kw->id[0] != kw->id[1])
              p->lstate = EXPR_BEG;
            return kw->id[1];
          }
        }
      }

      if (IS_BEG() || p->lstate == EXPR_DOT || IS_ARG()) {
        if (cmd_state) {
          p->lstate = EXPR_CMDARG;
        }
        else {
          p->lstate = EXPR_ARG;
        }
      }
      else if (p->lstate == EXPR_FNAME) {
        p->lstate = EXPR_ENDFN;
      }
      else {
        p->lstate = EXPR_END;
      }
    }
    {
      mrb_sym ident = intern_cstr(tok(p));

      pylval.id = ident;
      if (last_state != EXPR_DOT && islower(tok(p)[0]) && local_var_p(p, ident)) {
        p->lstate = EXPR_END;
      }
    }
    return result;
  }
}

static int
yylex(void *lval, parser_state *p)
{
  p->ylval = lval;
  return parser_yylex(p);
}

static void
parser_init_cxt(parser_state *p, mrbc_context *cxt)
{
  if (!cxt) return;
  if (cxt->filename) mrb_parser_set_filename(p, cxt->filename);
  if (cxt->lineno) p->lineno = cxt->lineno;
  if (cxt->syms) {
    int i;

    p->locals = cons(0,0);
    for (i=0; i<cxt->slen; i++) {
      local_add_f(p, cxt->syms[i]);
    }
  }
  p->capture_errors = cxt->capture_errors;
  p->no_optimize = cxt->no_optimize;
  p->on_eval = cxt->on_eval;
  if (cxt->partial_hook) {
    p->cxt = cxt;
  }
}

static void
parser_update_cxt(parser_state *p, mrbc_context *cxt)
{
  node *n, *n0;
  int i = 0;

  if (!cxt) return;
  if (intn(p->tree->car) != NODE_SCOPE) return;
  n0 = n = p->tree->cdr->car;
  while (n) {
    i++;
    n = n->cdr;
  }
  cxt->syms = (mrb_sym *)mrb_realloc(p->mrb, cxt->syms, i*sizeof(mrb_sym));
  cxt->slen = i;
  for (i=0, n=n0; n; i++,n=n->cdr) {
    cxt->syms[i] = sym(n->car);
  }
}

void mrb_codedump_all(mrb_state*, struct RProc*);
void mrb_parser_dump(mrb_state *mrb, node *tree, int offset);

MRB_API void
mrb_parser_parse(parser_state *p, mrbc_context *c)
{
  struct mrb_jmpbuf buf1;
  p->jmp = &buf1;

  MRB_TRY(p->jmp) {
    int n = 1;

    p->cmd_start = TRUE;
    p->in_def = p->in_single = 0;
    p->nerr = p->nwarn = 0;
    p->lex_strterm = NULL;

    parser_init_cxt(p, c);

    if (p->mrb->jmp) {
      n = yyparse(p);
    }
    else {
      struct mrb_jmpbuf buf2;

      p->mrb->jmp = &buf2;
      MRB_TRY(p->mrb->jmp) {
        n = yyparse(p);
      }
      MRB_CATCH(p->mrb->jmp) {
        p->nerr++;
      }
      MRB_END_EXC(p->mrb->jmp);
      p->mrb->jmp = 0;
    }
    if (n != 0 || p->nerr > 0) {
      p->tree = 0;
      return;
    }
    if (!p->tree) {
      p->tree = new_nil(p);
    }
    parser_update_cxt(p, c);
    if (c && c->dump_result) {
      mrb_parser_dump(p->mrb, p->tree, 0);
    }
  }
  MRB_CATCH(p->jmp) {
    yyerror(p, "memory allocation error");
    p->nerr++;
    p->tree = 0;
    return;
  }
  MRB_END_EXC(p->jmp);
}

MRB_API parser_state*
mrb_parser_new(mrb_state *mrb)
{
  mrb_pool *pool;
  parser_state *p;
  static const parser_state parser_state_zero = { 0 };

  pool = mrb_pool_open(mrb);
  if (!pool) return NULL;
  p = (parser_state *)mrb_pool_alloc(pool, sizeof(parser_state));
  if (!p) return NULL;

  *p = parser_state_zero;
  p->mrb = mrb;
  p->pool = pool;

  p->s = p->send = NULL;
#ifndef MRB_DISABLE_STDIO
  p->f = NULL;
#endif

  p->cmd_start = TRUE;
  p->in_def = p->in_single = 0;

  p->capture_errors = FALSE;
  p->lineno = 1;
  p->column = 0;
#if defined(PARSER_TEST) || defined(PARSER_DEBUG)
  yydebug = 1;
#endif
  p->tsiz = MRB_PARSER_TOKBUF_SIZE;
  p->tokbuf = p->buf;

  p->lex_strterm = NULL;
  p->all_heredocs = p->parsing_heredoc = NULL;
  p->lex_strterm_before_heredoc = NULL;

  p->current_filename_index = -1;
  p->filename_table = NULL;
  p->filename_table_length = 0;

  return p;
}

MRB_API void
mrb_parser_free(parser_state *p) {
  if (p->tokbuf != p->buf) {
    mrb_free(p->mrb, p->tokbuf);
  }
  mrb_pool_close(p->pool);
}

MRB_API mrbc_context*
mrbc_context_new(mrb_state *mrb)
{
  return (mrbc_context *)mrb_calloc(mrb, 1, sizeof(mrbc_context));
}

MRB_API void
mrbc_context_free(mrb_state *mrb, mrbc_context *cxt)
{
  mrb_free(mrb, cxt->filename);
  mrb_free(mrb, cxt->syms);
  mrb_free(mrb, cxt);
}

MRB_API const char*
mrbc_filename(mrb_state *mrb, mrbc_context *c, const char *s)
{
  if (s) {
    size_t len = strlen(s);
    char *p = (char *)mrb_malloc(mrb, len + 1);

    memcpy(p, s, len + 1);
    if (c->filename) {
      mrb_free(mrb, c->filename);
    }
    c->filename = p;
  }
  return c->filename;
}

MRB_API void
mrbc_partial_hook(mrb_state *mrb, mrbc_context *c, int (*func)(struct mrb_parser_state*), void *data)
{
  c->partial_hook = func;
  c->partial_data = data;
}

MRB_API void
mrb_parser_set_filename(struct mrb_parser_state *p, const char *f)
{
  mrb_sym sym;
  size_t i;
  mrb_sym* new_table;

  sym = mrb_intern_cstr(p->mrb, f);
  p->filename = mrb_sym2name_len(p->mrb, sym, NULL);
  p->lineno = (p->filename_table_length > 0)? 0 : 1;

  for (i = 0; i < p->filename_table_length; ++i) {
    if (p->filename_table[i] == sym) {
      p->current_filename_index = (int)i;
      return;
    }
  }

  if (p->filename_table_length == UINT16_MAX) {
    yyerror(p, "too many files to compile");
    return;
  }
  p->current_filename_index = p->filename_table_length++;

  new_table = (mrb_sym*)parser_palloc(p, sizeof(mrb_sym) * p->filename_table_length);
  if (p->filename_table) {
    memmove(new_table, p->filename_table, sizeof(mrb_sym) * p->current_filename_index);
  }
  p->filename_table = new_table;
  p->filename_table[p->filename_table_length - 1] = sym;
}

MRB_API char const*
mrb_parser_get_filename(struct mrb_parser_state* p, uint16_t idx) {
  if (idx >= p->filename_table_length) return NULL;
  else {
    return mrb_sym2name_len(p->mrb, p->filename_table[idx], NULL);
  }
}

#ifndef MRB_DISABLE_STDIO
MRB_API parser_state*
mrb_parse_file(mrb_state *mrb, FILE *f, mrbc_context *c)
{
  parser_state *p;

  p = mrb_parser_new(mrb);
  if (!p) return NULL;
  p->s = p->send = NULL;
  p->f = f;

  mrb_parser_parse(p, c);
  return p;
}
#endif

MRB_API parser_state*
mrb_parse_nstring(mrb_state *mrb, const char *s, size_t len, mrbc_context *c)
{
  parser_state *p;

  p = mrb_parser_new(mrb);
  if (!p) return NULL;
  p->s = s;
  p->send = s + len;

  mrb_parser_parse(p, c);
  return p;
}

MRB_API parser_state*
mrb_parse_string(mrb_state *mrb, const char *s, mrbc_context *c)
{
  return mrb_parse_nstring(mrb, s, strlen(s), c);
}

MRB_API mrb_value
mrb_load_exec(mrb_state *mrb, struct mrb_parser_state *p, mrbc_context *c)
{
  struct RClass *target = mrb->object_class;
  struct RProc *proc;
  mrb_value v;
  unsigned int keep = 0;

  if (!p) {
    return mrb_undef_value();
  }
  if (!p->tree || p->nerr) {
    if (c) c->parser_nerr = p->nerr;
    if (p->capture_errors) {
      char buf[256];
      int n;

      n = snprintf(buf, sizeof(buf), "line %d: %s\n",
          p->error_buffer[0].lineno, p->error_buffer[0].message);
      mrb->exc = mrb_obj_ptr(mrb_exc_new(mrb, E_SYNTAX_ERROR, buf, n));
      mrb_parser_free(p);
      return mrb_undef_value();
    }
    else {
      if (mrb->exc == NULL) {
        mrb->exc = mrb_obj_ptr(mrb_exc_new_str_lit(mrb, E_SYNTAX_ERROR, "syntax error"));
      }
      mrb_parser_free(p);
      return mrb_undef_value();
    }
  }
  proc = mrb_generate_code(mrb, p);
  mrb_parser_free(p);
  if (proc == NULL) {
    if (mrb->exc == NULL) {
      mrb->exc = mrb_obj_ptr(mrb_exc_new_str_lit(mrb, E_SCRIPT_ERROR, "codegen error"));
    }
    return mrb_undef_value();
  }
  if (c) {
    if (c->dump_result) mrb_codedump_all(mrb, proc);
    if (c->no_exec) return mrb_obj_value(proc);
    if (c->target_class) {
      target = c->target_class;
    }
    if (c->keep_lv) {
      keep = c->slen + 1;
    }
    else {
      c->keep_lv = TRUE;
    }
  }
  MRB_PROC_SET_TARGET_CLASS(proc, target);
  if (mrb->c->ci) {
    mrb->c->ci->target_class = target;
  }
  v = mrb_top_run(mrb, proc, mrb_top_self(mrb), keep);
  if (mrb->exc) return mrb_nil_value();
  return v;
}

#ifndef MRB_DISABLE_STDIO
MRB_API mrb_value
mrb_load_file_cxt(mrb_state *mrb, FILE *f, mrbc_context *c)
{
  return mrb_load_exec(mrb, mrb_parse_file(mrb, f, c), c);
}

MRB_API mrb_value
mrb_load_file(mrb_state *mrb, FILE *f)
{
  return mrb_load_file_cxt(mrb, f, NULL);
}
#endif

MRB_API mrb_value
mrb_load_nstring_cxt(mrb_state *mrb, const char *s, size_t len, mrbc_context *c)
{
  return mrb_load_exec(mrb, mrb_parse_nstring(mrb, s, len, c), c);
}

MRB_API mrb_value
mrb_load_nstring(mrb_state *mrb, const char *s, size_t len)
{
  return mrb_load_nstring_cxt(mrb, s, len, NULL);
}

MRB_API mrb_value
mrb_load_string_cxt(mrb_state *mrb, const char *s, mrbc_context *c)
{
  return mrb_load_nstring_cxt(mrb, s, strlen(s), c);
}

MRB_API mrb_value
mrb_load_string(mrb_state *mrb, const char *s)
{
  return mrb_load_string_cxt(mrb, s, NULL);
}

#ifndef MRB_DISABLE_STDIO

static void
dump_prefix(node *tree, int offset)
{
  printf("%05d ", tree->lineno);
  while (offset--) {
    putc(' ', stdout);
    putc(' ', stdout);
  }
}

static void
dump_recur(mrb_state *mrb, node *tree, int offset)
{
  while (tree) {
    mrb_parser_dump(mrb, tree->car, offset);
    tree = tree->cdr;
  }
}

static void
dump_args(mrb_state *mrb, node *n, int offset)
{
  if (n->car) {
    dump_prefix(n, offset+1);
    printf("mandatory args:\n");
    dump_recur(mrb, n->car, offset+2);
  }
  n = n->cdr;
  if (n->car) {
    dump_prefix(n, offset+1);
    printf("optional args:\n");
    {
      node *n2 = n->car;

      while (n2) {
        dump_prefix(n2, offset+2);
        printf("%s=\n", mrb_sym2name(mrb, sym(n2->car->car)));
        mrb_parser_dump(mrb, n2->car->cdr, offset+3);
        n2 = n2->cdr;
      }
    }
  }
  n = n->cdr;
  if (n->car) {
    dump_prefix(n, offset+1);
    printf("rest=*%s\n", mrb_sym2name(mrb, sym(n->car)));
  }
  n = n->cdr;
  if (n->car) {
    dump_prefix(n, offset+1);
    printf("post mandatory args:\n");
    dump_recur(mrb, n->car, offset+2);
  }

  n = n->cdr;
  if (n) {
    mrb_assert(intn(n->car) == NODE_ARGS_TAIL);
    mrb_parser_dump(mrb, n, offset);
  }
}

#endif

void
mrb_parser_dump(mrb_state *mrb, node *tree, int offset)
{
#ifndef MRB_DISABLE_STDIO
  int nodetype;

  if (!tree) return;
  again:
  dump_prefix(tree, offset);
  nodetype = intn(tree->car);
  tree = tree->cdr;
  switch (nodetype) {
  case NODE_BEGIN:
    printf("NODE_BEGIN:\n");
    dump_recur(mrb, tree, offset+1);
    break;

  case NODE_RESCUE:
    printf("NODE_RESCUE:\n");
    if (tree->car) {
      dump_prefix(tree, offset+1);
      printf("body:\n");
      mrb_parser_dump(mrb, tree->car, offset+2);
    }
    tree = tree->cdr;
    if (tree->car) {
      node *n2 = tree->car;

      dump_prefix(n2, offset+1);
      printf("rescue:\n");
      while (n2) {
        node *n3 = n2->car;
        if (n3->car) {
          dump_prefix(n2, offset+2);
          printf("handle classes:\n");
          dump_recur(mrb, n3->car, offset+3);
        }
        if (n3->cdr->car) {
          dump_prefix(n3, offset+2);
          printf("exc_var:\n");
          mrb_parser_dump(mrb, n3->cdr->car, offset+3);
        }
        if (n3->cdr->cdr->car) {
          dump_prefix(n3, offset+2);
          printf("rescue body:\n");
          mrb_parser_dump(mrb, n3->cdr->cdr->car, offset+3);
        }
        n2 = n2->cdr;
      }
    }
    tree = tree->cdr;
    if (tree->car) {
      dump_prefix(tree, offset+1);
      printf("else:\n");
      mrb_parser_dump(mrb, tree->car, offset+2);
    }
    break;

  case NODE_ENSURE:
    printf("NODE_ENSURE:\n");
    dump_prefix(tree, offset+1);
    printf("body:\n");
    mrb_parser_dump(mrb, tree->car, offset+2);
    dump_prefix(tree, offset+1);
    printf("ensure:\n");
    mrb_parser_dump(mrb, tree->cdr->cdr, offset+2);
    break;

  case NODE_LAMBDA:
    printf("NODE_LAMBDA:\n");
    dump_prefix(tree, offset);
    goto block;

  case NODE_BLOCK:
    block:
    printf("NODE_BLOCK:\n");
    tree = tree->cdr;
    if (tree->car) {
      dump_args(mrb, tree->car, offset+1);
    }
    dump_prefix(tree, offset+1);
    printf("body:\n");
    mrb_parser_dump(mrb, tree->cdr->car, offset+2);
    break;

  case NODE_IF:
    printf("NODE_IF:\n");
    dump_prefix(tree, offset+1);
    printf("cond:\n");
    mrb_parser_dump(mrb, tree->car, offset+2);
    dump_prefix(tree, offset+1);
    printf("then:\n");
    mrb_parser_dump(mrb, tree->cdr->car, offset+2);
    if (tree->cdr->cdr->car) {
      dump_prefix(tree, offset+1);
      printf("else:\n");
      mrb_parser_dump(mrb, tree->cdr->cdr->car, offset+2);
    }
    break;

  case NODE_AND:
    printf("NODE_AND:\n");
    mrb_parser_dump(mrb, tree->car, offset+1);
    mrb_parser_dump(mrb, tree->cdr, offset+1);
    break;

  case NODE_OR:
    printf("NODE_OR:\n");
    mrb_parser_dump(mrb, tree->car, offset+1);
    mrb_parser_dump(mrb, tree->cdr, offset+1);
    break;

  case NODE_CASE:
    printf("NODE_CASE:\n");
    if (tree->car) {
      mrb_parser_dump(mrb, tree->car, offset+1);
    }
    tree = tree->cdr;
    while (tree) {
      dump_prefix(tree, offset+1);
      printf("case:\n");
      dump_recur(mrb, tree->car->car, offset+2);
      dump_prefix(tree, offset+1);
      printf("body:\n");
      mrb_parser_dump(mrb, tree->car->cdr, offset+2);
      tree = tree->cdr;
    }
    break;

  case NODE_WHILE:
    printf("NODE_WHILE:\n");
    dump_prefix(tree, offset+1);
    printf("cond:\n");
    mrb_parser_dump(mrb, tree->car, offset+2);
    dump_prefix(tree, offset+1);
    printf("body:\n");
    mrb_parser_dump(mrb, tree->cdr, offset+2);
    break;

  case NODE_UNTIL:
    printf("NODE_UNTIL:\n");
    dump_prefix(tree, offset+1);
    printf("cond:\n");
    mrb_parser_dump(mrb, tree->car, offset+2);
    dump_prefix(tree, offset+1);
    printf("body:\n");
    mrb_parser_dump(mrb, tree->cdr, offset+2);
    break;

  case NODE_FOR:
    printf("NODE_FOR:\n");
    dump_prefix(tree, offset+1);
    printf("var:\n");
    {
      node *n2 = tree->car;

      if (n2->car) {
        dump_prefix(n2, offset+2);
        printf("pre:\n");
        dump_recur(mrb, n2->car, offset+3);
      }
      n2 = n2->cdr;
      if (n2) {
        if (n2->car) {
          dump_prefix(n2, offset+2);
          printf("rest:\n");
          mrb_parser_dump(mrb, n2->car, offset+3);
        }
        n2 = n2->cdr;
        if (n2) {
          if (n2->car) {
            dump_prefix(n2, offset+2);
            printf("post:\n");
            dump_recur(mrb, n2->car, offset+3);
          }
        }
      }
    }
    tree = tree->cdr;
    dump_prefix(tree, offset+1);
    printf("in:\n");
    mrb_parser_dump(mrb, tree->car, offset+2);
    tree = tree->cdr;
    dump_prefix(tree, offset+1);
    printf("do:\n");
    mrb_parser_dump(mrb, tree->car, offset+2);
    break;

  case NODE_SCOPE:
    printf("NODE_SCOPE:\n");
    {
      node *n2 = tree->car;
      mrb_bool first_lval = TRUE;

      if (n2 && (n2->car || n2->cdr)) {
        dump_prefix(n2, offset+1);
        printf("local variables:\n");
        dump_prefix(n2, offset+2);
        while (n2) {
          if (n2->car) {
            if (!first_lval) printf(", ");
            printf("%s", mrb_sym2name(mrb, sym(n2->car)));
            first_lval = FALSE;
          }
          n2 = n2->cdr;
        }
        printf("\n");
      }
    }
    tree = tree->cdr;
    offset++;
    goto again;

  case NODE_FCALL:
  case NODE_CALL:
  case NODE_SCALL:
    switch (nodetype) {
    case NODE_FCALL:
      printf("NODE_FCALL:\n"); break;
    case NODE_CALL:
      printf("NODE_CALL(.):\n"); break;
    case NODE_SCALL:
      printf("NODE_SCALL(&.):\n"); break;
    default:
      break;
    }
    mrb_parser_dump(mrb, tree->car, offset+1);
    dump_prefix(tree, offset+1);
    printf("method='%s' (%d)\n",
        mrb_sym2name(mrb, sym(tree->cdr->car)),
        intn(tree->cdr->car));
    tree = tree->cdr->cdr->car;
    if (tree) {
      dump_prefix(tree, offset+1);
      printf("args:\n");
      dump_recur(mrb, tree->car, offset+2);
      if (tree->cdr) {
        dump_prefix(tree, offset+1);
        printf("block:\n");
        mrb_parser_dump(mrb, tree->cdr, offset+2);
      }
    }
    break;

  case NODE_DOT2:
    printf("NODE_DOT2:\n");
    mrb_parser_dump(mrb, tree->car, offset+1);
    mrb_parser_dump(mrb, tree->cdr, offset+1);
    break;

  case NODE_DOT3:
    printf("NODE_DOT3:\n");
    mrb_parser_dump(mrb, tree->car, offset+1);
    mrb_parser_dump(mrb, tree->cdr, offset+1);
    break;

  case NODE_COLON2:
    printf("NODE_COLON2:\n");
    mrb_parser_dump(mrb, tree->car, offset+1);
    dump_prefix(tree, offset+1);
    printf("::%s\n", mrb_sym2name(mrb, sym(tree->cdr)));
    break;

  case NODE_COLON3:
    printf("NODE_COLON3: ::%s\n", mrb_sym2name(mrb, sym(tree)));
    break;

  case NODE_ARRAY:
    printf("NODE_ARRAY:\n");
    dump_recur(mrb, tree, offset+1);
    break;

  case NODE_HASH:
    printf("NODE_HASH:\n");
    while (tree) {
      dump_prefix(tree, offset+1);
      printf("key:\n");
      mrb_parser_dump(mrb, tree->car->car, offset+2);
      dump_prefix(tree, offset+1);
      printf("value:\n");
      mrb_parser_dump(mrb, tree->car->cdr, offset+2);
      tree = tree->cdr;
    }
    break;

  case NODE_KW_HASH:
    printf("NODE_KW_HASH:\n");
    while (tree) {
      dump_prefix(tree, offset+1);
      printf("key:\n");
      mrb_parser_dump(mrb, tree->car->car, offset+2);
      dump_prefix(tree, offset+1);
      printf("value:\n");
      mrb_parser_dump(mrb, tree->car->cdr, offset+2);
      tree = tree->cdr;
    }
    break;

  case NODE_SPLAT:
    printf("NODE_SPLAT:\n");
    mrb_parser_dump(mrb, tree, offset+1);
    break;

  case NODE_ASGN:
    printf("NODE_ASGN:\n");
    dump_prefix(tree, offset+1);
    printf("lhs:\n");
    mrb_parser_dump(mrb, tree->car, offset+2);
    dump_prefix(tree, offset+1);
    printf("rhs:\n");
    mrb_parser_dump(mrb, tree->cdr, offset+2);
    break;

  case NODE_MASGN:
    printf("NODE_MASGN:\n");
    dump_prefix(tree, offset+1);
    printf("mlhs:\n");
    {
      node *n2 = tree->car;

      if (n2->car) {
        dump_prefix(tree, offset+2);
        printf("pre:\n");
        dump_recur(mrb, n2->car, offset+3);
      }
      n2 = n2->cdr;
      if (n2) {
        if (n2->car) {
          dump_prefix(n2, offset+2);
          printf("rest:\n");
          if (n2->car == (node*)-1) {
            dump_prefix(n2, offset+2);
            printf("(empty)\n");
          }
          else {
            mrb_parser_dump(mrb, n2->car, offset+3);
          }
        }
        n2 = n2->cdr;
        if (n2) {
          if (n2->car) {
            dump_prefix(n2, offset+2);
            printf("post:\n");
            dump_recur(mrb, n2->car, offset+3);
          }
        }
      }
    }
    dump_prefix(tree, offset+1);
    printf("rhs:\n");
    mrb_parser_dump(mrb, tree->cdr, offset+2);
    break;

  case NODE_OP_ASGN:
    printf("NODE_OP_ASGN:\n");
    dump_prefix(tree, offset+1);
    printf("lhs:\n");
    mrb_parser_dump(mrb, tree->car, offset+2);
    tree = tree->cdr;
    dump_prefix(tree, offset+1);
    printf("op='%s' (%d)\n", mrb_sym2name(mrb, sym(tree->car)), intn(tree->car));
    tree = tree->cdr;
    mrb_parser_dump(mrb, tree->car, offset+1);
    break;

  case NODE_SUPER:
    printf("NODE_SUPER:\n");
    if (tree) {
      dump_prefix(tree, offset+1);
      printf("args:\n");
      dump_recur(mrb, tree->car, offset+2);
      if (tree->cdr) {
        dump_prefix(tree, offset+1);
        printf("block:\n");
        mrb_parser_dump(mrb, tree->cdr, offset+2);
      }
    }
    break;

  case NODE_ZSUPER:
    printf("NODE_ZSUPER\n");
    break;

  case NODE_RETURN:
    printf("NODE_RETURN:\n");
    mrb_parser_dump(mrb, tree, offset+1);
    break;

  case NODE_YIELD:
    printf("NODE_YIELD:\n");
    dump_recur(mrb, tree, offset+1);
    break;

  case NODE_BREAK:
    printf("NODE_BREAK:\n");
    mrb_parser_dump(mrb, tree, offset+1);
    break;

  case NODE_NEXT:
    printf("NODE_NEXT:\n");
    mrb_parser_dump(mrb, tree, offset+1);
    break;

  case NODE_REDO:
    printf("NODE_REDO\n");
    break;

  case NODE_RETRY:
    printf("NODE_RETRY\n");
    break;

  case NODE_LVAR:
    printf("NODE_LVAR %s\n", mrb_sym2name(mrb, sym(tree)));
    break;

  case NODE_GVAR:
    printf("NODE_GVAR %s\n", mrb_sym2name(mrb, sym(tree)));
    break;

  case NODE_IVAR:
    printf("NODE_IVAR %s\n", mrb_sym2name(mrb, sym(tree)));
    break;

  case NODE_CVAR:
    printf("NODE_CVAR %s\n", mrb_sym2name(mrb, sym(tree)));
    break;

  case NODE_CONST:
    printf("NODE_CONST %s\n", mrb_sym2name(mrb, sym(tree)));
    break;

  case NODE_MATCH:
    printf("NODE_MATCH:\n");
    dump_prefix(tree, offset + 1);
    printf("lhs:\n");
    mrb_parser_dump(mrb, tree->car, offset + 2);
    dump_prefix(tree, offset + 1);
    printf("rhs:\n");
    mrb_parser_dump(mrb, tree->cdr, offset + 2);
    break;

  case NODE_BACK_REF:
    printf("NODE_BACK_REF: $%c\n", intn(tree));
    break;

  case NODE_NTH_REF:
    printf("NODE_NTH_REF: $%d\n", intn(tree));
    break;

  case NODE_ARG:
    printf("NODE_ARG %s\n", mrb_sym2name(mrb, sym(tree)));
    break;

  case NODE_BLOCK_ARG:
    printf("NODE_BLOCK_ARG:\n");
    mrb_parser_dump(mrb, tree, offset+1);
    break;

  case NODE_INT:
    printf("NODE_INT %s base %d\n", (char*)tree->car, intn(tree->cdr->car));
    break;

  case NODE_FLOAT:
    printf("NODE_FLOAT %s\n", (char*)tree);
    break;

  case NODE_NEGATE:
    printf("NODE_NEGATE\n");
    mrb_parser_dump(mrb, tree, offset+1);
    break;

  case NODE_STR:
    printf("NODE_STR \"%s\" len %d\n", (char*)tree->car, intn(tree->cdr));
    break;

  case NODE_DSTR:
    printf("NODE_DSTR\n");
    dump_recur(mrb, tree, offset+1);
    break;

  case NODE_XSTR:
    printf("NODE_XSTR \"%s\" len %d\n", (char*)tree->car, intn(tree->cdr));
    break;

  case NODE_DXSTR:
    printf("NODE_DXSTR\n");
    dump_recur(mrb, tree, offset+1);
    break;

  case NODE_REGX:
    printf("NODE_REGX /%s/%s\n", (char*)tree->car, (char*)tree->cdr);
    break;

  case NODE_DREGX:
    printf("NODE_DREGX\n");
    dump_recur(mrb, tree->car, offset+1);
    dump_prefix(tree, offset);
    printf("tail: %s\n", (char*)tree->cdr->cdr->car);
    if (tree->cdr->cdr->cdr->car) {
      dump_prefix(tree, offset);
      printf("opt: %s\n", (char*)tree->cdr->cdr->cdr->car);
    }
    if (tree->cdr->cdr->cdr->cdr) {
      dump_prefix(tree, offset);
      printf("enc: %s\n", (char*)tree->cdr->cdr->cdr->cdr);
    }
    break;

  case NODE_SYM:
    printf("NODE_SYM :%s (%d)\n", mrb_sym2name(mrb, sym(tree)),
           intn(tree));
    break;

  case NODE_SELF:
    printf("NODE_SELF\n");
    break;

  case NODE_NIL:
    printf("NODE_NIL\n");
    break;

  case NODE_TRUE:
    printf("NODE_TRUE\n");
    break;

  case NODE_FALSE:
    printf("NODE_FALSE\n");
    break;

  case NODE_ALIAS:
    printf("NODE_ALIAS %s %s:\n",
        mrb_sym2name(mrb, sym(tree->car)),
        mrb_sym2name(mrb, sym(tree->cdr)));
    break;

  case NODE_UNDEF:
    printf("NODE_UNDEF");
    {
      node *t = tree;
      while (t) {
        printf(" %s", mrb_sym2name(mrb, sym(t->car)));
        t = t->cdr;
      }
    }
    printf(":\n");
    break;

  case NODE_CLASS:
    printf("NODE_CLASS:\n");
    if (tree->car->car == (node*)0) {
      dump_prefix(tree, offset+1);
      printf(":%s\n", mrb_sym2name(mrb, sym(tree->car->cdr)));
    }
    else if (tree->car->car == (node*)1) {
      dump_prefix(tree, offset+1);
      printf("::%s\n", mrb_sym2name(mrb, sym(tree->car->cdr)));
    }
    else {
      mrb_parser_dump(mrb, tree->car->car, offset+1);
      dump_prefix(tree, offset+1);
      printf("::%s\n", mrb_sym2name(mrb, sym(tree->car->cdr)));
    }
    if (tree->cdr->car) {
      dump_prefix(tree, offset+1);
      printf("super:\n");
      mrb_parser_dump(mrb, tree->cdr->car, offset+2);
    }
    dump_prefix(tree, offset+1);
    printf("body:\n");
    mrb_parser_dump(mrb, tree->cdr->cdr->car->cdr, offset+2);
    break;

  case NODE_MODULE:
    printf("NODE_MODULE:\n");
    if (tree->car->car == (node*)0) {
      dump_prefix(tree, offset+1);
      printf(":%s\n", mrb_sym2name(mrb, sym(tree->car->cdr)));
    }
    else if (tree->car->car == (node*)1) {
      dump_prefix(tree, offset+1);
      printf("::%s\n", mrb_sym2name(mrb, sym(tree->car->cdr)));
    }
    else {
      mrb_parser_dump(mrb, tree->car->car, offset+1);
      dump_prefix(tree, offset+1);
      printf("::%s\n", mrb_sym2name(mrb, sym(tree->car->cdr)));
    }
    dump_prefix(tree, offset+1);
    printf("body:\n");
    mrb_parser_dump(mrb, tree->cdr->car->cdr, offset+2);
    break;

  case NODE_SCLASS:
    printf("NODE_SCLASS:\n");
    mrb_parser_dump(mrb, tree->car, offset+1);
    dump_prefix(tree, offset+1);
    printf("body:\n");
    mrb_parser_dump(mrb, tree->cdr->car->cdr, offset+2);
    break;

  case NODE_DEF:
    printf("NODE_DEF:\n");
    dump_prefix(tree, offset+1);
    printf("%s\n", mrb_sym2name(mrb, sym(tree->car)));
    tree = tree->cdr;
    {
      node *n2 = tree->car;
      mrb_bool first_lval = TRUE;

      if (n2 && (n2->car || n2->cdr)) {
        dump_prefix(n2, offset+1);
        printf("local variables:\n");
        dump_prefix(n2, offset+2);
        while (n2) {
          if (n2->car) {
            if (!first_lval) printf(", ");
            printf("%s", mrb_sym2name(mrb, sym(n2->car)));
            first_lval = FALSE;
          }
          n2 = n2->cdr;
        }
        printf("\n");
      }
    }
    tree = tree->cdr;
    if (tree->car) {
      dump_args(mrb, tree->car, offset);
    }
    mrb_parser_dump(mrb, tree->cdr->car, offset+1);
    break;

  case NODE_SDEF:
    printf("NODE_SDEF:\n");
    mrb_parser_dump(mrb, tree->car, offset+1);
    tree = tree->cdr;
    dump_prefix(tree, offset+1);
    printf(":%s\n", mrb_sym2name(mrb, sym(tree->car)));
    tree = tree->cdr->cdr;
    if (tree->car) {
      dump_args(mrb, tree->car, offset+1);
    }
    tree = tree->cdr;
    mrb_parser_dump(mrb, tree->car, offset+1);
    break;

  case NODE_POSTEXE:
    printf("NODE_POSTEXE:\n");
    mrb_parser_dump(mrb, tree, offset+1);
    break;

  case NODE_HEREDOC:
    printf("NODE_HEREDOC (<<%s):\n", ((parser_heredoc_info*)tree)->term);
    dump_recur(mrb, ((parser_heredoc_info*)tree)->doc, offset+1);
    break;

  case NODE_ARGS_TAIL:
    printf("NODE_ARGS_TAIL:\n");
    {
      node *kws = tree->car;

      while (kws) {
        mrb_parser_dump(mrb, kws->car, offset+1);
        kws = kws->cdr;
      }
    }
    tree = tree->cdr;
    if (tree->car) {
      mrb_assert(intn(tree->car->car) == NODE_KW_REST_ARGS);
      mrb_parser_dump(mrb, tree->car, offset+1);
    }
    tree = tree->cdr;
    if (tree->car) {
      dump_prefix(tree, offset+1);
      printf("block='%s'\n", mrb_sym2name(mrb, sym(tree->car)));
    }
    break;

  case NODE_KW_ARG:
    printf("NODE_KW_ARG %s\n", mrb_sym2name(mrb, sym(tree->car)));
    mrb_parser_dump(mrb, tree->cdr->car, offset + 1);
    break;

  case NODE_KW_REST_ARGS:
    printf("NODE_KW_REST_ARGS %s\n", mrb_sym2name(mrb, sym(tree)));
    break;

  default:
    printf("node type: %d (0x%x)\n", nodetype, (unsigned)nodetype);
    break;
  }
#endif
}
