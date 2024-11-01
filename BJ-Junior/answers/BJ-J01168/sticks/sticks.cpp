#include<bits/stdc++.h>
using namespace std;
void print(int a){
    int n=a%7;
    switch(n){
        case 0:cout<<88;break;
        case 1:cout<<108;break;
        case 2:cout<<188;break;
        case 3:cout<<200;break;
        case 4:cout<<208;break;
        case 5:cout<<288;break;
        case 6:cout<<688;break;
    }
    for(int i=1;i<=a/7;i++)cout<<8;
    cout<<endl;
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int a;
        cin>>a;
        switch(a){
            case 1:cout<<-1<<endl;break;
            case 2:cout<<1<<endl;break;
            case 3:cout<<7<<endl;break;
            case 4:cout<<4<<endl;break;
            case 5:cout<<2<<endl;break;
            case 6:cout<<6<<endl;break;
            case 7:cout<<8<<endl;break;
            case 8:cout<<10<<endl;break;
            case 9:cout<<18<<endl;break;
            case 10:cout<<22<<endl;break;
            case 11:cout<<20<<endl;break;
            case 12:cout<<28<<endl;break;
            case 13:cout<<68<<endl;break;
            case 14:cout<<88<<endl;break;
            default:print(a-14);
        }
    }
    return 0;
}
