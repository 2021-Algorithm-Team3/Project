#pragma once
#include <vector>
#include <string>
#include "Lecture.h"

// ���� Ž��
void linearSearch(vector<Liberal>& liberalList, vector<wstring>& inputLiberal);

// ���� Ž��
void BinarySearch(vector<Liberal>& liberalList, vector<wstring>& inputLiberal);

bool compare(Liberal l1, Liberal l2);

// �ؽø� �̿��� Ž��
int hashing_L(wstring name);

void make_HT(vector<Liberal>* liberalHash, vector<Liberal>& liberalList);

void set_Complete_Hash(vector<Liberal>* liberalHash, vector<wstring>& inputList);

// ���� ����

