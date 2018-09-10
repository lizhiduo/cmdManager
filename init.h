/*************************************************************************
	> File Name: init.h
	> Author: 
	> Mail: 
	> Created Time: 2017年12月10日 星期日 15时47分30秒
 ************************************************************************/

#ifndef _INIT_H
#define _INIT_H

#define CALLBACK
typedef void (CALLBACK *init_fn_t)(void);


#ifndef ARRAY_SIZE
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))
#endif

#ifndef NULL
#define NULL ((void *) 0) 
#endif

#define __initcall(fn, id) \
    static init_fn_t __initcall_##fn##id \
    __attribute__((unused, __section__("initcall" #id))) = fn


#define DECLARE_INIT0(func) __initcall(func, 0) 
#define DECLARE_INIT1(func) __initcall(func, 1)
#define DECLARE_INIT2(func) __initcall(func, 2)
#define DECLARE_INIT3(func) __initcall(func, 3)


void do_initcalls(void);


#endif

