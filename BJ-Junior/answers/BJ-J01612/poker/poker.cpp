#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,ans=52;
map<string,int> f;
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		string k;
		cin>>k;
		if(f[k]==0)
		{
			ans--;
			f[k]=1;
		}	
	}
	cout<<ans;
	return 0;
}
