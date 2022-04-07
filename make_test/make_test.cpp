#include <iostream>
#include <vector>
#include <windows.h>
#include "test.h"

using namespace std;

int main()
{

    int c;
    test user_question;
    int num;
    int current_num = 1;
    int ex_num = 0;

   cout << "풀 문제의 수를 입력하시오: ";
    cin >> num;
    cout << endl;
    cout << "필요한 보기의 수를 입력하시오: ";
    cin >> ex_num;
    system("cls");

    for (int i = 0; i < num; i++) {
        user_question.have_question(current_num);
        cout << endl;

        user_question.have_example(num, ex_num);
        cout << endl;

        user_question.have_answer();
        cout << endl;

        system("cls");

        current_num++;
    }

    cout << "문제를 풀고 싶으면 1을 입력하세요: " << endl;
    cin >> c;

    if (c == 1) {
        user_question.solve_problem(num, ex_num);
        user_question.show_score();
    }
    else {
        cout << "No?";
    }


}
