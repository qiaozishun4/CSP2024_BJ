#include <iostream>
using namespace std;
int s[8]={-1,1,7,4,2,6,8};
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin >> t;
    for(int i=0;i<t;i++){
        int n;
        cin >>n;
        if(n<=7){
            cout <<s[n-1]<<endl;
            continue;
        }
        else if(n%7==0){
            for(int i=0;i<(n/7);i++) cout <<'8';
            cout <<endl;
        }
        else if(n%7==1){
            cout <<"10";
            for(int i=0;i<(n/7-1);i++) cout <<'8';
            cout <<endl;
        }
        else if(n%7==2){
            cout <<"1";
            for(int i=0;i<(n/7);i++) cout <<'8';
            cout <<endl;
        }
        else if(n%7==3){
            cout <<"22";
            for(int i=0;i<(n/7-1);i++) cout <<'8';
            cout <<endl;
        }
        else if(n%7==4){
            cout <<"20";
            for(int i=0;i<(n/7-1);i++) cout <<'8';
            cout <<endl;
        }
        else if(n%7==5){
            cout <<"60";
            for(int i=0;i<(n/7-1);i++) cout <<'8';
            cout <<endl;
        }
        else if(n%7==6){
            cout <<"68";
            for(int i=0;i<(n/7-1);i++) cout <<'8';
            cout <<endl;
        }

    }
    return 0;
}
