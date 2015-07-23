
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                            global.c
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                                          ��ʢ�r �ֲ�ʢ Ҷ����
                                                         2015��7��
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
	//������ڵ�ַ,������,�Ƿ�����,��Ӧ��tty,���ȼ�
	{NewCreate,"UserProcess  ",FALSE,3,0},//��ʾ�´�����ϵͳ����
	{task_tty,"IO-Main      ",TRUE,0,15},//�����̨
	{Begin,"Begin        ",TRUE,0,10},//ϵͳ��ʼ�����е�������
	{FiveinaRow,"FiveinaRow   ",FALSE,1,5 },//��������Ϸ
	{ManageProcess,"ManageProcess",TRUE,2,10},//�������
	{NewCreate2,"SysProcess   ",TRUE,3,10},//��ʾ�´������û�����
        {Play,"Play         ",FALSE,3,10}//ģ����Ļ����
};

PUBLIC int task_proc_table[NR_TASKS_PROCS] = {1, 2};

PUBLIC char task_stack[STACK_SIZE_TOTAL];

PUBLIC t_pf_irq_handler	irq_table[NR_IRQ];
PUBLIC TTY tty_table[NR_CONSOLES];
PUBLIC CONSOLE console_table[NR_CONSOLES];

PUBLIC t_sys_call sys_call_table[NR_SYS_CALL] = 
{
	//ϵͳ���ú�����
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
