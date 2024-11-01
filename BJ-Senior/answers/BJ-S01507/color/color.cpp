#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int T;
    cin>>T;
    while(T--)
    {
		int n;
		cin>>n;
		int a[1000005]={0};
		for(int i=1;i<=n;i++)
		{
			int x;
			cin>>x;
			a[x]++;
		}
		int sum=0;
		for(int i=1;i<=1000000;i++)
		{
			if(a[i]>=2) sum+=a[i];
		}
		cout<<sum<<endl;
	}
    return 0;
}

