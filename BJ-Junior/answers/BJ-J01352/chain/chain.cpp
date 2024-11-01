#include <bits/stdc++.h>
using namespace std;
int n,k,q,cp = 0;
//vector<int> v[200005];
int ansa[200005];
void solve()
{
	cin >> n >> k >> q ;
	for(int i=1;i<=n;i++)
	{
		//v[i].clear();
		int s;
		cin >> s ;
		int pos1 = -998244353;
		for(int j=1;j<=s;j++) 
		{
			int x;
			cin >> x;
			if(j - pos1 + 1 <= k)
			{
				ansa[x] = cp;
				// cout << "ssss" << x << "\n";
			}
 			//v[i].push_back(x);
			if(x == 1) pos1 = j;
		}
	}
	// for(int i=1;i<=10;i++)
	// {
	// 	cout << "a" << i << " " << ansa[i]<< "\n";
	// }
	for(int i=1;i<=q;i++)
	{
		int rj,cj;
		cin >> rj >> cj;
		if(rj == 1) 
		{
			if(ansa[cj] == cp) cout << 1 << "\n";
			else cout << 0 << "\n";
		}
		else cout << 0 << "\n";
	}
	return;
}
int main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T;
	cin >>T ;
	while(T--)
	{
		cp ++;
		solve();
	}
}