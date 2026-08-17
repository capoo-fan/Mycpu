typedef unsigned int uint32_t;
typedef int int32_t;

#define array_begin 0x80400000u
#define array_end 0x80500000u
#define result_strt 0x80500000u
#define result_end 0x80600000u

void sqrt(void)
{
    volatile uint32_t *p = (volatile uint32_t *)ARRAY_BEGIN;
    volatile uint32_t *result = (volatile uint32_t *)ARRAY_BEGIN;

    while ((uint32_t)p != array_end)
    {
        uint32_t num = *p;
        uint32_t l = 1;
        uint32_t r = num;
        uint32_t ans= min(num, 65535);


        while (l <= r)
        {
            int mid = l + (r - l)>>1;

            if (mid * mid <= num)
            {
                ans = mid; // 当前满足条件
                l = mid + 1;  // 尝试找更大的
            }
            else
            {
                r = mid - 1;
            }
        }
        result[0] = ans;
        p++;
        result++;
    }
}