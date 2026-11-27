#pragma once
// Copyright (C) RenZhai.2022.All Rights Reserved.
// 作者：人宅
// この C ライブラリのソースコードの詳しい解説は AboutCG の C 言語入門動画教材を参照：
//https://www.aboutcg.org/courseDetails/902/introduce
// UE4 ゲーム開発など、その他の技術については以下のサイトを参照：
//https://zhuanlan.zhihu.com/p/60117613
//
// bilibili では作者の各種チュートリアルの紹介を視聴できる：
//https://space.bilibili.com/29544409
//
// 個人ブログ
//http://renzhai.net
//
// このサンプルの詳しい操作方法：
// テキスト版（詳細）：
//https://zhuanlan.zhihu.com/p/144558934
// 動画版：
//https://www.bilibili.com/video/BV1x5411s7s3

#ifdef CLOSE_DISABLE_DEBUG_INFOR
#pragma warning(disable:4267)// 引数：型変換によってデータが失われる可能性がある
#pragma warning(disable:4311)// 型変換：ポインターを DWORD に変換すると切り詰められる可能性がある
#pragma warning(disable:4244)// 型変換によってデータが失われる可能性がある
#pragma warning(disable:4309)// 定数値の切り詰め
#pragma warning(disable:4305)// 引数：型変換による切り詰め
#pragma warning(disable:4133)// 互換性のない型：char[260] から LPWSTR への変換
#pragma warning(disable:4090)// 初期化：const 修飾子が異なる
#pragma warning(disable:4013)// 関数が未定義のため、戻り値を int とする外部関数と仮定する
#pragma warning(disable:4251)// DLL の状態チェックは後で有効にする
#pragma warning(disable:4717)// すべての制御パスで再帰が発生し、実行時にスタックがオーバーフローする
#pragma warning(disable:4099)// struct として宣言された型が class として参照されている
#pragma warning(disable:4018)// 比較：符号付きと符号なしの型が一致しない
#pragma warning(disable:4477)
#pragma warning(disable:4244)//'argument': conversion from 'float' to 'int', possible loss of data
#endif // DEBUG

//core minimal
// #include "simple_core_minimal/simple_c_guid/simple_guid.h"
// #include "simple_core_minimal/simple_c_path/simple_path.h"
// #include "simple_core_minimal/simple_c_windows/simple_c_windows_setting.h"
// #include "simple_core_minimal/simple_c_windows/simple_c_windows_register.h"
// #include "simple_core_minimal/simple_c_helper_file/simple_file_helper.h"
// #include "simple_core_minimal/simple_c_time/simple_c_time.h"
//
// //core
// #include "simple_core_minimal/simple_c_core/simple_c_string_algorithm/string_algorithm.h"
// #include "simple_core_minimal/simple_c_core/simple_c_array/simple_c_array.h"
//
//
// //application 
 #include "simple_c_log/simple_c_log.h"
//
// //Delegate
// #include "simple_delegate/simple_delegate.h"
//
// //net
// //#include "simple_channel/simple_net_drive.h"
//
// //math
// #include "simple_math/simple_core_math.h"
//
// //image
// #include "simple_image/simple_image.h"
//
// コンテナー
// #include "simple_library/public/simple_array/simple_hash_array.h"
//
// 外部ライブラリ
// //xml
// #include "simple_library/third_party_library/tinyxml/tinystr.h"
// #include "simple_library/third_party_library/tinyxml/tinyxml.h"
//
// //Json
// #include "simple_library/third_party_library/nlohmann/json.hpp"