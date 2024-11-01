#include <bits/stdc++.h>

using namespace std;

const int N=1e5+5;
int n,x,c,b[N],att[N],def[N],deford=1,atord=2,ans;

int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%d",&x);
        if(att[x]==0) c++,b[c]=x;
        att[x]++,def[x]++;
    }
    if(c==1){
        cout<<n;
        return 0;
    }
    while(atord!=c+1){
        if(atord==deford){
            atord++;
        }
        if(att[b[atord]]>=def[b[deford]]){
            att[b[atord]]-=def[b[deford]];
            def[b[deford]]=0;
            deford++;
        }else{
            def[b[deford]]-=att[b[atord]];
            att[b[atord]]=0;
            atord++;
        }
    }
    for(int i=1;i<=c;i++){
        ans+=def[b[i]];
    }
    cout<<ans;
    return 0;
}
