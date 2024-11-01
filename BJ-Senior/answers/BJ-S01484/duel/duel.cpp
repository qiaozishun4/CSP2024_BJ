#include <bits/stdc++.h>
#define int long long
using namespace std;
int n = 0;
int lst[100010];
int read(){
	int x = 0;
	int f = 1;
	char c = getchar();
	while(c < '0' || c > '9'){
		if(c == '-') f = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9'){
		x = x * 10 + c - '0';
		c = getchar();
	}
	return x * f;
}
map <int, int> mp;
set <int> st;
int cnt[100010];
signed main(){
	freopen("duel4.in", "r", stdin);
	n = read();
	for(int i = 1; i <= n; i++){
		lst[i] = read();
		st.insert(lst[i]);
		cnt[lst[i]] ++;
	}
	int ct = 0;
//	bool flg = 1;
//	sort(lst + 1, lst + 1 + n);
	for(auto it = st.begin(); it != st.end(); it++){
		if(it != st.begin()){
			int c = 1;
			while(c <= cnt[*it]){
				if(it == st.begin()) break;
				auto pre = prev(it);
				cnt[*pre] --;
				ct ++;
				if(cnt[*pre] == 0){
					st.erase(pre);
				}
				c ++;
			}
		}
	}
	cout << n - ct;
//	for(int i = 2; i <= n; i++){
//		if(lst[i] != lst[i - 1]){
//			
//		}
//
	return 0;
}