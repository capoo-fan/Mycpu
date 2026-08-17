typedef unsigned int uint32_t;

#define ARRAY_BEGIN  0x80400000u
#define ARRAY_END    0x80700000u
#define RESULT_ADDR  0x80700000u

void count_first(void)
{
    volatile uint32_t *p = (volatile uint32_t *)ARRAY_BEGIN;

    uint32_t key = 0;

    uint32_t c0 = 0;
    uint32_t c1 = 0;
    uint32_t c2 = 0;
    uint32_t c3 = 0;

    while ((uint32_t)p != ARRAY_END) {
        c0=p[0];
        c1=p[1];
        c2=p[2];
        c3=p[3];

        if(c0>key) key=c0;
        if(c1>key) key=c1;
        if(c2>key) key=c2;
        if(c3>key) key=c3;

        p += 4;
    }

    *(volatile uint32_t *)RESULT_ADDR = key;
}