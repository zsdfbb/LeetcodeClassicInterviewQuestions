#include "../common.h"

int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize)
{
    int size = gasSize;

    // 起始点
    int start = 0;
    // 当前位置
    int ci = 0;
    // 当前油量
    int cgas = 0;
    while (start < size) {
        printf("start: %d\n", start);
        cgas = 0;
        int i = 0;
        for (; i < size; i++) {
            ci = (start + i) % size;
            printf("ci:%d\n", ci);
            cgas = cgas + gas[ci] - cost[ci];
            if (cgas < 0) {
                // 开往i+1加油站失败, 重新寻找起点开始
                start = start + i + 1;
                break;
            }
        }
        if (i == size && cgas >= 0) {
            // 成功, 唯一的
            return start;
        }
    }

    return -1;
}

int main()
{
    // 示例 1:
    // 输入: gas = [1,2,3,4,5], cost = [3,4,5,1,2]
    // 输出: 3
    // 解释:
    // 从 3 号加油站(索引为 3 处)出发，可获得 4 升汽油。此时油箱有 = 0 + 4 = 4 升汽油
    // 开往 4 号加油站，此时油箱有 4 - 1 + 5 = 8 升汽油
    // 开往 0 号加油站，此时油箱有 8 - 2 + 1 = 7 升汽油
    // 开往 1 号加油站，此时油箱有 7 - 3 + 2 = 6 升汽油
    // 开往 2 号加油站，此时油箱有 6 - 4 + 3 = 5 升汽油
    // 开往 3 号加油站，你需要消耗 5 升汽油，正好足够你返回到 3 号加油站。
    // 因此，3 可为起始索引。
    int g1[] = {1,2,3,4,5};
    int c1[] = {3,4,5,1,2};
    int ret = canCompleteCircuit(g1, ARRAY_SIZE(g1), c1, ARRAY_SIZE(c1));
    printf("res: %d\n", ret);

    // 示例 2:
    // 输入: gas = [2,3,4], cost = [3,4,3]
    // 输出: -1
    // 解释:
    // 你不能从 0 号或 1 号加油站出发，因为没有足够的汽油可以让你行驶到下一个加油站。
    // 我们从 2 号加油站出发，可以获得 4 升汽油。 此时油箱有 = 0 + 4 = 4 升汽油
    // 开往 0 号加油站，此时油箱有 4 - 3 + 2 = 3 升汽油
    // 开往 1 号加油站，此时油箱有 3 - 3 + 3 = 3 升汽油
    // 你无法返回 2 号加油站，因为返程需要消耗 4 升汽油，但是你的油箱只有 3 升汽油。
    // 因此，无论怎样，你都不可能绕环路行驶一周。

    int g2[] = {2,3,4};
    int c2[] = {3,4,3};
    ret = canCompleteCircuit(g2, ARRAY_SIZE(g2), c2, ARRAY_SIZE(c2));
    printf("res: %d\n", ret);

}