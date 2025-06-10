#include <stdio.h>
#include <string.h>

int main()
{
    // /*変数を最初に初期化しないとおかしくなるのでコメントアウトします。*/


    // /*①入力が正の数か出力するコード*/
    // int a;
    // printf("数値を入力してください。:");
    // scanf("%d", &a);
    // if (a > 0)
    // {
    //     printf("入力した値は正の数です。\n");
    // }
    // else{
    //     printf("入力した値は正の数はありません")
    // }
    // // }には;つけなくていい
    // // 間違えてif (a>0);{とかつけないように！！


    // /*② 1-3の数を入力してそれぞれに対応する文字列を出力するコード*/
    // int a;
    // printf("1-3の数字を入力してください。\n");
    // scanf("%d", &a);
    // if (a == 1)
    // {
    //     printf("You're A\n");
    // }
    // else if (a == 2 || a == 3)
    // // &&がand(かつ)、||がor(または)を表す
    // {
    //     printf("You're B\n");
    // }
    // else
    // {
    //     printf("不適切な数字です。\n");
    // }


    /*③switch文を使った条件分岐*/
    int num;
    printf("出たサイコロの目を入力してください");
    scanf("%d", &num);
    switch (num)
    {
    case 1:
        printf("You're A");
        break;
    case 2:
    case 3:
    case 4:
        printf("You're B");
        break;
    case 5:
    case 6:
        printf("You're C");
        break;
    default:
        printf("You're wrong");
        break;
    }


    // /*④名前と年齢の入力から出力を出すコード*/
    // /*scanfは数字のinputに使用することが多く、文字列はfgetsが多い*/
    // char name[100];
    // int age;
    // printf("名前を入力してください。:\n");
    // fgets(name, sizeof(name), stdin);
    // // fgets(変数, sizeof(変数の長さ), stdin(入力という意味))
    // name[strcspn(name, "\n")] = '\0';
    // // fgetsは文字列に\nつけて返してしまうため削除しないといけない
    // printf("年齢を入力してください。:\n");
    // scanf("%d", &age);
    // printf("こんにちは%sさん、%d歳ですね！\n", name, age);
}