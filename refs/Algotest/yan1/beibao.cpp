/**
 * @file beibao.cpp
 * @author hellone (hellone@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-03-22
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<iostream>
int main(int argc, char const *argv[])
{
    int n;
    int tasks[n] = {};
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += tasks[i];
    }
    int dp[sum/2] = {0};
    for (int i = 0; i < n; i++)
    {
        if (tasks[i] >= sum/2)  return tasks[i];
        for (int j = 0; j < sum/2; j++)
        {
            dp[j] = dp[j] > tasks[i]
        }
        
    }
    
    return 0;
}
