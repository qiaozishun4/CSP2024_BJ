#include<bits/stdc++.h>
using namespace std;
int gs[]={6,2,5,5,4,5,6,3,7,6};
int calc(int x)
{
	int s=0;
	while(x)
	{
		s += gs[x%10];
		x /= 10;
	}
	return s;
}
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int T;cin >> T;
	while(T--)
	{
		int n;cin >> n;
		int ans=-1;
		for(int i=1;i<=1000;i++)
			if(calc(i)==n)
			{
				ans=i;
				break;
			}
		cout << ans << endl;
	}
	return 0;
}
