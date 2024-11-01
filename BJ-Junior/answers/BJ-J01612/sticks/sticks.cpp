#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll t,n;
string f[100000];
string ans;
ll s[20]={6,2,5,5,4,5,6,3,7,6};
bool check(string x,string y)
{
	if(x=="a")
	{
		return 0;
	}
	if(x.size()!=y.size())
	{
		return x.size()<y.size();
	}
	int xlen=x.size();
	for(int i=0;i<xlen;i++)
	{
		if(x[i]!=y[i])
		{
			return x[i]<y[i];
		}
	}
	return 1;
}
void dfs(ll w,ll y,string k)
{
	if(y==0)
	{
		if(!check(ans,k))
		{
			ans=k;
		}
		return ;
	}
	if(y<2||check(ans,k))
	{
		return ;
	}
	if(w==1)
	{
		for(int i=1;i<=9;i++)
		{
			if(y>=s[i]&&(i==1||i==2||i==4||i==6||i==7||i==8))
			{
				string a;
				if(i==1)
				{
					a="1";
				}
				if(i==2)
				{
					a="2";
				}
				if(i==4)
				{
					a="4";
				}
				if(i==6)
				{
					a="6";
				}
				if(i==7)
				{
					a="7";
				}
				if(i==8)
				{
					a="8";
				}
				dfs(w+1,y-s[i],k+a);
			}
		}
	}
	else
	{
		for(int i=0;i<=9;i++)
		{
			if(y>=s[i]&&(i==1||i==2||i==4||i==0||i==7||i==8))
			{
				string a;
				if(i==0)
				{
					a="0";
				}
				if(i==1)
				{
					a="1";
				}
				if(i==2)
				{
					a="2";
				}
				if(i==4)
				{
					a="4";
				}
				if(i==7)
				{
					a="7";
				}
				if(i==8)
				{
					a="8";
				}
				dfs(w+1,y-s[i],k+a);
			}
		}
	}
}
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		ans="a";
		if(f[n]!="")
		{
			cout<<f[n]<<"\n";
		}
		else if(n<=1)
		{
			cout<<-1<<"\n";
		}	
		else if(n%7==0)
		{
			ll k=n/7;
			for(int i=1;i<=k;i++)
			{
				cout<<8;
			}
			cout<<"\n";
		}
		else if((n-1)%7==0)
		{
			ll k=(n-8)/7;
			cout<<10;
			for(int i=1;i<=k;i++)
			{
				cout<<8;
			}
			cout<<"\n";
		}
		else
		{
			dfs(1,n,"");
			cout<<ans<<"\n";
			f[n]=ans;
		}	
	}
	return 0;
}
