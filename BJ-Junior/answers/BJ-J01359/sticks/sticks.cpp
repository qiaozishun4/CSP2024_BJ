#include<bits/stdc++.h>
using namespace std;
int t;
int val[14]={6,2,5,5,4,5,6,3,7,6};
string Min(string a,string b)
{
	if(a.size()<b.size())
	{
		return a;
	}
	if(b.size()<a.size())
	{
		return b;
	}
	for(int i=0;i<a.size();i++)
	{
		if(a[i]<b[i])
		{
			return a;
		}
		else if(b[i]<a[i])
		{
			return b;
		}
	}
	return a;
}
string dfs(int x,int num,string ans)
{
	if(num>x)
	{
		return "-1";
	}
	if(num==x)
	{
		return ans;
	}
	int st=0;
	if(num==0)
	{
		st=1;
	}
	string s="-1";
	for(int i=st;i<=9;i++)
	{
		string sum=ans+(char)(i+'0');
		string numm=dfs(x,num+val[i],sum);
		if(numm!="-1")
		{
			if(s=="-1")
			{
				s=numm;
			}
			else
			{
				s=Min(s,numm);
			}
		}
	}
	return s;
}
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		cout<<dfs(n,0,"")<<endl;
	}
	return 0;
}