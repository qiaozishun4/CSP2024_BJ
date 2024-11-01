#include <bits/stdc++.h>
using namespace std;
int t;
int n,m,l,v;
struct car{
    int d=0,v=0,a=0;
    double ms=0;
    int l=0,r=0;
};
vector<int> road[1000005];
int main(){
    ios::sync_with_stdio(false);
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    
    cin>>t;
    while(t--){
        car a[100005];
        for(int i=0;i<1000005;i++)road[i].clear();
        map<int,int> ext;
        cin>>n>>m>>l>>v;
        for(int i=0;i<n;i++){
            cin>>a[i].d>>a[i].v>>a[i].a;
            if(a[i].a==0){
                if(a[i].v>v){
                    a[i].l=a[i].d;
                    a[i].r=l;
                }else{
                    a[i].l=a[i].r=l+1;
                }
            }else{
                a[i].ms=a[i].d+(pow(v,2)-pow(a[i].v,2))/(2*a[i].a);
                if(a[i].v<=v){
                    a[i].l=a[i].ms+1;
                    a[i].r=l;
                    if(a[i].l>a[i].r)a[i].l=a[i].r=l+1;
                }else{
                    a[i].l=a[i].d;
                    a[i].r=min(l,(int)a[i].ms);
                }
            }
            for(int j=a[i].l;j<=a[i].r;j++){
                road[j].push_back(i);
            }
            //cout<<a[i].l<<" "<<a[i].r<<endl;
        }
        int q[100005]={0};
        for(int i=0;i<m;i++){
            cin>>q[i];
            for(int j=0;j<road[q[i]].size();j++){
                ext[road[q[i]][j]]++;
            }
        }
        int ans=0;
        for(auto v:ext){
            ans++;
        }
        int kick=0;
        for(int i=0;i<m;i++){
            for(int j=i+1;j<m;j++){
                if(i==j)continue;
                bool flag1=false;
                for(int k=0;k<road[q[i]].size();k++){
                    if(road[q[i]][k]==road[q[j]][0])flag1=true;
                    if(flag1&&road[q[i]][k]==road[q[j]][road[q[j]].size()-1])kick++;
                }
            }
        }
        cout<<ans<<endl<<m-kick+1<<endl;
    }
    
    return 0;
}