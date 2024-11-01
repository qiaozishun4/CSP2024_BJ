#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
vector<int> to[100001];
vector<int> fr[100001];
int cnt[100001];
int cnt2[100001];
int d[100001];
int v[100001];
int a[100001];
int p[100001];
bool c[100001];
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        int n,m,L,V,sum=0,ans=0;
        cin>>n>>m>>L>>V;
        for(int i=1;i<=n;i++){
            cin>>d[i]>>v[i]>>a[i];
        }
        for(int i=1;i<=m;i++){
            cin>>p[i];
        }
        for(int i=1;i<=n;i++){
            if(v[i]>V){
                sum++;
                for(int j=1;j<=m;j++){
                    if(p[j]>=d[i]){
                        to[j].push_back(i);
                        fr[i].push_back(j);
                        cnt[i]++;
                        cnt2[j]++;
                    }
                }
            }
        }
        cout<<sum<<" "<<m/2<<endl;
        // hou tou zhen de bu hui le
        // zhi neng pian fen
        // mei you SPJ TaT
    }
    return 0;
}