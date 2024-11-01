#include <iostream>
#include <vector>
using namespace std;

unsigned dfs(const vector<unsigned>& nums, unsigned i=0, unsigned last0=-1, unsigned last1=-1) {
	if (i >= nums.size()) {
		return 0;
	}
	return max(
		dfs(nums, i+1, nums[i], last1) + (nums[i]==last0 ? last0 : 0),
		dfs(nums, i+1, last0, nums[i]) + (nums[i]==last1 ? last1 : 0));
}

int main() {
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);

	unsigned turnN; cin >> turnN;
	for (unsigned turn=0; turn<turnN; ++turn) {
		unsigned len; cin >> len;
		vector<unsigned> nums(len);
		for (auto& i : nums) {
			cin >> i;
		}
		cout << dfs(nums) << "\n";
	}
}
