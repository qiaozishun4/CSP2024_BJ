#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 15;
char map1[N][N];
int n,m,k,xi,yi,di;
bool flag;
// 1 2 0 0 20 0
int dfs(int x,int y,int d,int CT,int k,int n){
    int a = 0,b = 0,c = 0,e = 0;
    if(n == k) flag = true;
    if(d == 0){
        ++y;
        ++a;
    }
    if(d == 1){
        ++x;
        ++b;
    }
    if(d == 2){
        --y;
        ++c;
    }
    if(d == 3){
        --x;
        ++e;
    }
    if(x >= 1 && x <= n && y >= 1 && y <= m && map1[x][y] == '.'){
        if(flag) return ++CT;
        dfs(x,y,d,++CT,k,++n);
    }else{
        if(a == 1){
            --y;
            d = (d + 1) % 4;
            if(flag) return CT;
            dfs(x,y,d,CT,k,++n);
        }
        if(b == 1){
            --x;
            d = (d + 1) % 4;
            if(flag) return CT;
            dfs(x,y,d,CT,k,++n);
        }
        if(c == 1){
            ++y;
            d = (d + 1) % 4;
            if(flag) return CT;
            dfs(x,y,d,CT,k,++n);
        }
        if(e == 1){
            ++x;
            d = (d + 1) % 4;
            if(flag) return CT;
            dfs(x,y,d,CT,k,++n);
        }
    }
}
/*
2
1 5 4
1 1 2
....x
5 5 20
1 1 0
.....
.xxx.
.x.x.
..xx.
x....
*/
int main(){
   freopen("explore.in","r",stdin);
   freopen("explore.out","w",stdout);
  int T;
    scanf("%d",&T);
    while(T--){
        cin >> n >> m >> k;
        cin >> xi >> yi >> di;
        for(int i = 1;i <= n;i++)
            for(int j = 1;j <= m;j++)
                cin >> map1[i][j];
        int CT = 0,n = 0;
        flag = false;
        cout << dfs(xi,yi,di,CT,k,n) << endl;
    }
    return 0;
}

