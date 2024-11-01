#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int T,n,m,L,V,ma;
int d[N],v[N],a[N],p[N],num[N],up[N],ans,cnt,f;
struct node{
    int si,al=0;
}w[N];
vector<int> road[N],s[N];
int fi(double x,int y,int z){
    int l=1,r=m;
    while(l<r){
        int mid=(l+r)/2;
        if(p[mid]>x){
            r=mid-1;
        }else if(p[mid]<x){
            l=mid+1;
        }else{
            return mid+y+z;
        }
    }
    if(p[l]<x){
        return l+y;
    }else{
        return l+z;
    }
}
bool cmp(node a,node b){
    return a.al>b.al;
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        ma=INT_MIN;
        cnt=0;
        memset(num,0,sizeof(num));
        memset(up,0,sizeof(up));
        ans=0;
        f=0;
        scanf("%d%d%d%d",&n,&m,&L,&V);
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&d[i],&v[i],&a[i]);
        }
        for(int i=1;i<=m;i++){
            scanf("%d",&p[i]);
        }
        for(int i=1;i<=n;i++){
            if(a[i]!=0){
                double tv=(V*V-v[i]*v[i])*1.0/2/a[i]+d[i];
                if(a[i]>0){
                    num[i]=fi(tv,1,0);
                    if(tv<=p[m]){
                        up[num[i]]++;
                    }else{
                        num[i]=-1;
                    }
                }
                if(a[i]<0){
                    num[i]=fi(tv,0,-1);
                    int k=fi(d[i],0,-1);
                    if(d[i]<=p[num[i]]&&p[num[i]]<tv){
                        for(int j=k+1;j<=num[i];j++){
                            road[i].push_back(j);
                            s[j].push_back(i);
                            w[j].si=j;
                            w[j].al++;
                        }
                        cnt++;
                    }else{
                        num[i]=-1;
                    }
                }
            }else{
                if(v[i]>V){
                    num[i]=fi(d[i],1,0);
                    up[num[i]]++;
                }
            }
        }
        for(int i=1;i<=m;i++){
            up[i]+=up[i-1];
            if(ma<up[i]){
                ma=up[i];
                f=i;
            }
        }
        ma=1;
        cnt+=up[m];
        sort(w+1,w+1+n,cmp);
        while(w[1].al!=0){
            sort(w+1,w+1+n,cmp);
            if(f<=w[1].si){
                ma=0;
            }
            ans++;
            w[1].al=0;
            for(auto i:s[w[1].si]){
                for(auto j:road[i]){
                    w[j].al--;
                }
                road[i].clear();
            }
        }
        /*for(int i=1;i<=m;i++){
            cout<<up[i]<<" ";
        }
        cout<<endl;
        cout<<ma<<endl;*/
        cout<<cnt<<" "<<m-ans-ma<<endl;
    }
    return 0;
}
