Ques 1.The Fibonacci numbers, commonly denoted F(n) form a sequence, 
called the Fibonacci sequence, such that each number is the sum of the two 
preceding ones, starting from 0 and 1. That is, 
F(0) = 0, F(1) = 1 
F(n) = F(n - 1) + F(n - 2), for n > 1. 
Given n, calculate F(n). 

Program code: 
#include <iostream> 
using namespace std; 
int fibonacci_iterative(int n) { 
if (n == 0) return 0; 
if (n == 1) return 1; 
int a = 0, b = 1, c; 
for (int i = 2; i <= n; ++i) { 
c = a + b; 
a = b; 
b = c; 
} 
return b; 
} 
int main() { 
int n = 2; 
cout << "Fibonacci number F(" << n << ") is " << fibonacci_iterative(n) << 
endl; 
return 0; 
} 
