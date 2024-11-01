#include<bits/stdc++.h>
using namespace std;
int t,x[15]={6,2,5,5,4,5,6,3,7,6};
int ans[2010];
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++){
        int n,num;
        cin>>n;
        num=(n+6)/7;
        if(n==1){
            cout<<-1<<endl;
            continue;
        }

        if(n%7==0){
            for(int j=1;j<=num;j++){
                cout<<8;
            }
            cout<<endl;
            continue;

        }
        for(int j=1;j<=9;j++){
            if(n>=x[j]&&(n-x[j]+6)/7<num){
                ans[1]=j;
                n-=x[j];
                break;
            }
        }


        for(int j=2;j<=num;j++){
            int sum=n-(num-1)*6;
            for(int k=2;k<=num;k++){
                ans[k]=0;
            }
            for(int k=num;k>1;k--){
                sum-=1;
                ans[k]=8;
                if(sum==0){
                    break;
                }
            }
        }
        for(int j=1;j<=num;j++){
            cout<<ans[j];
        }
        cout<<endl;
    }
    return 0;

}

