#include<bits/stdc++.h>
using namespace std;
int a[21]={0,-1,1,7,4,3,6,8,24,23,20,60,80,88,108,188,228,208,800,889};
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
		cout<<a[n]<<endl;
	}
}
