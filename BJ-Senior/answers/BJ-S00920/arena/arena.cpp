#include<bits/stdc++.h>
using namespace std;
int T,n,m,a[1000006],c[1000006],q1,q2,q3,x1[1000006],x2[1000006],x3[1000006],x4[1000006],maxx[1000006];
int main(){
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=m;i++){
        cin>>c[i];
    }
    cin>>q1>>q2>>q3>>T;
    while(T--){
        for(int i=1;i<=4;i++){
            cin>>x1[i]>>x2[i]>>x3[i]>>x4[i];
        }
    }
    maxx[1]=max(x1[1],max(x2[1],max(x3[1],x4[1])));
    maxx[2]=max(x1[2],max(x2[2],max(x3[2],x4[2])));
    maxx[3]=max(x1[3],max(x2[3],max(x3[3],x4[3])));
    maxx[4]=max(x1[4],max(x2[4],max(x3[4],x4[4])));
    cout<<maxx[1]-1<<endl<<maxx[2]-1<<endl<<maxx[3]-1<<endl<<maxx[4]-1;
return 0;
}
