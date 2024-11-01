#include <bits/stdc++.h>

using namespace std;
long long sum,ans;
int k;
int num[10]={6,2,5,5,4,5,6,3,7,6};
int t[51];
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    for(int i=0;i<10;i++){
        t[i]=num[i];
    }
    for(int i=10;i<=805;i++){
        int x=i;
        sum=0;
        while(x>0){
            sum+=num[x%10];
            x/=10;
        }
        t[i]=sum;
    }
    cin>>k;
    while(k--){
        long long n;
        cin>>n;
        bool f=0;
        for(int i=1;i<=805;i++){
            if(t[i]==n){
                cout<<i<<endl;
                f=1;
                break;
            }
        }
        if(f==0){
            cout<<"-1"<<endl;
        }
    }
    return 0;
}
