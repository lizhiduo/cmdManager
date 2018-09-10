/*************************************************************************
	> File Name: main.c
	> Author: 
	> Mail: 
	> Created Time: 2017年12月10日 星期日 13时18分15秒
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>

#include "cmd.h"
#include "common.h"
#include "init.h"

int main()
{
    do_initcalls();

    dispatch_cmds(GPIO_HIGH, 0);
    dispatch_cmds(SPI_START, 0);
    
    return 0;
}

