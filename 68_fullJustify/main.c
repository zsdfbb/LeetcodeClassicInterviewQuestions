
#include "../common.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char *build_words_line(char **words, int *wordsLenth, int start, int end, int maxWidth, int lastline)
{
    // 保存本行的单词
    char* line = calloc(maxWidth + 1, 1);
    int li = 0;

    // 是最后一行
    if (lastline) {
        for (int i = start; i <= end; i++) {
            //printf("words[%d]: %s\n", i, words[i]);
            // 单词一定在line内
            strcpy(&line[li], words[i]);
            li += wordsLenth[i];
            // space可能不在
            if (li < maxWidth) {
                line[li++] = ' ';
            }
        }
        while (li < maxWidth) {
            line[li++] = ' ';
        }
        return line;
    }

    // 不是最后一行
    // 只有一个单词
    if (end == start) {
        strcpy(&line[li], words[start]);
        li += wordsLenth[start];
        while (li < maxWidth) {
            line[li++] = ' ';
        }
        //printf("line: %s\n", line);
        return line;
    }

    // 多个单词
    int wc = end - start;
    int wl = 0;
    for (int i = start; i <= end; i++) {
        wl += wordsLenth[i];
    }

    int space_normal = (maxWidth - wl) / (wc);
    int space_extra = (maxWidth - wl) % (wc);
    //printf("wl:%d space_normal: %d, space_extra:%d\n", wl, space_normal, space_extra);
    for (int i = start; i <= end; i++) {
        //printf("words: %s\n", words[i]);
        strcpy(&line[li], words[i]);
        li += wordsLenth[i];

        for (int j = 0; i < end && j < space_normal; j++) {
            line[li++] = ' ';
        }

        if (space_extra > 0) {
            line[li++] = ' ';
            space_extra--;
        }
    }

    return line;
}

 char** fullJustify(char** words, int wordsSize, int maxWidth, int* returnSize)
 {
    // 存放结果
    char **res = calloc(wordsSize + 1, sizeof(char *));
    int ri = 0;

    // 计算每一个word的长度，方便后面统计每行的长度
    int wl[wordsSize];
    for (int i = 0; i < wordsSize; i++) {
        wl[i] = strlen(words[i]);
    }

    // 统计每一行的单词数，是否为最后一行
    int start = 0;
    int end = 0;
    int tmp_width = 0;
    while(end < wordsSize) {
        //printf("=========\n");
        //printf("start:%d end:%d\n", start, end);
        while (end < wordsSize) {
            // 加上 新单词长度和空格数量
            int new_width = tmp_width + wl[end] + (end - start);
            // 产生跨行，结束
            //printf("newwitdth:%d, wl[%d]:%d \n", new_width, end, wl[end]);
            if (new_width > maxWidth) {
                // end属于下一行
                break;
            }
            // 没有产生跨行, 继续
            tmp_width += wl[end];
            end++;
        }
        // [start, end) 是同一行的单词
        //printf("start:%d end:%d\n", start, end);
        
        // 最后一行, 每个单词只需要单空格间距输出即可
        if (end >= wordsSize) {
            //printf("lastline\n");
            res[ri++] = build_words_line(words, wl, start, end-1, maxWidth, 1);
            *returnSize = ri;
            return res;
        }

        // 不是最后一行, 统计空格单词数和空格数
        //printf("Not lastline\n");
        res[ri++] = build_words_line(words, wl, start, end-1, maxWidth, 0);

        // restart
        start = end;
        tmp_width = 0;
    }
    return res; 
}

void freelines(char **res, int resSize)
{
    for (int i = 0; i < resSize; i++) {
        free(res[i]);
    }
    free(res);
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
    //printf("\n示例 1:\n");
    char *w1[] = {"This", "is", "an", "example", "of", "text", "justification."};
    int res_size = 0;
    char **res = fullJustify(w1, ARRAY_SIZE(w1), 16, &res_size);
    //printf("res_size: %d\n", res_size);
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
    //printf("\n示例 2:\n");
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
    //printf("\n示例 3:\n");
    char *w3[] = {"Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"};
    res_size = 0;
    char **res3 = fullJustify(w3, ARRAY_SIZE(w3), 20, &res_size);
    debug_str_info(res3,  res_size);

    // 示例 4:
    // ["a","b","c","d","e"]
    // 1
    //printf("\n示例 4:\n");
    char *w4[] = {"a","b","c","d","e"};
    res_size = 0;
    char **res4 = fullJustify(w4, ARRAY_SIZE(w4), 1, &res_size);
    debug_str_info(res4,  res_size);

    // 示例 5:
    // ["a","b","c","d","e"]
    // 1
    //printf("\n示例 5:\n");
    char *w5[] = {"a","b","c","d","e"};
    res_size = 0;
    char **res5 = fullJustify(w5, ARRAY_SIZE(w5), 3, &res_size);
    debug_str_info(res5,  res_size);

    return 0;
}