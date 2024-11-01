#include <bits/stdc++.h>
using namespace std;

const int N=1e5+5;
int n,m,l,lmax,vmax,s,t;
int tou[N],d[N],cnt=0,a[N],v[N],bu,pan,pa;
struct node{
    int a,b;
};
vector<node> ran;
int erfen(int x){
    int ld,rd,mid;
    ld=1,rd=m;
    while(ld<=rd){
        mid=(ld+rd)/2;
        if(tou[mid]>x) rd=mid-1;
        else if(tou[mid]<x) ld=mid+1;
        else{
            ld=mid;
            break;
        }
    }
    return ld;
}
int efz(int x){
    int ld,rd,mid;
    ld=1,rd=m;
    while(ld<=rd){
        mid=(ld+rd)/2;
        if(tou[mid]>x) rd=mid-1;
        else if(tou[mid]<x) ld=mid+1;
        else{
            rd=mid;
            break;
        }
    }
    return rd;
}
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>t;
    while(t--){
        cnt=0,pan=0,pa=0;
        cin>>n>>m>>lmax>>vmax;
        //cn+=n+1;
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&d[i],&v[i],&a[i]);
        }
        for(int i=1;i<=m;i++){
            scanf("%d",&tou[i]);
        }
        for(int i=1;i<=n;i++){
            if(a[i]==0){
                if(v[i]>vmax and d[i]<=tou[m]) cnt++;
                //cout<<i<<" "<<v[i]<<" "<<vmax<<endl;
                pan++;
                continue;
            }else if(a[i]<0){
                if(v[i]<=vmax) continue;
                int biao=erfen(d[i]);
                int num=(pow(vmax,2)-pow(v[i],2))/(2*a[i])+d[i];
                //cout<<i<<" "<<biao<<" "<<num<<endl;
                if(num>tou[biao]){
                    cnt++;
                    int nu=efz(num);
                    ran.push_back({biao,nu});
                }
                pa++;
            }else{
                int num=(pow(vmax,2)-pow(v[i],2))/(2*a[i])+d[i];
                //cout<<i<<" "<<num<<endl;
                if(num<tou[m]) cnt++;
            }
        }
        if(pan==n){
            if(cnt!=0) printf("%d %d\n",cnt,m-1);
            else printf("%d %d\n",cnt,m);
            continue;
        }
        if(pa==0 and pan==0){
            if(cnt!=0) printf("%d %d\n",cnt,m-1);
            else printf("%d %d\n",cnt,m);
            continue;
        }
        printf("%d %d\n",cnt,m-ran.size()-1);
    }
    return 0;
}
