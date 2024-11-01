#include<bits/stdc++.h>
using namespace std;
int n,m,a[7]={8,10,18,23,20,28,68};
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>n;
    for(int ex=0;ex<n;ex++){
        cin>>m;
        if(m==1)
        cout<<"-1"<<endl;
        else if(m==2)
        cout<<"2"<<endl;
        else if(m==3)
        cout<<"7"<<endl;
        else if(m==4)
        cout<<"4"<<endl;
        else if(m==5)
        cout<<"2"<<endl;
        else if(m==6)
        cout<<"6"<<endl;
        else{
            cout<<a[m%7];
            for(int i=0;i<(m-m%7-7)/7;i++)
            cout<<"8";
            cout<<endl;
        }
    }
    return 0;
}