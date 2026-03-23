# 数学 Math

## 数论基础

### 最大公约数（GCD）与最小公倍数（LCM）
```cpp
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int lcm(int a, int b) { return a / gcd(a, b) * b; }
```

### 裴蜀定理（Bezout's Lemma）
对于整数 a, b，方程 `ax + by = c` 有整数解当且仅当 `gcd(a, b) | c`

### 快速幂
```cpp
long long power(long long base, long long exp, long long mod) {
    long long result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) result = result * base % mod;
        base = base * base % mod;
        exp >>= 1;
    }
    return result;
}
```

## 素数

### 埃氏筛法（Sieve of Eratosthenes）O(n log log n)
```cpp
vector<bool> sieve(int n) {
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i)
                isPrime[j] = false;
        }
    }
    return isPrime;
}
```

## 二分查找

用于在有序数组中查找目标值，时间复杂度 O(log n)：
```cpp
int binarySearch(vector<int>& arr, int target) {
    int l = 0, r = arr.size() - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}
```

## 进制转换

- 十进制转 k 进制：反复对 k 取余
- k 进制转十进制：按位权展开求和
