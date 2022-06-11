#include <climits>
#include <iostream>
using namespace std;
void swap(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}
int part(int arr[], int l, int r){
	int x = arr[r], i = l;
	for (int j = l; j <= r - 1; j++) {
		if (arr[j] <= x) {
			swap(&arr[i], &arr[j]);
			i++;
		}
	}
	swap(&arr[i], &arr[r]);
	return i;
}
int ksmallest(int arr[], int l, int r, int k)
{
	if (k > 0 && k <= r - l + 1) {
		int pos = part(arr, l, r);
		if (pos - l == k - 1)
			return arr[pos];
		if (pos - l > k - 1)
			return ksmallest(arr, l, pos - 1, k);
		return ksmallest(arr, pos + 1, r, k - pos + l - 1);
	}
	return -1;
}
int main()
{
	int arr[20],n,k;
	cin>>n;
	while(n--){
		for(int i=0;i<20;i++)
			cin>>arr[i];
		cin>>k;
		cout<<ksmallest(arr, 0, 19, k)<<endl;
	}
}