#include <vector>
#include <iostream>

bool binarySearch_it(const std::vector<int>& arr, int value)
{
	int l_bound = 0;
	int r_bound = arr.size() - 1;
	int mid;
	while (l_bound <= r_bound){
		mid = l_bound + (r_bound - l_bound)/2;
		if(arr[mid] == value){
			return true;
		}
		else if(arr[mid] > value){
			r_bound = mid - 1;
		}
		else{
			l_bound = mid + 1;
		}
	}
	return false;
}

bool binarySearch_rec(const std::vector<int>& arr, int value, int l_bound, int r_bound)
{
	if(r_bound >= l_bound){
		int mid = l_bound + (r_bound - l_bound)/2;
		if(arr[mid] == value){
			return true;
		}
		else if(arr[mid] > value){
			return binarySearch_rec(arr, value, l_bound, mid - 1);
		}
		else{
			return binarySearch_rec(arr, value, mid + 1, r_bound);
		}
	}
	else{
		return false;
	}

}

int main()
{
	std::vector<int> arr = {1,2,3,4,5,6,7,8,9,10};
	std::cout << binarySearch_rec(arr,3,0,arr.size() - 1) << "\n";
	std::cout << binarySearch_it(arr,3) << "\n";
	return 0;
}