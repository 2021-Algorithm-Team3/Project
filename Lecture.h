#pragma once
#include <string>
#ifndef LECTURE_H
#define LECTURE_H
using namespace std;
class Major {
	wstring name; // �����
	int credit; // ����
	wstring prior_lecture; // ���� �� �̼� �����
	bool must; // �ʼ� ����
	bool completed; // ���� �������� ����
public:
	Major(wstring name, int credit, wstring prior_lecture, bool must, bool completed);
	wstring getName();
	int getCredit();
	wstring getPriorLecture();
	bool getMust();
	bool getCompleted();
	//void setCompleted(Major& m);
	void setCompleted();

	Major *next = NULL;
};

class Liberal {
private:
	string name; // �����
	int credit; // ����
	bool must; // �ʼ� ����
	bool completed; // ���� �������� ����
public:
	Liberal(string name, int credit, bool must, bool completed);
	string getName();
	int getCredit();
	bool getMust();
	bool getCompleted();
	void setCompleted(Liberal l);
};


#endif //LECTURE_H