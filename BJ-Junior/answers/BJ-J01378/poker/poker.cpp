#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int ans=52;
    bool a[13][4];
    memset(a,0,sizeof(a));
    int i,p,p1,m1;
    cin>>p;
    char m,n;
    string s;
    for(i=0;i<p;i++){
        cin>>s;
        m=s[0];
        n=s[1];
        if(s[0]=='D')p1=0;
        else if(s[0]=='C')p1=1;
        else if(s[0]=='H')p1=2;
        else p1=3;
        if(s[1]=='A')m1=0;
        else if(s[1]=='T')m1=9;
        else if(s[1]=='J')m1=10;
        else if(s[1]=='Q')m1=11;
        else if(s[1]=='K')m1=12;
        else m1=s[1]-'1';
        if(a[m1][p1]==0){
            a[m1][p1]=1;
            ans--;
        }
    }cout<<ans;
}
