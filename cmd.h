/*************************************************************************
	> File Name: cmd.h
	> Author: 
	> Mail: 
	> Created Time: 2017年12月10日 星期日 10时41分20秒
 ************************************************************************/

#ifndef _CMD_H
#define _CMD_H

#include "common.h"
#include "cmdCtl.h"
#include "cmdInfo.h"

#define CALLBACK
#define INDEX_BASE (65)
#define MAX_CMD_CNT (10)
#define CMD_BASE    (26)

#define GET_CMD_INDEX(code) \
        (((CMDC_GET_TYPE(code) - INDEX_BASE)) * MAX_CMD_CNT) \
         + CMDC_GET_NR(code)

typedef int (CALLBACK *CMD_EXE) (void *);

typedef struct tagCMD
{
    CMD_CODES cmdCode;
    CMD_EXE func;
}CMD;


int register_cmds(CMD cmds[], int num);
int dispatch_cmds(CMD_CODES cmdCode, void *args);

#endif
