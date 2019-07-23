#include <iostream>
#include <vector>
using namespace std;
void merge(vector<int>&d, int start, int mid, int end)
{
	int i = start, j = mid + 1, t = 0;
	int *temp = new int[(end-start) + 1];
	while (i <= mid && j <= end){
		if (d[i] <= d[j]) temp[t++] = d[i++];
		else temp[t++] = d[j++];
	}
	//남은 뒷부분 넣어주기
	if (i > mid) for (int k = j; k <= end; k++, t++) temp[t] = d[k];
	else for (int k = i; k <= mid; k++, t++) temp[t] = d[k];

	for (int i = start, k = 0; i <= end; i++,k++) d[i]=temp[k];
	delete[] temp;
}

void mergeSort(vector<int>&d, int start, int end)
{
	if (start < end){
		int mid = (start + end) / 2;
		mergeSort(d, start, mid);
		mergeSort(d, mid + 1, end);
		merge(d, start, mid, end);
	}
}

int main() {
	vector<int> d;
	int n;
	cin >> n;
	for (int i = 0,t=0; i < n; i++){
		cin >> t;
		d.push_back(t);
	}
	mergeSort(d, 0, n-1);
	for (int i = 0; i < n; i++) cout << d[i] << '\n';
	return 0;
}