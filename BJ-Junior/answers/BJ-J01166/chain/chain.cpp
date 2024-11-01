#include<bits/stdc++.h>//CSPJ T4不会，写暴力。。。
using namespace std;
vector<int> v[1005];
vector<bool> s[105][1005];
int x[1005];
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    ios::sync_with_stdio(0);
    int T;cin>>T;
    while(T--){
        for(int i=1;i<=1000;i++)v[i].clear();
        for(int i=1;i<=100;i++){
            for(int j=1;j<=1000;j++)s[i][j].clear();
        }
        int n,K,q;cin>>n>>K>>q;
        for(int i=1;i<=n;i++){
            cin>>x[i];
            for(int j=1;j<=x[i];j++){
                int kk;cin>>kk;
                v[i].push_back(kk);
            }
        }
        for(int i=1;i<=100;i++){
            for(int j=1;j<=1000;j++){
                for(int k=0;k<x[j];k++)s[i][j].push_back(0);
            }
        }
        for(int i=1;i<=n;i++){
                for(int j=v[i].size()-1;j>=0;j--){
                    if(v[i][j]==1){
                            int ll=v[i].size();
                        for(int k=j+1;k<=min(ll-1,j+K-1);k++)s[1][i][k]=1;
                    }
                }
        }
        for(int i=2;i<=10;i++){
            for(int j=1;j<=n;j++){
                for(int k=0;k<v[j].size();k++){
                    if(s[i-1][j][k]==1){
                        for(int X=1;X<=n;X++){
                            for(int Y=0;Y<v[X].size();Y++){
                                if(X==j)continue;
                                if(v[j][k]==v[X][Y])s[i][X][Y]=1;
                            }
                        }
                    }
                }
            }
            for(int j=1;j<=n;j++){
                for(int k=v[j].size()-1;k>=0;k--){
                     if(s[i][j][k]==1){
                         s[i][j][k]=0;
                         int hh=v[j].size();
                         for(int l=k+1;l<=min(hh-1,k+K-1);l++)s[i][j][l]=1;
                     }
                }
            }
        }
        while(q--){
            int l,r;cin>>l>>r;
            int ans=0;
            for(int i=1;i<=n;i++){
                if(ans)break;
                for(int j=0;j<v[i].size();j++){
                    if(s[l][i][j]==1&&v[i][j]==r){
                        ans=1;break;
                    }
                }
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}// luogu Uid = 680101 please guanzhu me
