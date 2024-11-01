#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t,n,i;
	cin>>t;
	while(t--)
	{
		cin>>n;
		if(!(n%7)) 
		{
			for(i=1;i<=n/7;i++) cout<<8;
			cout<<endl;
		}
		else if(!((n-1)%7))
		{
			n--;
			cout<<1<<0;
			for(i=1;i<=n/7-1;i++) cout<<8;
			cout<<endl;
		}
		else cout<<-1<<endl;
	}
	return 0;
}
