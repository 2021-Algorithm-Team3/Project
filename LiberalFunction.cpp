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
	return (kor_value / length + other_value - MIN_KOR) % HASH_SIZE;
}

void make_HT(vector<Liberal>* liberalHash, vector<Liberal>& liberalList) {
	int hash = 0;

	//�ؽ����̺� ����
	for (int i = 0; i < liberalList.size(); i++) {
		hash = hashing_L(liberalList[i].getName());

		liberalHash[hash].push_back(liberalList[i]);   // �� vector�� ���̰� �߸� ������ ���� �߻� ��
	}
}

void set_Complete_Hash(vector<Liberal>* liberalHash, vector<wstring>& inputList) {
	int hash = 0;

	setlocale(LC_ALL, "korean");

	for (int i = 0; i < inputList.size(); i++) {
		hash = hashing_L(inputList[i]);
		// �ϳ� ���̸� �ٷ� ����
		if (liberalHash[hash].size() == 0) {
			liberalHash[hash].at(0).setCompleted();
		}
		// ���� ���� chain�� Ž���Ͽ� ����
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
	vector<Liberal> experiment; // ���� ���� ���� 
	vector<Liberal> theory; // �� ���� ���� ���� 
	for (int i = 17; i <= 22; i++) { // ���� ���� �߿� ���� ���� Ȯ��
		if (liberalList[i].getCompleted() == true) experiment.push_back(liberalList[i]);
	}

	if (experiment.size() == 0) {
		for (int i = 17; i <= 22; i++) liberalExperiment.push_back(liberalList[i]); n[0] = 1;
	}

	for (int i = 23; i <= 26; i++) {  // �̷� ���� �߿� �� ���� ������ �ִ��� üũ
		if (liberalList[i].getCompleted() == false) 
			theory.push_back(liberalList[i]); 
	}

	if (theory.size() > 2) { // �� ���� ������ 3, 4���� �����ؾ� �ϴ� ���� ����
		if (experiment.size() > 0) { // ���� ���� �� ���� ������ �ִ� ��� ��ġ�� ���� ���� ���� �Ұ�
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