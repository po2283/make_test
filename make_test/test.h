#pragma once
#include <string>

using namespace std;

/*테스트의 특징을 모아둔 클래스
필요한 변수
1. 지문
2. 보기
3. 정답*/

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