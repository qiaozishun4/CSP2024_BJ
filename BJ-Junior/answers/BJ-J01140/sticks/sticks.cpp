#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(n<7)
            switch(n){
                case 1:
                    cout<<-1<<endl;
                    break;
                case 2:
                    cout<<1<<endl;
                    break;
                case 3:
                    cout<<7<<endl;
                    break;
                case 4:
                    cout<<4<<endl;
                    break;
                case 5:
                    cout<<2<<endl;
                    break;
                case 6:
                    cout<<0<<endl;
                    break;
            }
        else
            switch(n%7){
                case 1:
                    cout<<10;
                    n-=7;
                    while(n>0){
                        cout<<8;
                        n-=7;
                    }
                    cout<<endl;
                    break;
                case 2:
                    cout<<1;
                    n-=1;
                    while(n>0){
                        cout<<8;
                        n-=7;
                    }
                    cout<<endl;
                    break;
                case 3:
                    cout<<22;
                    n-=9;
                    while(n>0){
                        cout<<8;
                        n-=7;
                    }
                    cout<<endl;
                    break;
                case 4:
                    cout<<20;
                    n-=10;
                    while(n>0){
                        cout<<8;
                        n-=7;
                    }
                    cout<<endl;
                    break;
                case 5:
                    cout<<2;
                    n-=5;
                    while(n>0){
                        cout<<8;
                        n-=7;
                    }
                    cout<<endl;
                    break;
                case 6:
                    cout<<80;
                    n-=12;
                    while(n>0){
                        cout<<8;
                        n-=7;
                    }
                    cout<<endl;
                    break;
                default:
                    while(n>0){
                        cout<<8;
                        n-=7;
                    }
                    cout<<endl;
                    break;
            }
    }
    return 0;
}
