#include <vector>
#include <iostream>
#include <limits.h>

#define INF INT_MAX

//end of first subarray condition
/*
void merge(std::vector<int>& arr, int p, int q, int r)
{
	int n1 = q - p + 1;
	int n2 = r - q;
	std::vector<int> L(n1), R(n2);
	int i, j, k;
	for(i = 0 ; i < n1 ; ++i){
		L[i] = arr[p + i];
	}
	for(j = 0 ; j < n2 ; ++j){
		R[j] = arr[q + j + 1];
	}
	i = j = 0;
	for(k = p ; k <= r ; ++k){
		if(i >= n1){
			arr[k] = R[j++];
		}
		else if(j >= n2){
			arr[k] = L[i++];
		}
		else if(L[i] < R[j]){
			arr[k] = L[i++];
		}
		else{
			arr[k] = R[j++];
		}
	}
}
*/

//sentinel symbol
void merge(std::vector<int>& arr, int p, int q, int r)
{
	int n1 = q - p + 1;
	int n2 = r - q;
	std::vector<int> L(n1 + 1), R(n2 + 1);
	int i, j, k;
	for(i = 0 ; i < n1 ; ++i){
		L[i] = arr[p + i];
	}
	for(j = 0 ; j < n2 ; ++j){
		R[j] = arr[q + j + 1];
	}
	i = j = 0;
	L[n1] = R[n2] = INF;
	for(k = p ; k <= r ; ++k){
		if(L[i] < R[j]){
			arr[k] = L[i++];
		}
		else{
			arr[k] = R[j++];
		}
	}
}

void mergeSort(std::vector<int>& arr, int p, int r)
{
	if (p < r){
		int q = (p + r)/2;
		mergeSort(arr,p,q);
		mergeSort(arr,q + 1, r);
		merge(arr,p,q,r);
	}
}

int main()
{
	std::vector<int> arr = {-24,15,-11,2,-9,11,17,-5,1,0,9,13,-1};
	mergeSort(arr,0,arr.size() - 1);
	for(auto it : arr){
		std::cout << it << " ";
	}
	std::cout << "\n";
	return 0;
}