//T1.cpp
#include<bits/stdc++.h>
using namespace std;
const int a[10]={6,2,5,5,4,5,6,3,7,6};
int T;
int main()
{
	int i;
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		if(n==1)
		{
			cout<<-1<<endl;
			continue;
		}
		for(i=1;;i++)
		{
			int tmp=i,sum=0;
			while(tmp)
			{
				sum+=a[tmp%10];
				tmp/=10;
			}
			if(sum==n)
			{
				cout<<i<<endl;
				break;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}