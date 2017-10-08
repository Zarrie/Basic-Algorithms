#include <vector>
#include <iostream>
#include <fstream>

void insertionSort(std::vector<int>& arr)
{
	int itPos,insPos,key;
	for(itPos = 1 ; itPos < arr.size() ; ++itPos){
		key = arr[itPos];
		insPos = itPos - 1;
		while (insPos >= 0 && arr[insPos] > key){
			arr[insPos + 1] = arr[insPos];
            insPos = insPos - 1;
		}
		arr[insPos + 1] = key;
	}
}

int main()
{
	std::vector<int> arr = {7,15,1,5,244,124,18,21};
	std::ifstream source;
	source.open("sort.in", std::ios::in);
	int x;
	while(!source.eof()){
		source >> x;
		arr.push_back(x);
	}
	insertionSort(arr);
	for(auto it : arr){
		std::cout << it << " ";
	}
	std::cout << "\n";
	return 0;
}