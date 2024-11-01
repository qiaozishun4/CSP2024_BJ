#include<bits/stdc++.h>

using namespace std;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    int a[5][15]={0};
    for(int i=0;i<n;i++){
        char b,c;
        cin>>b>>c;
        if(b=='D'){
            if(c=='T'){
                a[0][9]=1;
            }
            else if(c=='J'){
                a[0][10]=1;
            }
            else if(c=='Q'){
                a[0][11]=1;
            }
            else if(c=='K'){
                a[0][12]=1;
            }
            else if(c=='A'){
                a[0][0]=1;
            }
            else {
            int d=c-'0';
                a[0][d-1]=1;
            }
        }
         if(b=='C'){
            if(c=='T'){
                a[1][9]=1;
            }
            else if(c=='J'){
                a[1][10]=1;
            }
            else if(c=='Q'){
                a[1][11]=1;
            }
            else if(c=='K'){
                a[1][12]=1;
            }
            else if(c=='A'){
                a[1][0]=1;
            }
            else {
            int d=c-'0';
                a[1][d-1]=1;
            }
        }
         if(b=='H'){
            if(c=='T'){
                a[2][9]=1;
            }
            else if(c=='J'){
                a[2][10]=1;
            }
            else if(c=='Q'){
                a[2][11]=1;
            }
            else if(c=='K'){
                a[2][12]=1;
            }
            else if(c=='A'){
                a[2][0]=1;
            }
            else {
            int d=c-'0';
                a[2][d-1]=1;
            }
        }
         if(b=='S'){
            if(c=='T'){
                a[3][9]=1;
            }
            else if(c=='J'){
                a[3][10]=1;
            }
            else if(c=='Q'){
                a[3][11]=1;
            }
            else if(c=='K'){
                a[3][12]=1;
            }
            else if(c=='A'){
                a[3][0]=1;
            }
            else {
            int d=c-'0';
                a[3][d-1]=1;
            }
        }
    }
    int ans=0;
    for(int i=0;i<4;i++){
        for(int j=0;j<13;j++){
            if(a[i][j]==0){
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}
