#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int r[100005],n,ssort[100005],ans;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>r[i];
		ssort[r[i]]++;
	}
	for(int i=1;i<100002;i++){
		ssort[i+1]=max(ssort[i],ssort[i+1]);
		ans=max(ans,ssort[i+1]);
	}
	cout<<ans;
	return 0;
}
