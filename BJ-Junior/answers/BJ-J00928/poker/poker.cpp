#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
string a[55];
const int num = 52;
int main()
{
  freopen("poker.in",r,stdin);
  freopen("poker.out",w,stdout);
  int n,cnt;
  cin >> n;
  for(int i = 1;i<=n;i++)
  {
     cin >> a[i];
     cnt++;
  }
  for(int i = 1;i<=n-1;i++)
  {
     for(int j = i+1;j<=n;j++)
     {
        if(a[i]==a[j])
        {
           cnt--;
        }
     }
  }
  cout << num-cnt;
  fclose(stdin);
  fclose(stdout);
  return 0;
}