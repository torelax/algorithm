/**
 * @file yunmei.cpp
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
    int upl = 1000, dis = 1000, sum = 3000;
    // 第一次将所有的资源依次运送到下个补给站，每次装满出发
    while (sum > upl)
    {
        int times = sum / upl * 2 - 1;
        dis -= upl/times;
        std::cout << "one step far from " << dis << " meters" << std::endl;
        sum -= upl;
    }
    std::cout << sum - dis;
    return 0;
}
