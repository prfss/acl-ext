#pragma once

#include <map>
#include <vector>

using namespace std;

namespace aclext {
// <---
// name: Divisor
vector<long long> divisor(long long n) {
    vector<long long> ret;
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ret.push_back(int(i));
            if (i * i != n) ret.push_back(n / i);
        }
    }
    return ret;
}
// --->

// <---
// name: Prime Factorization
map<long long, int> prime_factor(long long n) {
    map<long long, int> res;
    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            res[i]++;
            n /= i;
            i--;
        }
    }
    if (n != 1) res[n]++;
    return res;
}
// --->

// name: Is Prime
bool is_prime(long long n) {
    if (n == 1) return false;
    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}
// --->

// <---
// name: Totient
long long totient(long long x) {
    long long ans = 1;
    for (long long i = 2; i * i <= x; i++) {
        long long temp = 1;
        while (x % i == 0) {
            temp *= i;
            x /= i;
        }

        if (temp != 1) {
            ans *= temp - temp / i;
        }
    }
    if (x != 1) {
        ans *= x - 1;
    }

    return ans;
}
// --->

// <---
// name: Extended Euclidean Algorithm
template <typename T>
tuple<T, T, T> extgcd(T a, T b) {
    if (b == 0) {
        return make_tuple(a, 1, 0);
    } else {
        auto [g, x, y] = extgcd(b, a % b);
        return make_tuple(g, y, x - a / b * y);
    }
}
// --->
}