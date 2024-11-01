#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int s;
        cin>>s;
        if(s==1){
            cout<<"-1"<<endl;
        }
        else if(s%7==0){
            while(s){
                s/=10;
                cout<<"8";
            }
            cout<<endl;
        }
        else if(s%7==1){
            cout<<"10";
            s-=8;
            while(s){
                s/=10;
                cout<<"8";
            }
            cout<<endl;
        }
        else if(s%7==2){
            cout<<"1";
            s-=2;
            while(s){
                s/=10;
                cout<<"8";
            }
            cout<<endl;
        }
        else if(s%7==3){
            if(s/7==0){
                cout<<"7"<<endl;
            }
            else if(s/7==1){
                cout<<"23"<<endl;
            }
            else{
                cout<<"200";
                s-=17;
                while(s){
                    s/=10;
                    cout<<"8";
                }
                cout<<endl;
            }
        }
        else if(s%7==4){
            if(s/7==0){
                cout<<"4"<<endl;
            }
            else{
                cout<<"20";
                s-=11;
                while(s){
                    s/=10;
                    cout<<"8";
                }
                cout<<endl;
            }
        }
        else if(s%7==5){
            cout<<"2";
            s-=5;
            while(s){
                s/=10;
                cout<<"8";
            }
            cout<<endl;
        }
        else if(s%7==6){
            cout<<"6";
            s-=6;
            while(s){
                s/=10;
                cout<<"8";
            }
            cout<<endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
