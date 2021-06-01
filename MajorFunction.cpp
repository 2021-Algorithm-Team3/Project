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
	return m1.getName() < m2.getName();		// ���Ǹ����� ������ ����
}

void BinarySearch(vector<Major>& majorList, vector<wstring>& inputMajor)
{
	sort(majorList.begin(), majorList.end(), compare);		// ���� Ž���� ���� ���� ���� ����

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

		if (temp >= MIN_KOR && temp <= MAX_KOR) {  // ���� ���� �ִ� ���ڰ� �ѱ��̸� kor_value�� ����
			kor_value += temp;
		}
		else {
			other_value += temp;   // �ƴϸ� other_value�� ����
			length--;  // �ѱ��� �ƴ� ���ڸ�ŭ length-1
		}
	}
	return (kor_value / length + other_value - MIN_KOR) % HASH_SIZE;
}

void make_HT(vector<Major> *majorHash, vector<Major> &majorList) {
	int hash = 0;

	//�ؽ����̺� ����
	for (int i = 0; i < majorList.size(); i++) {
		hash = hashing(majorList[i].getName());

		majorHash[hash].push_back(majorList[i]);   // �� vector�� ���̰� �߸� ������ ���� �߻� ��
	}
}

void set_Complete_Hash(vector<Major> *majorHash, vector<wstring> &inputList) {
	int hash = 0;

	setlocale(LC_ALL, "korean");

	for (int i = 0; i < inputList.size(); i++) {
		hash = hashing(inputList[i]);
		// �ϳ� ���̸� �ٷ� ����
		if (majorHash[hash].size() == 0) {
			majorHash[hash].at(0).setCompleted();
		}
		// ���� ���� chain�� Ž���Ͽ� ����
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
