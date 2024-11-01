#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,ans=52;
    string a;
    bool q[5][15];
    cin>>n;
    if(n==1){
        cout<<51;
        return 0;
    }
    for(int i=1;i<=5;i++){
        for(int j=1;j<=15;j++){
            q[i][j]==false;
        }
    }
    for(int i=0;i<n;i++){
        cin>>a;
        if(a[0]=='D'){
            if(a[1]=='A') q[1][1]=true;
            else if(a[1]=='T') q[1][10]=true;
            else if(a[1]=='J') q[1][11]=true;
            else if(a[1]=='Q') q[1][12]=true;
            else if(a[1]=='K') q[1][13]=true;
            else q[1][a[1]]=true;
        }
        if(a[0]=='C'){
            if(a[1]=='A') q[2][1]=true;
            else if(a[1]=='T') q[2][10]=true;
            else if(a[1]=='J') q[2][11]=true;
            else if(a[1]=='Q') q[2][12]=true;
            else if(a[1]=='K') q[2][13]=true;
            else q[2][a[1]]=true;
        }
        if(a[0]=='H'){
            if(a[1]=='A') q[3][1]=true;
            else if(a[1]=='T') q[3][10]=true;
            else if(a[1]=='J') q[3][11]=true;
            else if(a[1]=='Q') q[3][12]=true;
            else if(a[1]=='K') q[3][13]=true;
            else q[3][a[1]]=true;
        }
        if(a[0]=='S'){
            if(a[1]=='A') q[4][1]=true;
            else if(a[1]=='T') q[4][10]=true;
            else if(a[1]=='J') q[4][11]=true;
            else if(a[1]=='Q') q[4][12]=true;
            else if(a[1]=='K') q[4][13]=true;
            else q[4][a[1]]=true;
        }
    }
    for(int i=1;i<=4;i++){
        for(int j=1;j<=13;j++){
            if(q[i][j]==true){
                ans--;
            }
        }
    }
    cout<<ans;
    return 0;
}