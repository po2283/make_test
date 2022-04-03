#pragma once
#include <string>
#include<vector>
#include<iostream>

using namespace std;

class test {
protected:
	vector<string> question;
	vector<vector<string>> example;
	vector<string> answer;
	int correct;

public:

	test(){
		correct = 0;
	}
	~test(){}

	/*������ �Է¹޴� �Լ�
	������ �޾ư����� ���Ϳ��ٰ� �����ؾ� �Ѵ�.*/

	void have_question(int current_num) {
		string q;
		cout << current_num << "��" << endl;
		cout << "������ �Է��Ͻÿ�" << endl;
		cin.ignore();
		getline(cin, q);
		question.push_back(q);
	}

	void have_example(int num) {
		string ex;
		vector<string> r_example;
		int current_num = 0;
		int ex_num = 1;
		
		for (int i = current_num; i < num; i++) {
			cout << "���⸦ �Է��Ͻÿ�" << endl;
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

	void have_answer() {
		string an;
		cout << "������ �Է��Ͻÿ�: " << endl;
		cin >> an;
		answer.push_back(an);
	}

	void print_q(int current, int current_num) {
		cout << current_num << "��" << endl;
		cout << question[current] << endl;
		cout << endl;
	}

	void print_ex(int current) {
		for (int i = 0; i < 3; i++) {
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

	void solve_answer(string a, int current) {
		if (a == answer[current]) {
			correct++;
		}
	}

	void show_score() {
		cout << "����� ������ " << correct;
	}

	void solve_problem(int num) {
		string s_an;
		int score;
		int i = 0;
		int current_num = 1;

		cout << "������ Ȯ���մϴ�..." << endl;
		Sleep(1000);
		system("cls");

		while (i != num) {
			print_q(i, current_num);
			print_ex(i);

			cout << "������ �Է��ϼ���: ";
			cin >> s_an;
			solve_answer(s_an, i);
			cout << endl;
			system("cls");
			i++;
			current_num++;
		}
		
	}


};