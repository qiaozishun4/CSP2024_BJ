#include <bits/stdc++.h>
using namespace std;
int T;
int a[10]={6,2,5,5,4,5,6,3,7,6};
int main() {
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>T;
    while(T--){
        int n,num=0,sum=0;
        cin>>n;
        if(n==1){
            cout<<"-1"<<endl;
            continue;
        }
        while(n!=0){
            for(int i=2;i<=9;i++){
                if(n%7>=a[i]){
                    num=num*10+i;
                    n-=i;
                }
                i=0;
            }
            sum=min(sum,num);
        }
        cout<<sum;
    }
    return 0;
}
