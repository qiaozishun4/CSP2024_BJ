#include<bits/stdc++.h>
using namespace std;
int a[5][15],n,ans=52;
int hs(char c){
    if(c=='D')return 0;
    if(c=='C')return 1;
    if(c=='H')return 2;
    if(c=='S')return 3;
}
int ds(char c){
    if(c=='A')return 1;
    if(c>='2'&&c<='9')return c-'0';
    if(c=='T')return 10;
    if(c=='J')return 11;
    if(c=='Q')return 12;
    if(c=='K')return 13;
}
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    while(n--){
        char d,h;
        cin>>h>>d;
        if(a[hs(h)][ds(d)]==0){
            ans--;
            a[hs(h)][ds(d)]=1;
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
