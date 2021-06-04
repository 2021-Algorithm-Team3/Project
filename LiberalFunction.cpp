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

void extractNormal(vector<Liberal>& liberalList, vector<wstring>& normalLiberal, int& n)
{
	int totalCredit = 9;		// 소양 과목은 총 3개, 9학점을 들어야 함
	int cnt = 0;
	for (int i = 27; i < 32; i++)
	{
		if (liberalList[i].getCompleted() == 1)
		{
			if (totalCredit == 0)		// 만약 다 들었으면 더 이상 검사할 필요 없음
				break;

			totalCredit -= liberalList[i].getCredit();		// 수강한 과목이면 전체 9학점에서 해당 학점 만큼 빼줌
			cnt++;		// 들은 과목의 갯수를 셈
		}
			
	}

	if (totalCredit > 0)		// 9학점에서 학점이 남았다면 들어야 할 과목이 있다는 것
	{
		for (int i = 27; i < 32; i++)
		{
			if (liberalList[i].getCompleted() == 0)
				normalLiberal.push_back(liberalList[i].getName());		// 안 들은 과목을 벡터에 담아줌
		}
		if (cnt <= 3)
			n = 3 - cnt;		// 안 들은 과목 중에 몇 개를 들어야 하는지 계산
	}
}