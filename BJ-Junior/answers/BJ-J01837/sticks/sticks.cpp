#include<bits/stdc++.h>
using namespace std;
int t,n,shuzi[10]={6,2,5,5,4,5,6,3,7,6};
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n;
        int sum;
        sum=1;
        bool f=true;
        while(sum<=1e7){
            int kkk=0;
            int temp=sum;
            while(temp!=0){
                kkk+=shuzi[temp%10];
                temp/=10;
            }
            if(kkk==n){
                f=false;
                cout<<sum<<endl;
                break;
            }
            sum++;
        }
        if(f==true){
            cout<<"-1"<<endl;
        }
    }
    return 0;
}
