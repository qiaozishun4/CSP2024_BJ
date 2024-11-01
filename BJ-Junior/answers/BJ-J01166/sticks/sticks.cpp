#include<bits/stdc++.h>
using namespace std;
int ans[20]={0,-1,1,7,4,2,6,8,10,18,20,28,68};
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    ios::sync_with_stdio(0);
    int T;cin>>T;
    while(T--){
        int n;cin>>n;
        if(n<14)cout<<ans[n];
        else{
            if(n%7==0){

            }else if(n%7==1){
                cout<<"10";
                n-=8;
            }else if(n%7==2){
                cout<<"1";
                n-=2;
            }else if(n%7==3){
                cout<<"23";n-=10;
            }else if(n%7==4){
                cout<<"20";n-=11;
            }else if(n%7==5){
                cout<<"2";n-=5;

            }else{
                cout<<"6";n-=6;
            }
            for(int i=1;i<=n/7;i++)cout<<"8";
        }
        cout<<endl;
    }
    return 0;
}
