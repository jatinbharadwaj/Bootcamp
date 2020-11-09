#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t --){
        int n;
        cin >> n;
        vector<pair<int, int>> a(n + 1);
        for(int i = 0; i < n; i ++){
            cin >> a[i].first;
        }
        for(int i = 0; i < n; i ++){
            cin >> a[i].second;
        }
        a[n] = {0, 0};
        sort(a.begin(), a.end() - 1);
        vector<long long> sum(n + 1);
        for(int i = n - 1; i >= 0; i --){
            sum[i] = a[i].second;
            sum[i] += sum[i + 1];
        }
        long long mn = sum[0];
        for(int i = 0; i < n; i ++){
            mn = min(mn, max(1ll * a[i].first, sum[i + 1]));
            // cout << i << ": " << a[i].first << " " << sum[i + 1] << "\n";
        }
        cout << mn << "\n";
    }
}