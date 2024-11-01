#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int n;
int a[101000];
int t[1000100];
bool s[100100];

int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        t[a[i]]++;
    }
    int sum=n;
    int f=-1;
    for(int i=1;i<=1000000;i++){
        if(t[i]!=0&&f!=-1){
            if(t[i]-f<=0){
                sum-=t[i];
            }else{
                sum-=f;
            }

        }
        if(t[i]!=0){
             if(f==-1)f=t[i];
             else f+=max(0,t[i]-f);
        }

    }
    cout<<sum<<endl;

    return 0;
}
