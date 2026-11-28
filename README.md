# SKREngine

ゲームエンジンプロジェクト  
制作期間：二ヶ月（2025年6月～2025年8月）  
C++ でゲームエンジンの基礎を学ぶための開発プロジェクトです。現在は数学ライブラリとエンジンの基本構成を中心に実装しています。

## 主な実装

### ベクトルと行列

2D・3D・4D のベクトル、行列、色を扱う型を用意しています。3D ベクトルでは内積、外積、長さ、正規化などを実装しています。

4×4 行列では、積、行列式、転置、逆行列などを扱います。逆行列は拡大係数行列を作り、行基本変形で求める構成です。演算をライブラリ任せにするだけでなく、計算の過程をコードとして確かめることを重視しています。

### 回転と補間

クォータニオンでは、軸と角度からの回転生成、積、正規化、逆回転、線形補間、球面線形補間などを実装しています。補間する二つの回転の関係を確認し、近い回転では線形補間を使うなど、計算の分岐も扱っています。

### エンジンと基礎ライブラリの分離

エンジン本体を置く `Engine` と、数学などの共通処理を置く `MyBaseLibrary` を分けています。`Engine` クラスには初期化、更新、終了の各段階を定義し、今後の処理を追加するための骨組みを用意しています。

## 主なコード

| 型・ファイル | 主な関数 | 内容 |
| --- | --- | --- |
| [FVector_3d](Engine/Source/MyBaseLibrary/BaseLibrary/private/simple_math/transformation/vector/vector_3d.cpp) | `dot()`、`crossProduct()`、`normalize()` | 3D ベクトルの基本演算 |
| [FMatrix_4x4](Engine/Source/MyBaseLibrary/BaseLibrary/private/simple_math/transformation/matrix/matrix_4x4.cpp) | `determinant()`、`transpose()`、`inverse()` | 行列式、転置、逆行列 |
| [FQuat](Engine/Source/MyBaseLibrary/BaseLibrary/private/simple_math/transformation/quaterinon/quat.cpp) | `CreateRot()`、`nlerp()`、`s_lerp()` | 回転の生成と補間 |
| [Engine](Engine/Source/Engine/Engine.h) | `preInit()`、`Init()`、`Tick()`、`Exit()` | エンジンのライフサイクルの宣言 |

## 現在の開発状況

数学処理には実装済みの関数がありますが、行列と回転の相互変換などには未実装の箇所が残っています。エンジン本体と Windows 向けのクラスも、現在は骨組みの段階です。

今後は数学ライブラリの確認と不足部分の実装を進め、ウィンドウや DirectX 12 の描画処理を接続していく予定です。

## 開発環境と構成

Windows、C++、Visual Studio のプロジェクトで、MSVC **v143** を指定しています。[Engine/SKREngine.sln](Engine/SKREngine.sln) からソリューションを開けます。

```text
Engine/
├── SKREngine.sln
└── Source/
    ├── Engine/          エンジン本体とプラットフォーム別の骨組み
    └── MyBaseLibrary/   数学などの基礎ライブラリ
```

基礎ライブラリには nlohmann/json と TinyXML も収録しています。これらの第三者ライブラリには、各ファイルに記載されたライセンスが適用されます。
