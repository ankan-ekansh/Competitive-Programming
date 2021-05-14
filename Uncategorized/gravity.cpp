/*
    Stay motivated and keep working hard
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<vector<char>> figureUnderGravity(vector<vector<char>> matrix)
{
    ll n, m;
    n = matrix.size();
    m = matrix[0].size();
    vector<vector<ll>> dist(n, vector<ll>(m, INT_MAX));
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            for (ll k = i; k < n; k++)
            {
                if (matrix[k][j] == '#' && matrix[i][j] == 'F')
                {
                    dist[i][j] = min(dist[i][j], k - i);
                }
            }
        }
    }
    ll shift = INT_MAX;
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            if (matrix[i][j] == 'F')
                shift = min({shift, dist[i][j], n - i});
        }
    }
    shift = shift - 1;
    // cout << shift << "\n";
    for (ll i = n - 1; i >= shift; i--)
    {
        for (ll j = 0; j < m; j++)
        {
            if (matrix[i][j] != '#')
            {
                matrix[i][j] = matrix[i - shift][j];
            }
        }
    }
    for (ll i = shift - 1; i >= 0; i--)
    {
        for (ll j = 0; j < m; j++)
        {
            matrix[i][j] = '.';
        }
    }
    return matrix;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    // freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n, m;
    cin >> n >> m;
    vector<vector<char>> matrix(n, vector<char>(m, '.'));
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
        }
    }
    vector<vector<char>> ans = figureUnderGravity(matrix);
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}