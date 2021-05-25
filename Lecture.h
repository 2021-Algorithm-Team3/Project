#include <string>
#ifndef LECTURE_H
#define LECTURE_H
using namespace std;
class Major {
	string name; // 과목명
	int credit; // 학점
	string prior_lecture; // 직전 선 이수 과목명
	bool must; // 필수 여부
	bool completed; // 들은 과목인지 여부
public:
	Major(string name, int credit, string prior_lecture, bool must, bool completed);
	string getName();
	int getCredit();
	string getPriorLecture();
	bool getMust();
	bool getCompleted();
	void setCompleted(Major m);
};

class Liberal {
private:
	string name; // 과목명
	int credit; // 학점
	bool must; // 필수 여부
	bool completed; // 들은 과목인지 여부
public:
	Liberal(string name, int credit, bool must, bool completed);
	string getName();
	int getCredit();
	bool getMust();
	bool getCompleted();
	void setCompleted(Liberal l);
};


#endif //LECTURE_H
