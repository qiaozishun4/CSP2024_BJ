#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t,n,a[10000],num=0;
	cin>>t;
	for(int j=0;j<t;j++)
	{
		cin>>n;
		int n1=n;
		if(n1>=7) a[1]=8,n1-=7;
		else if(n1>=6) a[1]=6,n1-=6;
		else if(n1>=4) a[1]=4,n1-=4;
		else if(n1>=3) a[1]=7,n1-=3;
		else if(n1>=2) a[1]=1,n1-=2;
		for(int i=2; ;i++) 
		{
			if(n1>=6) a[i]=0,n1-=6;
			else if(n1>=2) a[i]=1,n1-=2;
			else if(n1>=5) a[i]=2,n1-=5;
			else if(n1>=4) a[i]=4,n1-=4;
			else if(n1>=3) a[i]=7,n1-=3;
			else if(n1>=7) a[i]=8,n1-=7;
			else if(n1==1) 
			{
				cout<<"-1";
				break;
			}
			else 
			{
				num=i-1;
				break;
			}
		}
		for(int i=1;i<=num;i++) cout<<a[i];
		cout<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
