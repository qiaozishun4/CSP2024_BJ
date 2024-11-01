#include<bits/stdc++.h>
using namespace std;
bool f[5][20];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    char a,b;
    int n;
    cin>>n;
    int ans=0;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        if(a=='C'){
            if(b>='2'&&b<='9'){
                f[0][(b-'0')]++;
            }
            else if(b=='T') f[0][10]++;
            else if(b=='A') f[0][1]++;
            else if(b=='Q') f[0][12]++;
            else if(b=='K') f[0][13]++;
            else if(b=='J') f[0][11]++;
        }
        if(a=='D'){
            if(b>='2'&&b<='9'){
                f[1][(b-'0')]++;
            }
            else if(b=='T') f[1][10]++;
            else if(b=='A') f[1][1]++;
            else if(b=='Q') f[1][12]++;
            else if(b=='K') f[1][13]++;
            else if(b=='J') f[1][11]++;
        }
        if(a=='H'){
            if(b>='2'&&b<='9'){
                f[2][(b-'0')]++;
            }
            else if(b=='T') f[2][10]++;
            else if(b=='A') f[2][1]++;
            else if(b=='Q') f[2][12]++;
            else if(b=='K') f[2][13]++;
            else if(b=='J') f[2][11]++;
        }
        if(a=='S'){
            if(b>='2'&&b<='9'){
                f[3][(b-'0')]++;
            }
            else if(b=='T') f[3][10]++;
            else if(b=='A') f[3][1]++;
            else if(b=='Q') f[3][12]++;
            else if(b=='K') f[3][13]++;
            else if(b=='J') f[3][11]++;
        }
    }
    for(int i=0;i<4;i++){
        for(int j=1;j<=13;j++){
            if(f[i][j]==0) ans++;
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
