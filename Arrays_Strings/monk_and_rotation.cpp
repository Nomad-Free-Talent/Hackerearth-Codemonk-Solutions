#include <iostream>
using namespace std;
int main() {
	int T;
	cin >> T;
	while (T --) {
		int N, K;
		cin >> N >> K;
		K = K % N;
		int *A = new int[N];
		for (int i = 0; i < N; i ++) {
			cin >> A[i];
		}
		for (int i = N - K; i < N; i ++) {
			cout << A[i] << ' ';
		}
		for (int i = 0; i < N - K; i ++) {
			cout << A[i] << ' ';
		}
		cout << endl;
		delete[] A;
	}
}
