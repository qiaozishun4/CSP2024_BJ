#include <iostream>
#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int T;
int m, n, k, ans[100];
char mp;
bool flag[103][100000];
bool f[103][100000];
int x, y;
int dm[4]={0, 1, 0, -1};
int d;
int dn[4]={1, 0, -1, 0};
int main(){
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    cin>>T;
    for(int q=0;q<T;q++){
            ans[q]=1;
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i=0;i<=m+1;i++){
            for(int j=0;j<=n+1;j++){
                flag[i][j]=0;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>mp;
                if(mp=='x'){
                    flag[i][j]=0;
                }else if(mp=='.'){
                    flag[i][j]=1;
                }
                f[i][j]=1;
            }
        }
        f[x][y]=0;
        for(int i=0;i<k;i++){
            if(!flag[x+dm[d]][y+dn[d]]){
                d=(d+1)%4;
                continue;
            }

            x=x+dm[d];
            y=y+dn[d];
            if(f[x][y]==1){
                ans[q]+=1;
            }
            f[x][y]=0;
            cout<<"("<<x<<","<<y<<")"<<endl;
        }
    }
    for(int i=0;i<T;i++){
        cout<<ans[i]<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
