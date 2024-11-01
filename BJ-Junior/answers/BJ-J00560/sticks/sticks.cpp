#include <bits/stdc++.h>
using namespace std;
int a[10] = {6,2,5,5,4,5,6,3,7,6};
int k;
string ans;
bool flag;
void dfs(int last,string num)
{
    if(last == 0){
            flag = 1;
            if(ans.size() > num.size()) ans = num;
            else if(ans.size() == num.size()) {
                for(int i = 0;i <= ans.size();i++)
                {
                    if(ans[i] > num[i]) {
                        ans = num;
                        break;
                    }
                    else if(num[i] > ans[i])
                    {
                        break;
                    }
                }
            }

            return;
    }
    if(num.size() > ans.size()) return;
    if(num[1] > ans[1] && num.size() == ans.size()) return;
    if(last == 1) return;
    for(int i = 0;i <= 9;i++)
    {
        if(i == 0 && last == k) continue;
        if(last >= a[i] && num.size() + 1 <= ans.size()){
                dfs(last - a[i],num + char(i + '0'));
        }
    }
}
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int n;
    cin >> n;
    while(n--)
    {
        ans = "99999999999999999999";
        flag = 0;
        cin >> k;
        if(k > 50)
        {
            if(k % 7 == 0)
            {
                while(k > 0)
                {
                    k -= 7;
                    cout << 8;
                }
            }
            else if(k % 7 == 1){
                k -= 7;
                cout << 8;
                for(int i = 1;i <= 6;i++) cout << 0;
                k -= 6 * 6;
                while(k > 0)
                {
                    k -= 7;
                    cout << 8;
                }
            }
            cout << endl;
        }
        else{
            dfs(k,"");
            if(ans != "99999999999999999999") cout << ans << endl;
            else cout <<-1 << endl;
        }

    }
    return 0;
}