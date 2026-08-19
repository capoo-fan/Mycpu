// 正整数除法

typedef unsigned int uint32_t;
typedef int int32_t;

#define dividend 0x80400000u
#define divisor    0x80700000u
#define RESULT_ADDR  0x80700000u

void div(void)
{
    volatile uint32_t a = *(volatile uint32_t *)dividend; // 读取被除数
    volatile uint32_t b = *(volatile uint32_t *)divisor; // 读取除数

    if(a<b) {
        *(volatile uint32_t *)RESULT_ADDR = 0;
        return;
    }
    uint32_t l = 1;
    uint32_t r = a;
    uint32_t ans;

    while (l<=r) {
        uint32_t mid = l + ((r - l) >> 1);
        uint32_t c=mid*b;
        if(c==a) {
            *(volatile uint32_t *)RESULT_ADDR = mid;
            return;
        }
        if (c <= a) 
        {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    *(volatile uint32_t *)RESULT_ADDR = ans;
}