#include<bits/stdc++.h>
using namespace std;
int t,n,m,ans1,ans2;
double p[100010],L,V;
struct car{
    double d,a,v;
}cars[100010];
set<int>s;
set<int>v[100010];
double geta(double a,double s,double v){
    return sqrt(max(v*v*1.0+2.0*a*s,0.00));
}
bool cmp(set<int>a,set<int>b){
    return a.size()>b.size();
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>t;
    while(t--){
        s.clear();
        ans1=0;
        ans2=0;
        cin>>n>>m>>L>>V;
        for(int i=1;i<=n;i++){
            cin>>cars[i].d>>cars[i].v>>cars[i].a;
        }
        for(int i=1;i<=m;i++){
            v[i].clear();
            cin>>p[i];
        }
        bool flag=0;
        for(int i=1;i<=n;i++){
            flag=0;
            for(int j=1;j<=m;j++){
                if(p[j]>=cars[i].d){
                    if(geta(cars[i].a,p[j]-cars[i].d,cars[i].v)>V*1.00){
                        if(flag==0){
                            ans1++;
                            flag=1;
                            //cout<<i<<'\n';
                        }
                        v[j].insert(i);
                    }
                }
            }
        }
        sort(v+1,v+1+m,cmp);
        for(int i=1;i<=m;i++){
            //cout<<v[i].size()<<'\n';
            int front1=s.size();
            for(int can:v[i]){
                //cout<<can<<' ';
                s.insert(can);
                for(int j=i+1;j<=m;j++){
                    v[j].erase(can);
                }
            }
            sort(v+i+1,v+1+m,cmp);
            if(s.size()!=front1){
                ans2++;
            }
            //cout<<'\n';
        }
        cout<<ans1<<' '<<m-ans2<<'\n';
    }

    return 0;
}
