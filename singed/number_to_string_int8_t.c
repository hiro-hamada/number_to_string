#include <stdint.h>
#include <stdio.h>
#include "number_to_string_int8_t.h"


/* Prototype of function */
static char *process_100(int8_t num, int *p_flag, char *p_str);
static char *process_10(int8_t num, int *p_flag, char *p_str);
static char *process_1(int8_t num, int *p_flag, char *p_str);


/*=====================================================
 * int8_t用数値<=>文字列変換
 * int8_t (-128 ~ 127)
 *===================================================*/
char *number_to_string_int8_t(int8_t num)
{
    static char str[5];
    int  flag = 0;
    char *p_error_message = "number size is over";

    /* num == -128 process */
    if(num == INT8_T_MINIMUM)
    {
        str[0] = '-';
        str[1] = '1';
        str[2] = '2';
        str[3] = '8';
        str[4] = '\0';
        
        return str;
    }

    /* For negative number process */
    if(num < 0)
    {
        str[flag] = '-';
        flag++;
        num *= (-1);     // 128はint8_tでは受け取れないので-128はダメ
    }

    /* converting process */
    if(MIN_100 <= num && num <= MAX_100)
    {
        return process_100(num, &flag, str);
    }
    else if(MIN_10 <= num && num <= MAX_10)
    {
        return process_10(num, &flag, str);
    }
    else if(MIN_1 <= num && num <= MAX_1)
    {
        return process_1(num, &flag, str);
    }
    else
    {
        return p_error_message;
    }
}


/*-----------------------------------------------------
 * 100の位を文字へ
 *---------------------------------------------------*/
static char *process_100(int8_t num, int *p_flag, char *p_str)
{
    int8_t remainder_100 = num % 100;
    
    p_str[*p_flag] = ASCII_NUMBER_0 + 1;
    (*p_flag)++;
    
    return process_10(remainder_100, p_flag, p_str);
}


/*-----------------------------------------------------
 * 10の位を文字へ
 *---------------------------------------------------*/
static char *process_10(int8_t num, int *p_flag, char *p_str)
{
    int    divide_10    = (int)(num / 10);
    int8_t remainder_10 = num % 10;
    char   val          = ASCII_NUMBER_0;
    int    i;
    
    for(i = 0; i < divide_10; i++)
    {
        val++;
    }
    
    p_str[*p_flag] = val;
    (*p_flag)++;
    
    return process_1(remainder_10, p_flag, p_str);
}


/*-----------------------------------------------------
 * 1の位を文字へ
 *---------------------------------------------------*/
static char *process_1(int8_t num, int *p_flag, char *p_str)
{
    int  divide_1 = (int)num;
    char val      = ASCII_NUMBER_0;
    int  i;
    
    for(i = 0; i < divide_1; i++)
    {
        val++;
    }
    
    p_str[*p_flag] = val;
    (*p_flag)++;
    
    p_str[*p_flag] = '\0';
        
    return p_str;
}
