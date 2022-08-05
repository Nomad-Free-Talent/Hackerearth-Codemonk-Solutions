#include <iostream>
#include <vector>
#include <algorithm>
#define LIMIT 100000

using namespace std;

struct node {
	long long val;
	long long chunk;
	int idx;
	node(long long v, long long c, int i): val(v), chunk(c), idx(i) {};
};

long long getInt() {
	char ch;
	do {
		ch = getchar();
	} while(ch < '0' || ch > '9');
	long long res = 0;
	do {
		res = res * 10 + ch - '0';
		ch = getchar();
	} while(ch >= '0' && ch <= '9');
	return res;
}

bool verify(const vector<node> &vec) {
	long long weight_sum = 0;
	for (node el : vec) {
		weight_sum += el.chunk % LIMIT;
	}

	return weight_sum != 0;
}

void next(vector<node> &vec) {
	for (node &el : vec) {
		el.chunk /= LIMIT;
	}
}

int main() {
	int n;
	vector<node> vec;
	cin >> n;
	for (int i = 0; i < n; i ++) {
		long long a;
		a = getInt();
		vec.push_back(node(a, a, i));
	}
	while(verify(vec)) {
		sort(vec.begin(), vec.end(), [](const node &l, const node &r) {
			if ((l.chunk % LIMIT) == (r.chunk % LIMIT)) {
				return l.idx < r.idx;
			}
			return (l.chunk % LIMIT) < (r.chunk % LIMIT);
		});
		int idx = 0;
		for (node &el : vec) {
			cout << el.val << ' ';
			el.idx = idx++;
		}
		cout << endl;
		next(vec);
	}
}
