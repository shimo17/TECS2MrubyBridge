EV3RT_PATH="/home/shimo/TECS2MrubyBridhePlugin/hr-tecs"

MRuby::CrossBuild.new('ARM') do |conf|

  toolchain :gcc
  EV3_RT_INCLUDES = %w(include
                       .
                       arch
                       target/ev3_gcc
                       target/ev3_gcc/api
                       target/ev3_gcc/api/include
                       target/ev3_gcc/dmloader/app/include
                       target/ev3_gcc/dmloader/include
                       target/ev3_gcc/drivers/bluetooth/btstack/include
                       target/ev3_gcc/drivers/soc/AM1808_StarterWare_1_00_03_03/include/hw
                       target/ev3_gcc/drivers/bluetooth/include
                       target/ev3_gcc/drivers/brick/include
                       target/ev3_gcc/drivers/common/include
                       target/ev3_gcc/drivers/common/virtual-linux-kernel/arch/arm/include
                       target/ev3_gcc/drivers/common/virtual-linux-kernel/include
                       target/ev3_gcc/drivers/console/include
                       target/ev3_gcc/drivers/fatfs/include
                       target/ev3_gcc/drivers/gpio/include
                       target/ev3_gcc/drivers/lcd/include
                       target/ev3_gcc/drivers/lcd/linux/include
                       target/ev3_gcc/drivers/linux/arch/arm/include
                       target/ev3_gcc/drivers/linux/arch/arm/mach-davinci/include
                       target/ev3_gcc/drivers/linux/include
                       target/ev3_gcc/drivers/motor/include
                       target/ev3_gcc/drivers/newlib/include
                       target/ev3_gcc/drivers/sensor/analog/include
                       target/ev3_gcc/drivers/sensor/uart/d_uart/Linuxmod_AM1808/pru-firmware-05-31-2011-1423-v3.0/pru/hal/common/include
                       target/ev3_gcc/drivers/sensor/uart/d_uart/Linuxmod_AM1808/pru-firmware-05-31-2011-1423-v3.0/pru/hal/uart/include
                       target/ev3_gcc/drivers/sensor/uart/include
                       target/ev3_gcc/drivers/soc/AM1808_StarterWare_1_00_03_03/include
                       target/ev3_gcc/drivers/soc/include
                       target/ev3_gcc/drivers/sound/include
                       target/ev3_gcc/kernel_mod/include
                       target/ev3_gcc/pil/include
                       target/ev3_gcc/platform/include
                       target/ev3_gcc/TLSF-2.4.6/include
                       sdk/common/ev3api/include
                       syssvc
                       arch/arm_gcc/am1808
                       arch/arm_gcc/common
                       arch/gcc
                       workspace/mruby_call
                       include/mruby)

  conf.cc.defines = %w(DISABLE_STDIO)
  conf.bins = []

  [conf.cc, conf.objc, conf.asm].each do |cc|
    cc.command_requirement = :WINDOWS_STYLE_PATH
    cc.command = ENV['CC'] || 'arm-none-eabi-gcc'
    cc.flags = [ENV['CFLAGS'] || %w(-g -std=gnu99 -O3 -Wall -Werror-implicit-function-declaration)]
    cc.include_paths = cc.include_paths << EV3_RT_INCLUDES.map{|inc| File.join(EV3RT_PATH, inc)},

    cc.defines = %w(DISABLE_GEMS)
    cc.option_include_path = '-I%s'
    cc.option_define = '-D%s'
    cc.compile_options = '%{flags} -MMD -o %{outfile} -c %{infile}'
  end

  [conf.cxx].each do |cxx|
    cxx.command_requirement = :WINDOWS_STYLE_PATH
    cxx.command = ENV['CXX'] || 'arm-none-eabi-g++'
    cxx.flags = [ENV['CXXFLAGS'] || ENV['CFLAGS'] || %w(-g -O3 -Wall -Werror-implicit-function-declaration)]
    cxx.include_paths = cc.include_paths.dup
    cxx.defines = %w(DISABLE_GEMS)
    cxx.option_include_path = '-I%s'
    cxx.option_define = '-D%s'
    cxx.compile_options = '%{flags} -MMD -o %{outfile} -c %{infile}'
  end

  conf.linker do |linker|
    linker.command_requirement = :WINDOWS_STYLE_PATH
    linker.command = ENV['LD'] || 'arm-none-eabi-gcc'
    linker.flags = [ENV['LDFLAGS'] || %w()]
    linker.libraries = %w(m)
    linker.library_paths = []
    linker.option_library = '-l%s'
    linker.option_library_path = '-L%s'
    linker.link_options = '%{flags} -o %{outfile} %{objs} %{flags_before_libraries} %{libs} %{flags_after_libraries}'
  end

  # Archiver settings
  conf.archiver do |archiver|
    archiver.command_requirement = :WINDOWS_STYLE_PATH
    archiver.command = ENV['AR'] || 'arm-none-eabi-ar'
  end
  #
  #   conf.cc.flags << "-m32"
  #   conf.linker.flags << "-m32"
    #
  # Use standard print/puts/p
  conf.gem :core => "mruby-print"
  # Use extended toplevel object (main) methods
  conf.gem :core => "mruby-toplevel-ext"
  # Use standard Math module
  #  conf.gem :core => "mruby-math"
  # Use mruby-compiler to build other mrbgems
  conf.gem :core => "mruby-compiler"
  conf.gem :core => "mruby-array-ext"
  conf.gem :core => "mruby-lcd"
  # =>  conf.gem :core => "mruby-lcd"
  conf.build_mrbtest_lib_only
=begin
  # Use standard Kernel#sprintf method
  conf.gem :core => "mruby-sprintf"
  # Use standard Time class
  # conf.gem :core => "mruby-time"
  # Use standard Struct class
  conf.gem :core => "mruby-struct"
  # Use extensional Enumerable module
  conf.gem :core => "mruby-enum-ext"
  # Use extensional String class
  #conf.gem :core => "mruby-string-ext"
  # Use extensional Numeric class
  conf.gem :core => "mruby-numeric-ext"
  # Use extensional Array class
  conf.gem :core => "mruby-array-ext"
  # Use extensional Hash class
  conf.gem :core => "mruby-hash-ext"
  # Use extensional Range class
  conf.gem :core => "mruby-range-ext"
  # Use extensional Proc class
  conf.gem :core => "mruby-proc-ext"
  # Use extensional Symbol class
  conf.gem :core => "mruby-symbol-ext"
  # Use Random class
  # conf.gem :core => "mruby-random"
  # Use extensional Object class
  conf.gem :core => "mruby-object-ext"
  # Use ObjectSpace class
  conf.gem :core => "mruby-objectspace"
  # Use Fiber class
  conf.gem :core => "mruby-fiber"
  # Use Enumerator class (require mruby-fiber)
  conf.gem :core => "mruby-enumerator"
  # Use Enumerable::Lazy classlin (require mruby-enumerator)
  conf.gem :core => "mruby-enum-lazy"
  # Generate mirb command
  # conf.gem :core => "mruby-bin-mirb"
  # Generate mruby command
  # conf.gem :core => "mruby-bin-mruby"
  # Generate mruby-strip command
  # conf.gem :core => "mruby-bin-strip"
=end
  #conf.gem :core => "mruby-tecs"
  #conf.gem :core => "mruby-bin-mruby"
  #conf.gem :core => "mruby-ev3-motor"
end
