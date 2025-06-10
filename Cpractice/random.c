#include <stdio.h>
#include <stdlib.h>
// rand関数が入ってる関数
#include <time.h>
/*ランダムに1-12の数字を返すコード*/ 
int main()
{
    int a;
    srand((unsigned)time(NULL));
    // srand()というのはrand関数のrandom配列に対応する番号みたいなもの
    // srandを固定してしまうと同じ値しか出てこない
    // time関数は刻一刻と変化するのでよくsrandのパラメータに使われる。
    // time関数はtime_t型(long型として扱う環境が多い)、srandの引数はunsigned int型なので、(unsigned)で型を変更して入れてる
    a = rand() % 12 + 1;
    // randは0-randmaxまでの値を返す(bitの容量)ので範囲を定めたい場合は%を使って範囲を小さくする。
    printf("今日のあなたの運勢は%d位です。\n", a);
}