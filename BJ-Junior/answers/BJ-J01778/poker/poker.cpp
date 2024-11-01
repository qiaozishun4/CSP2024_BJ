#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int a[20][10];
int n,ans;
string s;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s;
        int x,y;
        if(s[1]=='A')x=1;
        if(s[1]=='2')x=2;
        if(s[1]=='3')x=3;
        if(s[1]=='4')x=4;
        if(s[1]=='5')x=5;
        if(s[1]=='6')x=6;
        if(s[1]=='7')x=7;
        if(s[1]=='8')x=8;
        if(s[1]=='9')x=9;
        if(s[1]=='T')x=10;
        if(s[1]=='J')x=11;
        if(s[1]=='Q')x=12;
        if(s[1]=='K')x=13;
        if(s[0]=='D')y=1;
        if(s[0]=='C')y=2;
        if(s[0]=='H')y=3;
        if(s[0]=='S')y=4;
        if(a[y][x]==0){
            a[y][x]=1;
            ans++;
        }
    }
    cout<<52-ans;
    return 0;
}