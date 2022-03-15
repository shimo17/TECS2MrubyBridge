MRUBY_CFLAGS = -g -std=gnu99 -O3 -Wall -Werror-implicit-function-declaration -Wdeclaration-after-statement -Wwrite-strings -I"/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/include" -I../hr-tecs/target/ev3_gcc/api/include \
                              -I../hr-tecs/include \
                              -I../hr-tecs/target/ev3_gcc \
                              -I../hr-tecs/arch/arm_gcc/am1808 \
                              -I../hr-tecs/arch \
                              -I../hr-tecs/arch/arm_gcc/common \
                              -I../hr-tecs/workspace/bluetooth
MRUBY_LDFLAGS =  -L/home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/lib
MRUBY_LDFLAGS_BEFORE_LIBS = 
MRUBY_LIBS = -lmruby -lm
MRUBY_LIBMRUBY_PATH = /home/shimo/mruby-on-ev3rt+tecs_package-beta1.0.1/mruby/build/host/lib/libmruby.a
