#include <bits/stdc++.h>
using namespace std;
long long n,m;
double L,V,T,d[100010],v[100010],a[100010],p[100010],l[100010],cnt;
bool vis[100010];
void f1(int x){
    if(v[x]<=V)
        l[x]=-1;
    else
        l[x]=L;
}
void f2(int x){
    if(v[x]<=V)
        l[x]=-1;
    else{
        l[x]=min(L,(V*V-v[x]*v[x])/2/a[x]+d[x]);
    }
}
void f3(int x){
    if(V*V>=2*a[x]*(L-d[x])+v[x]*v[x])
        l[x]=-1;
    else{
        l[x]=L;
        double s=(V*V-v[x]*v[x])/2/a[x];
        if(s>0)
            d[x]+=s;
    }
}
bool check(int L,int R){
    if(R<=L)
        return 0;
    if(p[m]>L)
        return 1;
    return 0;
}
bool checkk(int L,int R){
    if(R<L)
        return 0;
    int l=1,r=m;
    while(l<=r){
        int mid=(l+r)/2;
        if(p[mid]>=L&&p[mid]<=R)
            return 1;
        else if(p[mid]<L)
            l=mid+1;
        else if(p[mid]>R)
            r=mid-1;
    }
    return 0;
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>T;
    while(T--){
        memset(vis,0,sizeof(vis));
        cnt=0;
        cin>>n>>m>>L>>V;
        for(int i=1;i<=n;i++){
            cin>>d[i]>>v[i]>>a[i];
        }
        for(int i=1;i<=m;i++){
            cin>>p[i];
        }
        for(int i=1;i<=n;i++){
            if(a[i]==0){
                f1(i);
                if(checkk(d[i],l[i]))
                    cnt++;
            }
            else if(a[i]<0){
                f2(i);
            }
            else if(a[i]>0){
                f3(i);
                if(check(d[i],l[i])){
                cnt++;
            }
            }

            //cout<<d[i]<<" "<<l[i]<<" "<<check(d[i],l[i])<<endl;
        }
        if(cnt!=0)
            cout<<cnt<<" "<<m-1<<"\n";
        else
            cout<<0<<" "<<m<<"\n";
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
2 5 8 9 15*/
