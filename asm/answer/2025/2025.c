typedef unsigned int uint32_t;

#define ARRAY_BEGIN  0x80400000u
#define ARRAY_END    0x80700000u
#define RESULT_ADDR  0x80700000u

void count_first(void)
{
    volatile uint32_t *p = (volatile uint32_t *)ARRAY_BEGIN;

    const uint32_t key = p[0];

    uint32_t c0 = 0;
    uint32_t c1 = 0;
    uint32_t c2 = 0;
    uint32_t c3 = 0;

    while ((uint32_t)p != ARRAY_END) {
        c0 += (p[0] == key);
        c1 += (p[1] == key);
        c2 += (p[2] == key);
        c3 += (p[3] == key);

        c0 += (p[4] == key);
        c1 += (p[5] == key);
        c2 += (p[6] == key);
        c3 += (p[7] == key);

        p += 8;
    }

    uint32_t count = c0 + c1 + c2 + c3;

    *(volatile uint32_t *)RESULT_ADDR = count;
}