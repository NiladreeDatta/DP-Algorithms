#include<bits/stdc++.h>
using namespace std;
int n;
vector <int> a;
int dp[100000],lis[100000];
int func(int i, vector <int>& a)
{
    if(dp[i] != -1) return dp[i];

    int ans = 0;
    for(int j = i + 1 ; j < a.size() ; j++)
    {
        if(a[j] > a[i])
        {
            ans = max(ans, func(j,a));
        }
    }
    return dp[i] = ans + 1;
}
int main()
{
    cin >> n;
    for(int i = 0 ; i < n ; i++)
    {
        int u;
        cin >> u;
        a.push_back(u);
    }
    memset(dp,-1, sizeof (dp));
    int ans = 0;
    for(int i = 0 ; i < n ; i++)
    {
        ans = max(ans, func(i, a));
    }
    cout << ans << endl;


    return 0;
}
