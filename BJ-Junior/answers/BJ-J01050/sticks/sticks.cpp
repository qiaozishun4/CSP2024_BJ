#include<iostream>
using namespace std;
int min_fst[25]={-1,-1,1,7,4,2,6,8,10,18,22,20,28,80,88};
void slove(){
    int n;cin>>n;
    if(n<=1)cout<<-1;
    else if(n<=14)cout<<min_fst[n];
    else{
        int k=n%7;
        if(k==0){
            for(int i=1;i<=n/7;i++)cout<<8;
        }else{
            k+=7;
            if(k==10){
                cout<<200;
                for(int i=1;i<=(n-k)/7-1;i++)cout<<8;
            }else{
                cout<<min_fst[k];
                for(int i=1;i<=(n-k)/7;i++)cout<<8;
            }
        }
    }
    cout<<endl;
    return;
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T;cin>>T;
    while(T--)slove();
    fclose(stdin);
    fclose(stdout);
    return 0;
}
