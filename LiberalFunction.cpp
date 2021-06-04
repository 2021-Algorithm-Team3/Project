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
	return l1.getName() < l2.getName();		// ���Ǹ����� ������ ����
}

void BinarySearch(vector<Liberal>& liberalList, vector<wstring>& inputLiberal)
{

	sort(liberalList.begin(), liberalList.end(), compare);		// ���� Ž���� ���� ���� ���� ����

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

		if (temp >= MIN_KOR && temp <= MAX_KOR) {  // ���� ���� �ִ� ���ڰ� �ѱ��̸� kor_value�� ����
			kor_value += temp;
		}
		else {
			other_value += temp;   // �ƴϸ� other_value�� ����
			length--;  // �ѱ��� �ƴ� ���ڸ�ŭ length-1
		}
	}
	if (length == 0)
		return other_value % HASH_SIZE;
	return (kor_value / length + other_value - MIN_KOR) % HASH_SIZE;
}

void make_HT(vector<Liberal*>* liberalHash, vector<Liberal>& liberalList) {
	int hash = 0;

	//�ؽ����̺� ����
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
		// �ϳ� ���̸� �ٷ� ����
		if (liberalHash[hash].size() == 0) {
			liberalHash[hash].at(0)->setCompleted();
		}
		// ���� ���� chain�� Ž���Ͽ� ����
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

void extractCommon(vector<Liberal> &liberalList, vector<Liberal> &liberalCommon, int semester, int year) {
	int i;

	for (i = 0; i < 10; i++) {
		if (liberalList[i].getCompleted() == false) {
			Liberal temp = liberalList[i];

			if (i == 0) {
				if (semester == 1) // �����
					liberalCommon.push_back(temp);
			}
			else if (i == 1) {
				if (semester == 2)// �ұ����ΰ�
					liberalCommon.push_back(temp);
			}
			else if (i >= 7 && i <= 9) {    //������
				if (semester == 2)
					liberalCommon.push_back(temp);
			}
			else                                     // ������
				liberalCommon.push_back(temp);
		}
	}
}