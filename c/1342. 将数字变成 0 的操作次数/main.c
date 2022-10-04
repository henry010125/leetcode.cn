#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

int numberOfSteps_bybite(int num){
    int cnt = 0;
    while (num != 0) {
        if (num % 2 == 0) {
            num /= 2;
        } else {
            num -= 1;
        }
        cnt++;
    }
    return cnt;
}

int numberOfSteps_bynum(int num){
    int count = 0;
    while(num)
    {
        if(num % 2)
            num ^= 1;
        else
            num >>= 1;
        count++;
    }
    return count;
}