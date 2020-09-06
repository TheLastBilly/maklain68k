#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define USAGE "needs to arguments [b/d/h] [value]\n"

static inline size_t ipow(size_t base, size_t power)
{
    size_t rst = 1;
    for(size_t i = 0; i < power; i++)
        rst *= base;
    return rst;
}

static inline char * lutobin(size_t lu)
{
    size_t index = 0;
    char * rst = (char *)calloc(sizeof(char) * sizeof(size_t) * 8, 1);
    for(size_t i = (~(size_t)0)/2 + 1; i > 0; i /= 2)
    {
        rst[index++] = i&lu ? '1' : '0';
    }
    return rst;
}

int main(int argc, char const *argv[])
{
    if(argc != 3)
    {
        printf(USAGE);    
        return 1;
    }
    
    char opt = argv[1][0]; 
    size_t rst = 0, str_s;
    char *bstr = NULL;
    
    switch(opt)
    {
        case 'b':
            str_s = strlen(argv[2])-1;
            for(int i = str_s; i > 0; i--)
            {
                if(argv[2][i] == '1')
                    rst += ipow(2, str_s - i);
            }
            printf("decimal: %lu\nhexadecimal: 0x%lX\n", rst, rst);
            break;

        case 'h':
            str_s = strlen(argv[2])-1;
            for(int i = str_s; i > 0; i--)
            {
                if(argv[2][i] >= 'a' && argv[2][i] <= 'f')
                    rst += ipow(16, str_s - i) * (argv[2][i] - 87);
                else if(argv[2][i] >= '0' && argv[2][i] <= '9')
                    rst += ipow(16, str_s - i) * (argv[2][i] - 48);
                else
                {
                    printf("\"%s\" is not a hexadecimal number.", argv[2]);
                    return 1;
                }
            }
            bstr = lutobin(rst);
            printf("decimal: %lu\nbinary:%s\n", rst, bstr);
            free(bstr);
            break;
        case 'd':
            str_s = strlen(argv[2])-1;
            for(int i = str_s; i > 0; i--)
            {
                if(argv[2][i] >= '0' && argv[2][i] <= '9')
                    rst += ipow(10, str_s - i) * (argv[2][i] - 48);
                else
                {
                    printf("\"%s\" is not a decimal number.", argv[2]);
                    return 1;
                }
            }
            bstr = lutobin(rst);
            printf("binary: %s\nhexadecimal: 0x%lX\n", bstr, rst);
            free(bstr);
            break;
        default:
            printf(USAGE);    
            return 1;
    }

    return 0;
}
