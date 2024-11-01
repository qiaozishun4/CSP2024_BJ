#include<bits/stdc++.h>
using namespace std;

int num[]={1,7,4,2,3,5,0,6,9,8};
int cnt[]={2,3,4,5,5,5,6,6,6,7};
int t,n;
priority_queue<int,vector<int>,greater<int>>pq;


void got(int x){
    if(x%7==0){
        for(int i=1;i<=x/7;i++){
            cout<<8;
        }

            cout<<endl;
            return ;
    }else if(x%7==1&&x>7){
        cout<<10;
        for(int i=1;i<=x/7-1;i++){
            cout<<8;
        }
        cout<<endl;
    }else{
        int k=n/7;
        for(int j=1;j<=k+1;j++){
            for(int i=0;i<=9;i++){
            if((x-cnt[i])/k<=7){
                pq.push(num[i]);
                x-=cnt[i];
                break;
            }
            else{
                continue;
            }
        }
        }

        while(!pq.empty()){
            cout<<pq.top();
            pq.pop();
        }
        cout<<endl;
    }

}

void solve(){
    cin>>n;
    long long number=0;
    //first bit
    if(n<=1){
        cout<<-1<<"\n";
    }else if(n<=7&&n!=6){
        cout<<num[lower_bound(cnt,cnt+10,n)-cnt]<<"\n";
    }else if(n==6){
        cout<<6<<endl;
    }else{
        switch(n){
            case 8:cout<<10;break;
            case 9:cout<<18;break;
            case 10:cout<<22;break;
            case 11:cout<<20;break;
            case 12:cout<<28;break;
            case 13:cout<<68;break;
            case 14:cout<<88;break;
            case 18:cout<<208;break;
            case 15:cout<<108;break;
            case 16:cout<<188;break;
            case 17:cout<<200;break;
            case 19:cout<<288;break;
            case 20:cout<<880;break;
            case 21:cout<<888;break;
            case 22:cout<<1088;break;
            default: got(n);break;
        }
    }

}


int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);

    cin>>t;
    while(t--){
        solve();
    }


    fclose(stdin);
    fclose(stdout);
    return 0;
}
