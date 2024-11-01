#include<bits/stdc++.h>
using namespace std;

int T,n;
int main (){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>T;
    for(int i=0;i<T;i++){

        cin>>n;

        if(n%7==0){

            for(int j=1;j<=n/7;j++){

                cout<<"8";
            }
            cout<<endl;
        }

        else if(n%7==1){

            int k=n/7;
            cout<<"10";
            for(int j=1;j<k;j++){

                cout<<"8";
            }
            cout<<endl;
        }
        else if(n%7==2){

            int k=n/7;
            cout<<"18";
            for(int j=1;j<k;j++){

                cout<<"8";
            }
            cout<<endl;
        }
        else if(n%7==3){

            int k=n/7;
            cout<<"25";
            for(int j=1;j<k;j++){

                cout<<"8";
            }
            cout<<endl;
        }
        else if(n%7==4){

            int k=n/7;
            cout<<"26";
            for(int j=1;j<k;j++){

                cout<<"8";
            }
            cout<<endl;
        }
        else if(n%7==5){

            int k=n/7;
            cout<<"28";
            for(int j=1;j<k;j++){

                cout<<"8";
            }
            cout<<endl;
        }
        else if(n%7==6){

            int k=n/7;
            cout<<"68";
            for(int j=1;j<k;j++){

                cout<<"8";
            }
            cout<<endl;
        }

    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}
