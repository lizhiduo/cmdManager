/*************************************************************************
	> File Name: gpio.c
	> Author: 
	> Mail: 
	> Created Time: 2017年12月10日 星期日 12时31分27秒
 ************************************************************************/

#include<stdio.h>

#include "cmd.h"
#include "common.h"
#include "init.h"

static int gpio_high(){
    
    printf("[%s][%s][%d]\n", __FILE__, __func__, __LINE__);
    
    return 0;
}

static int gpio_low(){
    
    printf("[%s][%s][%d]\n", __FILE__, __func__, __LINE__);

    return 0;
}

CMD gpio_cmds[] = {
    {GPIO_HIGH, gpio_high},
    {GPIO_LOW, gpio_low},
};

void gpio_init(){
    printf("[%s][%s]\n", __FILE__, __func__);
    register_cmds(gpio_cmds, ARRAY_SIZE(gpio_cmds)); 
}

DECLARE_INIT(gpio_init);

