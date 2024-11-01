#include<bits/stdc++.h>
using namespace std;
int n,dp[100002],t,x=0,m,c=1;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    for(int p=1;p<=t;p++){
        cin>>n;
        dp[1]=-1;
        dp[2]=1;
        dp[3]=7;
        for(int i=4;i<=n;i++){
            m=dp[i-2];
            while(true){
                m/=10;
                x++;
                if(m==0){
                    break;
                }
            }
            for(int j=1;j<=x+1;j++){
                c*=10;
            }
            if(dp[i-2]=-1){
                m=dp[i-5];
                while(true){
                    m/=10;
                    x++;
                    if(m==0){
                        break;
                    }
                }
                for(int j=1;j<=x+1;j++){
                    c*=10;
                }
                if(dp[i-5]=-1){
                    m=dp[i-4];
                    while(true){
                        m/=10;
                        x++;
                        if(m==0){
                            break;
                        }
                    }
                    for(int j=1;j<=x+1;j++){
                        c*=10;
                    }
                    if(dp[i-4]=-1){
                        m=dp[i-6];
                        while(true){
                            m/=10;
                            x++;
                            if(m==0){
                                break;
                            }
                        }
                        for(int j=1;j<=x+1;j++){
                            c*=10;
                        }
                        if(dp[i-6]=-1){
                            m=dp[i-3];
                            while(true){
                                m/=10;
                                x++;
                                if(m==0){
                                    break;
                                }
                            }
                            for(int j=1;j<=x+1;j++){
                                c*=10;
                            }
                            if(dp[i-3]=-1){
                                m=dp[i-7];
                                while(true){
                                    m/=10;
                                    x++;
                                    if(m==0){
                                        break;
                                    }
                                }
                                for(int j=1;j<=x+1;j++){
                                    c*=10;
                                }
                                if(dp[i-7]=-1){
                                    dp[i]=-1;
                                }else{
                                    dp[i]=dp[i-7]+c*8;
                                }
                            }else{
                                dp[i]=dp[i-3]+c*7;
                            }
                        }else{
                            dp[i]=dp[i-6]+c*6;
                        }
                    }else{
                        dp[i]=dp[i-4]+c*4;
                    }
                }else{
                    dp[i]=dp[i-5]+c*2;
                }
            }else{
                dp[i]=dp[i-2]+c*1;
            }
        }
        cout<<dp[n]<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}