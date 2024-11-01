#include<bits/stdc++.h>
using namespace	std;
int a[100005],b[100005];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		a[x]++;
		b[x]++;
	}
	int nxt=0,ans=n;
	for(int i=1;i<=100000;i++){
		while(a[i]){
			while(nxt<=100000&&(nxt<=i||b[nxt]==0)){
				nxt++;
			}
			if(nxt>100000){
				cout<<ans;
				return 0;
			}
			if(b[nxt]>=a[i]){
				b[nxt]-=a[i];
				ans-=a[i];
				a[i]=0;
			}
			else{
				a[i]-=b[nxt];
				ans-=b[nxt];
				b[nxt]=0;
			}
		}
	}
	cout<<ans;
	return 0;
}
