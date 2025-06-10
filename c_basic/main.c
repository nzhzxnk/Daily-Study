#include <stdio.h>
#include "ave.h"
#include "strc.h"

// headerをincludeして関数のファイルと繋げている。headerにはプロトタイプ宣言
// 自作header(.c)はinclude ""だけど, もともとc言語にコンパイルされてるheader(.lib)はinclude <>で書く

/*合格不合格をお知らせするコード*/
int min = 70, x = 100;
// この２つはグローバル関数なのでmainの中に入れない。
int main()
{
    int y = 100, z = 100;
    double result;
    line();
    form("数学", &y);
    form("英語", &z);
    result = ave(x, y, z);
    line();
    if (result >= min)
    {
        printf("【合格】\nあなたの点数は%f点で、合格基準に達しています。\n", result);
    }
    else
    {
        printf("【不合格】\nあなたの点数は%f点で、合格基準に達していません。\n", result);
    }
    line();
    return 0;
}

// この後に続く関数の定義はそれぞれファイル分けた