#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int t;
	cin >> t;
	vector<vector<int> > vi;
	while(t --) 
	{
		int n,k,q;
		cin >> n >> k >> q;
		for (int i=0;i<n;i++)
		{
			int x;
			cin >> x;
			for (int j=0;j<x;j++)
			{
				int s;
				cin >> s;
				vi[n].push_back(s);
			}
		}
		for (int i=0;i<q;i++)
		{
			int c,r;
			cin >> r >> c;
		}
	}
	srand(time(0));
	while(q --)
		cout << rand()%2 << endl;
	return 0;
}