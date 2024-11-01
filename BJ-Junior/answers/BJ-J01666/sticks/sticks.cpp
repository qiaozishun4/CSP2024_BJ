#include <bits/stdc++.h>
using namespace std;
int q,n,st[10]={-1,-1,1,7,4,2,6,8};
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>q;
	while(q--){
		cin>>n;
		if(n==1){
			cout<<-1<<'\n';
			continue;
		}
		int l=(n+6)/7;
		int co=l*7-n,i=1;
		if(l==1){
			cout<<st[n]<<'\n';
			continue;
		}
		if(co>=5){
			co-=5;
			cout<<1;
			i++;
		}else if(co>=2){
			co-=2;
			cout<<2;
			i++;
		}
		else if(co>=1){
			co-=1;
			cout<<6;
			i++;
		}
		while(co>=1&&i<l){
			co--;
			cout<<0;
			i++;
		}
		if(co!=0){
			if(co==2) cout<<2;
			if(co==1) cout<<0;
			cout<<'\n';
			continue;
		}
		for(int j=i;j<=l;j++) cout<<8;
		cout<<'\n';
	}
	return 0;
}
