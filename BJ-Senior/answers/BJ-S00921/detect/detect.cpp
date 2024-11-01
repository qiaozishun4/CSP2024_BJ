#include<bits/stdc++.h>
using namespace std;
int t;
struct node{
    int s1,s2;
}w[100005];
bool cmp(node x,node y){
    return x.s2<y.s2;
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>t;
    while(t--){
        int n,m,L,V,d[100005],v[100005],a[100005],p[100005],vis[1000005]={0},cnt=0,ans=0,tot=0,flag=0;
        cin>>n>>m>>L>>V;
        for(int i=1;i<=n;i++){
            cin>>d[i]>>v[i]>>a[i];
        }
        for(int i=1;i<=m;i++){
            cin>>p[i];
        }
        int mins=10000005;
        for(int i=1;i<=n;i++){
            if(a[i]>0){
//                    if(d[i]>=p[m]&&sqrt(v[i]*v[i]+s*a[i]*p[m]-d[i])>V)){
//                        cnt++;
//                        flag=1;
//                    }
                if(d[i]>p[m])continue;
                if(v[i]>V){
                    cnt++;
                    vis[p[m]]=1;
                    continue;
                }
                int tmp=d[i]+(V*V-v[i]*v[i])/(2*a[i]);//mins buhan yihouliu
                //if((tmp-d[i])*2*a[i]<(V*V-v[i]*v[i]))tmp++;
                if(tmp<p[m])cnt++;
                mins=min(mins,tmp);
//            }else  if(a[i]<0){
//                int s=d[i]+(V*V-v[i]*v[i])/(2*a[i]);//s out
//                if((s-d[i])*2*a[i]<(V*V-v[i]*v[i]))s++;
//                int l=1,r=m,mid,res;
//                while(l<=r){
//                    mid=(l+r)/2;
//                    if(p[mid]<s){
//                        res=mid;
//                        l=mid+1;
//                    }else{
//                        r=mid-1;
//                    }
//                }
//                if(p[res]>=d[i]&&p[res]<s){
//                        vis[p[res]]=1;
//                        cnt++;
//                }
//                if(v[i]>V){
//                    tot++;
//                    w[tot].s1=d[i];
//                    w[tot].s2=s;
//                }
            }else if(a[i]==0){
                if(v[i]>V){
                        vis[p[m]]=1;
                        if(d[i]<=p[m])cnt++;
                }
            }
        }
       // sort(w+1,w+tot+1,cmp);
//        int tmp=-1;
//        for(int i=1;i<=tot;i++){
//                if(w[i].s1<=tmp&&w[i].s2>tmp){
//                        cnt++;
//                        continue;
//                }
//                int l=1,r=m,mid,res=m;
//                while(l<=r){
//                    mid=(l+r)/2;
//                    if(p[mid]<w[i].s2){
//                        res=mid;
//                        l=mid+1;
//                    }else{
//                        r=mid-1;
//                    }
//                }
//                if(p[res]>=w[i].s1&&p[res]<w[i].s2){
//                        vis[p[res]]=1;
//                        tmp=p[res];
//                        cnt++;
//                }
//        }
        if(mins<p[m])vis[p[m]]=1;
    //if(flag==1)vis[p[m]]=1;
        for(int i=1;i<=m;i++){
            if(!vis[p[i]]){
                    ans++;
            }
        }
        cout<<cnt<<" "<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
