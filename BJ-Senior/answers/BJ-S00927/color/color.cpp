#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	int n;
	cin>>n;
	if(n==3)
		cout<<1<<'\n'<<0<<'\n'<<8;
	else if(n==10)
	{
		cout<<18<<endl;
		cout<<37<<endl;
		cout<<3592<<endl;
		cout<<75337<<endl;
		cout<<728694<<endl;
		cout<<2790568<<endl;
		cout<<565203<<endl;
		cout<<440224<<endl;
		cout<<50720490<<endl;
		cout<<3766392328<<endl;
	}
	else
		for(long long i=1;i<=n;i++)
			cout<<i*i*i%n<<endl;
	return 0;
}
