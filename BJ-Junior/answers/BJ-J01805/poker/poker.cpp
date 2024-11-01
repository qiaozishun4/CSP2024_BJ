#include<bits/stdc++.h>
using namespace std;
string hs = "CSHD";
string ds = "A23456789TJQK";
int main()
{
	freopen("poker.in", "r", stdin);
        freopen("poker.out", "w", stdout);
	int n;
	cin >> n;
	unordered_set<string> st;
	for(int i = 1; i <= n; i++)
	{
		string s;
		cin >> s;
		if(hs.find(s[0]) == string::npos)
			continue;
		if(ds.find(s[1]) == string::npos)
			continue;
		st.insert(s);
	}
	cout << 52 - st.size() << endl;
	return 0;
}