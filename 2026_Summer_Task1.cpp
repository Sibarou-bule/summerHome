#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    int answer = -1;//入力する変数
    int question;//当てる数字         
    int count = 0;//何回目        

    srand((unsigned int)time(nullptr));

    question = rand() % 101;//０～１００までランだむで入れる

    cout << "数字当てゲーム" << endl;
    cout << "0～100までの数字を当ててください。" << endl;

    while (question != answer)//questionとanswerが一緒じゃない場合くりかえす
    {
        count++;//カウント＋１

        //入力チェック
        while (true)
        {
            cout << "0～100の数字を入力してください：" << endl;
            cin >> answer;

            //answerが０～１００以外の場合
            if (answer < 0 || answer > 100)
            {
                cout << "入力に誤りがあります。再入力してください。" << endl;
            }
            else
            {
                break;
            }
        }

        if (question > answer)//questionのほうが大きかった場合
        {
            cout << "もっと大きい数字です。" << endl;
        }
        else if (question < answer)//answerのほうが大きかった場合
        {
            cout << "もっと小さい数字です。" << endl;
        }
    }

    //正解したら
    cout << endl;
    cout << "おめでとうございます！正解です！" << endl;
    cout << "正解：" << answer << endl;
    cout << count << "回目で当てることができました。" << endl;

    return 0;
}