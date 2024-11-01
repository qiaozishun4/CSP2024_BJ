#include<bits/stdc++.h>
using namespace std;
int a[10]={6,2,5,5,4,5,6,3,7,6};
int s(int n){
    int sa=0;
    for(;n;n/=10){
        sa+=a[n%10];
    }return sa;
}
void f(int n){
    if(n<30){
        int i;
        for(i=1;;i++){
            if(s(i)==n){cout<<i;return;}
        }
    }f(n-7);
    cout<<8;
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t,i,n;
    cin>>t;
    for(i=0;i<t;i++){
        cin>>n;
        if(n<=1){
            cout<<-1;

        }else f(n);
        cout<<endl;
    }
}
