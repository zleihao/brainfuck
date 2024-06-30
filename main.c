#include <stdio.h>
#include <stdlib.h>
#include "stdint.h"

extern void brain_fuck(uint8_t *str, uint32_t size);

int main(int argv, char *argc[])
{
    uint32_t size;
    uint8_t *buffer = NULL;

    if (argv != 2) {
        perror("输入参数过少");
        return -1;
    }

    FILE *fp = fopen(argc[1], "rb");
    if (NULL == fp) {
        perror("打开失败");
        return -1;
    }

    fseek(fp, 0, SEEK_END);
    size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    buffer = (uint8_t *)malloc(sizeof(uint8_t) * (size + 1));

    if (fread(buffer, 1, 2048, fp) != size) {
        printf("读取失败\n");
        free(buffer);
        return -1;
    }

    brain_fuck(buffer, size);
    free(buffer);

    return 0;
}