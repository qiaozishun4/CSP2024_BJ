#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		if(n%7==0)
		{
			for(int i=1;i<=n/7;i++)
			{
				cout<<12;
			}
			cout<<endl;
		}
		else if(n%7==1)
		{
			cout<<10;
			n-=8;
			for(int i=1;i<=n/7;i++)
			{
				cout<<12;
			}
			cout<<endl;
		}
	}
	//6,2,5,5,4,5,6,3,7,6
	//0 1 2 3 4 5 6 7 8 9
	return 0;
}
