#inlude<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int res = 0;
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int f = 1;
        if ((a == b && b == c && a % 2 == 1) || (a % 2 == 1 && b % 2 == 1 && c % 2 == 1)) {
            f = 0;
        }
        res = min(min(a, b), c) + d / 2;
        int Res = (a / 2) + (b / 2) + (c / 2) + (d / 2) + (f == 0 ? 1 : 0);
        cout << max(Res, res) << endl;
    }
    return 0;
}
