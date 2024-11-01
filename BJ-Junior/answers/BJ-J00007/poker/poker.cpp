#include<bits/stdc++.h>
using namespace std;
bool d[13],h[13],s[13],c[13];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int q;
    cin>>q;
    while(q--){
        string x;
        cin>>x;
        if(x[0]=='D'){
            if(x[1]>='2'&&x[1]<='9') d[x[1]-'0'-1]=1;
            else if(x[1]=='A') d[0]=1;
            else if(x[1]=='J') d[10]=1;
            else if(x[1]=='Q') d[11]=1;
            else if(x[1]=='K') d[12]=1;
            else if(x[1]=='T') d[9]=1;
        }else if(x[0]=='S'){
            if(x[1]>='2'&&x[1]<='9') s[x[1]-'0'-1]=1;
            else if(x[1]=='A') s[0]=1;
            else if(x[1]=='J') s[10]=1;
            else if(x[1]=='Q') s[11]=1;
            else if(x[1]=='K') s[12]=1;
            else if(x[1]=='T') s[9]=1;
        }else if(x[0]=='C'){
            if(x[1]>='2'&&x[1]<='9') c[x[1]-'0'-1]=1;
            else if(x[1]=='A') c[0]=1;
            else if(x[1]=='J') c[10]=1;
            else if(x[1]=='Q') c[11]=1;
            else if(x[1]=='K') c[12]=1;
            else if(x[1]=='T') c[9]=1;
        }else if(x[0]=='H'){
            if(x[1]>='2'&&x[1]<='9') h[x[1]-'0'-1]=1;
            else if(x[1]=='A') h[0]=1;
            else if(x[1]=='J') h[10]=1;
            else if(x[1]=='Q') h[11]=1;
            else if(x[1]=='K') h[12]=1;
            else if(x[1]=='T') h[9]=1;
        }
    }
    int cnt=0;
    for(int i=0;i<13;i++){
        if(!d[i]) cnt++;
    }
    for(int i=0;i<13;i++){
        if(!s[i]) cnt++;
    }
    for(int i=0;i<13;i++){
        if(!h[i]) cnt++;
    }
    for(int i=0;i<13;i++){
        if(!c[i]) cnt++;
    }
    cout<<cnt;
    return 0;
}
