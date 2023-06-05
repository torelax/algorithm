### 万能头文件<bits/stdc++.h>
# Fabonacci
### 递归解法：
``` C++
int fab(n) {
    if (n == 1|n == 2) return 1;
    return fab(n-1) + fab(n-2);
}
```
- 此法时间复杂度为$O(2^n)$
### DP剪枝
- 递归问题在于重复计算fab(n) 备忘录记录fab(n)，进行剪枝
```C++
int fab(n) {
    if (n==1 | n==2) return 1;
    int pos1 = 1, pos2 = 1;
    for (int i=3; i<=n; i++) {
        int res = pos1 + pos2;
        pos1 = pos2;
        pos2 = res;
    }
    return pos2;
}
```
- - -
### A、B最大公约数gcd一定能被公约数k整除
设有两个数$A、B$,他们的最大公约数$gcd(A, B):=>gcd$,另有公约数$k:$
$A = m_1\cdot gcd = s_1\cdot k$
$B = m_2\cdot gcd = s_2\cdot k$ $%a/b == \frac{a}{b} $
则有 $s_1/m_1=s_2/m_2$，则$s_2=s_1m_2/m1$
因为$m_1、m_2$互质且$s_2、s_1$为整数，则必有
$s_1 = x\cdot m_1\quad x\in N$
即$gcd/k=x$
- - -
### C++加速代码
``` C++
static const auto io_sync_off = []()
{
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();
```
+ 解释如下


---
###  多数元素 
#### array[]中个数大于n/2
+ Boyer-Moore投票法
``` Python

```
**array**整体可分为**多数元素**和**非多数元素**，极端情况下所有**非多数元素**都相同，即维护一个选票，始终有`count[非多数元素]++`，仍然可被**多数元素**减尽

## 最长上升子序列
####贪心+二分
+ 考虑一个简单的贪心，如果我们要使上升子序列尽可能的长，则我们需要让序列上升得尽可能慢，因此我们希望每次在上升子序列最后加上的那个数尽可能的小。

+ 基于上面的贪心思路，我们维护一个数组 `d[i]` ，表示长度为 i 的最长上升子序列的末尾元素的最小值，用 $\textit{len}$ 记录目前最长上升子序列的长度，起始时 $\textit{len}$ 为 1，$d[1]=nums[0]$

- 同时我们可以注意到`d[i]`是关于`i`单调递增的。因为如果`d[j]≥d[i]`且`j<i`我们考虑从长度为`i`的最长上升子序列的末尾删除`i−j`个元素，那么这个序列长度变为`j`且第`j`个元素`x`（末尾元素）必然小于`d[i]`也就小于`d[j]`那么我们就找到了一个长度为`j`的最长上升子序列，并且末尾元素比`d[j]`小，从而产生了矛盾。因此数组`d[]`的单调性得证。

我们依次遍历数组`nums[]`中的每个元素，并更新数组 `d[]`和 `len`的值。如果`nums[i]>d[len]`则更新`len=len+1`否则在 `d[1…len]`中找满足 `d[i−1]<nums[j]<d[i]`的下标`i`并更新`d[i]=nums[j]`

**整个算法流程为**
设当前已求出的最长上升子序列的长度为`len`（初始时为 1）从前往后遍历数组`nums`在遍历到`nums[i]`时
- 如果`nums[i] > d[len]`则直接加入到`d`数组末尾，并更新 `len=len+1`
- 否则，在 d 数组中二分查找，找到**第一个**比`nums[i]`小的数`d[k]`并更新`d[k+1]=nums[i]`
以输入序列 [0, 8, 4, 12, 2] 为例：

> 第一步插入 0，d = [0]
> 第二步插入 8，d = [0, 8]
> 第三步插入 4，d = [0, 4]
> 第四步插入 12，d = [0, 4, 12]
> 第五步插入 2，d = [0, 2, 12]
最终得到最大递增子序列长度为 3
``` C++
C++Python3
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = 1, n = (int)nums.size();
        if (n == 0) return 0;
        vector<int> d(n + 1, 0);
        d[len] = nums[0];
        for (int i = 1; i < n; ++i) {
            if (nums[i] > d[len]) 
                d[++len] = nums[i];
            else {
                int l = 1, r = len, pos = 0; // 如果找不到说明所有的数都比 nums[i] 大，此时要更新 d[1]，所以这里将 pos 设为 0
                while (l <= r) {
                    int mid = (l + r) >> 1;
                    if (d[mid] < nums[i]) {
                        pos = mid;
                        l = mid + 1;
                    }
                    else r = mid - 1;
                }
                d[pos + 1] = nums[i];
            }
        }
        return len;
    }
};
```