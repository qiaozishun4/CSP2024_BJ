#include<bits/stdc++.h>
using namespace std;
signed main()
{
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	set<string> st;
	int n;
	string s;
	cin >> n;
	for(int i = 1; i <= n; i ++)
	{
		cin >> s;
		st.insert(s);
	}
	cout << 52 - st.size();
	return 0;
}
