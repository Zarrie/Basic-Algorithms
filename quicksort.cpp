#include <vector>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include <chrono>
#include <algorithm>

int partition(std::vector<int>& arr, int begin, int end)
{
	int pivot = arr[end];
	int i = begin - 1;
	for(int j = begin ; j <= end - 1 ; ++j){
		if(arr[j] <= pivot)
			std::swap(arr[++i], arr[j]);
	}
	std::swap(arr[i + 1], arr[end]);
	return i + 1;
}

void quicksort(std::vector<int>& arr, int begin, int end)
{
	if(begin < end){
		int delim = partition(arr,begin,end);
		quicksort(arr,begin, delim - 1);
		quicksort(arr, delim + 1, end);
	}
}

int main()
{
//	std::vector<int> arr = {5,12,52,151,23,6246,2,24,2,2,25,2,11,1,5,246,7,357,356,3453,4,6356,35,345,34};
	std::vector<int> arr;
	int tmp;
	std::ifstream input;
	input.open("/home/zarrie/Desktop/10000000.txt", std::ios::in);
	while(!input.eof()){
		input >> tmp;
		arr.push_back(tmp);
	}


	std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();    
	quicksort(arr, 0, arr.size() - 1);
//	std::sort(arr.begin(), arr.end());
	end = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed_seconds = end-start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);
 
    std::cout << "finished computation at " << std::ctime(&end_time)
              << "elapsed time: " << elapsed_seconds.count() << "s\n";


	input.close();
	std::ofstream output;
	output.open("/home/zarrie/Desktop/10000000RESULT.txt", std::ios::out);
	for(auto it : arr)
		output << it << " ";
	std::cout << "\n";
	return 0;
}