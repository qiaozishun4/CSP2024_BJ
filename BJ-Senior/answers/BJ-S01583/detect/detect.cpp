#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+7;
struct node{
    int d,v,a;
}k[N];
int n,m,l,v,p[N],h[N];
int main(){
    freopen("detect2.in","r",stdin);
    int T;cin>>T;
    while(T--){
        memset(h,0,sizeof(h));
        cin>>n>>m>>l>>v;
        for(int i=1;i<=n;i++)
            cin>>k[i].d>>k[i].v>>k[i].a;
        for(int i=1;i<=m;i++)
            cin>>p[i];
        for(int i=1;i<=n;i++){
            double left,right,d=0;
            if(k[i].a!=0){
                d=ll(v*v-k[i].v*k[i].v)*1.0/ll(2*k[i].a);
                if(k[i].v>v)    left=k[i].d,right=k[i].d+d;
                else    left=k[i].d+d,right=N;
            }else{
                if(k[i].v>v)left=k[i].d,right=N;
                else    left=-1,right=-1;
            }
            for(int j=1;j<=m;j++)
                if(p[j]<right && p[j]>left)
                    h[i]=j;
        }
        int cnt=0;
        for(int i=1;i<=m;i++){
            if(h[i]>0){
                cnt++;
            }
        }
        cout<<cnt<<'\n';
    }
    return 0;
}
//cout<<"在"<<p[j]<<"位置的"<<j<<"号检测仪探测到"<<i<<"号车辆超速\n";
