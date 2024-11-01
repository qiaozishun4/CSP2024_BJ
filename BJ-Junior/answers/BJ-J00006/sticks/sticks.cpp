#include<iostream>
#include<cstdio>
using namespace std;
int t,n[51];
int num[10]={6,2,5,5,4,5,6,3,7,6};
int maximum(){
    int x=-1;
    for(int i=0;i<t;i++)x=max(x,n[i]);
    return x;
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdin);
    cin>>t;
    for(int i=0;i<t;i++)cin>>n[i];
    for(int i=0;i<t;i++){
        if(n[i]%7==0){
            for(int i=0;i<n[i]/7;i++)cout<<8;
            cout<<endl;
        }else if(n[i]%7==1){cout<<"10";
            for(int i=0;i<n[i]/7-1;i++)cout<<8;
            cout<<endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}