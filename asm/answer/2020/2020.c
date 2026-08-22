// include <stdio.h>
typedef unsigned int uint32_t;

#define RESULT_ADDR 0x80700000u

void count(void)
{
    uint32_t n = 200977;

    uint32_t i = 1;
    uint32_t ans=0;
    for (i = 1; i <= n; i++)
    {
        uint32_t j=i;
        while (j != 0)
        {
            if ((j & 1) != 0)
                ans++;

            j=j>>1;
        }
    }
    *(volatile uint32_t *)RESULT_ADDR = ans;
}