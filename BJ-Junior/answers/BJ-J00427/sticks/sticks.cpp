#include<iostream>
using namespace std;
int t,arr[20]={0,-1,1,7,4,2,6,8,10,18,22,20};
double n;
void cout8(int num){
    for(int i=1;i<=num;i++){
        cout<<8;
    }
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        if(n>=12){
            switch(int(n)%7){
                case 0:cout8(n/7);break;
                case 1:cout<<10;cout8(n/7-1);break;
                case 2:cout<<1;cout8(n/7);break;
                case 3:cout<<22;cout8(n/7-1);break;
                case 4:cout<<20;cout8(n/7-1);break;
                case 5:cout<<2;cout8(n/7);break;
                case 6:cout<<6;cout8(n/7);break;
            }
        }else cout<<arr[int(n)];
        cout<<endl;
    }
    return 0;
}
