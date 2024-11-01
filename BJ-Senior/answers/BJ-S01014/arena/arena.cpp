#include<iostream>
#include<cstdio>
using namespace std;

const int MAX=2000000;
int n,m,T;
int a[MAX],b[MAX],c[MAX],t[MAX][4];

int main(){
    int r,g;
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);

    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int j=0;j<m;j++)
        cin>>c[j];

    for(int k=1;k<n;k++){
        int q=2;
        for(int i=0;i<k;i++)
            q*=2;
        if(q>=n) break;
    }

    for(int i=0;i<n;i++)
        cin>>b[i];

    cin>>T;
    for(int i=0;i<T;i++)
        for(int j=0;j<4;j++)
            cin>>t[i][j];

    return 0;
}
