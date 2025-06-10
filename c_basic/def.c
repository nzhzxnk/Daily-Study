#include <stdio.h>
#include <string.h>

// /*①平均を計算するave関数*/
// // 関数のプロトタイプ宣言
// double ave(double, double);
// // プロトタイプ宣言をすればmain()関数の後ろに加えていく感じで詳細を書ける。見出しみたいなもの。
// int main()
// {
//     double a = 0.3, b = 4.3, c, f;
//     int d = 6, e = 17;
//     c = ave(a, b);
//     f = ave(d, e);
//     printf("%f ", c);
//     printf("%f ", f);
// }
// double ave(double x, double y)
// {
//     double z = (x + y) / 2;
//     return z;
// }

/*②合格不合格をお知らせするコード*/
double ave(int, int, int);
void form(char[], int *);
// ポインタの話になるみたいなのであとで
void line();
int min = 70;
// minはグローバル関数、合格基準を表す、結局あんまグローバル関数の恩恵受けてないような気がする
int main()
{
    int x = 100, y = 100, z = 100;
    // 何かしら値を初期設定しなければいけない？resultとかとの違いは？
    double result;
    line();
    // xは素点でみんな100点持ってるものとする。
    form("数学", &y);
    form("英語", &z);
    // &もおそらくポインタの話になるので後で
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
    // 何も出力されないけど、プログラムが正常に終了したことを示す。書かなくても自動で付与されるらしい。
}
// 平均点を算出する関数
double ave(int a, int b, int c)
{
    double d = (a + b + c) / 3.0;
    return d;
}
// 点数入力受け付ける関数
void form(char subject[], int *score)
{
    printf("あなたの%sの点数を入力してください。:", subject);
    scanf("%d", score);
}
// voidのような戻り値のない関数ではreturn;は不要
// 　線を引く関数
void line()
{
    printf("************************\n");
}
