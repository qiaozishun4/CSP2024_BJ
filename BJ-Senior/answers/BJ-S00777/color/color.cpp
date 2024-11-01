#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

bool local = 0;

int len, ans = 0;
vector<int> nums;
vector<int> atp;

void read() {
	cin >> len;
	nums = vector<int>(len);
	for (int i = 0; i < len; i++) cin >> nums.at(i);
	atp = vector<int>(len);
}

void solve2() {
	vector<int> closestPos(len);
	int res = 0;
	int rp = -1, bp = -1;
	for (int i = 0; i < len; i++) {
		if (atp.at(i) == 0) {
			if (rp != -1) {
				if (nums.at(rp) == nums.at(i)) res += nums.at(i);	
			}
			rp = i;
		} else {
			if (bp != -1) {
				if (nums.at(bp) == nums.at(i)) res += nums.at(i);	
			}
			bp = i;
		}
	}
	if (res > ans) {
		ans = res;
	   	// for (int i: atp) cout << i << ' '; cout << '\n';
	}
}

void fill(vector<int>& vec, int index) {
	if (index == len) {
		solve2();
		return;
	}
	vec.at(index) = 0;
	fill(vec, index + 1);
	if (index > 0) {
		vec.at(index) = 1;
		fill(vec, index + 1);	
	}
}

void solve() {
	ans = 0;
	fill(atp, 0);
	cout << ans << '\n';
}

signed main() {
	FILE* _;
	if (!local) {
		_ = freopen("color.in", "r", stdin);
		_ = freopen("color.out", "w", stdout);
	} else _ = freopen("color2.in", "r", stdin);
	ios::sync_with_stdio();
	cin.tie(0);
	cout.tie(0);
    int testNum;
    cin >> testNum;
    for (int _ = 0; _ < testNum; _++) {
        read();
        solve();
    }

	return 0;
}
