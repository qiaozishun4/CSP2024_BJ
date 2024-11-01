#include<bits/stdc++.h>
using namespace std;
int n,r[100005],sum;
int h[100005];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<n;i++){
		scanf("%d ",&r[i]);
		h[r[i]]++;
	}
	scanf("%d",&r[n]);
	for(int i=2;i<=100005;i++){
		h[i-1]=h[i-1]-h[i];
		if(h[i-1]<0){
			h[i]=0;
		}
	}
	for(int i=1;i<=100005;i++){
		sum+=h[i];
	}
	cout<<sum;
	return 0;
}
