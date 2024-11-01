#include<bits/stdc++.h>
using namespace std;
int gh[100005];
int main(){
    freopen("stick.in","r",stdin);
    freopen("stick.out","w",stdout);
    int a,b,sum=0;
    bool jjj=true;
    cin>>a;
    for(int i=1;i<=a;i++){
        cin>>b;

            if(b<=7){
                if(b==1){
                    cout<<-1<<endl;
                    break;
                }
                if(b==2){
                    cout<<1<<endl;
                    break;
                }
                if(b==3){
                    cout<<7<<endl;
                    break;
                }
                if(b==4){
                    cout<<4<<endl;
                    break;
                }
                if(b==5){
                    cout<<2<<endl;
                    break;
                }
                if(b==6){
                    cout<<6<<endl;
                    break;
                }
                if(b==7){
                    cout<<8<<endl;
                    break;
                }
            }
            int j=0;
            while(b>0){
                    if(b<=7){
                if(b==1){
                    gh[j-1]=7;
                    gh[j]=1;
                    break;
                }
                if(b==2){
                    gh[j]=1;
                    break;
                }
                if(b==3){
                    gh[j]=7;
                    break;
                }
                if(b==4){
                    gh[j]=4;
                    break;
                }
                if(b==5){
                    gh[j]=2;
                    break;
                }
                if(b==6){
                    gh[j]=6;
                    break;
                }
                if(b==7){
                    gh[j]=8;
                    break;
                }
                    }
                gh[j]=8;
                b-=7;
                j++;

        }
        for(int i=14290;i>=0;i--){
        if(gh[i]==0&&jjj){
            continue;
        }else{
            jjj=false;
        }
        cout<<gh[i];
    }

    return 0;
}
}
