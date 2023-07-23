#include "stdafx.h"
#include <vector>
#include <future>
#include <iostream>

int FindFirstRepeatElementIndex(bool bExcute)
{
	if (!bExcute)
	{
		return -1;
	}

	int idx = -1;
	std::vector<int> datas = { 1 , 3, 5, 7, 9, 11, 11, 13, 14, 15, 16, 17 };
	for (size_t i = 0; i < datas.size(); ++i)
	{
		for (size_t j = i = 1; j < datas.size(); ++j)
		{
			if (datas[j] == datas[i])
			{
				idx = i;
				break;
			}
		}
	}

	return idx;
}

#define THREAD_COUNT 8
int main()
{
	std::future<int> results[THREAD_COUNT];

	int realExcuteIdx = rand() % THREAD_COUNT;
	for (int idx = 0; idx < THREAD_COUNT; ++idx)
	{
		bool bRealExcute = (realExcuteIdx == idx);
		results[idx] = std::async(FindFirstRepeatElementIndex, bRealExcute);
	}

	for (auto& one_result : results)
	{
		std::cout<< one_result.get() << std::endl;
	}

	return 0;
}