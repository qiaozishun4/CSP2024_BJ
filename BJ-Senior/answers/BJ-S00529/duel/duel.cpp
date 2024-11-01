#include<bits/stdc++.h>
#define N 100010
using namespace std;
int num[N];
int ans=0;
int main(){
	freopen("duel.in","r",stdin);	
	freopen("duel.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;	
		num[x]++;
	}
	int ans=0;
	for(int i=0;i<=100000;i++){
		if(num[i]>ans){
			ans=num[i];
		}
	}
	cout<<ans;
	return 0;
}