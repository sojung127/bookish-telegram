#include <iostream>
#include <vector>
#include <list>
using namespace std;

void shell_sort(vector<int>& v);

void heap_sort(vector<int>& v);
void heapify(vector<int>& v, int size, int i) {
	int max = i; 
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	//i는 루트 노드의 배열 인덱스

	if (left<size && v[left]>v[max])
		max = left;
	if (right<size && v[right]>v[max])
		max = right;
	if (max != i) {
		int temp = v[i];
		v[i] = v[max];
		v[max] = temp;

		heapify(v, size, max);
	}
}
int partition(vector<int>& arr, int startIndex, int endIndex) {
	int pivotIndex = (startIndex + endIndex) / 2;
	int pivotValue = arr[pivotIndex];

	while (true) {
		while (arr[startIndex] < pivotValue)
			startIndex++;
		while (arr[endIndex] > pivotValue)
			endIndex--;
		if (startIndex >= endIndex)
			return endIndex;

		// 두개의 키의 위치가 역전되면 그 위치를 전달
		// 아니라면 값을 바꾸고 키의 위치가 역전될때까지 반복
		int temp = arr[startIndex];
		arr[startIndex] = arr[endIndex];
		arr[endIndex] = temp;
	}
}
void quickSort(vector<int>& arr, int start, int end) {
	if (start < end) {
		int pivot = partition(arr, start, end);
		quickSort(arr, start, pivot);
		quickSort(arr, pivot + 1, end);
	}
}
void radix_sort(vector<int>& arr, int radix) {
	for (int i = 0; i < radix; i++) {
		vector<list<int>> bucket(10);
		for (int value : arr) {
			int current = value;
			for (int j = 0; j < i; j++) {
				current /= 10;
			}
			current = current % 10;
			bucket[current].push_back(value);
		}
		int key = 0;
		for (int j = 0; j < 10; j++) {
			if (!bucket[j].empty()) {
				list<int>::iterator iter;
				for (iter = bucket[j].begin(); iter != bucket[j].end(); iter++)
					arr[key++] = *iter;
			}
		}
	}
}
int main() {

	vector<int> v = { 24,51,4,2,65,48,11 };
	int arr[8]= { 24,51,4,2,65,48,11 };
	//shell_sort(v);
	//heap_sort(v);
	radix_sort(v, 2);
	for (int num : v)
		cout << num << " ";
	return 0;
}


void heap_sort(vector<int>& v) {
	int size = v.size();

	for (int i = size / 2 - 1; i >= 0; i--)
		heapify(v, size, i);

	for (int i = size - 1; i >= 0; i--) {
		int temp = v[0];
		v[0] = v[i];
		v[i] = temp;

		heapify(v, i, 0);
	}
}

void shell_sort(vector<int>& v) {
	for (int gap = v.size() / 2; gap > 0; gap /= 2) {
		for (int i = gap; i < v.size(); i++) {
			int current = i;
			int value = v[i];
			while (current >= gap && v[current - gap] > value) {
				v[current] = v[current - gap];
				current -= gap;
			}
			v[current] = value;
		}
	}
}

