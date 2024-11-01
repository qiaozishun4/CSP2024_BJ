#include<iostream>
using namespace std;
int ans[22]={0,-1,1,7,4,2,6,8,10,18,22,48,28,68,88,108,188,200,208,288,688,888};
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int q,a;
    cin>>q;
    for(int ii=0;ii<q;ii++){
        cin>>a;
        if(a==1){
                cout<<-1;
                continue;
        }

    if(a%7==0){
        for(int i=0;i<a/7;i++){
            cout<<8;
        }
        cout<<endl;
        continue;
    }
    if(a%7==1){
        cout<<10;
        for(int i=0;i<a/7-1;i++){
            cout<<8;
        }
        cout<<endl;
        continue;
    }
    cout<<ans[a]<<endl;
    }
    return 0;
}
