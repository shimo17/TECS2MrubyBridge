MRUBY_CFLAGS = -g -std=gnu99 -O3 -Wall -Werror-implicit-function-declaration -Wdeclaration-after-statement -Wwrite-strings -g3 -O0 -DMRB_DEBUG -I./include -I./src -I./mrbgems/mruby-compiler/core -I./mrbgems/mruby-random/src
MRUBY_LDFLAGS =  -L/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/lib
MRUBY_LDFLAGS_BEFORE_LIBS = 
MRUBY_LIBS = -lmruby -lm
