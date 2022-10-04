#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "../LIBRARY/uthash/uthash.h"


//遍歷數組，時間複雜度O(n^2)
int* twoSum_forloop(int* nums, int numsSize, int target, int* returnSize){
    *returnSize = 0;
    int* ans = malloc(sizeof(int) * 2);
    for (int i = 0; i < numsSize; i++) {
        for (int j = i+1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) { 
                ans[0] = i;
                ans[1] = j;
                *returnSize = 2;
                break;
            }
        }
    }
    return ans;
}


//哈希表，時間複雜度O(n)
struct hash_struct                                                      //聲明hash_struct結構體的長相
{
    int key;
    int value;
    UT_hash_handle hh;
};

struct hash_struct *hash_table = NULL;                                  //建立一個空的結構體"hash_table"

struct hash_struct *find(int ikey) {
    struct hash_struct *s;
    HASH_FIND_INT(hash_table, &ikey, s);
    return s;
}

void add2table(int ikey, int ivalue) {
    struct hash_struct *s = find(ikey);                                              //建立一個暫時的hash_struct結構體"s"
    if (s == NULL) {
        struct hash_struct *tmp = malloc(sizeof(struct hash_struct));
        tmp->key = ikey;
        tmp->value = ivalue;
        HASH_ADD_INT(hash_table,key,tmp);
    } else {
        s->value = ivalue;
    }
}

int* twoSum_hash(int* nums, int numsSize, int target, int* returnSize){
    *returnSize = 0;
    hash_table = NULL;
    int* ans = malloc(sizeof(int) * 2);
    for (int i = 0; i < numsSize; i++) {
        struct hash_struct *s = find(target - nums[i]);
        if (s !=NULL) {
            ans[0] = s->value;
            ans[1] = i;
            *returnSize = 2;
            return ans;
        }
        add2table(nums[i], i);
    }
    return NULL;
}