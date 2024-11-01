#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 1e5+10;
int n,ans;
map<string,int> dp;
int dis[10] = {6,2,5,5,4,5,6,3,7,6};
void dfs(string s,int sum) {
//	cout<<s<<' '<<sum<<endl;
	if(sum==0) {
		int num = 0,tmp = 1;
		for(int i = s.size()-1;i>=0;i--)
			num += (s[i]-'0')*tmp,tmp*=10;
		ans = min(ans,num);
		return;
	}
	if(s.size()!=0) {
		for(int i = 0;i<10;i++)
			if(sum>=dis[i])
				dfs(s+char(i+'0'),sum-dis[i]);
	} else {
		for(int i = 1;i<10;i++)
                        if(sum>=dis[i])
                                dfs(s+char(i+'0'),sum-dis[i]);
	}
}
signed main() {
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int T;cin>>T;
	while(T--) {
		ans = LONG_LONG_MAX;
		cin>>n;
		dfs("",n);
		if(ans==LONG_LONG_MAX)	ans = -1;
		cout<<ans<<endl;
	}
	return 0;
}
