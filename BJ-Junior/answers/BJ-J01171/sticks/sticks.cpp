#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[10]={6,2,5,5,4,5,6,3,7,6};
int t,p[200005];
signed main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);

    ios::sync_with_stdio(0);
    cin>>t;
    p[0]=0;
    while(t--){
        int n;
        cin>>n;
        if(n==1){
            cout<<"-1\n";continue;
        }
        int w=(n+6)/7;
        for(int i=1;i<=w;i++){
            for(int j=0;j<10;j++){
                if(i==1&&j==0)continue;
                if(n-a[j]<0)continue;
                if(n-a[j]>(w-i)*7)continue;
                if(n-a[j]==1)continue;
                cout<<j;
                n-=a[j];
                break;
            }
        }
        cout<<endl;

    }
    return 0;
}
