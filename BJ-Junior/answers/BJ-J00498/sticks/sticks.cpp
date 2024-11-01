#include<bits/stdc++.h>
using namespace std;
int b[100010];
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    long long n,m;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>m;
        if(m<2) cout<<"-1"<<endl;
        if(m==2) cout<<"1"<<endl;
        if(m==3) cout<<"7"<<endl;
        if(m==4) cout<<"4"<<endl;
        if(m==5) cout<<"2"<<endl;
        if(m==6) cout<<"6"<<endl;
        if(m%7==0){
            for(int i=0;i<(m/7);i++) {
                    cout<<"8";
            }
            cout<<endl;
        }

    }
}
