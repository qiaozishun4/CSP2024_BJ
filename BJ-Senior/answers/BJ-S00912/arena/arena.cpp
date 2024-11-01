#include<bits/stdc++.h>
using namespace std;
int  n,m,a[100010],c[100010],k=1,b[100010],t;
int x0,x1,x2,x3;
int main(){
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    for(int i=1;i<=m;i++){
        cin >> c[i];
    }
    while(1){
        if(pow(2,k) < n){
            k++;
        }
        else break;
    }
    for(int i=1;i<=k;i++){
        for(int j=1;j<=pow(2,k-i);j++){
            cin >> b[j];
        }
    }
    cin >> t;
    for(int i=1;i<=t;i++){
        cin >> x0 >> x1 >> x2 >> x3;
    }
    for(int i=1;i<=t;i++){
        cout << t+x0+x1+x2+x3;
    }
    return 0;
}

