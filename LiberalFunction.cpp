/*교양 과목 함수*/
#include "Lecture.h"
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <locale>

using namespace std;

#define MIN_KOR 44032
#define MAX_KOR 55203
#define HASH_SIZE 700

void linearSearch(vector<Liberal>& liberalList, vector<wstring>& inputLiberal) // 선형 탐색
{
	for (int i = 0; i < inputLiberal.size(); i++)
	{
		for (int j = 0; j < liberalList.size(); j++)
		{
			if (inputLiberal[i] == liberalList[j].getName())
				liberalList[j].setCompleted();
		}
	}
}

bool compare(Liberal l1, Liberal l2)
{
	return l1.getName() < l2.getName();	// 강의명으로 ㄱㄴㄷ 정렬
}

void BinarySearch(vector<Liberal>& liberalList, vector<wstring>& inputLiberal) // 이진 탐색
{

	sort(liberalList.begin(), liberalList.end(), compare); // 이진 탐색을 위해 정렬 먼저 진행

	for (int i = 0; i < inputLiberal.size(); i++)
	{
		int start = 0;
		int end = liberalList.size() - 1;
		int mid;
		while (start <= end)
		{
			mid = (start + end) / 2;

			if (liberalList[mid].getName() == inputLiberal[i])
			{
				liberalList[mid].setCompleted();
				break;
			}
			else if (liberalList[mid].getName() > inputLiberal[i])
				end = mid - 1;
			else
				start = mid + 1;
		}
	}
}

void make1DVector(vector<Liberal>& liberalList, vector<Liberal>& tempVector)
{
	for (int i = 0; i < liberalList.size(); i++)
	{
		for (int j = 0; j < tempVector.size(); j++)
		{
			if (liberalList[i].getCompleted() == true && liberalList[i].getName() == tempVector[j].getName())	// 정렬된 vector와 원래 순서를 가진 vector를 비교하여 원래 순서의 vector에서 setCompleted를 수행
				tempVector[j].setCompleted();
		}
	}
}

int hashing_L(wstring name) {
	int kor_value = 0, other_value = 0;
	int length;
	length = name.length();

	for (int i = 0; i < name.length(); i++) {
		int temp = name[i];

		if (temp >= MIN_KOR && temp <= MAX_KOR) {  // 현재 보고 있는 문자가 한글이면 kor_value에 더함
			kor_value += temp;
		}
		else {
			other_value += temp;   // 아니면 other_value에 더함
			length--;  // 한글이 아닌 문자만큼 length-1
		}
	}
	if (length == 0)
		return other_value % HASH_SIZE;
	return (kor_value + other_value + name.length()) % HASH_SIZE;
}

void make_HT(vector<Liberal*>* liberalHash, vector<Liberal>& liberalList) {
	int hash = 0;

	//해시테이블 구성
	for (int i = 0; i < liberalList.size(); i++) {
		hash = hashing_L(liberalList[i].getName());

		liberalHash[hash].push_back(&liberalList[i]);
	}
}

void set_Complete_Hash(vector<Liberal*>* liberalHash, vector<wstring>& inputList) {
	int hash = 0;

	setlocale(LC_ALL, "korean");

	for (int i = 0; i < inputList.size(); i++) {
		hash = hashing_L(inputList[i]);
		// 하나 뿐이면 바로 갱신
		if (liberalHash[hash].size() == 1) {
			liberalHash[hash].at(0)->setCompleted();
		}
		// 여러 개면 chain을 탐색하여 갱신
		else {
			wstring name = inputList[i];
			for (int i = 0; i < liberalHash[hash].size(); i++) {
				if (liberalHash[hash].at(i)->getName() == name) {
					liberalHash[hash].at(i)->setCompleted();
				}
			}
		}
	}
}

// 공통교양 과목 추출
void extractCommon(vector<Liberal>& liberalList, vector<Liberal>& liberalCommon, vector<Liberal>& liberalCommon_cyber, int semester, int year, int& n) {
	int i;
	int flag = 0;
	n = 0;

	for (i = 0; i < 10; i++) {
		Liberal temp = liberalList[i];
		if (i >= 7 && i <= 9) { 
			if (liberalList[i].getCompleted() == true)
				flag = 1;
		}
		else if (liberalList[i].getCompleted() == false) {
			if (i == 0) {
				if (semester == 1) 
					liberalCommon.push_back(temp);
			}
			else if (i == 1) {
				if (semester == 2) 
					liberalCommon.push_back(temp);
			}
			else 
				liberalCommon.push_back(temp);
		}
	}

	if (semester == 2) {
		if (flag == 0) { // 사이버 강의
			for (int i = 7; i < 10; i++) {
				liberalCommon_cyber.push_back(liberalList[i]);
			}
			n = 1;
		}
	}
}

// 기본소양 과목 추출
void extractNormal(vector<Liberal>& liberalList, vector<wstring>& normalLiberal, int& n) {
	int totalCredit = 9;
	int cnt = 0;
	for (int i = 27; i < 32; i++) {
		if (liberalList[i].getCompleted() == 1) {
			if (totalCredit == 0)
				break;

			totalCredit -= liberalList[i].getCredit();
			cnt++;
		}

	}

	if (totalCredit > 0) {
		for (int i = 27; i < 32; i++) {
			if (liberalList[i].getCompleted() == 0)
				normalLiberal.push_back(liberalList[i].getName());
		}
		if (cnt <= 3)
			n = 3 - cnt;
	}
}

// MSC 수학 과목 추출
void extractMath(int y, vector<Liberal>& liberalList, vector<Liberal>& liberalMath_must, vector<Liberal>& liberalMath, int& n) {
	vector<Liberal> liberalMath_;
	for (int i = 10; i < 17; i++) {
		liberalMath_.push_back(liberalList[i]);
	}

	int sumOfCredit = 0;
	int haveTo = 12;
	// 총 들은 학점 계산
	for (int i = 0; i < liberalMath_.size(); i++) {
		if (liberalMath_[i].getCompleted())
			sumOfCredit += liberalMath_[i].getCredit();
	}

	// 공선대의 경우 따로 처리
	if (y >= 2 && liberalMath_[2].getCompleted() == false) // 2학년 이상이지만 공선대를 안들었을 경우
		liberalMath_must.push_back(liberalMath_[2]); // 무조건 들어야함

	// 수학과목을 필수만큼 수강하지 않음
	if (sumOfCredit < haveTo) {
		for (int i = 0; i < liberalMath_.size(); i++) {
			if (i == 2) // 공선대 뛰어넘음
				continue;
			if (liberalMath_[i].getCompleted() == false) {
				if (liberalMath_[i].getMust() == true) // 필수과목 처리
					liberalMath_must.push_back(liberalMath_[i]);
				else
					liberalMath.push_back(liberalMath_[i]);
			}
		}
		n = (haveTo - sumOfCredit) / 3;
		n -= liberalMath_must.size();
		if (y < 2) // 공선대 처리
			n -= 1;
	}
	else
		n = 0;
}

// MSC 과학 과목 추출
void extractScience(vector<Liberal>& liberalList, vector<Liberal>& liberalExperiment, vector<Liberal>& liberalTheory, int n[2]) {
	n[0] = 0; n[1] = 0;
	vector<Liberal> experiment; // 들은 실험 과목 
	vector<Liberal> theory; // 안 들은 실험 과목 
	for (int i = 17; i <= 22; i++) { // 실험 과목 중에 들은 과목 확인
		if (liberalList[i].getCompleted() == true) experiment.push_back(liberalList[i]);
	}

	if (experiment.size() == 0) {
		for (int i = 17; i <= 22; i++) liberalExperiment.push_back(liberalList[i]); n[0] = 1;
	}

	for (int i = 23; i <= 26; i++) {  // 이론 과목 중에 안 들은 과목이 있는지 체크
		if (liberalList[i].getCompleted() == false)
			theory.push_back(liberalList[i]);
	}

	if (theory.size() > 2) { // 안 들은 과목이 3, 4개면 수강해야 하는 과목 존재
		if (experiment.size() > 0) { // 실험 과목 중 들은 과목이 있는 경우 겹치는 개론 과목 수강 불가
			wstring substr_experiment = experiment[0].getName().substr(2, 2);
			for (int i = 0; i < theory.size(); i++) {
				if (theory[i].getName().substr(0, 2) != substr_experiment) {
					liberalTheory.push_back(theory[i]);
				}
			}
		}
		else {
			for (int i = 0; i < theory.size(); i++) liberalTheory.push_back(theory[i]);
		}
	}

	n[1] = theory.size() - 2;

}