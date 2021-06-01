#include <string>
#include "Lecture.h"

Major::Major(wstring name, int credit, wstring prior_lecture, bool must, bool completed) {
	this->name = name;
	this->credit = credit;
	this->prior_lecture = prior_lecture;
	this->must = must;
	this->completed = completed;
}

wstring Major::getName() {
	return name;
}

int Major::getCredit() {
	return credit;
}

wstring Major::getPriorLecture() {
	return prior_lecture;
}

bool Major::getMust() {
	return must;
}

bool Major::getCompleted() {
	return completed;
}

void Major::setCompleted(Major& m) {
	m.completed = 1;
}

//=======================================================================================================================================//

Liberal::Liberal(string name, int credit, bool must, bool completed) {
	this->name = name;
	this->credit = credit;
	this->must = must;
	this->completed = completed;
}

string Liberal::getName() {
	return name;
}

int Liberal::getCredit() {
	return credit;
}

bool Liberal::getMust() {
	return must;
}

bool Liberal::getCompleted() {
	return completed;
}

void Liberal::setCompleted(Liberal l) {
	l.completed = 1;
}