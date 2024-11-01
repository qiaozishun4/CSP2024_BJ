#include<bits/stdc++.h>
using namespace std;
int b[22]={0,-1,1,7,4,2,6,8,10,19,22,20,28,68,88,108,188,200,208,288,688,888};
int main(){
    freopen("stick.in","r",stdin);
    freopen("stick.out","w",stdout);
    int n,t[50];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>t[i];
    }
    for(int i=0;i<n;i++){
        if(t[i]<=21){
            cout<<b[t[i]];
        }else{
            int x=t[i]%7;
            int y=t[i]/7;
            if(x==1){
                cout<<108;
            }else if(x==2){
                cout<<188;
            }else if(x==3){
                cout<<200;
            }else if(x==4){
                cout<<208;
            }else if(x==5){
                cout<<288;
            }else if(x==6){
                cout<<688;
            }else{
                cout<<888;
            }
            if(x){
                for(int j=0;j<y-2;j++){
                    cout<<8;
                }
            }else{
                for(int j=0;j<y-3;j++){
                    cout<<8;
                }
            }
        }
        cout<<endl;
    }
    fclose(stdin);
    fclose(stdout);
}