#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N =10005;
int main(){
freopen("sticks.in","r",stdin);
freopen("sticks.out","w",stdout);
int n,s;
int ck[10]={6,2,5,5,4,5,6,3,7,6};
cin>>n;
for(int h=1;h<=n;h++){
    cin>>s;
    if(s<2){
        cout<<"-1"<<endl;
        continue;}
    int w=s/7+!(s%7==0);
    int ans[w];
    for(int i=1;i<=w;i++){
            if(i==w){
            if(i==1){
                for(int j=1;j<=9;j++){
                    if(s-ck[j]==0){
                        ans[i]=j;
                        break;
                    }
                }
            }
            else{
                for(int j=0;j<=9;j++){
                    if(s-ck[j]==0){
                        ans[i]=j;
                        break;
                    }
                }
            }
        }
        else if(i==1){
            for(int j=1;j<=9;j++)
            if((s-ck[j])/7+!((s-ck[j])%7==0)<=w-i){
                s-=ck[j];
                ans[i]=j;
                break;
            }
        }
        else {
            for(int j=0;j<=9;j++)
            if((s-ck[j])/7+!((s-ck[j])%7==0)<=w-i){
                s-=ck[j];
                ans[i]=j;
                break;
            }
            }

    }
    for(int i=1;i<=w;i++)
        cout<<ans[i];
    cout<<endl;
}
return 0;
}
