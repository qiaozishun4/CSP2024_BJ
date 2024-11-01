#include<bits/stdc++.h>
using namespace std;
int a[200010];
int lr[20],lb[20];
int main() {
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        for(int i=1; i<=n; i++) {
            cin>>a[i];
        }
        if(n<=15) { //20pts

            //0r1b
            long long fans=0;
            for(int i=0; i<(1<<n); i++) {
                long long ans=0;
                int nr=0,nb=0;
                for(int j=1; j<=n; j++) {
                    lb[j]=nb;
                    lr[j]=nr;
                    if(i&(1<<(j-1))) { //b
                        if(a[j]==a[lb[j]])ans+=a[j];
                        nb=j;
                    } else {
                        if(a[j]==a[lr[j]])ans+=a[j];
                        nr=j;
                    }
                }
                fans=max(fans,ans);
            }cout<<fans<<'\n';
        }else cout<<"IDK...\n";

    }
    return 0;
}
