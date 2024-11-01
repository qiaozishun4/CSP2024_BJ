#include<bits/stdc++.h>
using namespace std;
string a[200];
long long ans=52;
int main()
{
    //std::ios_sync_stdio
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    long long n;
    cin>>n;
    for(long long i=1;i<=n;i++){
        string b;
        bool zt=1;//b chuanxianguo zt=0
        cin>>b;
        for(long long j=1;j<=200;j++){
            if(b==a[j]){
                zt=0;
                break;

            }
        }
        if(zt==1){
            a[i]=b;
            ans--;
        }

    }
    if(ans<0){
        ans=0;
    }
    cout<<ans;
    return 0;
}