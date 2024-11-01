#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int X[4]= {0,1,0,-1};
int Y[4] = {1,0,-1,0};
struct node{
    int a,b;
}p[1000005];
bool cmp(node x,node y){
    if(x.a != y.a){
        return x.a<y.a;
    }
    else{
        return x.b<y.b;
    }
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t,n,m,k,x,y,d;
    cin>>t;
    while(t--){
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        char a[1005][1005];
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
               cin>>a[i][j];
            }
        }
        p[1].a = x;
        p[1].b = y;
        int sum = 1;
        for(int i=1;i<=k;i++){
            if(a[x+X[d%4]][y+Y[d%4]] == '.'&& x+X[d%4] >= 1 && x+X[d%4] <= n && y+Y[d%4] >= 1&&y+Y[d%4] <= m){
                x = x+X[d%4];
                y = y+Y[d%4];
                sum++;
                p[sum].a = x;
                p[sum].b = y;
            }
            else{
                d++;
            }
        }
        sort(p+1,p+sum+1,cmp);
        int ans = sum;
        for(int i=2;i<=sum;i++){
            if(p[i].a == p[i-1].a &&p[i].b == p[i-1].b){
                ans--;
            }
        }
        cout<<ans<<endl;
    }
}
