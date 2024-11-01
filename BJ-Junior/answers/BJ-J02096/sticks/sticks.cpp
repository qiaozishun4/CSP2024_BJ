#include<iostream>
using namespace std;
int main(){
    int T,t=0;
    cin>>T;
    int num[T],sum[T]a[7][2]={{0,6},{1,2},{2,5},{4,4},{6,6},{7,3},{8,7}};
    for(int j=0;j<T;j++){
        cin>>num[j];
    }
    for(int j=0;j<T;j++){
        sum[j]=0;;
    }
    while(t<T){
        int n=num[t];
        if(n<2){
            sum[t]=-1;
            break;
        }
        int k=n/7;
        if(n%7!=0){
            k++;
        }
        t++;
    }
    for(int i=0;i<T;i++){
        cout<<sum[i]<<endl;
    }
    return 0;
}