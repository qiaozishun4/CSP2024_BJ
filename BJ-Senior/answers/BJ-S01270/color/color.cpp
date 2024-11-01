#include <iostream>
#include <cstdio>
using namespace std;
long long t,n,ma=-1,a[200005];
bool b[200005];
void dfs(int p){
    //cout<<p;
    if(p>n){
        long long cnt=0,id0=0,id1=0;
        for(int i=1;i<=n;i++){
            if(b[i]){
                if(a[id1]==a[i])cnt+=a[i];
                id1=i;
            }
        }
        for(int i=1;i<=n;i++){
            if(!b[i]){
                if(a[id0]==a[i])cnt+=a[i];
                id0=i;
            }
        }//cout<<cnt<<' ';
        /*
        for(int i=1;i<=n;i++){
            cout<<b[i];
        }*/
        //cout<<endl;
        ma=max(ma,cnt);
        return;
    }
    b[p]=1;
    dfs(p+1);
    b[p]=0;
    dfs(p+1);
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>t;
    a[0]=-1;
    for(int o=1;o<=t;o++){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        ma=-1;
        dfs(1);
        cout<<ma<<endl;

    }
    return 0;
}
