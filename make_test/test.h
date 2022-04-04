#pragma once
#include <string>
#include<vector>
#include<iostream>

using namespace std;

/*문제를 받아서 푸는 class*/
class test {
protected:
	/*질문, 보기, 정답을 벡터에다가 저장한다.
	이때 보기는 row가 3인 이차원 벡터로 저장한다.
	correct는 문제를 맞춘 수.*/
	vector<string> question;
	vector<vector<string>> example;
	vector<string> answer;
	int correct;

public:

	/*correct 초기화.*/
	test(){
		correct = 0;
	}
	/*소멸자, 필수.*/
	~test(){}

	/*문제를 입력받는 함수
	문제를 받아가지고 벡터에다가 저장해야 한다.
	getline을 그냥 쓰면 오류가 난다. 꼭 cin.ignore()이 필요하다.
	cin.ingnore()을 사용해서 버퍼의 내용을 지워야 한다.*/
	void have_question(int current_num) {
		string q;
		cout << current_num << "번" << endl;
		cout << "문제를 입력하시오" << endl;
		cin.ignore();
		getline(cin, q);
		question.push_back(q);
	}

	/*보기를 받는 함수.
	보기는 row가 3인 이차원배열로 받는다.
	이때 행을 표시하는 current_num은 보기를 저장하고 있는 문제의 번호(0부터 시작하는 걸 고려)이다.*/
	void have_example(int num) {
		string ex;
		vector<string> r_example;
		int current_num = 0;
		int ex_num = 1;
		
		for (int i = current_num; i < num; i++) {
			cout << "보기를 입력하시오" << endl;
			for (int j = 0; j < 3; j++) {
				cout << ex_num << ") ";
				cin >> ex;
				r_example.push_back(ex);
				ex_num++;
			}
			example.push_back(r_example);
			ex_num = 1;
			current_num++;
			break;
		}
	}

	/*정답을 받는 함수.
	정답을 string으로 입력받아 push_back한다.*/
	void have_answer() {
		string an;
		cout << "정답을 입력하시오: " << endl;
		cin >> an;
		answer.push_back(an);
	}

	/*질문을 출력하는 함수.
	curent는 현재 문제의 출력 번호다. current_num은 현재 문제가 저장되어 있는 벡터의 위치다.*/
	void print_q(int current, int current_num) {
		cout << current_num << "번" << endl;
		cout << question[current] << endl;
		cout << endl;
	}

	/*보기를 출력하는 함수.
	current는 현재 출력하고자 하는 문제이다.
	보기가 총 세 개여서 i를 0부터 3까지 돌려준다.*/
	void print_ex(int current) {
		for (int i = 0; i < 3; i++) {
			cout << i+1 << ") ";
			cout << example[current][i] << endl;
		}
		cout << endl;
	}

	/*문제를 출력하는 함수.*/
	void print_an() {
		for (int i = 0; i < answer.size(); i++) {
			cout << answer[i] << endl;
		}
		cout << endl;
	}

	/*정답을 비교하는 함수.
	a를 받아서 answer과 맞을 경우 correct를 ++해준다.
	문제가 차례대로 나오는 걸 고려한다.*/
	void solve_answer(string a, int current) {
		if (a == answer[current]) {
			correct++;
		}
	}

	/*총 점수를 출력하는 함수.*/
	void show_score() {
		cout << "당신의 점수는 " << correct;
	}

	/*문제를 푸는 함수.
	문제를 user가 풀고자 하면 실행한다. 
	i가 받은 문제 갯수와 같지 않을 때까지 돌려준다.
	문제와 보기를 출력하고 정답을 받는다. 
	solve_answer을 호출해서 받은 정답과 답이 맞는지 확인한다.*/
	void solve_problem(int num) {
		string s_an;
		int score;
		int i = 0;
		int current_num = 1;

		cout << "문제를 확인합니다..." << endl;
		Sleep(1000);
		system("cls");

		while (i != num) {
			print_q(i, current_num);
			print_ex(i);

			cout << "정답을 입력하세오: ";
			cin >> s_an;
			solve_answer(s_an, i);
			cout << endl;
			system("cls");
			i++;
			current_num++;
		}
		
	}


};