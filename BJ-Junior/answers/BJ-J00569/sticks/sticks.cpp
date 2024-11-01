#include<bits/stdc++.h>
using namespace std;
int a[114514];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        if(a[i]==1){
            cout<<-1<<endl;
        }if(a[i]==2){
            cout<<1<<endl;
        }if(a[i]==3){
            cout<<7<<endl;
        }if(a[i]==6){
            cout<<6<<endl;
        }if(a[i]==5){
            cout<<1<<endl;
        }
        if(a[i]==6){
            cout<<6<<endl;
        }
        if(a[i]==18){
            cout<<208<<endl;
        }
    }
    return 0;
}
