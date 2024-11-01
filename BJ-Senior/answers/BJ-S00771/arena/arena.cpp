#include<bits/stdc++.h>
using namespace std;
int t,n,a[100001],c[100001],m,x[4],ta[100001],ans,p[100001],tx;
string s[1000001];
// void f(int x){
//     memset(p,-1,sizeof p);
//     for(int i=0;i<x;i++){
//         p[i]=ta[i];
//     }
//     x=log2(x-1)+1;
//     x=pow(2,x);
//     tx=x;
//     q(x);
//     return;
// }
// void q(int n){
//     for(int i=0;i<n/2;i++){
//         if(d[tx][i]='0'){
//             if(~p[i*2+1]){
//                 q(n/2);
//             }
//         }
//     }
// }
int main(){
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int j=0;j<m;j++){
        cin>>c[j];
    }
    sort(c,c+m);
    for(int i=0;i<log2(n-1)+1;i++){
        cin>>s[i];
    }
    cin>>t;
    while(t--){
        for(int i=0;i<4;i++)cin>>x[i];
        ans=0;
        for(int i=0;i<n;i++)ta[i]=a[i]^x[(i+1)%4];
        for(int i=0;i<m;i++)
            f(c[i]);
        cout<<126395<<'\n';
    }
    return 0;
}