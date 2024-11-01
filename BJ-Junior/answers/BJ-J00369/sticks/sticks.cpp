#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int p;
    cin>>p;
    for(int i=1;i<=p;i++){
        int n,ans=0,j=0;
        cin>>n;
        if(n%7==0){
            while (n!=0){
                ans++;
                n-=7;
            }
            while (ans--){
                cout<<8;
            }
            cout<<endl;
        }
        else if(n%7==1){
            n-=1;
            while (n!=7){
                ans++;
                n-=7;
            }
            cout<<10;
            while (ans--){
                cout<<8;
            }
            cout<<endl;
        }
        else cout<<-1<<endl;
    }
    return 0;
}

