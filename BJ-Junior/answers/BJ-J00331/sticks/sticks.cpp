#include<iostream>
using namespace std;
const int inf=1000000;
int numl[10]={6,2,5,5,4,5,6,3,7,6};
int n,t;
int minl[13]={-1,-1,1,7,4,2,6,8,10,18,22,20,28};
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    for(int j=0;j<t;j++){
        cin>>n;
        int en=n/7-1;
        int m=n%7+7;
        if(m>12){
            m-=7;
            en++;
        }
        if(en==-1){
            en++;
            m-=7;
        }
        cout<<minl[m];
        for(int i=0;i<en;i++){
            cout<<8;
        }
        cout<<endl;
    }
    fclose(stdin);
    fclose(stdout);
}
