#include "Lecture.h"
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

void linearSearch(vector<Major>& majorList, vector<wstring>& inputMajor)
{
	for (int i = 0; i < inputMajor.size(); i++)
	{
		for (int j = 0; j < majorList.size(); j++)
		{
			if (inputMajor[i] == majorList[j].getName())
				majorList[j].setCompleted(majorList[j]);
		}

	}
}

bool compare(Major m1, Major m2)
{
	return m1.getName() < m2.getName();		// 강의명으로 ㄱㄴㄷ 정렬
}

void BinarySearch(vector<Major>& majorList, vector<wstring>& inputMajor)
{
	sort(majorList.begin(), majorList.end(), compare);		// 이진 탐색을 위해 정렬 먼저 진행

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
				majorList[mid].setCompleted(majorList[mid]);
				break;
			}
			else if (majorList[mid].getName() > inputMajor[i])
				end = mid - 1;
			else
				start = mid + 1;
		}
	}



}


