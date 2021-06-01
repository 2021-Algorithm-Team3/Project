#include "Lecture.h"
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <locale>

using namespace std;

#define MIN_KOR 44032
#define MAX_KOR 55203
#define HASH_SIZE 100

void linearSearch(vector<Major>& majorList, vector<wstring>& inputMajor)
{
	for (int i = 0; i < inputMajor.size(); i++)
	{
		for (int j = 0; j < majorList.size(); j++)
		{
			if (inputMajor[i] == majorList[j].getName())
				//majorList[j].setCompleted(majorList[j]);
				majorList[j].setCompleted();
		}
	}
}

bool compare(Major m1, Major m2)
{
	return m1.getName() < m2.getName();		// 강의명으로 ㄱㄴㄷ 정렬
}

void BinarySearch(vector<Major>& majorList, vector<wstring>& inputMajor)
{
	sort(majorList.begin(), majorList.end(), compare);		// 이진 탐색을 위해 정렬 먼저 진행

	for (int i = 0; i < inputMajor.size(); i++)
	{
		int start = 0;
		int end = majorList.size() - 1;
		int mid;
		while (start <= end)
		{
			mid = (start + end) / 2;

			if (majorList[mid].getName() == inputMajor[i])
			{
				//majorList[mid].setCompleted(majorList[mid]);
				majorList[mid].setCompleted();
				break;
			}
			else if (majorList[mid].getName() > inputMajor[i])
				end = mid - 1;
			else
				start = mid + 1;
		}
	}
}

int hashing(wstring name) {
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

void make_HT(vector<Major> *majorHash, vector<Major> &majorList) {
	int hash = 0;

	//해시테이블 구성
	for (int i = 0; i < majorList.size(); i++) {
		hash = hashing(majorList[i].getName());

		majorHash[hash].push_back(majorList[i]);   // 각 vector의 길이가 잘못 나오는 오류 발생 중
	}
}

void set_Complete_Hash(vector<Major> *majorHash, vector<wstring> &inputList) {
	int hash = 0;

	setlocale(LC_ALL, "korean");

	for (int i = 0; i < inputList.size(); i++) {
		hash = hashing(inputList[i]);
		// 하나 뿐이면 바로 갱신
		if (majorHash[hash].size() == 0) {
			majorHash[hash].at(0).setCompleted();
		}
		// 여러 개면 chain을 탐색하여 갱신
		else {
			wstring name = inputList[i];
			for (int i = 0; i < majorHash[hash].size(); i++) {
				if (majorHash[hash].at(i).getName() == name) {
					majorHash[hash].at(i).setCompleted();
				}
			}
		}
	}
}
