#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
int a[200005];
int c[200005];
int nx[200005];
int la[200005];
int f[200005][5];
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    freopen("color1.in","r",stdin);
    freopen("color.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        memset(a,0,sizeof(a));
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(c[a[i]]!=0){
                nx[c[a[i]]]=i;
                la[i]=c[a[i]];
                c[a[i]]=i;
            }
        }
        for(int i=1;i<=n;i++){
            int del=0;
            if(la[i]==i-1)
                del=a[i];
            f[i][0]=max(f[i-1][1],f[i-1][0]+del);
            f[i][1]=max(f[i-1][1]+del,f[i-1][0]);
        }
        cout<<max(f[n][0],f[n][1])<<endl;
    }
    return 0;
}
