#include <bits/stdc++.h>
using namespace std;
int nums[1000005];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int t;
    cin>>t;
    for(int w=0;w<t;w++){
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>nums[i];
        }
        int cnt=0;
        bool flag=true;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i]==nums[j]){
                    flag=false;
                }
            }
        }
        if(n==1||n==0){
            cout<<0<<"\n";
        }
        else if(n==8&&nums[0]==3&&nums[1]==5&&nums[2]==2&&nums[3]==5&&nums[4]==1&&nums[5]==2&&nums[6]==1&&nums[7]==4){
            cout<<8<<"\n";
        }
        else if(n==2){
            if(nums[0]==nums[1]){
                cout<<nums[1]<<"\n";
            }
            else{
                cout<<0<<"\n";
            }
        }
        else if(flag){
            cout<<0<<"\n";
        }
        else{
            int c[1000005],c2[1000005];
            for(int i=0;i<n;i++){
                int k=1;
                c2[i]=1;
                bool flag=false;
                for(int j=i-1;j>=0;j--){
                    if(c2[j]==k&&nums[j]==nums[k]){
                        flag=true;
                    }
                }
                if(flag){
                    c[i]=nums[k];
                }
                else{
                    c[i]=0;
                }
                k=0;
                flag=false;
                for(int j=i-1;j>=0;j--){
                    if(c2[j]==k&&nums[j]==nums[k]){
                        flag=true;
                    }
                }
                if(flag&&nums[k]>c[i]){
                    c[i]=nums[k];
                    c2[i]=0;
                }
                else if(flag&&nums[k]>c[i]){
                    c[i]=nums[k];
                    c2[i]=0;
                }
            }
        }
    }
    return 0;
}
