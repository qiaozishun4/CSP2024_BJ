#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[100010],c[100010];
int ans[100010];
int d[30][100010];
struct node {
    int v,w;
};
node tmp[100010];
signed main() {
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    int n,m;
    cin>>n>>m;
    for(int i=1; i<=n; i++) {
        cin>>a[i];
    }
    for(int i=1; i<=m; i++) {
        cin>>c[i];
        for(int tp=0; tp<=30; tp++) {
            if((1<<tp)==c[i]) {
                c[i]=tp;
                break;
            }
        }
    }
    int k=0;
    for(k=0; k<=30; k++) {
        if((1<<k)>=n)break;
    }
    for(int i=1; i<=k; i++) {
        string tmp;
        cin>>tmp;
        for(int j=1; j<=(1<<(k-i)); j++) {
            d[i][j]=tmp[j-1]-'0';
        }
    }
    cin>>t;
    //cout<<t<<'\n';

    for(int _=1; _<=t; _++) {
        int x[4];
        cin>>x[0]>>x[1]>>x[2]>>x[3];
        for(int j=1; j<=n; j++) {
            a[j]^=x[j%4];
        }
        for(int j=1; j<=1<<(k-1); j++) {
            tmp[j]= {j,a[j]};
        }
        //xianran
        ans[0]=1;
        int lc=1,ci=k-1;
        while(ci>=1) {
            ans[lc-1]=tmp[1].v;
            for(int j=1; j<=(1<<(ci-1)); j++) {
                if(d[lc][j]==0) {
                    if(tmp[2*j-1].w>=lc) { //xiao win
                        tmp[j]=tmp[2*j-1];
                    } else {
                        tmp[j]=tmp[2*j];
                    }
                } else {
                    if(tmp[2*j].w>=lc) { //da win
                        tmp[j]=tmp[2*j];
                    } else {
                        tmp[j]=tmp[2*j-1];
                    }
                }
            }
            ci--;
            lc++;
        }
        ans[lc-1]=tmp[1].v;
        int fans=0;
        for(int i=1; i<=m; i++) {
            fans^=(ans[c[i]]*i);
        }
        cout<<fans<<'\n';
        for(int j=1; j<=n; j++) {
            a[j]^=x[j%4];
        }
    }
    return 0;
}
