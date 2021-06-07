#include "Lecture.h"
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <locale>

using namespace std;

#define MIN_KOR 44032
#define MAX_KOR 55203
#define HASH_SIZE 1000

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
	return m1.getName() < m2.getName();      // ���Ǹ����� ������ ����
}

void BinarySearch(vector<Major>& majorList, vector<wstring>& inputMajor)
{

	sort(majorList.begin(), majorList.end(), compare);      // ���� Ž���� ���� ���� ���� ����

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

		if (temp >= MIN_KOR && temp <= MAX_KOR) {  // ���� ���� �ִ� ���ڰ� �ѱ��̸� kor_value�� ����
			kor_value += temp;
		}
		else {
			other_value += temp;   // �ƴϸ� other_value�� ����
			length--;  // �ѱ��� �ƴ� ���ڸ�ŭ length-1
		}
	}
	return (kor_value + other_value + name.length()) % HASH_SIZE;
}

void make_HT(vector<Major*>* majorHash, vector<Major>& majorList) {
	int hash = 0;

	//�ؽ����̺� ����
	for (int i = 0; i < majorList.size(); i++) {
		hash = hashing_M(majorList[i].getName());

		majorHash[hash].push_back(&majorList[i]);   // �� vector�� ���̰� �߸� ������ ���� �߻� ��
	}
}

void set_Complete_Hash(vector<Major*>* majorHash, vector<wstring>& inputList) {
	int hash = 0;

	setlocale(LC_ALL, "korean");

	for (int i = 0; i < inputList.size(); i++) {
		hash = hashing_M(inputList[i]);
		// �ϳ� ���̸� �ٷ� ����
		if (majorHash[hash].size() == 1) {
			majorHash[hash].at(0)->setCompleted();
			totalCredit += majorHash[hash].at(0)->getCredit();
		}
		// ���� ���� chain�� Ž���Ͽ� ����
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

void make2Dvector(vector<Major>& majorList, vector<vector<Major>>& tempInfo, vector<vector<Major>>& majorInfo) { // ���� ���� �� �ʿ��� 2���� ����(majorInfo) ����
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
	end_idx = (s == 1 ? 2 * (y - 1) : 2 * (y - 1) + 1); //��� ���� �г��б⿡ ���� majorInfo �˻� �� ���° index���� �˻������� ����
	vector<Major> tempList; // �ӽ� ����

	for (int i = 0; i <= end_idx; i++) {
		for (int j = 0; j < majorInfo[i].size(); j++) {
			int semester = majorInfo[i][j].getSemester();
			if (semester == 0 || semester == s) {
				if (majorInfo[i][j].getCompleted() == false) {
					if (majorInfo[i][j].getPriorLecture() == L"") {
						tempList.push_back(majorInfo[i][j]);
						sumOfCredit += majorInfo[i][j].getCredit();
					}
					else { // ���̼������� �ִ� ���
						int flag = 0;
						for (int k = 0; k < inputList.size(); k++) {
							if (majorInfo[i][j].getPriorLecture() == inputList[k]) { flag = 1; break; } // ���̼������� ������ ���
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
	(1) 1,2�г��̸鼭 ��õ ���� ������ 15���� �̻��� ���
	(2) 3,4�г��̸鼭 ��õ ���� ������ 24���� �̻��� ���
	��Ͽ��� �г�, �б� ��� �ʼ� ���� ������ �ƴ� ���� ��� �Ϻθ� �����ϰ�
	�̸� ��ü ���� ����Ʈ�� �־���
	*/

	if (end_idx < 4) maxCredit = 15; // (1)
	else maxCredit = 24; // (2)

	if (sumOfCredit >= maxCredit) {

		for (int i = tempList.size() - 1; i >= 0; i--) {
			if (sumOfCredit < maxCredit) break;
			if (tempList[i].getMust() == false) { // �ʼ� ������ �ƴϸ� ��ü ���� ����Ʈ(replaceList)�� �߰�
				replaceList.push_back(tempList[i]);
				sumOfCredit -= tempList[i].getCredit();
			}
		}
	}

	// �������� ó��
	for (int i = 0; i < majorInfo[8].size(); i++) {
		if (i >= 0 && i <= 2 && majorInfo[8][i].getCompleted() == false ) { // �������� �ʼ� ó��
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

	// replaceList�� �� ������ �����ϰ� outputList�� �߰�
	for (int i = 0; i < tempList.size(); i++) {
		int flag = 0;
		for (int j = 0; j < replaceList.size(); j++) {
			if (tempList[i].getName() == replaceList[j].getName()) { flag = 1; break; }
		}
		if (flag == 0) outputList.push_back(tempList[i]);
	}
}