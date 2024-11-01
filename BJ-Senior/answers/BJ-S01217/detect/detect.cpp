#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int N2=1e3+5;
struct node{
    int d,v,a;
}vehicle[N];
int camera[N2];
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        int n,m,L,V,ans=0,ans2,max_num_of_run_speed=INT_MIN,min_num_of_run_speed=INT_MAX;
        cin>>n>>m>>L>>V;
        ans2=m;
        for(int i=1;i<=n;i++){
            cin>>vehicle[i].d>>vehicle[i].v>>vehicle[i].a;
        }
        for(int i=1;i<=m;i++){
            cin>>camera[i];
        }
        //if speed limited
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(camera[j]>=vehicle[i].d && vehicle[i].v>V){
                    ans++;
                    max_num_of_run_speed=max(max_num_of_run_speed,vehicle[i].d);
                    min_num_of_run_speed=min(min_num_of_run_speed,vehicle[i].d);
                    break;
                }
            }
        }
        for(int i=1;i<=m;i++){
            if(camera[i]>max_num_of_run_speed||camera[i]<min_num_of_run_speed){
                ans2--;
            }
        }
        cout<<ans<<" "<<ans2<<endl;
    }
    return 0;
}
