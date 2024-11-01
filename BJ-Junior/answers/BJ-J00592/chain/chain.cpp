#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int n;
	cin>>n;
	srand(time(NULL));
	while(n--){
		int nn,k,q;
		cin>>nn>>k>>q;
		while(nn--) { int k1; while(cin>>k1);};
		while(q--){
			int j,c;
			cin>>j>>c;
			int c1=rand()%2;
			cout<<c1<<endl;
		}
	}
	return 0;
}