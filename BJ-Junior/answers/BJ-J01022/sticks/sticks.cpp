#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define pb emplace_back
int s[]={6,2,5,5,4,5,6,3,7,6};
//       0,1,2,3,4,5,6,7,8,9
int cnt[15];
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t,n,x,c;
    cin>>t;
    while(t--){
        for(int i=0;i<=9;i++) cnt[i]=0;
        cin>>n;
        if(n<=1){
            cout<<"-1"<<endl;
            continue;
        }
        if(n%7==0){
            x=n/7;
            for(int i=1;i<=x;i++) cout<<'8';
            cout<<endl;
        }else if((n-1)%7==0){
            x=(n-1)/7;
            cout<<"10";
            for(int i=1;i<x;i++) cout<<'8';
            cout<<endl;
        }else{

            if(n==6) cout<<'6'<<endl;
            else{
                cnt[8]=n/7;
                n%=7;
                cnt[0]=n/6;
                n%=6;
                cnt[2]=n/5;
                n%=5;
                cnt[4]=n/4;
                n%=4;
                cnt[7]=n/3;
                n%=3;
                cnt[1]=n/2;
                n%=2;
                for(int i=0;i<=9;i++) c+=cnt[i];
                if(c==2 && cnt[0]==1){
                    cnt[0]--;
                    cnt[6]++;
                }
                for(int i=1;i<=9;i++){
                    if(cnt[i]){
                        cnt[i]--;
                        cout<<i;
                        break;
                    }
                }
                for(int i=0;i<=9;i++){
                    while(cnt[i]--){
                        cout<<i;
                    }
                }
                cout<<endl;
            }
        }
    }
    return 0;
}
