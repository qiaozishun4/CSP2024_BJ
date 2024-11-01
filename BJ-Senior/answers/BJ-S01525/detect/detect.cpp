#include<bits/stdc++.h>
using namespace std;
const int N=100005;
struct Ccar{
    int d,v,a;
}car[N];
int b[N];
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T; cin>>T;
    for(int t=1;t<=T;t++){
        int n,m,L,V;
        cin>>n>>m>>L>>V;
        int ans1=0;
        for(int i=1;i<=n;i++){
            cin>>car[i].d;
            cin>>car[i].v;
            cin>>car[i].a;
            if(car[i].v>V){
                ans1++;
            }
        }
        for(int i=1;i<=m;i++){
            cin>>b[i];
        }
        cout<<ans1<<' '<<m-1<<endl;
    }
    return 0;
}
