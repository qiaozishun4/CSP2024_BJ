#include <bits/stdc++.h>
using namespace std;
int n;
int out=0,maxn=0;
int a[10005],v[10005],dp[10005];
vector<int>x;
int main(){
	//int rp;
	//while(1){
	//rp++;
	//}
    freopen("duel.in","r",stdin);                                                                                                                                              
    freopen("duel.out","w",stdout);                                                                                                                                            
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxn=max(maxn,a[i]);
    }
    for(int i=1;i<=n;i++){
		if(a[i]==maxn){
			x.push_back(i);
		}
	}
	for(int i=1;i<n;i++){
		for(int j=1;j<=n;j++){
			if(a[j]>a[i]){
				dp[j]=max(dp[j],dp[i]+1);
			}
		}
	}
	for(int i=0;i<=x.size();i++){
		out+=dp[x[i]];
	}
	cout<<out;
    return 0;
}