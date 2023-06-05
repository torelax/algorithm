#include <iostream>

int sum(int a[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
       sum += a[i]; 
    }
    return sum;
}

int main(int argc, char const *argv[])
{
    int n = 3, m = 2, N = 8;
    int seq[N] = {5, 11, 2, 5, 11, 2, 5, 11};
    int s = sum(seq, N);
    std::cout << "sum:" << s <<std::endl;
    for(int i=0; i<N; i++) {
        if ((s+(n-m)*seq[i]) % m == 0)
        {
            std::cout << seq[i];
            break;
        }
        
    }
    //std::cout << "Error!";
    return 0;
}
