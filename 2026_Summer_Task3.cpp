#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main(void)
{
	const int CARD = 3;//３桁
	const int CARD_NUMBER = 10;//０～９

	int i, hit = 0;
	int playerCard[CARD];//enemyが当てる数字
	int enemyCard[CARD];//playerが当てる数字
	int plyChoice[CARD];//playerが入力する変数
	int emyChoice[CARD];//enemyが入力する変数

	bool trunFlag = true;//true:playerターン　false:enemyターン
	bool judgementFlag = false;//true:playeの勝利　false:enemyの勝利

	srand((unsigned int)time(NULL));

	//当てる用の数字を決める（ランダム）
	for (i = 0; i < CARD; i++)//３回回す
	{
		playerCard[i] = rand() % CARD_NUMBER;//０～９でランダム
		enemyCard[i] = rand() % CARD_NUMBER;//０～９でランダム
	}
	cout << "===================   Hit & Blow   ============================" << "\n";
	cout << "3マスの数字あてゲームプレイヤーとCPUが、お互いに隠し持った3つの数字を当てるターン制のゲーム" << "\n";
	cout << "あなたの配られてカードは," << "\n";

	//player用のカードは見せる
	for (i = 0; i < CARD; i++)//３回回す
	{
		cout << i + 1 << "番目" << playerCard[i] << "\n";
	}

	cout << "===================   GAME STRAT   ============================" << "\n";

	while (true)//ゲームループ
	{

		if (trunFlag)//playerターン
		{

			hit = 0;//初期化
			cout << "PLAYER TRUN 「数字の0から9までの数字を3つ選んでください」\n";
			for (i = 0; i < CARD; i++)//３回回す
			{
				//入力チェック
				while (true)
				{
					cin >> plyChoice[i];
					if (0 > plyChoice[i] || 9 < plyChoice[i])//０～９以外を入力したら
					{
						cout << "入力に誤りがあります。再度入力してください。\n";
					}
					else//それ以外なら
					{
						break;//抜けだす
					}

				}
			}


			for (i = 0; i < CARD; i++)//３回回す
			{
				if (plyChoice[i] == enemyCard[i])//一致してたら
				{
					cout << "Hit,";//ヒット
					hit++;//hitに＋１する
				}
				else//一致してなかったら
				{
					cout << "Blow,";
				}
			}
			cout << "\n";
			if (hit == 3)//hit変数が３なら
			{
				cout << "3Hit!!\n";
				judgementFlag = true;//player勝利用のフラグにする
				break;//whileを抜け出す
			}

			cout << "\n";
			trunFlag = false;//enemyターンにする
		}
		else//enemyターン
		{
			hit = 0;//初期化

			cout << "ENEMY TRUN \n";
			for (i = 0; i < CARD; i++)//３回回す
			{
				emyChoice[i] = rand() % CARD_NUMBER;//ランダムで入力する

				cout << i + 1 << "番目" << emyChoice[i] << "\n";
			}

			for (i = 0; i < CARD; i++)//３回回す
			{
				if (emyChoice[i] == playerCard[i])//一致してたら
				{
					cout << "Hit,";
					hit++;//hitに＋１する
				}
				else//一致してなかったら
				{
					cout << "Blow,";
				}
			}
			cout << "\n";
			if (hit == 3)//hit変数が３なら
			{
				//enemy勝利用のフラグのまま
				cout << "3Hit!!\n";
				break;//whileを抜け出す
			}

			cout << "\n";
			trunFlag = true;//playerターンにする
		}


	}

	if (judgementFlag)//tureなら（playerが勝利したら）
	{
		cout << "PLAYER WINNER\n";
	}
	else//falseなら（enemyが勝利したら）
	{
		cout << "ENEMY WINNER\n";
	}
	return 0;
}