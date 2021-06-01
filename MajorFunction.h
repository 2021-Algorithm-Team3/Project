#pragma once
#include <vector>
#include <string>
#include "Lecture.h"

void linearSearch(vector<Major>& majorList, vector<wstring>& inputMajor);

void BinarySearch(vector<Major>& majorList, vector<wstring>& inputMajor);

bool compare(Major m1, Major m2);

int hashing(wstring name);

void make_HT(vector<Major> *majorHash, vector<Major> &majorList);

void set_Complete_Hash(vector<Major> *majorHash, vector<wstring> &inputList);

