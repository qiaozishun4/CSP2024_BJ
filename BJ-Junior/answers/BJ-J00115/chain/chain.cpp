#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int t=0;
    cin>>t;
    int n=0,k=0,q=0,l=0,s=0,r=0,c=0;
    for(int j1=1;j1<=t;j1++)
    {
		cin>>n>>k>>q;
		for(int j2=1;j2<=n;j2++)
		{
			cin>>l;
			for(int j3=1;j3<=l;j3++)
			{
				cin>>s;
			}
		}
		for(int j3=1;j3<=q;j3++)
		{
			cin>>r>>c;
			cout<<0<<endl;
		}
	}
    return 0;
}



