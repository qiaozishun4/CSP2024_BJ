#include<bits/stdc++.h>//1 7 4 2 0 8
using namespace std;//   2 3 4 5 6 7
int t,x,y,a[100005],c[12]={6,2,5,5,4,5,6,3,7,6};
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>x;
        if(x%7==0){
            y=x/7;
            for(int i=1;i<=y;i++)
                cout<<8;
            cout<<endl;
        }
        else if(x%7==1){
            cout<<12;
            y=x/7-1;
            for(int i=1;i<=y;i++)
                cout<<8;
            cout<<endl;
        }
    }
    return 0;
}
