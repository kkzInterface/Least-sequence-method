Least sequence method（最小二乗法）
======================
最小二乗法のc++プログラムです。[みその計算物理学](http://www.geocities.jp/supermisosan/saisyounizyouhou1.html)のcプログラムを参考にc++仕様（あんま変わらんけど）で組み直しました。プログラム中の変数に関しては、[szksrv](http://szksrv.isc.chubu.ac.jp/lms/lms1.html)の最小二乗法の説明に記述されているアルファベットに対応しています。

How to run
----------
コンパイルし、実行ファイルを実行します。

    g++ -o Least_sequence Least_sequence.cc
    ./Least_sequence

Read a file
-----------
readFile関数で定数DATA_SOURCEに定義されているファイルを読み込みます。ファイルの内容はtest-dataを参照してください。なお、test-dataの中身は一列目がx、二列目がyとなっています。

A reference
-----------
1. [みその計算物理学](http://www.geocities.jp/supermisosan/saisyounizyouhou1.html "みその計算物理学")
2. [szksrv](http://szksrv.isc.chubu.ac.jp/lms/lms1.html "szksrv")