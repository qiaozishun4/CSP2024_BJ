#include<bits/stdc++.h>
#define N 500001
using namespace std;
int tb1[10],tb2[10],canchoose[10];//tb2:sticks a num uses
char ans[N];
inline void make(){
    tb1[2]=1;
    tb1[3]=7;
    tb1[4]=4;
    tb1[5]=2;
    tb1[6]=0;
    tb1[7]=8;
    tb2[1]=2;
    tb2[7]=3;
    tb2[4]=4;
    tb2[2]=5;
    tb2[0]=6;
    tb2[6]=6;
    canchoose[1]=0;
    canchoose[2]=1;
    canchoose[3]=2;
    canchoose[4]=4;
    canchoose[5]=6;
    canchoose[6]=7;
    canchoose[7]=8;
    return;
}
int main(){
    FILE* f1=freopen("sticks.in","r",stdin);
    FILE* f2=freopen("sticks.out","w",stdout);
    int t;
    cin>>t;
    make();
    while(t--){
        int n,h=0,yes=1,first=1;
        cin>>n;
        while(1){
            if(n==1){
                yes=0;
                cout<<-1<<endl;
                break;
            }
            if(n>=2&&n<=7){
                if(n==6){
                    ans[h++]=6+'0';
                    break;
                }
                else{
                    ans[h++]=tb1[n]+'0';
                }
                break;
            }
            else{
                int minweishu=ceil((double)n/7.0);
                for(int i=1;i<=7;i++){
                    if(first&&(i==1)){
                        continue;
                    }
                    int num=canchoose[i];
                    int lastn=n-tb2[num];
                    if(ceil((double)lastn/7.0)==minweishu-1){
                        ans[h++]=num+'0';
                        first=0;
                        minweishu--;
                        n=lastn;
                        break;
                    }
                }
            }
        }
        if(yes){
            for(int i=0;i<h;i++){
                cout<<ans[i];
            }
            cout<<endl;
        }
    }
    fclose(f1);
    fclose(f2);
    return 0;
}
