#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int n;
    int num[10]={6,2,5,5,4,5,6,3,7,6};
    cin>>n;
    while(n>1){
        int m;
        cin>>m;
        if(m==6){
            cout<<'0'<<endl;
            continue;
        }
        if(m==1){
           cout<<"-1"<<endl;
           continue;
        }else if(m%7==0){
            for(int i=0;i<m/7;i++){
                cout<<'8';
            }
            cout<<endl;
            continue;
        }else if(m%7==1){
            cout<<"10";
            for(int i=0;i<m/7-1;i++){
                cout<<'8';
            }
            cout<<endl;
            continue;
        }else if(m%7==2){
            cout<<'1';
            for(int i=0;i<m/7;i++){
                cout<<'8';
            }
            cout<<endl;
        }else if(m%7==3){
            if(m>7){
                cout<<"22";
            for(int i=0;i<m/7-1;i++){
                cout<<'8';
            }
            cout<<endl;
            }else if(m==3){
                cout<<'7'<<endl;
            }
        }else if(m%7==4){
            if(m>7){
                cout<<"20";
            for(int i=0;i<m/7-1;i++){
                cout<<'8';
            }
            cout<<endl;
            }else if(m==4){
                cout<<'4'<<endl;
            }

        }else if(m%7==5){
            cout<<'2';
            for(int i=0;i<m/7;i++){
                cout<<'8';
            }
            cout<<endl;
        }else if(m%7==6){
            cout<<'9';
            for(int i=0;i<m/7;i++){
                cout<<'8';
            }
            cout<<endl;
        }

        n--;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
