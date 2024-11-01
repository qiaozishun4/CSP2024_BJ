#include<bits/stdc++.h>
using namespace std;
int t;
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    int n;
    for(int i=1;i<=t;i++){
        cin>>n;
        if(n==1) cout<<-1;
        else if(n%7==0){
            for(int j=1;j<=n/7;j++) cout<<8;
        }
        else cout<<-1;
        cout<<endl;
    }
    return 0;
}
