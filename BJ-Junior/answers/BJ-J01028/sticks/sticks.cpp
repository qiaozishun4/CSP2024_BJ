#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int n,b[7]={1,7,4,2,6,8};
    cin>>n;
    for(int i=1;i<=n;i++){
        int a,ans=1e6;
        cin>>a;
        if(a==1){
            cout<<-1;
            return 0;
        }else if(a==2) ans=1;
        else if(a==3) ans=7;
        else if(a==4) ans=4;
        else if(a==5) ans=2;
        else if(a==6) ans=6;
        else if(a==7) ans=8;
        else{
            for(int i=2;i<a;i++){
                for(int j=2;i<a;j++){
                    if(i+j==a&&b[i]+b[j]<ans){
                        ans=b[j]+b[i];
                    }
                }
            }
        }
        cout<<ans;
    }
    return 0;
}
