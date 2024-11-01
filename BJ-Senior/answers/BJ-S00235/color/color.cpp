#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int T;
    cin>>T;
    for(int tt=1;tt<=T;tt++){
        int n,x;
        long long ans=0;
        int a[1000005]={0};
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>x;
            a[x]++;
            if(a[x]==2){
                a[x]-=2;
                ans+=x;
            }
        }
        cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
}
