#include<iostream>
using namespace std;
const int a[]={6,2,5,5,4,5,6,3,7,6};
int n;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        scanf("%d",&n);
        if(n%7==0){
            for(int i=1;i<=n/7;i++) cout<<8;
            cout<<endl;
            continue;
        }else if(n%7==1){
            cout<<10;
            for(int i=1;i<=n/7-1;i++) cout<<8;
            cout<<endl;
            continue;
        }else if(n<2){
            cout<<-1<<endl;
            continue;
        }
    }
    return 0;
}

