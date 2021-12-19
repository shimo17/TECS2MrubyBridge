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
#line 7 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:339  */

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
#include "mruby.h"
#include "mruby/compile.h"
#include "mruby/proc.h"
#include "mruby/error.h"
#include "node.h"
#include "mruby/throw.h"

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
  return list4((node*)NODE_IF, a, b, c);
}

/* (:unless cond then else) */
static node*
new_unless(parser_state *p, node *a, node *b, node *c)
{
  return list4((node*)NODE_IF, a, c, b);
}

/* (:while cond body) */
static node*
new_while(parser_state *p, node *a, node *b)
{
  return cons((node*)NODE_WHILE, cons(a, b));
}

/* (:until cond body) */
static node*
new_until(parser_state *p, node *a, node *b)
{
  return cons((node*)NODE_UNTIL, cons(a, b));
}

/* (:for var obj body) */
static node*
new_for(parser_state *p, node *v, node *o, node *b)
{
  return list4((node*)NODE_FOR, v, o, b);
}

/* (:case a ((when ...) body) ((when...) body)) */
static node*
new_case(parser_state *p, node *a, node *b)
{
  node *n = list2((node*)NODE_CASE, a);
  node *n2 = n;

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
new_call(parser_state *p, node *a, mrb_sym b, node *c)
{
  node *n = list4((node*)NODE_CALL, a, nsym(b), c);
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
  return list4((node*)NODE_CLASS, c, s, cons(locals_node(p), b));
}

/* (:sclass obj body) */
static node*
new_sclass(parser_state *p, node *o, node *b)
{
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
  return list6((node*)NODE_SDEF, o, nsym(m), locals_node(p), a, b);
}

/* (:arg . sym) */
static node*
new_arg(parser_state *p, mrb_sym sym)
{
  return cons((node*)NODE_ARG, nsym(sym));
}

/* (m o r m2 b) */
/* m: (a b c) */
/* o: ((a . e1) (b . e2)) */
/* r: a */
/* m2: (a b c) */
/* b: a */
static node*
new_args(parser_state *p, node *m, node *opt, mrb_sym rest, node *m2, mrb_sym blk)
{
  node *n;

  n = cons(m2, nsym(blk));
  n = cons(nsym(rest), n);
  n = cons(opt, n);
  return cons(m, n);
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
  return cons((node*)NODE_ASGN, cons(a, b));
}

/* (:masgn mlhs=(pre rest post)  mrhs) */
static node*
new_masgn(parser_state *p, node *a, node *b)
{
  return cons((node*)NODE_MASGN, cons(a, b));
}

/* (:asgn lhs rhs) */
static node*
new_op_asgn(parser_state *p, node *a, mrb_sym op, node *b)
{
  return list4((node*)NODE_OP_ASGN, a, nsym(op), b);
}

/* (:int . i) */
static node*
new_int(parser_state *p, const char *s, int base)
{
  return list3((node*)NODE_INT, (node*)strdup(s), (node*)(intptr_t)base);
}

/* (:float . i) */
static node*
new_float(parser_state *p, const char *s)
{
  return cons((node*)NODE_FLOAT, (node*)strdup(s));
}

/* (:str . (s . len)) */
static node*
new_str(parser_state *p, const char *s, int len)
{
  return cons((node*)NODE_STR, cons((node*)strndup(s, len), (node*)(intptr_t)len));
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
  return cons((node*)NODE_XSTR, cons((node*)strndup(s, len), (node*)(intptr_t)len));
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
  return cons((node*)NODE_DSYM, new_dstr(p, a));
}

/* (:str . (a . a)) */
static node*
new_regx(parser_state *p, const char *p1, const char* p2, const char* p3)
{
  return cons((node*)NODE_REGX, cons((node*)p1, cons((node*)p2, (node*)p3)));
}

/* (:dregx . a) */
static node*
new_dregx(parser_state *p, node *a, node *b)
{
  return cons((node*)NODE_DREGX, cons(a, b));
}

/* (:backref . n) */
static node*
new_back_ref(parser_state *p, int n)
{
  return cons((node*)NODE_BACK_REF, (node*)(intptr_t)n);
}

/* (:nthref . n) */
static node*
new_nth_ref(parser_state *p, int n)
{
  return cons((node*)NODE_NTH_REF, (node*)(intptr_t)n);
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
  return new_call(p, recv, intern_cstr(m), 0);
}

/* (:call a op b) */
static node*
call_bin_op(parser_state *p, node *recv, const char *m, node *arg1)
{
  return new_call(p, recv, intern_cstr(m), list1(list1(arg1)));
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

  if (a->car == (node*)NODE_SUPER ||
      a->car == (node*)NODE_ZSUPER) {
    if (!a->cdr) a->cdr = cons(0, b);
    else {
      args_with_block(p, a->cdr, b);
    }
  }
  else {
    n = a->cdr->cdr->cdr;
    if (!n->car) n->car = cons(0, b);
    else {
      args_with_block(p, n->car, b);
    }
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
  if ((int)(intptr_t)lhs->car == NODE_LVAR) {
    local_add(p, sym(lhs->cdr));
  }
}

static node*
var_reference(parser_state *p, node *lhs)
{
  node *n;

  if ((int)(intptr_t)lhs->car == NODE_LVAR) {
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
  return cons((node*)(intptr_t)type, cons((node*)0, cons((node*)(intptr_t)paren, (node*)(intptr_t)term)));
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
    p->heredoc_end_now = TRUE;
  }
  else {
    /* next heredoc */
    p->lex_strterm->car = (node*)(intptr_t)parsing_heredoc_inf(p)->type;
  }
}
#define is_strterm_type(p,str_func) ((int)(intptr_t)((p)->lex_strterm->car) & (str_func))

/* xxx ----------------------------- */


#line 1072 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:339  */

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
    tLABEL = 312,
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
    tAMPER = 354,
    tLAMBDA = 355,
    tSYMBEG = 356,
    tREGEXP_BEG = 357,
    tWORDS_BEG = 358,
    tSYMBOLS_BEG = 359,
    tSTRING_BEG = 360,
    tXSTRING_BEG = 361,
    tSTRING_DVAR = 362,
    tLAMBEG = 363,
    tHEREDOC_BEG = 364,
    tHEREDOC_END = 365,
    tLITERAL_DELIM = 366,
    tHD_LITERAL_DELIM = 367,
    tHD_STRING_PART = 368,
    tHD_STRING_MID = 369,
    tLOWEST = 370,
    tUMINUS_NUM = 371,
    tLAST_TOKEN = 372
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 1017 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:355  */

    node *nd;
    mrb_sym id;
    int num;
    stack_type stack;
    const struct vtable *vars;

#line 1235 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif



int yyparse (parser_state *p);



/* Copy the second part of user declarations.  */

#line 1251 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:358  */

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
#define YYLAST   10639

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  144
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  161
/* YYNRULES -- Number of rules.  */
#define YYNRULES  555
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  968

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   372

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     143,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   130,     2,     2,     2,   128,   123,     2,
     139,   140,   126,   124,   137,   125,   136,   127,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   118,   142,
     120,   116,   119,   117,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   135,     2,   141,   122,     2,   138,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   133,   121,   134,   131,     2,     2,     2,
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
     115,   129,   132
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,  1167,  1167,  1167,  1178,  1184,  1188,  1193,  1197,  1203,
    1205,  1204,  1216,  1243,  1249,  1253,  1258,  1262,  1268,  1268,
    1272,  1276,  1280,  1284,  1288,  1292,  1296,  1301,  1302,  1306,
    1310,  1314,  1318,  1322,  1327,  1331,  1336,  1340,  1344,  1348,
    1351,  1355,  1362,  1363,  1367,  1371,  1375,  1379,  1382,  1389,
    1390,  1393,  1394,  1398,  1397,  1410,  1414,  1419,  1423,  1428,
    1432,  1437,  1441,  1445,  1449,  1453,  1459,  1463,  1469,  1470,
    1476,  1480,  1484,  1488,  1492,  1496,  1500,  1504,  1508,  1512,
    1518,  1519,  1525,  1529,  1535,  1539,  1545,  1549,  1553,  1557,
    1561,  1565,  1571,  1577,  1584,  1588,  1592,  1596,  1600,  1604,
    1610,  1616,  1623,  1627,  1630,  1634,  1638,  1644,  1645,  1646,
    1647,  1652,  1659,  1660,  1663,  1667,  1667,  1673,  1674,  1675,
    1676,  1677,  1678,  1679,  1680,  1681,  1682,  1683,  1684,  1685,
    1686,  1687,  1688,  1689,  1690,  1691,  1692,  1693,  1694,  1695,
    1696,  1697,  1698,  1699,  1700,  1701,  1704,  1704,  1704,  1705,
    1705,  1706,  1706,  1706,  1707,  1707,  1707,  1707,  1708,  1708,
    1708,  1709,  1709,  1709,  1710,  1710,  1710,  1710,  1711,  1711,
    1711,  1711,  1712,  1712,  1712,  1712,  1713,  1713,  1713,  1713,
    1714,  1714,  1714,  1714,  1715,  1715,  1718,  1722,  1726,  1730,
    1734,  1738,  1742,  1746,  1750,  1755,  1760,  1765,  1769,  1773,
    1777,  1781,  1785,  1789,  1793,  1797,  1801,  1805,  1809,  1813,
    1817,  1821,  1825,  1829,  1833,  1837,  1841,  1845,  1849,  1853,
    1857,  1861,  1865,  1869,  1873,  1877,  1881,  1885,  1889,  1893,
    1899,  1906,  1907,  1912,  1916,  1923,  1929,  1930,  1933,  1934,
    1935,  1940,  1945,  1952,  1957,  1962,  1967,  1972,  1979,  1979,
    1990,  1996,  2000,  2006,  2011,  2016,  2020,  2024,  2028,  2034,
    2038,  2042,  2048,  2049,  2050,  2051,  2052,  2053,  2054,  2055,
    2060,  2059,  2071,  2075,  2070,  2080,  2080,  2084,  2088,  2092,
    2096,  2101,  2106,  2110,  2114,  2118,  2122,  2126,  2130,  2134,
    2135,  2141,  2147,  2140,  2159,  2167,  2175,  2175,  2175,  2182,
    2182,  2182,  2189,  2195,  2200,  2202,  2199,  2211,  2209,  2225,
    2230,  2223,  2245,  2243,  2258,  2262,  2257,  2277,  2283,  2276,
    2298,  2302,  2306,  2310,  2316,  2323,  2324,  2325,  2328,  2329,
    2332,  2333,  2341,  2342,  2348,  2352,  2355,  2359,  2365,  2369,
    2375,  2379,  2383,  2387,  2391,  2395,  2399,  2403,  2407,  2413,
    2417,  2421,  2425,  2429,  2433,  2437,  2441,  2445,  2449,  2453,
    2457,  2461,  2465,  2469,  2475,  2476,  2483,  2487,  2491,  2498,
    2502,  2508,  2509,  2512,  2517,  2520,  2524,  2530,  2534,  2541,
    2540,  2553,  2563,  2567,  2572,  2579,  2583,  2587,  2591,  2595,
    2599,  2603,  2607,  2611,  2618,  2617,  2630,  2629,  2643,  2651,
    2660,  2663,  2670,  2673,  2677,  2678,  2681,  2685,  2688,  2692,
    2695,  2696,  2697,  2698,  2701,  2702,  2703,  2707,  2713,  2714,
    2720,  2725,  2724,  2735,  2739,  2745,  2749,  2755,  2759,  2765,
    2768,  2769,  2772,  2773,  2776,  2782,  2788,  2789,  2792,  2799,
    2798,  2812,  2816,  2823,  2827,  2834,  2841,  2842,  2843,  2844,
    2845,  2849,  2855,  2859,  2865,  2866,  2867,  2871,  2877,  2881,
    2885,  2889,  2893,  2899,  2905,  2909,  2913,  2917,  2921,  2925,
    2932,  2941,  2942,  2946,  2950,  2949,  2965,  2971,  2977,  2981,
    2985,  2989,  2993,  2997,  3001,  3005,  3009,  3013,  3017,  3021,
    3025,  3029,  3034,  3040,  3045,  3050,  3055,  3062,  3066,  3073,
    3077,  3083,  3087,  3093,  3100,  3106,  3112,  3116,  3122,  3126,
    3132,  3133,  3136,  3141,  3148,  3149,  3152,  3159,  3163,  3170,
    3175,  3175,  3200,  3201,  3207,  3212,  3218,  3222,  3228,  3229,
    3230,  3233,  3234,  3235,  3236,  3239,  3240,  3241,  3244,  3245,
    3248,  3249,  3252,  3253,  3256,  3259,  3262,  3263,  3264,  3267,
    3268,  3272,  3271,  3278,  3279,  3283
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
  "tIVAR", "tCONSTANT", "tCVAR", "tLABEL", "tINTEGER", "tFLOAT", "tCHAR",
  "tXSTRING", "tREGEXP", "tSTRING", "tSTRING_PART", "tSTRING_MID",
  "tNTH_REF", "tBACK_REF", "tREGEXP_END", "tUPLUS", "tUMINUS", "tPOW",
  "tCMP", "tEQ", "tEQQ", "tNEQ", "tGEQ", "tLEQ", "tANDOP", "tOROP",
  "tMATCH", "tNMATCH", "tDOT2", "tDOT3", "tAREF", "tASET", "tLSHFT",
  "tRSHFT", "tCOLON2", "tCOLON3", "tOP_ASGN", "tASSOC", "tLPAREN",
  "tLPAREN_ARG", "tRPAREN", "tLBRACK", "tLBRACE", "tLBRACE_ARG", "tSTAR",
  "tAMPER", "tLAMBDA", "tSYMBEG", "tREGEXP_BEG", "tWORDS_BEG",
  "tSYMBOLS_BEG", "tSTRING_BEG", "tXSTRING_BEG", "tSTRING_DVAR", "tLAMBEG",
  "tHEREDOC_BEG", "tHEREDOC_END", "tLITERAL_DELIM", "tHD_LITERAL_DELIM",
  "tHD_STRING_PART", "tHD_STRING_MID", "tLOWEST", "'='", "'?'", "':'",
  "'>'", "'<'", "'|'", "'^'", "'&'", "'+'", "'-'", "'*'", "'/'", "'%'",
  "tUMINUS_NUM", "'!'", "'~'", "tLAST_TOKEN", "'{'", "'}'", "'['", "'.'",
  "','", "'`'", "'('", "')'", "']'", "';'", "'\\n'", "$accept", "program",
  "$@1", "top_compstmt", "top_stmts", "top_stmt", "@2", "bodystmt",
  "compstmt", "stmts", "stmt", "$@3", "command_asgn", "expr", "expr_value",
  "command_call", "block_command", "cmd_brace_block", "$@4", "command",
  "mlhs", "mlhs_inner", "mlhs_basic", "mlhs_item", "mlhs_list",
  "mlhs_post", "mlhs_node", "lhs", "cname", "cpath", "fname", "fsym",
  "undef_list", "$@5", "op", "reswords", "arg", "arg_value", "aref_args",
  "paren_args", "opt_paren_args", "opt_call_args", "call_args",
  "command_args", "@6", "block_arg", "opt_block_arg", "args", "mrhs",
  "primary", "@7", "@8", "$@9", "$@10", "@11", "@12", "$@13", "$@14",
  "$@15", "$@16", "$@17", "$@18", "@19", "@20", "@21", "@22", "@23", "@24",
  "@25", "@26", "primary_value", "then", "do", "if_tail", "opt_else",
  "for_var", "f_marg", "f_marg_list", "f_margs", "block_param",
  "opt_block_param", "block_param_def", "opt_bv_decl", "bv_decls", "bvar",
  "f_larglist", "lambda_body", "do_block", "$@27", "block_call",
  "method_call", "brace_block", "@28", "@29", "case_body", "cases",
  "opt_rescue", "exc_list", "exc_var", "opt_ensure", "literal", "string",
  "string_rep", "string_interp", "@30", "xstring", "regexp", "heredoc",
  "opt_heredoc_bodies", "heredoc_bodies", "heredoc_body",
  "heredoc_string_rep", "heredoc_string_interp", "@31", "words", "symbol",
  "basic_symbol", "sym", "symbols", "numeric", "variable", "var_lhs",
  "var_ref", "backref", "superclass", "$@32", "f_arglist", "f_args",
  "f_bad_arg", "f_norm_arg", "f_arg_item", "f_arg", "f_opt_asgn", "f_opt",
  "f_block_opt", "f_block_optarg", "f_optarg", "restarg_mark",
  "f_rest_arg", "blkarg_mark", "f_block_arg", "opt_f_block_arg",
  "singleton", "$@33", "assoc_list", "assocs", "assoc", "operation",
  "operation2", "operation3", "dot_or_colon", "opt_terms", "opt_nl",
  "rparen", "rbracket", "trailer", "term", "nl", "$@34", "terms", "none", YY_NULLPTR
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
     365,   366,   367,   368,   369,   370,    61,    63,    58,    62,
      60,   124,    94,    38,    43,    45,    42,    47,    37,   371,
      33,   126,   372,   123,   125,    91,    46,    44,    96,    40,
      41,    93,    59,    10
};
# endif

#define YYPACT_NINF -771

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-771)))

#define YYTABLE_NINF -556

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-556)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -771,   126,  2464,  -771,  6996,  8804,  9131,  5370,  -771,  8465,
    8465,  -771,  -771,  8913,  6393,  4889,  7674,  7674,  -771,  -771,
    7674,  3085,  2692,  -771,  -771,  -771,  -771,   181,  6393,  -771,
     -26,  -771,  -771,  5507,  2823,  -771,  -771,  5644,  -771,  -771,
    -771,  -771,  -771,  -771,  -771,  8578,  8578,    90,  4290,   -41,
    7787,  8013,  6665,  -771,  6121,   627,   866,   873,   883,   449,
    -771,   235,  8691,  8578,  -771,   246,  -771,  1209,  -771,   379,
    -771,  -771,   101,    37,  -771,    36,  9022,  -771,   117,  2933,
       7,    87,    13,    66,  -771,  -771,  -771,  -771,  -771,  -771,
    -771,  -771,  -771,  -771,    14,    92,  -771,    49,    51,  -771,
    -771,  -771,  -771,  -771,    31,    53,   141,   389,   400,  8465,
     331,  4404,   371,  -771,   175,  -771,   213,  -771,  -771,    51,
    -771,  -771,  -771,  -771,  -771,  -771,  -771,  -771,  -771,  -771,
    -771,  -771,  -771,  -771,  -771,  -771,  -771,  -771,  -771,  -771,
    -771,  -771,  -771,  -771,  -771,  -771,  -771,  -771,    45,    74,
      83,   100,  -771,  -771,  -771,  -771,  -771,  -771,   129,   187,
    -771,   204,  -771,   214,  -771,  -771,  -771,  -771,  -771,  -771,
    -771,  -771,  -771,  -771,  -771,  -771,  -771,  -771,  -771,  -771,
    -771,  -771,  -771,  -771,  -771,  -771,  -771,  -771,  -771,  -771,
    -771,  -771,  -771,  -771,  -771,  -771,  -771,  -771,    13,  3490,
     282,   379,   109,   276,   395,    25,   304,    50,   109,  8465,
    8465,   342,  -771,  -771,   423,   377,    54,    95,  -771,  -771,
    -771,  -771,  -771,  -771,  -771,  -771,  6257,  -771,  -771,   275,
    -771,  -771,  -771,   246,   407,  -771,  -771,   299,  8578,  8578,
    8578,  8578,  -771,  2933,   366,  -771,  -771,   324,   326,  -771,
    -771,  -771,  4775,  -771,  7674,  7674,  -771,  -771,  5003,  8465,
    -771,  -771,   335,  4518,  -771,   538,   402,   362,  7222,  4290,
     339,   246,  1209,   328,   359,  -771,  8465,   328,   345,    94,
     106,  -771,   366,   356,   106,  -771,   442,  9240,   355,   551,
     645,   649,   758,  -771,  -771,  -771,  -771,   937,  -771,  -771,
    -771,  -771,  -771,  -771,   381,   812,  -771,  -771,   947,  -771,
     955,  -771,   969,  -771,   590,   430,   434,  -771,  -771,  -771,
    -771,  5117,  8465,  8465,  8465,  8465,  7222,  8465,  8465,  -771,
    -771,  8126,  -771,  4290,  6774,   369,  8126,  8578,  8578,  8578,
    8578,  8578,  8578,  8578,  8578,  8578,  8578,  8578,  8578,  8578,
    8578,  8578,  8578,  8578,  8578,  8578,  8578,  8578,  8578,  8578,
    8578,  8578,  8578,  2283,  7674,  9519,  -771,  -771, 10491,  -771,
    -771,  -771,  8691,  8691,  -771,   412,  -771,   379,  -771,   777,
    -771,  -771,  -771,  -771,  -771,  9600,  7674,  9681,  3490,  8465,
    -771,  -771,   501,   506,    67,  -771,  3633,   505,  8578,  9762,
    7674,  9843,  8578,  8578,  3919,    55,    55,   103,  9924,  7674,
   10005,  -771,   460,  -771,   381,   407,  8239,   514,  -771,  -771,
    -771,  -771,  8578,  6883,  -771,  -771,  7900,  -771,   328,   392,
    -771,  -771,   328,  -771,   418,   419,  -771,    71,  -771,  -771,
    6393,  4033,   440,  9762,  9843,  8578,  1209,   328,  -771,  -771,
    5230,   427,   379,  -771,  -771,  7109,  -771,  -771,  8013,  -771,
    -771,  -771,   777,    36,  9240,  -771,  9240, 10086,  7674, 10167,
     450,  -771,  -771,  -771,  -771,  1156,  -771,  -771,  -771,  -771,
    1074,  -771,  -771,  -771,  -771,  -771,   438,  8578,  -771,   446,
     535,   451,   540,  -771,  -771,   526,  4518,  -771,  -771,  -771,
     381,  -771,   437,  -771,  -771,  -771,  -771,  -771,  -771,  -771,
    8578,  8578,  -771,  -771,  -771,  -771,  -771,  -771,  -771,  -771,
      33,  8578,  -771,   455,   458,  -771,   328,  9240,   459,  -771,
    -771,  -771,   482,  2671,  -771,  -771,   402,  9456,  9456,  9456,
    9456,  1064,  1064, 10511,  3321,  9456,  9456,  3064,  3064,   597,
     597,  3191,  1064,  1064,   736,   736,   670,    52,    52,   402,
     402,   402,  3216,  5871,  3347,  5984,  -771,    53,  -771,   328,
     464,  -771,   556,  -771,  -771,  2954,  -771,  -771,  2208,    33,
      33,  -771,  2540,  -771,  2933,  -771,  -771,   246,  8465,  3490,
     432,   229,  -771,    53,   328,    53,   589,    71,   916,  6529,
    -771,  8352,   616,  -771,   150,  -771,  2802,  5757,  2561,   328,
     244,   269,   616,  -771,  -771,  -771,  -771,   139,   152,   328,
     107,   123,  8465,  6393,  -771,   381,   634,    69,  -771,  -771,
    8578,   366,  -771,  7335,   326,  -771,  -771,  -771,  -771,  6883,
    7900,  -771,  -771,   516,  -771,  2933,   274,  1209,   328,   106,
     369,  -771,   432,   229,   328,   322,   327,  -771,  -771,  1156,
     487,  -771,   520,   328,  -771,   328,    61,  1074,  -771,  -771,
    -771,  1074,  -771,  -771,   654,  -771,  -771,  -771,   525,  4518,
    -771,  -771,  -771,   402,   402,  -771,   836,  4661,  -771,  -771,
     533,  7448,  -771,  -771,  9240,  8691,  8578,   561,  8691,  8691,
    -771,   412,   544,   562,  8691,  8691,  -771,  -771,   412,  -771,
      66,   101,  4661,  4518,  8578,    33,  -771,   246,   661,  -771,
    -771,  -771,  1074,  3490,   246,  -771,   455,  -771,   605,  -771,
    4176,   667,  -771,  8465,   673,  -771,  8578,  8578,   277,  8578,
    8578,   691,  4661,  4661,   130,    55,  -771,  -771,  7561,  3776,
    -771,  8578,  -771,  -771,   574,  -771,  -771,  -771,   200,   328,
     694,   577,  1170,  -771,   575,   578,  4661,  4518,  -771,  -771,
     579,   580,  -771,   593,  -771,   594,   593,  -771,   598,   328,
     615,   614,  9349,  -771,   622,   624,  -771,   712,  8578,   629,
    -771,  2933,  8578,  -771,  2933,  -771,  2933,  -771,  -771,  8691,
    -771,  2933,  -771,  2933,  -771,  -771,  -771,   749,   633,  2933,
    4518,  3490,  -771,  -771,   328,   755,  -771,   916,  9458,   109,
    -771,  -771,  4661,  -771,  -771,   109,  -771,  8578,  -771,   760,
     761,  -771,  -771,   138,  -771,  7900,  -771,   641,   694,   558,
    -771,  -771,   748,   772,   657,  1074,  -771,   654,  -771,   654,
    -771,   654,  -771,  -771,  -771,   679,  -771,  1074,  -771,   750,
     790,  1074,  -771,   654,  -771,  -771,   671,  2933,  -771,  2933,
    -771,  -771,   676,   800,  -771,  -771,  3490,   762,  -771,   808,
     645,   649,  3490,  -771,  3633,  -771,  -771,  4661,  -771,  -771,
    -771,   694,   641,   694,   683,  -771,   237,  -771,  -771,  -771,
    -771,   593,   687,   593,   593,  -771,   689,   690,  -771, 10248,
     593,  -771,   693,   593,  -771,  -771,   801,   777, 10329,  7674,
   10410,   506,   150,   817,   641,   694,   748,  -771,  -771,   654,
    -771,  -771,  -771,  1074,  -771,   654,  -771,   695,   697,  -771,
     654,  -771,  -771,  -771,    82,   229,   328,   119,   121,  -771,
    -771,  -771,   641,  -771,   593,   593,   700,   593,   593,   128,
    -771,  -771,   654,  -771,  -771,  -771,   593,  -771
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       2,     0,     0,     1,     0,     0,     0,     0,   270,     0,
       0,   296,   299,     0,     0,   540,   320,   321,   322,   323,
     282,   248,   248,   466,   465,   467,   468,   542,     0,    10,
       0,   470,   469,   458,   530,   460,   459,   462,   461,   454,
     455,   414,   415,   471,   472,     0,     0,     0,     0,   272,
     555,   555,    78,   291,     0,     0,     0,     0,     0,     0,
     429,     0,     0,     0,     3,   540,     6,     9,    27,    39,
      42,    50,    49,     0,    66,     0,    70,    80,     0,    47,
     229,     0,    51,   289,   262,   263,   264,   265,   266,   412,
     411,   443,   413,   410,   464,     0,   267,   268,   248,     5,
       8,   320,   321,   282,   285,   392,     0,   102,   103,     0,
       0,     0,     0,   105,   473,   324,     0,   464,   268,     0,
     312,   156,   166,   157,   153,   182,   183,   184,   185,   164,
     179,   172,   162,   161,   177,   160,   159,   155,   180,   154,
     167,   171,   173,   165,   158,   174,   181,   176,   175,   168,
     178,   163,   152,   170,   169,   151,   149,   150,   146,   147,
     148,   107,   109,   108,   141,   142,   138,   120,   121,   122,
     129,   126,   128,   123,   124,   143,   144,   130,   131,   135,
     125,   127,   117,   118,   119,   132,   133,   134,   136,   137,
     139,   140,   145,   520,   314,   110,   111,   519,     0,     0,
       0,    48,     0,     0,     0,   464,     0,   268,     0,     0,
       0,     0,   335,   334,     0,     0,   464,   268,   175,   168,
     178,   163,   146,   147,   107,   108,     0,   112,   114,    20,
     113,   549,   551,   540,     0,   553,   550,   541,     0,     0,
       0,     0,   243,   230,   253,    64,   247,   555,   555,   524,
      65,    63,   542,    62,     0,   555,   391,    61,   542,     0,
     543,    18,     0,     0,   207,     0,   208,   279,     0,     0,
       0,   540,    15,   542,    68,    14,     0,   542,     0,   546,
     546,   231,     0,     0,   546,   522,     0,     0,    76,     0,
      86,    93,   492,   448,   447,   449,   450,     0,   446,   445,
     427,   421,   420,   423,     0,     0,   418,   441,     0,   452,
       0,   416,     0,   425,     0,   456,   457,    46,   222,   223,
       4,   541,     0,     0,     0,     0,     0,     0,     0,   379,
     381,     0,    82,     0,    74,    71,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   555,     0,   539,   538,     0,   396,
     394,   290,     0,     0,   385,    55,   288,   309,   102,   103,
     104,   456,   457,   474,   307,     0,   555,     0,     0,     0,
     315,   317,     0,   555,   279,   326,     0,   325,     0,     0,
     555,     0,     0,     0,     0,     0,     0,   279,     0,   555,
       0,   304,     0,   115,   430,     0,     0,     0,   554,   527,
     254,   250,     0,     0,   244,   252,     0,   245,   542,     0,
     284,   249,   542,   239,   555,   555,   238,   542,   287,    45,
       0,     0,     0,     0,     0,     0,    17,   542,   277,    13,
     541,    67,   273,   276,   280,   548,   232,   547,   548,   234,
     281,   523,    92,    84,     0,    79,     0,     0,   555,     0,
     498,   495,   494,   493,   496,     0,   511,   515,   514,   510,
     492,   292,   376,   497,   499,   501,   555,     0,   508,   555,
     513,   555,     0,   491,   451,     0,     0,   434,   439,   438,
     424,   432,     0,   436,   428,   419,   442,   453,   417,   426,
       0,     0,     7,    21,    22,    23,    24,    25,    43,    44,
     555,     0,    28,    37,     0,    38,   542,     0,    72,    83,
      41,    40,     0,   186,   253,    36,   204,   212,   217,   218,
     219,   214,   216,   226,   227,   220,   221,   197,   198,   224,
     225,   542,   213,   215,   209,   210,   211,   199,   200,   201,
     202,   203,   531,   536,   532,   537,   390,   248,   388,   542,
     531,   533,   532,   534,   389,   248,   531,   532,   248,   555,
     555,    29,   188,    35,   196,    53,    56,     0,     0,     0,
     102,   103,   106,     0,   542,   555,     0,   542,   492,     0,
     271,   555,   555,   402,   555,   327,   186,   535,   532,   542,
     531,   532,   555,   329,   297,   328,   300,   535,   278,   542,
     531,   532,     0,     0,   552,   431,     0,     0,   303,   526,
       0,   255,   251,     0,   555,   525,   283,   544,   235,   240,
     242,   286,    19,     0,    26,   195,    69,    16,   542,   546,
      85,    77,    89,    91,   542,   531,   532,   503,   498,     0,
     347,   338,   340,   542,   336,   542,     0,     0,   484,   518,
     504,     0,   487,   512,     0,   489,   516,   444,     0,     0,
     433,   435,   437,   205,   206,   367,   542,     0,   365,   364,
     261,     0,    81,    75,     0,     0,     0,     0,     0,     0,
     387,    59,     0,   393,     0,     0,   237,   386,    57,   236,
     382,    52,     0,     0,     0,   555,   310,     0,     0,   393,
     313,   521,   492,     0,     0,   318,   403,   404,   555,   405,
       0,   555,   332,     0,     0,   330,     0,     0,   393,     0,
       0,     0,     0,     0,   393,     0,   116,   302,     0,     0,
     256,     0,   257,   246,   555,    11,   274,   233,    87,   542,
       0,   345,     0,   500,     0,   369,     0,     0,   293,   502,
     555,   555,   517,   555,   509,   555,   555,   422,     0,   542,
       0,   555,     0,   506,   555,   555,   363,     0,     0,   259,
      73,   187,     0,    34,   193,    33,   194,    60,   545,     0,
      31,   191,    32,   192,    58,   383,   384,     0,     0,   189,
       0,     0,   475,   308,   542,     0,   477,   492,     0,     0,
     407,   333,     0,    12,   409,     0,   294,     0,   295,     0,
       0,   305,   255,   555,   258,   241,   337,   348,     0,   343,
     339,   375,     0,     0,     0,     0,   480,     0,   482,     0,
     488,     0,   485,   490,   440,     0,   366,   354,   356,     0,
     505,     0,   359,     0,   361,   380,   260,   228,    30,   190,
     397,   395,     0,     0,   476,   316,     0,     0,   406,     0,
      94,   101,     0,   408,     0,   298,   301,     0,   399,   400,
     398,     0,   346,     0,   341,   373,   542,   371,   374,   378,
     377,   555,   555,   555,   555,   368,   555,   555,   279,     0,
     555,   507,   555,   555,    54,   311,     0,   100,     0,   555,
       0,   555,   555,     0,   344,     0,     0,   370,   481,     0,
     478,   483,   486,     0,   351,     0,   353,   535,   278,   360,
       0,   357,   362,   319,   535,    99,   542,   531,   532,   401,
     331,   306,   342,   372,   555,   555,   555,   555,   555,   393,
     479,   352,     0,   349,   355,   358,   555,   350
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -771,  -771,  -771,   397,  -771,    20,  -771,  -380,    76,  -771,
      57,  -771,  -319,    96,   112,   -57,  -771,  -418,  -771,   -13,
     840,  -173,   -21,   -58,  -250,  -409,   -16,  1283,   -72,   838,
       4,   -15,  -771,  -771,  -249,  -771,  1006,  1430,  -771,    12,
     271,  -334,    77,    78,  -771,  -353,  -239,    30,  -293,    10,
    -771,  -771,  -771,  -771,  -771,  -771,  -771,  -771,  -771,  -771,
    -771,  -771,  -771,  -771,  -771,  -771,  -771,  -771,  -771,  -771,
     294,  -182,  -387,   -56,  -561,  -771,  -688,  -691,   209,  -771,
    -508,  -771,  -605,  -771,   -54,  -771,  -771,   158,  -771,  -771,
    -771,   -77,  -771,  -771,  -384,  -771,   -46,  -771,  -771,  -771,
    -771,  -771,   606,   765,  -771,  -771,  -771,  -771,  -771,  -201,
    -432,  -771,   378,  -771,  -771,  -771,     0,  -771,  -771,  -771,
    1490,  1395,   878,  1579,  -771,  -771,    86,  -280,  -754,  -391,
    -602,   184,  -603,  -618,  -770,    38,   221,  -771,  -482,  -771,
    -272,   363,  -771,  -771,  -771,     5,  -425,   831,  -323,  -771,
     709,     2,   -25,    80,  -565,  -245,    -5,    48,  -771,   -33,
      -2
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    64,    65,    66,   262,   392,   393,   271,
     272,   440,    68,    69,   202,    70,    71,   586,   715,    72,
      73,   273,    74,    75,    76,   465,    77,   203,   113,   114,
     227,   228,   229,   623,   195,   196,    79,   244,   278,   566,
     707,   432,   433,   253,   254,   246,   424,   434,   525,    80,
     199,   276,   648,   277,   292,   666,   209,   742,   210,   743,
     622,   887,   589,   587,   811,   388,   390,   598,   599,   817,
     265,   396,   614,   734,   735,   215,   661,   662,   663,   779,
     687,   688,   764,   896,   897,   481,   768,   330,   520,    82,
      83,   376,   580,   579,   417,   890,   602,   728,   819,   823,
      84,    85,   305,   306,   496,    86,    87,    88,   624,   633,
     501,   502,   503,   679,    89,    90,    91,   299,    92,    93,
     205,   206,    96,   207,   384,   588,   723,   724,   483,   484,
     485,   486,   487,   488,   783,   784,   489,   490,   491,   492,
     772,   668,   198,   389,   283,   435,   249,   119,   593,   568,
     368,   234,   429,   430,   703,   456,   397,   260,   414,   237,
     275
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      99,   635,   259,   242,   242,   317,   371,   242,   596,   427,
     235,   194,   482,   261,   230,   115,   115,   530,   335,   616,
     493,   248,   248,   115,   100,   248,   404,   274,   230,   719,
     569,   626,   321,   635,   256,   459,   288,   464,   380,   461,
     567,   731,   575,   535,   738,   578,   247,   247,   281,   285,
     247,   741,   594,   774,   744,   280,   284,   651,   298,    67,
     235,    67,   115,   236,   595,   769,   609,   320,   680,   837,
     632,   712,   713,   632,   840,   619,   567,   369,   575,   -94,
     279,   780,   613,   782,   664,   395,   115,   595,   898,   758,
     766,   911,   369,   245,   250,  -324,   447,   251,   -97,  -275,
     257,   366,  -275,   500,  -463,   201,   201,   263,   327,   328,
     374,   201,   685,   236,   565,  -463,   573,   256,   693,   573,
    -101,   595,   208,   337,   270,   395,     3,   233,  -100,   329,
     -94,   374,   -96,  -466,   654,   -96,   565,   -98,   573,   373,
     403,   -94,  -324,  -324,   -95,   267,   595,   892,   -98,   367,
     565,   -86,   573,   331,   686,   -95,   730,   445,   416,   565,
     526,   573,  -465,   911,   -97,  -101,  -101,   733,   730,   767,
     252,  -467,   898,   332,   855,   363,   375,   -99,   360,   361,
     362,  -466,   372,  -100,   370,   771,   -93,   270,  -468,   775,
     255,   -86,   255,   680,   565,   573,   427,   231,   232,   370,
     665,   680,   924,   840,   785,   377,   748,   810,   493,   718,
    -465,   231,   232,   625,   232,   635,   464,  -470,   565,  -467,
     573,  -531,   364,   365,   -97,   -97,  -393,   774,   235,   463,
     298,   455,   -93,   336,   952,   415,  -468,   232,   450,   242,
     -92,   242,   242,   458,   -88,   425,   425,   769,   274,   232,
     236,   231,   232,   436,   782,   769,   236,   248,   782,   248,
     -90,   -96,   -96,   -98,   -98,  -470,   235,   -87,   664,   761,
     -95,   -95,   888,   449,   522,  -469,   -89,   464,  -531,   531,
     258,   236,   247,   797,   247,   790,   632,   632,  -393,   -91,
     804,  -532,  -458,   315,   316,   383,    81,   115,    81,   116,
     116,   385,  -462,   204,   204,   201,   201,   214,   727,   204,
     204,   204,   274,   592,   204,   581,   583,  -278,   528,   236,
     258,   405,   406,  -469,   232,   446,   493,   457,   457,   428,
     782,   431,   457,  -393,   739,  -393,  -393,   394,   438,   442,
    -458,   512,    81,   815,   115,   270,   289,   -88,   386,   387,
    -462,   242,   -90,   451,   437,   439,   204,   453,   831,   740,
     -96,   524,   436,   902,  -278,  -278,   524,   827,  -532,   664,
     289,   664,   452,   242,   926,   907,   530,   574,    67,   912,
     232,   959,   378,   517,   436,   -98,   379,   242,   231,   232,
     -67,   603,   398,   -95,   402,   753,   242,   407,   436,   574,
     615,   615,   411,   204,   757,    81,   650,   436,   463,   270,
     635,   -81,   413,   574,   786,  -528,   327,   328,   201,   201,
     201,   201,   574,   518,   519,   642,  -529,   416,   634,   381,
     382,   873,   425,   425,   513,   514,   515,   516,   -88,    99,
     230,   418,   814,   -90,   464,   749,   627,   664,   894,   889,
     493,   956,   445,   236,   236,   242,   574,   422,  -535,   -88,
     649,   423,   -88,   426,   -90,   -88,   436,   -90,   441,   463,
     -90,   232,   604,   337,   115,   -66,   115,  -458,  -100,   448,
     612,   574,   632,   399,   669,   597,   454,   669,  -462,   669,
     460,   497,   466,    81,   498,   499,   916,   462,    67,   -92,
     664,   510,   664,   204,   204,   511,   529,   647,   636,   585,
     313,   408,   638,   301,   302,   753,   600,   641,   689,   601,
    -535,   605,  -528,   494,  -458,  -458,   697,   646,  -528,   628,
     400,   401,   637,  -529,   664,  -462,  -462,   115,   658,  -529,
     471,   472,   473,   474,   702,   493,   204,   681,   204,   204,
     498,   499,   204,   204,   704,   639,   640,    81,   409,   410,
     303,   304,    81,    81,   -81,  -535,   657,  -535,  -535,   702,
     204,  -531,   678,   709,   644,   667,   709,   689,   689,   700,
     -96,   289,   716,   671,   702,   946,   673,   706,   674,   677,
     706,   676,  -253,   709,   702,   691,   694,   595,   695,   729,
     732,   -88,   732,   725,   720,   700,   692,   706,   746,   658,
     732,   471,   472,   473,   474,    81,   204,   204,   204,   204,
      81,   204,   204,   230,   760,   204,   443,    81,   289,   702,
     204,   524,   425,   805,   730,   236,   463,   882,   531,   467,
     765,   793,   795,   884,   754,   701,   705,   800,   802,   747,
     755,   509,   799,   708,   301,   302,   711,   762,   204,   777,
     565,   765,   308,   310,   312,   314,   204,   204,   337,   565,
    -254,   573,   -98,   400,   444,   236,   813,   721,   -95,   792,
     204,   822,    81,   204,   201,   798,   468,   469,   826,   300,
      81,   301,   302,   -90,   204,   893,   818,   457,    81,   -87,
     717,   303,   304,   204,   115,   658,   828,   471,   472,   473,
     474,   835,   812,   689,   838,   841,   845,   847,   201,   816,
     842,   358,   359,   360,   361,   362,   820,   865,   756,   824,
     849,   851,   854,  -464,   745,    81,   856,  -268,   303,   304,
     615,   337,   868,   763,    81,   658,   475,   471,   472,   473,
     474,   857,   425,   477,   765,   778,   350,   351,   289,   861,
     289,   863,   204,   787,   870,   236,  -255,   871,   669,   669,
     875,   669,   236,   669,   669,   885,   886,   478,   891,   669,
    -464,  -464,   669,   669,  -268,  -268,   659,   899,   807,   808,
      81,   900,   115,   236,   358,   359,   360,   361,   362,   895,
     905,   471,   472,   473,   474,   908,   821,   337,  -256,   470,
     914,   471,   472,   473,   474,   915,   943,   917,   829,   830,
     925,   289,   350,   351,   929,   833,   933,   935,   115,   201,
     940,   732,   951,    98,  -531,    98,  -532,   962,   643,   836,
      98,    98,   843,   844,   120,   825,    98,    98,    98,   710,
     475,    98,   672,   212,   675,   773,   476,   477,   776,   357,
     358,   359,   360,   361,   362,  -279,   950,   236,   759,   806,
     781,   927,   953,   236,   504,   949,   301,   302,   909,    98,
     682,   478,   204,    81,   479,   197,   872,   470,   770,   471,
     472,   473,   474,    98,   874,   906,   918,   480,   883,   669,
     669,   669,   669,   876,   669,   669,   242,   391,   669,     0,
     669,   669,  -279,  -279,     0,     0,   204,   436,     0,   603,
     732,   702,     0,   303,   304,   386,   387,     0,   475,   307,
     301,   302,   574,     0,   476,   477,   309,   301,   302,     0,
      98,     0,    98,   919,   920,     0,   311,   301,   302,     0,
       0,     0,   669,   669,   669,   669,   669,     0,   921,   478,
     922,     0,   479,   923,   669,     0,     0,   470,     0,   471,
     472,   473,   474,    81,     0,     0,     0,   303,   304,   232,
       0,    81,     0,     0,   303,   304,     0,     0,   289,   204,
       0,     0,   204,   204,   303,   304,     0,     0,   204,   204,
     494,   301,   302,     0,     0,     0,    81,    81,   475,     0,
     506,   301,   302,     0,   476,   477,     0,    81,   507,   301,
     302,     0,   243,   243,    81,     0,   243,   204,     0,   901,
      98,   903,   508,   301,   302,   904,    81,    81,     0,   478,
      98,    98,   479,    81,     0,   910,     0,   913,   303,   304,
       0,   264,   266,     0,     0,   722,   243,   243,   303,   304,
      81,    81,   495,     0,     0,     0,   303,   304,   318,   319,
     505,     0,     0,   505,     0,   505,   860,   505,     0,   505,
     303,   304,     0,    98,     0,    98,    98,     0,     0,    98,
      98,     0,     0,   204,    98,     0,     0,     0,     0,    98,
      98,     0,     0,     0,    81,    81,     0,    98,     0,     0,
       0,     0,   879,   954,     0,     0,    81,   955,     0,   957,
       0,     0,     0,     0,   958,   470,     0,   471,   472,   473,
     474,     0,     0,   846,   848,   337,   850,     0,   852,   853,
       0,     0,     0,     0,   858,     0,   966,   862,   864,     0,
     350,   351,    98,    98,    98,    98,    98,    98,    98,    98,
       0,     0,    98,     0,    98,     0,   475,    98,     0,     0,
      81,     0,   476,   477,     0,     0,    81,     0,    81,     0,
       0,    81,     0,     0,     0,   355,   356,   357,   358,   359,
     360,   361,   362,     0,     0,    98,     0,   478,     0,     0,
     479,     0,     0,    98,    98,     0,     0,   658,     0,   471,
     472,   473,   474,   204,     0,     0,     0,    98,     0,    98,
      98,   658,     0,   471,   472,   473,   474,    98,     0,     0,
       0,    98,     0,     0,     0,    98,     0,     0,     0,     0,
      98,     0,     0,     0,   243,   243,   243,   318,   659,   322,
     323,   324,   325,   326,   660,     0,     0,     0,   243,     0,
     243,   243,   659,     0,   928,   930,   931,   932,   839,   934,
     936,     0,    98,   939,     0,   941,   942,     0,     0,     0,
       0,    98,     0,     0,     0,    78,     0,    78,     0,     0,
       0,     0,     0,     0,     0,     0,   213,     0,     0,    98,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   960,   961,   963,
     964,   965,     0,     0,     0,     0,     0,    98,     0,   967,
       0,    78,     0,     0,     0,     0,     0,   243,     0,     0,
       0,     0,   533,   536,   537,   538,   539,   540,   541,   542,
     543,   544,   545,   546,   547,   548,   549,   550,   551,   552,
     553,   554,   555,   556,   557,   558,   559,   560,   561,     0,
     243,     0,     0,     0,     0,     0,     0,     0,   582,   584,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   243,     0,    78,     0,     0,    95,     0,    95,
       0,     0,     0,     0,   606,     0,   243,     0,   582,   584,
       0,     0,     0,     0,     0,   243,     0,     0,     0,    98,
      98,     0,   243,     0,     0,     0,     0,     0,   243,   243,
       0,     0,   243,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    95,     0,     0,     0,     0,     0,     0,
       0,   645,     0,    98,     0,     0,     0,     0,     0,     0,
       0,   243,     0,     0,   243,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   243,     0,     0,     0,     0,     0,
       0,   282,    78,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    94,   243,    94,   117,   117,   117,     0,     0,
       0,     0,     0,   216,     0,     0,    95,     0,     0,     0,
      98,     0,     0,     0,     0,     0,   683,   684,    98,     0,
       0,     0,     0,     0,     0,     0,    98,   243,     0,    98,
      98,     0,     0,     0,     0,    98,    98,     0,    94,     0,
       0,     0,   290,    98,    98,     0,    78,     0,     0,     0,
       0,    78,    78,     0,    98,     0,     0,     0,     0,     0,
       0,    98,     0,     0,    98,     0,   290,     0,     0,     0,
       0,     0,     0,    98,    98,     0,     0,     0,     0,     0,
      98,    97,     0,    97,   118,   118,     0,     0,     0,     0,
       0,     0,   217,     0,    95,     0,     0,    98,    98,     0,
       0,    94,     0,     0,    78,     0,     0,   243,     0,    78,
       0,     0,     0,     0,     0,     0,    78,     0,     0,   532,
       0,     0,     0,     0,     0,     0,     0,    97,     0,     0,
      98,   291,     0,     0,     0,     0,   243,     0,     0,   243,
       0,    98,    98,     0,     0,   243,   243,     0,     0,     0,
       0,     0,     0,    98,     0,   291,     0,     0,    95,     0,
       0,     0,     0,    95,    95,     0,     0,     0,   419,   420,
     421,    78,     0,     0,     0,     0,     0,     0,     0,    78,
       0,     0,     0,     0,     0,     0,     0,    78,     0,    94,
      97,     0,     0,     0,     0,     0,     0,   243,     0,     0,
       0,   606,   791,     0,   794,   796,     0,    98,     0,     0,
     801,   803,     0,    98,     0,    98,    95,     0,    98,     0,
     809,    95,     0,     0,    78,     0,     0,     0,    95,     0,
       0,     0,     0,    78,     0,     0,     0,     0,     0,     0,
       0,     0,   794,   796,     0,   801,   803,     0,     0,     0,
      98,     0,     0,    94,   243,     0,     0,   243,    94,    94,
       0,   523,     0,     0,     0,     0,   534,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   290,    97,    78,
       0,     0,     0,    95,     0,     0,     0,     0,     0,     0,
       0,    95,     0,     0,   243,     0,     0,     0,   867,    95,
       0,     0,     0,     0,     0,   869,     0,     0,     0,     0,
       0,    94,     0,     0,     0,     0,    94,     0,     0,     0,
       0,     0,     0,    94,   290,     0,     0,     0,     0,     0,
       0,     0,     0,   869,     0,     0,    95,     0,     0,     0,
       0,   243,    97,     0,     0,    95,   534,    97,    97,     0,
       0,     0,   629,   631,     0,     0,   282,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   291,     0,     0,     0,
       0,     0,    78,     0,     0,     0,     0,     0,    94,     0,
       0,     0,     0,     0,     0,   631,    94,     0,   282,     0,
       0,    95,     0,     0,    94,     0,     0,     0,     0,     0,
      97,     0,     0,     0,     0,    97,     0,     0,     0,     0,
       0,     0,    97,   291,     0,     0,     0,   670,     0,     0,
       0,     0,     0,     0,     0,   243,     0,     0,     0,     0,
       0,    94,     0,     0,     0,     0,     0,     0,     0,     0,
      94,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   690,     0,     0,   290,     0,   290,     0,     0,     0,
       0,     0,    78,     0,     0,     0,     0,    97,     0,     0,
      78,     0,     0,     0,     0,    97,     0,     0,   532,     0,
       0,     0,     0,    97,    95,     0,    94,     0,     0,     0,
       0,     0,     0,     0,     0,    78,    78,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    78,     0,     0,     0,
       0,     0,     0,    78,     0,     0,     0,   290,     0,     0,
      97,     0,     0,     0,     0,    78,    78,     0,     0,    97,
       0,   726,    78,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   291,     0,   291,     0,     0,     0,    78,
      78,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     750,     0,     0,   752,     0,     0,     0,     0,     0,   631,
     282,     0,     0,     0,    95,    97,     0,     0,     0,    94,
       0,     0,    95,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    78,    78,     0,     0,     0,     0,     0,
       0,   878,     0,     0,     0,    78,   291,    95,    95,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    95,     0,
       0,   789,     0,     0,     0,    95,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    95,    95,     0,
       0,     0,     0,     0,    95,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    78,
       0,    95,    95,     0,     0,    78,     0,    78,    97,    94,
      78,     0,     0,     0,     0,     0,     0,    94,   832,     0,
       0,   834,     0,     0,   290,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    94,    94,     0,    95,    95,     0,  -555,     0,
       0,     0,     0,    94,     0,     0,     0,    95,   866,     0,
      94,  -555,  -555,  -555,  -555,  -555,  -555,     0,  -555,     0,
       0,     0,    94,    94,  -555,  -555,     0,     0,     0,    94,
       0,     0,     0,     0,     0,  -555,  -555,     0,  -555,  -555,
    -555,  -555,  -555,     0,     0,     0,    94,    94,    97,     0,
       0,     0,     0,     0,     0,   282,    97,     0,     0,     0,
       0,    95,   117,   291,     0,     0,     0,    95,     0,    95,
       0,     0,    95,     0,     0,     0,     0,     0,     0,     0,
       0,    97,    97,     0,     0,     0,  -555,     0,     0,     0,
      94,    94,    97,     0,     0,     0,     0,     0,   880,    97,
       0,     0,    94,     0,     0,     0,     0,     0,     0,     0,
       0,    97,    97,     0,     0,     0,     0,     0,    97,     0,
       0,     0,     0,     0,   562,   563,     0,     0,   564,     0,
       0,  -555,  -555,     0,  -555,    97,    97,   255,  -555,     0,
    -555,  -555,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   118,     0,   173,   174,     0,    94,   175,   176,   177,
     178,     0,    94,     0,    94,     0,     0,    94,     0,     0,
       0,   179,     0,     0,     0,     0,     0,     0,     0,    97,
      97,     0,     0,     0,     0,     0,     0,   881,     0,     0,
       0,    97,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,     0,   190,   191,     0,     0,     0,     0,     0,
       0,   192,   255,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    97,     0,     0,     0,     0,
       0,    97,     0,    97,  -555,     4,    97,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,     0,     0,     0,
       0,     0,     0,    15,     0,    16,    17,    18,    19,     0,
       0,     0,     0,     0,    20,    21,    22,    23,    24,    25,
      26,     0,     0,    27,     0,     0,     0,     0,     0,    28,
      29,    30,    31,    32,     0,    33,    34,    35,    36,    37,
      38,     0,    39,    40,    41,     0,     0,    42,     0,     0,
      43,    44,     0,    45,    46,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    47,     0,     0,    48,    49,     0,    50,
      51,  -278,    52,     0,    53,    54,    55,    56,    57,    58,
      59,     0,     0,    60,  -278,  -278,  -278,  -278,  -278,  -278,
       0,  -278,     0,     0,   714,     0,     0,     0,  -278,  -278,
    -278,     0,     0,    61,    62,    63,     0,     0,  -278,  -278,
       0,  -278,  -278,  -278,  -278,  -278,  -555,  -555,     0,     0,
       0,   337,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,   349,     0,     0,   350,   351,     0,     0,
       0,     0,  -278,  -278,  -278,  -278,  -278,  -278,  -278,  -278,
    -278,  -278,  -278,  -278,  -278,     0,     0,  -278,  -278,  -278,
       0,   737,  -278,     0,     0,     0,     0,   352,  -278,   353,
     354,   355,   356,   357,   358,   359,   360,   361,   362,  -278,
       0,     0,     0,     0,     0,     0,     0,   -99,  -278,  -278,
    -278,  -278,  -278,  -278,  -278,  -278,  -278,  -278,  -278,  -278,
       0,     0,  -392,     0,     0,  -278,  -278,  -278,  -278,     0,
       0,  -278,  -278,  -278,  -278,  -392,  -392,  -392,  -392,  -392,
    -392,     0,  -392,     0,     0,   696,     0,     0,  -392,  -392,
    -392,     0,     0,     0,     0,     0,     0,     0,     0,  -392,
    -392,     0,  -392,  -392,  -392,  -392,  -392,     0,     0,     0,
       0,     0,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,     0,     0,   350,   351,     0,
       0,     0,     0,  -392,  -392,  -392,  -392,  -392,  -392,  -392,
    -392,  -392,  -392,  -392,  -392,  -392,     0,     0,  -392,  -392,
    -392,     0,     0,  -392,     0,     0,     0,     0,   352,  -392,
     353,   354,   355,   356,   357,   358,   359,   360,   361,   362,
       0,     0,     0,     0,     0,     0,     0,     0,  -230,  -392,
       0,  -392,  -392,  -392,  -392,  -392,  -392,  -392,  -392,  -392,
    -392,     0,     0,  -269,     0,  -392,  -392,  -392,  -392,  -392,
       0,   255,  -392,  -392,  -392,  -392,  -269,  -269,  -269,  -269,
    -269,  -269,     0,  -269,     0,     0,   696,     0,     0,     0,
    -269,  -269,  -269,     0,     0,     0,     0,     0,     0,     0,
    -269,  -269,     0,  -269,  -269,  -269,  -269,  -269,     0,     0,
       0,     0,     0,   337,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,   349,     0,     0,   350,   351,
       0,     0,     0,     0,  -269,  -269,  -269,  -269,  -269,  -269,
    -269,  -269,  -269,  -269,  -269,  -269,  -269,     0,     0,  -269,
    -269,  -269,     0,     0,  -269,     0,     0,     0,     0,   352,
    -269,   353,   354,   355,   356,   357,   358,   359,   360,   361,
     362,  -269,     0,     0,     0,     0,     0,     0,     0,     0,
    -269,  -269,  -269,  -269,  -269,  -269,  -269,  -269,  -269,  -269,
    -269,  -269,     0,     0,  -555,     0,     0,  -269,  -269,  -269,
    -269,     0,     0,  -269,  -269,  -269,  -269,  -555,  -555,  -555,
    -555,  -555,  -555,     0,  -555,     0,     0,     0,     0,     0,
    -555,  -555,  -555,     0,     0,     0,     0,     0,     0,     0,
       0,  -555,  -555,     0,  -555,  -555,  -555,  -555,  -555,     0,
       0,     0,     0,     0,   337,   338,   339,   340,   341,   342,
     343,   344,   345,   346,   347,   348,   349,     0,     0,   350,
     351,     0,     0,     0,     0,  -555,  -555,  -555,  -555,  -555,
    -555,  -555,  -555,  -555,  -555,  -555,  -555,  -555,     0,     0,
    -555,  -555,  -555,     0,     0,  -555,     0,     0,     0,     0,
     352,  -555,   353,   354,   355,   356,   357,   358,   359,   360,
     361,   362,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  -555,     0,  -555,  -555,  -555,  -555,  -555,  -555,  -555,
    -555,  -555,  -555,     0,     0,  -285,     0,  -555,  -555,  -555,
    -555,  -555,     0,   255,  -555,  -555,  -555,  -555,  -285,  -285,
    -285,  -285,  -285,  -285,     0,  -285,     0,     0,     0,     0,
       0,     0,  -285,  -285,     0,     0,     0,     0,     0,     0,
       0,     0,  -285,  -285,     0,  -285,  -285,  -285,  -285,  -285,
       0,     0,     0,     0,     0,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,  -556,  -556,     0,     0,
     350,   351,     0,     0,     0,     0,  -285,  -285,  -285,  -285,
    -285,  -285,  -285,  -285,  -285,  -285,  -285,  -285,  -285,     0,
       0,  -285,  -285,  -285,     0,     0,  -285,     0,     0,     0,
       0,     0,  -285,   353,   354,   355,   356,   357,   358,   359,
     360,   361,   362,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  -285,     0,  -285,  -285,  -285,  -285,  -285,  -285,
    -285,  -285,  -285,  -285,     0,     0,  -535,     0,     0,  -285,
    -285,  -285,  -285,     0,   252,  -285,  -285,  -285,  -285,  -535,
    -535,  -535,     0,  -535,  -535,     0,  -535,     0,     0,     0,
       0,     0,  -535,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  -535,  -535,     0,  -535,  -535,  -535,  -535,
    -535,     0,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,     0,     0,   350,   351,     0,
       0,     0,     0,     0,     0,     0,     0,  -535,  -535,  -535,
    -535,  -535,  -535,  -535,  -535,  -535,  -535,  -535,  -535,  -535,
       0,     0,  -535,  -535,  -535,     0,   698,     0,   352,     0,
     353,   354,   355,   356,   357,   358,   359,   360,   361,   362,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   -97,  -535,   232,  -535,  -535,  -535,  -535,  -535,
    -535,  -535,  -535,  -535,  -535,     0,     0,  -278,     0,  -535,
    -535,  -535,  -535,   -89,     0,     0,  -535,     0,  -535,  -535,
    -278,  -278,  -278,     0,  -278,  -278,     0,  -278,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  -278,  -278,     0,  -278,  -278,  -278,
    -278,  -278,   337,   338,   339,   340,   341,   342,   343,   344,
       0,   346,   347,     0,     0,     0,     0,   350,   351,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  -278,  -278,
    -278,  -278,  -278,  -278,  -278,  -278,  -278,  -278,  -278,  -278,
    -278,     0,     0,  -278,  -278,  -278,     0,   699,     0,     0,
     353,   354,   355,   356,   357,   358,   359,   360,   361,   362,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   -99,  -278,     0,  -278,  -278,  -278,  -278,
    -278,  -278,  -278,  -278,  -278,  -278,     0,     0,     0,     0,
       0,  -278,  -278,  -278,   -91,     0,     0,  -278,     0,  -278,
    -278,   268,     0,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,  -555,  -555,  -555,     0,     0,  -555,    15,
       0,    16,    17,    18,    19,     0,     0,     0,     0,     0,
      20,    21,    22,    23,    24,    25,    26,     0,     0,    27,
       0,     0,     0,     0,     0,    28,     0,    30,    31,    32,
       0,    33,    34,    35,    36,    37,    38,     0,    39,    40,
      41,     0,     0,    42,     0,     0,    43,    44,     0,    45,
      46,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    47,
       0,     0,    48,    49,     0,    50,    51,     0,    52,     0,
      53,    54,    55,    56,    57,    58,    59,     0,     0,    60,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    61,
      62,    63,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  -555,  -555,   268,     0,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,     0,     0,  -555,     0,
    -555,  -555,    15,     0,    16,    17,    18,    19,     0,     0,
       0,     0,     0,    20,    21,    22,    23,    24,    25,    26,
       0,     0,    27,     0,     0,     0,     0,     0,    28,     0,
      30,    31,    32,     0,    33,    34,    35,    36,    37,    38,
       0,    39,    40,    41,     0,     0,    42,     0,     0,    43,
      44,     0,    45,    46,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    47,     0,     0,    48,    49,     0,    50,    51,
       0,    52,     0,    53,    54,    55,    56,    57,    58,    59,
       0,     0,    60,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    61,    62,    63,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  -555,  -555,   268,     0,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,     0,
       0,  -555,     0,     0,  -555,    15,  -555,    16,    17,    18,
      19,     0,     0,     0,     0,     0,    20,    21,    22,    23,
      24,    25,    26,     0,     0,    27,     0,     0,     0,     0,
       0,    28,     0,    30,    31,    32,     0,    33,    34,    35,
      36,    37,    38,     0,    39,    40,    41,     0,     0,    42,
       0,     0,    43,    44,     0,    45,    46,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    47,     0,     0,    48,    49,
       0,    50,    51,     0,    52,     0,    53,    54,    55,    56,
      57,    58,    59,     0,     0,    60,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    61,    62,    63,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  -555,  -555,
     268,     0,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,     0,     0,  -555,     0,     0,  -555,    15,     0,
      16,    17,    18,    19,     0,     0,     0,     0,     0,    20,
      21,    22,    23,    24,    25,    26,     0,     0,    27,     0,
       0,     0,     0,     0,    28,     0,    30,    31,    32,     0,
      33,    34,    35,    36,    37,    38,     0,    39,    40,    41,
       0,     0,    42,     0,     0,    43,    44,     0,    45,    46,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    47,     0,
       0,    48,    49,     0,    50,    51,     0,    52,     0,    53,
      54,    55,    56,    57,    58,    59,     0,     0,    60,     0,
       0,     0,     0,     0,     4,     0,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,     0,     0,    61,    62,
      63,     0,    15,     0,    16,    17,    18,    19,     0,     0,
       0,  -555,  -555,    20,    21,    22,    23,    24,    25,    26,
       0,     0,    27,     0,     0,     0,     0,     0,    28,    29,
      30,    31,    32,     0,    33,    34,    35,    36,    37,    38,
       0,    39,    40,    41,     0,     0,    42,     0,     0,    43,
      44,     0,    45,    46,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    47,     0,     0,    48,    49,     0,    50,    51,
       0,    52,     0,    53,    54,    55,    56,    57,    58,    59,
       0,     0,    60,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    61,    62,    63,     0,     0,  -555,     0,     0,
       0,     0,     0,     0,     0,  -555,  -555,   268,     0,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,     0,
    -555,  -555,     0,     0,     0,    15,     0,    16,    17,    18,
      19,     0,     0,     0,     0,     0,    20,    21,    22,    23,
      24,    25,    26,     0,     0,    27,     0,     0,     0,     0,
       0,    28,     0,    30,    31,    32,     0,    33,    34,    35,
      36,    37,    38,     0,    39,    40,    41,     0,     0,    42,
       0,     0,    43,    44,     0,    45,    46,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    47,     0,     0,    48,    49,
       0,    50,    51,     0,    52,     0,    53,    54,    55,    56,
      57,    58,    59,     0,     0,    60,     0,     0,     0,     0,
       0,   268,     0,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,     0,     0,    61,    62,    63,     0,    15,
       0,    16,    17,    18,    19,     0,     0,     0,  -555,  -555,
      20,    21,    22,    23,    24,    25,    26,     0,     0,    27,
       0,     0,     0,     0,     0,    28,     0,    30,    31,    32,
       0,    33,    34,    35,    36,    37,    38,     0,    39,    40,
      41,     0,     0,    42,     0,     0,    43,    44,     0,    45,
      46,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    47,
       0,     0,   269,    49,     0,    50,    51,     0,    52,     0,
      53,    54,    55,    56,    57,    58,    59,     0,     0,    60,
       0,     0,     0,     0,     0,   268,     0,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,     0,     0,    61,
      62,    63,     0,    15,     0,    16,    17,    18,    19,     0,
    -555,     0,  -555,  -555,    20,    21,    22,    23,    24,    25,
      26,     0,     0,    27,     0,     0,     0,     0,     0,    28,
       0,    30,    31,    32,     0,    33,    34,    35,    36,    37,
      38,     0,    39,    40,    41,     0,     0,    42,     0,     0,
      43,    44,     0,    45,    46,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    47,     0,     0,    48,    49,     0,    50,
      51,     0,    52,     0,    53,    54,    55,    56,    57,    58,
      59,     0,     0,    60,     0,     0,     0,     0,     0,   268,
       0,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,     0,     0,    61,    62,    63,     0,    15,     0,    16,
      17,    18,    19,     0,  -555,     0,  -555,  -555,    20,    21,
      22,    23,    24,    25,    26,     0,     0,    27,     0,     0,
       0,     0,     0,    28,     0,    30,    31,    32,     0,    33,
      34,    35,    36,    37,    38,     0,    39,    40,    41,     0,
       0,    42,     0,     0,    43,    44,     0,    45,    46,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    47,     0,     0,
      48,    49,     0,    50,    51,     0,    52,     0,    53,    54,
      55,    56,    57,    58,    59,     0,     0,    60,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    61,    62,    63,
       0,     0,  -555,     0,     0,     0,     0,     0,     0,     0,
    -555,  -555,   268,     0,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,     0,     0,  -555,     0,     0,     0,
      15,     0,    16,    17,    18,    19,     0,     0,     0,     0,
       0,    20,    21,    22,    23,    24,    25,    26,     0,     0,
      27,     0,     0,     0,     0,     0,    28,     0,    30,    31,
      32,     0,    33,    34,    35,    36,    37,    38,     0,    39,
      40,    41,     0,     0,    42,     0,     0,    43,    44,     0,
      45,    46,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      47,     0,     0,    48,    49,     0,    50,    51,     0,    52,
       0,    53,    54,    55,    56,    57,    58,    59,     0,     0,
      60,     0,     0,     0,     0,     0,     0,     0,     5,     6,
       7,     8,     9,    10,    11,    12,    13,     0,     0,     0,
      61,    62,    63,     0,    15,     0,    16,    17,    18,    19,
       0,     0,     0,  -555,  -555,    20,    21,    22,    23,    24,
      25,    26,     0,     0,   106,     0,     0,     0,     0,     0,
       0,     0,     0,    31,    32,     0,    33,    34,    35,    36,
      37,    38,   238,    39,    40,    41,     0,     0,    42,     0,
       0,    43,    44,     0,    45,    46,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   200,     0,     0,   111,    49,     0,
      50,    51,     0,   239,   240,    53,    54,    55,    56,    57,
      58,    59,     0,     0,    60,     0,     0,     0,     0,     0,
       0,     0,     5,     6,     7,     8,     9,    10,    11,    12,
      13,     0,     0,     0,    61,   241,    63,     0,    15,     0,
      16,    17,    18,    19,     0,     0,     0,     0,   232,    20,
      21,    22,    23,    24,    25,    26,     0,     0,    27,     0,
       0,     0,     0,     0,     0,     0,     0,    31,    32,     0,
      33,    34,    35,    36,    37,    38,     0,    39,    40,    41,
       0,     0,    42,     0,     0,    43,    44,     0,    45,    46,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   200,     0,
       0,   111,    49,     0,    50,    51,     0,     0,     0,    53,
      54,    55,    56,    57,    58,    59,     0,     0,    60,     0,
       0,     0,     0,     0,     0,     0,     5,     6,     7,     8,
       9,    10,    11,    12,    13,     0,     0,     0,    61,    62,
      63,     0,    15,     0,    16,    17,    18,    19,     0,     0,
       0,   231,   232,    20,    21,    22,    23,    24,    25,    26,
       0,     0,    27,     0,     0,     0,     0,     0,     0,     0,
       0,    31,    32,     0,    33,    34,    35,    36,    37,    38,
       0,    39,    40,    41,     0,     0,    42,     0,     0,    43,
      44,     0,    45,    46,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   200,     0,     0,   111,    49,     0,    50,    51,
       0,     0,     0,    53,    54,    55,    56,    57,    58,    59,
       0,     0,    60,     0,     0,     0,     0,     0,     0,     0,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
       0,     0,    61,    62,    63,     0,    15,     0,    16,    17,
      18,    19,     0,     0,     0,     0,   232,    20,    21,    22,
      23,    24,    25,    26,     0,     0,    27,     0,     0,     0,
       0,     0,    28,    29,    30,    31,    32,     0,    33,    34,
      35,    36,    37,    38,     0,    39,    40,    41,     0,     0,
      42,     0,     0,    43,    44,     0,    45,    46,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    47,     0,     0,    48,
      49,     0,    50,    51,     0,    52,     0,    53,    54,    55,
      56,    57,    58,    59,     0,     0,    60,     0,     0,     0,
       0,     0,     0,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,     0,     0,     0,    61,    62,    63,    15,
       0,    16,    17,    18,    19,     0,     0,     0,     0,   418,
      20,    21,    22,    23,    24,    25,    26,     0,     0,    27,
       0,     0,     0,     0,     0,    28,     0,    30,    31,    32,
       0,    33,    34,    35,    36,    37,    38,     0,    39,    40,
      41,     0,     0,    42,     0,     0,    43,    44,     0,    45,
      46,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    47,
       0,     0,    48,    49,     0,    50,    51,     0,    52,     0,
      53,    54,    55,    56,    57,    58,    59,     0,     0,    60,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    61,
      62,    63,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   418,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,     0,     0,     0,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
       0,     0,     0,     0,     0,   155,   156,   157,   158,   159,
     160,   161,   162,    35,    36,   163,    38,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   164,
     165,   166,   167,   168,   169,   170,   171,   172,     0,     0,
     173,   174,     0,     0,   175,   176,   177,   178,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   179,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,     0,
     190,   191,     0,     0,     0,     0,     0,     0,   192,   193,
    -528,  -528,  -528,  -528,  -528,  -528,  -528,  -528,  -528,     0,
       0,     0,     0,     0,     0,     0,  -528,     0,  -528,  -528,
    -528,  -528,     0,  -528,     0,     0,     0,  -528,  -528,  -528,
    -528,  -528,  -528,  -528,     0,     0,  -528,     0,     0,     0,
       0,     0,     0,     0,     0,  -528,  -528,     0,  -528,  -528,
    -528,  -528,  -528,  -528,  -528,  -528,  -528,  -528,     0,     0,
    -528,     0,     0,  -528,  -528,     0,  -528,  -528,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  -528,     0,     0,  -528,
    -528,     0,  -528,  -528,     0,  -528,  -528,  -528,  -528,  -528,
    -528,  -528,  -528,  -528,     0,     0,  -528,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  -528,  -528,  -528,     0,
    -528,     0,     0,     0,     0,     0,  -528,  -529,  -529,  -529,
    -529,  -529,  -529,  -529,  -529,  -529,     0,     0,     0,     0,
       0,     0,     0,  -529,     0,  -529,  -529,  -529,  -529,     0,
    -529,     0,     0,     0,  -529,  -529,  -529,  -529,  -529,  -529,
    -529,     0,     0,  -529,     0,     0,     0,     0,     0,     0,
       0,     0,  -529,  -529,     0,  -529,  -529,  -529,  -529,  -529,
    -529,  -529,  -529,  -529,  -529,     0,     0,  -529,     0,     0,
    -529,  -529,     0,  -529,  -529,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  -529,     0,     0,  -529,  -529,     0,  -529,
    -529,     0,  -529,  -529,  -529,  -529,  -529,  -529,  -529,  -529,
    -529,     0,     0,  -529,     0,     0,     0,     0,     0,     0,
    -531,  -531,  -531,  -531,  -531,  -531,  -531,  -531,  -531,     0,
       0,     0,     0,  -529,  -529,  -529,  -531,  -529,  -531,  -531,
    -531,  -531,     0,  -529,     0,     0,     0,  -531,  -531,  -531,
    -531,  -531,  -531,  -531,     0,     0,  -531,     0,     0,     0,
       0,     0,     0,     0,     0,  -531,  -531,     0,  -531,  -531,
    -531,  -531,  -531,  -531,  -531,  -531,  -531,  -531,     0,     0,
    -531,     0,     0,  -531,  -531,     0,  -531,  -531,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  -531,   736,     0,  -531,
    -531,     0,  -531,  -531,     0,  -531,  -531,  -531,  -531,  -531,
    -531,  -531,  -531,  -531,     0,     0,  -531,     0,     0,     0,
       0,     0,     0,   -97,  -533,  -533,  -533,  -533,  -533,  -533,
    -533,  -533,  -533,     0,     0,     0,  -531,  -531,  -531,     0,
    -533,     0,  -533,  -533,  -533,  -533,  -531,     0,     0,     0,
       0,  -533,  -533,  -533,  -533,  -533,  -533,  -533,     0,     0,
    -533,     0,     0,     0,     0,     0,     0,     0,     0,  -533,
    -533,     0,  -533,  -533,  -533,  -533,  -533,  -533,  -533,  -533,
    -533,  -533,     0,     0,  -533,     0,     0,  -533,  -533,     0,
    -533,  -533,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    -533,     0,     0,  -533,  -533,     0,  -533,  -533,     0,  -533,
    -533,  -533,  -533,  -533,  -533,  -533,  -533,  -533,     0,     0,
    -533,     0,     0,     0,     0,     0,     0,  -534,  -534,  -534,
    -534,  -534,  -534,  -534,  -534,  -534,     0,     0,     0,     0,
    -533,  -533,  -533,  -534,     0,  -534,  -534,  -534,  -534,     0,
    -533,     0,     0,     0,  -534,  -534,  -534,  -534,  -534,  -534,
    -534,     0,     0,  -534,     0,     0,     0,     0,     0,     0,
       0,     0,  -534,  -534,     0,  -534,  -534,  -534,  -534,  -534,
    -534,  -534,  -534,  -534,  -534,     0,     0,  -534,     0,     0,
    -534,  -534,     0,  -534,  -534,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  -534,     0,     0,  -534,  -534,     0,  -534,
    -534,     0,  -534,  -534,  -534,  -534,  -534,  -534,  -534,  -534,
    -534,     0,     0,  -534,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  -534,  -534,  -534,     0,     0,     0,     0,
       0,     0,     0,  -534,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,     0,     0,
       0,   145,   146,   147,   218,   219,   220,   221,   152,   153,
     154,     0,     0,     0,     0,     0,   155,   156,   157,   222,
     223,   160,   224,   162,   293,   294,   225,   295,     0,     0,
       0,     0,     0,     0,   296,     0,     0,     0,     0,     0,
     164,   165,   166,   167,   168,   169,   170,   171,   172,     0,
       0,   173,   174,     0,     0,   175,   176,   177,   178,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   179,
       0,     0,     0,     0,     0,     0,   297,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
       0,   190,   191,     0,     0,     0,     0,     0,     0,   192,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,     0,     0,     0,   145,   146,   147,
     218,   219,   220,   221,   152,   153,   154,     0,     0,     0,
       0,     0,   155,   156,   157,   222,   223,   160,   224,   162,
     293,   294,   225,   295,     0,     0,     0,     0,     0,     0,
     296,     0,     0,     0,     0,     0,   164,   165,   166,   167,
     168,   169,   170,   171,   172,     0,     0,   173,   174,     0,
       0,   175,   176,   177,   178,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   179,     0,     0,     0,     0,
       0,     0,   412,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,     0,   190,   191,     0,
       0,     0,     0,     0,     0,   192,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
       0,     0,     0,   145,   146,   147,   218,   219,   220,   221,
     152,   153,   154,     0,     0,     0,     0,     0,   155,   156,
     157,   222,   223,   160,   224,   162,     0,     0,   225,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   164,   165,   166,   167,   168,   169,   170,   171,
     172,     0,     0,   173,   174,     0,     0,   175,   176,   177,
     178,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   179,     0,     0,   226,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,     0,   190,   191,     0,     0,     0,     0,     0,
       0,   192,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,     0,     0,     0,   145,
     146,   147,   218,   219,   220,   221,   152,   153,   154,     0,
       0,     0,     0,     0,   155,   156,   157,   222,   223,   160,
     224,   162,     0,     0,   225,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   164,   165,
     166,   167,   168,   169,   170,   171,   172,     0,     0,   173,
     174,     0,     0,   175,   176,   177,   178,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   179,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,     0,   190,
     191,     0,     0,     0,     0,     0,     0,   192,     5,     6,
       7,     8,     9,    10,    11,    12,    13,     0,     0,     0,
       0,     0,     0,     0,    15,     0,   101,   102,    18,    19,
       0,     0,     0,     0,     0,   103,   104,   105,    23,    24,
      25,    26,     0,     0,   106,     0,     0,     0,     0,     0,
       0,     0,     0,    31,    32,     0,    33,    34,    35,    36,
      37,    38,     0,    39,    40,    41,     0,     0,    42,     0,
       0,    43,    44,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   286,     0,     0,   111,    49,     0,
      50,    51,     0,     0,     0,    53,    54,    55,    56,    57,
      58,    59,     0,     0,    60,     0,     0,     5,     6,     7,
       8,     9,    10,    11,    12,    13,     0,     0,     0,     0,
       0,     0,     0,    15,   112,   101,   102,    18,    19,     0,
       0,     0,   287,     0,   103,   104,   105,    23,    24,    25,
      26,     0,     0,   106,     0,     0,     0,     0,     0,     0,
       0,     0,    31,    32,     0,    33,    34,    35,    36,    37,
      38,     0,    39,    40,    41,     0,     0,    42,     0,     0,
      43,    44,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   286,     0,     0,   111,    49,     0,    50,
      51,     0,     0,     0,    53,    54,    55,    56,    57,    58,
      59,     0,     0,    60,     0,     0,     5,     6,     7,     8,
       9,    10,    11,    12,    13,     0,     0,     0,     0,     0,
       0,     0,    15,   112,   101,   102,    18,    19,     0,     0,
       0,   527,     0,   103,   104,   105,    23,    24,    25,    26,
       0,     0,   106,     0,     0,     0,     0,     0,     0,     0,
       0,    31,    32,     0,    33,    34,    35,    36,    37,    38,
     238,    39,    40,    41,     0,     0,    42,     0,     0,    43,
      44,     0,    45,    46,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   200,     0,     0,   111,    49,     0,    50,    51,
       0,   630,   240,    53,    54,    55,    56,    57,    58,    59,
       0,     0,    60,   497,     0,     0,   498,   499,     0,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,     0,
       0,     0,    61,   241,    63,    15,     0,    16,    17,    18,
      19,     0,     0,     0,     0,     0,    20,    21,    22,    23,
      24,    25,    26,     0,     0,    27,     0,     0,     0,     0,
       0,    28,    29,    30,    31,    32,     0,    33,    34,    35,
      36,    37,    38,     0,    39,    40,    41,     0,     0,    42,
       0,     0,    43,    44,     0,    45,    46,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    47,     0,     0,    48,    49,
       0,    50,    51,     0,    52,     0,    53,    54,    55,    56,
      57,    58,    59,     0,     0,    60,     0,     0,     0,     0,
       0,     0,     5,     6,     7,     8,     9,    10,    11,    12,
      13,     0,     0,     0,     0,    61,    62,    63,    15,     0,
     101,   102,    18,    19,     0,     0,     0,     0,     0,   103,
     104,   105,    23,    24,    25,    26,     0,     0,   106,     0,
       0,     0,     0,     0,     0,     0,     0,    31,    32,     0,
      33,    34,    35,    36,    37,    38,   238,    39,    40,    41,
       0,     0,    42,     0,     0,    43,    44,     0,    45,    46,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   200,     0,
       0,   111,    49,     0,    50,    51,     0,   630,     0,    53,
      54,    55,    56,    57,    58,    59,     0,     0,    60,   497,
       0,     0,   498,   499,     0,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,     0,     0,     0,    61,   241,
      63,    15,     0,    16,    17,    18,    19,     0,     0,     0,
       0,     0,    20,    21,    22,    23,    24,    25,    26,     0,
       0,    27,     0,     0,     0,     0,     0,    28,     0,    30,
      31,    32,     0,    33,    34,    35,    36,    37,    38,     0,
      39,    40,    41,     0,     0,    42,     0,     0,    43,    44,
       0,    45,    46,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    47,     0,     0,    48,    49,     0,    50,    51,     0,
      52,     0,    53,    54,    55,    56,    57,    58,    59,     0,
       0,    60,     0,     0,     0,     0,     0,     0,     5,     6,
       7,     8,     9,    10,    11,    12,    13,     0,     0,     0,
       0,    61,    62,    63,    15,     0,   101,   102,    18,    19,
       0,     0,     0,     0,     0,   103,   104,   105,    23,    24,
      25,    26,     0,     0,   106,     0,     0,     0,     0,     0,
       0,     0,     0,    31,    32,     0,    33,    34,    35,    36,
      37,    38,     0,    39,    40,    41,     0,     0,    42,     0,
       0,    43,    44,     0,    45,    46,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   200,     0,     0,   111,    49,     0,
      50,    51,     0,   751,     0,    53,    54,    55,    56,    57,
      58,    59,     0,     0,    60,   497,     0,     0,   498,   499,
       0,     5,     6,     7,     8,     9,    10,    11,    12,    13,
       0,     0,     0,     0,    61,   241,    63,    15,     0,   101,
     102,    18,    19,     0,     0,     0,     0,     0,   103,   104,
     105,    23,    24,    25,    26,     0,     0,   106,     0,     0,
       0,     0,     0,     0,     0,     0,    31,    32,     0,    33,
      34,    35,    36,    37,    38,     0,    39,    40,    41,     0,
       0,    42,     0,     0,    43,    44,     0,    45,    46,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   200,     0,     0,
     111,    49,     0,    50,    51,     0,   788,     0,    53,    54,
      55,    56,    57,    58,    59,     0,     0,    60,   497,     0,
       0,   498,   499,     0,     5,     6,     7,     8,     9,    10,
      11,    12,    13,     0,     0,     0,     0,    61,   241,    63,
      15,     0,   101,   102,    18,    19,     0,     0,     0,     0,
       0,   103,   104,   105,    23,    24,    25,    26,     0,     0,
     106,     0,     0,     0,     0,     0,     0,     0,     0,    31,
      32,     0,    33,    34,    35,    36,    37,    38,     0,    39,
      40,    41,     0,     0,    42,     0,     0,    43,    44,     0,
      45,    46,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     200,     0,     0,   111,    49,     0,    50,    51,     0,   630,
       0,    53,    54,    55,    56,    57,    58,    59,     0,     0,
      60,   497,     0,     0,   498,   499,     0,     5,     6,     7,
       8,     9,    10,    11,    12,    13,     0,     0,     0,     0,
      61,   241,    63,    15,     0,    16,    17,    18,    19,     0,
       0,     0,     0,     0,    20,    21,    22,    23,    24,    25,
      26,     0,     0,   106,     0,     0,     0,     0,     0,     0,
       0,     0,    31,    32,     0,    33,    34,    35,    36,    37,
      38,   238,    39,    40,    41,     0,     0,    42,     0,     0,
      43,    44,     0,    45,    46,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   200,     0,     0,   111,    49,     0,    50,
      51,     0,   239,   240,    53,    54,    55,    56,    57,    58,
      59,     0,     0,    60,     0,     0,     0,     0,     0,     0,
       5,     6,     7,     8,     9,    10,    11,    12,    13,     0,
       0,     0,     0,    61,   241,    63,    15,     0,   101,   102,
      18,    19,     0,     0,     0,     0,     0,   103,   104,   105,
      23,    24,    25,    26,     0,     0,   106,     0,     0,     0,
       0,     0,     0,     0,     0,    31,    32,     0,    33,    34,
      35,    36,    37,    38,   238,    39,    40,    41,     0,     0,
      42,     0,     0,    43,    44,     0,    45,    46,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   200,     0,     0,   111,
      49,     0,    50,    51,     0,   239,     0,    53,    54,    55,
      56,    57,    58,    59,     0,     0,    60,     0,     0,     0,
       0,     0,     0,     5,     6,     7,     8,     9,    10,    11,
      12,    13,     0,     0,     0,     0,    61,   241,    63,    15,
       0,   101,   102,    18,    19,     0,     0,     0,     0,     0,
     103,   104,   105,    23,    24,    25,    26,     0,     0,   106,
       0,     0,     0,     0,     0,     0,     0,     0,    31,    32,
       0,    33,    34,    35,    36,    37,    38,   238,    39,    40,
      41,     0,     0,    42,     0,     0,    43,    44,     0,    45,
      46,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   200,
       0,     0,   111,    49,     0,    50,    51,     0,     0,   240,
      53,    54,    55,    56,    57,    58,    59,     0,     0,    60,
       0,     0,     0,     0,     0,     0,     5,     6,     7,     8,
       9,    10,    11,    12,    13,     0,     0,     0,     0,    61,
     241,    63,    15,     0,   101,   102,    18,    19,     0,     0,
       0,     0,     0,   103,   104,   105,    23,    24,    25,    26,
       0,     0,   106,     0,     0,     0,     0,     0,     0,     0,
       0,    31,    32,     0,    33,    34,    35,    36,    37,    38,
     238,    39,    40,    41,     0,     0,    42,     0,     0,    43,
      44,     0,    45,    46,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   200,     0,     0,   111,    49,     0,    50,    51,
       0,     0,     0,    53,    54,    55,    56,    57,    58,    59,
       0,     0,    60,     0,     0,     0,     0,     0,     0,     5,
       6,     7,     8,     9,    10,    11,    12,    13,     0,     0,
       0,     0,    61,   241,    63,    15,     0,    16,    17,    18,
      19,     0,     0,     0,     0,     0,    20,    21,    22,    23,
      24,    25,    26,     0,     0,   106,     0,     0,     0,     0,
       0,     0,     0,     0,    31,    32,     0,    33,    34,    35,
      36,    37,    38,     0,    39,    40,    41,     0,     0,    42,
       0,     0,    43,    44,     0,    45,    46,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   200,     0,     0,   111,    49,
       0,    50,    51,     0,   521,     0,    53,    54,    55,    56,
      57,    58,    59,     0,     0,    60,     0,     0,     0,     0,
       0,     0,     5,     6,     7,     8,     9,    10,    11,    12,
      13,     0,     0,     0,     0,    61,   241,    63,    15,     0,
     101,   102,    18,    19,     0,     0,     0,     0,     0,   103,
     104,   105,    23,    24,    25,    26,     0,     0,   106,     0,
       0,     0,     0,     0,     0,     0,     0,    31,    32,     0,
      33,    34,    35,    36,    37,    38,     0,    39,    40,    41,
       0,     0,    42,     0,     0,    43,    44,     0,    45,    46,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   200,     0,
       0,   111,    49,     0,    50,    51,     0,   239,     0,    53,
      54,    55,    56,    57,    58,    59,     0,     0,    60,     0,
       0,     0,     0,     0,     0,     5,     6,     7,     8,     9,
      10,    11,    12,    13,     0,     0,     0,     0,    61,   241,
      63,    15,     0,   101,   102,    18,    19,     0,     0,     0,
       0,     0,   103,   104,   105,    23,    24,    25,    26,     0,
       0,   106,     0,     0,     0,     0,     0,     0,     0,     0,
      31,    32,     0,    33,    34,    35,    36,    37,    38,     0,
      39,    40,    41,     0,     0,    42,     0,     0,    43,    44,
       0,    45,    46,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   200,     0,     0,   111,    49,     0,    50,    51,     0,
     521,     0,    53,    54,    55,    56,    57,    58,    59,     0,
       0,    60,     0,     0,     0,     0,     0,     0,     5,     6,
       7,     8,     9,    10,    11,    12,    13,     0,     0,     0,
       0,    61,   241,    63,    15,     0,    16,    17,    18,    19,
       0,     0,     0,     0,     0,    20,    21,    22,    23,    24,
      25,    26,     0,     0,    27,     0,     0,     0,     0,     0,
       0,     0,     0,    31,    32,     0,    33,    34,    35,    36,
      37,    38,     0,    39,    40,    41,     0,     0,    42,     0,
       0,    43,    44,     0,    45,    46,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   200,     0,     0,   111,    49,     0,
      50,    51,     0,     0,     0,    53,    54,    55,    56,    57,
      58,    59,     0,     0,    60,     0,     0,     0,     0,     0,
       0,     5,     6,     7,     8,     9,    10,    11,    12,    13,
       0,     0,     0,     0,    61,    62,    63,    15,     0,   101,
     102,    18,    19,     0,     0,     0,     0,     0,   103,   104,
     105,    23,    24,    25,    26,     0,     0,   106,     0,     0,
       0,     0,     0,     0,     0,     0,    31,    32,     0,    33,
      34,    35,    36,    37,    38,     0,    39,    40,    41,     0,
       0,    42,     0,     0,    43,    44,     0,    45,    46,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   200,     0,     0,
     111,    49,     0,    50,    51,     0,     0,     0,    53,    54,
      55,    56,    57,    58,    59,     0,     0,    60,     0,     0,
       0,     0,     0,     0,     5,     6,     7,     8,     9,    10,
      11,    12,    13,     0,     0,     0,     0,    61,   241,    63,
      15,     0,    16,    17,    18,    19,     0,     0,     0,     0,
       0,    20,    21,    22,    23,    24,    25,    26,     0,     0,
     106,     0,     0,     0,     0,     0,     0,     0,     0,    31,
      32,     0,    33,    34,    35,    36,    37,    38,     0,    39,
      40,    41,     0,     0,    42,     0,     0,    43,    44,     0,
      45,    46,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     200,     0,     0,   111,    49,     0,    50,    51,     0,     0,
       0,    53,    54,    55,    56,    57,    58,    59,     0,     0,
      60,     0,     0,     0,     0,     0,     0,     5,     6,     7,
       8,     9,    10,    11,    12,    13,     0,     0,     0,     0,
      61,   241,    63,    15,     0,   101,   102,    18,    19,     0,
       0,     0,     0,     0,   103,   104,   105,    23,    24,    25,
      26,     0,     0,   106,     0,     0,     0,     0,     0,     0,
       0,     0,    31,    32,     0,   107,    34,    35,    36,   108,
      38,     0,    39,    40,    41,     0,     0,    42,     0,     0,
      43,    44,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     109,     0,     0,   110,     0,     0,   111,    49,     0,    50,
      51,     0,     0,     0,    53,    54,    55,    56,    57,    58,
      59,     0,     0,    60,     0,     0,     5,     6,     7,     8,
       9,    10,    11,    12,    13,     0,     0,     0,     0,     0,
       0,     0,    15,   112,   101,   102,    18,    19,     0,     0,
       0,     0,     0,   103,   104,   105,    23,    24,    25,    26,
       0,     0,   106,     0,     0,     0,     0,     0,     0,     0,
       0,    31,    32,     0,    33,    34,    35,    36,    37,    38,
       0,    39,    40,    41,     0,     0,    42,     0,     0,    43,
      44,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   211,     0,     0,    48,    49,     0,    50,    51,
       0,    52,     0,    53,    54,    55,    56,    57,    58,    59,
       0,     0,    60,     0,     0,     5,     6,     7,     8,     9,
      10,    11,    12,    13,     0,     0,     0,     0,     0,     0,
       0,    15,   112,   101,   102,    18,    19,     0,     0,     0,
       0,     0,   103,   104,   105,    23,    24,    25,    26,     0,
       0,   106,     0,     0,     0,     0,     0,     0,     0,     0,
      31,    32,     0,    33,    34,    35,    36,    37,    38,     0,
      39,    40,    41,     0,     0,    42,     0,     0,    43,    44,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   286,     0,     0,   333,    49,     0,    50,    51,     0,
     334,     0,    53,    54,    55,    56,    57,    58,    59,     0,
       0,    60,     0,     0,     5,     6,     7,     8,     9,    10,
      11,    12,    13,     0,     0,     0,     0,     0,     0,     0,
      15,   112,   101,   102,    18,    19,     0,     0,     0,     0,
       0,   103,   104,   105,    23,    24,    25,    26,     0,     0,
     106,     0,     0,     0,     0,     0,     0,     0,     0,    31,
      32,     0,   107,    34,    35,    36,   108,    38,     0,    39,
      40,    41,     0,     0,    42,     0,     0,    43,    44,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     110,     0,     0,   111,    49,     0,    50,    51,     0,     0,
       0,    53,    54,    55,    56,    57,    58,    59,     0,     0,
      60,     0,     0,     5,     6,     7,     8,     9,    10,    11,
      12,    13,     0,     0,     0,     0,     0,     0,     0,    15,
     112,   101,   102,    18,    19,     0,     0,     0,     0,     0,
     103,   104,   105,    23,    24,    25,    26,     0,     0,   106,
       0,     0,     0,     0,     0,     0,     0,     0,    31,    32,
       0,    33,    34,    35,    36,    37,    38,     0,    39,    40,
      41,     0,     0,    42,     0,     0,    43,    44,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   286,
       0,     0,   333,    49,     0,    50,    51,     0,     0,     0,
      53,    54,    55,    56,    57,    58,    59,     0,     0,    60,
       0,     0,     5,     6,     7,     8,     9,    10,    11,    12,
      13,     0,     0,     0,     0,     0,     0,     0,    15,   112,
     101,   102,    18,    19,     0,     0,     0,     0,     0,   103,
     104,   105,    23,    24,    25,    26,     0,     0,   106,     0,
       0,     0,     0,     0,     0,     0,     0,    31,    32,     0,
      33,    34,    35,    36,    37,    38,     0,    39,    40,    41,
       0,     0,    42,     0,     0,    43,    44,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   859,     0,
       0,   111,    49,     0,    50,    51,     0,     0,     0,    53,
      54,    55,    56,    57,    58,    59,     0,     0,    60,     0,
       0,     5,     6,     7,     8,     9,    10,    11,    12,    13,
       0,     0,     0,     0,     0,     0,     0,    15,   112,   101,
     102,    18,    19,     0,     0,     0,     0,     0,   103,   104,
     105,    23,    24,    25,    26,     0,     0,   106,     0,     0,
       0,     0,     0,     0,     0,     0,    31,    32,     0,    33,
      34,    35,    36,    37,    38,     0,    39,    40,    41,     0,
       0,    42,     0,     0,    43,    44,     0,   337,  -556,  -556,
    -556,  -556,   342,   343,     0,     0,  -556,  -556,     0,     0,
       0,     0,   350,   351,     0,     0,     0,   877,     0,     0,
     111,    49,     0,    50,    51,     0,     0,     0,    53,    54,
      55,    56,    57,    58,    59,     0,     0,    60,     0,     0,
     570,   571,     0,     0,   572,   353,   354,   355,   356,   357,
     358,   359,   360,   361,   362,     0,     0,   112,   164,   165,
     166,   167,   168,   169,   170,   171,   172,     0,     0,   173,
     174,     0,     0,   175,   176,   177,   178,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   179,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,     0,   190,
     191,   590,   563,     0,     0,   591,     0,   192,   255,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   164,
     165,   166,   167,   168,   169,   170,   171,   172,     0,     0,
     173,   174,     0,     0,   175,   176,   177,   178,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   179,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,     0,
     190,   191,   576,   571,     0,     0,   577,     0,   192,   255,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     164,   165,   166,   167,   168,   169,   170,   171,   172,     0,
       0,   173,   174,     0,     0,   175,   176,   177,   178,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   179,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
       0,   190,   191,   607,   563,     0,     0,   608,     0,   192,
     255,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   164,   165,   166,   167,   168,   169,   170,   171,   172,
       0,     0,   173,   174,     0,     0,   175,   176,   177,   178,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     179,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,     0,   190,   191,   610,   571,     0,     0,   611,     0,
     192,   255,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   164,   165,   166,   167,   168,   169,   170,   171,
     172,     0,     0,   173,   174,     0,     0,   175,   176,   177,
     178,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   179,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,     0,   190,   191,   617,   563,     0,     0,   618,
       0,   192,   255,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   164,   165,   166,   167,   168,   169,   170,
     171,   172,     0,     0,   173,   174,     0,     0,   175,   176,
     177,   178,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   179,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,     0,   190,   191,   620,   571,     0,     0,
     621,     0,   192,   255,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   164,   165,   166,   167,   168,   169,
     170,   171,   172,     0,     0,   173,   174,     0,     0,   175,
     176,   177,   178,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   179,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,     0,   190,   191,   652,   563,     0,
       0,   653,     0,   192,   255,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   164,   165,   166,   167,   168,
     169,   170,   171,   172,     0,     0,   173,   174,     0,     0,
     175,   176,   177,   178,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   179,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,     0,   190,   191,   655,   571,
       0,     0,   656,     0,   192,   255,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   164,   165,   166,   167,
     168,   169,   170,   171,   172,     0,     0,   173,   174,     0,
       0,   175,   176,   177,   178,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   179,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,     0,   190,   191,   937,
     563,     0,     0,   938,     0,   192,   255,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   164,   165,   166,
     167,   168,   169,   170,   171,   172,     0,     0,   173,   174,
       0,     0,   175,   176,   177,   178,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   179,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,     0,   190,   191,
     944,   563,     0,     0,   945,     0,   192,   255,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   164,   165,
     166,   167,   168,   169,   170,   171,   172,     0,     0,   173,
     174,     0,     0,   175,   176,   177,   178,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   179,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,     0,   190,
     191,   947,   571,     0,     0,   948,     0,   192,   255,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   164,
     165,   166,   167,   168,   169,   170,   171,   172,     0,     0,
     173,   174,     0,     0,   175,   176,   177,   178,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   179,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,     0,
     190,   191,   576,   571,     0,     0,   577,     0,   192,   255,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     164,   165,   166,   167,   168,   169,   170,   171,   172,     0,
       0,   173,   174,     0,     0,   175,   176,   177,   178,     0,
       0,     0,   337,   338,   339,   340,   341,   342,   343,   179,
       0,   346,   347,     0,     0,     0,     0,   350,   351,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
       0,   190,   191,     0,     0,     0,     0,     0,     0,   192,
     353,   354,   355,   356,   357,   358,   359,   360,   361,   362
};

static const yytype_int16 yycheck[] =
{
       2,   426,    27,    16,    17,    62,    83,    20,   388,   248,
      15,     7,   292,    28,    14,     5,     6,   336,    76,   406,
     292,    16,    17,    13,     4,    20,   208,    48,    28,   594,
     364,   415,    65,   458,    22,   280,    52,   287,   110,   284,
     363,   602,   365,   336,   609,   368,    16,    17,    50,    51,
      20,   612,   386,   671,   619,    50,    51,   466,    54,     2,
      65,     4,    52,    15,   387,   667,   400,    65,   500,   760,
     423,   579,   580,   426,   762,   409,   399,    26,   401,    25,
      50,   686,    27,   686,   475,    16,    76,   410,   842,   654,
      29,   861,    26,    16,    17,    88,   269,    20,    16,   140,
      22,    88,   143,   304,    90,     9,    10,   133,    37,    38,
      98,    15,    79,    65,   363,    90,   365,   105,   527,   368,
      25,   444,    10,    71,    48,    16,     0,    15,    25,    28,
     116,   119,    25,    88,   468,    16,   385,    16,   387,    90,
      90,   116,   135,   136,    16,    55,   469,   838,    25,   136,
     399,   137,   401,   116,   121,    25,    18,    90,    20,   408,
     333,   410,    88,   933,    25,   116,   116,    17,    18,   108,
     139,    88,   926,   137,   779,    88,    98,    25,   126,   127,
     128,   136,    90,   116,   133,   667,   137,   111,    88,   671,
     139,   137,   139,   625,   443,   444,   435,   142,   143,   133,
     480,   633,   893,   891,   686,   109,   137,   715,   480,   589,
     136,   142,   143,   414,   143,   640,   466,    88,   467,   136,
     469,   139,   135,   136,   142,   143,    26,   845,   233,   287,
     226,   137,   137,   116,   925,   233,   136,   143,   271,   252,
     137,   254,   255,   137,   137,   247,   248,   849,   269,   143,
     202,   142,   143,   255,   857,   857,   208,   252,   861,   254,
     137,   142,   143,   142,   143,   136,   271,   137,   659,   660,
     142,   143,   833,   271,   331,    88,   137,   527,   139,   336,
     139,   233,   252,   701,   254,   694,   639,   640,    88,   137,
     708,   139,    88,    58,    59,   120,     2,   287,     4,     5,
       6,    88,    88,     9,    10,   209,   210,    13,   601,    15,
      16,    17,   333,   385,    20,   372,   373,    88,   334,   271,
     139,   209,   210,   136,   143,   268,   598,   279,   280,   252,
     933,   254,   284,   133,    90,   135,   136,    55,   258,   263,
     136,   321,    48,   723,   334,   269,    52,    25,   135,   136,
     136,   364,    25,   273,   258,   259,    62,   277,   745,    90,
     116,   331,   364,   845,   135,   136,   336,    90,   139,   760,
      76,   762,   276,   386,   137,   857,   695,   365,   321,   861,
     143,   946,    51,   326,   386,   116,    55,   400,   142,   143,
     116,   393,   116,   116,    90,   634,   409,    55,   400,   387,
     405,   406,    25,   109,   649,   111,   464,   409,   466,   333,
     835,   137,   137,   401,   686,    26,    37,    38,   322,   323,
     324,   325,   410,   327,   328,   440,    26,    20,   423,    58,
      59,   811,   434,   435,   322,   323,   324,   325,   116,   441,
     440,   142,   722,   116,   694,   627,   416,   838,   839,   833,
     722,   933,    90,   405,   406,   468,   444,    91,    26,   137,
     455,   137,   140,   137,   137,   143,   468,   140,   133,   527,
     143,   143,   396,    71,   464,   116,   466,    88,   116,   140,
     404,   469,   835,    88,   486,   389,   141,   489,    88,   491,
     134,   110,   137,   199,   113,   114,   876,    55,   441,   137,
     891,    71,   893,   209,   210,    71,   137,   450,   428,    97,
      61,    88,   432,    64,    65,   754,    15,   437,   520,    13,
      88,    16,   133,    63,   135,   136,   551,   447,   139,    15,
     135,   136,   140,   133,   925,   135,   136,   527,    51,   139,
      53,    54,    55,    56,   569,   817,   252,   110,   254,   255,
     113,   114,   258,   259,    90,   137,   137,   263,   135,   136,
     111,   112,   268,   269,   137,   133,   116,   135,   136,   594,
     276,   139,   496,   575,   134,   137,   578,   579,   580,   567,
     116,   287,   587,   137,   609,   919,    51,   575,   137,    63,
     578,    51,   137,   595,   619,   137,   137,   920,   116,   601,
     602,   137,   604,   599,    15,   593,   526,   595,   623,    51,
     612,    53,    54,    55,    56,   321,   322,   323,   324,   325,
     326,   327,   328,   623,   137,   331,    88,   333,   334,   654,
     336,   601,   634,   710,    18,   587,   694,   819,   695,    88,
     665,   698,   699,   825,   639,   567,    90,   704,   705,    15,
     134,    61,    90,   575,    64,    65,   578,   137,   364,   134,
     909,   686,    56,    57,    58,    59,   372,   373,    71,   918,
     137,   920,   116,   135,   136,   627,    15,   597,   116,   118,
     386,    14,   388,   389,   588,   141,   135,   136,    15,    62,
     396,    64,    65,   137,   400,   137,    91,   649,   404,   137,
     588,   111,   112,   409,   694,    51,    15,    53,    54,    55,
      56,   137,   717,   715,   137,   140,   137,   137,   622,   724,
     142,   124,   125,   126,   127,   128,   728,    15,   648,   731,
     137,   137,   134,    88,   622,   441,   121,    88,   111,   112,
     745,    71,   799,   663,   450,    51,    92,    53,    54,    55,
      56,   137,   754,    99,   779,   679,    86,    87,   464,   137,
     466,   137,   468,   687,    15,   717,   137,   134,   770,   771,
      15,   773,   724,   775,   776,    15,    15,   123,   137,   781,
     135,   136,   784,   785,   135,   136,    92,    15,   712,   713,
     496,   134,   782,   745,   124,   125,   126,   127,   128,    51,
     121,    53,    54,    55,    56,    55,   730,    71,   137,    51,
     134,    53,    54,    55,    56,    15,    15,    55,   742,   743,
     137,   527,    86,    87,   137,   749,   137,   137,   818,   733,
     137,   833,    15,     2,   139,     4,   139,   137,   441,   759,
       9,    10,   766,   767,     6,   733,    15,    16,    17,   578,
      92,    20,   489,    13,   491,   671,    98,    99,   674,   123,
     124,   125,   126,   127,   128,    88,   922,   819,   659,   711,
     686,   896,   926,   825,    62,   921,    64,    65,    88,    48,
     502,   123,   588,   589,   126,     7,   810,    51,   667,    53,
      54,    55,    56,    62,   814,   857,    88,   139,   822,   901,
     902,   903,   904,   817,   906,   907,   919,   198,   910,    -1,
     912,   913,   135,   136,    -1,    -1,   622,   919,    -1,   921,
     922,   946,    -1,   111,   112,   135,   136,    -1,    92,    63,
      64,    65,   920,    -1,    98,    99,    63,    64,    65,    -1,
     109,    -1,   111,   135,   136,    -1,    63,    64,    65,    -1,
      -1,    -1,   954,   955,   956,   957,   958,    -1,   882,   123,
     884,    -1,   126,   887,   966,    -1,    -1,    51,    -1,    53,
      54,    55,    56,   679,    -1,    -1,    -1,   111,   112,   143,
      -1,   687,    -1,    -1,   111,   112,    -1,    -1,   694,   695,
      -1,    -1,   698,   699,   111,   112,    -1,    -1,   704,   705,
      63,    64,    65,    -1,    -1,    -1,   712,   713,    92,    -1,
      63,    64,    65,    -1,    98,    99,    -1,   723,    63,    64,
      65,    -1,    16,    17,   730,    -1,    20,   733,    -1,   845,
     199,   847,    63,    64,    65,   851,   742,   743,    -1,   123,
     209,   210,   126,   749,    -1,   861,    -1,   863,   111,   112,
      -1,    45,    46,    -1,    -1,   139,    50,    51,   111,   112,
     766,   767,   297,    -1,    -1,    -1,   111,   112,    62,    63,
     305,    -1,    -1,   308,    -1,   310,   782,   312,    -1,   314,
     111,   112,    -1,   252,    -1,   254,   255,    -1,    -1,   258,
     259,    -1,    -1,   799,   263,    -1,    -1,    -1,    -1,   268,
     269,    -1,    -1,    -1,   810,   811,    -1,   276,    -1,    -1,
      -1,    -1,   818,   929,    -1,    -1,   822,   933,    -1,   935,
      -1,    -1,    -1,    -1,   940,    51,    -1,    53,    54,    55,
      56,    -1,    -1,   770,   771,    71,   773,    -1,   775,   776,
      -1,    -1,    -1,    -1,   781,    -1,   962,   784,   785,    -1,
      86,    87,   321,   322,   323,   324,   325,   326,   327,   328,
      -1,    -1,   331,    -1,   333,    -1,    92,   336,    -1,    -1,
     876,    -1,    98,    99,    -1,    -1,   882,    -1,   884,    -1,
      -1,   887,    -1,    -1,    -1,   121,   122,   123,   124,   125,
     126,   127,   128,    -1,    -1,   364,    -1,   123,    -1,    -1,
     126,    -1,    -1,   372,   373,    -1,    -1,    51,    -1,    53,
      54,    55,    56,   919,    -1,    -1,    -1,   386,    -1,   388,
     389,    51,    -1,    53,    54,    55,    56,   396,    -1,    -1,
      -1,   400,    -1,    -1,    -1,   404,    -1,    -1,    -1,    -1,
     409,    -1,    -1,    -1,   238,   239,   240,   241,    92,    40,
      41,    42,    43,    44,    98,    -1,    -1,    -1,   252,    -1,
     254,   255,    92,    -1,   901,   902,   903,   904,    98,   906,
     907,    -1,   441,   910,    -1,   912,   913,    -1,    -1,    -1,
      -1,   450,    -1,    -1,    -1,     2,    -1,     4,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    13,    -1,    -1,   468,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   954,   955,   956,
     957,   958,    -1,    -1,    -1,    -1,    -1,   496,    -1,   966,
      -1,    48,    -1,    -1,    -1,    -1,    -1,   331,    -1,    -1,
      -1,    -1,   336,   337,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,   349,   350,   351,   352,   353,
     354,   355,   356,   357,   358,   359,   360,   361,   362,    -1,
     364,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   372,   373,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   386,    -1,   111,    -1,    -1,     2,    -1,     4,
      -1,    -1,    -1,    -1,   398,    -1,   400,    -1,   402,   403,
      -1,    -1,    -1,    -1,    -1,   409,    -1,    -1,    -1,   588,
     589,    -1,   416,    -1,    -1,    -1,    -1,    -1,   422,   423,
      -1,    -1,   426,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    48,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   445,    -1,   622,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   455,    -1,    -1,   458,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   468,    -1,    -1,    -1,    -1,    -1,
      -1,    51,   199,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     2,   487,     4,     5,     6,     7,    -1,    -1,
      -1,    -1,    -1,    13,    -1,    -1,   111,    -1,    -1,    -1,
     679,    -1,    -1,    -1,    -1,    -1,   510,   511,   687,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   695,   521,    -1,   698,
     699,    -1,    -1,    -1,    -1,   704,   705,    -1,    48,    -1,
      -1,    -1,    52,   712,   713,    -1,   263,    -1,    -1,    -1,
      -1,   268,   269,    -1,   723,    -1,    -1,    -1,    -1,    -1,
      -1,   730,    -1,    -1,   733,    -1,    76,    -1,    -1,    -1,
      -1,    -1,    -1,   742,   743,    -1,    -1,    -1,    -1,    -1,
     749,     2,    -1,     4,     5,     6,    -1,    -1,    -1,    -1,
      -1,    -1,    13,    -1,   199,    -1,    -1,   766,   767,    -1,
      -1,   111,    -1,    -1,   321,    -1,    -1,   601,    -1,   326,
      -1,    -1,    -1,    -1,    -1,    -1,   333,    -1,    -1,   336,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,    -1,    -1,
     799,    52,    -1,    -1,    -1,    -1,   630,    -1,    -1,   633,
      -1,   810,   811,    -1,    -1,   639,   640,    -1,    -1,    -1,
      -1,    -1,    -1,   822,    -1,    76,    -1,    -1,   263,    -1,
      -1,    -1,    -1,   268,   269,    -1,    -1,    -1,   238,   239,
     240,   388,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   396,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   404,    -1,   199,
     111,    -1,    -1,    -1,    -1,    -1,    -1,   691,    -1,    -1,
      -1,   695,   696,    -1,   698,   699,    -1,   876,    -1,    -1,
     704,   705,    -1,   882,    -1,   884,   321,    -1,   887,    -1,
     714,   326,    -1,    -1,   441,    -1,    -1,    -1,   333,    -1,
      -1,    -1,    -1,   450,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   736,   737,    -1,   739,   740,    -1,    -1,    -1,
     919,    -1,    -1,   263,   748,    -1,    -1,   751,   268,   269,
      -1,   331,    -1,    -1,    -1,    -1,   336,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   287,   199,   496,
      -1,    -1,    -1,   388,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   396,    -1,    -1,   788,    -1,    -1,    -1,   792,   404,
      -1,    -1,    -1,    -1,    -1,   799,    -1,    -1,    -1,    -1,
      -1,   321,    -1,    -1,    -1,    -1,   326,    -1,    -1,    -1,
      -1,    -1,    -1,   333,   334,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   827,    -1,    -1,   441,    -1,    -1,    -1,
      -1,   835,   263,    -1,    -1,   450,   416,   268,   269,    -1,
      -1,    -1,   422,   423,    -1,    -1,   426,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   287,    -1,    -1,    -1,
      -1,    -1,   589,    -1,    -1,    -1,    -1,    -1,   388,    -1,
      -1,    -1,    -1,    -1,    -1,   455,   396,    -1,   458,    -1,
      -1,   496,    -1,    -1,   404,    -1,    -1,    -1,    -1,    -1,
     321,    -1,    -1,    -1,    -1,   326,    -1,    -1,    -1,    -1,
      -1,    -1,   333,   334,    -1,    -1,    -1,   487,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   919,    -1,    -1,    -1,    -1,
      -1,   441,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     450,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   521,    -1,    -1,   464,    -1,   466,    -1,    -1,    -1,
      -1,    -1,   679,    -1,    -1,    -1,    -1,   388,    -1,    -1,
     687,    -1,    -1,    -1,    -1,   396,    -1,    -1,   695,    -1,
      -1,    -1,    -1,   404,   589,    -1,   496,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   712,   713,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   723,    -1,    -1,    -1,
      -1,    -1,    -1,   730,    -1,    -1,    -1,   527,    -1,    -1,
     441,    -1,    -1,    -1,    -1,   742,   743,    -1,    -1,   450,
      -1,   601,   749,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   464,    -1,   466,    -1,    -1,    -1,   766,
     767,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     630,    -1,    -1,   633,    -1,    -1,    -1,    -1,    -1,   639,
     640,    -1,    -1,    -1,   679,   496,    -1,    -1,    -1,   589,
      -1,    -1,   687,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   810,   811,    -1,    -1,    -1,    -1,    -1,
      -1,   818,    -1,    -1,    -1,   822,   527,   712,   713,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   723,    -1,
      -1,   691,    -1,    -1,    -1,   730,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   742,   743,    -1,
      -1,    -1,    -1,    -1,   749,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   876,
      -1,   766,   767,    -1,    -1,   882,    -1,   884,   589,   679,
     887,    -1,    -1,    -1,    -1,    -1,    -1,   687,   748,    -1,
      -1,   751,    -1,    -1,   694,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   712,   713,    -1,   810,   811,    -1,     0,    -1,
      -1,    -1,    -1,   723,    -1,    -1,    -1,   822,   788,    -1,
     730,    13,    14,    15,    16,    17,    18,    -1,    20,    -1,
      -1,    -1,   742,   743,    26,    27,    -1,    -1,    -1,   749,
      -1,    -1,    -1,    -1,    -1,    37,    38,    -1,    40,    41,
      42,    43,    44,    -1,    -1,    -1,   766,   767,   679,    -1,
      -1,    -1,    -1,    -1,    -1,   835,   687,    -1,    -1,    -1,
      -1,   876,   782,   694,    -1,    -1,    -1,   882,    -1,   884,
      -1,    -1,   887,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   712,   713,    -1,    -1,    -1,    88,    -1,    -1,    -1,
     810,   811,   723,    -1,    -1,    -1,    -1,    -1,   818,   730,
      -1,    -1,   822,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   742,   743,    -1,    -1,    -1,    -1,    -1,   749,    -1,
      -1,    -1,    -1,    -1,    51,    52,    -1,    -1,    55,    -1,
      -1,   133,   134,    -1,   136,   766,   767,   139,   140,    -1,
     142,   143,    69,    70,    71,    72,    73,    74,    75,    76,
      77,   782,    -1,    80,    81,    -1,   876,    84,    85,    86,
      87,    -1,   882,    -1,   884,    -1,    -1,   887,    -1,    -1,
      -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   810,
     811,    -1,    -1,    -1,    -1,    -1,    -1,   818,    -1,    -1,
      -1,   822,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,    -1,   130,   131,    -1,    -1,    -1,    -1,    -1,
      -1,   138,   139,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   876,    -1,    -1,    -1,    -1,
      -1,   882,    -1,   884,     0,     1,   887,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    -1,    -1,    -1,
      -1,    -1,    -1,    19,    -1,    21,    22,    23,    24,    -1,
      -1,    -1,    -1,    -1,    30,    31,    32,    33,    34,    35,
      36,    -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    45,
      46,    47,    48,    49,    -1,    51,    52,    53,    54,    55,
      56,    -1,    58,    59,    60,    -1,    -1,    63,    -1,    -1,
      66,    67,    -1,    69,    70,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    89,    -1,    -1,    92,    93,    -1,    95,
      96,     0,    98,    -1,   100,   101,   102,   103,   104,   105,
     106,    -1,    -1,   109,    13,    14,    15,    16,    17,    18,
      -1,    20,    -1,    -1,    44,    -1,    -1,    -1,    27,    28,
      29,    -1,    -1,   129,   130,   131,    -1,    -1,    37,    38,
      -1,    40,    41,    42,    43,    44,   142,   143,    -1,    -1,
      -1,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    -1,    -1,    86,    87,    -1,    -1,
      -1,    -1,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    -1,    -1,    86,    87,    88,
      -1,    90,    91,    -1,    -1,    -1,    -1,   117,    97,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   108,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
      -1,    -1,     0,    -1,    -1,   134,   135,   136,   137,    -1,
      -1,   140,   141,   142,   143,    13,    14,    15,    16,    17,
      18,    -1,    20,    -1,    -1,    44,    -1,    -1,    26,    27,
      28,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,
      38,    -1,    40,    41,    42,    43,    44,    -1,    -1,    -1,
      -1,    -1,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    -1,    -1,    86,    87,    -1,
      -1,    -1,    -1,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    -1,    -1,    86,    87,
      88,    -1,    -1,    91,    -1,    -1,    -1,    -1,   117,    97,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   137,   117,
      -1,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,    -1,    -1,     0,    -1,   133,   134,   135,   136,   137,
      -1,   139,   140,   141,   142,   143,    13,    14,    15,    16,
      17,    18,    -1,    20,    -1,    -1,    44,    -1,    -1,    -1,
      27,    28,    29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      37,    38,    -1,    40,    41,    42,    43,    44,    -1,    -1,
      -1,    -1,    -1,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    -1,    -1,    86,    87,
      -1,    -1,    -1,    -1,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    -1,    -1,    86,
      87,    88,    -1,    -1,    91,    -1,    -1,    -1,    -1,   117,
      97,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   108,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,    -1,    -1,     0,    -1,    -1,   134,   135,   136,
     137,    -1,    -1,   140,   141,   142,   143,    13,    14,    15,
      16,    17,    18,    -1,    20,    -1,    -1,    -1,    -1,    -1,
      26,    27,    28,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    37,    38,    -1,    40,    41,    42,    43,    44,    -1,
      -1,    -1,    -1,    -1,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    -1,    -1,    86,
      87,    -1,    -1,    -1,    -1,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    -1,    -1,
      86,    87,    88,    -1,    -1,    91,    -1,    -1,    -1,    -1,
     117,    97,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   117,    -1,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,    -1,    -1,     0,    -1,   133,   134,   135,
     136,   137,    -1,   139,   140,   141,   142,   143,    13,    14,
      15,    16,    17,    18,    -1,    20,    -1,    -1,    -1,    -1,
      -1,    -1,    27,    28,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    37,    38,    -1,    40,    41,    42,    43,    44,
      -1,    -1,    -1,    -1,    -1,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    -1,    -1,
      86,    87,    -1,    -1,    -1,    -1,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    -1,
      -1,    86,    87,    88,    -1,    -1,    91,    -1,    -1,    -1,
      -1,    -1,    97,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   117,    -1,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,    -1,    -1,     0,    -1,    -1,   134,
     135,   136,   137,    -1,   139,   140,   141,   142,   143,    13,
      14,    15,    -1,    17,    18,    -1,    20,    -1,    -1,    -1,
      -1,    -1,    26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    37,    38,    -1,    40,    41,    42,    43,
      44,    -1,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    -1,    -1,    86,    87,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      -1,    -1,    86,    87,    88,    -1,    90,    -1,   117,    -1,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   116,   117,   143,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,    -1,    -1,     0,    -1,   133,
     134,   135,   136,   137,    -1,    -1,   140,    -1,   142,   143,
      13,    14,    15,    -1,    17,    18,    -1,    20,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    37,    38,    -1,    40,    41,    42,
      43,    44,    71,    72,    73,    74,    75,    76,    77,    78,
      -1,    80,    81,    -1,    -1,    -1,    -1,    86,    87,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    -1,    -1,    86,    87,    88,    -1,    90,    -1,    -1,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   116,   117,    -1,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,    -1,    -1,    -1,    -1,
      -1,   134,   135,   136,   137,    -1,    -1,   140,    -1,   142,
     143,     1,    -1,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    -1,    -1,    18,    19,
      -1,    21,    22,    23,    24,    -1,    -1,    -1,    -1,    -1,
      30,    31,    32,    33,    34,    35,    36,    -1,    -1,    39,
      -1,    -1,    -1,    -1,    -1,    45,    -1,    47,    48,    49,
      -1,    51,    52,    53,    54,    55,    56,    -1,    58,    59,
      60,    -1,    -1,    63,    -1,    -1,    66,    67,    -1,    69,
      70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,
      -1,    -1,    92,    93,    -1,    95,    96,    -1,    98,    -1,
     100,   101,   102,   103,   104,   105,   106,    -1,    -1,   109,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   129,
     130,   131,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   142,   143,     1,    -1,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    -1,    -1,    15,    -1,
      17,    18,    19,    -1,    21,    22,    23,    24,    -1,    -1,
      -1,    -1,    -1,    30,    31,    32,    33,    34,    35,    36,
      -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    45,    -1,
      47,    48,    49,    -1,    51,    52,    53,    54,    55,    56,
      -1,    58,    59,    60,    -1,    -1,    63,    -1,    -1,    66,
      67,    -1,    69,    70,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    89,    -1,    -1,    92,    93,    -1,    95,    96,
      -1,    98,    -1,   100,   101,   102,   103,   104,   105,   106,
      -1,    -1,   109,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   129,   130,   131,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   142,   143,     1,    -1,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    -1,
      -1,    15,    -1,    -1,    18,    19,    20,    21,    22,    23,
      24,    -1,    -1,    -1,    -1,    -1,    30,    31,    32,    33,
      34,    35,    36,    -1,    -1,    39,    -1,    -1,    -1,    -1,
      -1,    45,    -1,    47,    48,    49,    -1,    51,    52,    53,
      54,    55,    56,    -1,    58,    59,    60,    -1,    -1,    63,
      -1,    -1,    66,    67,    -1,    69,    70,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    89,    -1,    -1,    92,    93,
      -1,    95,    96,    -1,    98,    -1,   100,   101,   102,   103,
     104,   105,   106,    -1,    -1,   109,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   129,   130,   131,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   142,   143,
       1,    -1,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    -1,    -1,    15,    -1,    -1,    18,    19,    -1,
      21,    22,    23,    24,    -1,    -1,    -1,    -1,    -1,    30,
      31,    32,    33,    34,    35,    36,    -1,    -1,    39,    -1,
      -1,    -1,    -1,    -1,    45,    -1,    47,    48,    49,    -1,
      51,    52,    53,    54,    55,    56,    -1,    58,    59,    60,
      -1,    -1,    63,    -1,    -1,    66,    67,    -1,    69,    70,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,    -1,
      -1,    92,    93,    -1,    95,    96,    -1,    98,    -1,   100,
     101,   102,   103,   104,   105,   106,    -1,    -1,   109,    -1,
      -1,    -1,    -1,    -1,     1,    -1,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    -1,    -1,   129,   130,
     131,    -1,    19,    -1,    21,    22,    23,    24,    -1,    -1,
      -1,   142,   143,    30,    31,    32,    33,    34,    35,    36,
      -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    45,    46,
      47,    48,    49,    -1,    51,    52,    53,    54,    55,    56,
      -1,    58,    59,    60,    -1,    -1,    63,    -1,    -1,    66,
      67,    -1,    69,    70,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    89,    -1,    -1,    92,    93,    -1,    95,    96,
      -1,    98,    -1,   100,   101,   102,   103,   104,   105,   106,
      -1,    -1,   109,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   129,   130,   131,    -1,    -1,   134,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   142,   143,     1,    -1,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    -1,
      14,    15,    -1,    -1,    -1,    19,    -1,    21,    22,    23,
      24,    -1,    -1,    -1,    -1,    -1,    30,    31,    32,    33,
      34,    35,    36,    -1,    -1,    39,    -1,    -1,    -1,    -1,
      -1,    45,    -1,    47,    48,    49,    -1,    51,    52,    53,
      54,    55,    56,    -1,    58,    59,    60,    -1,    -1,    63,
      -1,    -1,    66,    67,    -1,    69,    70,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    89,    -1,    -1,    92,    93,
      -1,    95,    96,    -1,    98,    -1,   100,   101,   102,   103,
     104,   105,   106,    -1,    -1,   109,    -1,    -1,    -1,    -1,
      -1,     1,    -1,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    -1,    -1,   129,   130,   131,    -1,    19,
      -1,    21,    22,    23,    24,    -1,    -1,    -1,   142,   143,
      30,    31,    32,    33,    34,    35,    36,    -1,    -1,    39,
      -1,    -1,    -1,    -1,    -1,    45,    -1,    47,    48,    49,
      -1,    51,    52,    53,    54,    55,    56,    -1,    58,    59,
      60,    -1,    -1,    63,    -1,    -1,    66,    67,    -1,    69,
      70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,
      -1,    -1,    92,    93,    -1,    95,    96,    -1,    98,    -1,
     100,   101,   102,   103,   104,   105,   106,    -1,    -1,   109,
      -1,    -1,    -1,    -1,    -1,     1,    -1,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    -1,    -1,   129,
     130,   131,    -1,    19,    -1,    21,    22,    23,    24,    -1,
     140,    -1,   142,   143,    30,    31,    32,    33,    34,    35,
      36,    -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    45,
      -1,    47,    48,    49,    -1,    51,    52,    53,    54,    55,
      56,    -1,    58,    59,    60,    -1,    -1,    63,    -1,    -1,
      66,    67,    -1,    69,    70,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    89,    -1,    -1,    92,    93,    -1,    95,
      96,    -1,    98,    -1,   100,   101,   102,   103,   104,   105,
     106,    -1,    -1,   109,    -1,    -1,    -1,    -1,    -1,     1,
      -1,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    -1,    -1,   129,   130,   131,    -1,    19,    -1,    21,
      22,    23,    24,    -1,   140,    -1,   142,   143,    30,    31,
      32,    33,    34,    35,    36,    -1,    -1,    39,    -1,    -1,
      -1,    -1,    -1,    45,    -1,    47,    48,    49,    -1,    51,
      52,    53,    54,    55,    56,    -1,    58,    59,    60,    -1,
      -1,    63,    -1,    -1,    66,    67,    -1,    69,    70,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,    -1,    -1,
      92,    93,    -1,    95,    96,    -1,    98,    -1,   100,   101,
     102,   103,   104,   105,   106,    -1,    -1,   109,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   129,   130,   131,
      -1,    -1,   134,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     142,   143,     1,    -1,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    -1,    -1,    15,    -1,    -1,    -1,
      19,    -1,    21,    22,    23,    24,    -1,    -1,    -1,    -1,
      -1,    30,    31,    32,    33,    34,    35,    36,    -1,    -1,
      39,    -1,    -1,    -1,    -1,    -1,    45,    -1,    47,    48,
      49,    -1,    51,    52,    53,    54,    55,    56,    -1,    58,
      59,    60,    -1,    -1,    63,    -1,    -1,    66,    67,    -1,
      69,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      89,    -1,    -1,    92,    93,    -1,    95,    96,    -1,    98,
      -1,   100,   101,   102,   103,   104,   105,   106,    -1,    -1,
     109,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    -1,    -1,    -1,
     129,   130,   131,    -1,    19,    -1,    21,    22,    23,    24,
      -1,    -1,    -1,   142,   143,    30,    31,    32,    33,    34,
      35,    36,    -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    48,    49,    -1,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    -1,    -1,    63,    -1,
      -1,    66,    67,    -1,    69,    70,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    89,    -1,    -1,    92,    93,    -1,
      95,    96,    -1,    98,    99,   100,   101,   102,   103,   104,
     105,   106,    -1,    -1,   109,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    -1,    -1,    -1,   129,   130,   131,    -1,    19,    -1,
      21,    22,    23,    24,    -1,    -1,    -1,    -1,   143,    30,
      31,    32,    33,    34,    35,    36,    -1,    -1,    39,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,    49,    -1,
      51,    52,    53,    54,    55,    56,    -1,    58,    59,    60,
      -1,    -1,    63,    -1,    -1,    66,    67,    -1,    69,    70,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,    -1,
      -1,    92,    93,    -1,    95,    96,    -1,    -1,    -1,   100,
     101,   102,   103,   104,   105,   106,    -1,    -1,   109,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    -1,    -1,    -1,   129,   130,
     131,    -1,    19,    -1,    21,    22,    23,    24,    -1,    -1,
      -1,   142,   143,    30,    31,    32,    33,    34,    35,    36,
      -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    48,    49,    -1,    51,    52,    53,    54,    55,    56,
      -1,    58,    59,    60,    -1,    -1,    63,    -1,    -1,    66,
      67,    -1,    69,    70,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    89,    -1,    -1,    92,    93,    -1,    95,    96,
      -1,    -1,    -1,   100,   101,   102,   103,   104,   105,   106,
      -1,    -1,   109,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      -1,    -1,   129,   130,   131,    -1,    19,    -1,    21,    22,
      23,    24,    -1,    -1,    -1,    -1,   143,    30,    31,    32,
      33,    34,    35,    36,    -1,    -1,    39,    -1,    -1,    -1,
      -1,    -1,    45,    46,    47,    48,    49,    -1,    51,    52,
      53,    54,    55,    56,    -1,    58,    59,    60,    -1,    -1,
      63,    -1,    -1,    66,    67,    -1,    69,    70,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    89,    -1,    -1,    92,
      93,    -1,    95,    96,    -1,    98,    -1,   100,   101,   102,
     103,   104,   105,   106,    -1,    -1,   109,    -1,    -1,    -1,
      -1,    -1,    -1,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    -1,    -1,    -1,   129,   130,   131,    19,
      -1,    21,    22,    23,    24,    -1,    -1,    -1,    -1,   142,
      30,    31,    32,    33,    34,    35,    36,    -1,    -1,    39,
      -1,    -1,    -1,    -1,    -1,    45,    -1,    47,    48,    49,
      -1,    51,    52,    53,    54,    55,    56,    -1,    58,    59,
      60,    -1,    -1,    63,    -1,    -1,    66,    67,    -1,    69,
      70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,
      -1,    -1,    92,    93,    -1,    95,    96,    -1,    98,    -1,
     100,   101,   102,   103,   104,   105,   106,    -1,    -1,   109,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   129,
     130,   131,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   142,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    -1,    -1,    -1,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      -1,    -1,    -1,    -1,    -1,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
      80,    81,    -1,    -1,    84,    85,    86,    87,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    98,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,    -1,
     130,   131,    -1,    -1,    -1,    -1,    -1,    -1,   138,   139,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    19,    -1,    21,    22,
      23,    24,    -1,    26,    -1,    -1,    -1,    30,    31,    32,
      33,    34,    35,    36,    -1,    -1,    39,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    48,    49,    -1,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    -1,    -1,
      63,    -1,    -1,    66,    67,    -1,    69,    70,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    89,    -1,    -1,    92,
      93,    -1,    95,    96,    -1,    98,    99,   100,   101,   102,
     103,   104,   105,   106,    -1,    -1,   109,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   129,   130,   131,    -1,
     133,    -1,    -1,    -1,    -1,    -1,   139,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    19,    -1,    21,    22,    23,    24,    -1,
      26,    -1,    -1,    -1,    30,    31,    32,    33,    34,    35,
      36,    -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    48,    49,    -1,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    -1,    -1,    63,    -1,    -1,
      66,    67,    -1,    69,    70,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    89,    -1,    -1,    92,    93,    -1,    95,
      96,    -1,    98,    99,   100,   101,   102,   103,   104,   105,
     106,    -1,    -1,   109,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    -1,
      -1,    -1,    -1,   129,   130,   131,    19,   133,    21,    22,
      23,    24,    -1,   139,    -1,    -1,    -1,    30,    31,    32,
      33,    34,    35,    36,    -1,    -1,    39,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    48,    49,    -1,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    -1,    -1,
      63,    -1,    -1,    66,    67,    -1,    69,    70,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    89,    90,    -1,    92,
      93,    -1,    95,    96,    -1,    98,    99,   100,   101,   102,
     103,   104,   105,   106,    -1,    -1,   109,    -1,    -1,    -1,
      -1,    -1,    -1,   116,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    -1,    -1,    -1,   129,   130,   131,    -1,
      19,    -1,    21,    22,    23,    24,   139,    -1,    -1,    -1,
      -1,    30,    31,    32,    33,    34,    35,    36,    -1,    -1,
      39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,
      49,    -1,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    -1,    -1,    63,    -1,    -1,    66,    67,    -1,
      69,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      89,    -1,    -1,    92,    93,    -1,    95,    96,    -1,    98,
      99,   100,   101,   102,   103,   104,   105,   106,    -1,    -1,
     109,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,
     129,   130,   131,    19,    -1,    21,    22,    23,    24,    -1,
     139,    -1,    -1,    -1,    30,    31,    32,    33,    34,    35,
      36,    -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    48,    49,    -1,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    -1,    -1,    63,    -1,    -1,
      66,    67,    -1,    69,    70,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    89,    -1,    -1,    92,    93,    -1,    95,
      96,    -1,    98,    99,   100,   101,   102,   103,   104,   105,
     106,    -1,    -1,   109,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   129,   130,   131,    -1,    -1,    -1,    -1,
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
      -1,    -1,    -1,    -1,    -1,    -1,   105,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
      -1,   130,   131,    -1,    -1,    -1,    -1,    -1,    -1,   138,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    -1,    -1,    -1,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    -1,    -1,    -1,
      -1,    -1,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    -1,    -1,    -1,    -1,    -1,    -1,
      63,    -1,    -1,    -1,    -1,    -1,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,    80,    81,    -1,
      -1,    84,    85,    86,    87,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    98,    -1,    -1,    -1,    -1,
      -1,    -1,   105,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,    -1,   130,   131,    -1,
      -1,    -1,    -1,    -1,    -1,   138,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      -1,    -1,    -1,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    -1,    -1,    -1,    -1,    -1,    45,    46,
      47,    48,    49,    50,    51,    52,    -1,    -1,    55,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,    -1,    80,    81,    -1,    -1,    84,    85,    86,
      87,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    98,    -1,    -1,   101,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,    -1,   130,   131,    -1,    -1,    -1,    -1,    -1,
      -1,   138,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    -1,    -1,    -1,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    -1,
      -1,    -1,    -1,    -1,    45,    46,    47,    48,    49,    50,
      51,    52,    -1,    -1,    55,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,    80,
      81,    -1,    -1,    84,    85,    86,    87,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    98,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,    -1,   130,
     131,    -1,    -1,    -1,    -1,    -1,    -1,   138,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    19,    -1,    21,    22,    23,    24,
      -1,    -1,    -1,    -1,    -1,    30,    31,    32,    33,    34,
      35,    36,    -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    48,    49,    -1,    51,    52,    53,    54,
      55,    56,    -1,    58,    59,    60,    -1,    -1,    63,    -1,
      -1,    66,    67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    89,    -1,    -1,    92,    93,    -1,
      95,    96,    -1,    -1,    -1,   100,   101,   102,   103,   104,
     105,   106,    -1,    -1,   109,    -1,    -1,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    19,   129,    21,    22,    23,    24,    -1,
      -1,    -1,   137,    -1,    30,    31,    32,    33,    34,    35,
      36,    -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    48,    49,    -1,    51,    52,    53,    54,    55,
      56,    -1,    58,    59,    60,    -1,    -1,    63,    -1,    -1,
      66,    67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    89,    -1,    -1,    92,    93,    -1,    95,
      96,    -1,    -1,    -1,   100,   101,   102,   103,   104,   105,
     106,    -1,    -1,   109,    -1,    -1,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    19,   129,    21,    22,    23,    24,    -1,    -1,
      -1,   137,    -1,    30,    31,    32,    33,    34,    35,    36,
      -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    48,    49,    -1,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    -1,    -1,    63,    -1,    -1,    66,
      67,    -1,    69,    70,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    89,    -1,    -1,    92,    93,    -1,    95,    96,
      -1,    98,    99,   100,   101,   102,   103,   104,   105,   106,
      -1,    -1,   109,   110,    -1,    -1,   113,   114,    -1,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    -1,
      -1,    -1,   129,   130,   131,    19,    -1,    21,    22,    23,
      24,    -1,    -1,    -1,    -1,    -1,    30,    31,    32,    33,
      34,    35,    36,    -1,    -1,    39,    -1,    -1,    -1,    -1,
      -1,    45,    46,    47,    48,    49,    -1,    51,    52,    53,
      54,    55,    56,    -1,    58,    59,    60,    -1,    -1,    63,
      -1,    -1,    66,    67,    -1,    69,    70,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    89,    -1,    -1,    92,    93,
      -1,    95,    96,    -1,    98,    -1,   100,   101,   102,   103,
     104,   105,   106,    -1,    -1,   109,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    -1,    -1,    -1,    -1,   129,   130,   131,    19,    -1,
      21,    22,    23,    24,    -1,    -1,    -1,    -1,    -1,    30,
      31,    32,    33,    34,    35,    36,    -1,    -1,    39,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,    49,    -1,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      -1,    -1,    63,    -1,    -1,    66,    67,    -1,    69,    70,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,    -1,
      -1,    92,    93,    -1,    95,    96,    -1,    98,    -1,   100,
     101,   102,   103,   104,   105,   106,    -1,    -1,   109,   110,
      -1,    -1,   113,   114,    -1,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    -1,    -1,    -1,   129,   130,
     131,    19,    -1,    21,    22,    23,    24,    -1,    -1,    -1,
      -1,    -1,    30,    31,    32,    33,    34,    35,    36,    -1,
      -1,    39,    -1,    -1,    -1,    -1,    -1,    45,    -1,    47,
      48,    49,    -1,    51,    52,    53,    54,    55,    56,    -1,
      58,    59,    60,    -1,    -1,    63,    -1,    -1,    66,    67,
      -1,    69,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    89,    -1,    -1,    92,    93,    -1,    95,    96,    -1,
      98,    -1,   100,   101,   102,   103,   104,   105,   106,    -1,
      -1,   109,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    -1,    -1,    -1,
      -1,   129,   130,   131,    19,    -1,    21,    22,    23,    24,
      -1,    -1,    -1,    -1,    -1,    30,    31,    32,    33,    34,
      35,    36,    -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    48,    49,    -1,    51,    52,    53,    54,
      55,    56,    -1,    58,    59,    60,    -1,    -1,    63,    -1,
      -1,    66,    67,    -1,    69,    70,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    89,    -1,    -1,    92,    93,    -1,
      95,    96,    -1,    98,    -1,   100,   101,   102,   103,   104,
     105,   106,    -1,    -1,   109,   110,    -1,    -1,   113,   114,
      -1,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      -1,    -1,    -1,    -1,   129,   130,   131,    19,    -1,    21,
      22,    23,    24,    -1,    -1,    -1,    -1,    -1,    30,    31,
      32,    33,    34,    35,    36,    -1,    -1,    39,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    48,    49,    -1,    51,
      52,    53,    54,    55,    56,    -1,    58,    59,    60,    -1,
      -1,    63,    -1,    -1,    66,    67,    -1,    69,    70,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,    -1,    -1,
      92,    93,    -1,    95,    96,    -1,    98,    -1,   100,   101,
     102,   103,   104,   105,   106,    -1,    -1,   109,   110,    -1,
      -1,   113,   114,    -1,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    -1,    -1,    -1,    -1,   129,   130,   131,
      19,    -1,    21,    22,    23,    24,    -1,    -1,    -1,    -1,
      -1,    30,    31,    32,    33,    34,    35,    36,    -1,    -1,
      39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,
      49,    -1,    51,    52,    53,    54,    55,    56,    -1,    58,
      59,    60,    -1,    -1,    63,    -1,    -1,    66,    67,    -1,
      69,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      89,    -1,    -1,    92,    93,    -1,    95,    96,    -1,    98,
      -1,   100,   101,   102,   103,   104,   105,   106,    -1,    -1,
     109,   110,    -1,    -1,   113,   114,    -1,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,
     129,   130,   131,    19,    -1,    21,    22,    23,    24,    -1,
      -1,    -1,    -1,    -1,    30,    31,    32,    33,    34,    35,
      36,    -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    48,    49,    -1,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    -1,    -1,    63,    -1,    -1,
      66,    67,    -1,    69,    70,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    89,    -1,    -1,    92,    93,    -1,    95,
      96,    -1,    98,    99,   100,   101,   102,   103,   104,   105,
     106,    -1,    -1,   109,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    -1,
      -1,    -1,    -1,   129,   130,   131,    19,    -1,    21,    22,
      23,    24,    -1,    -1,    -1,    -1,    -1,    30,    31,    32,
      33,    34,    35,    36,    -1,    -1,    39,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    48,    49,    -1,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    -1,    -1,
      63,    -1,    -1,    66,    67,    -1,    69,    70,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    89,    -1,    -1,    92,
      93,    -1,    95,    96,    -1,    98,    -1,   100,   101,   102,
     103,   104,   105,   106,    -1,    -1,   109,    -1,    -1,    -1,
      -1,    -1,    -1,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    -1,    -1,    -1,    -1,   129,   130,   131,    19,
      -1,    21,    22,    23,    24,    -1,    -1,    -1,    -1,    -1,
      30,    31,    32,    33,    34,    35,    36,    -1,    -1,    39,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,    49,
      -1,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    -1,    -1,    63,    -1,    -1,    66,    67,    -1,    69,
      70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,
      -1,    -1,    92,    93,    -1,    95,    96,    -1,    -1,    99,
     100,   101,   102,   103,   104,   105,   106,    -1,    -1,   109,
      -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,   129,
     130,   131,    19,    -1,    21,    22,    23,    24,    -1,    -1,
      -1,    -1,    -1,    30,    31,    32,    33,    34,    35,    36,
      -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    48,    49,    -1,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    -1,    -1,    63,    -1,    -1,    66,
      67,    -1,    69,    70,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    89,    -1,    -1,    92,    93,    -1,    95,    96,
      -1,    -1,    -1,   100,   101,   102,   103,   104,   105,   106,
      -1,    -1,   109,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    -1,    -1,
      -1,    -1,   129,   130,   131,    19,    -1,    21,    22,    23,
      24,    -1,    -1,    -1,    -1,    -1,    30,    31,    32,    33,
      34,    35,    36,    -1,    -1,    39,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    48,    49,    -1,    51,    52,    53,
      54,    55,    56,    -1,    58,    59,    60,    -1,    -1,    63,
      -1,    -1,    66,    67,    -1,    69,    70,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    89,    -1,    -1,    92,    93,
      -1,    95,    96,    -1,    98,    -1,   100,   101,   102,   103,
     104,   105,   106,    -1,    -1,   109,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    -1,    -1,    -1,    -1,   129,   130,   131,    19,    -1,
      21,    22,    23,    24,    -1,    -1,    -1,    -1,    -1,    30,
      31,    32,    33,    34,    35,    36,    -1,    -1,    39,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,    49,    -1,
      51,    52,    53,    54,    55,    56,    -1,    58,    59,    60,
      -1,    -1,    63,    -1,    -1,    66,    67,    -1,    69,    70,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,    -1,
      -1,    92,    93,    -1,    95,    96,    -1,    98,    -1,   100,
     101,   102,   103,   104,   105,   106,    -1,    -1,   109,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    -1,    -1,    -1,    -1,   129,   130,
     131,    19,    -1,    21,    22,    23,    24,    -1,    -1,    -1,
      -1,    -1,    30,    31,    32,    33,    34,    35,    36,    -1,
      -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      48,    49,    -1,    51,    52,    53,    54,    55,    56,    -1,
      58,    59,    60,    -1,    -1,    63,    -1,    -1,    66,    67,
      -1,    69,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    89,    -1,    -1,    92,    93,    -1,    95,    96,    -1,
      98,    -1,   100,   101,   102,   103,   104,   105,   106,    -1,
      -1,   109,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    -1,    -1,    -1,
      -1,   129,   130,   131,    19,    -1,    21,    22,    23,    24,
      -1,    -1,    -1,    -1,    -1,    30,    31,    32,    33,    34,
      35,    36,    -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    48,    49,    -1,    51,    52,    53,    54,
      55,    56,    -1,    58,    59,    60,    -1,    -1,    63,    -1,
      -1,    66,    67,    -1,    69,    70,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    89,    -1,    -1,    92,    93,    -1,
      95,    96,    -1,    -1,    -1,   100,   101,   102,   103,   104,
     105,   106,    -1,    -1,   109,    -1,    -1,    -1,    -1,    -1,
      -1,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      -1,    -1,    -1,    -1,   129,   130,   131,    19,    -1,    21,
      22,    23,    24,    -1,    -1,    -1,    -1,    -1,    30,    31,
      32,    33,    34,    35,    36,    -1,    -1,    39,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    48,    49,    -1,    51,
      52,    53,    54,    55,    56,    -1,    58,    59,    60,    -1,
      -1,    63,    -1,    -1,    66,    67,    -1,    69,    70,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,    -1,    -1,
      92,    93,    -1,    95,    96,    -1,    -1,    -1,   100,   101,
     102,   103,   104,   105,   106,    -1,    -1,   109,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    -1,    -1,    -1,    -1,   129,   130,   131,
      19,    -1,    21,    22,    23,    24,    -1,    -1,    -1,    -1,
      -1,    30,    31,    32,    33,    34,    35,    36,    -1,    -1,
      39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,
      49,    -1,    51,    52,    53,    54,    55,    56,    -1,    58,
      59,    60,    -1,    -1,    63,    -1,    -1,    66,    67,    -1,
      69,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      89,    -1,    -1,    92,    93,    -1,    95,    96,    -1,    -1,
      -1,   100,   101,   102,   103,   104,   105,   106,    -1,    -1,
     109,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,
     129,   130,   131,    19,    -1,    21,    22,    23,    24,    -1,
      -1,    -1,    -1,    -1,    30,    31,    32,    33,    34,    35,
      36,    -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    48,    49,    -1,    51,    52,    53,    54,    55,
      56,    -1,    58,    59,    60,    -1,    -1,    63,    -1,    -1,
      66,    67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      86,    -1,    -1,    89,    -1,    -1,    92,    93,    -1,    95,
      96,    -1,    -1,    -1,   100,   101,   102,   103,   104,   105,
     106,    -1,    -1,   109,    -1,    -1,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    19,   129,    21,    22,    23,    24,    -1,    -1,
      -1,    -1,    -1,    30,    31,    32,    33,    34,    35,    36,
      -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    48,    49,    -1,    51,    52,    53,    54,    55,    56,
      -1,    58,    59,    60,    -1,    -1,    63,    -1,    -1,    66,
      67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    89,    -1,    -1,    92,    93,    -1,    95,    96,
      -1,    98,    -1,   100,   101,   102,   103,   104,   105,   106,
      -1,    -1,   109,    -1,    -1,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    19,   129,    21,    22,    23,    24,    -1,    -1,    -1,
      -1,    -1,    30,    31,    32,    33,    34,    35,    36,    -1,
      -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      48,    49,    -1,    51,    52,    53,    54,    55,    56,    -1,
      58,    59,    60,    -1,    -1,    63,    -1,    -1,    66,    67,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    89,    -1,    -1,    92,    93,    -1,    95,    96,    -1,
      98,    -1,   100,   101,   102,   103,   104,   105,   106,    -1,
      -1,   109,    -1,    -1,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      19,   129,    21,    22,    23,    24,    -1,    -1,    -1,    -1,
      -1,    30,    31,    32,    33,    34,    35,    36,    -1,    -1,
      39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,
      49,    -1,    51,    52,    53,    54,    55,    56,    -1,    58,
      59,    60,    -1,    -1,    63,    -1,    -1,    66,    67,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      89,    -1,    -1,    92,    93,    -1,    95,    96,    -1,    -1,
      -1,   100,   101,   102,   103,   104,   105,   106,    -1,    -1,
     109,    -1,    -1,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    19,
     129,    21,    22,    23,    24,    -1,    -1,    -1,    -1,    -1,
      30,    31,    32,    33,    34,    35,    36,    -1,    -1,    39,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,    49,
      -1,    51,    52,    53,    54,    55,    56,    -1,    58,    59,
      60,    -1,    -1,    63,    -1,    -1,    66,    67,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,
      -1,    -1,    92,    93,    -1,    95,    96,    -1,    -1,    -1,
     100,   101,   102,   103,   104,   105,   106,    -1,    -1,   109,
      -1,    -1,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    19,   129,
      21,    22,    23,    24,    -1,    -1,    -1,    -1,    -1,    30,
      31,    32,    33,    34,    35,    36,    -1,    -1,    39,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,    49,    -1,
      51,    52,    53,    54,    55,    56,    -1,    58,    59,    60,
      -1,    -1,    63,    -1,    -1,    66,    67,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,    -1,
      -1,    92,    93,    -1,    95,    96,    -1,    -1,    -1,   100,
     101,   102,   103,   104,   105,   106,    -1,    -1,   109,    -1,
      -1,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    19,   129,    21,
      22,    23,    24,    -1,    -1,    -1,    -1,    -1,    30,    31,
      32,    33,    34,    35,    36,    -1,    -1,    39,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    48,    49,    -1,    51,
      52,    53,    54,    55,    56,    -1,    58,    59,    60,    -1,
      -1,    63,    -1,    -1,    66,    67,    -1,    71,    72,    73,
      74,    75,    76,    77,    -1,    -1,    80,    81,    -1,    -1,
      -1,    -1,    86,    87,    -1,    -1,    -1,    89,    -1,    -1,
      92,    93,    -1,    95,    96,    -1,    -1,    -1,   100,   101,
     102,   103,   104,   105,   106,    -1,    -1,   109,    -1,    -1,
      51,    52,    -1,    -1,    55,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,    -1,    -1,   129,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,    80,
      81,    -1,    -1,    84,    85,    86,    87,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    98,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,    -1,   130,
     131,    51,    52,    -1,    -1,    55,    -1,   138,   139,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
      80,    81,    -1,    -1,    84,    85,    86,    87,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    98,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,    -1,
     130,   131,    51,    52,    -1,    -1,    55,    -1,   138,   139,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    80,    81,    -1,    -1,    84,    85,    86,    87,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    98,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
      -1,   130,   131,    51,    52,    -1,    -1,    55,    -1,   138,
     139,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    -1,    80,    81,    -1,    -1,    84,    85,    86,    87,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      98,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,    -1,   130,   131,    51,    52,    -1,    -1,    55,    -1,
     138,   139,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,    -1,    80,    81,    -1,    -1,    84,    85,    86,
      87,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,    -1,   130,   131,    51,    52,    -1,    -1,    55,
      -1,   138,   139,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    -1,    80,    81,    -1,    -1,    84,    85,
      86,    87,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,    -1,   130,   131,    51,    52,    -1,    -1,
      55,    -1,   138,   139,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    -1,    80,    81,    -1,    -1,    84,
      85,    86,    87,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,    -1,   130,   131,    51,    52,    -1,
      -1,    55,    -1,   138,   139,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    -1,    80,    81,    -1,    -1,
      84,    85,    86,    87,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    98,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,    -1,   130,   131,    51,    52,
      -1,    -1,    55,    -1,   138,   139,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,    80,    81,    -1,
      -1,    84,    85,    86,    87,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    98,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,    -1,   130,   131,    51,
      52,    -1,    -1,    55,    -1,   138,   139,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,    80,    81,
      -1,    -1,    84,    85,    86,    87,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    98,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,    -1,   130,   131,
      51,    52,    -1,    -1,    55,    -1,   138,   139,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,    80,
      81,    -1,    -1,    84,    85,    86,    87,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    98,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,    -1,   130,
     131,    51,    52,    -1,    -1,    55,    -1,   138,   139,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
      80,    81,    -1,    -1,    84,    85,    86,    87,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    98,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,    -1,
     130,   131,    51,    52,    -1,    -1,    55,    -1,   138,   139,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    80,    81,    -1,    -1,    84,    85,    86,    87,    -1,
      -1,    -1,    71,    72,    73,    74,    75,    76,    77,    98,
      -1,    80,    81,    -1,    -1,    -1,    -1,    86,    87,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
      -1,   130,   131,    -1,    -1,    -1,    -1,    -1,    -1,   138,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   145,   146,     0,     1,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    19,    21,    22,    23,    24,
      30,    31,    32,    33,    34,    35,    36,    39,    45,    46,
      47,    48,    49,    51,    52,    53,    54,    55,    56,    58,
      59,    60,    63,    66,    67,    69,    70,    89,    92,    93,
      95,    96,    98,   100,   101,   102,   103,   104,   105,   106,
     109,   129,   130,   131,   147,   148,   149,   154,   156,   157,
     159,   160,   163,   164,   166,   167,   168,   170,   171,   180,
     193,   214,   233,   234,   244,   245,   249,   250,   251,   258,
     259,   260,   262,   263,   264,   265,   266,   267,   291,   304,
     149,    21,    22,    30,    31,    32,    39,    51,    55,    86,
      89,    92,   129,   172,   173,   193,   214,   264,   267,   291,
     173,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    45,    46,    47,    48,    49,
      50,    51,    52,    55,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    80,    81,    84,    85,    86,    87,    98,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     130,   131,   138,   139,   174,   178,   179,   266,   286,   194,
      89,   157,   158,   171,   214,   264,   265,   267,   158,   200,
     202,    89,   164,   171,   214,   219,   264,   267,    33,    34,
      35,    36,    48,    49,    51,    55,   101,   174,   175,   176,
     260,   142,   143,   158,   295,   300,   301,   303,    57,    98,
      99,   130,   163,   180,   181,   186,   189,   191,   289,   290,
     186,   186,   139,   187,   188,   139,   183,   187,   139,   296,
     301,   175,   150,   133,   180,   214,   180,    55,     1,    92,
     152,   153,   154,   165,   166,   304,   195,   197,   182,   191,
     289,   304,   181,   288,   289,   304,    89,   137,   170,   214,
     264,   267,   198,    53,    54,    56,    63,   105,   174,   261,
      62,    64,    65,   111,   112,   246,   247,    63,   246,    63,
     246,    63,   246,    61,   246,    58,    59,   159,   180,   180,
     295,   303,    40,    41,    42,    43,    44,    37,    38,    28,
     231,   116,   137,    92,    98,   167,   116,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      86,    87,   117,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,    88,   135,   136,    88,   136,   294,    26,
     133,   235,    90,    90,   183,   187,   235,   157,    51,    55,
     172,    58,    59,   120,   268,    88,   135,   136,   209,   287,
     210,   294,   151,   152,    55,    16,   215,   300,   116,    88,
     135,   136,    90,    90,   215,   158,   158,    55,    88,   135,
     136,    25,   105,   137,   302,   295,    20,   238,   142,   181,
     181,   181,    91,   137,   190,   304,   137,   190,   186,   296,
     297,   186,   185,   186,   191,   289,   304,   157,   297,   157,
     155,   133,   152,    88,   136,    90,   154,   165,   140,   295,
     303,   297,   157,   297,   141,   137,   299,   301,   137,   299,
     134,   299,    55,   167,   168,   169,   137,    88,   135,   136,
      51,    53,    54,    55,    56,    92,    98,    99,   123,   126,
     139,   229,   271,   272,   273,   274,   275,   276,   277,   280,
     281,   282,   283,   284,    63,   247,   248,   110,   113,   114,
     253,   254,   255,   256,    62,   247,    63,    63,    63,    61,
      71,    71,   149,   158,   158,   158,   158,   154,   157,   157,
     232,    98,   159,   181,   191,   192,   165,   137,   170,   137,
     156,   159,   171,   180,   181,   192,   180,   180,   180,   180,
     180,   180,   180,   180,   180,   180,   180,   180,   180,   180,
     180,   180,   180,   180,   180,   180,   180,   180,   180,   180,
     180,   180,    51,    52,    55,   178,   183,   292,   293,   185,
      51,    52,    55,   178,   183,   292,    51,    55,   292,   237,
     236,   159,   180,   159,   180,    97,   161,   207,   269,   206,
      51,    55,   172,   292,   185,   292,   151,   157,   211,   212,
      15,    13,   240,   304,   152,    16,   180,    51,    55,   185,
      51,    55,   152,    27,   216,   300,   216,    51,    55,   185,
      51,    55,   204,   177,   252,   253,   238,   191,    15,   181,
      98,   181,   189,   253,   289,   290,   297,   140,   297,   137,
     137,   297,   175,   147,   134,   180,   297,   154,   196,   289,
     167,   169,    51,    55,   185,    51,    55,   116,    51,    92,
      98,   220,   221,   222,   273,   271,   199,   137,   285,   304,
     181,   137,   285,    51,   137,   285,    51,    63,   152,   257,
     254,   110,   256,   180,   180,    79,   121,   224,   225,   304,
     181,   137,   297,   169,   137,   116,    44,   296,    90,    90,
     183,   187,   296,   298,    90,    90,   183,   184,   187,   304,
     184,   187,   224,   224,    44,   162,   300,   158,   151,   298,
      15,   297,   139,   270,   271,   174,   181,   192,   241,   304,
      18,   218,   304,    17,   217,   218,    90,    90,   298,    90,
      90,   218,   201,   203,   298,   158,   175,    15,   137,   215,
     181,    98,   181,   190,   289,   134,   297,   299,   298,   222,
     137,   273,   137,   297,   226,   296,    29,   108,   230,   274,
     280,   282,   284,   275,   277,   282,   275,   134,   152,   223,
     226,   275,   276,   278,   279,   282,   284,   152,    98,   181,
     169,   180,   118,   159,   180,   159,   180,   161,   141,    90,
     159,   180,   159,   180,   161,   235,   231,   152,   152,   180,
     224,   208,   300,    15,   271,   151,   300,   213,    91,   242,
     304,   152,    14,   243,   304,   158,    15,    90,    15,   152,
     152,   216,   181,   152,   181,   137,   297,   221,   137,    98,
     220,   140,   142,   152,   152,   137,   285,   137,   285,   137,
     285,   137,   285,   285,   134,   226,   121,   137,   285,    89,
     214,   137,   285,   137,   285,    15,   181,   180,   159,   180,
      15,   134,   152,   151,   297,    15,   270,    89,   171,   214,
     264,   267,   215,   152,   215,    15,    15,   205,   218,   238,
     239,   137,   221,   137,   273,    51,   227,   228,   272,    15,
     134,   275,   282,   275,   275,   121,   279,   282,    55,    88,
     275,   278,   282,   275,   134,    15,   151,    55,    88,   135,
     136,   152,   152,   152,   221,   137,   137,   296,   285,   137,
     285,   285,   285,   137,   285,   137,   285,    51,    55,   285,
     137,   285,   285,    15,    51,    55,   185,    51,    55,   240,
     217,    15,   221,   228,   275,   275,   282,   275,   275,   298,
     285,   285,   137,   285,   285,   285,   275,   285
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   144,   146,   145,   147,   148,   148,   148,   148,   149,
     150,   149,   151,   152,   153,   153,   153,   153,   155,   154,
     154,   154,   154,   154,   154,   154,   154,   154,   154,   154,
     154,   154,   154,   154,   154,   154,   154,   154,   154,   154,
     156,   156,   157,   157,   157,   157,   157,   157,   158,   159,
     159,   160,   160,   162,   161,   163,   163,   163,   163,   163,
     163,   163,   163,   163,   163,   163,   164,   164,   165,   165,
     166,   166,   166,   166,   166,   166,   166,   166,   166,   166,
     167,   167,   168,   168,   169,   169,   170,   170,   170,   170,
     170,   170,   170,   170,   171,   171,   171,   171,   171,   171,
     171,   171,   172,   172,   173,   173,   173,   174,   174,   174,
     174,   174,   175,   175,   176,   177,   176,   178,   178,   178,
     178,   178,   178,   178,   178,   178,   178,   178,   178,   178,
     178,   178,   178,   178,   178,   178,   178,   178,   178,   178,
     178,   178,   178,   178,   178,   178,   179,   179,   179,   179,
     179,   179,   179,   179,   179,   179,   179,   179,   179,   179,
     179,   179,   179,   179,   179,   179,   179,   179,   179,   179,
     179,   179,   179,   179,   179,   179,   179,   179,   179,   179,
     179,   179,   179,   179,   179,   179,   180,   180,   180,   180,
     180,   180,   180,   180,   180,   180,   180,   180,   180,   180,
     180,   180,   180,   180,   180,   180,   180,   180,   180,   180,
     180,   180,   180,   180,   180,   180,   180,   180,   180,   180,
     180,   180,   180,   180,   180,   180,   180,   180,   180,   180,
     181,   182,   182,   182,   182,   183,   184,   184,   185,   185,
     185,   185,   185,   186,   186,   186,   186,   186,   188,   187,
     189,   190,   190,   191,   191,   191,   191,   191,   191,   192,
     192,   192,   193,   193,   193,   193,   193,   193,   193,   193,
     194,   193,   195,   196,   193,   197,   193,   193,   193,   193,
     193,   193,   193,   193,   193,   193,   193,   193,   193,   193,
     193,   198,   199,   193,   193,   193,   200,   201,   193,   202,
     203,   193,   193,   193,   204,   205,   193,   206,   193,   207,
     208,   193,   209,   193,   210,   211,   193,   212,   213,   193,
     193,   193,   193,   193,   214,   215,   215,   215,   216,   216,
     217,   217,   218,   218,   219,   219,   220,   220,   221,   221,
     222,   222,   222,   222,   222,   222,   222,   222,   222,   223,
     223,   223,   223,   223,   223,   223,   223,   223,   223,   223,
     223,   223,   223,   223,   224,   224,   225,   225,   225,   226,
     226,   227,   227,   228,   228,   229,   229,   230,   230,   232,
     231,   233,   233,   233,   233,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   236,   235,   237,   235,   238,   239,
     239,   240,   240,   241,   241,   241,   242,   242,   243,   243,
     244,   244,   244,   244,   245,   245,   245,   245,   246,   246,
     247,   248,   247,   247,   247,   249,   249,   250,   250,   251,
     252,   252,   253,   253,   254,   254,   255,   255,   256,   257,
     256,   258,   258,   259,   259,   260,   261,   261,   261,   261,
     261,   261,   262,   262,   263,   263,   263,   263,   264,   264,
     264,   264,   264,   265,   266,   266,   266,   266,   266,   266,
     266,   267,   267,   268,   269,   268,   270,   270,   271,   271,
     271,   271,   271,   271,   271,   271,   271,   271,   271,   271,
     271,   271,   271,   272,   272,   272,   272,   273,   273,   274,
     274,   275,   275,   276,   277,   278,   279,   279,   280,   280,
     281,   281,   282,   282,   283,   283,   284,   285,   285,   286,
     287,   286,   288,   288,   289,   289,   290,   290,   291,   291,
     291,   292,   292,   292,   292,   293,   293,   293,   294,   294,
     295,   295,   296,   296,   297,   298,   299,   299,   299,   300,
     300,   302,   301,   303,   303,   304
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     2,     1,     1,     3,     2,     1,
       0,     5,     4,     2,     1,     1,     3,     2,     0,     4,
       2,     3,     3,     3,     3,     3,     4,     1,     3,     3,
       6,     5,     5,     5,     5,     3,     3,     3,     3,     1,
       3,     3,     1,     3,     3,     3,     2,     1,     1,     1,
       1,     1,     4,     0,     5,     2,     3,     4,     5,     4,
       5,     2,     2,     2,     2,     2,     1,     3,     1,     3,
       1,     2,     3,     5,     2,     4,     2,     4,     1,     3,
       1,     3,     2,     3,     1,     2,     1,     4,     3,     3,
       3,     3,     2,     1,     1,     4,     3,     3,     3,     3,
       2,     1,     1,     1,     2,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     0,     4,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     5,     3,     5,
       6,     5,     5,     5,     5,     4,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     4,     4,     2,     2,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     2,     3,     3,     3,     3,     6,     1,
       1,     1,     2,     4,     2,     3,     1,     1,     1,     1,
       2,     4,     2,     1,     2,     2,     4,     1,     0,     2,
       2,     2,     1,     1,     2,     3,     4,     4,     5,     3,
       4,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     4,     0,     0,     5,     0,     3,     3,     3,     2,
       3,     3,     1,     4,     3,     1,     4,     3,     2,     1,
       2,     0,     0,     5,     6,     6,     0,     0,     7,     0,
       0,     7,     5,     4,     0,     0,     9,     0,     6,     0,
       0,     8,     0,     5,     0,     0,     7,     0,     0,     9,
       1,     1,     1,     1,     1,     1,     1,     2,     1,     1,
       1,     5,     1,     2,     1,     1,     1,     3,     1,     3,
       1,     4,     6,     3,     5,     2,     4,     1,     3,     6,
       8,     4,     6,     4,     2,     6,     2,     4,     6,     2,
       4,     2,     4,     1,     1,     1,     3,     1,     4,     1,
       4,     1,     3,     1,     1,     4,     1,     3,     3,     0,
       5,     2,     4,     5,     5,     2,     4,     4,     3,     3,
       3,     2,     1,     4,     0,     5,     0,     5,     5,     1,
       1,     6,     1,     1,     1,     1,     2,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     2,     3,     1,     2,
       1,     0,     4,     1,     2,     2,     3,     2,     3,     1,
       0,     1,     1,     2,     1,     2,     1,     2,     1,     0,
       4,     2,     3,     1,     4,     2,     1,     1,     1,     1,
       1,     2,     2,     3,     1,     1,     2,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     0,     4,     3,     2,     6,     8,
       4,     6,     4,     6,     2,     4,     6,     2,     4,     2,
       4,     1,     0,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     3,     2,     2,     2,     1,     3,     1,     3,
       1,     1,     2,     1,     1,     1,     2,     2,     1,     1,
       0,     4,     1,     2,     1,     3,     3,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     1,     0,     1,     2,     2,     0,     1,     1,     1,
       1,     0,     3,     1,     2,     0
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
#line 1167 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      p->lstate = EXPR_BEG;
                      if (!p->locals) p->locals = cons(0,0);
                    }
#line 5014 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 1172 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      p->tree = new_scope(p, (yyvsp[0].nd));
                      NODE_LINENO(p->tree, (yyvsp[0].nd));
                    }
#line 5023 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 1179 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = (yyvsp[-1].nd);
                    }
#line 5031 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 1185 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_begin(p, 0);
                    }
#line 5039 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 1189 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_begin(p, (yyvsp[0].nd));
                      NODE_LINENO((yyval.nd), (yyvsp[0].nd));
                    }
#line 5048 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 1194 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = push((yyvsp[-2].nd), newline_node((yyvsp[0].nd)));
                    }
#line 5056 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 1198 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_begin(p, 0);
                    }
#line 5064 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 1205 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = local_switch(p);
                    }
#line 5072 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 1209 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      yyerror(p, "BEGIN not supported");
                      local_resume(p, (yyvsp[-3].nd));
                      (yyval.nd) = 0;
                    }
#line 5082 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 1220 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
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
#line 5108 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 1244 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = (yyvsp[-1].nd);
                    }
#line 5116 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 1250 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_begin(p, 0);
                    }
#line 5124 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 1254 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_begin(p, (yyvsp[0].nd));
                      NODE_LINENO((yyval.nd), (yyvsp[0].nd));
                    }
#line 5133 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 1259 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = push((yyvsp[-2].nd), newline_node((yyvsp[0].nd)));
                    }
#line 5141 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 1263 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_begin(p, (yyvsp[0].nd));
                    }
#line 5149 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 1268 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {p->lstate = EXPR_FNAME;}
#line 5155 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 1269 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_alias(p, (yyvsp[-2].id), (yyvsp[0].id));
                    }
#line 5163 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 1273 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = (yyvsp[0].nd);
                    }
#line 5171 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 1277 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_if(p, cond((yyvsp[0].nd)), (yyvsp[-2].nd), 0);
                    }
#line 5179 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 1281 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_unless(p, cond((yyvsp[0].nd)), (yyvsp[-2].nd), 0);
                    }
#line 5187 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 1285 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_while(p, cond((yyvsp[0].nd)), (yyvsp[-2].nd));
                    }
#line 5195 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 1289 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_until(p, cond((yyvsp[0].nd)), (yyvsp[-2].nd));
                    }
#line 5203 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 1293 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_rescue(p, (yyvsp[-2].nd), list1(list3(0, 0, (yyvsp[0].nd))), 0);
                    }
#line 5211 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 1297 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      yyerror(p, "END not suported");
                      (yyval.nd) = new_postexe(p, (yyvsp[-1].nd));
                    }
#line 5220 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 1303 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_masgn(p, (yyvsp[-2].nd), (yyvsp[0].nd));
                    }
#line 5228 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 1307 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_op_asgn(p, (yyvsp[-2].nd), (yyvsp[-1].id), (yyvsp[0].nd));
                    }
#line 5236 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 1311 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_op_asgn(p, new_call(p, (yyvsp[-5].nd), intern("[]",2), (yyvsp[-3].nd)), (yyvsp[-1].id), (yyvsp[0].nd));
                    }
#line 5244 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 1315 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_op_asgn(p, new_call(p, (yyvsp[-4].nd), (yyvsp[-2].id), 0), (yyvsp[-1].id), (yyvsp[0].nd));
                    }
#line 5252 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 1319 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_op_asgn(p, new_call(p, (yyvsp[-4].nd), (yyvsp[-2].id), 0), (yyvsp[-1].id), (yyvsp[0].nd));
                    }
#line 5260 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 1323 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      yyerror(p, "constant re-assignment");
                      (yyval.nd) = 0;
                    }
#line 5269 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 1328 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_op_asgn(p, new_call(p, (yyvsp[-4].nd), (yyvsp[-2].id), 0), (yyvsp[-1].id), (yyvsp[0].nd));
                    }
#line 5277 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 1332 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      backref_error(p, (yyvsp[-2].nd));
                      (yyval.nd) = new_begin(p, 0);
                    }
#line 5286 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 1337 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_asgn(p, (yyvsp[-2].nd), new_array(p, (yyvsp[0].nd)));
                    }
#line 5294 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 1341 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_masgn(p, (yyvsp[-2].nd), (yyvsp[0].nd));
                    }
#line 5302 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 1345 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_masgn(p, (yyvsp[-2].nd), new_array(p, (yyvsp[0].nd)));
                    }
#line 5310 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 1352 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_asgn(p, (yyvsp[-2].nd), (yyvsp[0].nd));
                    }
#line 5318 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 1356 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_asgn(p, (yyvsp[-2].nd), (yyvsp[0].nd));
                    }
#line 5326 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 1364 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_and(p, (yyvsp[-2].nd), (yyvsp[0].nd));
                    }
#line 5334 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 1368 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_or(p, (yyvsp[-2].nd), (yyvsp[0].nd));
                    }
#line 5342 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 1372 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = call_uni_op(p, cond((yyvsp[0].nd)), "!");
                    }
#line 5350 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 1376 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = call_uni_op(p, cond((yyvsp[0].nd)), "!");
                    }
#line 5358 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 1383 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      if (!(yyvsp[0].nd)) (yyval.nd) = new_nil(p);
                      else (yyval.nd) = (yyvsp[0].nd);
                    }
#line 5367 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 1398 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      local_nest(p);
                    }
#line 5375 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 1404 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_block(p, (yyvsp[-2].nd), (yyvsp[-1].nd));
                      local_unnest(p);
                    }
#line 5384 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 1411 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_fcall(p, (yyvsp[-1].id), (yyvsp[0].nd));
                    }
#line 5392 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 1415 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      args_with_block(p, (yyvsp[-1].nd), (yyvsp[0].nd));
                      (yyval.nd) = new_fcall(p, (yyvsp[-2].id), (yyvsp[-1].nd));
                    }
#line 5401 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 1420 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_call(p, (yyvsp[-3].nd), (yyvsp[-1].id), (yyvsp[0].nd));
                    }
#line 5409 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 1424 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      args_with_block(p, (yyvsp[-1].nd), (yyvsp[0].nd));
                      (yyval.nd) = new_call(p, (yyvsp[-4].nd), (yyvsp[-2].id), (yyvsp[-1].nd));
                   }
#line 5418 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 1429 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_call(p, (yyvsp[-3].nd), (yyvsp[-1].id), (yyvsp[0].nd));
                    }
#line 5426 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 1433 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      args_with_block(p, (yyvsp[-1].nd), (yyvsp[0].nd));
                      (yyval.nd) = new_call(p, (yyvsp[-4].nd), (yyvsp[-2].id), (yyvsp[-1].nd));
                    }
#line 5435 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 1438 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_super(p, (yyvsp[0].nd));
                    }
#line 5443 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 1442 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_yield(p, (yyvsp[0].nd));
                    }
#line 5451 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 1446 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_return(p, ret_args(p, (yyvsp[0].nd)));
                    }
#line 5459 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 1450 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_break(p, ret_args(p, (yyvsp[0].nd)));
                    }
#line 5467 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 1454 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_next(p, ret_args(p, (yyvsp[0].nd)));
                    }
#line 5475 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 1460 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = (yyvsp[0].nd);
                    }
#line 5483 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 1464 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = (yyvsp[-1].nd);
                    }
#line 5491 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 1471 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = (yyvsp[-1].nd);
                    }
#line 5499 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 1477 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = list1((yyvsp[0].nd));
                    }
#line 5507 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 1481 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = list1(push((yyvsp[-1].nd),(yyvsp[0].nd)));
                    }
#line 5515 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 1485 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = list2((yyvsp[-2].nd), (yyvsp[0].nd));
                    }
#line 5523 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 1489 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = list3((yyvsp[-4].nd), (yyvsp[-2].nd), (yyvsp[0].nd));
                    }
#line 5531 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 1493 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = list2((yyvsp[-1].nd), new_nil(p));
                    }
#line 5539 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 1497 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = list3((yyvsp[-3].nd), new_nil(p), (yyvsp[0].nd));
                    }
#line 5547 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 1501 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = list2(0, (yyvsp[0].nd));
                    }
#line 5555 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 1505 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = list3(0, (yyvsp[-2].nd), (yyvsp[0].nd));
                    }
#line 5563 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 1509 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = list2(0, new_nil(p));
                    }
#line 5571 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 1513 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = list3(0, new_nil(p), (yyvsp[0].nd));
                    }
#line 5579 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 1520 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_masgn(p, (yyvsp[-1].nd), NULL);
                    }
#line 5587 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 1526 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = list1((yyvsp[-1].nd));
                    }
#line 5595 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 1530 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = push((yyvsp[-2].nd), (yyvsp[-1].nd));
                    }
#line 5603 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 1536 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = list1((yyvsp[0].nd));
                    }
#line 5611 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 1540 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = push((yyvsp[-1].nd), (yyvsp[0].nd));
                    }
#line 5619 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 1546 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      assignable(p, (yyvsp[0].nd));
                    }
#line 5627 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 1550 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_call(p, (yyvsp[-3].nd), intern("[]",2), (yyvsp[-1].nd));
                    }
#line 5635 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 1554 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_call(p, (yyvsp[-2].nd), (yyvsp[0].id), 0);
                    }
#line 5643 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 1558 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_call(p, (yyvsp[-2].nd), (yyvsp[0].id), 0);
                    }
#line 5651 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 1562 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_call(p, (yyvsp[-2].nd), (yyvsp[0].id), 0);
                    }
#line 5659 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 1566 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      if (p->in_def || p->in_single)
                        yyerror(p, "dynamic constant assignment");
                      (yyval.nd) = new_colon2(p, (yyvsp[-2].nd), (yyvsp[0].id));
                    }
#line 5669 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 1572 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      if (p->in_def || p->in_single)
                        yyerror(p, "dynamic constant assignment");
                      (yyval.nd) = new_colon3(p, (yyvsp[0].id));
                    }
#line 5679 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 1578 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      backref_error(p, (yyvsp[0].nd));
                      (yyval.nd) = 0;
                    }
#line 5688 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 1585 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      assignable(p, (yyvsp[0].nd));
                    }
#line 5696 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 1589 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_call(p, (yyvsp[-3].nd), intern("[]",2), (yyvsp[-1].nd));
                    }
#line 5704 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 1593 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_call(p, (yyvsp[-2].nd), (yyvsp[0].id), 0);
                    }
#line 5712 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 1597 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_call(p, (yyvsp[-2].nd), (yyvsp[0].id), 0);
                    }
#line 5720 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 1601 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_call(p, (yyvsp[-2].nd), (yyvsp[0].id), 0);
                    }
#line 5728 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 1605 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      if (p->in_def || p->in_single)
                        yyerror(p, "dynamic constant assignment");
                      (yyval.nd) = new_colon2(p, (yyvsp[-2].nd), (yyvsp[0].id));
                    }
#line 5738 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 1611 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      if (p->in_def || p->in_single)
                        yyerror(p, "dynamic constant assignment");
                      (yyval.nd) = new_colon3(p, (yyvsp[0].id));
                    }
#line 5748 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 1617 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      backref_error(p, (yyvsp[0].nd));
                      (yyval.nd) = 0;
                    }
#line 5757 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 1624 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      yyerror(p, "class/module name must be CONSTANT");
                    }
#line 5765 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 1631 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = cons((node*)1, nsym((yyvsp[0].id)));
                    }
#line 5773 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 1635 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = cons((node*)0, nsym((yyvsp[0].id)));
                    }
#line 5781 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 1639 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = cons((yyvsp[-2].nd), nsym((yyvsp[0].id)));
                    }
#line 5789 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 1648 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      p->lstate = EXPR_ENDFN;
                      (yyval.id) = (yyvsp[0].id);
                    }
#line 5798 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 1653 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      p->lstate = EXPR_ENDFN;
                      (yyval.id) = (yyvsp[0].id);
                    }
#line 5807 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 1664 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_undef(p, (yyvsp[0].id));
                    }
#line 5815 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 1667 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {p->lstate = EXPR_FNAME;}
#line 5821 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 1668 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = push((yyvsp[-3].nd), nsym((yyvsp[0].id)));
                    }
#line 5829 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 1673 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    { (yyval.id) = intern_c('|');   }
#line 5835 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 1674 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    { (yyval.id) = intern_c('^');   }
#line 5841 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 1675 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    { (yyval.id) = intern_c('&');   }
#line 5847 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 1676 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    { (yyval.id) = intern("<=>",3); }
#line 5853 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 1677 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    { (yyval.id) = intern("==",2);  }
#line 5859 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 1678 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    { (yyval.id) = intern("===",3); }
#line 5865 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 1679 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    { (yyval.id) = intern("=~",2);  }
#line 5871 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 1680 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    { (yyval.id) = intern("!~",2);  }
#line 5877 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 1681 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    { (yyval.id) = intern_c('>');   }
#line 5883 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 1682 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    { (yyval.id) = intern(">=",2);  }
#line 5889 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 1683 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    { (yyval.id) = intern_c('<');   }
#line 5895 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 1684 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    { (yyval.id) = intern("<=",2);  }
#line 5901 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 1685 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    { (yyval.id) = intern("!=",2);  }
#line 5907 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 1686 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    { (yyval.id) = intern("<<",2);  }
#line 5913 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 1687 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    { (yyval.id) = intern(">>",2);  }
#line 5919 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 1688 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    { (yyval.id) = intern_c('+');   }
#line 5925 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 1689 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    { (yyval.id) = intern_c('-');   }
#line 5931 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 1690 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    { (yyval.id) = intern_c('*');   }
#line 5937 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 1691 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    { (yyval.id) = intern_c('*');   }
#line 5943 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 1692 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    { (yyval.id) = intern_c('/');   }
#line 5949 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 1693 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    { (yyval.id) = intern_c('%');   }
#line 5955 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 1694 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    { (yyval.id) = intern("**",2);  }
#line 5961 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 1695 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    { (yyval.id) = intern_c('!');   }
#line 5967 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 140:
#line 1696 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    { (yyval.id) = intern_c('~');   }
#line 5973 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 1697 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    { (yyval.id) = intern("+@",2);  }
#line 5979 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 142:
#line 1698 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    { (yyval.id) = intern("-@",2);  }
#line 5985 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 143:
#line 1699 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    { (yyval.id) = intern("[]",2);  }
#line 5991 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 144:
#line 1700 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    { (yyval.id) = intern("[]=",3); }
#line 5997 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 145:
#line 1701 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    { (yyval.id) = intern_c('`');   }
#line 6003 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 186:
#line 1719 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_asgn(p, (yyvsp[-2].nd), (yyvsp[0].nd));
                    }
#line 6011 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 187:
#line 1723 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_asgn(p, (yyvsp[-4].nd), new_rescue(p, (yyvsp[-2].nd), list1(list3(0, 0, (yyvsp[0].nd))), 0));
                    }
#line 6019 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 188:
#line 1727 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_op_asgn(p, (yyvsp[-2].nd), (yyvsp[-1].id), (yyvsp[0].nd));
                    }
#line 6027 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 189:
#line 1731 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_op_asgn(p, (yyvsp[-4].nd), (yyvsp[-3].id), new_rescue(p, (yyvsp[-2].nd), list1(list3(0, 0, (yyvsp[0].nd))), 0));
                    }
#line 6035 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 190:
#line 1735 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_op_asgn(p, new_call(p, (yyvsp[-5].nd), intern("[]",2), (yyvsp[-3].nd)), (yyvsp[-1].id), (yyvsp[0].nd));
                    }
#line 6043 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 191:
#line 1739 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_op_asgn(p, new_call(p, (yyvsp[-4].nd), (yyvsp[-2].id), 0), (yyvsp[-1].id), (yyvsp[0].nd));
                    }
#line 6051 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 192:
#line 1743 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_op_asgn(p, new_call(p, (yyvsp[-4].nd), (yyvsp[-2].id), 0), (yyvsp[-1].id), (yyvsp[0].nd));
                    }
#line 6059 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 193:
#line 1747 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_op_asgn(p, new_call(p, (yyvsp[-4].nd), (yyvsp[-2].id), 0), (yyvsp[-1].id), (yyvsp[0].nd));
                    }
#line 6067 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 194:
#line 1751 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      yyerror(p, "constant re-assignment");
                      (yyval.nd) = new_begin(p, 0);
                    }
#line 6076 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 195:
#line 1756 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      yyerror(p, "constant re-assignment");
                      (yyval.nd) = new_begin(p, 0);
                    }
#line 6085 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 196:
#line 1761 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      backref_error(p, (yyvsp[-2].nd));
                      (yyval.nd) = new_begin(p, 0);
                    }
#line 6094 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 197:
#line 1766 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_dot2(p, (yyvsp[-2].nd), (yyvsp[0].nd));
                    }
#line 6102 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 198:
#line 1770 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_dot3(p, (yyvsp[-2].nd), (yyvsp[0].nd));
                    }
#line 6110 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 199:
#line 1774 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = call_bin_op(p, (yyvsp[-2].nd), "+", (yyvsp[0].nd));
                    }
#line 6118 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 200:
#line 1778 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = call_bin_op(p, (yyvsp[-2].nd), "-", (yyvsp[0].nd));
                    }
#line 6126 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 201:
#line 1782 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = call_bin_op(p, (yyvsp[-2].nd), "*", (yyvsp[0].nd));
                    }
#line 6134 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 202:
#line 1786 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = call_bin_op(p, (yyvsp[-2].nd), "/", (yyvsp[0].nd));
                    }
#line 6142 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 203:
#line 1790 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = call_bin_op(p, (yyvsp[-2].nd), "%", (yyvsp[0].nd));
                    }
#line 6150 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 204:
#line 1794 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = call_bin_op(p, (yyvsp[-2].nd), "**", (yyvsp[0].nd));
                    }
#line 6158 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 205:
#line 1798 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = call_uni_op(p, call_bin_op(p, (yyvsp[-2].nd), "**", (yyvsp[0].nd)), "-@");
                    }
#line 6166 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 206:
#line 1802 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = call_uni_op(p, call_bin_op(p, (yyvsp[-2].nd), "**", (yyvsp[0].nd)), "-@");
                    }
#line 6174 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 207:
#line 1806 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = call_uni_op(p, (yyvsp[0].nd), "+@");
                    }
#line 6182 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 208:
#line 1810 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = call_uni_op(p, (yyvsp[0].nd), "-@");
                    }
#line 6190 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 209:
#line 1814 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = call_bin_op(p, (yyvsp[-2].nd), "|", (yyvsp[0].nd));
                    }
#line 6198 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 210:
#line 1818 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = call_bin_op(p, (yyvsp[-2].nd), "^", (yyvsp[0].nd));
                    }
#line 6206 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 211:
#line 1822 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = call_bin_op(p, (yyvsp[-2].nd), "&", (yyvsp[0].nd));
                    }
#line 6214 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 212:
#line 1826 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = call_bin_op(p, (yyvsp[-2].nd), "<=>", (yyvsp[0].nd));
                    }
#line 6222 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 213:
#line 1830 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = call_bin_op(p, (yyvsp[-2].nd), ">", (yyvsp[0].nd));
                    }
#line 6230 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 214:
#line 1834 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = call_bin_op(p, (yyvsp[-2].nd), ">=", (yyvsp[0].nd));
                    }
#line 6238 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 215:
#line 1838 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = call_bin_op(p, (yyvsp[-2].nd), "<", (yyvsp[0].nd));
                    }
#line 6246 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 216:
#line 1842 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = call_bin_op(p, (yyvsp[-2].nd), "<=", (yyvsp[0].nd));
                    }
#line 6254 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 217:
#line 1846 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = call_bin_op(p, (yyvsp[-2].nd), "==", (yyvsp[0].nd));
                    }
#line 6262 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 218:
#line 1850 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = call_bin_op(p, (yyvsp[-2].nd), "===", (yyvsp[0].nd));
                    }
#line 6270 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 219:
#line 1854 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = call_bin_op(p, (yyvsp[-2].nd), "!=", (yyvsp[0].nd));
                    }
#line 6278 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 220:
#line 1858 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = call_bin_op(p, (yyvsp[-2].nd), "=~", (yyvsp[0].nd));
                    }
#line 6286 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 221:
#line 1862 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = call_bin_op(p, (yyvsp[-2].nd), "!~", (yyvsp[0].nd));
                    }
#line 6294 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 222:
#line 1866 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = call_uni_op(p, cond((yyvsp[0].nd)), "!");
                    }
#line 6302 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 223:
#line 1870 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = call_uni_op(p, cond((yyvsp[0].nd)), "~");
                    }
#line 6310 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 224:
#line 1874 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = call_bin_op(p, (yyvsp[-2].nd), "<<", (yyvsp[0].nd));
                    }
#line 6318 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 225:
#line 1878 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = call_bin_op(p, (yyvsp[-2].nd), ">>", (yyvsp[0].nd));
                    }
#line 6326 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 226:
#line 1882 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_and(p, (yyvsp[-2].nd), (yyvsp[0].nd));
                    }
#line 6334 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 227:
#line 1886 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_or(p, (yyvsp[-2].nd), (yyvsp[0].nd));
                    }
#line 6342 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 228:
#line 1890 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_if(p, cond((yyvsp[-5].nd)), (yyvsp[-3].nd), (yyvsp[0].nd));
                    }
#line 6350 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 229:
#line 1894 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = (yyvsp[0].nd);
                    }
#line 6358 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 230:
#line 1900 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = (yyvsp[0].nd);
                      if (!(yyval.nd)) (yyval.nd) = new_nil(p);
                    }
#line 6367 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 232:
#line 1908 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = (yyvsp[-1].nd);
                      NODE_LINENO((yyval.nd), (yyvsp[-1].nd));
                    }
#line 6376 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 233:
#line 1913 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = push((yyvsp[-3].nd), new_hash(p, (yyvsp[-1].nd)));
                    }
#line 6384 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 234:
#line 1917 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = cons(new_hash(p, (yyvsp[-1].nd)), 0);
                      NODE_LINENO((yyval.nd), (yyvsp[-1].nd));
                    }
#line 6393 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 235:
#line 1924 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = (yyvsp[-1].nd);
                    }
#line 6401 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 240:
#line 1936 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = cons((yyvsp[-1].nd),0);
                      NODE_LINENO((yyval.nd), (yyvsp[-1].nd));
                    }
#line 6410 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 241:
#line 1941 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = cons(push((yyvsp[-3].nd), new_hash(p, (yyvsp[-1].nd))), 0);
                      NODE_LINENO((yyval.nd), (yyvsp[-3].nd));
                    }
#line 6419 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 242:
#line 1946 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = cons(list1(new_hash(p, (yyvsp[-1].nd))), 0);
                      NODE_LINENO((yyval.nd), (yyvsp[-1].nd));
                    }
#line 6428 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 243:
#line 1953 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = cons(list1((yyvsp[0].nd)), 0);
                      NODE_LINENO((yyval.nd), (yyvsp[0].nd));
                    }
#line 6437 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 244:
#line 1958 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = cons((yyvsp[-1].nd), (yyvsp[0].nd));
                      NODE_LINENO((yyval.nd), (yyvsp[-1].nd));
                    }
#line 6446 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 245:
#line 1963 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = cons(list1(new_hash(p, (yyvsp[-1].nd))), (yyvsp[0].nd));
                      NODE_LINENO((yyval.nd), (yyvsp[-1].nd));
                    }
#line 6455 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 246:
#line 1968 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = cons(push((yyvsp[-3].nd), new_hash(p, (yyvsp[-1].nd))), (yyvsp[0].nd));
                      NODE_LINENO((yyval.nd), (yyvsp[-3].nd));
                    }
#line 6464 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 247:
#line 1973 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = cons(0, (yyvsp[0].nd));
                      NODE_LINENO((yyval.nd), (yyvsp[0].nd));
                    }
#line 6473 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 248:
#line 1979 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.stack) = p->cmdarg_stack;
                      CMDARG_PUSH(1);
                    }
#line 6482 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 249:
#line 1984 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      p->cmdarg_stack = (yyvsp[-1].stack);
                      (yyval.nd) = (yyvsp[0].nd);
                    }
#line 6491 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 250:
#line 1991 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_block_arg(p, (yyvsp[0].nd));
                    }
#line 6499 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 251:
#line 1997 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = (yyvsp[0].nd);
                    }
#line 6507 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 252:
#line 2001 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = 0;
                    }
#line 6515 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 253:
#line 2007 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = cons((yyvsp[0].nd), 0);
                      NODE_LINENO((yyval.nd), (yyvsp[0].nd));
                    }
#line 6524 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 254:
#line 2012 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = cons(new_splat(p, (yyvsp[0].nd)), 0);
                      NODE_LINENO((yyval.nd), (yyvsp[0].nd));
                    }
#line 6533 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 255:
#line 2017 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = push((yyvsp[-2].nd), (yyvsp[0].nd));
                    }
#line 6541 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 256:
#line 2021 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = push((yyvsp[-3].nd), new_splat(p, (yyvsp[0].nd)));
                    }
#line 6549 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 257:
#line 2025 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = push((yyvsp[-3].nd), (yyvsp[0].nd));
                    }
#line 6557 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 258:
#line 2029 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = push((yyvsp[-4].nd), new_splat(p, (yyvsp[0].nd)));
                    }
#line 6565 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 259:
#line 2035 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = push((yyvsp[-2].nd), (yyvsp[0].nd));
                    }
#line 6573 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 260:
#line 2039 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = push((yyvsp[-3].nd), new_splat(p, (yyvsp[0].nd)));
                    }
#line 6581 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 261:
#line 2043 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = list1(new_splat(p, (yyvsp[0].nd)));
                    }
#line 6589 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 269:
#line 2056 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_fcall(p, (yyvsp[0].id), 0);
                    }
#line 6597 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 270:
#line 2060 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.stack) = p->cmdarg_stack;
                      p->cmdarg_stack = 0;
                    }
#line 6606 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 271:
#line 2066 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      p->cmdarg_stack = (yyvsp[-2].stack);
                      (yyval.nd) = (yyvsp[-1].nd);
                    }
#line 6615 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 272:
#line 2071 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.stack) = p->cmdarg_stack;
                      p->cmdarg_stack = 0;
                    }
#line 6624 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 273:
#line 2075 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {p->lstate = EXPR_ENDARG;}
#line 6630 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 274:
#line 2076 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      p->cmdarg_stack = (yyvsp[-3].stack);
                      (yyval.nd) = (yyvsp[-2].nd);
                    }
#line 6639 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 275:
#line 2080 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {p->lstate = EXPR_ENDARG;}
#line 6645 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 276:
#line 2081 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = 0;
                    }
#line 6653 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 277:
#line 2085 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = (yyvsp[-1].nd);
                    }
#line 6661 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 278:
#line 2089 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_colon2(p, (yyvsp[-2].nd), (yyvsp[0].id));
                    }
#line 6669 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 279:
#line 2093 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_colon3(p, (yyvsp[0].id));
                    }
#line 6677 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 280:
#line 2097 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_array(p, (yyvsp[-1].nd));
                      NODE_LINENO((yyval.nd), (yyvsp[-1].nd));
                    }
#line 6686 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 281:
#line 2102 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_hash(p, (yyvsp[-1].nd));
                      NODE_LINENO((yyval.nd), (yyvsp[-1].nd));
                    }
#line 6695 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 282:
#line 2107 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_return(p, 0);
                    }
#line 6703 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 283:
#line 2111 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_yield(p, (yyvsp[-1].nd));
                    }
#line 6711 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 284:
#line 2115 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_yield(p, 0);
                    }
#line 6719 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 285:
#line 2119 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_yield(p, 0);
                    }
#line 6727 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 286:
#line 2123 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = call_uni_op(p, cond((yyvsp[-1].nd)), "!");
                    }
#line 6735 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 287:
#line 2127 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = call_uni_op(p, new_nil(p), "!");
                    }
#line 6743 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 288:
#line 2131 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_fcall(p, (yyvsp[-1].id), cons(0, (yyvsp[0].nd)));
                    }
#line 6751 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 290:
#line 2136 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      call_with_block(p, (yyvsp[-1].nd), (yyvsp[0].nd));
                      (yyval.nd) = (yyvsp[-1].nd);
                    }
#line 6760 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 291:
#line 2141 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      local_nest(p);
                      (yyval.num) = p->lpar_beg;
                      p->lpar_beg = ++p->paren_nest;
                    }
#line 6770 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 292:
#line 2147 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.stack) = p->cmdarg_stack;
                      p->cmdarg_stack = 0;
                    }
#line 6779 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 293:
#line 2152 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      p->lpar_beg = (yyvsp[-3].num);
                      (yyval.nd) = new_lambda(p, (yyvsp[-2].nd), (yyvsp[0].nd));
                      local_unnest(p);
                      p->cmdarg_stack = (yyvsp[-1].stack);
                      CMDARG_LEXPOP();
                    }
#line 6791 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 294:
#line 2163 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_if(p, cond((yyvsp[-4].nd)), (yyvsp[-2].nd), (yyvsp[-1].nd));
                      SET_LINENO((yyval.nd), (yyvsp[-5].num));
                    }
#line 6800 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 295:
#line 2171 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_unless(p, cond((yyvsp[-4].nd)), (yyvsp[-2].nd), (yyvsp[-1].nd));
                      SET_LINENO((yyval.nd), (yyvsp[-5].num));
                    }
#line 6809 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 296:
#line 2175 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {COND_PUSH(1);}
#line 6815 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 297:
#line 2175 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {COND_POP();}
#line 6821 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 298:
#line 2178 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_while(p, cond((yyvsp[-4].nd)), (yyvsp[-1].nd));
                      SET_LINENO((yyval.nd), (yyvsp[-6].num));
                    }
#line 6830 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 299:
#line 2182 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {COND_PUSH(1);}
#line 6836 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 300:
#line 2182 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {COND_POP();}
#line 6842 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 301:
#line 2185 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_until(p, cond((yyvsp[-4].nd)), (yyvsp[-1].nd));
                      SET_LINENO((yyval.nd), (yyvsp[-6].num));
                    }
#line 6851 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 302:
#line 2192 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_case(p, (yyvsp[-3].nd), (yyvsp[-1].nd));
                    }
#line 6859 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 303:
#line 2196 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_case(p, 0, (yyvsp[-1].nd));
                    }
#line 6867 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 304:
#line 2200 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {COND_PUSH(1);}
#line 6873 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 305:
#line 2202 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {COND_POP();}
#line 6879 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 306:
#line 2205 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_for(p, (yyvsp[-7].nd), (yyvsp[-4].nd), (yyvsp[-1].nd));
                      SET_LINENO((yyval.nd), (yyvsp[-8].num));
                    }
#line 6888 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 307:
#line 2211 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      if (p->in_def || p->in_single)
                        yyerror(p, "class definition in method body");
                      (yyval.nd) = local_switch(p);
                    }
#line 6898 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 308:
#line 2218 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_class(p, (yyvsp[-4].nd), (yyvsp[-3].nd), (yyvsp[-1].nd));
                      SET_LINENO((yyval.nd), (yyvsp[-5].num));
                      local_resume(p, (yyvsp[-2].nd));
                    }
#line 6908 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 309:
#line 2225 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.num) = p->in_def;
                      p->in_def = 0;
                    }
#line 6917 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 310:
#line 2230 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = cons(local_switch(p), (node*)(intptr_t)p->in_single);
                      p->in_single = 0;
                    }
#line 6926 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 311:
#line 2236 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_sclass(p, (yyvsp[-5].nd), (yyvsp[-1].nd));
                      SET_LINENO((yyval.nd), (yyvsp[-7].num));
                      local_resume(p, (yyvsp[-2].nd)->car);
                      p->in_def = (yyvsp[-4].num);
                      p->in_single = (int)(intptr_t)(yyvsp[-2].nd)->cdr;
                    }
#line 6938 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 312:
#line 2245 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      if (p->in_def || p->in_single)
                        yyerror(p, "module definition in method body");
                      (yyval.nd) = local_switch(p);
                    }
#line 6948 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 313:
#line 2252 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_module(p, (yyvsp[-3].nd), (yyvsp[-1].nd));
                      SET_LINENO((yyval.nd), (yyvsp[-4].num));
                      local_resume(p, (yyvsp[-2].nd));
                    }
#line 6958 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 314:
#line 2258 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.stack) = p->cmdarg_stack;
                      p->cmdarg_stack = 0;
                    }
#line 6967 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 315:
#line 2262 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      p->in_def++;
                      (yyval.nd) = local_switch(p);
                    }
#line 6976 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 316:
#line 2269 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_def(p, (yyvsp[-5].id), (yyvsp[-2].nd), (yyvsp[-1].nd));
                      SET_LINENO((yyval.nd), (yyvsp[-6].num));
                      local_resume(p, (yyvsp[-3].nd));
                      p->in_def--;
                      p->cmdarg_stack = (yyvsp[-4].stack);
                    }
#line 6988 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 317:
#line 2277 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      p->lstate = EXPR_FNAME;
                      (yyval.stack) = p->cmdarg_stack;
                      p->cmdarg_stack = 0;
                    }
#line 6998 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 318:
#line 2283 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      p->in_single++;
                      p->lstate = EXPR_ENDFN; /* force for args */
                      (yyval.nd) = local_switch(p);
                    }
#line 7008 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 319:
#line 2291 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_sdef(p, (yyvsp[-7].nd), (yyvsp[-4].id), (yyvsp[-2].nd), (yyvsp[-1].nd));
                      SET_LINENO((yyval.nd), (yyvsp[-8].num));
                      local_resume(p, (yyvsp[-3].nd));
                      p->in_single--;
                      p->cmdarg_stack = (yyvsp[-5].stack);
                    }
#line 7020 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 320:
#line 2299 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_break(p, 0);
                    }
#line 7028 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 321:
#line 2303 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_next(p, 0);
                    }
#line 7036 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 322:
#line 2307 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_redo(p);
                    }
#line 7044 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 323:
#line 2311 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_retry(p);
                    }
#line 7052 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 324:
#line 2317 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = (yyvsp[0].nd);
                      if (!(yyval.nd)) (yyval.nd) = new_nil(p);
                    }
#line 7061 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 331:
#line 2336 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_if(p, cond((yyvsp[-3].nd)), (yyvsp[-1].nd), (yyvsp[0].nd));
                    }
#line 7069 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 333:
#line 2343 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = (yyvsp[0].nd);
                    }
#line 7077 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 334:
#line 2349 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = list1(list1((yyvsp[0].nd)));
                    }
#line 7085 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 336:
#line 2356 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_arg(p, (yyvsp[0].id));
                    }
#line 7093 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 337:
#line 2360 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_masgn(p, (yyvsp[-1].nd), 0);
                    }
#line 7101 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 338:
#line 2366 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = list1((yyvsp[0].nd));
                    }
#line 7109 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 339:
#line 2370 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = push((yyvsp[-2].nd), (yyvsp[0].nd));
                    }
#line 7117 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 340:
#line 2376 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = list3((yyvsp[0].nd),0,0);
                    }
#line 7125 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 341:
#line 2380 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = list3((yyvsp[-3].nd), new_arg(p, (yyvsp[0].id)), 0);
                    }
#line 7133 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 342:
#line 2384 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = list3((yyvsp[-5].nd), new_arg(p, (yyvsp[-2].id)), (yyvsp[0].nd));
                    }
#line 7141 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 343:
#line 2388 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = list3((yyvsp[-2].nd), (node*)-1, 0);
                    }
#line 7149 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 344:
#line 2392 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = list3((yyvsp[-4].nd), (node*)-1, (yyvsp[0].nd));
                    }
#line 7157 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 345:
#line 2396 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = list3(0, new_arg(p, (yyvsp[0].id)), 0);
                    }
#line 7165 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 346:
#line 2400 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = list3(0, new_arg(p, (yyvsp[-2].id)), (yyvsp[0].nd));
                    }
#line 7173 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 347:
#line 2404 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = list3(0, (node*)-1, 0);
                    }
#line 7181 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 348:
#line 2408 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = list3(0, (node*)-1, (yyvsp[0].nd));
                    }
#line 7189 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 349:
#line 2414 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_args(p, (yyvsp[-5].nd), (yyvsp[-3].nd), (yyvsp[-1].id), 0, (yyvsp[0].id));
                    }
#line 7197 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 350:
#line 2418 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_args(p, (yyvsp[-7].nd), (yyvsp[-5].nd), (yyvsp[-3].id), (yyvsp[-1].nd), (yyvsp[0].id));
                    }
#line 7205 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 351:
#line 2422 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_args(p, (yyvsp[-3].nd), (yyvsp[-1].nd), 0, 0, (yyvsp[0].id));
                    }
#line 7213 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 352:
#line 2426 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_args(p, (yyvsp[-5].nd), (yyvsp[-3].nd), 0, (yyvsp[-1].nd), (yyvsp[0].id));
                    }
#line 7221 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 353:
#line 2430 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_args(p, (yyvsp[-3].nd), 0, (yyvsp[-1].id), 0, (yyvsp[0].id));
                    }
#line 7229 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 354:
#line 2434 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_args(p, (yyvsp[-1].nd), 0, 1, 0, 0);
                    }
#line 7237 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 355:
#line 2438 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_args(p, (yyvsp[-5].nd), 0, (yyvsp[-3].id), (yyvsp[-1].nd), (yyvsp[0].id));
                    }
#line 7245 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 356:
#line 2442 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_args(p, (yyvsp[-1].nd), 0, 0, 0, (yyvsp[0].id));
                    }
#line 7253 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 357:
#line 2446 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_args(p, 0, (yyvsp[-3].nd), (yyvsp[-1].id), 0, (yyvsp[0].id));
                    }
#line 7261 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 358:
#line 2450 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_args(p, 0, (yyvsp[-5].nd), (yyvsp[-3].id), (yyvsp[-1].nd), (yyvsp[0].id));
                    }
#line 7269 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 359:
#line 2454 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_args(p, 0, (yyvsp[-1].nd), 0, 0, (yyvsp[0].id));
                    }
#line 7277 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 360:
#line 2458 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_args(p, 0, (yyvsp[-3].nd), 0, (yyvsp[-1].nd), (yyvsp[0].id));
                    }
#line 7285 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 361:
#line 2462 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_args(p, 0, 0, (yyvsp[-1].id), 0, (yyvsp[0].id));
                    }
#line 7293 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 362:
#line 2466 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_args(p, 0, 0, (yyvsp[-3].id), (yyvsp[-1].nd), (yyvsp[0].id));
                    }
#line 7301 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 363:
#line 2470 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_args(p, 0, 0, 0, 0, (yyvsp[0].id));
                    }
#line 7309 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 365:
#line 2477 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      p->cmd_start = TRUE;
                      (yyval.nd) = (yyvsp[0].nd);
                    }
#line 7318 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 366:
#line 2484 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = 0;
                    }
#line 7326 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 367:
#line 2488 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = 0;
                    }
#line 7334 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 368:
#line 2492 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = (yyvsp[-2].nd);
                    }
#line 7342 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 369:
#line 2499 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = 0;
                    }
#line 7350 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 370:
#line 2503 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = 0;
                    }
#line 7358 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 373:
#line 2513 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      local_add_f(p, (yyvsp[0].id));
                      new_bv(p, (yyvsp[0].id));
                    }
#line 7367 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 375:
#line 2521 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = (yyvsp[-2].nd);
                    }
#line 7375 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 376:
#line 2525 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = (yyvsp[0].nd);
                    }
#line 7383 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 377:
#line 2531 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = (yyvsp[-1].nd);
                    }
#line 7391 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 378:
#line 2535 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = (yyvsp[-1].nd);
                    }
#line 7399 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 379:
#line 2541 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      local_nest(p);
                    }
#line 7407 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 380:
#line 2547 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_block(p,(yyvsp[-2].nd),(yyvsp[-1].nd));
                      local_unnest(p);
                    }
#line 7416 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 381:
#line 2554 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      if ((yyvsp[-1].nd)->car == (node*)NODE_YIELD) {
                        yyerror(p, "block given to yield");
                      }
                      else {
                        call_with_block(p, (yyvsp[-1].nd), (yyvsp[0].nd));
                      }
                      (yyval.nd) = (yyvsp[-1].nd);
                    }
#line 7430 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 382:
#line 2564 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_call(p, (yyvsp[-3].nd), (yyvsp[-1].id), (yyvsp[0].nd));
                    }
#line 7438 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 383:
#line 2568 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_call(p, (yyvsp[-4].nd), (yyvsp[-2].id), (yyvsp[-1].nd));
                      call_with_block(p, (yyval.nd), (yyvsp[0].nd));
                    }
#line 7447 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 384:
#line 2573 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_call(p, (yyvsp[-4].nd), (yyvsp[-2].id), (yyvsp[-1].nd));
                      call_with_block(p, (yyval.nd), (yyvsp[0].nd));
                    }
#line 7456 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 385:
#line 2580 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_fcall(p, (yyvsp[-1].id), (yyvsp[0].nd));
                    }
#line 7464 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 386:
#line 2584 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_call(p, (yyvsp[-3].nd), (yyvsp[-1].id), (yyvsp[0].nd));
                    }
#line 7472 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 387:
#line 2588 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_call(p, (yyvsp[-3].nd), (yyvsp[-1].id), (yyvsp[0].nd));
                    }
#line 7480 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 388:
#line 2592 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_call(p, (yyvsp[-2].nd), (yyvsp[0].id), 0);
                    }
#line 7488 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 389:
#line 2596 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_call(p, (yyvsp[-2].nd), intern("call",4), (yyvsp[0].nd));
                    }
#line 7496 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 390:
#line 2600 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_call(p, (yyvsp[-2].nd), intern("call",4), (yyvsp[0].nd));
                    }
#line 7504 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 391:
#line 2604 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_super(p, (yyvsp[0].nd));
                    }
#line 7512 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 392:
#line 2608 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_zsuper(p);
                    }
#line 7520 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 393:
#line 2612 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_call(p, (yyvsp[-3].nd), intern("[]",2), (yyvsp[-1].nd));
                    }
#line 7528 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 394:
#line 2618 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      local_nest(p);
                      (yyval.num) = p->lineno;
                    }
#line 7537 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 395:
#line 2624 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_block(p,(yyvsp[-2].nd),(yyvsp[-1].nd));
                      SET_LINENO((yyval.nd), (yyvsp[-3].num));
                      local_unnest(p);
                    }
#line 7547 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 396:
#line 2630 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      local_nest(p);
                      (yyval.num) = p->lineno;
                    }
#line 7556 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 397:
#line 2636 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_block(p,(yyvsp[-2].nd),(yyvsp[-1].nd));
                      SET_LINENO((yyval.nd), (yyvsp[-3].num));
                      local_unnest(p);
                    }
#line 7566 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 398:
#line 2646 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = cons(cons((yyvsp[-3].nd), (yyvsp[-1].nd)), (yyvsp[0].nd));
                    }
#line 7574 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 399:
#line 2652 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      if ((yyvsp[0].nd)) {
                        (yyval.nd) = cons(cons(0, (yyvsp[0].nd)), 0);
                      }
                      else {
                        (yyval.nd) = 0;
                      }
                    }
#line 7587 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 401:
#line 2666 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = list1(list3((yyvsp[-4].nd), (yyvsp[-3].nd), (yyvsp[-1].nd)));
                      if ((yyvsp[0].nd)) (yyval.nd) = append((yyval.nd), (yyvsp[0].nd));
                    }
#line 7596 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 403:
#line 2674 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                        (yyval.nd) = list1((yyvsp[0].nd));
                    }
#line 7604 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 406:
#line 2682 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = (yyvsp[0].nd);
                    }
#line 7612 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 408:
#line 2689 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = (yyvsp[0].nd);
                    }
#line 7620 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 416:
#line 2704 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = (yyvsp[0].nd);
                    }
#line 7628 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 417:
#line 2708 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_dstr(p, push((yyvsp[-1].nd), (yyvsp[0].nd)));
                    }
#line 7636 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 419:
#line 2715 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = append((yyvsp[-1].nd), (yyvsp[0].nd));
                    }
#line 7644 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 420:
#line 2721 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = list1((yyvsp[0].nd));
                    }
#line 7652 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 421:
#line 2725 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = p->lex_strterm;
                      p->lex_strterm = NULL;
                    }
#line 7661 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 422:
#line 2731 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      p->lex_strterm = (yyvsp[-2].nd);
                      (yyval.nd) = list2((yyvsp[-3].nd), (yyvsp[-1].nd));
                    }
#line 7670 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 423:
#line 2736 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = list1(new_literal_delim(p));
                    }
#line 7678 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 424:
#line 2740 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = list1(new_literal_delim(p));
                    }
#line 7686 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 425:
#line 2746 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                        (yyval.nd) = (yyvsp[0].nd);
                    }
#line 7694 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 426:
#line 2750 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_dxstr(p, push((yyvsp[-1].nd), (yyvsp[0].nd)));
                    }
#line 7702 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 427:
#line 2756 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                        (yyval.nd) = (yyvsp[0].nd);
                    }
#line 7710 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 428:
#line 2760 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_dregx(p, (yyvsp[-1].nd), (yyvsp[0].nd));
                    }
#line 7718 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 434:
#line 2777 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      parser_heredoc_info * inf = parsing_heredoc_inf(p);
                      inf->doc = push(inf->doc, new_str(p, "", 0));
                      heredoc_end(p);
                    }
#line 7728 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 435:
#line 2783 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      heredoc_end(p);
                    }
#line 7736 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 438:
#line 2793 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      parser_heredoc_info * inf = parsing_heredoc_inf(p);
                      inf->doc = push(inf->doc, (yyvsp[0].nd));
                      heredoc_treat_nextline(p);
                    }
#line 7746 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 439:
#line 2799 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = p->lex_strterm;
                      p->lex_strterm = NULL;
                    }
#line 7755 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 440:
#line 2805 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      parser_heredoc_info * inf = parsing_heredoc_inf(p);
                      p->lex_strterm = (yyvsp[-2].nd);
                      inf->doc = push(push(inf->doc, (yyvsp[-3].nd)), (yyvsp[-1].nd));
                    }
#line 7765 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 441:
#line 2813 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_words(p, list1((yyvsp[0].nd)));
                    }
#line 7773 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 442:
#line 2817 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_words(p, push((yyvsp[-1].nd), (yyvsp[0].nd)));
                    }
#line 7781 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 443:
#line 2824 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_sym(p, (yyvsp[0].id));
                    }
#line 7789 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 444:
#line 2828 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      p->lstate = EXPR_END;
                      (yyval.nd) = new_dsym(p, push((yyvsp[-1].nd), (yyvsp[0].nd)));
                    }
#line 7798 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 445:
#line 2835 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      p->lstate = EXPR_END;
                      (yyval.id) = (yyvsp[0].id);
                    }
#line 7807 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 450:
#line 2846 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.id) = new_strsym(p, (yyvsp[0].nd));
                    }
#line 7815 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 451:
#line 2850 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.id) = new_strsym(p, (yyvsp[0].nd));
                    }
#line 7823 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 452:
#line 2856 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_symbols(p, list1((yyvsp[0].nd)));
                    }
#line 7831 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 453:
#line 2860 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_symbols(p, push((yyvsp[-1].nd), (yyvsp[0].nd)));
                    }
#line 7839 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 456:
#line 2868 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = negate_lit(p, (yyvsp[0].nd));
                    }
#line 7847 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 457:
#line 2872 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = negate_lit(p, (yyvsp[0].nd));
                    }
#line 7855 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 458:
#line 2878 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_lvar(p, (yyvsp[0].id));
                    }
#line 7863 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 459:
#line 2882 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_ivar(p, (yyvsp[0].id));
                    }
#line 7871 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 460:
#line 2886 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_gvar(p, (yyvsp[0].id));
                    }
#line 7879 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 461:
#line 2890 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_cvar(p, (yyvsp[0].id));
                    }
#line 7887 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 462:
#line 2894 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_const(p, (yyvsp[0].id));
                    }
#line 7895 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 463:
#line 2900 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      assignable(p, (yyvsp[0].nd));
                    }
#line 7903 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 464:
#line 2906 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = var_reference(p, (yyvsp[0].nd));
                    }
#line 7911 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 465:
#line 2910 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_nil(p);
                    }
#line 7919 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 466:
#line 2914 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_self(p);
                    }
#line 7927 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 467:
#line 2918 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_true(p);
                    }
#line 7935 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 468:
#line 2922 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_false(p);
                    }
#line 7943 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 469:
#line 2926 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      if (!p->filename) {
                        p->filename = "(null)";
                      }
                      (yyval.nd) = new_str(p, p->filename, strlen(p->filename));
                    }
#line 7954 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 470:
#line 2933 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      char buf[16];

                      snprintf(buf, sizeof(buf), "%d", p->lineno);
                      (yyval.nd) = new_int(p, buf, 10);
                    }
#line 7965 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 473:
#line 2946 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = 0;
                    }
#line 7973 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 474:
#line 2950 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      p->lstate = EXPR_BEG;
                      p->cmd_start = TRUE;
                    }
#line 7982 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 475:
#line 2955 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = (yyvsp[-1].nd);
                    }
#line 7990 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 476:
#line 2966 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = (yyvsp[-1].nd);
                      p->lstate = EXPR_BEG;
                      p->cmd_start = TRUE;
                    }
#line 8000 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 477:
#line 2972 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = (yyvsp[-1].nd);
                    }
#line 8008 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 478:
#line 2978 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_args(p, (yyvsp[-5].nd), (yyvsp[-3].nd), (yyvsp[-1].id), 0, (yyvsp[0].id));
                    }
#line 8016 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 479:
#line 2982 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_args(p, (yyvsp[-7].nd), (yyvsp[-5].nd), (yyvsp[-3].id), (yyvsp[-1].nd), (yyvsp[0].id));
                    }
#line 8024 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 480:
#line 2986 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_args(p, (yyvsp[-3].nd), (yyvsp[-1].nd), 0, 0, (yyvsp[0].id));
                    }
#line 8032 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 481:
#line 2990 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_args(p, (yyvsp[-5].nd), (yyvsp[-3].nd), 0, (yyvsp[-1].nd), (yyvsp[0].id));
                    }
#line 8040 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 482:
#line 2994 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_args(p, (yyvsp[-3].nd), 0, (yyvsp[-1].id), 0, (yyvsp[0].id));
                    }
#line 8048 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 483:
#line 2998 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_args(p, (yyvsp[-5].nd), 0, (yyvsp[-3].id), (yyvsp[-1].nd), (yyvsp[0].id));
                    }
#line 8056 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 484:
#line 3002 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_args(p, (yyvsp[-1].nd), 0, 0, 0, (yyvsp[0].id));
                    }
#line 8064 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 485:
#line 3006 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_args(p, 0, (yyvsp[-3].nd), (yyvsp[-1].id), 0, (yyvsp[0].id));
                    }
#line 8072 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 486:
#line 3010 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_args(p, 0, (yyvsp[-5].nd), (yyvsp[-3].id), (yyvsp[-1].nd), (yyvsp[0].id));
                    }
#line 8080 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 487:
#line 3014 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_args(p, 0, (yyvsp[-1].nd), 0, 0, (yyvsp[0].id));
                    }
#line 8088 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 488:
#line 3018 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_args(p, 0, (yyvsp[-3].nd), 0, (yyvsp[-1].nd), (yyvsp[0].id));
                    }
#line 8096 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 489:
#line 3022 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_args(p, 0, 0, (yyvsp[-1].id), 0, (yyvsp[0].id));
                    }
#line 8104 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 490:
#line 3026 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_args(p, 0, 0, (yyvsp[-3].id), (yyvsp[-1].nd), (yyvsp[0].id));
                    }
#line 8112 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 491:
#line 3030 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_args(p, 0, 0, 0, 0, (yyvsp[0].id));
                    }
#line 8120 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 492:
#line 3034 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      local_add_f(p, 0);
                      (yyval.nd) = new_args(p, 0, 0, 0, 0, 0);
                    }
#line 8129 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 493:
#line 3041 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      yyerror(p, "formal argument cannot be a constant");
                      (yyval.nd) = 0;
                    }
#line 8138 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 494:
#line 3046 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      yyerror(p, "formal argument cannot be an instance variable");
                      (yyval.nd) = 0;
                    }
#line 8147 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 495:
#line 3051 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      yyerror(p, "formal argument cannot be a global variable");
                      (yyval.nd) = 0;
                    }
#line 8156 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 496:
#line 3056 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      yyerror(p, "formal argument cannot be a class variable");
                      (yyval.nd) = 0;
                    }
#line 8165 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 497:
#line 3063 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.id) = 0;
                    }
#line 8173 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 498:
#line 3067 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      local_add_f(p, (yyvsp[0].id));
                      (yyval.id) = (yyvsp[0].id);
                    }
#line 8182 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 499:
#line 3074 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_arg(p, (yyvsp[0].id));
                    }
#line 8190 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 500:
#line 3078 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = new_masgn(p, (yyvsp[-1].nd), 0);
                    }
#line 8198 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 501:
#line 3084 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = list1((yyvsp[0].nd));
                    }
#line 8206 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 502:
#line 3088 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = push((yyvsp[-2].nd), (yyvsp[0].nd));
                    }
#line 8214 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 503:
#line 3094 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      local_add_f(p, (yyvsp[-1].id));
                      (yyval.id) = (yyvsp[-1].id);
                    }
#line 8223 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 504:
#line 3101 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = cons(nsym((yyvsp[-1].id)), (yyvsp[0].nd));
                    }
#line 8231 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 505:
#line 3107 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = cons(nsym((yyvsp[-1].id)), (yyvsp[0].nd));
                    }
#line 8239 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 506:
#line 3113 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = list1((yyvsp[0].nd));
                    }
#line 8247 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 507:
#line 3117 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = push((yyvsp[-2].nd), (yyvsp[0].nd));
                    }
#line 8255 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 508:
#line 3123 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = list1((yyvsp[0].nd));
                    }
#line 8263 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 509:
#line 3127 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = push((yyvsp[-2].nd), (yyvsp[0].nd));
                    }
#line 8271 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 512:
#line 3137 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      local_add_f(p, (yyvsp[0].id));
                      (yyval.id) = (yyvsp[0].id);
                    }
#line 8280 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 513:
#line 3142 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      local_add_f(p, 0);
                      (yyval.id) = -1;
                    }
#line 8289 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 516:
#line 3153 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      local_add_f(p, (yyvsp[0].id));
                      (yyval.id) = (yyvsp[0].id);
                    }
#line 8298 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 517:
#line 3160 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.id) = (yyvsp[0].id);
                    }
#line 8306 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 518:
#line 3164 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      local_add_f(p, 0);
                      (yyval.id) = 0;
                    }
#line 8315 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 519:
#line 3171 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = (yyvsp[0].nd);
                      if (!(yyval.nd)) (yyval.nd) = new_nil(p);
                    }
#line 8324 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 520:
#line 3175 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {p->lstate = EXPR_BEG;}
#line 8330 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 521:
#line 3176 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      if ((yyvsp[-1].nd) == 0) {
                        yyerror(p, "can't define singleton method for ().");
                      }
                      else {
                        switch ((enum node_type)(int)(intptr_t)(yyvsp[-1].nd)->car) {
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
#line 8357 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 523:
#line 3202 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = (yyvsp[-1].nd);
                    }
#line 8365 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 524:
#line 3208 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = list1((yyvsp[0].nd));
                      NODE_LINENO((yyval.nd), (yyvsp[0].nd));
                    }
#line 8374 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 525:
#line 3213 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = push((yyvsp[-2].nd), (yyvsp[0].nd));
                    }
#line 8382 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 526:
#line 3219 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = cons((yyvsp[-2].nd), (yyvsp[0].nd));
                    }
#line 8390 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 527:
#line 3223 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = cons(new_sym(p, (yyvsp[-1].id)), (yyvsp[0].nd));
                    }
#line 8398 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 549:
#line 3267 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {yyerrok;}
#line 8404 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 551:
#line 3272 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      p->lineno++;
                      p->column = 0;
                    }
#line 8413 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 554:
#line 3279 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {yyerrok;}
#line 8419 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;

  case 555:
#line 3283 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1646  */
    {
                      (yyval.nd) = 0;
                    }
#line 8427 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
    break;


#line 8431 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/mrbgems/mruby-compiler/core/y.tab.c" /* yacc.c:1646  */
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
#line 3287 "/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/mrbgems/mruby-compiler/core/parse.y" /* yacc.c:1906  */

#define yylval  (*((YYSTYPE*)(p->ylval)))

static void
yyerror(parser_state *p, const char *s)
{
  char* c;
  int n;

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
  int n;

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

  c = (int)(intptr_t)n->car;

  if (c == NODE_NTH_REF) {
    yyerror_i(p, "can't set variable $%d", (int)(intptr_t)n->cdr);
  }
  else if (c == NODE_BACK_REF) {
    yyerror_i(p, "can't set variable $%c", (int)(intptr_t)n->cdr);
  }
  else {
    mrb_bug(p->mrb, "Internal error in backref_error() : n=>car == %S", mrb_fixnum_value(c));
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

    c = (int)(intptr_t)p->pb->car;
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
  if (c == '\r') {
    c = nextc(p);
    if (c != '\n') {
      pushback(p, c);
      return '\r';
    }
    return c;
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
  p->pb = cons((node*)(intptr_t)c, p->pb);
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
    list = push(list, (node*)(intptr_t)c0);
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
  int len = strlen(s);

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
      if (c < 0) return c;
      if (c == '\n') {
        p->lineno++;
        p->column = 0;
      }
      if (c == *s) break;
    }
    s++;
    if (peeks(p, s)) {
      int len = strlen(s);

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
  p->bidx = 0;
  return p->column - 1;
}

static void
tokadd(parser_state *p, int32_t c)
{
  char utf8[4];
  unsigned len;

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
  if (p->bidx+len <= MRB_PARSER_BUF_SIZE) {
    unsigned i;
    for (i = 0; i < len; i++) {
      p->buf[p->bidx++] = utf8[i];
    }
  }
}

static int
toklast(parser_state *p)
{
  return p->buf[p->bidx-1];
}

static void
tokfix(parser_state *p)
{
  int i = p->bidx, imax = MRB_PARSER_BUF_SIZE - 1;

  if (i > imax) {
    i = imax;
    yyerror(p, "string too long (truncated)");
  }
  p->buf[i] = '\0';
}

static const char*
tok(parser_state *p)
{
  return p->buf;
}

static int
toklen(parser_state *p)
{
  return p->bidx;
}

#define IS_ARG() (p->lstate == EXPR_ARG || p->lstate == EXPR_CMDARG)
#define IS_END() (p->lstate == EXPR_END || p->lstate == EXPR_ENDARG || p->lstate == EXPR_ENDFN)
#define IS_BEG() (p->lstate == EXPR_BEG || p->lstate == EXPR_MID || p->lstate == EXPR_VALUE || p->lstate == EXPR_CLASS)
#define IS_SPCARG(c) (IS_ARG() && space_seen && !ISSPACE(c))
#define IS_LABEL_POSSIBLE() ((p->lstate == EXPR_BEG && !cmd_state) || IS_ARG())
#define IS_LABEL_SUFFIX(n) (peek_n(p, ':',(n)) && !peek_n(p, ':', (n)+1))

static int
scan_oct(const int *start, int len, int *retlen)
{
  const int *s = start;
  int retval = 0;

  /* mrb_assert(len <= 3) */
  while (len-- && *s >= '0' && *s <= '7') {
    retval <<= 3;
    retval |= *s++ - '0';
  }
  *retlen = s - start;

  return retval;
}

static int32_t
scan_hex(const int *start, int len, int *retlen)
{
  static const char hexdigit[] = "0123456789abcdef0123456789ABCDEF";
  const int *s = start;
  int32_t retval = 0;
  char *tmp;

  /* mrb_assert(len <= 8) */
  while (len-- && *s && (tmp = (char*)strchr(hexdigit, *s))) {
    retval <<= 4;
    retval |= (tmp - hexdigit) & 15;
    s++;
  }
  *retlen = s - start;

  return retval;
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
    c = scan_hex(buf, i, &i);
    if (i == 0) {
      yyerror(p, "Invalid escape character syntax");
      return 0;
    }
  }
  return c;

  case 'u':     /* Unicode */
  {
    int buf[9];
    int i;

    /* Look for opening brace */
    i = 0;
    buf[0] = nextc(p);
    if (buf[0] < 0) goto eof;
    if (buf[0] == '{') {
      /* \u{xxxxxxxx} form */
      for (i=0; i<9; i++) {
        buf[i] = nextc(p);
        if (buf[i] < 0) goto eof;
        if (buf[i] == '}') {
          break;
        }
        else if (!ISXDIGIT(buf[i])) {
          yyerror(p, "Invalid escape character syntax");
          pushback(p, buf[i]);
          return 0;
        }
      }
    }
    else if (ISXDIGIT(buf[0])) {
      /* \uxxxx form */
      for (i=1; i<4; i++) {
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
    c = scan_hex(buf, i, &i);
    if (i == 0) {
      yyerror(p, "Invalid escape character syntax");
      return 0;
    }
    if (c < 0 || c > 0x10FFFF || (c & 0xFFFFF800) == 0xD800) {
      yyerror(p, "Invalid Unicode code point");
      return 0;
    }
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
  int nest_level = (intptr_t)p->lex_strterm->cdr->car;
  int beg = (intptr_t)p->lex_strterm->cdr->cdr->car;
  int end = (intptr_t)p->lex_strterm->cdr->cdr->cdr;
  parser_heredoc_info *hinf = (type & STR_FUNC_HEREDOC) ? parsing_heredoc_inf(p) : NULL;

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
          return tHEREDOC_END;
        }
      }
      if (c < 0) {
        char buf[256];
        snprintf(buf, sizeof(buf), "can't find heredoc delimiter \"%s\" anywhere before EOF", hinf->term);
        yyerror(p, buf);
        return 0;
      }
      yylval.nd = new_str(p, tok(p), toklen(p));
      return tHD_STRING_MID;
    }
    if (c < 0) {
      yyerror(p, "unterminated string meets end of file");
      return 0;
    }
    else if (c == beg) {
      nest_level++;
      p->lex_strterm->cdr->car = (node*)(intptr_t)nest_level;
    }
    else if (c == end) {
      nest_level--;
      p->lex_strterm->cdr->car = (node*)(intptr_t)nest_level;
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
        yylval.nd = new_str(p, tok(p), toklen(p));
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
        yylval.nd = new_str(p, tok(p), toklen(p));
        return tSTRING_MID;
      }
    }
    tokadd(p, c);
  }

  tokfix(p);
  p->lstate = EXPR_END;
  end_strterm(p);

  if (type & STR_FUNC_XQUOTE) {
    yylval.nd = new_xstr(p, tok(p), toklen(p));
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
    } else {
      dup = NULL;
    }
    if (enc) {
      encp = strndup(&enc, 1);
    } else {
      encp = NULL;
    }
    yylval.nd = new_regx(p, s, dup, encp);

    return tREGEXP;
  }

  yylval.nd = new_str(p, tok(p), toklen(p));
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

  yylval.nd = newnode;
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
        yylval.id = intern("**",2);
        p->lstate = EXPR_BEG;
        return tOP_ASGN;
      }
      pushback(p, c);
      c = tPOW;
    }
    else {
      if (c == '=') {
        yylval.id = intern_c('*');
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
        yylval.id = intern("<<",2);
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
        yylval.id = intern(">>",2);
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
    yylval.nd = new_str(p, tok(p), toklen(p));
    p->lstate = EXPR_END;
    return tCHAR;

  case '&':
    if ((c = nextc(p)) == '&') {
      p->lstate = EXPR_BEG;
      if ((c = nextc(p)) == '=') {
        yylval.id = intern("&&",2);
        p->lstate = EXPR_BEG;
        return tOP_ASGN;
      }
      pushback(p, c);
      return tANDOP;
    }
    else if (c == '=') {
      yylval.id = intern_c('&');
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
        yylval.id = intern("||",2);
        p->lstate = EXPR_BEG;
        return tOP_ASGN;
      }
      pushback(p, c);
      return tOROP;
    }
    if (c == '=') {
      yylval.id = intern_c('|');
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
      yylval.id = intern_c('+');
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
      yylval.id = intern_c('-');
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
    p->lstate = EXPR_END;
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
        yylval.nd = new_int(p, tok(p), 16);
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
        yylval.nd = new_int(p, tok(p), 2);
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
        yylval.nd = new_int(p, tok(p), 10);
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
          yylval.nd = new_int(p, tok(p), 8);
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
        yylval.nd = new_int(p, "0", 10);
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
      double d;
      char *endp;

      errno = 0;
      d = strtod(tok(p), &endp);
      if (d == 0 && endp == tok(p)) {
        yywarning_s(p, "corrupted float value %s", tok(p));
      }
      else if (errno == ERANGE) {
        yywarning_s(p, "float %s out of range", tok(p));
        errno = 0;
      }
      yylval.nd = new_float(p, tok(p));
      return tFLOAT;
    }
    yylval.nd = new_int(p, tok(p), 10);
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
      p->lstate = EXPR_ENDARG;
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
    if (IS_END() || ISSPACE(c)) {
      pushback(p, c);
      p->lstate = EXPR_BEG;
      return ':';
    }
    pushback(p, c);
    p->lstate = EXPR_FNAME;
    return tSYMBEG;

  case '/':
    if (IS_BEG()) {
      p->lex_strterm = new_strterm(p, str_regexp, '/', 0);
      return tREGEXP_BEG;
    }
    if ((c = nextc(p)) == '=') {
      yylval.id = intern_c('/');
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
      yylval.id = intern_c('^');
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
      yylval.id = intern_c('%');
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
      yylval.id = intern_cstr(tok(p));
      return tGVAR;

    case '-':
      tokadd(p, '$');
      tokadd(p, c);
      c = nextc(p);
      pushback(p, c);
      gvar:
      tokfix(p);
      yylval.id = intern_cstr(tok(p));
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
      yylval.nd = new_back_ref(p, c);
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
        yylval.nd = new_nth_ref(p, (int)n);
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
        if (p->bidx == 1) {
          yyerror(p, "incomplete instance variable syntax");
        }
        else {
          yyerror(p, "incomplete class variable syntax");
        }
        return 0;
      }
      else if (isdigit(c)) {
        if (p->bidx == 1) {
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
          p->lstate = EXPR_BEG;
          nextc(p);
          tokfix(p);
          yylval.id = intern_cstr(tok(p));
          return tLABEL;
        }
      }
      if (p->lstate != EXPR_DOT) {
        const struct kwtable *kw;

        /* See if it is a reserved word.  */
        kw = mrb_reserved_word(tok(p), toklen(p));
        if (kw) {
          enum mrb_lex_state_enum state = p->lstate;
          yylval.num = p->lineno;
          p->lstate = kw->state;
          if (state == EXPR_FNAME) {
            yylval.id = intern_cstr(kw->name);
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

      yylval.id = ident;
#if 0
      if (last_state != EXPR_DOT && islower(tok(p)[0]) && lvar_defined(ident)) {
        p->lstate = EXPR_END;
      }
#endif
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
  if ((int)(intptr_t)p->tree->car != NODE_SCOPE) return;
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
  struct mrb_jmpbuf buf;
  p->jmp = &buf;

  MRB_TRY(p->jmp) {

    p->cmd_start = TRUE;
    p->in_def = p->in_single = 0;
    p->nerr = p->nwarn = 0;
    p->lex_strterm = NULL;

    parser_init_cxt(p, c);
    yyparse(p);
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
#ifndef MRB_DISBLE_STDIO
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
  mrb_free(mrb, cxt->syms);
  mrb_free(mrb, cxt);
}

MRB_API const char*
mrbc_filename(mrb_state *mrb, mrbc_context *c, const char *s)
{
  if (s) {
    int len = strlen(s);
    char *p = (char *)mrb_alloca(mrb, len + 1);

    memcpy(p, s, len + 1);
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
      p->current_filename_index = i;
      return;
    }
  }

  p->current_filename_index = p->filename_table_length++;

  new_table = (mrb_sym*)parser_palloc(p, sizeof(mrb_sym) * p->filename_table_length);
  if (p->filename_table) {
    memmove(new_table, p->filename_table, sizeof(mrb_sym) * p->filename_table_length);
  }
  p->filename_table = new_table;
  p->filename_table[p->filename_table_length - 1] = sym;
}

MRB_API char const*
mrb_parser_get_filename(struct mrb_parser_state* p, uint16_t idx) {
  if (idx >= p->filename_table_length) { return NULL; }
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
mrb_parse_nstring(mrb_state *mrb, const char *s, int len, mrbc_context *c)
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

static mrb_value
load_exec(mrb_state *mrb, parser_state *p, mrbc_context *c)
{
  struct RClass *target = mrb->object_class;
  struct RProc *proc;
  mrb_value v;
  unsigned int keep = 0;

  if (!p) {
    return mrb_undef_value();
  }
  if (!p->tree || p->nerr) {
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
      mrb->exc = mrb_obj_ptr(mrb_exc_new_str_lit(mrb, E_SYNTAX_ERROR, "syntax error"));
      mrb_parser_free(p);
      return mrb_undef_value();
    }
  }
  proc = mrb_generate_code(mrb, p);
  mrb_parser_free(p);
  if (proc == NULL) {
    mrb->exc = mrb_obj_ptr(mrb_exc_new_str_lit(mrb, E_SCRIPT_ERROR, "codegen error"));
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
  proc->target_class = target;
  if (mrb->c->ci) {
    mrb->c->ci->target_class = target;
  }
  v = mrb_toplevel_run_keep(mrb, proc, keep);
  if (mrb->exc) return mrb_nil_value();
  return v;
}

#ifndef MRB_DISABLE_STDIO
MRB_API mrb_value
mrb_load_file_cxt(mrb_state *mrb, FILE *f, mrbc_context *c)
{
  return load_exec(mrb, mrb_parse_file(mrb, f, c), c);
}

MRB_API mrb_value
mrb_load_file(mrb_state *mrb, FILE *f)
{
  return mrb_load_file_cxt(mrb, f, NULL);
}
#endif

MRB_API mrb_value
mrb_load_nstring_cxt(mrb_state *mrb, const char *s, int len, mrbc_context *c)
{
  return load_exec(mrb, mrb_parse_nstring(mrb, s, len, c), c);
}

MRB_API mrb_value
mrb_load_nstring(mrb_state *mrb, const char *s, int len)
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

#endif

void
mrb_parser_dump(mrb_state *mrb, node *tree, int offset)
{
#ifndef MRB_DISABLE_STDIO
  int nodetype;

  if (!tree) return;
  again:
  dump_prefix(tree, offset);
  nodetype = (int)(intptr_t)tree->car;
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
    printf("NODE_BLOCK:\n");
    goto block;

  case NODE_BLOCK:
    block:
    printf("NODE_BLOCK:\n");
    tree = tree->cdr;
    if (tree->car) {
      node *n = tree->car;

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
            printf("%s=", mrb_sym2name(mrb, sym(n2->car->car)));
            mrb_parser_dump(mrb, n2->car->cdr, 0);
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
        dump_prefix(n, offset+1);
        printf("blk=&%s\n", mrb_sym2name(mrb, sym(n)));
      }
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
    printf("NODE_CALL:\n");
    mrb_parser_dump(mrb, tree->car, offset+1);
    dump_prefix(tree, offset+1);
    printf("method='%s' (%d)\n",
        mrb_sym2name(mrb, sym(tree->cdr->car)),
        (int)(intptr_t)tree->cdr->car);
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
    printf("op='%s' (%d)\n", mrb_sym2name(mrb, sym(tree->car)), (int)(intptr_t)tree->car);
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
    printf("NODE_BACK_REF: $%c\n", (int)(intptr_t)tree);
    break;

  case NODE_NTH_REF:
    printf("NODE_NTH_REF: $%d\n", (int)(intptr_t)tree);
    break;

  case NODE_ARG:
    printf("NODE_ARG %s\n", mrb_sym2name(mrb, sym(tree)));
    break;

  case NODE_BLOCK_ARG:
    printf("NODE_BLOCK_ARG:\n");
    mrb_parser_dump(mrb, tree, offset+1);
    break;

  case NODE_INT:
    printf("NODE_INT %s base %d\n", (char*)tree->car, (int)(intptr_t)tree->cdr->car);
    break;

  case NODE_FLOAT:
    printf("NODE_FLOAT %s\n", (char*)tree);
    break;

  case NODE_NEGATE:
    printf("NODE_NEGATE\n");
    mrb_parser_dump(mrb, tree, offset+1);
    break;

  case NODE_STR:
    printf("NODE_STR \"%s\" len %d\n", (char*)tree->car, (int)(intptr_t)tree->cdr);
    break;

  case NODE_DSTR:
    printf("NODE_DSTR\n");
    dump_recur(mrb, tree, offset+1);
    break;

  case NODE_XSTR:
    printf("NODE_XSTR \"%s\" len %d\n", (char*)tree->car, (int)(intptr_t)tree->cdr);
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
    dump_prefix(tree, offset);
    printf("opt: %s\n", (char*)tree->cdr->cdr->cdr);
    break;

  case NODE_SYM:
    printf("NODE_SYM :%s\n", mrb_sym2name(mrb, sym(tree)));
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
      node *n = tree->car;

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
            printf("%s=", mrb_sym2name(mrb, sym(n2->car->car)));
            mrb_parser_dump(mrb, n2->car->cdr, 0);
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
      if (n->cdr) {
        dump_prefix(n, offset+1);
        printf("blk=&%s\n", mrb_sym2name(mrb, sym(n->cdr)));
      }
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
      node *n = tree->car;

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
            printf("%s=", mrb_sym2name(mrb, sym(n2->car->car)));
            mrb_parser_dump(mrb, n2->car->cdr, 0);
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
        dump_prefix(n, offset+1);
        printf("blk=&%s\n", mrb_sym2name(mrb, sym(n)));
      }
    }
    tree = tree->cdr;
    mrb_parser_dump(mrb, tree->car, offset+1);
    break;

  case NODE_POSTEXE:
    printf("NODE_POSTEXE:\n");
    mrb_parser_dump(mrb, tree, offset+1);
    break;

  case NODE_HEREDOC:
    printf("NODE_HEREDOC:\n");
    mrb_parser_dump(mrb, ((parser_heredoc_info*)tree)->doc, offset+1);
    break;

  default:
    printf("node type: %d (0x%x)\n", nodetype, (unsigned)nodetype);
    break;
  }
#endif
}
