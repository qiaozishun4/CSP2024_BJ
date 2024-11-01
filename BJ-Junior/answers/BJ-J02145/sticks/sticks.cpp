#include <bits/stdc++.h>

using namespace std;

int t;
int n;
int arr[10]={6,2,5,5,4,5,6,3,7,6};

int count_sticks(int num){
    int sticks=0;
    int b;
    b=num;
    while(b!=0){
        sticks+=arr[b%10];
        b/=10;
    }
    return sticks;
}

int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);

    cin >> t;

    for(int i=0;i<t;i++){
        cin >> n;
        int ans=-1;
        int j=1;
        while(j<=100000){
            if(count_sticks(j)==n){
                ans=j;
                break;
            }
            //cout << "j=" << j << ' ' << count_sticks(j) << endl;
            j++;
        }
        cout << ans << endl;
    }

    return 0;
}

/*
#include <bits/stdc++.h>

using namespace std;

int t;
int n;
int ans[21]={-1,-1,1,7,4,3,6,8,16,18,78,26,28,68,88,168,188,468,368,388,688};

int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);

    cin >> t;

    for(int i=0;i<t;i++){
        cin >> n;
        if(n<=20){
            cout << ans[n] << endl;
        }
        else{
            cout << -1 << endl;
        }
    }

    return 0;
}
*/
