#include<bits/stdc++.h>
using namespace std;
long long n,c[100],d[100],h[100],s[100],sum=0;
char x,y;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x>>y;
        if(x=='C') c[y]++;
        if(x=='D') d[y]++;
        if(x=='H') h[y]++;
        if(x=='S') s[y]++;
    }
    for(int i=50;i<=57;i++){
        if(c[i]>0) sum++;
        if(d[i]>0) sum++;
        if(h[i]>0) sum++;
        if(s[i]>0) sum++;
    }
    if(c[65]>0) sum++;
    if(d[65]>0) sum++;
    if(h[65]>0) sum++;
    if(s[65]>0) sum++;

    if(c[84]>0) sum++;
    if(d[84]>0) sum++;
    if(h[84]>0) sum++;
    if(s[84]>0) sum++;

    if(c[74]>0) sum++;
    if(d[74]>0) sum++;
    if(h[74]>0) sum++;
    if(s[74]>0) sum++;

    if(c[81]>0) sum++;
    if(d[81]>0) sum++;
    if(h[81]>0) sum++;
    if(s[81]>0) sum++;

    if(c[75]>0) sum++;
    if(d[75]>0) sum++;
    if(h[75]>0) sum++;
    if(s[75]>0) sum++;
    cout<<52-sum;
    return 0;
}
