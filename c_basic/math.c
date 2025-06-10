#include <stdio.h>
#include <math.h>
#include "calc.h"

int main()
{
    int d;
    double rad;
    extern double s, c, t;
    printf("測定した角度を入力してください。:");
    scanf("%d", &d);
    tri(d);
    printf("\n");
    check(s, c);
}