# bbsite_sns_buttons モジュール

コンテンツタイプに SNS のボタン(Facebook の 「いいね!」等)を表示するフィールドを追加
します。

例えば、[BBSite の技術 BLOG](http://bbsite.jp/blog) のように動作します。

対応しているボタンは、Facebook, Google+, はてなブックマーク, LINE です。他のボタンも
追加予定です。

このモジュールは Drupal 7.x で動作します

## Install

モジュールをダウンロードし、モジュールフォルダ (sites/all/modules 等)に展開します。
モジュールを *有効* にします。

管理画面(admin/bbsite/sns_buttons)で利用したいボタンを選択します。

コンテンツタイプの表示フィールド管理画面に移動します
(admin/structure/types/manage/ *Content Type* /display)。

Default, Teaser, RSS 等のそれぞれで SNSボタンを表示するかしないかを設定します。


## 表示のカスタマイズについて

テーマ関数は *Theme name* _bbsite_sns_buttons($element) になります。ご自身のテーマの
template.php に上記テーマ関数を実装してください。


## バグ

コンテンツタイプ毎にこのモジュールを有効にするか否かを指定することが出来ますが、コン
テンツタイプ毎に表示するボタンを切り換えることが出来ません。


## ライセンスなど

- License: GPL v2
- Repository:  https://github.com/smiyabe/bbsite_sns_buttons
- Satoshi Miyabe (miyabe @ bbsite.jp)


