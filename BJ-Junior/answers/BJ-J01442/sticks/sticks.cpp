#include<iostream>
using namespace std;
int T,n;

//int a[21]={-1,-1,2,7,4,2,6,8,10,};
int a[10]={6,2,5,5,4,5,6,3,7,6};
int cc[51]={-1,-1,1,7,4,2,6,8,10,18,22,20,28,68,88,108,188,200,208,288,688,888,1088,1888,2008,2088,2888,6888,8888,10888,18888,20088,20888,28888,68888,88888,108888,188888,200888,208888,288888,688888,888888,1088888,1888888,2008888,2088888,2888888,6888888,8888888,10888888,};
void specialA(int n){
    for(int i=1;i<=n/7;i++){
        cout<<8;
    }
    cout<<endl;
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n;
        if(n<2){
            cout<<-1<<endl;
            continue;
        }
        if(n%7==0){
            specialA(n);
            continue;
        }
        /*
        for(int i=1;;i++){
            int temp=i,b=0;
            while(temp>0){
                b+=a[temp%10];
                temp/=10;
            }
            if(b==n){
                cout<<i<<endl;
                break;
            }
        }*/
        if(n<=50){
            cout<<cc[n]<<endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
