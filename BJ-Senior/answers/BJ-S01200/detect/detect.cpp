#include<iostream>
using namespace std;
int T;
int n,m,L,V;
int d[100005],a[100005],v[100005];
int dtc[100005];
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>T;
    while(T--){
        int Min=100000007;
        cin>>n>>m>>L>>V;
        for(int i=1;i<=n;i++){
            cin>>d[i]>>a[i]>>v[i];
            Min=min(Min,d[i]);
        }
        for(int i=1;i<=m;i++){
            cin>>dtc[i];
        }
        int ans1=0,ans2=0;
        for(int i=1;i<=n;i++){
            if(a[i]>=0){
                if(v[i]>V&&d[i]<=dtc[m-1]){
                    ans1++;
                }
            }

        }
        for(int i=1;i<=m;i++){
            ans2++;
            if(dtc[i]>Min){
                break;
            }
        }
        cout<<ans1<<" "<<ans2<<endl;
    }
    fclose(stdin);
    fclose(stdout);

    return 0;
}
