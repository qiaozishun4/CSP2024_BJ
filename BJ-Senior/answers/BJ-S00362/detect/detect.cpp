#include<bits/stdc++.h>
using namespace std;
struct node{
    double d,v,a;
}a[100005];
vector<int> v[100005];
double b[100005];
double n,m,l,V;
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        cin>>n>>m>>l>>V;
        bool flag=1;
        for(int i=1;i<=n;i++){
            cin>>a[i].d>>a[i].v>>a[i].a;
        }
        for(int i=1;i<=m;i++){
            cin>>b[i];
        }
        int cnt1=0,cnt2=0;
        for(int i=1;i<=n;i++){
            if(a[i].a==0){
                for(int j=1;j<=m;j++){
                    if(a[i].d>b[i])continue;
                    if(a[i].v>V){
                        v[i].push_back(j);
                        if(v[i].size()==1){
                            cnt1++;
                        }
                    }
                }
            }else if(a[i].a>0){
                for(int j=1;j<=m;j++){
                    if(a[i].d>b[i])continue;
                    double c=b[i]-a[i].d;
                    double sx=sqrt(a[i].v*a[i].v+2*a[i].a*c);
                    if(sx>V){
                        v[i].push_back(j);
                        if(v[i].size()==1){
                            cnt1++;
                        }
                    }
                }
            }else{
                for(int j=1;j<=m;j++){
                    if(a[i].d>b[i])continue;
                    double c=b[i]-a[i].d;
                    double sx=sqrt(a[i].v*a[i].v+2*a[i].a*c);
                    if(sx<=0)break;
                    if(sx>V){
                        v[i].push_back(j);
                        if(v[i].size()==1){
                            cnt1++;
                        }
                    }
                }
            }
        }
        cout<<cnt1<<" "<<1<<'\n';
    }
    return 0;
}
