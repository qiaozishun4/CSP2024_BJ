#include<bits/stdc++.h>
using namespace std;
int t,n[10],k[10],q[10],l[100010],s[10000][10000],r[100010],c[100010];
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n[i]>>k[i]>>q[i];
        for(int j=1;j<=n[i];j++){
            cin>>l[j];
            for(int m=1;m<=l[j];m++){
                cin>>s[j][m];
            }
        }
        for(int j=1;j<=q[i];j++){
            cin>>r[j]>>c[j];
        }
    }
    for(int i=1;i<=q[1];i++){
            if(k[i]<l[i]){
                cout<<0;
            }
            else{
                cout<<1;
            }
            cout<<endl;
        }

    }

