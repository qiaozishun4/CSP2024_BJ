#include<bits/stdc++.h>
using namespace std;
int s[10]={6,2,5,5,4,5,6,3,7,6};
int n,t;
int main(){
    cin>>t;
    while(t--){
        cin>>n;
        if(n%7==0){
            for(int i=1;i<=n/7;i++){
                cout<<8;
            }
        continue;
        }
        else if(n%7==1){
            cout<<10;
            for(int i=1;i<=(n-8)/7;i++){
                cout<<8;

            }
            cout<<endl;
            continue;
        }else{
            for(int i=1;i<10000000;i++){
                int j=i,x,sum;
                while(j!=0){
                    sum+=s[j%10];
                    j/=10;
                }
                if(sum==n){
                    cout<<i;
                    continue;
                }
            }
        }
    }
    return 0;
}