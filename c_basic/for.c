#include <stdio.h>

int main()
{
    // /*①基本的なfor文3つ*/
    // int i;
    // for (i = 1; i <= 5; i++)
    // // for (i=1で初期化; iの範囲を決める; 次のiにどんな処理をするか){}という構造
    // // i++ は i += 1 と同じ
    // {
    //     printf("%d ", i);
    // }
    // printf("\n");
    // for (i = 1; i <= 5; i += 2)
    // // 2ずつiを増やしたければこうする
    // {
    //     printf("%d ", i);
    // }
    // printf("\n");
    // for (i = 1; i < 5; i++)
    // // 条件は、必ず整数入る範囲とかではない、なんでもいい
    // {
    //     printf("%d ", i);
    // }
    // printf("\n");

    // /*②二重ループ*/
    // int i,j;
    // for (i=1; i<=4; i++){
    //     for (j=2; j<11; j+=2){
    //         printf("%d+%d=%d ", i, j, i+j);
    //     }
    // } printf("\n");

    // /*③whileとdo-while*/
    // int num, i;
    // printf("1以下の整数と2以上の整数を入力しそれぞれの差を比較してください。");
    // scanf("%d", &num);
    // printf("while文で実行\n");
    // i = 1;
    // while (i < num)
    // {
    //     printf("%d ", i);
    //     i++;
    // }
    // printf("\n");
    // printf("do-whileで実行\n");
    // i = 1;
    // do
    // {
    //     printf("%d ", i);
    //     i++;
    // } while (i < num);
    // // do-whileもwhileもやること自体は一緒
    // // はじめの初期化した値で一回試すのがdo-while
    // printf("\n");

    /*④無限ループ*/
    int num;
    printf("負の数を入力するとループから抜けることができます。\n");
    while (1)
    {
        printf("数値を入力してください。: ");
        scanf("%d", &num);
        if (num < 0)
        {
            break;
        }
    }
    printf("ループから抜け出せました！\n");
}