#include<bits/stdc++.h>
using namespace std;
int n,t,k,q,l,a[10010],b[10010],c[10010],d[10010];
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin >>t;
    for(int i=1;i<=t;i++){
        for(int j=1;j<=n;j++){
            cin >> a[j];
        }
        for(int l=1;l<=q;l++){
            cin >> b[l] >> c[l];
            if(b[l] == c[l]){
                d[l] = 1;
            }
            else d[l] = 0;
        }
    }
    for(int i=1;i<=t;i++){
        cout << d[i];
    }
    return 0;
}
