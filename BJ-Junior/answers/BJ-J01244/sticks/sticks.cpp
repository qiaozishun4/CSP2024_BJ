#include<bits/stdc++.h>
using namespace std;
int stick[]={6,2,5,5,4,5,6,3,7,6};
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(n<2){
            cout<<-1;
            continue;
        }
        int b=n/7;
        for(int i=pow(10,b);i<pow(10,b+1);i++){
            int n1=i,sum=0;
            while(n1){
                sum+=stick[n1%10];
                n1/=10;
            }
            if(sum==n){
                cout<<i<<endl;
                break;
            }
        }
    }
    return 0;
}
