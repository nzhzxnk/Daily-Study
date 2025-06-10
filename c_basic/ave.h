/*ave関数のプロトタイプ宣言*/
#ifndef _AVE_H_
#define _AVE_H_
// #のはマクロと言われるもの
// 二重includeをしないようにしている。二重になると定義が重複してエラーになる
// in not define(このファイル)　-> define(このファイル)　-> end

double ave(int, int, int);

#endif //_AVE_H_
// endifの後にファイル名いらないが人間にとってはわかりやすいのでコメントしておく