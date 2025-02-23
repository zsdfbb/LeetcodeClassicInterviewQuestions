#include "../common.h"

#include "stdbool.h"

bool isIsomorphic(char* s, char* t)
{
    int smap[512];
    int tmap[512];
    for (int i = 0; i < sizeof(smap)/sizeof(int); i++) {
        smap[i] = -1;
        tmap[i] = -1;
    }
    
    while (*s != '\0' && *t != '\0') {
        if (smap[*s] == -1) {
            smap[*s] = *t;
        } else {
            if (smap[*s] != *t) {
                return false;
            }
        }

        if (tmap[*t] == -1) {
            tmap[*t] = *s;
        } else {
            if (tmap[*t] != *s) {
                return false;
            }
        }

        s++;
        t++;
    }
    return true;
}

int main()
{

    // 示例 1:
    // 输入：s = "egg", t = "add"
    // 输出：true
    printf("%d\n", isIsomorphic("egg", "add"));

    // 示例 2：
    // 输入：s = "foo", t = "bar"
    // 输出：false
    printf("%d\n", isIsomorphic("foo", "bar"));

    // 示例 3：
    // 输入：s = "paper", t = "title"
    // 输出：true
    printf("%d\n", isIsomorphic("paper", "title"));


    printf("%d\n", isIsomorphic("badc", "baba"));

    return 0;
}