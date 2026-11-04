#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class BIT {
    int n;
    vector<ll> t;

public:
    BIT(int n) : n(n), t(n + 1, 0) {}

    void add(int i, ll v) {
        for (; i <= n; i += i & -i)
            t[i] += v;
    }

    ll get(int i) {
        ll s = 0;
        for (; i > 0; i -= i & -i)
            s += t[i];
        return s;
    }

    int kth(ll k) {
        int p = 0;
        for (int b = 1 << (31 - __builtin_clz(n)); b; b >>= 1) {
            int q = p + b;
            if (q <= n && t[q] < k) {
                p = q;
                k -= t[q];
            }
        }
        return p + 1;
    }
};

class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();

        vector<int> v = nums;
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());

        int m = v.size();
        vector<int> a(n);

        for (int i = 0; i < n; i++)
            a[i] = lower_bound(v.begin(), v.end(), nums[i]) - v.begin() + 1;

        BIT cnt(m), sum(m);
        vector<ll> cost(n - x + 1);
        ll total = 0;

        for (int i = 0; i < n; i++) {
            cnt.add(a[i], 1);
            sum.add(a[i], nums[i]);
            total += nums[i];

            if (i >= x) {
                cnt.add(a[i-x], -1);
                sum.add(a[i-x], -nums[i-x]);
                total -= nums[i-x];
            }

            if (i >= x-1) {
                int p = cnt.kth((x+1)/2);
                ll med = v[p-1];

                ll c = cnt.get(p);
                ll s = sum.get(p);

                cost[i-x+1] = med*c-s + total-s-med*(x-c);
            }
        }

        const ll INF = LLONG_MAX / 4;
        vector<ll> dp(n+1, 0), ndp(n+1);

        for (int j = 1; j <= k; j++) {
            fill(ndp.begin(), ndp.end(), INF);

            for (int i = 1; i <= n; i++) {
                ndp[i] = ndp[i-1];

                if (i >= x)
                    ndp[i] = min(ndp[i],
                                 dp[i-x] + cost[i-x]);
            }

            dp.swap(ndp);
        }

        return dp[n];
    }
};