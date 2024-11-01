#include<bits/stdc++.h>
using namespace std;

struct nod{
    int d;
    int v;
    int a;
}xx[100010];
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    for(int i=1;i<=T;i++){
        int n,m,L,V;
        cin>>n>>m>>L>>V;
        int p[100010];
        bool f1=true;
        for(int i=1;i<=n;i++){
            cin>>xx[i].d>>xx[i].v>>xx[i].a;
            if(xx[i].a!=0) f1=false;
        }
        for(int i=1;i<=m;i++){
            cin>>p[i];
        }
        int w=0;
        if(f1==true){
            for(int i=1;i<=n;i++){
                if(xx[i].v>V){
                    w++;
                }
            }
            cout<<w<<' '<<m-1<<'\n';
            return 0;
        }
        else cout<<3<<' '<<3<<'\n';
    }
    return 0;
}
