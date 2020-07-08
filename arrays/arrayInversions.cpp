//count the inversions in an array
//problem: https://practice.geeksforgeeks.org/problems/inversion-of-array/0/

#include<iostream>

using namespace std;

typedef long long ll;

ll merge(int *left, int l_size, int *right, int r_size, int *arr, int size) {
    int i, j, k;
    i = j = k = 0;

    ll inversion_count = 0;
    while(i < l_size && j < r_size) {
        if(left[i] <= right[j]) {
            arr[k] = left[i++];
        } else {
        	inversion_count += l_size - i;
            arr[k] = right[j++];
        }

        ++k;
    }

    while(i < l_size) {
        arr[k] = left[i++];
        ++k;
    }

    while(j < r_size) {
        arr[k] = right[j++];
        ++k;
    }

    return inversion_count;
}

ll merge_sort(int *arr, int size) {
    if(size < 2)
        return 0;

    int mid = size / 2;
    int l_size = mid;
    int r_size = size - l_size;

    int left[l_size];
    int right[r_size];

    int k = 0;
    for(int i=0; i<l_size; ++i) {
        left[i] = arr[k++];
    }

    for(int i=0; i<r_size; ++i) {
        right[i] = arr[k++];
    }

    ll a = merge_sort(left, l_size);
    ll b = merge_sort(right, r_size);
    return a + b + merge(left, l_size, right, r_size, arr, size);
}

int main() {
	int t;
	cin >> t;

	while(t--) {
		int n;
		cin >> n;

		int a[n];
		for(int i=0; i<n; ++i) {
			cin >> a[i];
		}

    	cout << merge_sort(a, n) << "\n";
	}

	return 0;
}