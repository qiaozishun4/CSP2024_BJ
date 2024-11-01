#include <bits/stdc++.h>
using namespace std;
int a[11]={6,2,5,5,4,5,6,3,7,6,0};
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t,ans=-1;
    cin>>t;
    while(t--){
        int n;
        string s="";
        cin>>n;
        for(int i=1;i<=1000000;i++){
            int g=i%10,sh=i/10%10,b=i/100%10,q=i/1000%10,w=i/10000%10,sw=i/100000;
            if(i<10)if(g==0)continue;
            else if(i>=10&&i<100)if(sh==0)continue;
            else if(i>=100&&i<1000)if(b==0)continue;
            else if(i>=1000&&i<10000)if(q==0)continue;
            else if(i>=10000&&i<100000)if(w==0)continue;
            if(i<10)sh=10;
            if(i<100)b=10;
            if(i<1000)q=10;
            if(i<10000)w=10;
            if(i<100000)sw=10;
            int tem=a[g]+a[sh]+a[b]+a[q]+a[w]+a[sw];
            if(tem==n){
                ans=i;break;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
