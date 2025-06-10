#include <stdio.h>
#include <math.h>
#include "calc.h"
#define P 3.14
// 定数を定義する場合このようにする

double s, c, t;
void tri(int d)
{
    double rad;
    rad = d * P / 180;
    s = sin(rad);
    c = cos(rad);
    t = tan(rad);
    // sin,cos,tanはラジアンにしか対応してない。
    printf("sin(%d)= %f ", d, s);
    printf("cos(%d)= %f ", d, c);
    printf("tan(%d)= %f ", d, t);
}

void check(double s, double c)
{
    printf("三角関数の公式がきちんと成り立つか確認します。\n");
    printf("sin2(%f)+cos2(%f)=%fです。\n", pow(s, 2), pow(c, 2), pow(s, 2) + pow(c, 2));
    printf("|sin|=%fであり正常な範囲(0<=|sin|<=1)にあります。\n", fabs(s));
}
