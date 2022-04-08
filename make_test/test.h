#pragma once

#include <string>
#include<vector>
#include<iostream>
#include<windows.h>
#include<fstream>

using namespace std;

/*테스트의 특징을 모아둔 클래스
필요한 변수
1. 지문
2. 보기
3. 정답*/

class test {
public:
//protected:
	vector<string> question;
	vector<vector<string>> example;
	vector<int> answer;
	int correct;
	ofstream testt;


	test(){
		correct = 0;
	}
	~test(){}

	/*문제를 입력받는 함수
	문제를 받아가지고 벡터에다가 저장해야 한다.*/

	void have_question(int current_num) {
		string q;
		cout << current_num << "번" << endl;
		cout << "문제를 입력하시오" << endl;
		cin.ignore();
		getline(cin, q);
		question.push_back(q);
		testt.open("testt.txt");
		testt << q << endl;
		testt.close();
	}

	void have_example(int num, int ex_num) {
		string ex;
		vector<string> r_example;
		int current_num = 0;
		
		for (int i = current_num; i < num; i++) {
			cout << "보기를 입력하시오" << endl;
			for (int j = 0; j < ex_num; j++) {
				cout << j+1 << ") ";
				getline(cin, ex);
				r_example.push_back(ex);
			}
			example.push_back(r_example);
			current_num++;
			break;
		}
	}

	void have_answer() {
		int an;
		cout << "정답을 입력하시오: " << endl;
	cin >> an;
		answer.push_back(an);
	}

	void print_q(int current) {
		int current_num = 1;
		cout << current_num << "번" << endl;
		cout << question[current] << endl;
		cout << endl;
		current_num++;
	}

	void print_ex(int current, int ex_num) {
		for (int i = 0; i < ex_num; i++) {
			cout << i+1 << ") ";
			cout << example[current][i] << endl;
		}
		cout << endl;
	}

	void print_an() {
		for (int i = 0; i < answer.size(); i++) {
			cout << answer[i] << endl;
		}
		cout << endl;
	}


};