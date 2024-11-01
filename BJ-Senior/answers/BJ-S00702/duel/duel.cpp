#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<vector>
using namespace std;
int x[1000050];
int main(){
    //freopen("duel.out","w",stdin);
    //I know you are reading this, NOIP 2024 RP++!
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        int p;cin>>p;
        x[p]++;
    }
    sort(x+1,x+n+1);
    long long ans=0;
    int lft=0;
    for(int i=0;i<=100000;i++){
        ans+=min(x[i],lft);
        lft-=min(x[i],lft);
        lft+=x[i];
    }
    cout<<n-ans<<endl;
}
