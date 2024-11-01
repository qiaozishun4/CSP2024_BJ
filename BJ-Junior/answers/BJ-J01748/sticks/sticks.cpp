#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(n%7==0){
            for(int i=0;i<n/7;i++){
                cout<<8;
            }cout<<endl;
        }else if(n%7==1&&n!=1){
            cout<<10;
            for(int i=1;i<n/7;i++){
                cout<<8;
            }

        }else{
            if(n<=7){
                if(n==1){
                    cout<<-1<<endl;
                }else if(n==2){
                    cout<<1<<endl;
                }else if(n==3){
                    cout<<7<<endl;
                }else if(n==4){
                    cout<<4<<endl;
                }else if(n==5){
                    cout<<2<<endl;
                }else if(n==6){
                    cout<<6<<endl;
                }else if(n==7){
                    cout<<8<<endl;
                }
            }else{
                if(n<=14){
                    if(n==8){
                        cout<<10<<endl;
                    }else if(n==9){
                        cout<<18<<endl;
                    }else if(n==10){
                        cout<<23<<endl;
                    }else if(n==11){
                        cout<<26<<endl;
                    }else if(n==12){
                        cout<<28<<endl;
                    }else if(n==13){
                        cout<<68<<endl;
                    }else if(n==14){
                        cout<<88<<endl;
                    }
                }else{
                    if(n%7==1){
                        cout<<"10";
                    }else if(n%7==2){
                        cout<<18;
                    }else if(n%7==3){
                        cout<<"40";
                    }else if(n%7==4){
                        cout<<20;
                    }else if(n%7==5){
                        cout<<"60";
                    }else if(n%7==6){
                        cout<<68;
                    }for(int i=1;i<n/7;i++){
                        cout<<8;
                    }cout<<endl;
                }
            }
        }
    }fclose(stdin);
    fclose(stdout);

return 0;
}





