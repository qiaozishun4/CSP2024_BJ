#include<bits/stdc++.h>
using namespace std;
int n[8]={-1,-1,1,7,4,2,0,8};
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int a;
        cin>>a;
        if(a==6){
            cout<<6<<endl;
            continue;
        }
        if(a<=7){
            cout<<n[a]<<endl;
            continue;
        }
        int b=a%7;
        if(b==1){
            cout<<10;
            a-=7;
        }else if(b==3){
            cout<<22;
            a-=7;
        }else if(b==4){
            cout<<20;
            a-=7;
        }else {
            cout<<n[b];
        }
        for(int i=0;i<(a-b)/7;i++){
            cout<<8;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
