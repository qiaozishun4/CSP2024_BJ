#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);

	long long n;
	cin >> n;
    map<int, long long>mp;
	for (int i = 0; i < n; i++){
        int tmp;
        cin >>tmp;
        mp[tmp]++;
	}

	vector<int>v;
	for (const auto &i: mp){
        v.push_back(i.second);
	}

	long long result = n;
    int ptr = v.size() - 1;
    while (ptr > 0){
        for (int j = ptr - 1; j >=0; j--){
            if (v[j] < v[ptr]){
                result -= v[j];
                v[ptr] -= v[j];
                v[j] = 0;
            }else{
                result -= v[ptr];
                v[j] -= v[ptr];
                // ptr = j;
            }
        }
        ptr--;
    }

	cout << result;

	return 0;
}
