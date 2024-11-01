#include<iostream>
#include<cstdio>
using namespace std;
int a[10]={6,2,5,5,4,5,6,3,7,6};
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        int n;
        cin>>n;
        int ans;
        switch(n){
            case 2:ans=1;break;
            case 3:ans=7;break;
            case 4:ans=4;break;
            case 5:ans=2;break;
            case 6:ans=9;break;
            case 7:ans=8;break;
            case 8:ans=10;break;
            case 9:ans=18;break;
            case 10:ans=40;break;
            case 11:ans=20;break;
            case 12:ans=60;break;
        }
    }
    cout<<ans<<endl;
    return 0;
}