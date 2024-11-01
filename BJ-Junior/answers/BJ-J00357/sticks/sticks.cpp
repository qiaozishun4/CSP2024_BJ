#include<bits/stdc++.h>
using namespace std;
int a[55]={-1,1,7,4,2,6,8,10,18,22,20,28,80,88,108,188,200,208,288,808,888,1088,1888,2008,2088,2888,8088,8888,10888,18888,20088,20888,28888,80888,88888,108888,188888,200888,208888,288888,808888,888888,1088888,1888888,2008888,2088888,2888888,8088888,8888888,10888888};
int t,n,ans;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        if(n<=50){
            printf("%d\n",a[n-1]);
        }else if(n%7==0){
            for(int i=0;i<(n/7);i++){
                cout<<8;
            }
            cout<<endl;
        }

    }
    return 0;
}
