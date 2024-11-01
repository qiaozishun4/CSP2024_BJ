#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n;
	cin>>n;
	int card[n],vis[n],count=n;
	for(int i=0;i<n;i++){
		cin>>card[i];
		vis[i]=1;
	}
	for(int i=0;i<n;i++){
		int mininbig=1000000,id=-1;
		for(int j=0;j<n;j++){
			if(card[j]<mininbig&&card[j]>card[i]&&vis[j]==1){
				mininbig=card[j];
				id=j;
			}
		}
		if(id!=-1){
			count--;
			vis[id]=0;
		}
	}
	cout<<count;
	return 0;	
}
