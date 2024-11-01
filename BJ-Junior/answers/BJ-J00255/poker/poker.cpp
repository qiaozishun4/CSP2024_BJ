#include<bits/stdc++.h>
using namespace std;
long long d[20]={};
long long c[20]={};
long long h[20]={};
long long s[20]={};
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    long long n,sum=52;
    cin>>n;
    for(int i=1;i<=n;i++){
        string m;
        cin>>m;
        if(m[0]=='D'){
            if(m[1]=='A') d[1]=1;
            else if(m[1]=='T') d[10]=1;
            else if(m[1]=='J') d[11]=1;
            else if(m[1]=='Q') d[12]=1;
            else if(m[1]=='K') d[13]=1;
            else d[m[1]-'0']=1;
        }
        else if(m[0]=='C'){
            if(m[1]=='A') c[1]=1;
            else if(m[1]=='T') c[10]=1;
            else if(m[1]=='J') c[11]=1;
            else if(m[1]=='Q') c[12]=1;
            else if(m[1]=='K') c[13]=1;
            else c[m[1]-'0']=1;
        }
        else if(m[0]=='H'){
            if(m[1]=='A') h[1]=1;
            else if(m[1]=='T') h[10]=1;
            else if(m[1]=='J') h[11]=1;
            else if(m[1]=='Q') h[12]=1;
            else if(m[1]=='K') h[13]=1;
            else h[m[1]-'0']=1;
        }
        else if(m[0]=='S'){
            if(m[1]=='A') s[1]=1;
            else if(m[1]=='T') s[10]=1;
            else if(m[1]=='J') s[11]=1;
            else if(m[1]=='Q') s[12]=1;
            else if(m[1]=='K') s[13]=1;
            else s[m[1]-'0']=1;
        }
    }
    for(int i=1;i<=13;i++){
        sum=sum-d[i]-c[i]-h[i]-s[i];
    }
    cout<<sum<<endl;
    return 0;
}