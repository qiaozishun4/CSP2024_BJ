#include<bits/stdc++.h>
using namespace std;
int stick[10]={6,2,5,5,4,5,6,3,7,6};
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        int n;
        cin>>n;
        int tmp=n;
        int p=0;
        if(n==1) cout<<"-1"<<endl;
        if(n%7==0){
            for(int j=1;j<=n/7;j++){
                cout<<"8";
            }
            cout<<endl;
        }
        else if(n%6==0){
            for(int j=1;j<n/6;j++){
                cout<<"6";
            }
            cout<<"0"<<endl;
        }
        else if(n%5==0){
            for(int j=1;j<=n/5;j++){
                cout<<"2";
            }
            cout<<endl;
        }
        else if(n%4==0){
            for(int j=1;j<=n/4;j++){
                cout<<"4";
            }
            cout<<endl;
        }
        else if(n%3==0){
            for(int j=1;j<n/6+1;j++){
                cout<<"6";
            }
            cout<<"7"<<endl;
        }
        else if(n%2==0){
            for(int j=1;j<n/4+1;j++){
                cout<<"4";
            }
            cout<<"1"<<endl;
        }
        else{
            if(tmp-7>1) {
                tmp-=7;
                p+=1;
            }
            else{
                n=tmp;
                if(n%6==0){
                for(int j=1;j<n/6;j++){
                    cout<<"6";
                }
            }

            else if(n%5==0){
                for(int j=1;j<=n/5;j++){
                    cout<<"2";
                }
            }
            else if(n%4==0){
                for(int j=1;j<=n/4;j++){
                    cout<<"4";
                }
            }
            else if(n%3==0){
                for(int j=1;j<n/6+1;j++){
                    cout<<"6";
                }
            }
            else if(n%2==0){
                for(int j=1;j<n/4+1;j++){
                    cout<<"4";
                }
            }
            for(int q=1;q<=p;q++){
                cout<<"8";
            }
            cout<<endl;
    }
    }
    }
    return 0;
}