#include <bits/stdc++.h>
using namespace std;
int f[100000];
string r(int n)
{
	if(n<9)
	{
		if(n==1)
			return "-1";
		if(n==2)
			return "1";
		if(n==3)
			return "7";
		if(n==4)
			return "4";
		if(n==5)
			return "2";
		if(n==6)
			return "6";
		if(n==7)
			return "8";
		if(n==8)
			return "10";
	} 
	int i=0,c,e=1000000;
	string s,b;
	while(i<6)
	{
		if(i!=1)
			s=r(n-7+i)+r(7-i);
		else
			s=r(n-7+i)+"0";
		c=s.size();
		int p=1;
		for(int j=0;j<c;j++)
		{
			if(int(s[j])<f[j])
				break;
			if(int(s[j])>f[j])
			{
				p=0;
				break;
			}
		}
		if((c<=e&&p)||!i)
		{
			e=c;
			b=s;
			for(int j=0;j<c;j++)
				f[j]=int(s[j]);
		}
		i++;
	}
	return b;
}
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		cout<<r(n)<<endl;
	}
	return 0;
}