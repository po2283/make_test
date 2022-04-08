#include <iostream>
#include <vector>
#include <windows.h>
#include "test.h"
#include "solve.h"
#include <fstream>

using namespace std;

int main()
{
    int c;
    test user_question;
    int num;
    int current_num = 1;
    int ex_num = 0;
    solve user_slove;
    

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
        user_slove.solve_problem(num, ex_num);
        user_slove.show_score();
    }
    else {
        cout << "No?";
    }


}
