#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> node;

int main() {
	int t;
	cin >> t;
	while (t --) {
		int n;
		map<int, int> cnt;
		vector<node> vec;
		cin >> n;
		while (n --) {
			int h;
			cin >> h;
			cnt[h] ++;
		}
		copy(cnt.begin(), cnt.end(), back_inserter<vector<node>>(vec));

		sort(vec.begin(), vec.end(), [](const node &l, const node &r)
            {
				return l.first > r.first;
            });
		
		int mxCnt = 0;
		int mnCnt = 1e6;
		int res = 0;
		for (auto const &el: vec) {
			if (el.second > mxCnt) {
				mxCnt = el.second;
			} else {
				res = res > (mxCnt - el.second) ? res : (mxCnt - el.second);
			}
			if (el.second < mnCnt) {
				mnCnt = el.second;
			} else {
				res = res > (el.second - mnCnt) ? res : (el.second - mnCnt);
			}
		}
		cout << (res ? res : -1) << endl;
	}
}
