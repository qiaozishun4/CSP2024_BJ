#include<iostream>
#include<cmath>
using namespace std;
int main(){
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n+1],c[m+1];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=m;i++){
        cin>>c[i];
    }
    int k=0;
    while(pow(2,k)<n){
        k++;
    }
    string chou[k+1];
    for(int i=1;i<=n;i++){
        cin>>chou[i];
    }
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        int x[4];
        cin>>x[0]>>x[1]>>x[2]>>x[3];
        int ans=0;
        for(int j=1;j<=n;j++){
            ans=ans^a[j];
        }
    }
    cout<<ans;
    return 0;
}
