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

int totalCredit = 0;

void linearSearch(vector<Major>& majorList, vector<wstring>& inputMajor)
{
	for (int i = 0; i < inputMajor.size(); i++)
	{
		for (int j = 0; j < majorList.size(); j++)
		{
			if (inputMajor[i] == majorList[j].getName()) {
				majorList[j].setCompleted();
				totalCredit += majorList[j].getCredit();
			}
				
		}
	}
}

bool compare(Major m1, Major m2)
{
	return m1.getName() < m2.getName();      // 강의명으로 ㄱㄴㄷ 정렬
}

void BinarySearch(vector<Major>& majorList, vector<wstring>& inputMajor)
{

	sort(majorList.begin(), majorList.end(), compare);      // 이진 탐색을 위해 정렬 먼저 진행

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
				majorList[mid].setCompleted();
				totalCredit += majorList[mid].getCredit();
				break;
			}
			else if (majorList[mid].getName() > inputMajor[i])
				end = mid - 1;
			else
				start = mid + 1;
		}
	}
}

int hashing_M(wstring name) {
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

void make_HT(vector<Major*>* majorHash, vector<Major>& majorList) {
	int hash = 0;

	//해시테이블 구성
	for (int i = 0; i < majorList.size(); i++) {
		hash = hashing_M(majorList[i].getName());

		majorHash[hash].push_back(&majorList[i]);   // 각 vector의 길이가 잘못 나오는 오류 발생 중
	}
}

void set_Complete_Hash(vector<Major*>* majorHash, vector<wstring>& inputList) {
	int hash = 0;

	setlocale(LC_ALL, "korean");

	for (int i = 0; i < inputList.size(); i++) {
		hash = hashing_M(inputList[i]);
		// 하나 뿐이면 바로 갱신
		if (majorHash[hash].size() == 0) {
			majorHash[hash].at(0)->setCompleted();
			totalCredit += majorHash[hash].at(0)->getCredit();
		}
		// 여러 개면 chain을 탐색하여 갱신
		else {
			wstring name = inputList[i];
			for (int i = 0; i < majorHash[hash].size(); i++) {
				if (majorHash[hash].at(i)->getName() == name) {
					majorHash[hash].at(i)->setCompleted();
					totalCredit += majorHash[hash].at(i)->getCredit();
				}
			}
		}
	}
}

void make2Dvector(vector<Major>& majorList, vector<vector<Major>>& tempInfo, vector<vector<Major>>& majorInfo) { // 과목 추출 시 필요한 2차원 벡터(majorInfo) 생성
	majorInfo = tempInfo;
	for (int i = 0; i < tempInfo.size(); i++) {
		for (int j = 0; j < tempInfo[i].size(); j++) {
			int k;
			for (k = 0; k < majorList.size(); k++) {
				if (tempInfo[i][j].getName() == majorList[k].getName()) { break; }
			}
			majorInfo[i][j] = majorList[k];
		}
	}
}

void subjectExtraction(int y, int s, vector<vector<Major>>& majorInfo, vector<wstring>& inputList, vector<Major>& outputList, vector<Major>& replaceList) {
	int end_idx, maxCredit, sumOfCredit = 0;
	end_idx = (s == 1 ? 2 * (y - 1) : 2 * (y - 1) + 1); //등록 예정 학년학기에 따라 majorInfo 검사 시 몇번째 index까지 검사할지를 결정
	vector<Major> tempList; // 임시 벡터

	for (int i = 0; i <= end_idx; i++) {
		for (int j = 0; j < majorInfo[i].size(); j++) {
			int semester = majorInfo[i][j].getSemester();
			if (semester == 0 || semester == s) {
				if (majorInfo[i][j].getCompleted() == false) {
					if (majorInfo[i][j].getPriorLecture() == L"") {
						tempList.push_back(majorInfo[i][j]);
						sumOfCredit += majorInfo[i][j].getCredit();
					}
					else { // 선이수과목이 있는 경우
						int flag = 0;
						for (int k = 0; k < inputList.size(); k++) {
							if (majorInfo[i][j].getPriorLecture() == inputList[k]) { flag = 1; break; } // 선이수과목을 수강한 경우
						}
						if (flag == 1) {
							tempList.push_back(majorInfo[i][j]);
							sumOfCredit += majorInfo[i][j].getCredit();
						}
					}
				}
			}
		}
	}

	/*
	(1) 1,2학년이면서 추천 전공 학점이 15학점 이상인 경우
	(2) 3,4학년이면서 추천 전공 학점이 24학점 이상인 경우
	등록예정 학년, 학기 가운데 필수 전공 과목이 아닌 과목 가운데 일부를 제외하고
	이를 대체 가능 리스트에 넣어줌
	*/

	if (end_idx < 4) maxCredit = 15; // (1)
	else if (84 - totalCredit < 24) { maxCredit = 84 - totalCredit; }
	else maxCredit = 24; // (2)

	if (sumOfCredit >= maxCredit) {

		for (int i = tempList.size() - 1; i >= 0; i--) {
			if (sumOfCredit < maxCredit) break;
			if (tempList[i].getMust() == false) { // 필수 전공이 아니면 대체 가능 리스트(replaceList)에 추가
				replaceList.push_back(tempList[i]);
				sumOfCredit -= tempList[i].getCredit();
			}
		}
	}

	// 공대전공 처리
	for (int i = 0; i < majorInfo[8].size(); i++) {
		if (i >= 0 && i <= 2 && majorInfo[8][i].getCompleted() == false ) { // 개별연구 필수 처리
			if(majorInfo[8][i].getMust() == true)
				outputList.push_back(majorInfo[8][i]);
			else
				replaceList.push_back(majorInfo[8][i]);
			i = 2;
		}
		else if (majorInfo[8][i].getCompleted() == false) {
			if (majorInfo[8][i].getSemester() == 0 || majorInfo[8][i].getSemester() == s)
				replaceList.push_back(majorInfo[8][i]);
		}
	}

	// replaceList에 들어간 과목을 제외하고 outputList에 추가
	for (int i = 0; i < tempList.size(); i++) {
		int flag = 0;
		for (int j = 0; j < replaceList.size(); j++) {
			if (tempList[i].getName() == replaceList[j].getName()) { flag = 1; break; }
		}
		if (flag == 0) outputList.push_back(tempList[i]);
	}
}