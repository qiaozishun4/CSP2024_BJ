#include<bits/stdc++.h>

using namespace std;
int main(){
    freopen("color2.in","r",stdin);
    freopen("color.out","w",stdout);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int a[1000010]={0};
        int n;
        int c=0;
        cin>>n;
        for(int j=0;j<n;j++){
            int b;
            cin>>b;
            a[b]++;
            if(b>c){
                c=b;
            }
        }
        int ans=0;
        for(int j=0;j<=c;j++){
           if(a[j]>=2){
                ans+=(a[j]-1)*j;
           }
        }
        cout<<ans<<endl;
    }

    return 0;
}
