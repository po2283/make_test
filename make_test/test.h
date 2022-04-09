#pragma once
#include <string>
#include<vector>
#include<iostream>
#include<map>
using namespace std;

/*테스트의 특징을 모아둔 클래스
필요한 변수
1. 지문
2. 보기
3. 정답*/

class test {
protected:
	map<int, string> question;
	map<int, vector<string>> example;
	map<int, int> answer;
	int correct;

public:

	test(){
		correct = 0;
	}
	~test(){}

	void have_question(int current_num) {
		string q;
		cout << current_num << "번" << endl;
		cout << "문제를 입력하시오" << endl;
		cin.ignore();
		getline(cin, q);
		question.insert(make_pair(current_num, q));
	}

	void have_example(int current_num, int num, int ex_num) {
		string ex;
		vector<string> r_example;

		for (int i = current_num; i <= num; i++) {
			cout << "보기를 입력하시오" << endl;
			for (int j = 0; j < ex_num; j++) {
				cout << j+1 << ") ";
				getline(cin, ex);
				r_example.push_back(ex);
			}
			example.insert(make_pair(current_num, r_example));
			break;
		}
	}

	void have_answer(int current_num) {
		int an;
		cout << "정답을 입력하시오: " << endl;
		cin >> an;
		answer.insert(make_pair(current_num, an));
	}

	void print_q(int current) {
		cout << current << "번" << endl;
		auto q = question.find(current);
		if (q != question.end()) {
			cout << q->second << endl;
		}
	}

	void print_ex(int current, int ex_num) {
		for (int i = 0; i < ex_num; i++) {
			cout << i+1 << ") ";
			cout << example[current][i] << endl;
		}
		cout << endl;
	}

	/*
	void print_an() {
		for (int i = 0; i < answer.size(); i++) {
			cout << answer[i] << endl;
		}
		cout << endl;
	}
	*/

	void solve_answer(int current, int an) {
		if (an == answer[current]) {
			correct++;
		}
	}

	void show_score() {
		cout << "당신의 점수는 " << correct;
	}

	void solve_problem(int num, int ex_num) {
		int s_an;
		int score;
		int i = 1;

		cout << "문제를 확인합니다..." << endl;
		Sleep(1000);
		system("cls");

		while (i != num+1) {
			print_q(i);
			print_ex(i, ex_num);

			cout << "정답을 입력하세오: ";
			cin >> s_an;
			solve_answer(i, s_an);
			cout << endl;
			system("cls");
			i++;
		}
		
	}


};