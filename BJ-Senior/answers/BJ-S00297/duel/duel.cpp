#include<bits/stdc++.h>
using namespace std;
#define ll long long
inline int read()
{
	int res=0,op=0;
	char ch=getchar();
	while(!isdigit(ch))
	{
		op|=ch=='-';
		ch=getchar();
	}
	while(isdigit(ch))
	{
		res=(res<<3)+(res<<1)+(ch^48);
		ch=getchar();
	}
	return op?-res:res;
}
inline void write(int x)
{
	if(x<0)
	{
		putchar('-');
		x=-x;
	}
	if(x>9) write(x/10);
	putchar(x%10^48);
}
int n,a[100005],q[100005],hd,tl;
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	n=read();
	hd=1;
	tl=0;
	for(int i=1;i<=n;++i) a[i]=read();
	sort(a+1,a+1+n);
	for(int i=1;i<=n;++i)
	{
		if(hd<=tl&&a[i]>q[hd]) ++hd;
		q[++tl]=a[i];
	}
	write(tl-hd+1);
	puts("");
	return 0;
}