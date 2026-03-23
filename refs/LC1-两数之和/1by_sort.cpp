/* 
首尾递进方法可行性分析 假设某一时刻 首尾处于i 和 j 且num[i] + num[j] < target
此时必有 num[i] + num[j+1] > target 所以才会有 j+1 -1
则 num[i] + num[j+1] > target 所以此时需要仅需要 i++ 
j--的情况也同理
*/

