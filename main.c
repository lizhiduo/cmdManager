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

static void sys_init()
{
    init_fn_t *fn;

    for(fn=&__start_init_sec; fn<&__stop_init_sec; fn++){
        (*fn)();
    }
}

int main()
{
    sys_init();

    dispatch_cmds(GPIO_HIGH, 0);
    dispatch_cmds(SPI_START, 0);
    
    return 0;
}
