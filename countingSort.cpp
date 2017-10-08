#include <bits/stdc++.h>

void getMinMax(const std::vector<int>& arr, int &min, int &max)
{
	max = INT_MIN;
	min = INT_MAX;
	for(int i = 0 ; i < arr.size() ; ++i){
		if(arr[i] < min)
			min = arr[i];
		if(arr[i] > max)
			max = arr[i];
	}
}

void countingSort(std::vector<int>& arr)
{
	int min, max;
	getMinMax(arr, min, max);
	std::vector<int> count(max - min + 1);
	for(int i = 0 ; i < arr.size() ; ++i)
		count[arr[i] - min]++;
	for(int i = 1 ; i < max - min + 1 ; ++i)
		count[i] += count[i - 1];
	std::vector<int> result(arr.size());
	for(int i = 0 ; i < arr.size() ; ++i){
		result[count[arr[i] - min] - 1] = arr[i];
		count[arr[i] - min]--;
	}
	arr = result;
}

int main()
{
	std::vector<int> arr = {1, 4, 1, 2, 7, 5, 2};
	countingSort(arr);
	for(auto it : arr)
		std::cout << it << " ";
	std::cout << std::endl;
	return 0;
}