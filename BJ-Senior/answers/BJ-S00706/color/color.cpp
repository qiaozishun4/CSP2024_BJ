#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n,x,ans=0;
        cin>>n;
        memset(a,0,1000005);
        for(int i=0;i<n;i++){
            cin>>x;
            a[x]++;
        }
        int tmp=1000005;
        while(a[tmp]==0) tmp--;
        tmp++;
        for(int i=0;i<tmp;i++){
            if(a[i]>1) ans+=i;
        }
        cout<<ans<<"\n";
    }
    return 0;
}
