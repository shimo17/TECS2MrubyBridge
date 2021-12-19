
	mruby on EV3RT+TECS beta1.0 
	（2016年5月10日）

mrubyを用いたLEGO Mindstorm EV3 (EV3) 開発パッケージのベータ版です。
TOPPERS/HRP2カーネルとTECSを用いてLEGO Mindstorm EV3を動かすための基本パッケージを含みます。

【動作確認環境】
・OS
Windows 7 Professional 64bit
Windows 8
Windows 8.1
Windows 10

・cygwin
CYGWIN_NT-6.1-WOW64 1.7.17(0.262/5/3) 2012-10-19 14:39 i686 Cygwin

・Ruby
ruby 1.9.3p327 (2012-11-10 revision 37606) [i386-cygwin]
ruby 2.2.3p173 (2015-08-18 revision 51636) [x86_64-cygwin]

・GNU Make
GNU Make 3.82.90
GNU Make 4.1

※RubyおよびGNU Makeは、cygwinインストール時に導入してください。

・クロスコンパイラ
arm-none-eabi-gcc.exe (GNU Tools for ARM Embedded Processors) 4.8.3 20140228 (release) [ARM/embedded-4_8-branch revision 208322]

※クロスコンパイラは以下のURLから導入を行ってください。
https://launchpad.net/gcc-arm-embedded/4.8/4.8-2014-q1-update

・mkimage
Windows用バイナリは本パッケージに同梱しておりますが、以下から入手できます。
http://www.compulab.co.il/workspace/mediawiki/index.php5/U-Boot_images


【サンプルプログラム】
サンプルプログラムは、(mruby-on-ev3rt+tecss)/hr-tecs/workspace/mruby_appディレクトリにあります。
EV3向けのアプリケーションを作成したサンプルアプリケーションの内容は次のとおりです。

(※) が書かれたサンプルは動作確認にシリアルケーブル接続を必要としません。
サンプルプログラムの実装の際に使用したポートも記載しています。
動作確認の際は、EV3のセンサおよびアクチュエータの接続ポートを確認してください。

基本サンプル

すべてのサンプル共通
スタート画面でアプリケーションの起動とシャットダウンを選択できる。
BACKボタンでスタート画面に戻る。

・battery_sample.rb
バッテリの電流、電圧を取得しLCDに表示するプログラム

・button_sample.rb
押されたボタンを認識し、LCDに表示するプログラム

・color_sample.rb
カラーセンサの値をLCDに表示するプログラム
カラーセンサ（:port_4）

・color_sample2.rb
カラーセンサで色を識別（黒、、青、緑、黄色、赤、白、茶）し
LCDで表示するプログラム
カラーセンサ（:port_4）

・gyro_sample.rb
ジャイロセンサの値（角度）をLCDに表示するプログラム
ジャイロセンサ（:port_4）

・lcd_sample.rb
LCDコンソールに出力(LCD.puts)をするプログラム：コンソールモード
左、右、中央ボタンで押されたボタンコンソールに表示
上、下のボタンでコンソールを移動
戻るボタン長押しでプログラム終了

・lcd_sample2.rb
LCDの指定した座標（フォント）に表示（LCD.draw）するプログラム：drawモード

・lcd_sample3.rb：
LCD.printを利用したのプログラム：コンソールモード
数字を200ミリごとに、表示するする。

デフォルトは、mediumフォント
下記の用に変更するとsmallフォントに変更できる
   #LCD.font=:medium
    LCD.font=:small

・led_sample.rb
押されたボタンに応じた、本体のLEDの色を変更するプログラム

左ボタン：緑
右ボタン：オレンジ
上ボタン：赤
下ボタン：消灯
中央ボタン：オレンジ

・motor_sample.rb
超音波センサの値（距離）が15cm以上のとき前進し、
15cm未満の時は停止する

左モータ（:port_a）
右モータ（:port_b）
超音波センサ（:port_3）

・motor_sample2.rb
モータ(rotate, reset, counts)サンプルプログラム

モータ（:port_a）

・speaker_sample.rb
配列で定義された音と順番に鳴らすプログラム

・speaker_sample2.rb
押されたボタンに応じた、音を鳴らすプログラム

左ボタン：C4
右ボタン：C5
上ボタン：C6
下ボタン：F4
中央ボタン：F5

・touch_sample.rb
タッチセンサの押された回数をLCDに表示するプログラム
タッチセンサ（:port_4）

【動作確認手順】
本パッケージは、次の流れで動作確認を行います。
1. (コンピュータ) mruby・EV3RT+TECS・EV3ドライバ・アプリケーションなどをクロスコンパイラによりビルド
2. (コンピュータ) ビルド成果物(uImage) をそのままの名前でSDカードのルートディレクトリへコピー
3. (EV3) SDカードをEV3のSDスロットに差し込み、電源を入れるとEV3RT+TECSが起動、
4. (EV3) Enterボタン（EV3本体の真ん中のボタン）を押すとmrubyプログラムが起動

1-1. mrubyのビルド
$ cd (mruby-on-ev3rt+tecs)/mruby
$ make
mrubyディレクトリでmakeを実行すると、mrubyがビルドされます。

mrubyのクリーンは以下のコマンドで行えます。
$ make clean

1-2. EV3RT+TECS・EV3ドライバ・アプリケーションのビルド
本パッケージでは、開発方法としてSDを用いる方法とBluetoothを用いる方法がありま
す。
1-2-1. SDを用いる方法
$ cd (mruby-on-ev3rt+tecs)/workspace/sd/

・実行するmrubyプログラムの選択
(mruby-on-ev3rt+tecs)/workspace/sd/Makefile

下記から実行したいmrubyプログラムを選択

#  mrubyのアプリケーションファイル名
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

カレントディレクトリをサンプルアプリケーションのディレクトリに移動し、makeを行うことでコンパイルが行えます。
*make tecsとmake dependの実行は、初めの一回のみでよい。

2. SDカードへコピー
デフォルトでは、cygwinが使用されていることを想定の上で、Eドライブにコピーされます。
具体的には、以下のコマンドが実行されます。
$ cp uImage /cygdrive/e/

ドライブを変更するには、サンプルコードのMakefileを編集します。
Makefile内を "SD_DIR" で検索して、変数にSDカードドライブを指定してください。

#
# SDのドライブ文字を指定
#
SD_DIR = /cygdrive/e/

アプリケーションディレクトリのクリーンは以下のコマンドで行えます。
・TECSの生成物を残す
$ make clean
・すべての生成物を削除 (推奨)
$ make realclean

1-2-2. Bluetoothを用いた方法
    詳細は、doc/mruby_on_ev3rt+tecs_build.pdf を参照してください。

【関連情報】
+---------------------+     +-------------------------+     +----------------------+    +-------------+
|                     |     |                         |     |                      |    |             |
| mruby application   |     | mruby class             |     | mruby => TECS Bridge |    |   TECS      |
|                     |-----| Wrapper for TECS Driver |====>|                      |----|>  Drivers   |
|                     |     |                         |     |                      |    |             |
|                     |     |                         |     |                      |    |             |
+---------------------+     +-------------------------+     +----------------------+    +-------------+
EV3のドライバは、TECSコンポーネント (C言語) で実装されています。
mrubyからEV3ドライバはmruby=>TECS Bridgeの仕組みを利用して呼び出されます。
TECSおよびmruby=>TECS Bridgeに関する情報はTOPPERSのWebサイトを参照してください。
http://www.toppers.jp/tecs.html

【補足：シリアルケーブルに関して】
シリアルケーブルはEV3本体のPort1を使用します。
(シリアルに使用するため、現在Port1にセンサを取り付けできない制約があります)
コンピュータへの接続にはUSB-Serial変換ケーブルおよびEV3-Serial変換コネクタが必要となります。
動作確認では以下のシリアルケーブルおよびコネクタを使用しました。

OLIMEX USBシリアル変換ケーブル(３線式)
※2015年6月現在、Windows 8で使用ができません (ドライバがありません)
http://strawberry-linux.com/catalog/items?code=15076

Breadboard Connector Kit for NXT(BCK01)
※NXT用ですがEV3にも使用可能です
http://www.technologia.co.jp/70_4600.html

上記シリアルケーブルおよびConnector Kitを使用する場合、それぞれ以下が対応します。
青(GND) - GRND (2 or 3)
緑(TX) - SCL (5)
赤(RX) - SDA (6)
baud rateは 115200 です。
