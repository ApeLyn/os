
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                            global.c
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                                          杜盛瑀 林昌盛 叶坤宇
                                                         2015年7月
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

#define GLOBAL_VARIABLES_HERE

#include "type.h"
#include "const.h"
#include "protect.h"
#include "proc.h"
#include "tty.h"
#include "console.h"
#include "global.h"
#include "proto.h"
#include "keyboard.h"

PUBLIC PROCESS proc_table[MAX_TASKS_PROCS];

PUBLIC TASK task_whole_list[] =	
{
	//函数入口地址,进程名,是否任务,对应的tty,优先级
	{NewCreate,"UserProcess  ",FALSE,3,0},//显示新创建的系统进程
	{task_tty,"IO-Main      ",TRUE,0,15},//多控制台
	{Begin,"Begin        ",TRUE,0,10},//系统开始后运行的主程序
	{FiveinaRow,"FiveinaRow   ",FALSE,1,5 },//五子棋游戏
	{ManageProcess,"ManageProcess",TRUE,2,10},//管理进程
	{NewCreate2,"SysProcess   ",TRUE,3,10},//显示新创建的用户进程
        {Play,"Play         ",FALSE,3,10}//模拟屏幕保护
};

PUBLIC int task_proc_table[NR_TASKS_PROCS] = {1, 2};

PUBLIC char task_stack[STACK_SIZE_TOTAL];

PUBLIC t_pf_irq_handler	irq_table[NR_IRQ];
PUBLIC TTY tty_table[NR_CONSOLES];
PUBLIC CONSOLE console_table[NR_CONSOLES];

PUBLIC t_sys_call sys_call_table[NR_SYS_CALL] = 
{
	//系统调用函数表
	sys_get_ticks, 
	sys_write, 
	sys_getchar, 
	sys_clear, 
	sys_shutdown, 
	sys_echoon, 
	sys_echooff, 
	sys_accepton, 
	sys_acceptoff, 
	sys_flush
};
PUBLIC char ContentOfConsoleOrder[16][32];
PUBLIC int  SumofConsoleOrder;
