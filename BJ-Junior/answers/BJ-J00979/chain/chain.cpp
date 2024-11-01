#include <bits/stdc++.h>
using namespace std;
int n,h[2003][2003],k,a[1145];
bool chk(int f)
{

	for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=h[i][0];j++)
			{
				if(h[i][j]==f)
				for(int z=j-1;z>=j-k+1;z--) if(h[i][z]==1) return 1;
			}
		}
		return 0;
}
int main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
    int T; cin>>T;
    while(T--)
    {
		int q; cin>>n>>k>>q;
		for(int i=1;i<=n;i++)
		{
			cin>>h[i][0];
			for(int j=1;j<=h[i][0];j++) cin>>h[i][j];
		}
		while(q--){
		int l,r;
		cin>>l>>r;
		cout<<chk(r)<<endl;
	}
    }
    return 0;
}
