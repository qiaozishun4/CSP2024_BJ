#include<bits/stdc++.h>
using namespace std;
int a[100000000];
int main(){
    for(int i=0;i<100000000;i++){
        int k=i,sum=0;
        do{
            switch(k%10){
                case 0:sum+=6;break;
                case 1:sum+=2;break;
                case 2:sum+=5;break;
                case 3:sum+=5;break;
                case 4:sum+=4;break;
                case 5:sum+=5;break;
                case 6:sum+=6;break;
                case 7:sum+=3;break;
                case 8:sum+=7;break;
                case 9:sum+=6;break;
            }
            k/=10;
        }while(k!=0);
        a[i]=sum;
    }
    int n;
    cin>>n;
    while(n--){
        int k;
        cin>>k;
        bool qwertyuiop=true;
        for(int i=0;i<100000000;i++){
            if(a[i]==k){
                qwertyuiop=false;
                cout<<i<<endl;;
                break;
            }
        }
        if(qwertyuiop)cout<<-1<<endl;
    }
    return 0;
}
