#include <bits/stdc++.h>
using namespace std;
struct car{
    int d,v,a;
}cars[100010];
int p[100010];
int vis[100010];
vector <int> rd[100010];
int v2[100010],v3[100010];
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        int n,m,L,V;
        cin>>n>>m>>L>>V;
        memset(p,0,sizeof(p));
        memset(cars,0,sizeof(cars));
        memset(vis,0,sizeof(vis));
        memset(rd,0,sizeof(rd));
        memset(v2,0,sizeof(v2));
        memset(v3,0,sizeof(v3));
        for(int i = 1; i <= n; i++){
            cin>>cars[i].d>>cars[i].v>>cars[i].a;
        }
        for(int i = 1; i <= m; i++){
            cin>>p[i];
        }
        int cnt = 0;
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(cars[j].d <= p[i]){
                    int spq = 2*cars[j].a*(p[i]-cars[j].d)+cars[j].v*cars[j].v;
                    if(spq > V*V&&spq>0){
                        if(!vis[j]){
                            vis[j] = 1;
                            cnt++;
                        }
                        rd[i].emplace_back(j);
                    }
                }
            }
            //ddd
        }
        cout<<cnt<<' ';
        int ct = 0;
        for(int i = 1; i <= m; i++){
            int cct = 0;
            int k = -1;
            int kind = -1;
            for(int j = 1; j <= m; j++){
                int ccct = 0;
                for(int k1 = 0; k1 < rd[j].size(); k1++){
                    if(v2[rd[j][k1]] == 0){
                        ccct++;
                    }
                }
                if(ccct > kind){
                    kind = ccct;
                    k = j;
                }
            }
            for(int j = 0; j < rd[k].size(); j++){
                if(v2[rd[k][j]] == 0){
                    cct++;
                    v2[rd[k][j]] = 1;
                }
            }
            v3[k] = 1;
            if(cct){
                ct++;
            }
        }
        cout<<m-ct<<endl;
    }
}
