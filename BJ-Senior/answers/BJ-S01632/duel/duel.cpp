#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    freopen("duel.in","r+",stdin);
    freopen("duel.out","w+",stdout);
    int listLength,attackTimes=0;
    cin>>listLength;
    int dataList[listLength],attackedList[listLength];
    for(int i=0;i<listLength;i++){
        cin>>dataList[i];
    }
    for(int i=0;i<listLength;i++){
        for(int j=i+1;j<listLength;j++){
            if(dataList[j]<dataList[i]){
                swap(dataList[j],dataList[i]);
            }
        }
    }
    for(int i=0;i<listLength;i++){
        for(int j=i+1;j<listLength;j++){
            if((dataList[i]<dataList[j])&&(dataList[i]!=0)&&(dataList[j]!=0)&&(attackedList[j]!=1)){
                dataList[i]=0;
                attackedList[j]=1;
                attackTimes++;
                break;
            }
        }
    }

    cout<<listLength-attackTimes<<endl;
    return 0;
}
