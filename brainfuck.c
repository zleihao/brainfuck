#include <stdio.h>
#include <stdint.h>

uint8_t cmd[30000];

void brain_fuck(uint8_t *str, uint32_t size)
{
    uint32_t i = 0;
    uint8_t cnt = 0;
    uint8_t *g_p = &cmd[1500];

    while (i < size) {
        switch (str[i]) {
        case '>':
            g_p++;
            break;
        case '<':
            g_p--;
            break;
        case '+':
            (*g_p)++;
            break;
        case '-':
            (*g_p)--;
            break;
        case '.':
            fputc(*g_p, stdout);
            break;
        case ',':
            *g_p = (char)fgetc(stdin);
            break;
        case '[':
            if (*g_p == 0) {
                cnt = 1;
                while (i < size) {
                    i++;
                    if (str[i] == '[') {
                        cnt++;
                    } else if (str[i] == ']') {
                        cnt--;
                    }
                    if (cnt == 0) {
                        break;
                    }
                }
            }
            break;
        case ']':
            if (*g_p != 0) {
                cnt = 1;
                while (i < size) {
                    i--;
                    if (str[i] == ']') {
                        cnt++;
                    } else if (str[i] == '[') {
                        cnt--;
                    }
                    if (cnt == 0) {
                        break;
                    }
                }
            }
            break;
        default:
            break;
        }

        i++;
    }
    return;
}