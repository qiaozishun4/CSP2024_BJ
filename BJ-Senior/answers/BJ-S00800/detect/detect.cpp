#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int p[N],c[N][2];
double ans;
double l,v;
int n,m;
struct node{
    double d,v,a;
}ll[N];
bool ch(int l,int r){
    for(int i=1;i<=m;i++){
        if(p[i]>=l && p[i]<=r)return false;
    }
    return true;
}
bool flag=1,flag1=1;
map<int,int> ol;
int main(){

    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        cin>>n>>m>>l>>v;
        for(int i=1;i<=n;i++){
            cin>>ll[i].d>>ll[i].v>>ll[i].a;
            if(ll[i].a!=0)flag=0;
            if(ll[i].a<=0)flag1=0;
        }
        for(int i=1;i<=m;i++){
            cin>>p[i];
            ol[p[i]]=i;
        }
        if(flag){
            ans=0;
            for(int i=1;i<=n;i++){
                if(ll[i].v>v && ll[i].a<=p[m])ans++;
            }
            if(ans==0)m++;
            cout<<ans<<" "<<m-1<<endl;
        }
        else if(flag1){
            ans=0;
            for(int i=1;i<=n;i++){
                if(ll[i].d > p[m])continue;
                if(ll[i].d+ll[i].a*(p[m]-ll[i].d) > v)ans++;
            }
            if(ans==0)m++;
            cout<<ans<<" "<<m-1;
        }
        else{
            for(int i=1;i<=n;i++){
                if(ll[i].a==0){
                    if(ll[i].v > v){
                        ans++;
                    }
                }else{
                    double lq=(pow(v,2)-pow(ll[i].v,2))/(2*ll[i].a) + ll[i].d;
                    if(ll[i].a>0){
                        int idx=*(lower_bound(p+1,p+m+1,lq));
                        if(ch(ceil(lq),l))continue;
                        ans++;
                    }else{
                        if(ll[i].v > v){
                            if(ch(ll[i].d,floor(lq)))continue;
                            ans++;
                        }
                    }
                }
            }
            cout<<ans<<" "<<ans<<endl;
        }
    }
    fclose(stdin);
    fclose(stdout);

    return 0;
}
