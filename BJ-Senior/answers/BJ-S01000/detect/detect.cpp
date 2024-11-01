#include<bits/stdc++.h>
using namespace std;
struct car{
    int d,v,a;
    bool over;
};
int f(int n,int m,int L,int V){
    car c[n];
    int p[m];
    int pt[m];
    int dp[n][m];
    int cnt=0;
    for(int i=0;i<n;i++){
        cin>>c[i].d>>c[i].v>>c[i].a;
        c[i].over=true;
    }
    for(int i=0;i<m;i++){
        cin>>p[i];
        pt[i]=0;
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(c[j].d>p[i]){
                if(c[j].v>V){
                    if(c[j].over=true){
                        cnt++;
                        c[j].over=false;
                    }
                }
            }
        }
    }
    return cnt;

}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int t,n,m,L,V;
    cin>>t;
    int a[t];
    for(int i=0;i<t;i++){
        cin>>n>>m>>L>>V;
        a[i]=f(n,m,L,V);
    }
    for(int i=0;i<t;i++){
        cout<<a[i]<<" "<<a[i]-1<<"\n";
    }
    return 0;
}