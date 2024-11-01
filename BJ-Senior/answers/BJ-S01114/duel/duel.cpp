#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;

int n,maxn,ans;
int dra[N];

int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        dra[x]++;
        maxn=max(maxn,x);
    }
    for(int i=1;i<=maxn;i++){
        if(dra[i]!=0){
            ans-=dra[i];
            if(ans<0) ans=0;
            ans+=dra[i];
        }
    }
    cout<<ans;
    return 0;
}
