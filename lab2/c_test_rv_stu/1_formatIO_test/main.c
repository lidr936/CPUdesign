#include "peripheral.h"

#define LED_BASE  0xFFFF1000
#define DLED_BASE 0xFFFF2000

volatile unsigned int *peri_led    = (volatile unsigned int*) LED_BASE;
volatile unsigned int *peri_digled = (volatile unsigned int*) DLED_BASE;

int main()
{
    uart_init();

    printf("2024311270 Test #1 - Formatted input/output test:\n");
    
    /****** Phase 0 ******/
    printf("<Phase 0> - Formatted output test:\n");
    printf("%d\n0x%x\n%c\n%s\n%f\n", 123, 0x456, 'c', "Hello World!", 98.7654);

    /****** Phase 1 ******/
    printf("\n<Phase 1> - Formatted input test:\n");
    int  input_int;
    char input_ch;
    char input_str[64];
    while (1)
    {
        printf("Enter an integer, a char, and a string (e.g., 123 x hello): \n");
        scanf("%d %c %s", &input_int, &input_ch, input_str);
        printf("Input received: int=%d, char='%c', string=\"%s\"\n", input_int, input_ch, input_str);
        if (input_str[0] == 'e' && input_str[1] == 'n' && input_str[2] == 'd' && input_str[3] == '\0')
        {
            printf("Test ended.");
            break;
        }

        // input_int 是负数时，最低位LED点亮；数码管显示绝对值
        *peri_led    = input_int < 0 ? 1 : 0;
        *peri_digled = input_int < 0 ? -input_int : input_int;
    }

    return 0;
}
