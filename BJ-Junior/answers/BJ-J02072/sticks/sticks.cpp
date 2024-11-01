#include <bits/stdc++.h>

using namespace std;

int t,n;
int a[10]={6,2,5,5,4,5,6,3,7,6};
vector<int> v;

int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        v.clear();
        if(n==1){
            printf("-1\n");
            continue;
        }
        if(n<=6){
            if(n==2) printf("1\n");
            if(n==3) printf("7\n");
            if(n==4) printf("4\n");
            if(n==5) printf("2\n");
            if(n==6) printf("6\n");
            continue;
        }
        int dig=1+int(n/7);
        int yu=n%7;
        //cout<<dig<<" ";
        while(yu!=0){
            for(int i=0;i<10;i++){
                if(i==0 && v.size()==0) continue;
                if(a[i]>=yu){
                    v.push_back(i);
                    dig--;
                    yu+=7-a[i];
                    yu=yu%7;
                    break;
                }
            }
        }
        for(int i=0;i<v.size();i++) cout<<v[i];
        for(int i=1;i<=dig;i++) cout<<"8";
        cout<<endl;
    }
    return 0;
}
