#include <iostream>
using namespace std;
int main() {
	int T;
	cin >> T;
	while (T --) {
		int N;
		cin >> N;
		int** M = new int*[N];
		int count = 0;
		for (int i = 0; i < N; i ++) {
			M[i] = new int[N];
			for (int j = 0; j < N; j ++) {
				cin >> M[i][j];
				for (int k = 0; k <= i; k ++) {
					for (int l = 0; l <= j; l ++) {
						if (M[k][l] > M[i][j]) {
							count ++;
						}
					}
				}
			}
		}
		cout << count << endl;
		for (int i = 0; i < N; i ++) delete[] M[i];
		delete[] M;
	}
}
