#include<bits/stdc++.h>
using namespace std;
string a;
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n,sum=0;
	cin>>n;
	sum=52-n;
	string s;
	for(int i=1;i<=n;++i)
	{
		cin>>s;
		if(i!=1)
		{
			if(a==s)
			sum++;
		}
		a=s;
	}
	if(n==52)
	{
		cout<<0<<endl;
		return 0;
	}
	else if(n==1)
	{
		cout<<51<<endl;
		return 0;
	}
	cout<<sum<<endl;
	return 0;
}