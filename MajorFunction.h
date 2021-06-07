#pragma once
#include <vector>
#include <string>
#include "Lecture.h"

// 선형 탐색
void linearSearch(vector<Major>& majorList, vector<wstring>& inputMajor);

// 이진 탐색
void BinarySearch(vector<Major>& majorList, vector<wstring>& inputMajor);

bool compare(Major m1, Major m2);

// 해시를 이용한 탐색
int hashing_M(wstring name);

void make_HT(vector<Major*>* majorHash, vector<Major>& majorList);

void set_Complete_Hash(vector<Major*>* majorHash, vector<wstring>& inputList);

// 과목 추출
void make2Dvector(vector<Major>& majorList, vector<vector<Major>>& tempInfo, vector<vector<Major>>& majorInfo);

void subjectExtraction(int y, int s, vector<vector<Major>>& majorInfo, vector<wstring>& inputList, vector<Major>& outputList, vector<Major>& replaceList);
