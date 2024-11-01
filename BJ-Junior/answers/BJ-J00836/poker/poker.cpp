#include<bits/stdc++.h>
using namespace std;
int z[5][14];
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        char a,b;
        cin>>a>>b;
        int x,y;
        if(a=='D'){
            x=1;
        }else if(a=='C'){
            x=2;
        }else if(a=='H'){
            x=3;
        }else if(a=='S'){
            x=4;
        }
        if(b=='A'){
            y=1;
        }else if(b>='2' && b<='9'){
            y=b-'0';
        }else if(b=='T'){
            y=10;
        }else if(b=='J'){
            y=11;
        }else if(b=='Q'){
            y=12;
        }else if(b=='K'){
            y=13;
        }
        z[x][y]=1;
    }
    int ans=0;
    for(int i=1;i<=4;i++){
        for(int j=1;j<=13;j++){
            if(z[i][j]==0){
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}
