#include<bits/stdc++.h>
using namespace std;
int n,b,ans=0,d[20],c[20],h[20],s[20];
string a;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a;
        if(a[1]=='A'){
            b=1;
        }else if(a[1]=='T'){
            b=10;
        }else if(a[1]=='J'){
            b=11;
        }else if(a[1]=='Q'){
            b=12;
        }else if(a[1]=='K'){
            b=13;
        }else{
            b=int(a[1]-48);
        }
        if(a[0]=='D'){
            d[b]=1;
        }else if(a[0]=='C'){
            c[b]=1;
        }else if(a[0]=='H'){
            h[b]=1;
        }else if(a[0]=='S'){
            s[b]=1;
        }
    }
    for(int i=1;i<=13;i++){
        if(!d[i]){
            ans++;
        }
        if(!c[i]){
            ans++;
        }
        if(!h[i]){
            ans++;
        }
        if(!s[i]){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
