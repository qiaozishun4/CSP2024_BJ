#include <bits/stdc++.h>
using namespace std;
int a[8]={-1,-1,1,7,4,2,0,8};
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		if(n%7==0)
		for(int i=1;i<=n/7;i++)
		cout<<8;
		if(n==1)
		cout<<-1;
		else if(n==6)
		cout<<6;
		else if(n<8)
		cout<<a[n];
		else if(n==8)
		cout<<10;
		else if(n==12)
		cout<<min(a[n-7]*10+8,a[n-7]+80);
		else if(n<14)
		cout<<min(min(a[n-7]*10+8,a[n-7]+80),a[n-6]*10);
		else
		{
			int x=a[n%7+1];
			cout<<min(x,8)<<0;
			for(int i=1;i<=(n-x-13)/7;i++)
			cout<<8;
			cout<<max(x,8);
		}
		cout<<endl;
	}
}
