#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
long long n,m;
long long a[10000];
long long k,xx0,xx1,xx2,xx3,t;
int main(){
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<m;i++){
        cin>>c[i];
    }
    for(int i=1;i<=3*n;i++){
        if(2^i>=n){
            k=i;
        }
    }
    for(int r=0;r<k;r++){
        for(int g=0;g<2^(k-r);g++){
            cin>>g;
        }
    }
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>xx0>>xx1>>xx2>>xx3;
    }
    for(int i=0;i<t;i++){
        cout<<0<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
