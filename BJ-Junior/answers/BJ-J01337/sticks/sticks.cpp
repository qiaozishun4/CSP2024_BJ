#include <bits/stdc++.h>
using namespace std;
//long long d[10]={0,0,1,7,4,2,0,8};
/*
string dfs(long long s,long long f){

}
*/
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n,t;
    cin>>t;
    while(t--){
        cin>>n;
        if(n%7==0){
            for(int i=1;i<=n/7;i++){
                cout<<8;
            }
        }else if((n-1)%7==0){
            n/=7;
            if(n>=5){
                cout<<600000;
                n-=5;
            }else{
                cout<<44;
                n-=1;
            }
            for(int i=1;i<=n;i++){
                cout<<8;
            }
        }
        cout<<endl;
        /*
        for(int i=2;i<=n;i++){
            if(n>=)
        }
        if(n<2){
            cout<<-1<<endl;
        }else{
            long long sum3,sum2,sum[10]={};
            sum3=n/3;
            if(n-sum3*3==0){
                sum2=0;
            }else if(n-sum3*3==1){
                sum3--;
                sum2=2;
            }else{
                sum2=1;
            }
            if(sum2==0){
                sum[6]=sum3/2;
                sum[3]=sum3%2;
            }else if(sum2==1){
                if(sum3==0){
                    sum[2]=1;
                }else if(sum3%2){
                    sum[2]=1;
                    sum[6]=sum3/2;
                }else{
                    sum[5]=1;
                    sum[6]=sum3/2;
                }
            }else{
                if(sum3==0){
                    sum[4]=1;
                }else if(sum3%2){
                    sum[5]=2;
                    sum[6]=sum3/2-1;
                }else{
                    sum[7]=1;
                    sum[6]=sum3/2;
                }
            }
            for(int i=2;i<=7;i++){
                cout<<sum[i]<<" ";
            }
            cout<<"=-=-";
            //first
            if(sum[2]){
                cout<<1;
                sum[2]--;
            }else if(sum[5]){
                cout<<2;
                sum[5]--;
            }else if(sum[4]){
                cout<<4;
                sum[4]--;
            }else if(sum[6]){
                cout<<6;
                sum[6]--;
            }else if(sum[3]){
                cout<<7;
                sum[3]--;
            }else if(sum[7]){
                cout<<8;
                sum[7]--;
            }
            //back
            while(1){
                if(sum[2]){
                    cout<<1;
                    sum[2]--;
                }else if(sum[5]){
                    cout<<2;
                    sum[5]--;
                }else if(sum[4]){
                    cout<<4;
                    sum[4]--;
                }else if(sum[6]){
                    cout<<6;
                    sum[6]--;
                }else if(sum[3]){
                    cout<<7;
                    sum[3]--;
                }else if(sum[7]){
                    cout<<8;
                    sum[7]--;
                }else{
                    cout<<endl;
                    break;
                }
            }
        }
        */
    }
}

