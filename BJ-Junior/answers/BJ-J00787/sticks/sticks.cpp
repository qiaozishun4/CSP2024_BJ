#include<iostream>
#include<stdio.h>
using namespace std;
int n[10001],nk[100001];
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n[i];
        nk[i]=n[i];
        if(n[i]%7==0){
            int f=n[i]/7;
            while(f>0){
                cout<<"8";
                f--;
            }
        }
        cout<<endl;
    }
return 0;}