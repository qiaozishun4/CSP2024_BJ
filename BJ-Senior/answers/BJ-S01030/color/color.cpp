#include <bits/stdc++.h>
using namespace std;

int t,n,a[200005],mode[200005];

int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        int ans = 0,last = 1;
        for(int i = 1;i<=n;i++){
            cin>>a[i];
            mode[i] = 0;
            int pos = 0;
            for(int j = i-1;j>=1;j--){
                if(a[j] == a[i]){
                    pos = j;
                    break;
                }
                if(mode[j] == (!last)){
                    break;
                }
            }
            if(pos == 0){
                mode[i] = !last;
                last = !last;
            }
            else{
                mode[i] = mode[pos];
                last = mode[pos];
                ans+=a[i];
            }

        }
        //for(int i = 1;i<=n;i++) cout<<mode[i]<<" ";
        //cout<<"ans:";
        cout<<ans<<endl;
    }
    return 0;
}
