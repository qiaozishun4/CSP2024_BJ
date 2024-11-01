#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
int d[114514],v[114514],a[114514];
int p[114514];
int cntp[1145140];
int overs[1145140];
db D(db v1,db v0,db a){
    return (v1*v1-v0*v0)/(2*a);
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        int n,m,L,V;
        cin>>n>>m>>L>>V;
        int task=0;
        for(int i=1;i<=n;i++)cin>>d[i]>>v[i]>>a[i];
        if(a[1]==0)task=1;
        if(a[1]>0)task=2;
        if(a[1]<0)task=3;
        for(int i=0;i<=L;i++)cntp[i]=-1;
        for(int i=1;i<=m;i++)cin>>p[i],cntp[p[i]]=i;

        int last=-1;
        for(int i=L;i>=0;i--)
            if(cntp[i]>0)last=cntp[i];
            else cntp[i]=last;

        if(task==1){
            int over=0;
            for(int i=1;i<=n;i++)
                if(v[i]>V)
                    if(cntp[d[i]]!=-1)over++;
            cout<<over<<' '<<m-(over?1:0)<<'\n';
        }
    }
    return 0;
}
/*
1
5 5 15 3
0 3 0
12 4 0
1 1 4
5 5 -2
6 4 -4
2 5 8 9 15

*/
