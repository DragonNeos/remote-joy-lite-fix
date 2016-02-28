English follows

# はじめに #
あきん堂本舗様が公開されているRemoteJoyLiteへのマイナー修正です。本家と比べ以下のような特長があります。
  * トリプルバッファを用いてフルスクリーン表示を行うため、FPSが高くなります。
  * 画像拡大フィルタにSpline36を採用しているため、文字や立ち絵のブラーが改善されます
  * USB自動再接続機能により、RemoteJoyLiteではフリーズしてしまうシーンでもプレイし続けることができます

# 使用方法 #
  * 本家RemoteJoyLiteが動く状態にしてください
  * 本パッケージをRemoteJoyLiteに上書きして下さい
  * 32-bit版Windowsをお使いの場合はx86フォルダの中のResetUsb.exeをRemoteJoyLiteのフォルダにコピーして下さい
  * 64-bit版Winodwsをお使いの場合はx64フォルダの中のResetUsb.exeをRemoteJoyLiteのフォルダにコピーして下さい

# 注意 #
  * Norton AntiVirusのSONARが反応する場合があります。これは内部でResetUsb.exeを呼び出しているためだと思われます。反応する場合はSONARの除外リストに入れてからご使用下さい。

# リンク #
  * 本家サイト あきん堂本舗 http://cgi.din.or.jp/~takakind/cgi-bin/index.cgi?p=RemoteJoyLite

# Summary #
remote-joy-lite-fix is minor fix for RemoteJoyLite developed by "Akind". There are some differences compared to the original RemoteJoyLite.
  * Uses fullscreen mode with triplebuffer. The fps will be increased.
  * Implements Spline36 image scaling filter. The blur of letters and 2d images will be reduced.
  * Implemented automatic usb resetting. The frequency of freeze is drastically decreased.

# Usage #
  * Setup the original RemoteJoyLite.
  * Overwrite remote-joy-lite-fix to the RemoteJoyLite.
  * If you are using Windows 32-bit version, copy x86/ResetUsb.exe to the top folder.
  * If you are using Windows 64-bit version, copy x64/ResetUsb.exe to the top folder.

# Note #
  * Norton AntiVirus SONAR will notify that the exe file should be an virus. This is because remote-joy-lite-fix calls ResetUsb internally. Please add remote-joy-lite-fix to the exclusive list.

# Link #
  * The original developer's site "Akind's" http://cgi.din.or.jp/~takakind/cgi-bin/index.cgi?p=RemoteJoyLite