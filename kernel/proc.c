
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                               proc.c
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                                                    ¶ÅÊ¢¬r ÁÖ²ýÊ¢ Ò¶À¤Óî
                                                         2015Äê7ÔÂ
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

#include "type.h"
#include "const.h"
#include "protect.h"
#include "string.h"
#include "proc.h"
#include "tty.h"
#include "console.h"
#include "global.h"
#include "proto.h"
#include "keyboard.h"

/*======================================================================*
                              schedule
 *======================================================================*/
PUBLIC void schedule()
{
	PROCESS* p;
	int i = 0;
	int greatest_ticks = 0;
	while (!greatest_ticks)
	{
	
		for ( p = proc_table; p < proc_table + 7 ; ++p )
		{
			if (p->priority == 0) continue;
			if ( p->ticks > greatest_ticks )
			{
				greatest_ticks = p -> ticks;
				p_proc_ready = p;
			}
		}
		if ( !greatest_ticks )
		{
				for ( p = proc_table+7; p < proc_table + MAX_TASKS_PROCS; ++p )
				{
					if (p->priority == 0) continue;
					if ( p->ticks > greatest_ticks )
					{
						greatest_ticks = p -> ticks;
						p_proc_ready = p;
					}
				}
		
		}
		if(!greatest_ticks)
		{
			for ( p = proc_table; p < proc_table + MAX_TASKS_PROCS ; ++p )
			{
				p->ticks = p->priority;
			}
		}
	}
}


/*======================================================================*
                           sys_get_ticks
 *======================================================================*/
PUBLIC int sys_get_ticks()
{
	return ticks;
}

