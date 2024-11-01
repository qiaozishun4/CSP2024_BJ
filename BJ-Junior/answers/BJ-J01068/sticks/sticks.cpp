#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int sz[10][10];
int a[N], ans[N];
int cnt = 0;
bool flag;
void dfs(int d, int n){
    if(n==1) return;
    if(n==0){
            int o = 0;
        while(a[o]==ans[o]&&o<99999){
            o++;
        }
        if(o==99999) return;
        if(a[o]<ans[o]){
            flag = true;
            for(int i = 1; i<d; i++){
                ans[i] = a[i];
            }
            cnt = d-1;
        }
        return;
    }
    for(int i = 2; i<=7; i++){
        if(i>n) continue;
        for(int j = 1; j<=5; j++){
          if(sz[i][j]!=-1){
             if(sz[i][j]!=0||d!=1){
                a[d] = sz[i][j];
                dfs(d+1, n-i);
             }
          }
       }
    }
}
int main(){
    freopen("stick.in","r",stdin);
    freopen("stick.out","w",stdout);
    memset(sz, -1, sizeof(sz));
    for(int i = 2; i<=7; i++){
        if(i==2){
            sz[i][1] = 1;
        }else if(i==3){
            sz[i][1] = 7;
        }else if(i==4){
            sz[i][1] = 4;
        }else if(i==5){
            sz[i][1] = 2, sz[i][2] = 3, sz[i][3] = 5;
        }else if(i==6){
            sz[i][1] = 0, sz[i][2] = 6, sz[i][3] = 9;
        }else{
            sz[i][1] = 8;
        }
    }
    int T;
    cin >> T;
    while(T--){
        cnt = 0;
        flag = false;
        memset(a, 0, sizeof(a));
        memset(ans, 9, sizeof(ans));
        int n;
        cin >> n;
        dfs(1, n);
        if(!flag) cout << -1 << endl;
        else{
            for(int i = 1; i<=cnt; i++){
                cout << ans[i];
            }
            cout << endl;
        }
    }
    return 0;
}
