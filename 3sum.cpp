#include <vector>
#include <iostream>
#include <utility>
using std::vector;
using std::cin;
using std::cout;

//O(nlogn) sorting algo
void insertSort(vector<int> &A, int l, int r)
{
	for(int i = l; i <= r; i++){
		int j = i;
		while( (j > 0) && (A[j] < A[j - 1])){
            		std::swap(A[j], A[j-1]);
			j--;
		}
	}
}

std::pair<int, int> two_sum(vector<int> arr, int c) 
{
    int L = 0;
    int R = arr.size() - 1;
    while (L <= R) {
        if (arr[L] + arr[R] == c) {
            return std::make_pair(L, R);
        }
        else if (arr[L] + arr[R] > c) R--;
        else if (arr[L] + arr[R] < c) L++;
    }
    return std::make_pair(0, 0);
}


void three_sum(vector<int> arr, int tar)
{
    insertSort(arr, 0, arr.size() - 1);
    //For easch element of the array check whether 2 elements sum to target - element
    for(int i = 0; i < arr.size() - 1; ++i) {
        std::pair<int, int> ret = two_sum(arr, tar - arr[i]);    
        if (ret != std::pair<int, int>(0, 0)) {
            cout << "Found at i=" << i << " j=" << ret.first << " k=" << ret.second << std::endl;
            return;
        }    
    }
    cout << "Not found" << std::endl;
}


int main() 
{
    vector<int> arr;
    int i;
    int tar;
    while (cin >> i) arr.push_back(i);
    if (arr.size() > 3) {
        tar = arr[arr.size() - 1];
        arr.pop_back();
    }
    else {
        cout << "Error requires at least 4 inputs";
        return 1;
    }
    three_sum(arr, tar);
    return 0;
}
