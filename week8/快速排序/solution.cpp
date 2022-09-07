#include "bits/stdc++.h"
int r[1000], s[1000], f;
using namespace std;
void Insertionsort(int A[1000], int N)
{
	int p, i;
	int temp;
	for (p = 1; p < N; p++)
	{
		temp = A[p];
		for (i = p; i > 0 && A[i - 1] > temp; i--)
		{
			A[i] = A[i - 1];
		}
		A[i] = temp;
	}
}
int Median3(int A[1000], int left, int right)
{
	int center = (left + right) / 2;
	if (A[left] > A[center])
		swap(A[left], A[center]);
	if (A[left] > A[right])
		swap(A[left], A[right]);
	if (A[center] > A[right])
		swap(A[center], A[right]);
	swap(A[center], A[right - 1]);
	return A[right - 1];
}
void patition(int A[1000], int left, int right)
{
	int pivot, low, high;
	if (5 <= right - left)
	{
		pivot = Median3(A, left, right);
		s[f++] = pivot;
		low = left;
		high = right - 1;
		while (true)
		{
			while (A[++low] < pivot);
			while (A[--high] > pivot);
			if (low < high) swap(A[low], A[high]);
			else break;
		}
		swap(A[low], A[right - 1]);
		patition(A, left, low - 1),patition(A, low + 1, right); 
	}
	else Insertionsort(A + left, right - left + 1);

}
void patition(int A[1000], int N)
{
	patition(A, 1, N - 1);
}
int main()
{
	int k = 1; string input; stringstream ss;
	while (cin>>input)
	{
		if (input == "#") break;
		else ss << input, ss >> r[k], k++, ss.clear();
	}
	patition(r, k);
	cout << "After Sorting:" << endl;
	for (int i = 1; i < k; i++) cout << r[i] << ((i == k - 1) ? " \nMedian3 Value:\n" : " ");
	if (f)
		for (int j = 0; j < f; j++)
			cout << s[j] << ((j == f - 1) ? " \n" : " ");
	if (!f) cout<<"none"<<endl;
	return 0;
}