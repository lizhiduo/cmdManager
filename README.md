# cmdManager

## 修改Mk中的gpio.c 与 spi.c的位置可以改变 spi_init 和 gpio_init初始化顺序

## 自定义lds section
`ld -verbose > sec.lds`获取默认链接脚本
保留分割线“====”中间内容
在bss段上添加如下内容：
```
.initlist :
  {
    __initcall0_start = .;
    *(initcall0)
    __initcall1_start = .;
    *(initcall1)
    __initcall2_start = .;
    *(initcall2)
    __initcall3_start = .;
    *(initcall3)
    __initcall_end = .;
  }
```
