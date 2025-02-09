#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>


#include "../common.h"
#include "../uthash/uthash.h"

#define MAX_SIZE 100001

struct element {
    int val;        // key

    UT_hash_handle hh;
};

typedef struct {
    // 预先申请的资源
    struct element *element_array;
    // hash表实现快速操作
    struct element *element_htable;
    // 元素计数
    int count;
} RandomizedSet;


RandomizedSet* randomizedSetCreate() {
    RandomizedSet *rs = malloc(sizeof(RandomizedSet));
    rs->element_array = malloc(sizeof(struct element) * MAX_SIZE);
    rs->element_htable = NULL;
    rs->count = 0;
}

bool randomizedSetInsert(RandomizedSet* obj, int val) {
    
}

bool randomizedSetRemove(RandomizedSet* obj, int val) {
    
}

int randomizedSetGetRandom(RandomizedSet* obj) {
    
}

void randomizedSetFree(RandomizedSet* obj) {
    
}

/**
 * Your RandomizedSet struct will be instantiated and called as such:
 * RandomizedSet* obj = randomizedSetCreate();
 * bool param_1 = randomizedSetInsert(obj, val);
 
 * bool param_2 = randomizedSetRemove(obj, val);
 
 * int param_3 = randomizedSetGetRandom(obj);
 
 * randomizedSetFree(obj);
*/

int main()
{
    // 示例：
    // 输入
    // ["RandomizedSet", "insert", "remove", "insert", "getRandom", "remove", "insert", "getRandom"]
    // [[], [1], [2], [2], [], [1], [2], []]
    // 输出
    // [null, true, false, true, 2, true, false, 2]
    // 解释
    // RandomizedSet randomizedSet = new RandomizedSet();
    // randomizedSet.insert(1); // 向集合中插入 1 。返回 true 表示 1 被成功地插入。
    // randomizedSet.remove(2); // 返回 false ，表示集合中不存在 2 。
    // randomizedSet.insert(2); // 向集合中插入 2 。返回 true 。集合现在包含 [1,2] 。
    // randomizedSet.getRandom(); // getRandom 应随机返回 1 或 2 。
    // randomizedSet.remove(1); // 从集合中移除 1 ，返回 true 。集合现在包含 [2] 。
    // randomizedSet.insert(2); // 2 已在集合中，所以返回 false 。
    // randomizedSet.getRandom(); // 由于 2 是集合中唯一的数字，getRandom 总是返回 2 。

    return 0;
}