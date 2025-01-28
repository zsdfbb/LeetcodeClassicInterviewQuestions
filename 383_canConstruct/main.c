#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

bool canConstruct(char* ransomNote, char* magazine)
{
    bool res = false;
    unsigned int dict[512] = {0};
    int rl = strlen(ransomNote);
    int ml = strlen(magazine);

    for (int i = 0; i < rl; i++) {
        dict[ransomNote[i]] += 1;
    }

    for (int i = 0; i < ml; i++) {
        char c = magazine[i];
        if (dict[c] > 0) {
            dict[c] -= 1;
        }
    }

    int sum = 0;
    for (int i = 0; i < 512; i++) {
        sum += dict[i];
    }

    // printf("sum: %d\n", sum);
    if (sum == 0) {
        res = true;
    }
    return res;
}

int main()
{
    // 示例 1：
    // 输入：ransomNote = "a", magazine = "b"
    // 输出：false
    char ransomNote1[] = "a";
    char magazine1[] = "b";
    printf("%d\n", canConstruct(ransomNote1, magazine1));

    // 示例 2：
    // 输入：ransomNote = "aa", magazine = "ab"
    // 输出：false
    char ransomNote2[] = "aa";
    char magazine2[] = "ab";
    printf("%d\n", canConstruct(ransomNote2, magazine2));

    // 示例 3：
    // 输入：ransomNote = "aa", magazine = "aab"
    // 输出：true
    char ransomNote3[] = "aa";
    char magazine3[] = "aab";
    printf("%d\n", canConstruct(ransomNote3, magazine3));

    return 0;
}