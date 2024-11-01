#include<bits/stdc++.h>
using namespace std;
int a[10]={6,2,5,5,4,5,6,3,7,6};
int ans[51];
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin>>t;
   for(int i=1;i<=t;i++){
        cin>>ans[i];
   }
   for(int i=1;i<=t;i++){
        if(ans[i]==1||ans[i]==0){
            cout<<-1<<endl;
            continue;
        }
        if(ans[i]==6){
            cout<<6<<endl;
            continue;
        }
        for(int j=1;j<=1e6;j++){
            int temp=0;
            int ans1=j;
            while(ans1){
                temp+=a[ans1%10];
                ans1/=10;
            }
            if(temp==ans[i]){
                cout<<j<<endl;
                break;
            }
        }
   }
   fclose(stdin);
   fclose(stdout);
    return 0;
}



