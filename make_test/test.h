#pragma once
#include <string>
#include<vector>
#include<iostream>

using namespace std;

/*������ �޾Ƽ� Ǫ�� class*/
class test {
protected:
	/*����, ����, ������ ���Ϳ��ٰ� �����Ѵ�.
	�̶� ����� row�� 3�� ������ ���ͷ� �����Ѵ�.
	correct�� ������ ���� ��.*/
	vector<string> question;
	vector<vector<string>> example;
	vector<string> answer;
	int correct;

public:

	/*correct �ʱ�ȭ.*/
	test(){
		correct = 0;
	}
	/*�Ҹ���, �ʼ�.*/
	~test(){}

	/*������ �Է¹޴� �Լ�
	������ �޾ư����� ���Ϳ��ٰ� �����ؾ� �Ѵ�.
	getline�� �׳� ���� ������ ����. �� cin.ignore()�� �ʿ��ϴ�.
	cin.ingnore()�� ����ؼ� ������ ������ ������ �Ѵ�.*/
	void have_question(int current_num) {
		string q;
		cout << current_num << "��" << endl;
		cout << "������ �Է��Ͻÿ�" << endl;
		cin.ignore();
		getline(cin, q);
		question.push_back(q);
	}

	/*���⸦ �޴� �Լ�.
	����� row�� 3�� �������迭�� �޴´�.
	�̶� ���� ǥ���ϴ� current_num�� ���⸦ �����ϰ� �ִ� ������ ��ȣ(0���� �����ϴ� �� ���)�̴�.*/
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

	/*������ �޴� �Լ�.
	������ string���� �Է¹޾� push_back�Ѵ�.*/
	void have_answer() {
		string an;
		cout << "������ �Է��Ͻÿ�: " << endl;
		cin >> an;
		answer.push_back(an);
	}

	/*������ ����ϴ� �Լ�.
	curent�� ���� ������ ��� ��ȣ��. current_num�� ���� ������ ����Ǿ� �ִ� ������ ��ġ��.*/
	void print_q(int current, int current_num) {
		cout << current_num << "��" << endl;
		cout << question[current] << endl;
		cout << endl;
	}

	/*���⸦ ����ϴ� �Լ�.
	current�� ���� ����ϰ��� �ϴ� �����̴�.
	���Ⱑ �� �� ������ i�� 0���� 3���� �����ش�.*/
	void print_ex(int current) {
		for (int i = 0; i < 3; i++) {
			cout << i+1 << ") ";
			cout << example[current][i] << endl;
		}
		cout << endl;
	}

	/*������ ����ϴ� �Լ�.*/
	void print_an() {
		for (int i = 0; i < answer.size(); i++) {
			cout << answer[i] << endl;
		}
		cout << endl;
	}

	/*������ ���ϴ� �Լ�.
	a�� �޾Ƽ� answer�� ���� ��� correct�� ++���ش�.
	������ ���ʴ�� ������ �� ����Ѵ�.*/
	void solve_answer(string a, int current) {
		if (a == answer[current]) {
			correct++;
		}
	}

	/*�� ������ ����ϴ� �Լ�.*/
	void show_score() {
		cout << "����� ������ " << correct;
	}

	/*������ Ǫ�� �Լ�.
	������ user�� Ǯ���� �ϸ� �����Ѵ�. 
	i�� ���� ���� ������ ���� ���� ������ �����ش�.
	������ ���⸦ ����ϰ� ������ �޴´�. 
	solve_answer�� ȣ���ؼ� ���� ����� ���� �´��� Ȯ���Ѵ�.*/
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