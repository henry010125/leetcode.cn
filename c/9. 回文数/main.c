#include <stdbool.h>

int digits10(int x) {
    int num = 1;
    while (x > 9) {
        x /= 10;
        num++;
    }
    return num;
}

int reverse(int x) {
    int digits = digits10(x);
    int ans = 0;
    while (digits > 0) {
        digits--;
        ans = ans + (x % 10) * pow(10,digits);
        x /= 10;
    }
    return ans;
}


bool isPalindrome(int x){
    if (x < 0 || x != reverse(x)) {
        return false;
    }
    return true;
}