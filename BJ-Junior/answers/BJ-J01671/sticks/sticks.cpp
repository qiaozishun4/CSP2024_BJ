#include <bits/stdc++.h>
using namespace std;
int T,n,a,b;
int l[15]={-1,-1,1,7,4,2,6,8,10,18,22,20,28,68,88};
int main()
{
	freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
	
	cin>>T;
	for (int tt=0;tt<T;tt++)
	{
		cin >> n;
		if (n<15)
		{
			cout<<l[n]<<endl;
		}
		else
		{
			a=n%7;b=n/7-1;
			cout<<l[7+a];
			for(int i=0;i<b;i++) cout << '8';
			cout << endl;
		}
	}
	return 0;
} 


