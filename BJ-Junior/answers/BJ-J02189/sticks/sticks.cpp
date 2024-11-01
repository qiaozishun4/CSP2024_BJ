#include<bits/stdc++.h>
using namespace std;
int a[10]={6,2,5,5,4,5,6,3,7,6};
int main(){
    freopen("stick.in","r",stdin);
    freopen("stick.out","w",stdout);
    int n;
    cin>>n;
    if(n==1){
        cout<<-1
    }
    for(int i=1;i<=2E9;i++){
        int cnt=0,k=i;
        while(k!=0){
            cnt+=a[k%10];
            k/=10;
        }
        if(cnt==n){
            cout<<i;
            return 0;
        }
    }
}
