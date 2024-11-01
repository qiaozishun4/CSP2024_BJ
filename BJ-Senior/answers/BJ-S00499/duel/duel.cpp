#include <bits/stdc++.h>
using namespace std;

long long n;
long long a[100005];

long long ans;

int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;

    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    for(long long i=1;i<=n;i++){
        for(long long j=1;j<=n;j++){
            if(a[i]<=a[j]){

                continue;
            }
            if(a[i]>a[j] and a[j]!=-1){
                ans++;
                a[j]=-1;
                break;
            }

        }

    }

    cout<<n-ans;


    return 0;
}
