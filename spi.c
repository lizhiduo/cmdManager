/*************************************************************************
	> File Name: spi.c
	> Author: 
	> Mail: 
	> Created Time: 2017年12月10日 星期日 14时28分30秒
 ************************************************************************/

#include<stdio.h>

#include "cmd.h"
#include "common.h"
#include "init.h"

static int spi_start(){
    
    printf("[%s][%s][%d]\n", __FILE__, __func__, __LINE__);
    
    return 0;
}

static int spi_stop(){
    
    printf("[%s][%s][%d]\n", __FILE__, __func__, __LINE__);

    return 0;
}

CMD spi_cmds[] = {
    {SPI_START, spi_start},
    {SPI_STOP, spi_stop},
};

void spi_init(){
   register_cmds(spi_cmds, ARRAY_SIZE(spi_cmds)); 
}

DECLARE_INIT(spi_init);

