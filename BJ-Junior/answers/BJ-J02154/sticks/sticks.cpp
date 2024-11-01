#include<bits/stdc++.h>
using namespace std;
int us[10]={6,2,5,5,4,5,6,3,7,6};
int main(){
    int t;
    cin>>t;
    int n;
    while (t--){
        cin>>n;
        if (n%7==0){
            while (n){
                n-=7;
                cout<<8;
            }
            continue;
        }
        if (n==1){
            cout<<-1;
            continue;
        }
        if (n%7==1){
            cout<<10;
            while(n!=8){
                n-=7;
                cout<<8;
            }
            continue;
        }
        for (int i=1;;i++){
            int x=i,cnt=0;
            while (x){
                cnt+=us[x%10];
                x/=10;
            }
            if (cnt==n){
                cout<<i<<endl;
                is=1;
                break;
            }
        }
        if (!is)cout<<-1<<endl;
    }
    return 0;
}