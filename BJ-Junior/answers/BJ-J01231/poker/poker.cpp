#include<bits/stdc++.h>
using namespace std;
int a;
int ans=52;
const int N=20;
int d[N],c[N],h[N],s[N];
int f(char x){
        if(x=='A')return 1;
        if(x=='T')return 10;
    if(x=='J')return 11;
    if(x=='Q')return 12;
    if(x=='K')return 13;
    return x-'0';
}
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>a;
    while(a--){
        char x,y;
        cin>>x>>y;
        int n=f(y);
        if(x=='D'){
            if(!d[n]){d[n]=1;ans--;}
        }
        if(x=='C'){
            if(!c[n]){c[n]=1;ans--;}
        }
        if(x=='H'){
            if(!h[n]){h[n]=1;ans--;}
        }
        if(x=='S'){
            if(!s[n]){s[n]=1;ans--;}
        }
    }

    cout<<ans;
    fclose(stdin);
    fclose(stdout);
}
