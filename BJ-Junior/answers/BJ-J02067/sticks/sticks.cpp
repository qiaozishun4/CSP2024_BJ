#include<bits/stdc++.h>
using namespace std;
const int data[10]={6,2,5,5,4,5,6,3,7,6};
const int max1=7,min1=2;
int n;
int cnt=0;
long long ans_fin[10000001]={0};
int cal(int ans,int wei,int p[30]){
    //cout<<endl<<endl;
    //cout<<"#data#";
    
    //for(int i=0;i<wei;i++){
    //    cout<<p[i]<<" ";
    //}
    //cout<<endl;
    //cout<<"#wei#"<<wei<<endl;
    //cout<<"#ans#"<<ans<<endl;
    if(ans<n){
        if(n-ans<max1){
            if(n-ans==7){
                p[wei]=8;
                cal(ans+7,wei+1,p);
            }else if(n-ans==6){
                if(wei==0){
                    p[wei]=6;
                    
                }else{
                    p[wei]=0;
                   
                }
                 cal(ans+6,wei+1,p);
            }else if(n-ans==5){
                p[wei]=2;
                 cal(ans+6,wei+1,p);
            }else if(n-ans==4){
                p[wei]=4;
                 cal(ans+4,wei+1,p);
            }else if(n-ans==3){
                p[wei]=7;
                 cal(ans+3,wei+1,p);
            }else if(n-ans==2){
                p[wei]=1;
                 cal(ans+2,wei+1,p);
            }
        }else{
            if(ans+min1>n){
                return -1;
            }
            for(int i=0;i<=9;i++){
                if(wei==0){
                    if(i==0){
                        i++;
                    }
                }
                p[wei]=i;
                //cout<<"CHOOSE"<<i<<endl;
                //cout<<"GOING TO NEXT"<<endl;
                cal(ans+data[i],wei+1,p);
            }
        }
        
    }else if(ans==n){
        for(int i=wei;i>=1;i--){
            ans_fin[cnt]+=pow(10,wei-i)*p[i-1];
        }
        //cout<<"###"<<ans_fin[cnt]<<endl;
        cnt++;
        return 1;
    }
    if(ans>n){
        return -1;
    }
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        cnt=0;
        memset(ans_fin,0,sizeof(ans_fin));
        cin>>n;
        if(n==1){
            cout<<-1<<endl;
        }else if(n==2){
            cout<<1<<endl;
        }else{
            int p[10]={0};
            cal(0,0,p);
            //cout<<"cnt:"<<cnt<<endl;
            if(cnt==0){
                cout<<-1<<endl;
            }else{
                long long int min=9223372036854775806;
                for(int i=0;i<cnt;i++){
                    if(ans_fin[i]<=min){
                        min=ans_fin[i];
                    }
                }
                cout<<min<<endl;
            }
        }
    }
    return 0;
}