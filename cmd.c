/*************************************************************************
	> File Name: cmd.c
	> Author: 
	> Mail: 
	> Created Time: 2017年12月10日 星期日 10时41分12秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>

#include "cmd.h"


int register_cmds(CMD cmds[], int num){
    int i = 0;

    if(num>0 || (num + gCmd.count)<MAX_CMD_CNT){
        memcpy((unsigned char*)&gCmd.cmds[gCmd.count], (unsigned char*)cmds, sizeof(CMD)*num);
        gCmd.count += num;
    }

    return 0; 
}

int dispatch_cmds(CMDCODE cmdCode){
    int i = 0;

    for(i=0; i<gCmd.count; i++){
        if(gCmd.cmds[i].cmdCode == cmdCode){
            gCmd.cmds[i].func();
        }
    }

    return 0;
}

