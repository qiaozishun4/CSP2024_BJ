#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n,ans=52;
	char a,b,c[52],d[52],o=0;
	cin>>n;
	while(n--)
	{
		int flag=0;
		cin>>a>>b;
		for(int i=0;i<=o;i++) if(c[i]==a&&d[i]==b) flag=1;
		if(flag==0)
		{
			o++;ans--;
			c[o]=a;d[o]=b;
		}
	}
	cout<<ans<<endl;
	return 0;
}