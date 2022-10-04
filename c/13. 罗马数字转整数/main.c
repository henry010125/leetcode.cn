#include <stdio.h>
#include <string.h>

int single_romanToInt(char C) {
    switch (C) {
        case 'I':
            return 1;
            break;
        case 'V':
            return 5;
            break;
        case 'X':
            return 10;
            break;
        case 'L':
            return 50;
            break;
        case 'C':
            return 100;
            break;
        case 'D':
            return 500;
            break;
        case 'M':
            return 1000;
            break;
    }
    return 0;
}

int romanToInt(char * s){
    int ans = single_romanToInt(s[0]);
    for (int i = 0; i < strlen(s); i++) {
        int a = single_romanToInt(s[i]);
        int b = single_romanToInt(s[i+1]);
        if (b > a) {
            ans -= 2*a;
        }
        ans += b;
    }
    return ans;
}

int main() {
    char* s = "MCMXCIV";
    printf("%d\n",romanToInt(s));
    return 0;
}