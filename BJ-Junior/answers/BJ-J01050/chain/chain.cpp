#include<bits/stdc++.h>
using namespace std;
int min_dis[200005];
void slove(){
    int n,k,q,kk;
    cin>>n>>k>>q;
    for(int i=1;i<=n;i++){
        int l;cin>>l;kk=-1;
        for(int j=1;j<=l;j++){
            int S;cin>>S;
            if(k>=0)kk++;
            if(kk>=2){
                if(min_dis[S]==0)min_dis[S]=kk;
                min_dis[S]=min(min_dis[S],kk);
            }
            if(S==1)kk=1;
        }
    }
    for(int j=1;j<=q;j++){
        int r,c;cin>>r>>c;
        if(2<=min_dis[c]&&min_dis[c]<=k)cout<<1;
        else cout<<0;
        cout<<endl;
    }
}
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int T;cin>>T;
    while(T--)slove();
    fclose(stdin);
    fclose(stdout);
    return 0;
}
