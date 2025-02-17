
#include "../common.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char *build_words_line(char **words, int *wordsLenth, int start, int end, int maxWidth)
{
    char* line = calloc(maxWidth + 1, 1);
    int li = 0;
    int gap = end - start;

    int wl_sum = 0;
    for (int i = start; i <= end; i++) {
        wl_sum += wordsLenth[i];
    }

    // 填充的空格
    printf("gap: %d\n", gap);
    int space_count = (gap == 0 ? 0 : (maxWidth - wl_sum) / gap);
    int space_left = (gap == 0 ? 0 : maxWidth - wl_sum) % gap;
    printf("space_count %d  space_left %d\n", space_count, space_left);

    for (int i = start; i <= end; i++) {
        printf("word: %s\n", words[i]);
        printf("li: %d\n", li);
        strcpy(&line[li], words[i]);
        li += wordsLenth[i];
        printf("li: %d\n", li);

        for (int j = 0; j < space_count && li < maxWidth; j++) {
            line[li] = ' ';
            li++;
        }
        printf("li: %d\n", li);

        if (space_left > 0 && li < maxWidth) {
            line[li] = ' ';
            space_left--;
            li++;
        }
        printf("li: %d\n", li);
    }

    return line;
}

 char** fullJustify(char** words, int wordsSize, int maxWidth, int* returnSize)
 {
    char **res = calloc(maxWidth, sizeof(char *));
    int ri = 0;
    int start = 0;
    int end = 0;
    int wl[wordsSize];
    int wl_sum = 0;

    int i = 0;
    start = 0;
    for (i = 0; i < wordsSize; i++) {
        wl[i] = strlen(words[i]);
        wl_sum += wl[i];
        if (wl_sum > maxWidth) {
            wl_sum = wl[i];
            end = i - 1;
            // [start, end] 需要合并成一行
            printf("start:%d end:%d\n", start, end);
            res[ri++] = build_words_line(words, wl, start, end, maxWidth);
            start = i;
        } else {
            // 至少补充一个空格
            wl_sum += 1;
        }
    }

    // 最后一行，不会产生 wl_sum > maxWidth 的情况，因此直接处理 [i, wordsSize -1]即可
    res[ri++] = build_words_line(words, wl, end + 1, wordsSize-1, maxWidth);
    *returnSize = ri;
    return res;
}

int main()
{
    //                  0       1   2       3         4     5       6  序号
    // 输入: words = ["This", "is", "an", "example", "of", "text", "justification."], maxWidth = 16
    //                  4       2   2       7         2     4       14  长度
    // 输出:
    // [
    //    "This    is    an",
    //    "example  of text",
    //    "justification.  "
    // ]
    char *w1[] = {"This", "is", "an", "example", "of", "text", "justification."};
    int res_size = 0;
    char **res = fullJustify(w1, ARRAY_SIZE(w1), 16, &res_size);
    printf("res_size: %d\n", res_size);
    debug_str_info(res,  res_size);


    // 示例 2:
    // 输入:words = ["What","must","be","acknowledgment","shall","be"], maxWidth = 16
    // 输出:
    // [
    // "What   must   be",
    // "acknowledgment  ",
    // "shall be        "
    // ]
    // 解释: 注意最后一行的格式应为 "shall be    " 而不是 "shall     be",
    //     因为最后一行应为左对齐，而不是左右两端对齐。       
    //     第二行同样为左对齐，这是因为这行只包含一个单词。
    char *w2[] = {"What","must","be","acknowledgment","shall","be"};
    res_size = 0;
    char **res2 = fullJustify(w2, ARRAY_SIZE(w2), 16, &res_size);
    debug_str_info(res2,  res_size);


    // 示例 3:
    // 输入:words = ["Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"]，maxWidth = 20
    // 输出:
    // [
    // "Science  is  what we",
    // "understand      well",
    // "enough to explain to",
    // "a  computer.  Art is",
    // "everything  else  we",
    // "do                  "
    // ]


    return 0;
}