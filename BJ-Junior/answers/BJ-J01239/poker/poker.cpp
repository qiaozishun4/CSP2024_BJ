#include<bits/stdc++.h>
using namespace std;
bool vis[4][20];
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    for(int i=0;i<4;i++) {
        for(int j=0;j<20;j++) {
            vis[i][j]=0;
        }
    }
    int n,ans=52,cnt;
    cin>>n;
    char a,b;
    for(int i=1;i<=n;i++) {
        cin>>a>>b;
        if(b=='A') {
            cnt=1;
        }
        if(b=='T') {
            cnt=10;
        }
        if(b=='J') {
            cnt=11;
        }
        if(b=='Q') {
            cnt=12;
        }
        if(b=='K') {
            cnt=13;
        }
        if('2'<=b&&b<='9') {
            cnt=b-'0';
        }
        if(a=='D') {
            if(!vis[0][cnt]) {
                vis[0][cnt]=1;
                ans--;
            }
        }
        if(a=='C') {
            if(!vis[1][cnt]) {
                vis[1][cnt]=1;
                ans--;
            }
        }
        if(a=='H') {
            if(!vis[2][cnt]) {
                vis[2][cnt]=1;
                ans--;
            }
        }
        if(a=='S') {
            if(!vis[3][cnt]) {
                vis[3][cnt]=1;
                ans--;
            }
        }
    }
    cout<<ans;
    return 0;
}
