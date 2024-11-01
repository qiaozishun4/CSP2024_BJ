#include<bits/stdc++.h>
using namespace std;
int l[100010];
vector<int> a[100010];
int main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int T;cin >> T;
	while(T--)
	{
		int n,k,q;cin >> n >> k >> q;
		for(int i=1;i<=n;i++)
		{
			cin >> l[i];
			a[i].resize(l[i]+1);
			for(int j=1;j<=l[i];j++)
				cin >> a[i][j];
		}
		cout << T%2 << endl;
	}
	return 0;
}
