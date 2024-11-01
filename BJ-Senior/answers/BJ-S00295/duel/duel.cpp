#include<bits/stdc++.h>
using namespace std;
struct node{
	int r;
	bool yn,gj;
}a[1000005];
int n;
bool cmd(node x,node y){
	if(x.r<y.r){
		return 1;
	}else{
		return 0;
	}
}
bool js(){
	for(int i=0;i<n;i++){
		if(a[i].yn==0){
			if(a[i].gj==0){
				return 0;
			}
		}
	}
	return 1;
}
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	bool tf=0;
	for(int i=0;i<n;i++){
		cin>>a[i].r;
	}
	sort(a,a+n+1,cmd);
	for(int i=0;i<n;i++){
		for(int j=1;j<=n;j++){
			if(js()){
				break;
			}
			if(a[i].gj==0&&a[j].yn==0&&a[i].r>a[j].r){
				//cout<<"i : "<<i<<" j : "<<j<<'\n';
				tf=1;
				a[i].gj=0;
				a[j].yn=1;
			}
		}
	}
	if(tf==0){
		cout<<n;
		return 0;
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		if(a[i].yn==0){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
