/*************************************************************************
	> File Name: main.c
	> Author: 
	> Mail: 
	> Created Time: 2017年12月10日 星期日 13时18分15秒
 ************************************************************************/

#include<stdio.h>

#include "cmd.h"
#include "common.h"

extern void gpio_init();
extern void spi_init();

int main(){
   
    gpio_init();
    spi_init();

    dispatch_cmds(GPIO_HIGH);
    dispatch_cmds(SPI_START);
    
    return 0;
}
