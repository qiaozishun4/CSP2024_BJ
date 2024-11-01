#include<bits/stdc++.h>
using namespace std;
int a[25]={0,-1,1,7,4,2,6,8,16,18,23,20,28,80,88,108,188,206,208,288,688};
int sticksSum[15]={6,2,5,5,4,5,6,3,7,6};
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(n==1){
            cout<<-1<<endl;
            continue;
        }
        if(n<=20){
           cout<<a[n]<<endl;
        }else{
            for(int i=1;i<=1000005;i++){
                int sum=0,x=i;
                while(x){
                    sum+=sticksSum[x%10];
                    x/=10;
                }
                if(sum==n){
                    cout<<i<<endl;
                    break;
                }
            }
            cout<<-1<<endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}