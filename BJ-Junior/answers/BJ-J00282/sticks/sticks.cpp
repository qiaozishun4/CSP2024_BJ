#include<bits/stdc++.h>
using namespace std;
int s,n,T,p,aa[10]={6,2,5,5,4,5,6,3,7,6},bb[21]={0};
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    for(int i=0;i<21;i++){
        p=i;
        while(p){
            bb[i]+=aa[p%10];
            p/=10;
        }
    }
    cin>>T;
    for(int i=0;i<T;i++){
        s=0;
        cin>>n;
        if(n<2){
            cout<<"-1";
        }else{
            if(n%7==0){
                for(int i=0;i<n/7;i++){
                    cout<<8;
                }
                cout<<"\n";
            }else if(n<21){
                for(int j=0;j<21;j++){
                    if(bb[j]==n){
                        cout<<j<<"\n;
                        break;
                    }
                }
            }else{
                cout<<"Damn!"；
            }
        }
    }
    return 0;
}
