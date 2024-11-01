#include<bits/stdc++.h>
using namespace std;
int T;
int n;
int sticks[]={6,2,5,5,4,5,6,3,7,6};
vector<int>v;
//rp++
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>T;
    while (T--){
        cin>>n;
        if (n<2){
            cout<<-1;
            continue;
        }
        for (int j=1;;j++){
            bool f=1;
            for (int i=0;i<=10;i++){
                if (i==0&&j==1)
                continue;
                if (n>sticks[i]){
                    v.push_back(i);
                    n-=sticks[i];
                    f=0;
                }
            }
            if (f)
            break;
        }
        for (int i=v.size()-1;i>=0;i--)
            cout<<v[i];
        cout<<endl;
        v.clear();
    }
    return 0;
}
