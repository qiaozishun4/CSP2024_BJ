#include<bits/stdc++.h>

using namespace std;
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
            int n,m,L,V;
            int d[100010],v[100010],a[100010];
            int p[100010];
            cin>>n>>m>>L>>V;
            int ans=0;
            for(int j=0;j<n;j++){
                cin>>d[j]>>v[j]>>a[j];
                if(v[j]>V){
                    ans++;
                }
            }
            for(int j=0;j<m;j++){
                cin>>p[j];
            }
            cout<<ans<<endl;
            if(ans!=0){
                cout<<m-1<<endl;
            }
            else{
                cout<<m<<endl;
            }
       }
       
    return 0;
}
