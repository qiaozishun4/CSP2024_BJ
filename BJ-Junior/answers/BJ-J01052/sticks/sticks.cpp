#include<bits/stdc++.h>
using namespace std;
int num[11]={6,2,5,5,4,5,6,3,7,6};
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin>>t;
    int n;
    int wei=0;
    int num[7]={0};//6,2,5,4,3,7
    bool flag=true;
    int l=0;
    while(t--){
        cin>>n;
        if(n==8){
            cout<<10;
            continue;
        }
        if(n<2){
            cout<<-1;
        }
        while(n>=2){
            if(n>=7){
                n-=7;
                num[5]++;
                wei++;
            }if(n>=6){
                n-=6;
                num[0]++;
                wei++;
            }if(n>=5){
                n-=5;
                num[2]++;
                wei++;
            }if(n>=4){
                n-=4;
                num[3]++;
                wei++;
            }if(n>=3){
                n-=3;
                num[4]++;
                wei++;
            }if(n>=2){
                n-=2;
                num[1]++;
                wei++;
            }
        }
        while(num[1]!=0){
            flag=false;
            cout<<"1";
            num[1]--;
        }
        if(flag==false){
            while(num[0]!=0){
                cout<<"0";
                num[0]--;
            }
        }
        while(num[2]!=0){
            flag=false;
            cout<<"2";
            num[2]--;
        }
        if(flag==false){
            while(num[0]!=0){
                cout<<"0";
                num[0]--;
            }
        }
        while(num[3]!=0){
            flag=false;
            cout<<"4";
            num[3]--;
        }
        if(flag==false){
            while(num[0]!=0){
                cout<<"0";
                num[0]--;
            }
        }
        while(num[4]!=0){
            flag=false;
            cout<<"7";
            num[4]--;
        }
        if(flag==false){
            while(num[0]!=0){
                cout<<"0";
                num[0]--;
            }
        }
        while(num[5]!=0){
            flag=false;
            cout<<"8";
            num[5]--;
        }
        if(flag==false){
            while(num[0]!=0){
                cout<<"0";
                num[0]--;
            }
        }
        if(flag==true){
            while(num[0]!=0){
                cout<<"6";
                num[0]--;
            }
        }
        cout<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}