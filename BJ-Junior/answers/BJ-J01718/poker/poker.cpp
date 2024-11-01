#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct poooker{
    char hs;
    int sz;
}a[1005];
int p[1005]={};
ll n;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].hs;
        char t;
        ll tlx,tly;
        if(a[i].hs=='D') tly=0;
        else if(a[i].hs=='C') tly=1;
        else if(a[i].hs=='H') tly=2;
        else if(a[i].hs=='S') tly=3;
        cin>>t;
        if(t=='J') tlx=11;
        else if(t=='Q') tlx=12;
        else if(t=='K') tlx=13;
        else if(t=='T') tlx=10;
        else if(t=='A') tlx=1;
        a[i].sz=tlx;
        p[13*tly+tlx]++;
    }
    ll cnt=0;
    for(int i=1;i<=52;i++){
        if(p[i]==0) cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}
