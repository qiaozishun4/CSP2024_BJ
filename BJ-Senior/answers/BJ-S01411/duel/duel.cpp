#include<bits/stdc++.h>
using namespace std;
int n,cnt;
vector<int>a;
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a.push_back(x);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i]<=a[j]&&i!=j)continue;
            else if(a[i]>a[j]&&i!=j){
                a[j]=-1;
                continue;
            }
            else break;
        }
    }
    for(int i=0;i<n;i++){
        if(a[i]!=-1)cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}
//仰天大笑出门去，我辈岂是蓬蒿人。