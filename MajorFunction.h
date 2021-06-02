#pragma once
#include <vector>
#include <string>
#include "Lecture.h"

// ���� Ž��
void linearSearch(vector<Major>& majorList, vector<wstring>& inputMajor);

// ���� Ž��
void BinarySearch(vector<Major>& majorList, vector<wstring>& inputMajor);

bool compare(Major m1, Major m2);

// �ؽø� �̿��� Ž��
int hashing(wstring name);

void make_HT(vector<Major>* majorHash, vector<Major>& majorList);

void set_Complete_Hash(vector<Major>* majorHash, vector<wstring>& inputList);

// ���� ����
void make2Dvector(vector<Major>& majorList, vector<vector<Major>>& tempInfo, vector<vector<Major>>& majorInfo);

void subjectExtraction(int y, int s, vector<vector<Major>>& majorInfo, vector<wstring>& inputList, vector<Major>& outputList, vector<Major>& replaceList);