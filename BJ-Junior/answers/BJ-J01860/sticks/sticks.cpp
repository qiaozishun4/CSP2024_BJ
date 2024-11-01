#include<bits/stdc++.h>
using namespace std;
int s1[15]={6,2,5,5,4,5,6,3,7,6};
int s[15][15]={{0,6},{1,2},{2,5},{3,5},{4,4},{5,5},{6,6},{7,3},{8,7},{9,6}};
//int s[15][15]={{6,0},{2,1},{3,7},{4,4},{5,2},{5,3},{5,5},{6,6},{7,8},{6,9}};
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T;
    cin >> T;
    for(int i=1;i<=T;i++){
        int n;
        cin >> n;
        int wei = ceil(n/7);
        int yi = n%7;
        if(n<2)cout << -1<<endl;
        else if(n==2)cout << 1<<endl;
        else if(n==3)cout << 7<<endl;
        else if(n==4)cout << 4<<endl;
        else if(n==5)cout << 2<<endl;
        else if(n==6)cout << 6<<endl;
        else if(n==7)cout << 8<<endl;
        else if(n==8)cout << 10<<endl;
        else if(n==9)cout << 18<<endl;
        else if(n==10)cout << 22<<endl;
        else if(n==11)cout << 20<<endl;
        else if(n==12)cout << 28<<endl;
        else if(n==13)cout << 68<<endl;
        else if(n==14)cout << 88<<endl;
        else if(n==15)cout << 108<<endl;
        else if(n==16)cout << 188<<endl;
        else if(n==17)cout << 228<<endl;
        else if(n==18)cout << 208<<endl;
        else if(n==19)cout << 288<<endl;
        else if(n==20)cout << 688<<endl;
        else if(n%7==0){
            for(int j=1;j<=wei;j++){
                cout << 8;
            }
            cout << endl;
        }
        else if(n%7==1){
                cout << 10;
            for(int j=1;j<=wei-1;j++){
                cout<<8;
            }
            cout << endl;
        }
        else{
            if(n%7==1)cout << 10;
            else if(n%7==2)cout << 18;
            else if(n%7==3)cout << 22;
            else if(n%7==4)cout << 20;
            else if(n%7==5)cout << 28;
            else if(n%7==6)cout << 68;

            for(int j=1;j<=wei-1;j++){
                cout << 8;
            }
            cout << endl;
        }
    }
    return 0;
}
