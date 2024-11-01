#include<bits/stdc++.h>
using namespace std;
struct q{
    int d;
    int v;
    int a;
};
const int N=1e5+10;
q x[N];
int M[N];
int c[N];
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n,m,l,v;
        cin>>n>>m>>l>>v;
        int k=0;
        for(int i=1;i<=n;i++){
            cin>>x[i].d>>x[i].v>>x[i].a;
            if(x[i].v>v){
                k++;
                c[k]=i;
            }
        }for(int i=1;i<=m;i++){
            cin>>M[i];
        }
        int sum=l+10;
        for(int i=1;i<=k;i++){
            min(sum,x[c[i]].d);
        }
        int cnt=0;
        for(int i=1;i<=m;i++){
            if(M[i]>=sum){
                cnt++;
            }
        }
        cout<<m-cnt;
    }
    return 0;
}