#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	freopen("arena.in.in","r",stdin);
	freopen("arena.out","w",stdout);
	ll t;
	cin>>t;
	srand(time(0));
	while(t--){
		cout<<(rand())%100000<<"\n";
	}
	return 0;
}
