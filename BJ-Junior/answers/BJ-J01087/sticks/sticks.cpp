#include<bits/stdc++.h>
using namespace std;
int s[10]={6,2,5,5,4,5,6,3,7,6};
int T,n,ans=-1;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>T;
    while(T--){

        cin>>n;
        if(n<2){
            cout<<ans;
            cout<<endl;
            continue;
        }


        ans=0;


        if(n<=21&&n>=2){
            if(n==2){
                cout<<1;
            cout<<endl;
            continue;
            }
            else if(n==3){
                cout<<7;
            cout<<endl;
            continue;
            }
            else if(n==4){
                cout<<4;
            cout<<endl;
            continue;
            }
            else if(n==5){
                cout<<2;
            cout<<endl;
            continue;
            }
            else if(n==6){
                cout<<6;
            cout<<endl;
            continue;
            }
            else if(n==7){
                cout<<8;
            cout<<endl;
            continue;
            }
            else if(n==8){
                cout<<10;
            cout<<endl;
            continue;
            }
            else if(n==9){
                cout<<18;
            cout<<endl;
            continue;
            }
            else if(n==10){
                cout<<23;
            cout<<endl;
            continue;
            }
            else if(n==11){
                cout<<20;
            cout<<endl;
            continue;
            }
            else if(n==12){
                cout<<28;
            cout<<endl;
            continue;
            }
            else if(n==13){
                cout<<68;
            cout<<endl;
            continue;
            }
            else if(n==14){
                cout<<88;
            cout<<endl;
            continue;
            }
            else if(n==15){
                cout<<108;
            cout<<endl;
            continue;
            }
            else if(n==16){
                cout<<188;
            cout<<endl;
            continue;
            }
            else if(n==17){
                cout<<238;
            cout<<endl;
            continue;
            }
            else if(n==18){
                cout<<208;
            cout<<endl;
            continue;
            }
            else if(n==19){
                cout<<288;
            cout<<endl;
            continue;
            }
            else if(n==20){
                cout<<688;
            cout<<endl;
            continue;
            }
            else{
                cout<<888;
            cout<<endl;
            continue;
            }
        }


        if(n%7==0){
            for(int i=1;i<=n/7;i++){
                cout<<8;
            }
            cout<<endl;
            continue;
        }


        if(n%7==1){
            cout<<10;
            for(int i=1;i<n/7;i++){
                cout<<8;
            }
            cout<<endl;
            continue;
        }


        else if(n%7==2){
            cout<<1;
            for(int i=1;i<=n/7;i++){
               cout<<8;
            }
            cout<<endl;
            continue;
        }


        else if(n%7==3){
            cout<<23;
            for(int i=1;i<n/7;i++){
                cout<<8;
            }
            cout<<endl;
            continue;
        }


        else if(n%7==4){
            cout<<20;
            for(int i=1;i<n/7;i++){
                cout<<8;
            }
            cout<<endl;
            continue;
        }


        else if(n%7==5){
            cout<<2;
            for(int i=1;i<=n/7;i++){
                cout<<8;
            }
            cout<<endl;
            continue;
        }


        else if(n%7==6){
            cout<<6;
            for(int i;i<=n/7;i++){
                cout<<8;
            }
            cout<<endl;
            continue;
        }
    }


    fclose(stdin);
    fclose(stdout);
    return 0;
}
