/******************************************************************************
*
*  Copyright (C), 2001-2022
*
*******************************************************************************
*  File Name     : cmdInfo.h
*  Version       : Initial Draft
*  Author        : lizhiduo
*  Created       : 2018/9/1
*  Last Modified :
*  Description   : cmdInfo.h header file
*
*
*
*  History:
* 
*       1.  Date         : 2018/9/1
*           Author       : lizhiduo
*           Modification : Created file
*
******************************************************************************/
#ifndef __CMDINFO_H__
#define __CMDINFO_H__


/*==============================================*
 *      include header files                    *
 *----------------------------------------------*/
#include "cmdCtl.h"

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */

/*==============================================*
 *      constants or macros define              *
 *----------------------------------------------*/
typedef enum tagCMD_CODES  
{
    TEST_BEGIN = MAKE_CMDC_CODE('A', 0),
    
    GPIO_HIGH = MAKE_CMDC_CODE('G', 0),
    GPIO_LOW = MAKE_CMDC_CODE('G', 1),
    
    SPI_START = MAKE_CMDC_CODE('S', 0),
    SPI_STOP  = MAKE_CMDC_CODE('S', 1),

    TEST_END = MAKE_CMDC_CODE('Z', 9),
} CMD_CODES;
/*==============================================*
 *      project-wide global variables           *
 *----------------------------------------------*/

/*==============================================*
 *      routines' or functions' implementations *
 *----------------------------------------------*/


#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */


#endif /* __CMDINFO_H__ */


