#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int T;
	cin >> T;
	while (T --) {
		int N, result = 1e9, temp;
		int *A;
		cin >> N;
		A = new int[N];
		for (int i = 0; i < N; i ++) {
			cin >> A[i];
		}
		sort(A, A + N);
		for (int i = 1; i < N; i ++) {
			temp = A[i - 1] ^ A[i];
			result = result > temp ? temp : result;
		}
		cout << result << endl;

		delete[] A;
	}
}
