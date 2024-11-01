#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int a;
    cin>>a;
    for(int l=1;l<=a;l++){
        char t[1001][1001];
        bool t1[1001][1001];
        int n,m,k;
        cin>>n>>m>>k;
        int x,y,d;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>t[i][j];
            }
        }
        int ans=1;
    for(int i=1;i<=k;i++){

        if(d==0){
            if(t[x][y+1]=='.'){
                if(t1[x][y+1]==false){
                    ans++;
                    t1[x][y+1]=true;
                }
                y++;
            }else{
                d++;
            }
        }else if(d==1){
             if(t[x+1][y]=='.'){
                if(t1[x+1][y]==false){
                    ans++;
                    t1[x+1][y]=true;
                }
                x++;
            }else{
                d++;
            }
        }else if(d==2){
            if(t[x][y-1]=='.'){
                if(t1[x][y-1]==false){
                    ans++;
                    t1[x][y-1]=true;
                }
                y--;
            }else{
                d++;
            }
        }else{
            if(t[x-1][y]=='.'){
                if(t1[x-1][y]==false){
                    ans++;
                    t1[x-1][y]=true;
                }
                x--;
            }else{
                d=0;
            }
        }

    }
        cout<<ans;
    }
    return 0;
}
