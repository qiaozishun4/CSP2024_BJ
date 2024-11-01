#include<iostream>
#include<cmath>
using namespace std;
int main(){
    freopen("sticks1.in","r",stdin);
    freopen("sticks1.out","w",stdout);
    int t,n,j,a,b;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n;
        b=0;
        if(n<2){
            cout<<-1<<endl;
        }
        else{
            j=1;
            while(1){
                for(int k=6;k>0;i++){
                    a=j/int(pow(10,k));
                    j%=int(pow(10,k));
                    if(a==0&&a==9&&a==6){
                        b+=6;
                    }
                    else if(a==1){
                        b+=2;
                    }
                    else if(a==4){
                        b+=4;
                    }
                    else if(a==7){
                        b+=3;
                    }
                    else if(a==8){
                        b+=7;
                    }
                    else{
                        b+=5;
                    }
                }
                if(b==n){
                    break;
                }
                j++;
            }
        }
        cout<<j;
    }
    return 0;
}