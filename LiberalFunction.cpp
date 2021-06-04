#include "Lecture.h"
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <locale>

using namespace std;

#define MIN_KOR 44032
#define MAX_KOR 55203
#define HASH_SIZE 50

void linearSearch(vector<Liberal>& liberalList, vector<wstring>& inputLiberal)
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
	return l1.getName() < l2.getName();		// 강의명으로 ㄱㄴㄷ 정렬
}

void BinarySearch(vector<Liberal>& liberalList, vector<wstring>& inputLiberal)
{

	sort(liberalList.begin(), liberalList.end(), compare);		// 이진 탐색을 위해 정렬 먼저 진행

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
	return (kor_value / length + other_value - MIN_KOR) % HASH_SIZE;
}

void make_HT(vector<Liberal>* liberalHash, vector<Liberal>& liberalList) {
	int hash = 0;

	//해시테이블 구성
	for (int i = 0; i < liberalList.size(); i++) {
		hash = hashing_L(liberalList[i].getName());

		liberalHash[hash].push_back(liberalList[i]);   // 각 vector의 길이가 잘못 나오는 오류 발생 중
	}
}

void set_Complete_Hash(vector<Liberal>* liberalHash, vector<wstring>& inputList) {
	int hash = 0;

	setlocale(LC_ALL, "korean");

	for (int i = 0; i < inputList.size(); i++) {
		hash = hashing_L(inputList[i]);
		// 하나 뿐이면 바로 갱신
		if (liberalHash[hash].size() == 0) {
			liberalHash[hash].at(0).setCompleted();
		}
		// 여러 개면 chain을 탐색하여 갱신
		else {
			wstring name = inputList[i];
			for (int i = 0; i < liberalHash[hash].size(); i++) {
				if (liberalHash[hash].at(i).getName() == name) {
					liberalHash[hash].at(i).setCompleted();
				}
			}
		}
	}
}

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