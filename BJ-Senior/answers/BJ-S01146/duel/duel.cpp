#include<bits/stdc++.h>
using namespace std;
int n;
int r[100010];
int tot[100010];
int maxr;
int ans;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>r[i];
        tot[r[i]]++;
        maxr=max(maxr,r[i]);
    }
    /*for(int v=1;v<=maxr;v++){
        if(tot[v]>=(n-tot[v])){
            n=tot[v];
            break;

        }else{


        }
    }*/
    for(int i=1;i<=maxr;i++){
        ans=max(ans,tot[i]);
    }
    cout<<ans;
    return 0;

}

