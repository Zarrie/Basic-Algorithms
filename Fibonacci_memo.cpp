#include <stdio.h>
#define MAXN 200

unsigned long long memo[MAXN] = {0};

unsigned long long fibonacci_memo(unsigned long num){
    if (memo[num] != 0) return memo[num];
    if (num == 0) return 0;
    if (num == 1) return 1;
    memo[num] = fibonacci_memo(num - 1) + fibonacci_memo(num - 2);
    return memo[num];
}

unsigned long long fibonacci_(unsigned long num){
    if (num == 0) return 0;
    if (num == 1) return 1;

    return fibonacci_(num - 1) + fibonacci_(num - 2);
}

int main()
{
    printf("%d ", fibonacci_memo(100));
    printf("%d ", fibonacci_(100));

    return 0;
}
