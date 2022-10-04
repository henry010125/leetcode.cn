#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>


int maximumWealth(int** accounts, int accountsSize, int* accountsColSize){
    int answer = 0;
    for (int i = 0; i < accountsSize; i++) {
        int n = 0;
        for (int j = 0; j < *accountsColSize; j++) {
            n += accounts[i][j];
        }
        if (n > answer) {
            answer = n;
        }
    }
    return answer;
}
