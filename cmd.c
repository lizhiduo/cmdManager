/*************************************************************************
	> File Name: cmd.c
	> Author: 
	> Mail: 
	> Created Time: 2017年12月10日 星期日 10时41分12秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>

#include "cmd.h"

typedef struct tagCMD_INFO
{
    CMD cmds[MAX_CMD_CNT * CMD_BASE];
    int count;
}CMD_INFO, *PCMD_INFO;

static CMD_INFO gCmd;


int register_cmds(CMD cmds[], int num){
    int i = 0;
    int code = 0;
    int cmdIndex = 0;
    PCMD_INFO pobj = &gCmd;

    if (0 == cmds || num <=0)
    {
        printf("no cmd..\n");
        return -1;
    }

    for (i = 0; i < num; ++i)
    {
        code = cmds[i].cmdCode;
        cmdIndex = GET_CMD_INDEX(code);
        pobj->cmds[cmdIndex].cmdCode = code;
        pobj->cmds[cmdIndex].func = cmds[i].func;
        pobj->count++;
    }
    
    return 0; 
}

int dispatch_cmds(CMD_CODES cmdCode, void *args){
    int cmdIdx     = 0;
    PCMD_INFO pobj = &gCmd;
    
    cmdIdx = GET_CMD_INDEX(cmdCode);
    if (0 == pobj->cmds[cmdIdx].func)
    {
        printf("Dont support this cmd..\n");
        return -1;
    }
    pobj->cmds[cmdIdx].func(args); 
    
    return 0;
}

