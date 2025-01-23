#include <bits/stdc++.h>

using i64 = long long;
const int mod = 1e9 + 7;
int dp[3005][205], a[205], b[205], vis[205];

void solve()
{
    int n, l, cnt = 0;
    std::cin >> n >> l;

    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i] >> b[i];
        if (a[i] != b[i])
        {
            cnt++;
            a[n + cnt] = b[i];
            b[n + cnt] = a[i];
            vis[i] = n + cnt;
            vis[n + cnt] = i;
        }
    }
    n += cnt;
    for (int i = 1; i <= l; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dp[a[j]][j] = 1;
            for (int k = 1; k <= n; k++)
            {
                if (k == j || k == vis[j])
                {
                    continue;
                }
                else
                {
                    if (b[k] == a[j] && i > a[j])
                    {
                        dp[i][j] = (dp[i][j] + dp[i - a[j]][k]) % mod;
                    }
                }
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans = (ans + dp[l][i]) % mod;
    }
    std::cout << ans << '\n';
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
