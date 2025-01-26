#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

bool isSubsequence(char *s, char *t)
{
    bool res = false;
    int sl = strlen(s);
    int tl = strlen(t);
    
    int ti;
    int si;
    for (ti = 0, si = 0; ti < tl && si < sl; ti++) {
        if (s[si] == t[ti]) {
            si++;
        }
    }
    if (si >= sl) {
        res = true;
    }
    
    return res;
}

int main()
{
    // test1:
    // s = "abc", t = "ahbgdc"
    char s1[] = "abc";
    char t1[] = "ahbgdc";
    printf("%d\n", (int)isSubsequence(s1, t1));

    // test2:
    // s = "axc", t = "ahbgdc"
    char s2[] = "axc";
    char t2[] = "ahbgdc";
    printf("%d\n", (int)isSubsequence(s2, t2));

    // test3:
    // s = "abc", t = "ab"
    char s3[] = "abc";
    char t3[] = "ab";
    printf("%d\n", (int)isSubsequence(s3, t3));

    // test4:
    // s = "", t = "ab"
    char s4[] = "";
    char t4[] = "ab";
    printf("%d\n", (int)isSubsequence(s4, t4));

    return 0;
}