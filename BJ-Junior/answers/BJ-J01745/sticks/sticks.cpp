#include <bits/stdc++.h>

using namespace std;
int sti[10]={6,2,5,5,4,5,6,3,7,6};
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T;
    cin>>T;
    for(int i=0;i<T;i++){
        int n;
        cin>>n;
        if(n==1){
            cout<<-1;
            continue;
        }
        if(n%7==0){
            for(int i=0;i<(n/7);i++){
                cout<<"8";
            }
            cout<<endl;
        }
        else{
            int x=n%7;
            if(x==1){
                cout<<"10";
                for(int i=0;i<(n/7)-1;i++){
                    cout<<"8";
                }
            }
            else if(x==2){
                cout<<18;
                for(int i=0;i<(n/7)-1;i++){
                    cout<<"8";
                }
            }
            else if(x==3){
                cout<<23;
                for(int i=0;i<(n/7)-1;i++){
                    cout<<"8";
                }
            }
            else if(x==4){
                cout<<20;
                for(int i=0;i<(n/7)-1;i++){
                    cout<<"8";
                }
            }
            else if(x==5){
                cout<<28;
                for(int i=0;i<(n/7)-1;i++){
                    cout<<"8";
                }
            }
            else if(x==6){
                cout<<68;
                for(int i=0;i<(n/7)-1;i++){
                    cout<<"8";
                }
            }
        }
        cout<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
