
	mruby on EV3RT+TECS beta1.0 
	�i2016�N5��10���j

mruby��p����LEGO Mindstorm EV3 (EV3) �J���p�b�P�[�W�̃x�[�^�łł��B
TOPPERS/HRP2�J�[�l����TECS��p����LEGO Mindstorm EV3�𓮂������߂̊�{�p�b�P�[�W���܂݂܂��B

�y����m�F���z
�EOS
Windows 7 Professional 64bit
Windows 8
Windows 8.1
Windows 10

�Ecygwin
CYGWIN_NT-6.1-WOW64 1.7.17(0.262/5/3) 2012-10-19 14:39 i686 Cygwin

�ERuby
ruby 1.9.3p327 (2012-11-10 revision 37606) [i386-cygwin]
ruby 2.2.3p173 (2015-08-18 revision 51636) [x86_64-cygwin]

�EGNU Make
GNU Make 3.82.90
GNU Make 4.1

��Ruby�����GNU Make�́Acygwin�C���X�g�[�����ɓ������Ă��������B

�E�N���X�R���p�C��
arm-none-eabi-gcc.exe (GNU Tools for ARM Embedded Processors) 4.8.3 20140228 (release) [ARM/embedded-4_8-branch revision 208322]

���N���X�R���p�C���͈ȉ���URL���瓱�����s���Ă��������B
https://launchpad.net/gcc-arm-embedded/4.8/4.8-2014-q1-update

�Emkimage
Windows�p�o�C�i���͖{�p�b�P�[�W�ɓ������Ă���܂����A�ȉ��������ł��܂��B
http://www.compulab.co.il/workspace/mediawiki/index.php5/U-Boot_images


�y�T���v���v���O�����z
�T���v���v���O�����́A(mruby-on-ev3rt+tecss)/hr-tecs/workspace/mruby_app�f�B���N�g���ɂ���܂��B
EV3�����̃A�v���P�[�V�������쐬�����T���v���A�v���P�[�V�����̓��e�͎��̂Ƃ���ł��B

(��) �������ꂽ�T���v���͓���m�F�ɃV���A���P�[�u���ڑ���K�v�Ƃ��܂���B
�T���v���v���O�����̎����̍ۂɎg�p�����|�[�g���L�ڂ��Ă��܂��B
����m�F�̍ۂ́AEV3�̃Z���T����уA�N�`���G�[�^�̐ڑ��|�[�g���m�F���Ă��������B

��{�T���v��

���ׂẴT���v������
�X�^�[�g��ʂŃA�v���P�[�V�����̋N���ƃV���b�g�_�E����I���ł���B
BACK�{�^���ŃX�^�[�g��ʂɖ߂�B

�Ebattery_sample.rb
�o�b�e���̓d���A�d�����擾��LCD�ɕ\������v���O����

�Ebutton_sample.rb
�����ꂽ�{�^����F�����ALCD�ɕ\������v���O����

�Ecolor_sample.rb
�J���[�Z���T�̒l��LCD�ɕ\������v���O����
�J���[�Z���T�i:port_4�j

�Ecolor_sample2.rb
�J���[�Z���T�ŐF�����ʁi���A�A�A�΁A���F�A�ԁA���A���j��
LCD�ŕ\������v���O����
�J���[�Z���T�i:port_4�j

�Egyro_sample.rb
�W���C���Z���T�̒l�i�p�x�j��LCD�ɕ\������v���O����
�W���C���Z���T�i:port_4�j

�Elcd_sample.rb
LCD�R���\�[���ɏo��(LCD.puts)������v���O�����F�R���\�[�����[�h
���A�E�A�����{�^���ŉ����ꂽ�{�^���R���\�[���ɕ\��
��A���̃{�^���ŃR���\�[�����ړ�
�߂�{�^���������Ńv���O�����I��

�Elcd_sample2.rb
LCD�̎w�肵�����W�i�t�H���g�j�ɕ\���iLCD.draw�j����v���O�����Fdraw���[�h

�Elcd_sample3.rb�F
LCD.print�𗘗p�����̃v���O�����F�R���\�[�����[�h
������200�~�����ƂɁA�\�����邷��B

�f�t�H���g�́Amedium�t�H���g
���L�̗p�ɕύX�����small�t�H���g�ɕύX�ł���
   #LCD.font=:medium
    LCD.font=:small

�Eled_sample.rb
�����ꂽ�{�^���ɉ������A�{�̂�LED�̐F��ύX����v���O����

���{�^���F��
�E�{�^���F�I�����W
��{�^���F��
���{�^���F����
�����{�^���F�I�����W

�Emotor_sample.rb
�����g�Z���T�̒l�i�����j��15cm�ȏ�̂Ƃ��O�i���A
15cm�����̎��͒�~����

�����[�^�i:port_a�j
�E���[�^�i:port_b�j
�����g�Z���T�i:port_3�j

�Emotor_sample2.rb
���[�^(rotate, reset, counts)�T���v���v���O����

���[�^�i:port_a�j

�Espeaker_sample.rb
�z��Œ�`���ꂽ���Ə��Ԃɖ炷�v���O����

�Espeaker_sample2.rb
�����ꂽ�{�^���ɉ������A����炷�v���O����

���{�^���FC4
�E�{�^���FC5
��{�^���FC6
���{�^���FF4
�����{�^���FF5

�Etouch_sample.rb
�^�b�`�Z���T�̉����ꂽ�񐔂�LCD�ɕ\������v���O����
�^�b�`�Z���T�i:port_4�j

�y����m�F�菇�z
�{�p�b�P�[�W�́A���̗���œ���m�F���s���܂��B
1. (�R���s���[�^) mruby�EEV3RT+TECS�EEV3�h���C�o�E�A�v���P�[�V�����Ȃǂ��N���X�R���p�C���ɂ��r���h
2. (�R���s���[�^) �r���h���ʕ�(uImage) �����̂܂܂̖��O��SD�J�[�h�̃��[�g�f�B���N�g���փR�s�[
3. (EV3) SD�J�[�h��EV3��SD�X���b�g�ɍ������݁A�d���������EV3RT+TECS���N���A
4. (EV3) Enter�{�^���iEV3�{�̂̐^�񒆂̃{�^���j��������mruby�v���O�������N��

1-1. mruby�̃r���h
$ cd (mruby-on-ev3rt+tecs)/mruby
$ make
mruby�f�B���N�g����make�����s����ƁAmruby���r���h����܂��B

mruby�̃N���[���͈ȉ��̃R�}���h�ōs���܂��B
$ make clean

1-2. EV3RT+TECS�EEV3�h���C�o�E�A�v���P�[�V�����̃r���h
�{�p�b�P�[�W�ł́A�J�����@�Ƃ���SD��p������@��Bluetooth��p������@�������
���B
1-2-1. SD��p������@
$ cd (mruby-on-ev3rt+tecs)/workspace/sd/

�E���s����mruby�v���O�����̑I��
(mruby-on-ev3rt+tecs)/workspace/sd/Makefile

���L������s������mruby�v���O������I��

#  mruby�̃A�v���P�[�V�����t�@�C����
#APP_RB = battery_sample.rb
#APP_RB = button_sample.rb
#APP_RB = color_sample.rb
#APP_RB = color_sample2.rb
#APP_RB = gyro_sample.rb
#APP_RB = lcd_sample.rb
#APP_RB = lcd_sample2.rb
#APP_RB = led_sample.rb
#APP_RB = motor_sample.rb
#APP_RB = motor_sample2.rb
#APP_RB = speaker_sample.rb
#APP_RB = speaker_sample2.rb
APP_RB = touch_sample.rb

$ make tecs
$ make depend
$ make

�J�����g�f�B���N�g�����T���v���A�v���P�[�V�����̃f�B���N�g���Ɉړ����Amake���s�����ƂŃR���p�C�����s���܂��B
*make tecs��make depend�̎��s�́A���߂̈��݂̂ł悢�B

2. SD�J�[�h�փR�s�[
�f�t�H���g�ł́Acygwin���g�p����Ă��邱�Ƃ�z��̏�ŁAE�h���C�u�ɃR�s�[����܂��B
��̓I�ɂ́A�ȉ��̃R�}���h�����s����܂��B
$ cp uImage /cygdrive/e/

�h���C�u��ύX����ɂ́A�T���v���R�[�h��Makefile��ҏW���܂��B
Makefile���� "SD_DIR" �Ō������āA�ϐ���SD�J�[�h�h���C�u���w�肵�Ă��������B

#
# SD�̃h���C�u�������w��
#
SD_DIR = /cygdrive/e/

�A�v���P�[�V�����f�B���N�g���̃N���[���͈ȉ��̃R�}���h�ōs���܂��B
�ETECS�̐��������c��
$ make clean
�E���ׂĂ̐��������폜 (����)
$ make realclean

1-2-2. Bluetooth��p�������@
    �ڍׂ́Adoc/mruby_on_ev3rt+tecs_build.pdf ���Q�Ƃ��Ă��������B

�y�֘A���z
+---------------------+     +-------------------------+     +----------------------+    +-------------+
|                     |     |                         |     |                      |    |             |
| mruby application   |     | mruby class             |     | mruby => TECS Bridge |    |   TECS      |
|                     |-----| Wrapper for TECS Driver |====>|                      |----|>  Drivers   |
|                     |     |                         |     |                      |    |             |
|                     |     |                         |     |                      |    |             |
+---------------------+     +-------------------------+     +----------------------+    +-------------+
EV3�̃h���C�o�́ATECS�R���|�[�l���g (C����) �Ŏ�������Ă��܂��B
mruby����EV3�h���C�o��mruby=>TECS Bridge�̎d�g�݂𗘗p���ČĂяo����܂��B
TECS�����mruby=>TECS Bridge�Ɋւ������TOPPERS��Web�T�C�g���Q�Ƃ��Ă��������B
http://www.toppers.jp/tecs.html

�y�⑫�F�V���A���P�[�u���Ɋւ��āz
�V���A���P�[�u����EV3�{�̂�Port1���g�p���܂��B
(�V���A���Ɏg�p���邽�߁A����Port1�ɃZ���T�����t���ł��Ȃ����񂪂���܂�)
�R���s���[�^�ւ̐ڑ��ɂ�USB-Serial�ϊ��P�[�u�������EV3-Serial�ϊ��R�l�N�^���K�v�ƂȂ�܂��B
����m�F�ł͈ȉ��̃V���A���P�[�u������уR�l�N�^���g�p���܂����B

OLIMEX USB�V���A���ϊ��P�[�u��(�R����)
��2015�N6�����݁AWindows 8�Ŏg�p���ł��܂��� (�h���C�o������܂���)
http://strawberry-linux.com/catalog/items?code=15076

Breadboard Connector Kit for NXT(BCK01)
��NXT�p�ł���EV3�ɂ��g�p�\�ł�
http://www.technologia.co.jp/70_4600.html

��L�V���A���P�[�u�������Connector Kit���g�p����ꍇ�A���ꂼ��ȉ����Ή����܂��B
��(GND) - GRND (2 or 3)
��(TX) - SCL (5)
��(RX) - SDA (6)
baud rate�� 115200 �ł��B
