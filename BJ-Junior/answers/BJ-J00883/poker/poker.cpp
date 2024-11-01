#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,d[20]={},c[20]={},s[20]={},h[20]={};
    cin>>n;
    for(int i=0;i<n;i++){
        string a;
        cin>>a;
        if(a[0]=='D'){
            if(a[1]=='A') d[1]++;
            else if(a[1]=='T') d[10]++;
            else if(a[1]=='J') d[11]++;
            else if(a[1]=='Q') d[12]++;
            else if(a[1]=='K') d[13]++;
            else d[a[1]-48]++;
        }
        if(a[0]=='C'){
            if(a[1]=='A') c[1]++;
            else if(a[1]=='T') c[10]++;
            else if(a[1]=='J') c[11]++;
            else if(a[1]=='Q') c[12]++;
            else if(a[1]=='K') c[13]++;
            else c[a[1]-48]++;
        }
        if(a[0]=='H'){
            if(a[1]=='A') h[1]++;
            else if(a[1]=='T') h[10]++;
            else if(a[1]=='J') h[11]++;
            else if(a[1]=='Q') h[12]++;
            else if(a[1]=='K') h[13]++;
            else h[a[1]-48]++;
        }
        if(a[0]=='S'){
            if(a[1]=='A') s[1]++;
            else if(a[1]=='T') s[10]++;
            else if(a[1]=='J') s[11]++;
            else if(a[1]=='Q') s[12]++;
            else if(a[1]=='K') s[13]++;
            else s[a[1]-48]++;
        }
    }
    int ans=0;
    for(int i=1;i<=13;i++){
        if(!d[i]) ans++;
        if(!c[i]) ans++;
        if(!h[i]) ans++;
        if(!s[i]) ans++;
    }
    cout<<ans;
    //fclose("poker.in");
    //fclose("poker.out");
    return 0;
}