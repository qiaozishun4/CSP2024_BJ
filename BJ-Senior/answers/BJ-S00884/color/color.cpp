#include<iostream>
#include<cstring>
using namespace std;
int T,n,a[200010];
long long s[200010],f[200010],F[1000010];
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>T;
	while(T--)
	{
		cin>>n;
		memset(F,0xc0,sizeof(F));
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			s[i]=s[i-1]+(a[i]==a[i-1])*a[i];
		}
		long long maxf=0;
		for(int i=2;i<=n;i++)
		{
			f[i-1]=max(maxf,a[i]+F[a[i]])+s[i-1];
			F[a[i-1]]=max(F[a[i-1]],f[i-1]-s[i]);
			maxf=max(maxf,f[i-1]-s[i]);
		}
		cout<<maxf+s[n]<<'\n';
	}
	return 0;
}