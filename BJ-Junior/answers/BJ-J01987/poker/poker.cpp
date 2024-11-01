#include<bits/stdc++.h>
using namespace std;
bool d[14],c[14],h[14],s[14];
int n;
int res=0;
string l;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>l;
        int temp;
        if(l[1]=='A') temp=1;
        if(l[1]=='J') temp=11;
        if(l[1]=='Q') temp=12;
        if(l[1]=='K') temp=13;
        if(l[1]=='T') temp=10;
        if(l[1]>='2'&&l[1]<='9') temp=l[1]-'0';
        if(l[0]=='D') d[temp]=true;
        if(l[0]=='C') c[temp]=true;
        if(l[0]=='H') h[temp]=true;
        if(l[0]=='S') s[temp]=true;
    }
    for(int i=1;i<=13;i++){
        if(d[i]==false) res++;
        if(c[i]==false) res++;
        if(h[i]==false) res++;
        if(s[i]==false) res++;
    }
    cout<<res;
    return 0;
}
