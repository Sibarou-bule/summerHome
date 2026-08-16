#include<iostream>
#include<cstdlib>
#include<ctime>
#include"game.h"

using namespace std;

void Game()
{
	int i;
	int dice[DICE];
	int diceSum;
	int playerNum;
	int cpuNum;
	int area[AREA_NUMBER] = {};
    int count = 0;
    int win = 0;
    int lose = 0;
    int choice;
	bool turnFlag = true;
	bool chakflag = false;
    bool gameOver = false;

	srand((unsigned int)time(NULL));

	cout << "ジャックポット\n";
	cout << "CPUとプレイヤーが交互に２つの六面サイコロを振り、1から9までのマスを陣取りするゲームです。\n";
	cout << "プレイヤーは交互に六面サイコロを2個振る\n";
	cout << "出た目の数に合わせて、対応するマスを取ることができます。\n";
	cout << "プレイヤーは以下のうち1つを選択できる:\n①六面サイコロの目\n②六面サイコロの目の合計\n";
	cout << "=======================GameSturt===========================\n";

    while (!gameOver)
	{
		if (turnFlag)//playerターン
		{
			for (i = 0;i < DICE;i++)
			{
				dice[i] = rand() % DICE_NUMBER;
				dice[i]++;
			}
			diceSum = dice[0] + dice[1];
			



			cout << "取れるマスは\n";
			cout << dice[0] << ":" << dice[1] << ":" << diceSum << endl;

            while (true)
            {
                // 合計が9を超える場合
                if (diceSum > AREA_NUMBER_MAX)
                {
                    if ((area[dice[0] - 1] == 1 || area[dice[0] - 1] == 2) &&
                        (area[dice[1] - 1] == 1 || area[dice[1] - 1] == 2))
                    {
                        cout << "もう取られてるので取れません\n";
                        gameOver = true;
                        break;
                    }
                }
                // 合計が9以下の場合
                else
                {
                    if ((area[dice[0] - 1] == 1 || area[dice[0] - 1] == 2) &&
                        (area[dice[1] - 1] == 1 || area[dice[1] - 1] == 2) &&
                        (area[diceSum - 1] == 1 || area[diceSum - 1] == 2))
                    {
                        cout << "もう取られてるので取れません\n";
                        gameOver = true;
                        break;
                    }
                }

                // ここから入力
                while (true)
                {
                    cout << "どこを取る？\n";
                    cin >> playerNum;

                    if (playerNum == dice[0] ||
                        playerNum == dice[1] ||
                        (diceSum <= AREA_NUMBER_MAX && playerNum == diceSum))
                    {
                        if (area[playerNum - 1] == 0)
                        {
                            area[playerNum - 1] = 1;
                            turnFlag = false;
                            break;
                        }
                        else
                        {
                            cout << "そのマスはもう取られています。\n";
                        }
                    }
                    else
                    {
                        cout << "その数字は選べません。\n";
                    }
                }
                count = 0;
                for (i = 0;i < AREA_NUMBER_MAX;i++)
                {
                    if (area[i] == 0)
                    {
                        count++;
                    }
                }
                break;
            }
            if (count == 0)
            {
                break;
            }
		}
		else//enemyターん
		{
			for (i = 0;i < DICE;i++)
			{
				dice[i] = rand() % DICE_NUMBER;
				dice[i]++;
			}
            diceSum = dice[0] + dice[1];

            while (true)
            {
                if (diceSum > AREA_NUMBER_MAX)
                {
                    if ((area[dice[0] - 1] == 1 || area[dice[0] - 1] == 2) &&
                        (area[dice[1] - 1] == 1 || area[dice[1] - 1] == 2))
                    {
                        gameOver = true;
                        break;
                    }
                }
                else
                {
                    if ((area[dice[0] - 1] == 1 || area[dice[0] - 1] == 2) &&
                        (area[dice[1] - 1] == 1 || area[dice[1] - 1] == 2) &&
                        (area[diceSum - 1] == 1 || area[diceSum - 1] == 2))
                    {
                        gameOver = true;
                        break;
                    }
                }

                while (true)
                {
                    if (diceSum <= AREA_NUMBER_MAX)
                    {
                        choice = rand() % 3;

                        if (choice == 0)
                            cpuNum = dice[0];
                        else if (choice == 1)
                            cpuNum = dice[1];
                        else
                            cpuNum = diceSum;
                    }
                    else
                    {
                        choice = rand() % 2;

                        if (choice == 0)
                            cpuNum = dice[0];
                        else
                            cpuNum = dice[1];
                    }

                    if (cpuNum == dice[0] ||
                        cpuNum == dice[1] ||
                        (cpuNum <= AREA_NUMBER_MAX && cpuNum == diceSum))
                    {
                        if (area[cpuNum - 1] == 0)
                        {
                            area[cpuNum - 1] = 2;
                            turnFlag = true;
                            break;
                        }
                        else
                        {
                            //ループ
                        }
                    }
                    else
                    {
                        //ループ
                    }
                }

                count = 0;
                for (i = 0;i < AREA_NUMBER_MAX;i++)
                {
                    if (area[i] == 0)
                    {
                        count++;
                    }
                }
                break;
            
            }
            if (count == 0)
            {
                break;
            }
		}
	}

    for (i = 0;i < AREA_NUMBER_MAX;i++)
    {
        if (area[i] == 1)
        {
            win++;
        }
        else if(area[i]==2)
        {
            lose++;
        }
    }

    cout << "＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝\n";
    cout << "＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝\n";

    cout << "player:" << win << endl;
    cout << "enemy：" << lose << endl;
}