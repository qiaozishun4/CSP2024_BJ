#include<iostream>
#include<cstdio>
using namespace std;
int stat[10]={88,10,18,22,20,28,68};
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(n<=7){
            int ans;
            switch(n){
                case 1:ans=-1;break;
                case 2:ans=1;break;
                case 3:ans=7;break;
                case 4:ans=4;break;
                case 5:ans=2;break;
                case 6:ans=6;break;
                default:ans=8;break;
            }
            cout<<ans<<'\n';
            continue;
        }
        int dig=n/7,p=n%7;
        if(dig*7!=n) dig++;
        else{
            for(int i=0;i<dig;i++) cout<<8;
            cout<<'\n';
            continue;
        }
        if(stat[p]==22&&dig!=2){
            cout<<200;
            dig--;
        }
        else{
            cout<<stat[p];
        }
        for(int i=0;i<dig-2;i++){
            cout<<8;
        }
        cout<<'\n';
    }
    return 0;
}
