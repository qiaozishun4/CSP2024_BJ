#include<bits/stdc++.h>
using namespace std;
int nm[10]={6,2,5,5,4,5,6,3,7,6};
bool cmp(int a,int b){
    return a<b;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        if(n==1){
            cout<<-1<<endl;
            continue;
        }
        int x=n/7;
        if(n%7>0){
            x++;
        }
        vector<int> p;
        int mc=0;
        for(int i=0;i<x-1;i++){
            p.push_back(8);
            mc+=7;
        }
        for(int i=0;i<10;i++){
            if(n-mc==nm[i]){
                p.push_back(i);
                mc=n;
                break;
            }
        }
        if(n-mc!=0){
            p.pop_back();
            p.push_back(0);
            p.push_back(1);
            mc=n;
        }
        for(int i=0;i<x-1;i++){
            for(int j=0;j<10;j++){
                if(mc-nm[p[i]]+nm[j]<mc&&p[i]>j&&n-(mc-nm[p[i]]+nm[j])<=7){
                    mc=mc-nm[p[i]]+nm[j];
                    p[i]=j;
                }
            }
        }
        for(int i=0;i<10;i++){
            if(n-mc==nm[i]){
                p[x-1]=i;
                break;
            }
        }
        int p1[x];
        for(int i=0;i<x;i++){
            p1[i]=p[i];
        }
        sort(p1,p1+x,cmp);
        if(p1[0]==0){
            int ol=1;
            for(int i=1;i<x;i++){
                if(p1[i]!=0){
                    ol=i;
                    break;
                }
            }
            int t=p1[ol];
            p1[ol]=p1[0];
            p1[0]=t;
        }
        for(int i=0;i<x;i++){
            cout<<p1[i];
        }
        cout<<endl;
    }
    return 0;
}