#pragma once
#include <string>

using namespace std;

/*�׽�Ʈ�� Ư¡�� ��Ƶ� Ŭ����
�ʿ��� ����
1. ����
2. ����
3. ����*/

class test {
protected:
	string question;
	string example;
	string answer;
public:


	test(){
		question = "";
		example = "";
		answer = "";
	}
	~test(){}

	test(string q, string ex, string an) {
		this->question = q;
		this->example = ex;
		this->answer = an;
	}

	void print() {
		cout << "question: " << question << endl << "example: " << example << endl << "answer: " << answer << endl;

	}

};