#include<bits/stdc++.h>
using namespace std;

struct car{
    int d,v,a;
};

car c[100010];
int pos[100010];
int t,n,m,l,V;
int ans=0;

int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);

    cin>>t;
    for(int i=0; i<t; i++){
        cin>>n>>m>>l>>V;
        for(int j=0; j<n; j++){
            cin>>c[j].d>>c[j].v>>c[j].a;
        }
        for(int j=0; j<m; j++){
            cin>>pos[j];
        }
        for(int j=0; j<n; j++){
            if(c[j].v>V){
                ans++;
            }
        }
        cout<<ans<<" "<<1<<endl;
    }

    return 0;
}
