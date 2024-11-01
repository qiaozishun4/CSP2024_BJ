#include<bits/stdc++.h>
using namespace std;
int l[10000],g[10000];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>l[i];
	}
	sort(l,l+n);
	for(int j=0;j<n;j++){
	for(int i=1;i<n-1;i++){
		if(l[i+1]>l[i]&&g[i+1]!=-1){
			l[i]=-1;
			g[i+1]=g[i]=-1;
		}
		
	}}
	int ans=0;
	for(int i=0;i<n;i++){
		if(l[i]!=-1)ans++;
	}
	cout<<ans-1;
	return 0;
}
