#include <bits/stdc++.h>
using namespace std;
int t,n;
int ans[20]={0,-1,1,7,4,2,6,8,10,18,40,20,28,68,88,108,188,408,208,288};
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        if(n<=19){
            cout<<ans[n]<<endl;
            continue;
        }
        int k=n/7,s=n%7;
        if(s==1){
            k--;
            cout<<"10";
        }
        if(s==2){
            cout<<"1";
        }
        if(s==3){
            k--;
            cout<<"40";
        }
        if(s==4){
            k--;
            cout<<"20";
        }
        if(s==5){
            cout<<"2";
        }
        if(s==6){
            cout<<"6";
        }
        for(int i=0;i<k;i++){
            cout<<"8";
        }
        cout<<endl;
    }
    return 0;
}