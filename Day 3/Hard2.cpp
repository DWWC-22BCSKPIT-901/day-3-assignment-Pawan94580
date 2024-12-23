Ques 5. Given a string s representing a valid expression, implement a basic 
calculator to evaluate it, and return the result of the evaluation. 
Note: You are not allowed to use any built-in function which evaluates 
strings as mathematical expressions, such as eval(). 

Program Code: 
#include <iostream> 
#include <stack> 
#include <string> 
 
int calculate(std::string s) { 
    std::stack<int> nums; 
    std::stack<char> ops; 
    int num = 0; 
    int result = 0; 
    int sign = 1; 
 
    for (int i = 0; i < s.length(); ++i) { 
        char ch = s[i]; 
        if (isdigit(ch)) { 
            num = num * 10 + (ch - '0'); 
        } else if (ch == '+' || ch == '-') { 
            result += sign * num; 
            num = 0; 
            sign = (ch == '+') ? 1 : -1; 
        } else if (ch == '(') { 
            nums.push(result); 
            ops.push(sign); 
            result = 0; 
            sign = 1; 
        } else if (ch == ')') { 
            result += sign * num; 
            num = 0; 
            result *= ops.top(); ops.pop(); 
            result += nums.top(); nums.pop(); 
        } 
} 
result += sign * num; 
return result; 
} 
int main() { 
std::string s = "1 + 1"; 
std::cout << "Result: " << calculate(s) << std::endl; 
s = "(1+(4+5+2)-3)+(6+8)"; 
std::cout << "Result: " << calculate(s) << std::endl; 
return 0; 
}
