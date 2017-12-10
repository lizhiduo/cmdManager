/*************************************************************************
	> File Name: cmd.h
	> Author: 
	> Mail: 
	> Created Time: 2017年12月10日 星期日 10时41分20秒
 ************************************************************************/

#ifndef _CMD_H
#define _CMD_H

#include "common.h"

#define MAX_CMD_CNT 10

typedef struct tag_cmd{
    CMDCODE cmdCode;
    int (*func)();
}CMD;


typedef struct tag_cmdInfo{
    CMD cmds[MAX_CMD_CNT];
    int count;
}CMDINFO;

CMDINFO gCmd;

int register_cmds(CMD cmds[], int num);
int dispatch_cmds(CMDCODE cmdCode);

#endif
