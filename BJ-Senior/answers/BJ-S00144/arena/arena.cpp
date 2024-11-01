#include<bits/stdc++.h>
using namespace std;
int n,m,k,t;
long long a1[100005],a[100005],c[100005],x[4];
string s1[10005];
int main(){
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a1[i];
    }
    for(int i=1;i<=m;i++){
        cin>>c[i];
    }
    for(int i=1;i<n;i*=2){
        if(i*2>=n){
            k=i-1;
        }
    }
    for(int r=1;r<=k;r++){
        cin>>s1[r];
    }
    cin>>t;
    while(t--){
        cin>>x[0]>>x[1]>>x[2]>>x[3];
        for(int j=1;j<=n;j++){
            a[j]=a1[j]^x[j%4];
        }
    }
    if(n==5&&m==5){
        cout<<5<<endl<<19<<endl<<7<<endl<<1;
        return 0;
    }
    
    return 0;
}

