#include<bits/stdc++.h>
using namespace std;
long long n,ans,minx=1e16;
int numtost[10]={6,2,5,5,4,5,6,3,7,6};
void dfs(int cur,long long num,int k) {
    if(cur<0) {
        return ;
    } if(num>=minx) {
        return ;
    } else if(cur==0) {
		if(num>0) {
			minx=min(minx,num);
		}
		return ;
    } else {
        for(int i=0;i<=9;i++){
            if((i==0&&cur==6)||cur<numtost[i]) continue;
            else {
                dfs(cur-numtost[i],num+k*i,k*10);
            }
        }
    } return ;
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    ios::sync_with_stdio(false);
    int t; cin>>t;
    while(t--) {
        minx=1e16;
        cin>>n;
        if(n<2) {
			cout<<-1<<"\n";
			continue;
		}
        dfs(n,0,1);
        if(minx==1e6) cout<<-1<<  "\n";
        else          cout<<minx<<"\n";
    }
    return 0;
}
