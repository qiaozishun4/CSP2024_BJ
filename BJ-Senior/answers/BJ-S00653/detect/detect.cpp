#include<bits/stdc++.h>
using namespace std;
double L,V,d[100010],v[100010],a[100010],l[100010],r[100010],q1[100010],q2[100010],t[1000010];
int c1[100010],c2[100010],p[100010],len[100010],T,n,m,vis[100010];
vector<int> h[1000010];
int pd(int car,int qi){
    if(l[car]==0&&r[car]==0){
        return 0;
    }
    if(l[car]==r[car]&&((q1[car]==0)||(q2[car]==0))){
        return 0;
    }
    if(l[car]==int(l[car])&&l[car]==p[qi]&&q1[car]==1){
        return 1;
    }
    if(r[car]==int(r[car])&&r[car]==p[qi]&&q2[car]==1){
        return 1;
    }
    if(p[qi]>l[car]&&p[qi]<r[car]){
        return 1;
    }
    return 0;
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>T;
    while(T--){
        memset(d,0,sizeof(d));
        memset(v,0,sizeof(v));
        memset(a,0,sizeof(a));
        memset(l,0,sizeof(l));
        memset(r,0,sizeof(r));
        memset(q1,0,sizeof(q1));
        memset(q2,0,sizeof(q2));
        memset(t,0,sizeof(t));
        memset(c1,0,sizeof(c1));
        memset(c2,0,sizeof(c2));
        memset(len,0,sizeof(len));
        memset(vis,0,sizeof(vis));
        cin>>n>>m>>L>>V;
        //cout<<"a";
        for(int i=1;i<=n;++i){
            cin>>d[i]>>v[i]>>a[i];
            if(v[i]>V){
                l[i]=d[i];
                q1[i]=1;
                if(a[i]>=0){
                    r[i]=L;
                    q2[i]=1;
                }
                else{
                    if(d[i]+(V*V-v[i]*v[i])/(2*a[i])<=L){
                        r[i]=d[i]+(V*V-v[i]*v[i])/(2*a[i]);
                    }
                    else{
                        r[i]=L;
                        q2[i]=1;
                    }
                }
            }
            else{
                if(a[i]>0){
                    if(d[i]+(V*V-v[i]*v[i])/(2*a[i])<L){
                        l[i]=d[i]+(V*V-v[i]*v[i])/(2*a[i]);
                        r[i]=L;
                        q2[i]=1;
                    }
                }
            }
        }
        for(int i=1;i<=m;++i){
            cin>>p[i];
            t[int(p[i])]=1;
        }
        sort(p+1,p+m+1);
        int cnt=0;
        for(int i=1;i<=n;++i){
            int x=1,y=m;
            while(x<=y){
                int mid=(x+y)/2;
                if(pd(i,mid)==0&&p[mid]<=l[i]){
                    x=mid+1;
                }
                if(pd(i,mid)==0&&p[mid]>=l[i]){
                    y=mid-1;
                }
                if(pd(i,mid)==1){
                    cnt++;
                    int g=mid;
                    while(pd(i,g-1)==1){
                        g--;
                    }
                    while(pd(i,mid+1)==1){
                        mid++;
                    }
                    len[i]=mid-g+1;
                    c1[i]=g;
                    c2[i]=mid;
                    h[len[i]].push_back(i);
                    break;
                }
                if(mid==(x+y)/2) break;
            }
        }
        cout<<cnt<<' ';
        int ans=m;
        for(int i=1;i<=m;++i){
            for(int j=0;j<h[i].size();++j){
                int z=h[i][j],sf=0;
                for(int k=c1[z];k<=c2[z];++k){
                    if(vis[k]==1){
                        sf=1;
                        break;
                    }
                }
                if(sf==0){
                    ans--;
                    for(int k=c1[z];k<=c2[z];++k){
                        vis[k]=1;
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
