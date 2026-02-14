#include<stdio.h>

int fib(int n){

    if (n<=1)
        return n;
    else
        return fib(n-1)+fib(n-2);

}

int main(){

    int num = 5;
    // int output = fib(num);
    printf("%d\n", fib(num));

    return 0;
}