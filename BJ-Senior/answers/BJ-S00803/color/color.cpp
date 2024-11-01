#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int dic[12];
struct nums{
    ll numbers[100002] = {};
    ll colors[100002] = {0};
    ll layer = 0;
    ll point = 0;
};

int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int t;
    cin >> t;
    for (int l = 0;l < t;l ++){
        int ans = 0,n;
        nums tmp;
        cin >> n;
        for (int i = 0;i < n;i ++){
            cin >> tmp.numbers[i];
            tmp.colors[i] = 0;
        }
        
        queue<nums> q;
        q.push(tmp);
        while (1){
            nums f = q.front();q.pop();
            nums f1,f2;
            f1.colors[f.layer] = 0;
            f2.colors[f.layer] = 1;
            f1.layer = f.layer + 1;
            f2.layer = f.layer + 1;
            if (f1.layer > n || f2.layer > n){
                break;
            }
            ll point1 = 0;
            for (ll i = 1;i < n;i ++){
                for (ll j = i-1;j >= 0;j --){
                    bool tmpflag = 0;
                    if (tmpflag == 0 && tmp.numbers[j] == tmp.numbers[i] && f1.colors[j] == f1.colors[i]){
                        point1 += tmp.numbers[j];
                        tmpflag = 1; 
                    }
                }
            }  
            f1.point = point1;
            ll point2 = 0;
            for (ll i = 1;i < n;i ++){
                for (ll j = i-1;j >= 0;j --){
                    bool tmpflag = 0;
                    if (tmpflag == 0 && tmp.numbers[j] == tmp.numbers[i] && f2.colors[j] == f2.colors[i]){
                        point2 += tmp.numbers[j];
                        tmpflag = 1; 
                    }
                }
            }
            f2.point = point2;
            if (f2.point > f1.point){
                q.push(f1);
                q.push(f2);    
            }
            else{
                
            }
            q.push(f1);
            q.push(f2);
            if (max(f2.point,f1.point) > ans){
                ans = max(f2.point,f1.point);
            }

        }
        dic[l] = ans;
    }
    for (int i = 0;i < t;i ++){
        cout<< dic[i] << endl;
    }
    return 0;
}