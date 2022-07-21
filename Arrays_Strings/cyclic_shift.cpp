#include <iostream>
using namespace std;

int compare(int aIdx, int bIdx, char *arr, const int &n) {	
	char *pA, *pB;
	int count = n;
	pA = &arr[aIdx];
	pB = &arr[bIdx];
	while (count --) {
		if (*pA < *pB) return -1;
		if (*pA > *pB) return 1;
		pA ++;
		pB ++;
	}
	return 0;
}

int main() {
	int T;
	cin >> T;
	while (T --) {
		int N, K;
		cin >> N >> K;
		char* A;
		int* P;
		A = new char[N * 2];
		P = new int[N]{0};
		cin >> A;
		for (int i = 0, j = N; i < N; i ++, j ++) {
			A[j] = A[i];
		}
		int nPCount = 1;
		int nPIdx = 0;
		for (int i = 1; i < N; i ++) {
			int comp = compare(nPIdx, i, A, N);
			if (comp < 0) {
				nPCount = 1;
				nPIdx = P[0] = i;
			}
			if (comp == 0) {
				P[nPCount ++] = i;
			}
		}
		cout << (long) N * ((K - 1) / nPCount) + P[(K - 1) % nPCount] << endl;
		delete[] A, P;
	}
}
