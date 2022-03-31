#pragma once
#include <string>
#include<vector>
#include<iostream>

using namespace std;

/*테스트의 특징을 모아둔 클래스
필요한 변수
1. 지문
2. 보기
3. 정답*/

class test {
protected:
	vector<string> question;
	vector<string> example;
	vector<string> answer;
	int correct;

public:

	test(){
		correct = 0;
	}
	~test(){}

	/*문제를 입력받는 함수
	문제를 받아가지고 벡터에다가 저장해야 한다.*/

	void have_question() {
		string q;
		cout << "문제를 입력하시오" << endl;
		getline(cin, q);
		question.push_back(q);
	}

	void have_example() {
		string ex;
		cout << "보기를 입력하시오" << endl;
		for (int i = 0; i < 3; i++) {
			cin >> ex;
			example.push_back(ex);
		}
	}

	void have_answer() {
		string an;
		cout << "정답을 입력하시오: " << endl;
		cin >> an;
		answer.push_back(an);
	}

	void print_q() {
		for (int i = 0; i < question.size(); i++) {
			cout << question[i] << endl;
		}
		cout << endl;
	}

	void print_ex() {
		for (int i = 0; i < 3; i++) {
			cout << example[i] << endl;
		}
		cout << endl;
	}

	void print_an() {
		for (int i = 0; i < answer.size(); i++) {
			cout << answer[i] << endl;
		}
		cout << endl;
	}

	int solve_answer(string a) {
		for (int i = 0; i < answer.size(); i++) {
			if (a == answer[i]) {
				correct++;
			}
		}
		return correct;
	}

	void solve_problem() {
		string s_an;
		int score;

		cout << "문제를 확인합니다..." << endl;
		Sleep(1000);
		system("cls");

		print_q();
		print_ex();
		cout << endl;

		cout << "정답을 입력하세오: ";
		cin >> s_an;
		score = solve_answer(s_an);

		cout << "당신의 점수는 " << correct;
	}


};