#include<bits/stdc++.h>
using namespace std;
int n,a[7] = {0,27,1,22,20,2,6},b[7] = {-1,-1,1,7,4,2,6};
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        if(n<7){
            cout<<b[n];
        }else{
            int m = n%7;
            if(m == 0){
                for(int i = 0;i<n/7;i++){
                    cout<<8;
                }
            }else if(m == 1||m == 3||m == 4){
                n-=7;
                cout<<a[m];
                for(int i = 0;i<n/7;i++){
                    cout<<8;
                }
            }else{
                cout<<a[m];
                for(int i = 0;i<n/7;i++){
                    cout<<8;
                }
            }
        }
        cout<<'\n';
    }
    return 0;
}
