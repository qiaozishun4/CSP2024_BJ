# include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t,n;
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n;
        if(n==1){
            cout<<"-1"<<endl;
        }
        else if(n<=7){
            if(n==2){
                cout<<"1"<<endl;
            }
            if(n==3){
                cout<<"7"<<endl;
            }
            if(n==4){
                cout<<"4"<<endl;
            }
            if(n==5){
                cout<<"2"<<endl;
            }
            if(n==6){
                cout<<"6"<<endl;
            }
            if(n==7){
                cout<<"8"<<endl;
            }
        }
        else{
            int z;
            z=n/8-1;
            if(n%7==1){
                cout<<"10";
            }
            if(n%7==2){
                cout<<"18";
            }
            if(n%7==3){
                if(n==10){
                    cout<<"22"<<endl;
                }
                else{
                    cout<<"200";
                    z=z-1;
                }
            }
            if(n%7==4){
                cout<<"20";
            }
            if(n%7==5){
                cout<<"28";
            }
            if(n%7==6){
                cout<<"68";
            }
            if(n%7==0){
                cout<<"88";
            }
            for(int j=1;j<=z;j++){
                cout<<"8"<<endl;
            }
        }
    }


    return 0;
}
