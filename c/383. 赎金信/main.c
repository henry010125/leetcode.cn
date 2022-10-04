#include <stdio.h>
#include <string.h>
#include <stdbool.h>


bool canConstruct(char * ransomNote, char * magazine);

int main(){
    char* ransomNote = "z";
    char* magazine = "ab";
    if (canConstruct(ransomNote, magazine)){
        printf("TRUE\n");
    } else {
        printf("FALSE\n");
    };
    return 0;
}

bool canConstruct(char * ransomNote, char * magazine){
    int x = strlen(magazine);
    int y = strlen(ransomNote);
    
    if (x < y){
        return false;
    }
    int ransomNote_cha_list[30] = {0};
    int magazine_cha_list[30] = {0};
    for(int i = 0; i < y; i++){
        ransomNote_cha_list[(ransomNote[i])-'a'] += 1;
    }
    for(int i = 0; i < x; i++){
        magazine_cha_list[(magazine[i])-'a'] += 1;
    }
    for (int i = 0; i < 30; i++){
        if (ransomNote_cha_list[i] > magazine_cha_list[i]){
            return false;
        }
    }
    return true;
}
