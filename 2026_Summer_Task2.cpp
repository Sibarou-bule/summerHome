#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    int player; //playerの入力変数         
    int cpu;//cpuの入力変数            
    int result;//リザルト         
    int i;
    int win = 0;//勝ち        
    int lose = 0;//負け       
    int draw = 0;//引き分け       

    srand((unsigned int)time(nullptr));

    cout << "じゃんけんゲームを開始します。" << endl;

    //5回勝負
    for ( i = 0; i < 5; i++)
    {
        cout << endl;
        cout << "-------- " << i + 1 << "回戦 --------" << endl;

        //入力チェック
        while (true)
        {
            cout << "0：グー　1：チョキ　2：パー" << endl;
            cout << "プレイヤーの手を入力してください：" << endl;

            cin >> player;

            if (player >= 0 && player <= 2)//playerが０～２の場合
            {
                break;
            }

            cout << "入力に誤りがあります。再入力してください。" << endl;
        }

        cpu = rand() % 3;//cpu入力（ランダム）

        //playerの変数に合わせて出すものを変える
        switch (player)
        {
        case 0://player==0の場合
            cout << "PLAYER：グー" << endl;
            break;

        case 1://player==１の場合
            cout << "PLAYER：チョキ" << endl;
            break;

        case 2://player==２の場合
            cout << "PLAYER：パー" << endl;
            break;
        }


        switch (cpu)//cpuの変数に合わせて出すものを変える
        {
        case 0://cpu==0の場合
            cout << "CPU：グー" << endl;
            break;

        case 1://cpu==1の場合
            cout << "CPU：チョキ" << endl;
            break;

        case 2://cpu==２の場合
            cout << "CPU：パー" << endl;
            break;
        }


        result = player - cpu;//引いた数の値で勝敗を判断する

        if (result == -1 || result == 2)//resultがー１、２の場合（勝ち）
        {
            cout << "PLAYER WIN!" << endl;
            win++;
        }
        else if (result == 0)//resultが０の場合（引き分け）
        {
        {
            cout << "DRAW" << endl;
            draw++;
        }
        else//resultがそれ以外の場合（まけ）
        {
        {
            cout << "CPU WIN!" << endl;
            lose++;
        }
    }

    //５回勝負後
    cout << endl;
    cout << "==============================" << endl;
    cout << "5回勝負終了！" << endl;
    cout << win << "勝 "
        << draw << "分 "
        << lose << "敗" << endl;
    cout << "==============================" << endl;

    return 0;
}