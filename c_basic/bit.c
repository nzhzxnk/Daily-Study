#include <stdio.h>

int main()
{
    /*
    i = 00001111;
    j = 11111111;
    i,jは何進法で与えても処理は2進数にした時のbitで行われる。
    【bit移動】
    00001111に対して<<1 -> 00011110(左に1bit移動)
    00001111に対して>>1 -> 00000111(右に1bit移動、どちらにせよ空いたところには0が入る)
    【bit演算】
    ① i | j (or: 各bitについて1があれば1)
    i  00001111
    j  11111111
    -> 11111111
    ② i & j (and: 各bitについてどちらも1なら1)
    i  00001111
    j  11111111
    -> 00001111
    ③ ~i (not: 各bitについて,0->1,1->0のように反転させる)
    i  00001111
    -> 11110000
    */

    /*16進法ver.*/
    unsigned char i = 0xf;
    unsigned char j = 0xff;
    // unsigned charは16進法の型
    // 初期値代入の時は必ず頭に0xつける
    printf("%d %d\n", i, j);
    // 16進数でも%dと型を指定すれば10進数にして表示される。
    printf("0x%x<<1 = 0x%x\n", i, i << 1);
    printf("0x%x>>1 = 0x%x\n", i, i >> 1);
    printf("0x%x|0x%x = 0x%x\n", i, j, i | j);
    printf("0x%x&0x%x = 0x%x\n", i, j, i & j);
    printf("~0x%x = 0x%x\n", i, (unsigned char)~i);
    // ~(not)はint型になって返ってくるので(unsigned char)で戻す。

    /*10進法ver.*/
    // int i = 15;
    // int j = 255;
    // printf("%d<<1 = %d\n", i, i << 1);
    // printf("%d>>1 = %d\n", i, i >> 1);
    // printf("%d|%d = %d\n", i, j, i | j);
    // printf("%d&%d = %d\n", i, j, i & j);
    // printf("~%d = %d\n", i, (int)~i);
}