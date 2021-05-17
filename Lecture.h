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
    Major(string name, int credit, string prior_lecture, bool must, bool completed = 0);
};

class Liberal {
    string name; // 과목명
    int credit; // 학점
    bool must; // 필수 여부
    bool completed; // 들은 과목인지 여부
};
#endif //LECTURE_H
