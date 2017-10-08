#include <vector>
#include <iostream>

void selectionSort(std::vector<int>& arr)
{
	unsigned int indMin;
	for(unsigned int it = 0 ; it < arr.size() - 1 ; ++it){
		indMin = it;
		for(unsigned int pos = it ; pos < arr.size() ; ++pos){
			if(arr[indMin] > arr[pos]){
				indMin = pos;
			}
		}
		std::swap(arr[indMin], arr[it]);
	}
}

int main()
{
	std::vector<int> arr = {5,6,12,2,4,11,1,0,-4};
	selectionSort(arr);
	for(auto it : arr){
		std::cout << it << " ";
	}
	std::cout << "\n";
	return 0;
}