#include <bits/stdc++.h>
using namespace std;
int t,n,a[9]={0,0,1,7,4,2,6,8};
void cout8(int n){
    for(int i = 1;i<=n;i++)
        cout << 8;
    cout <<endl;
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    for(int i = 1;i<=t;i++){
       cin>>n;
       if(n==1){
            cout <<-1<<endl;
            continue;
       }
       if(n<=7){
            cout <<a[n]<<endl;
            continue;
       }
       switch(n%7+7){
           case 7:
            cout << 8;
            break;
            case 8:
                cout << 10;
                break;
            case 9:
                cout << 18;
                break;
            case 10:
                cout << 22;
                break;
            case 11:
                cout << 20;
                break;
            case 12:
                cout << 28;
                break;
            case 13:
                cout << 68;
       }
       cout8(n/7-1);
    }
    return 0;
}
