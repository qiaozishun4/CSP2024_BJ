#include<bits/stdc++.h>
using namespace std;
int a[1000000]={-1,-1,1,7,4,2,0,8,10,18,22,20,28,68,88,108,188,200,208,288,688,888,1088,1888,2008,2088,2888,6888,8888,10888,18888,20088,20888,28888,68888,88888};
string s[7]={"108","188","200","208","288","688","888"};
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int n;
    cin>>n;
    for(int h=0; h<n; h++){
        int x;
        cin>>x;
        if(x<=35){
            cout<<a[x]<<"\n";
        }else{
            for(int j=0 ;j<n; j++){

                string ss=s[x%7-1];
                for(int i=0; i<x/10; i++){
                    ss+='8';
                }
                cout<<ss<<"\n";
            }

        }
    }


    return 0;
}
