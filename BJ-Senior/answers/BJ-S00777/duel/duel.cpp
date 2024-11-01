#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool local = 0;

long cardNum;
vector<long> powers;
vector<long> aliveCnt;
vector<long> atkCnt;

void read() {
	ios::sync_with_stdio();
	cin.tie(0);
	cout.tie(0);
	FILE* _;
	if (!local) {
		_ = freopen("duel.in", "r", stdin);
		_ = freopen("duel.out", "w", stdout);
	} else _ = freopen("duel4.in", "r", stdin);

	cin >> cardNum;
	powers = vector<long>(cardNum);
	for (long i = 0; i < cardNum; i++) cin >> powers.at(i);
}

void lisanhua(vector<long> allPos, vector<long>& tarPos) {
	sort(allPos.begin(), allPos.end());
	allPos.erase(unique(allPos.begin(), allPos.end()), allPos.end());
	for (long i = 0; i < tarPos.size(); i++) {
		tarPos[i] = lower_bound(allPos.begin(), allPos.end(), tarPos[i]) - allPos.begin();
	}
}

void solve() {
	lisanhua(powers, powers);
	sort(powers.begin(), powers.end());

	aliveCnt = vector<long>(powers.at(powers.size() - 1) + 1);
	for (long i: powers) aliveCnt.at(i)++;
	atkCnt = vector<long>(aliveCnt);
	long powerNum = aliveCnt.size();

	long p = 0;
	while (p < powerNum - 1) {
		if (aliveCnt.at(p) == 0) p++;
		bool flag = 0;
		long i;
		for (i = p + 1; i < powerNum; i++) {
			if (atkCnt.at(i) != 0) {
				flag = 1;
				break;
			}
		}
		if (flag) {
			aliveCnt.at(p)--;
			atkCnt.at(p)--;
			atkCnt.at(i)--;	
		} else break;	
	}

	long sum = 0;
	for (long i: aliveCnt) sum += i;
	cout << sum << '\n';
}

signed main() {
	read();
	solve();
	// for (long i: powers) cout << i << ' '; cout << '\n';
	// for (long i: aliveCnt) cout << i << ' '; cout << '\n';
   	return 0;
}
