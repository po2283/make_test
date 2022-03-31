#pragma once
#include <string>
#include<vector>
#include<iostream>

using namespace std;

/*�׽�Ʈ�� Ư¡�� ��Ƶ� Ŭ����
�ʿ��� ����
1. ����
2. ����
3. ����*/

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

	/*������ �Է¹޴� �Լ�
	������ �޾ư����� ���Ϳ��ٰ� �����ؾ� �Ѵ�.*/

	void have_question() {
		string q;
		cout << "������ �Է��Ͻÿ�" << endl;
		getline(cin, q);
		question.push_back(q);
	}

	void have_example() {
		string ex;
		cout << "���⸦ �Է��Ͻÿ�" << endl;
		for (int i = 0; i < 3; i++) {
			cin >> ex;
			example.push_back(ex);
		}
	}

	void have_answer() {
		string an;
		cout << "������ �Է��Ͻÿ�: " << endl;
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

		cout << "������ Ȯ���մϴ�..." << endl;
		Sleep(1000);
		system("cls");

		print_q();
		print_ex();
		cout << endl;

		cout << "������ �Է��ϼ���: ";
		cin >> s_an;
		score = solve_answer(s_an);

		cout << "����� ������ " << correct;
	}


};