#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5,ss[10]={6,2,5,5,4,5,6,3,7,6};
int anslen,ans[N],cnt[N];
bool ed;
int Check(int len)
{
	if(len<anslen)
	{
		anslen=len;
		for(int i=1;i<=anslen;i++)
		{
			ans[i]=cnt[i];
		}
		ed=0;
		return 0;
	}
	bool is=0;
	for(int i=1;i<=anslen;i++)
	{
		if(ans[i]>cnt[i])
		{
			is=1;
			break;
		}
		if(ans[i]<cnt[i])
		{
			break;
		}
	}
	if(is)
	{
		for(int i=1;i<=anslen;i++)
		{
			ans[i]=cnt[i];
		}
		ed=0;
	}
	return 0;
}
int Find(int x,int len)
{
	if(len==anslen)
	{
		return 0;
	}
	len++;
	for(int i=0;i<10;i++)
	{
		if(x==ss[i]&&len<=anslen)
		{
			cnt[len]=i;
			Check(len);
			return 0;
		}
	}
	if(len==anslen)
	{
		return 0;
	}
	for(int i=0;i<10;i++)
	{
		if(x>ss[i]&&x!=ss[i]+1)
		{
			cnt[len]=i;
			Find(x-ss[i],len);
		}
	}
	return 0;
}
int Ans(int n)
{
	for(int i=1;i<10;i++)
	{
		if(n==ss[i])
		{
			anslen=1;
			ans[1]=i;
			ed=0;
			return 0;
		}
	}
	for(int i=1;i<10;i++)
	{
		if(n>ss[i]&&n!=ss[i]+1)
		{
			cnt[1]=i;
			Find(n-ss[i],1);
		}
	}
	return 0;
}
void Print(int n)
{
	if(anslen==N)
	{
		cout<<-1<<endl;
		return;
	}
	int num=n;
	for(int i=1;i<=anslen;i++)
	{
		num-=ss[ans[i]];
		cout<<ans[i];
	}
	while(num>0)
	{
		cout<<8;
		num-=7;
	}
	cout<<endl;
	return;
}
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin>>T;
	for(int t=1;t<=T;t++)
	{
		int n;
		cin>>n;
		anslen=N;
		for(int i=n%7;i<=n;i+=7)
		{
			if(i<2)
			{
				continue;
			}
			ed=1;
			Ans(i);
			if(anslen!=N&&i!=n)
			{
				ans[++anslen]=8;
			}
			if(ed)
			{
				break;
			}
		}
		Print(n);
	}
	return 0;
}