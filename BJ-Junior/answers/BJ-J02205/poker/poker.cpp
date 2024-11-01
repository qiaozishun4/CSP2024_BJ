#include<bits/stdc++.h>
using namespace std;
bool d[13],c[13],h[13],s[13];
int main(){
    freopen("pocker.in","r",stdin);
    freopen("pocker.out","w",stdout);
    int n,ans=0;
    string a;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a;
        if(a[0]=='D')d[f(a[1])]==1;
        else if(a[0]=='c')c[f(a[1])]==1;
        else if(a[0]=='h')h[f(a[1])]==1;
        else s[f(a[1])]==1;
    }
    for(int i=0;i<13;i++){
        if(d[i]==0)ans++;
    }
    for(int i=0;i<13;i++){
        if(c[i]==0)ans++;
    }
    for(int i=0;i<13;i++){
        if(h[i]==0)ans++;
    }
    for(int i=0;i<13;i++){
        if(s[i]==0)ans++;
    }
    cout<<ans;
    return 0;
}
int f(char b){
    if(b=='A')return 0;
    else if(b=='2')return 1;
    else if(b=='3')return 2;
    else if(b=='4')return 3;
    else if(b=='5')return 4;
    else if(b=='6')return 5;
    else if(b=='7')return 6;
    else if(b=='8')return 7;
    else if(b=='9')return 8;
    else if(b=='T')return 9;
    else if(b=='J')return 10;
    else if(b=='Q')return 11;
    else if(b=='K')return 12;
}