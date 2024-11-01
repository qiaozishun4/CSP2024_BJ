#include<bits/stdc++.h>
using namespace std;

struct pai{
    int r = 0, c = 0, num = 0;
};

int main(){
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);

    int n, mx = -1, mn = INT_MAX, ans = 0, last= 0;
    pai a[100005];
    vector<int> nn;
    set<int> s;
    cin>>n;
    for (int i=1;i<=n;i++){
        int tmp;
        cin>>tmp;
        a[tmp].r = tmp; // 防御
        a[tmp].c++; // 攻击次数
        a[tmp].num++; // 存活个数
        s.insert(tmp);
    }
    ans = n;
    for (auto it = s.begin(); it != s.end(); it++){
        nn.push_back(*it);
    }
    //cout<<a[1].num<<'---'<<a[2].num<<endl;
    for (int i=0;i<nn.size()-1;i++){
        int ii = nn[i];
        for (int j=i+1;j<nn.size();j++){
            int jj = nn[j];
            if (a[ii].num <= a[jj].c){
                a[jj].c -= a[ii].num;
                ans -= a[ii].num;
                a[ii].num = 0;
                a[ii].c = 0;
                break;
            } else if (a[ii].num > a[jj].c){
                a[ii].num -= a[jj].c;
                ans -= a[jj].c;
                a[jj].c = 0;
            }
            //cout<<"111"<<endl;
            //break;
        }
    }
    cout<<ans<<endl;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
