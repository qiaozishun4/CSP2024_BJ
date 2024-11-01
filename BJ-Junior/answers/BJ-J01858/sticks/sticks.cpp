
#include<bits/stdc++.h>
using namespace std;
int k,n;
int main()
{
 freopen("sticks.in","r",stdin);
  freopen("sticks.in","w",stdout);
    cin>>k;
    while(k--){

        cin>>n;
        if(n%7==1){
            cout<<100;
            n=n/7;
        }
        else{
            n=n/7+2;
        }


        for(int i=1;i<=n-2;i++){
            cout<<8;
        }
        cout<<'\n';

    }
    return 0;
}
