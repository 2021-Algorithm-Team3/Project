#pragma once
#include <vector>
#include <string>
#include "Lecture.h"

// 선형 탐색
void linearSearch(vector<Liberal>& liberalList, vector<wstring>& inputLiberal);

// 이진 탐색
void BinarySearch(vector<Liberal>& liberalList, vector<wstring>& inputLiberal);

bool compare(Liberal l1, Liberal l2);

// 해시를 이용한 탐색
int hashing_L(wstring name);

void make_HT(vector<Liberal>* liberalHash, vector<Liberal>& liberalList);

void set_Complete_Hash(vector<Liberal>* liberalHash, vector<wstring>& inputList);

// 과목 추출

