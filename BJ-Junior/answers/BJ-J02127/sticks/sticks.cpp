#include<bits/stdc++.h>
using namespace std;
const int f[]={6,2,5,5,4,5,6,3,7,6};
int ans=0,n,ans2=1<<30;
bool h=0;
int read()
{
	char ch=getchar();
	int sum=0;
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9')
	{
		sum=sum*10+(ch-'0');
		ch=getchar();
	}
	return sum;
}
void dfs(int x)
{
	if(x>n||ans>ans2) return;
	if(x==n)
	{
		h=1;
		ans2=min(ans,ans2);
		return;
	}
	for(int i=(x==0?1:0);i<10;i++)
	{
		ans=ans*10+i;
		dfs(x+f[i]);
		ans/=10;
	}
	return;
}
string fun(int x)
{
	string s="";
	while(x)
	{
		s+="8";
		x-=7;
	}
	return s;
}
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t;
	t=read();
	while(t--)
	{
		n=read();
		if(n%7==0)
		{
			printf("%s\n",fun(n).c_str());
			continue;
		}
		if(n<2)
		{
			cout<<-1<<endl;
			continue;
		}
		dfs(0);
		if(!h) printf("-1\n");
		else printf("%d\n",ans2);
		h=0;
		ans=0;
		ans2=1<<30;
	}
	return 0;
}

