#include<bits/stdc++.h>
using namespace std;
int n,p[60]={};
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        char a,b;
        cin>>a>>b;
        int n=0;
        if(a=='c')n+=13;
        if(a=='h')n+=26;
        if(a=='s')n+=39;
        if(b=='A')n+=1;
        if(b=='2')n+=2;
        if(b=='3')n+=3;
        if(b=='4')n+=4;
        if(b=='5')n+=5;
        if(b=='6')n+=6;
        if(b=='7')n+=7;
        if(b=='8')n+=8;
        if(b=='9')n+=9;
        if(b=='T')n+=10;
        if(b=='J')n+=11;
        if(b=='Q')n+=12;
        if(b=='K')n+=13;
        p[n]++;
    }
    int cnt=0;
    for(int i=1;i<=52;i++){
        if(!p[i])cnt++;
    }
    cout<<cnt;
    return 0;
}
