#include<bits/stdc++.h>
#include<cstdio>
using namespace std;

int getx(int a,int p){
    if(p == 1) return a+1;
    if(p == 3) return a-1;
    return a;
}
int gety(int a,int p){
    if(p == 0) return a+1;
    if(p == 2) return a-1;
    return a;
}

int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int n,m,k,t,ans = 0;
    bool g[1005][1005] = {},v[1005][1005] = {};
    char c;
    string s;
    int x,y,d;
    cin>> t;
    while(t--){
        memset(g,0,sizeof(g));
        memset(v,0,sizeof(v));
        ans = 1;
        cin>>n >> m >> k;
        cin>> x >> y >>d;
        v[x][y] = true;
        for(int i=1;i<=n;i++){
            cin>> s;
            for(int j=0;j<m;j++){
                c = s[j];
                if(c == '.') g[i][j+1] = true;
            }
        }
        while(k--){
            if(g[getx(x,d)][gety(y,d)]){
                x = getx(x,d);
                y = gety(y,d);
                if(!v[x][y]){
                    v[x][y] = true;
                    ans++;
                }
            }
            else{
                d = (d+1)%4;
            }
        }
        cout<< ans << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}