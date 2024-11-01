#include <bits/stdc++.h>
using namespace std;

int t;

int m,n,l,V;

struct car{
    int d,v,a;
    vector<int> g;
}c[100005];

int p[100005];

int ansc;
double nowc;

vector<int> chao;

int main(){

    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);

    cin>>t;

    while(t--){
        ansc=0;
        cin>>m>>n>>l>>V;
        for(int i=1;i<=n;++i){
            cin>>c[i].d>>c[i].v>>c[i].a;
        }
        for(int i=1;i<=m;++i){
            cin>>p[i];
        }

        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j){
                nowc=sqrt(2*c[i].a*(p[j]-c[i].d)+pow(c[i].v,2));
                if(nowc>(double)V){
                    ansc++;
                    if(chao.front()!=i){
                        chao.push_back(i);
                    }
                    c[i].g.push_back(j);
                }
            }
        }
        cout<<ansc;
    }

    return 0;
}
