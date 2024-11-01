#include<iostream>
#include<cstdio>
using namespace std;
int pla[100005],l[100005],v[100005],a[100005];
int read()
{
	char c;
	int res=0;
	while(1)
	{
		c=getchar();
		if(c==' ' || c=='\n') return res;
		res=res*10+c-48;
	}
}
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int t=read();
	while(t--)
	{
		int n=read(),m=read(),L=read(),V=read(),cnt=0;
		double dv=V*V;
		for(int i=1;i<=n;i++)
		{
			l[i]=read();
			v[i]=read();
			a[i]=read()<<1;
		}
		for(int i=1;i<=m;i++) pla[i]=read();
		for(int i=1;i<=n;i++) if(pla[m]>=l[i] && v[i]*v[i]+a[i]*(pla[m]-l[i])>dv) cnt++;
		cout<<cnt<<" ";
		if(cnt) cout<<m-1<<endl;
		else cout<<m<<endl;
	}
	return 0;
}