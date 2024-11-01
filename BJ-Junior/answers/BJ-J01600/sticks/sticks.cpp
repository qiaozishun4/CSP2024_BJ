#include <bits/stdc++.h>
using namespace std;
string ans;
const long long w[]={6,2,5,5,4,5,6,3,7,7};
string dp[100005];
bool compare(string s1,string s2)
{
	if(s1.size()!=s2.size())
	{
		return s1.size()<s2.size();
	}
	for(long long i=0;i<s1.size();i++)
	{
		if(s1[i]!=s2[i])
		{
			return s1[i]<s2[i];
		}
	}
	return false;
}
void dfs(long long sum,string s,long long isone,long long exp)
{
	if(sum==exp)
	{
		if(compare(s,ans))ans=s;
		return;
	}
	if(sum>exp)return;
	if(isone)
	{
		for(long long i=1;i<=9;i++)
		{
			char c=i+'0';
			dfs(sum+w[i],s+c,0,exp);
		}
	}
	else
	{
		for(long long i=0;i<=9;i++)
		{
			char c=i+'0';
			dfs(sum+w[i],s+c,0,exp);
		}
	}

}
string big="";
pair<long long/*是否合法*/,string/*答案*/> getDP(long long n)
{
	string ans=big;
	for(long long start=1;start<=9;start++)
	{
		for(long long i=0;i<=n;i++)
		{
			dp[i]=big;
		}
		char c=start+'0';
		string s="";
		s+=c;
		dp[w[start]]=s;
		for(long long i=0;i<=9;i++)
		{
			for(long long j=w[i];j<=n;j++)
			{
				if(compare(dp[j-w[i]]+(char)(i+'0'),dp[j]))
				{
					dp[j]=dp[j-w[i]]+(char)(i+'0');
				}

				
			}
			
		}
		if(compare(dp[n],ans))ans=dp[n];
	}
	if(ans==big)return make_pair(-1,"");
	else return make_pair(1,ans);
}
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	long long t;
	cin>>t;
	
	for(long long i=1;i<=100000;i++)
	{
		big+='9';
	}
	while(t--)
	{
		long long n;
		cin>>n;
		if (n%7==0)
		{
			for(long long i=1;i<=n/7;i++)
			{
				cout<<8;
			}
			cout<<endl;
			continue;  
		}
		if((n-1)%7==0)
		{
			if(n==1)
			{
				cout<<-1<<endl;
				continue;
			}
			n-=8;
			cout<<10;
			for(long long i=1;i<=n/7;i++)
			{
				cout<<8;
			}
			cout<<endl;
			continue;
		}
		if(n>20&&n<=50)
		{
			string ans=big;
			for(long long start=1;start<=9;start++)
			{
				for(long long i=0;i<=55;i++)
				{
					dp[i]=big;
				}
				char c=start+'0';
				string s="";
				s+=c;
				dp[w[start]]=s;
				for(long long i=0;i<=9;i++)
				{
					for(long long j=w[i];j<=n;j++)
					{
						if(compare(dp[j-w[i]]+(char)(i+'0'),dp[j]))
						{
							dp[j]=dp[j-w[i]]+(char)(i+'0');
						}
					}
				}
				if(compare(dp[n],ans))ans=dp[n];
			}
			if(ans==big)cout<<-1<<endl;
			else cout<<ans<<endl;
			continue;
		}
		if(n>50)
		{
			long long base=n/7;
			while(getDP(n-base*7).first==-1)
			{
				base--;
			}
			cout<<getDP(n-base*7).second;
			for(long long i=1;i<=base;i++)
			{
				cout<<8;
			}
			cout<<endl;
			continue;
		}
		string yuan;
		for(long long i=1;i<=n;i++)
		{
			ans+='9';
		}
		yuan=ans;
		dfs(0,"",1,n);
		if(ans==yuan)cout<<-1<<endl;
		else cout<<ans<<endl;
	}
	return 0;
}