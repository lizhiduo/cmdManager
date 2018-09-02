/******************************************************************************
*
*  Copyright (C), 2001-2022
*
*******************************************************************************
*  File Name     : cmdCtl.h
*  Version       : Initial Draft
*  Author        : lizhiduo
*  Created       : 2018/9/2
*  Last Modified :
*  Description   : cmdInfo.h header file
*    cmdCode的大小为 32位，共分 4 个域：
*    bit31~bit30 2位为 “区别读写” 区。
*    bit29~bit16 14位为 "数据大小" 区，表示 runCmd() 中的 arg 变量传送的内存大小。
*    bit15~bit08 8位为 “魔数"(也称为"幻数")区，区别不同模块。
*    bit07~bit00 8位为 "区别序号" 区，是区分命令的命令顺序序号。
*
*
*  History:
* 
*       1.  Date         : 2018/9/2
*           Author       : lizhiduo
*           Modification : Created file
*
******************************************************************************/
#ifndef __CMDCTL_H__
#define __CMDCTL_H__

/*==============================================*
 *      include header files                    *
 *----------------------------------------------*/


#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */

/*==============================================*
 *      constants or macros define              *
 *----------------------------------------------*/
#define CMDC_NR_BITS   (8)
#define CMDC_TYPE_BITS (8)
#define CMDC_SIZE_BITS (14)
#define CMDC_DIR_BITS  (2)
    
#define CMDC_NR_SHIFT   (0) 
#define CMDC_TYPE_SHIFT (CMDC_NR_SHIFT + CMDC_NR_BITS)
#define CMDC_SIZE_SHIFT (CMDC_TYPE_SHIFT + CMDC_TYPE_BITS)
#define CMDC_DIR_SHIFT  (CMDC_SIZE_SHIFT + CMDC_SIZE_BITS) 
    
#define CMDC_NR_MASK   ((1 << CMDC_NR_BITS) - 1)
#define CMDC_TYPE_MASK ((1 << CMDC_TYPE_BITS) - 1)
#define CMDC_SIZE_MASK ((1 << CMDC_SIZE_BITS) - 1)
#define CMDC_DIR_MASK  ((1 << CMDC_DIR_BITS) - 1)
    
    
#define CMDC_NONE  (0)
#define CMDC_READ  (1U)
#define CMDC_WRITE (2U)
    
    
    
#define CMDC(dir, type, nr, size) \
               (((dir & CMDC_DIR_MASK)  << CMDC_DIR_SHIFT) | \
               ((type & CMDC_TYPE_MASK) << CMDC_TYPE_SHIFT) | \
               ((nr & CMDC_NR_MASK) << CMDC_NR_SHIFT) | \
               ((size & CMDC_SIZE_MASK) << CMDC_SIZE_SHIFT))
    
/* use to create code number.. */
#define MAKE_CMDC_CODE(type, nr) CMDC(CMDC_NONE, (type), (nr), 0)
#define MAKE_CMDC_W_CODE(type, nr, size) CMDC(CMDC_WRITE, (type), (nr), sizeof(size))
#define MAKE_CMDC_R_CODE(type, nr, size) CMDC(CMDC_READ, (type), (nr), sizeof(size))
    
/* used to decode cmdctl numbers.. */                                                      
#define CMDC_GET_DIR(nr)  (((nr) >> CMDC_DIR_SHIFT) & CMDC_DIR_MASK)
#define CMDC_GET_TYPE(nr) (((nr) >> CMDC_TYPE_SHIFT) & CMDC_TYPE_MASK)
#define CMDC_GET_NR(nr)   (((nr) >> CMDC_NR_SHIFT) & CMDC_NR_MASK)
#define CMDC_GET_SIZE(nr) (((nr) >> CMDC_SIZE_SHIFT) & CMDC_SIZE_MASK)


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


#endif /* __CMDCTL_H__ */
