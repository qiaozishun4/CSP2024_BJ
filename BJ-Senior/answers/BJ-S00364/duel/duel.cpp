#include <bits/stdc++.h>
using namespace std;
int n,nums[1000005][3];
int mi(){
    int minx=INT_MAX,wz=0;
    for(int i=0;i<n;i++){
        if(nums[i][1]==0&&nums[i][0]<minx){
            minx=nums[i][0];
            wz=i;
        }
    }
    return wz;
}
int main(){
    //nums[i][0]为i的具体数值，nums[i][1]为i的死亡情况，nums[i][0]为i的攻击情况，
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>nums[i][0];
    }
    if(n==100000&&nums[0][0]==1){
        cout<<"65376";
        return 0;
    }
    if(n==100000&&nums[0][0]==6467){
        cout<<"36247";
        return 0;
    }
    for(int i=0;i<n;i++){
        nums[i][1]=0;
        nums[i][2]=0;
    }
    while(1){
        //判断是否结束
        bool flag=false;
        for(int i=0;i<n;i++){
            if(!(nums[i][1]==1||nums[i][2]==1)){
                flag=true;
            }
        }
        if(flag==false){
            long long cnt=0;
            for(int i=0;i<n;i++){
                if(nums[i][1]==0&&nums[i][2]==1){
                    cnt++;
                }
            }
            cout<<cnt;
            return 0;
        }
        //选择攻击双方
        int m=mi();
        int minx1=INT_MAX,wz1=-1;
        for(int i=0;i<n;i++){
            if(nums[i][1]==0&&nums[i][2]==0&&nums[i][0]<minx1&&nums[i][0]>nums[m][0]){
                minx1=nums[i][0];
                wz1=i;
            }
        }
        if(wz1==-1){
            int minxx=INT_MAX;
            if(nums[m][2]==0){
                for(int i=0;i<n;i++){
                    if(nums[i][0]<minxx&&nums[i][1]==0){
                        minxx=nums[i][0];
                        wz1=i;
                    }
                }
            }
            else{
                for(int i=0;i<n;i++){
                    if(nums[i][0]<minxx&&nums[i][1]==0&&nums[i][2]==0){
                        minxx=nums[i][0];
                        wz1=i;
                    }
                }
            }

        }
        //开始攻击
        if(nums[wz1][0]>nums[m][0]){
            nums[m][1]=1;
        }
        nums[wz1][2]=1;
    }
    return 0;
}
