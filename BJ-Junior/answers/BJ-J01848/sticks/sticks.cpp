#include<bits/stdc++.h>
using namespace std;
int a[100005];
int pd_num(int num){
    if(num==1)return 2;
    if(num==2)return 5;
    if(num==3)return 5;
    if(num==4)return 4;
    if(num==5)return 5;
    if(num==6)return 6;
    if(num==7)return 3;
    if(num==8)return 7;
    if(num==9)return 6;
    if(num==0)return 6;
}
int pd_s(int num){
    int ans=0;
    while(num!=0){
        ans+=pd_num(num%10);
        num/=10;
    }
    return ans;
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    int n;
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n;
        for(int j=1;j<=10005;j++){
            if(n==1||n==0){
                a[i]=-1;
                break;
            }
            if(pd_s(j)==n){
                a[i]=j;
                break;
            }
        }
    }
    for(int i=1;i<=t;i++){
        cout<<a[i]<<endl;
    }
}