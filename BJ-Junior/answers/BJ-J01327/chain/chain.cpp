#include<bits/stdc++.h>
using namespace std;
int T,n,k,q;
int main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>T;
	for(int i=1;i<=T;i++){
		cin>>n>>k>>q;
		srand(time(0));
		for(int j=1;j<=q;j++)cout<<rand()%2<<"\n";
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
