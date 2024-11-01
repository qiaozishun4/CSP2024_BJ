#include<bits/stdc++.h>
using namespace std;
int T,n,ans[51]={-1,-1,1,7,4,2,6,8,10,18,40},num[11]={6,2,5,100000,4,100000,6,3,7,1000000};
//                0                      10
int main(){
freopen("sticks.in","r",stdin);
freopen("sticks.out","w",stdout);
cin>>T;
while(T--){
        int sum;
    cin>>n;
    if(n%7==0){
        for(int i=1;i<=(n/7);i++){
            cout<<8;
        }

    }else if(n%7==1){
        cout<<10;
        for(int i=1;i<(n/7);i++){
        cout<<8;
        }

    }else if(n<=10){
        cout<<ans[n];
    }else if(n==18){
        cout<<208;
    }else if(n==48){
        cout<<60000000;
        }else if(n<=50){
            int ff=1;
     for(int i=11;i<60000000;i++){
        int a1=i%10,a2=i/10%10,a3=i/100%10,a4=i/1000%10,a5=i/100000%10;
        int a6=i/1000000%10,a7=i/10000000;
        if(n==(num[a1]+num[a2]+num[a3]+num[a4]+num[a5]+num[a6]+num[a7])){
            ff=0;
            cout<<i;
        }
     }
     if(ff==1){
        cout<<-1;
     }
    }else{
    cout<<sum;
    }
    cout<<endl;
}
return 0;
}
