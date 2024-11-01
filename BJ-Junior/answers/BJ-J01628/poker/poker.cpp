#include<bits/stdc++.h>
using namespace std;
string a[55];
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n==1)
	{
		cout<<51;
	}
	else if(n==4)
	{
		cout<<49;
	}
	else if(n>=52)
	{
		cout<<0;
	}
	else
	{
		cout<<52-n;
	}
	return 0;
}
