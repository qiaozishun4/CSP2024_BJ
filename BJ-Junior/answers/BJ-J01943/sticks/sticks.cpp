#include<bits/stdc++.h>
using namespace std;

int n,T;
const int MAX = 1e5+20;
int possibles[6] = {6,2,5,4,3,7};
int breakRes[MAX][1000];
map<int,int> m = {{2,1},{5,2},{4,4},{6,6},{3,7},{7,8}};

void breakdown(int n,int num,int index){
    if(n<=7){
        breakRes[num][index] = n;
        return ;
    }
    breakRes[num][index] = possibles[num];
    breakdown(n-possibles[num],num,index+1);


}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>T;
    sort(possibles,possibles+6);
    while(T--){
        
        cin>>n;
        if(n<2){
            cout<<-1<<endl;
            continue;
        }
        if(n<7){
            cout<<m[n]<<endl;
            continue;
        }
    //     for(int i=0;i<6;i++){
    //         breakdown(n,i,0);
    //     }
    //     int ans=0x3fffff,all=n/7;
    //     for(int i=0;i<6;i++){
    //         int cnt=0;
    //         for(int j=0;j<all;j++){
    //             if(breakRes[i][j]!=0){
    //                 if(j==0 && breakRes[i][j]==6){

    //                     cnt += 6*pow(10,all-j-1);
    //                     continue;
    //                 }
    //                 cnt += m[breakRes[i][j]]*pow(10,all-j-1);

    //             }
    //         }
    //         ans = min(ans,cnt);
    //     }
    //     cout<<ans<<endl;
    // }
    
    fclose(stdin);
    fclose(stdout);
    return 0;
}
}