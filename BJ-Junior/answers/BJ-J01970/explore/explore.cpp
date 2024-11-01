#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
long long int n,m,k;
long long int x,y,d;
long long int t;
long long int g[N][N];
int mx[4]={0,1,0,-1};
int my[4]={1,0,-1,0};
map<long long int ,long long int > ans;
char o;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(long long int j=1;j<=n;j++){
            for(long long int p=1;p<=m;p++){
                    cin>>o;
                    if(o=='x') g[j][p]=0;
                    else g[j][p]=1;
                }
            }
/*
            for(long long int j=1;j<=n;j++){
                for(long long int p=1;p<=m;p++){
                    cout<<g[j][p]<<" ";
                }
                cout<<endl;
            }
*/
        ans[i];
        ans[i]=1;
        g[x][y]=2;
        for(int j=1;j<=k;j++){
            if((x+mx[d])<=n&&(x+mx[d])>=1&&(y+my[d])<=m&&(y+my[d])>=1&&g[(x+mx[d])][(y+my[d])]!=0){
                x+=mx[d];
                y+=my[d];
                if(g[x][y]==1){
                    ans[i]++;
                    g[x][y]++;
                }
            }else{
                d++;
                d%=4;
            }
        }
        //cout<<endl;
    }
    for(int i=1;i<=t;i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}
