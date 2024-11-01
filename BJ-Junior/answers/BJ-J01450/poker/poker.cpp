#include<iostream>
using namespace std;
int  main(){
        freopen("poker.in","r",stdin);
        freopen("poker.out","w",stdout);
        int  n;
        cin>>n;
        int  cnt=52;
        for(int  i=1;i<=n;i++){
               cin>>a[i];
        }
        for(int i=1;i<=n;i++){
               for(int j=1;j<i;j++){
                      if(a[i]==a[j]){
                            cnt--;
                      }
               }
        }
        cout<<cnt;
        return 0;
}