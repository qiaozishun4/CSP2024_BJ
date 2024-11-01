#include<bits/stdc++.h>
using namespace std;
int number[11]={6,2,5,5,4,5,6,3,7,6};
int a[100000];
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int _;
    cin>>_;
    while(_--){
        int n;
        cin>>n;
        if(n%2!=0&&n%3!=0&&n%5!=0&&n%7!=0){
            cout<<-1<<endl;
            continue;
        }else if(n%7==0){
            for(int i=1;i<=n/7;i++){
                cout<<8;
            }
            cout<<endl;
        }else if(n%2==0){
            for(int i=1;i<=n/2;i++){
                cout<<1;
            }
            cout<<endl;
        }else if(n%3==0){
            for(int i=1;i<=n/3;i++){
                cout<<3;
            }
            cout<<endl;
        }else if(n%6==0){
            cout<<6;
            for(int i=2;i<=n/6;i++){
                cout<<6;
            }
            cout<<endl;
        }else if(n%5==0){
            for(int i=0;i<n/5;i++){
                cout<<2;
            }
            cout<<endl;
        }
    }
    return 0;
}
