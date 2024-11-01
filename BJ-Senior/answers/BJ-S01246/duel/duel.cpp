#include<bits/stdc++.h>
using namespace std;
int n,an,nums[100010],sums;
vector<int>a;
bool flag=1;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    sums=n;
    for(int i=1;i<=n;i++){
        cin>>an;
        nums[an]++;
        a.push_back(an);
    }
    sort(a.begin(),a.end());
    for(int i=0;i<a.size()-1;i++){
        if(a[i]==a[i+1]){
            a.erase(a.begin()+i);
            i--;
        }
    }
    flag=0;
    for(int i=0;i<a.size();i++){
        for(int j=i-1;j>=0;j--){
            if(nums[a[j]]<=nums[a[i]]){
                sums-=nums[a[j]];
                nums[a[j]]=0;
            }else{
                sums-=nums[a[i]];
                nums[a[i]]=0;
                break;
            }
        }
    }
    cout<<sums;
    return 0;
}
