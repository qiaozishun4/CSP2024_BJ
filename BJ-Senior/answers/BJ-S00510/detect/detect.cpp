#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<cstring>
typedef long long ll;
using namespace std;
vector<int> v[100005];
int in[100005];
struct node{
    int d,v,a;
};
node car[100005];
int p[100005];
struct node2{
    int wz,siz;
    bool operator<(const node2 x)const{
        return siz<x.siz;
    }
};
node2 sizev[100005];
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int n,m,l,V,weiz,t;
    cin>>t;
    while(t--){
        memset(in,0,sizeof(in));
        cin>>n>>m>>l>>V;
        for(int i=1;i<=m;i++){
            v[i].clear();
            sizev[i].siz=0;
            sizev[i].wz=0;
        }
        for(int i=1;i<=n;i++){
            cin>>car[i].d>>car[i].v>>car[i].a;
        }
        for(int i=1;i<=m;i++){
            cin>>p[i];
            sizev[i].wz=i;
        }
        for(int i=1;i<=n;i++){
            if((car[i].v>V&&car[i].a>=0)){
                for(int j=1;j<=m;j++){
                    if(p[j]>car[i].d){
                        v[j].push_back(i);
                        sizev[j].siz++;
                        in[i]++;
                    }
                }
            }
            else if(car[i].v<=V&&car[i].a>0){
                if(car[i].v==V){
                    weiz=car[i].d+1;
                }
                else{
                    weiz=floor((1.0*car[i].d)+(((1.0*V*V)-(1.0*car[i].v*car[i].v))/(2.0*car[i].a)));
                }
                for(int j=1;j<=m;j++){
                    if(p[j]>weiz){
                        v[j].push_back(i);
                        sizev[j].siz++;
                        in[i]++;
                    }
                }
            }
            else if(car[i].v>V&&car[i].a<0){
                weiz=floor((1.0*car[i].d)+(((1.0*V*V)-(1.0*car[i].v*car[i].v))/(2.0*car[i].a)));
                for(int j=1;j<=m;j++){
                    if(p[j]>=car[i].d&&p[j]<=weiz){
                        v[j].push_back(i);
                        sizev[j].siz++;
                        in[i]++;
                    }
                }
            }
        }
        int ans1=0,ans2=0;
        sort(sizev+1,sizev+1+m);
        for(int i=1;i<=n;i++){
            if(in[i]!=0){
                ans1++;
            }
        }
        for(int i=1;i<=m;i++){
            bool flag=true;
            for(auto x:v[sizev[i].wz]){
                if(in[x]<=1){
                    flag=false;
                    break;
                }
            }
            if(flag==true){
                ans2++;
                for(auto x:v[sizev[i].wz]){
                    in[x]--;
                }
            }
        }
        cout<<ans1<<" "<<ans2<<endl;
    }
    return 0;
}
