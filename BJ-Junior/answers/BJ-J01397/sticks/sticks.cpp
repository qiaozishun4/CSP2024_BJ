#include <bits/stdc++.h>
using namespace std;
long long t,n,sum,a[15]={0,0,1,7,4,2,0,8,10,18,22,20,28,68,88};
string s,sa[10]={"0","1","2","3","4","5","6","7","8","9"};
long long Se(long long s)
{
    long long sum=0;
    while(s>14){
        s-=7;
        sum++;
    }
    return sum;
}
long long MO(long long s)
{
    while(s>14){
        s-=7;
    }
    return s;
}
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        if(n<=1){
            cout<<-1<<endl;
            continue;
        }
        else if(n==6){
            cout<<6<<endl;
            continue;
        }
        else if(n<=14){
            cout<<a[n]<<endl;
            continue;
        }
        else{
            for(int i=1;i<=Se(n);i++){
                s=s+"8";
            }
            long long d=a[MO(n)];
            s=sa[d%10]+s;
            if(d/10!=0){
                s=sa[d/10]+s;
            }
        }
        cout<<s<<endl;
    }
    return 0;
}