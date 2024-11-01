#include<iostream>
using namespace std;
int a[17]={0,-1,1,7,4,2,6,8,10,18,23,20,28,68,88};
void init(){
    int n;
    cin>>n;
    if(n<=14){
        cout<<a[n];
    }
    else{
        if(n%7==0){
            for(int i=0;i<n/7;i++){
                cout<<8;
            }
        }
        else{
            cout<<a[n%7+7];
            for(int i=0;i<(n/7-1);i++){
                cout<<8;
            }
        }
    }
    cout<<endl;
    return;
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T;
    cin>>T;
    for(int i=0;i<T;i++){
        init();
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
