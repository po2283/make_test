#include <iostream>
#include <vector>
#include <windows.h>
#include "test.h"

using namespace std;

int main()
{
    /*보기는 총 3개*/
    /*string str;
    getline(cin, str);
    cout << "str: " << str << endl;*/
    
    int num = 0;
    string question = "";
    string example = "";
    string answer = "";
    int c;
    int correct;
    string a = "";

    /*cout << "총 몇 문제를 입력하시겠어요?" << endl;
    cin >> num;
    cout << endl;*/

    test user_question;

    cout << "문제를 입력하시오" << endl;
    getline(cin, question);
    user_question.have_question(question);
    cout << endl;

    cout << "보기를 입력하시오" << endl;
    for (int i = 0; i < 3; i++) {
        cin >> example;
        user_question.have_example(example);
    }
    cout << endl;

    cout << "정답을 입력하시오: " << endl;
    cin >> answer;
    user_question.have_answer(answer);
    cout << endl;

    cout << "문제를 풀고 싶으면 1을 입력하세요: " << endl;
    cin >> c;
    if (c == 1) {
        cout << "문제를 확인합니다..." << endl;
        Sleep(1000);
        system("cls");

        user_question.print_q();
        user_question.print_ex();
        cout << endl;

        cout << "정답을 입력하세오: ";
        cin >> a;
        correct = user_question.solve_answer(a);
        cout << "당신의 점수는 " << correct;
    }
    else {
        cout << "No?";
    }
    

    /*for (int i = 0; i < num; i++) {
       // cout << "문제를 입력하세요." << endl;
        getline(cin, question);
        user_question.have_question(question);
        cout << endl;

        for (int j = 0; j < 3; j++) {
            cin >> example;
            user_question.have_example(example);
        }
        cout << endl;

        //cout << "답을 입력하세요" << endl;
        cin >> answer;
        user_question.have_answer(answer);
        cout << endl;
    }*/

    

    /*총 몇 문제를 낼지 받아서 그만큼 돌려주면서 문제 -> 보기 -> 답 순으로 저장한다.*/

}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
