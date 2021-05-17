#include "Lecture.h"

Major::Major(string name, int credit, string prior_lecture, bool must, bool completed = 0) {
    this->name = name;
    this->credit = credit;
    this->prior_lecture = prior_lecture;
}