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

    /*풀고자 하는 문제의 수를 입력한다.*/
   cout << "풀 문제의 수를 입력하시오: ";
    cin >> num;
    system("cls");

    /*문제를 num만큼 입력받는다.*/
    for (int i = 0; i < num; i++) {

        /*질문 받기*/
        user_question.have_question(current_num);
        cout << endl;

        /*보기 받기*/
        user_question.have_example(num);
        cout << endl;

        /*정답 받기*/
        user_question.have_answer();
        cout << endl;

        /*문제 하나를 모두 받았으면 콘솔 화면을 지워준다.*/
        system("cls");

        /*현재 몇 번째 문제를 받고 있는지 알려주는 변수.*/
        current_num++;
    }

    cout << "문제를 풀고 싶으면 1을 입력하세요: " << endl;
    cin >> c;

    if (c == 1) {
        user_question.solve_problem(num);
        user_question.show_score();
    }
    else {
        cout << "No?";
    }


}
