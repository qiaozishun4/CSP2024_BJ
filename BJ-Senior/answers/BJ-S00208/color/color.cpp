#include <bits/stdc++.h>
#include <cstdio>
int a[200005];
using namespace std;
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int t;
    cin >> t;
    while(t--){
        int n;
        long long ans=-0x3f3f3f3f;
        cin >> n;
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        for(unsigned long long i=0;i<pow(2,n);i++){
            bool ok[200005]={0};
            int t=i;
            long long cnt=0;
            int j=0;
            while(t>0){
                if(t%2==1) ok[j]=1;
                t/=2;
                j++;
            }
            /*for(int k=n-1;k>=0;k--){
                cout << ok[k] << " ";
            }
            cout << endl;*/
            for(int k=1;k<n;k++){
                int k1=k-1;
                while(k1>=0){
                    if(ok[k1]==ok[k]&&a[k1]==a[k]){
                        cnt+=a[k];
                        break;
                    }
                    k1--;
                }
            }
            ans=max(ans,cnt);
        }
        cout << ans << endl;
    }
    return 0;
}