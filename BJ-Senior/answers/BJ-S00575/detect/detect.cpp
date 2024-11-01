#include<bits/stdc++.h>
using namespace std;
int T,n,m,L,V;
int d[100005],v[100005],a[100005],p[100005];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>T;
    for(int i=1;i<=T;i++){
        int suo=0;
        cin>>n>>m>>L>>V;
        for(int j=1;j<=n;j++){
            cin>>d[j]>>v[j]>>a[j];
            if(v[j]>V) suo++;
        }

        sort(d+1,d+n+1,cmp);
        int f = d[1];
        int s=0;
        for(int j=1;j<=m;j++){
            cin>>p[j];
            if(p[j]>=f) s++;
        }

        cout<<suo<<" ";
        cout<<m-s<<endl;
    }

    return 0;
}