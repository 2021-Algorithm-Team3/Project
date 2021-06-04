#pragma once
#include <string>
#ifndef LECTURE_H
#define LECTURE_H
using namespace std;
class Major {
	wstring name; // 과목명
	int credit; // 학점
	wstring prior_lecture; // 직전 선 이수 과목명
	bool must; // 필수 여부
	bool completed; // 들은 과목인지 여부
public:
	Major(wstring name, int credit, wstring prior_lecture, bool must, bool completed);
	wstring getName();
	int getCredit();
	wstring getPriorLecture();
	bool getMust();
	bool getCompleted();
	//void setCompleted(Major& m);
	void setCompleted();

	Major* next = NULL;
};

class Liberal {
private:
	wstring name; // 과목명
	int credit; // 학점
	bool must; // 필수 여부
	bool completed; // 들은 과목인지 여부
public:
	Liberal(wstring name, int credit, bool must, bool completed);
	wstring getName();
	int getCredit();
	bool getMust();
	bool getCompleted();
	void setCompleted();
};

#endif //LECTURE_H