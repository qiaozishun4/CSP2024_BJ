#include<bits/stdc++.h>
using namespace std;
int n,t,a[5][20],cnt;
char hua,dian;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>hua>>dian;
        if(hua=='D') t=0;
        if(hua=='C') t=1;
        if(hua=='H') t=2;
        if(hua=='S') t=3;
        if(dian=='A') a[t][0]=1;
        else if(dian=='T') a[t][9]=1;
        else if(dian=='J') a[t][10]=1;
        else if(dian=='Q') a[t][11]=1;
        else if(dian=='K') a[t][12]=1;
        else a[t][dian-48]=1;
    }
    for(int i=0;i<4;i++){
        for(int j=0;j<13;j++){
            if(a[i][j]==0) cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
