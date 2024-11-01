#include<bits/stdc++.h>
using namespace std;
string answer = {};
void ERR(int n,int size2,char g,int i,const int n1){
    if(n == 0){
        return;
    }
    int size;
    if(n%7 == 0){
        size = n/7;
    }else{
        size = n/7+1;
    }
    while(i<=size){
        if(size <=size2 && answer[0] != '0' && n>0){
            if(i == 0){
            answer += '1';
            i++;
            ERR(n-2,size2,g,i+1,n1);
            }else{
                answer += g;
                i++;
                ERR(n-5,size2,g+1,i+1,n1);
            }
        }else{
            i = 0;
            answer = {};
            ERR(n1,size2,g+1,1,n1);
        }
    }
}

int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int n,t,size2;
    cin >> t;
    for(int i = 0;i<t;i++){
        cin >>n;
        const int n1 = n;
        if(n%7 == 0){
            size2 = n/7;
        }else{
            size2 = n/7+1;
        }
        if(n < 2){
            cout <<"-1" << endl;
        }
        else if(n == 2){
            cout << '1' << endl;
        }else if(n == 5){
            cout << '2' << endl;
        }else if(n == 4){
            cout << '4' << endl;
        }else if(n == 3){
            cout << '7' << endl;
        }else if(n == 7){
            cout << '8' << endl;
        }else if(n == 6){
            cout << '6' << endl;
        }else{
            for(int i = 7;i<=n;i+=7){
                answer += '8';
            }
            cout <<answer << endl;
            answer = {};
        }
    }
    return 0;
}
