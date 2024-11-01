#include<bits/stdc++.h>
using namespace std;
//int w[10]={6,2,5,5,4,5,6,3,7,6};
//int v[10]={0,1,2,3,4,5,6,7,8,9};
int w[8]={7,6,6,5,4,3,2};
int v[8]={8,6,0,2,4,7,1};
int mins=100001;
void stick(int s,int sum,bool f){
    if(s==0){
        mins=min(mins,sum);
        return;
    if(s==1){
        return;
    }
    }for(int i=0;i<8;i++){
        if(f && i==0){
            continue;
        }
        if(s-w[i]>=0){
            stick(s-w[i],sum*10+v[i],false);
        }
    }
}
int main(){
    int n,s;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s;
        stick(s,0,true);
        if(mins==100001){
            cout<<-1<<endl;
            continue;
        }
        cout<<mins;
        mins=100001;

    }

    return 0;
}
