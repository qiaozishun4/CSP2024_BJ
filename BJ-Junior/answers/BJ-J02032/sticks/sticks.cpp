include <iostream>
using namespace std;
int cd[8] = {0,0,1,7,4,2,0,8},k = 2e9;
void dfs(int n,int num,int w)
{
    cout <<  n << " " << num << " " << w << " ";
    if(w == 1&&num != 0)
    {
        num = num*10 + cd[n];
        cout << num << endl;
        k = min(num,k);
    }
    else
    {
        cout << endl;
        for(int i = 2;i <= 7;i++)
        {
            n-=i;
            num = num*10+cd[i];
            dfs(n,num,w-1);
        }
    }
}
int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if(n < 2)
        {
            cout << -1 <<  '\n';
            continue;
        }
        if(n < 8)
        {
            if(!cd[n])cout << 6 << endl;
            else cout << cd[n] << endl;
            continue;
        }
        int w = n/7+1;
        if(w % 7 == 0)w--;
        dfs(n,0,w);
        cout << k << '\n';}
include <iostream>
using namespace std;
int cd[8] = {0,0,1,7,4,2,0,8},k = 2e9;
void dfs(int n,int num,int w)
{
    cout <<  n << " " << num << " " << w << " ";
    if(w == 1&&num != 0)
    {
        num = num*10 + cd[n];
        cout << num << endl;
        k = min(num,k);
    }
    else
    {
        cout << endl;
        for(int i = 2;i <= 7;i++)
        {
            n-=i;
            num = num*10+cd[i];
            dfs(n,num,w-1);
        }
    }
}
int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if(n < 2)
        {
            cout << -1 <<  '\n';
            continue;
        }
        if(n < 8)
        {
            if(!cd[n])cout << 6 << endl;
            else cout << cd[n] << endl;
            continue;
        }
        int w = n/7+1;
        if(w % 7 == 0)w--;
        dfs(n,0,w);
        cout << k << '\n';}
 fclose(stdin);
    fclose(stdout);
    return 0;
}

