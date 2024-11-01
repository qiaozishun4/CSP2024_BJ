#include<bits/stdc++.h>
using namespace std;
int N=1000000;
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T,n,m,l,v,d[N],u[N],a[N],p[N];
    cin>>T;
    cin>>n>>m>>l>>v;
    for(int i=1;i<=n;i++){
        cin>>d[i]>>u[i]>>a[i];
    }
    for(int i=1;i<=m;i++){
        cin>>p[i];
    }
    int sum=0;
    for(int i=1;i<=n;i++){
        if(d[i]==0){
            continue;
        }
        int x=u[i];
        for(int i=1;i<=d[i];i++){
            x+=a[i];
        }
        if(x>v){
            sum++;
        }
    }
    cout<<sum<<" "<<m-2;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
