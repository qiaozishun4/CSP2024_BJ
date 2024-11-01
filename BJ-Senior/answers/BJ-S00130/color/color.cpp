#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int a[1005],inf=0x3f3f3f3f;
int n;
int ck(int x){
    bool c[1005];
    int sum=0;
    for(int i=0;i<n;i++){
        bool s=x%2;
        x/=2;
        c[i]=s;
    }
    for(int i=1;i<n;i++){
        for(int j=i-1;j>=0;j--){
            if(c[i]==c[j]){
                if(a[i]==a[j]) sum+=a[i];
                break;
            }
        }
    }
    return sum;
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        memset(a,0,sizeof(a));
        cin>>n;
        int maxn=-inf;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<(1<<n);i++){
            int s=ck(i);
            maxn=max(maxn,s);
        }
        cout<<maxn<<'\n';
    }
    return 0;
}
