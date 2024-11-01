#include<bits/stdc++.h>
using namespace std;
int T;
int n;
int a[200005];
int bin[1000005][2];
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>T;
	while(T--)
	{
		memset(a,0,sizeof(a));
		memset(bin,0,sizeof(bin));
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		bin[a[i]][0]++;
		bin[a[i]][1]=a[i];
	}
	int c=0;
	for(int i=1;i<=1000005;i++)
	{
		c+=(bin[i][0]-1)*bin[i][1];
	}
	cout<<c<<endl;
    }
    return 0;
}
