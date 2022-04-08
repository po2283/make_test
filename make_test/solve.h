#pragma once

#include "test.h"

using namespace std;

class solve : test {
protected:
	int correct;
public:
	solve(){
		correct = 0;
	}
	~solve(){}

	void solve_answer(int a, int current) {
		if (a == answer[current]) {
			correct++;
		}
	}

	void show_score() {
		cout << "당신의 점수는 " << correct;
	}

	void solve_problem(int num, int ex_num) {
		int s_an;
		int score;
		int i = 0;
		int current_num = 1;
		
		cout << "문제를 확인합니다..." << endl;
		Sleep(1000);
		system("cls");

		while (i != num) {
			print_q(&i);
			print_ex(i, ex_num);

			cout << "정답을 입력하세요: ";
			cin >> s_an;
			solve_answer(s_an, i);
			cout << endl;
			system("cls");
			i++;
		}
	}
};
