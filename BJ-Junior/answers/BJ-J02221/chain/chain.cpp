#include<bits/stdc++.h>
using namespace std;
void calc(){
    int n,k,q;
    cin>>n>>k>>q;
    int l[100010][200010];
    int r[100010][3];
    for(int i=1;i<=n;i++){
        cin>>l[i][0];
        for(int j=1;j<=m;j++){
            cin>>l[i][j];
        }
    }
    for(int i=1;i<=q;i++){
        cin>>r[i][1]>>r[i][2];
    }
    for(int i=1;i<=q;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=l[j][0];k++){
                if(l[j][k]==r[q][2]){
                    cout<<1<<endl;
                    return;
                }
            }
        }
    }
    cout<<0<<endl;
    return;
}
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int T;
    cin>>T;
    while(T--)calc();
    return 0;
}