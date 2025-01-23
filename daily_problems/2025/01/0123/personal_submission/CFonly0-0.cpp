#include <bits/stdc++.h>

using i64 = long long;
int a[200020], c[200020];

void solve()
{
    int n, m, k;
    std::cin >> n >> m >> k;

    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }

    int ans = 0;
    for (int l = 0, r = 0; l < n; l++)
    {
        while (r < n && c[a[l]] + k >= r - l)
        {
            c[a[r]]++;
            r++;
        }

        ans = std::max(ans, c[a[l]]);

        c[a[l]]--;
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
