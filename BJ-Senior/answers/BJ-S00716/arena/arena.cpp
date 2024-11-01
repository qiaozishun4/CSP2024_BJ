#include <bits/stdc++.h>
using namespace std;
int a[100005];
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	int T;
	int n;
	cin>>n>>T;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	while(T--){
		cin>>c;
		if(c==1){
			cout<<1;
		}
		else{
			cout<<2;
		}
	}
	return 0;
}
