#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int t,n,k,q,l[1005],s[2005],r[1005],c[1005],sl[1005];
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n>>k>>q;
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++){
            cin>>l[i];
            sl[i]=sl[i-1]+l[i];
            for(int j=sl[i-1]+1;j<=sl[i];j++)cin>>s[j];
        }
        int f0=1;
        for(int i=1;i<=q;i++){
            cin>>r[i]>>c[i];
            if(r[i]!=1)f0=0;
        }
        if(f0==1){
            for(int u=1;u<=q;u++){
                int f=0,g=1,r1=r[u],c1=c[u];
                for(int i=1;i<=sl[n];i++){
                    int g1=-1,g2=-1;
                    for(i;i<=sl[g];i++){
                        if(s[i]==1)g1=i;
                        if(s[i]==c[u])g2=i;
                    }
                    g++;
                    if(g1!=-1&&g2!=-1&&g1<g2&&(g2-g1+1)<=k){
                        cout<<1<<endl;
                        f=1;
                        break;
                    }
                }
                if(f==0)cout<<0<<endl;
            }
        }
        else{
            for(int u=1;u<=q;u++){
                cout<<0<<endl;
            }
        }
    }
}
