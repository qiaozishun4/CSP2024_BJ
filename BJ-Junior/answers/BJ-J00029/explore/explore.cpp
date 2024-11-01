#include<bits/stdc++.h>
using namespace std;
char a[1000][1000];
int main(){
    int t,n,m,k,x,y,d,p,q,s;
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++){s=0;
        cin>>n>>m>>k>>x>>y>>d;
        for(int j=1;j<=n;j++){
            for(int k=1;k<=m;k++)cin>>a[j][k];
        }p=x;q=y;while(k--){
            if(d==0&&a[p][q+1]||d==1&&a[p+1][q]||d==2&&a[p][q-1]||d==3&&a[p-1][q])d=(d+1)%4;
            else {s++;
                if(d==0)q++;
                if(d==1)p++;
                if(d==2)q--;
                if(d==3)p--;
            }
        }cout<<s;
    }return 0;
}