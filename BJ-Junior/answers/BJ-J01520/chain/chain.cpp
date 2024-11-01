#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++)
    {
		cout<<(i+i-1)%2<<endl;
	}
    return 0;
}
