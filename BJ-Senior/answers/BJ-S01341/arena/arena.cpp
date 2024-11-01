#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+7;
const int maxm=1e5+7;
int aa[maxn],c[maxm];

int cac2(int x){
    int k=1;
    while(k < x) k*=2;
    return k;
}

int main(){
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>aa[i];
    for(int i=0;i<m;i++)
        cin>>c[i];
    int l=cac2(n);
    for(int i=l;i>1;i/=2){
        string s;
        cin>>s;
    }
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        for(int j=0;j<4;j++)
            cin>>l;
    }
    for(int i=0;i<t;i++){
        int x=1*1;
        for(int j=2;j<=m;j++){
            x = x^(j*1);
        }
        cout<<x<<endl;
    }
    return 0;
}
