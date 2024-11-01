#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
using namespace std;

int main() {
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(nullptr);

	unsigned len; cin >> len;
	map<unsigned, unsigned> nums;
	for (unsigned i=0; i<len; ++i) {
		unsigned num; cin >> num;
		if (!nums.count(num)) {
			nums[num] = 0;
		}
		++nums[num];
	}
	unsigned liveN=0;
	for (const auto& item : nums) {
		const auto x = item.first, n = item.second;
		(liveN -= min(n, liveN)) += n;
	}
	cout << liveN << "\n";
}
