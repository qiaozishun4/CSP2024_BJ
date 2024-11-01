#include<iostream>
using namespace std;
#include<stdio.h>
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t,n;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n;
        if(n<2){
            cout<<-1<<endl;
            continue;
        }
        if(n%7==0){//Special A
            for(int j=0;j<n/7;j++)cout<<8;
            cout<<endl;
            continue;
        }
        if(n%7==1){//Special B
            cout<<10;
            for(int j=0;j<n/7-1;j++)cout<<8;
            continue;
        }
        switch(n){
            case 2:cout<<1<<endl;break;
            case 3:cout<<7<<endl;break;
            case 4:cout<<4<<endl;break;
            case 5:cout<<2<<endl;break;
            case 6:cout<<6<<endl;break;
            //case 7:cout<<8<<endl;break;
            //case 8:cout<<10<<endl;break;
            case 9:cout<<18<<endl;break;
            case 10:cout<<22<<endl;break;
            case 11:cout<<20<<endl;break;
            case 12:cout<<28<<endl;break;
            case 13:cout<<80<<endl;break;
            //case 14:cout<<88<<endl;break;
            //case 15:cout<<108<<endl;break;
            case 16:cout<<188<<endl;break;
            case 17:cout<<200<<endl;break;
            case 18:cout<<208<<endl;break;
            case 19:cout<<288<<endl;break;
            case 20:cout<<688<<endl;break;
            case 23:cout<<1888<<endl;break;
            case 24:cout<< 2008 <<endl;break;
            case 25:cout<<2088<<endl;break;
            case 26:cout<<2888<<endl;break;
            case 27:cout<<6888<<endl;break;
            case 30:cout<<18888<<endl;break;
            case 31:cout<<20088<<endl;break;
            case 32:cout<<20888<<endl;break;
            case 33:cout<<28888<<endl;break;
            case 34:cout<<48888<<endl;break;
            case 37:cout<<248888<<endl;break;
            case 38:cout<<228888<<endl;break;
            case 39:cout<<208888<<endl;break;
            case 40:cout<<288888<<endl;break;
            case 41:cout<<688888<<endl;break;
            case 44:cout<<1888888<<endl;break;
            case 45:cout<<2288888<<endl;break;
            case 46:cout<<2088888<<endl;break;
            case 49:cout<<18888888<<endl;break;
            case 50:cout<<20888888<<endl;break;
            default:cout<<-1;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
