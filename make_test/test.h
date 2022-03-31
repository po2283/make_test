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

	test(){}
	~test(){}

	/*문제를 입력받는 함수
	문제를 받아가지고 벡터에다가 저장해야 한다.*/

	void have_question(string q) {
		question.push_back(q);
	}

	void have_example(string ex) {
		example.push_back(ex);
	}

	void have_answer(string an) {
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
};