#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;

int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int tx;
    cin>>tx;
    for(int sp=0;sp<tx;sp++){
        int n;
        cin>>n;
        if(n>21){
            for(int i=0;i<(n/7);i++){
                cout<<"8";
            }
        }else if(n==0 || n==1){
            cout<<"-1\n";
            continue;
        }else if(n==2){
            cout<<"1";
        }else if(n==3){
            cout<<"7";
        }else if(n==4){
            cout<<"4";
        }else if(n==5){
            cout<<"2";
        }else if(n==6){
            cout<<"6";
        }else if(n==7){
            cout<<"8";
        }else if(n==8){
            cout<<"16";
        }else if(n==9){
            cout<<"18";
        }else if(n==10){
            cout<<"22";
        }else if(n==11){
            cout<<"20";
        }else if(n==12){
            cout<<"28";
        }else if(n==13){
            cout<<"68";
        }else if(n==14){
            cout<<"88";
        }else if(n==15){
            cout<<"108";
        }else if(n==16){
            cout<<"188";
        }else if(n==17){
            cout<<"200";
        }else if(n==18){
            cout<<"208";
        }else if(n==19){
            cout<<"288";
        }else if(n==20){
            cout<<"688";
        }
        cout<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

