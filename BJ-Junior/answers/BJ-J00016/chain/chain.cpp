#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int t,n,m,k,q,a[100010],b[100010],s[200010],sss[100000000],h=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n>>m>>q;
        for(int x=1;x<=n;x++){
            cin>>k;
            for(int y=1;y<=k;y++) cin>>s[i];
            for(int y=h;y<=h+k;y++) sss[i]=s[i];
            h=k;
        }
        for(int x=1;x<=q;x++){
            cin>>a[i]>>b[i];
        }
        int p=0;
        for(int i=1;i<=q;i++){
            for(int i=1;i<=n;i++){
                if(b[i]==sss[i]) p=1;
            }
            if(p==0) cout<<0<<endl;
            else cout<<1<<endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
