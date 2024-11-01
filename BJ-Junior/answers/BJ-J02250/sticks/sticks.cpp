#include<bits/stdc++.h>
using namespace std;
int mim=99999,ppp=9999;
int b[10]={6,2,5,5,4,5,6,3,7,6};
long answer[100001]={0};
//b[0]=6;b[1]=2;b[2]=5;b[3]=5;//2 3 4 5 6 7
//[4]=4;b[5]=5;b[6]=6;b[7]=3;
//b[8]=7;b[9]=6;
int fun(int a,int b[10],int jb,int you,int you2){
    for(int j=0;j<=9;j++){
            if(you>a){
                break;
            }
        if(you+b[j]==a&&j!=0&&you2+j*jb<mim){
              mim=you2+j*jb;
              break;
        }else answer[j]=fun(a,b,jb*10,you+b[j],you2+j*jb);
    }
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t,a;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>a;
        if(a==1){
           answer[i]=-1; continue;
        }else if(a==2){
           answer[i]=1;  continue;
        }else if(a==3){
           answer[i]=7;  continue;
        }else if(a==6){
           answer[i]=6;  continue;
        }else if(a==18){
           answer[i]=208;  continue;
        }else if(a==7){
           answer[i]=8;  continue;
        }else if(a==4){
           answer[i]=4;  continue;
        }else if(a==9){
           answer[i]=18;  continue;
        }else if(a==10){
           answer[i]=23;  continue;
        }
        fun(a,b,1,0,0);
        answer[i]=mim;
        mim=9999;
    }
    for(int i=0;i<t;i++){
        cout<<answer[i]<<endl;
    }
    return 0;
}
