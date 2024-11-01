#include<bits/stdc++.h>
using namespace std;
int T,n,hh,ans[55],ten[10]={6,2,5,5,4,5,6,3,7,6},shu,t;
void stik(int nm){
	if(nm==0){
		ans[hh]=min(ans[hh],shu);
		return;
	}
	if(t>ceil(n/7)){
		return;
	}
	int i=0;
	if(nm==n) i=1;
	for(;i<=9;i++){
		int x=nm-ten[i];
		if(nm-ten[i]<0) continue;
		t++;
		shu=shu*10+i;
		stik(x);
		t--;
		shu/=10;
	}
	return;
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>T;
	for(int rt=1;rt<=T;rt++){
		ans[rt]=1000000000;
		shu=0;
		t=0;
		cin>>n;
		hh=rt;
		stik(n);
	}
	for(int i=1;i<=T;i++){
		if(ans[i]==1000000000){
			cout<<"-1"<<endl;
			continue;
		}
		cout<<ans[i]<<endl;
	}
	return 0;
}