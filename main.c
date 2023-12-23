#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 特定の範囲で乱数を発生させる関数
int intrand(int min, int max)
{
    return rand() % max - min + 1;
}

// ゲーム
void game(char preceding[], char trailing[])
{
    while (1)
    {
        // サイコロの最大値, 先行のプレイヤーのダイス値, 後行のプレイヤーのダイス値
        int dice_max, preceding_dice, trailing_dice;
        char dicegame_start_pre[3], dicegame_start_tra[3];
        printf("%sはサイコロの最大値を決めてください:", preceding);
        scanf("%d", &dice_max);
        printf("ではゲーム開始です！\n");
        // 先行側のターン
        while (1)
        {
            printf("%sはサイコロを振ってください！なおサイコロの最小値は1で最大値は%dです:", preceding, dice_max);
            printf("(サイコロをふるにはYesと入力してください)\n");
            scanf("%s", dicegame_start_pre);
            // 入力がYesならif内をそれ以外ならもう一度
            if (strcmp(dicegame_start_pre, "Yes") == 0 || strcmp(dicegame_start_pre, "yes") == 0)
            {
                preceding_dice = intrand(1, dice_max);
                break;
            }
            else
                printf("Yesと入力してください！！\n");
        }
        printf("%sの出目は%dです\n", preceding, preceding_dice);
        // 後行側のターン
        while (1)
        {
            printf("%sはサイコロを振ってください！なおサイコロの最小値は1で最大値は%dです:", trailing, dice_max);
            printf("(サイコロをふるにはYesと入力してください)");
            scanf("%s", dicegame_start_tra);
            // 入力がYesならif内をそれ以外ならもう一度
            if (strcmp(dicegame_start_tra, "Yes") == 0 || strcmp(dicegame_start_tra, "yes") == 0)
            {
                trailing_dice = intrand(1, dice_max);
                break;
            }
            else
                printf("Yesと入力してください！！\n");
        }
        printf("%sの出目は%dです\n", trailing, trailing_dice);
        // 勝敗分
        if (trailing_dice == preceding_dice)
            printf("引き分けです！！\n");
        else if (trailing_dice < preceding_dice)
            printf("プレイヤー%sの勝ちです！！おめでとうございます！！\n", preceding);
        else
            printf("プレイヤー%sの勝ちです！！おめでとうございます！！\n", trailing);
        // コンティニューするかどうか
        while (1)
        {
            char *yesorno;
            printf("もう一回しますか？(YesかNoと入力してください):");
            scanf("%s", yesorno);
            if (strcmp(yesorno, "yes") == 0 || strcmp(yesorno, "Yes"))
            {
                printf("ではゲームリスタートです！");
                break;
            }
            else if (strcmp(yesorno, "no") == 0 || strcmp(yesorno, "No"))
            {
                printf("ゲームを終了します！");
                exit(0);
            }
            else
                printf("YesかNoでお願いします！!\n");
        }
    }
}

// サイコロをふる順番を決める関数
void turndec(char player1[], char player2[])
{
    while (1)
    {
        int player1_dice_roll;
        int player2_dece_roll;
        printf("まずはどちらが先行か決めます！\n%sはサイコロを振ってください:", player1);
        player1_dice_roll = intrand(1, 6);
        printf("出目は%dです！\n", player1_dice_roll);
        printf("次に%sサイコロを振ってください:", player2);
        player2_dece_roll = intrand(1, 6);
        printf("出目は%dです！\n", player2_dece_roll);
        if (player2_dece_roll == player1_dice_roll)
            printf("値が同じなので・・・もう一度振り直しましょう！\n");
        else if (player1_dice_roll < player2_dece_roll)
        {
            printf("%sが先行です！\n", player2);
            // player2を先行としてゲーム開始
            game(player2, player1);
        }
        else
        {
            printf("%sが先行です！\n", player1);
            // player1を先行としてゲーム開始
            game(player1, player2);
        }
    }
}

// プレイヤーの名前を入力させるための関数
void nameselect(char player1[], char player2[])
{
    printf("プレイヤー1の名前を入力してください:");
    scanf("%s", player1);
    printf("プレイヤー2の名前を入力してください:");
    scanf("%s", player2);
    turndec(player1, player2);
}

int main()
{
    // プレイヤーの名前を格納する変数
    char player1[100], player2[100];
    nameselect(player1, player2);
}