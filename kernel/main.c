
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                            main.c
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                                               杜盛瑀 林昌盛 叶坤宇
                                                         2015年7月          
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
int CreateProcess(int TaskID);//添加一个进程到表
t_bool KillProcess(int Pid);//结束pid号进程
void KernelError();//错误
void ManageProcess();
void Help();
void ProcessInfo();
void FiveinaRow();
void NewCreate(int id);
void NewCreate2(int id);
void Begin();
void sys_shutdown(PROCESS * p_proc);
void strtolower(char * src);
int strcmp(char * src, char * dst);
void DisPlay();
void Play();

PUBLIC int MCinix_main()//主函数
{
	disp_str("=====\"MCinix_main\" begins=====\n");
	int i;
	for(i = 0;i < NR_TASKS_PROCS;i++)
	{
		if (i < NR_TASKS_PROCS)
		{
			if(CreateProcess(task_proc_table[i]) < 0)//添加系统的初始任务
			{
				KernelError();
				while (1);
			} 
		}
	}
	p_proc_ready = proc_table;
	
	k_reenter = 0;
	ticks = 0;
	init_clock();

	restart();

	while(1){}
}

void Play()
{
	while(1)
	{
			clear();
			printf("     00                                00          \n");
			printf("   00  00                            0    0        \n");
			printf(" 00      00                          0            \n");
			printf("00        00                           0        \n");
			printf(" 00      00                               0       \n");
			printf("   00  00                             0    0       \n");
			printf("     00                                 00         \n");
			printf("_________________________________________________Copy Right___\n");
			printf("     **\n");
			printf("    **  . .     ,,,ooo oooo,,\n");
			printf("   **           o     o       ''''o\n");
			printf(" **    .         oooo,,oooooo''' *****         ooo,,,oooo\n");
			printf(" .  .    .           *                 *     ''          ""'\n");
			printf(" .    .     .     *                      *    ooo________ooo'''\n");
			printf(" .      .       *                          *\n");
			printf(" .        .    *                            *\n");
			printf(" .             *                            *\n");
			printf(" .             *                            *\n");
			printf(" .             *         m        m         *\n");
			printf(" .               *       mm      mm       *        _\n");
			printf(" .                *      mmmm  mmmm      *       /{_}\\\n");
			printf(" .                 ******mmmmmmmmmm******         (|)\n");
			printf("     X                   mmmmmmmmmm               A|A\n");
			printf("    x x                 mmmmmmmmmmmm             AAAAA       MAKE YOU NATURE\n");
			printf("     X /               mmmmmmmmmmmmmm            A| |A\n");
			printf("     |/               mmmmmmmmmmmmmmmm            | |\n");
			printf("YYYYYYYYYYYYYYYYYYYYY========M M=======YYYYYYYYYYYYYYYYYYYYY\n");
			milli_delay(600);
		///////////////////////////////////////////////////////////////////////////////////
			clear();
			printf("     00                                00          \n");
			printf("   00  00                            0    0        \n");
			printf(" 00      00                          0            \n");
			printf("00        00                           0        \n");
			printf(" 00      00                               0       \n");
			printf("   00  00                             0    0       \n");
			printf("     00                                 00         \n");
			printf("_________________________________________________Copy Right___\n");
			printf("     **\n");
			printf("    **  . .        ,,,ooo oooo,,\n");
			printf("   **              o     o       ''''o\n");
			printf(" **    .            oooo,,oooooo''' ***                ooo,,,oooo\n");
			printf(" .  .    .           *                 *          ''          ""'\n");
			printf(" .    .     .     *                      *         ooo________ooo'''\n");
			printf(" .      .       *                          *\n");
			printf(" .        .    *                            *\n");
			printf(" .             *                            *\n");
			printf(" .             *                            *\n");
			printf(" .             *         m        m         *\n");
			printf(" .               *       mm      mm       *        _\n");
			printf(" .                *      mmmm  mmmm      *       /{_}\\\n");
			printf(" .                 ******mmmmmmmmmm******         (|)\n");
			printf("     X                   mmmmmmmmmm               A|A\n");
			printf("    x x                 mmmmmmmmmmmm             AAAAA       MAKE YOU NATURE\n");
			printf("     X /               mmmmmmmmmmmmmm            A| |A\n");
			printf("     |/               mmmmmmmmmmmmmmmm            | |\n");
			printf("YYYYYYYYYYYYYYYYYYYYY========M M=======YYYYYYYYYYYYYYYYYYYYY\n");
			milli_delay(600);
			///////////////////////////////////////////////////////////////////////////////////
			clear();
			printf("     00                                00          \n");
			printf("   00  00                            0    0        \n");
			printf(" 00      00                          0            \n");
			printf("00        00                           0        \n");
			printf(" 00      00                               0       \n");
			printf("   00  00                             0    0       \n");
			printf("     00                                 00         \n");
			printf("_________________________________________________Copy Right___\n");
			printf("     **\n");
			printf("    **  . .             ,,,ooo oooo,,\n");
			printf("   **                   o     o       ''''o\n");
			printf(" **    .               **oooo,,oooooo'''                    ooo,,,oooo\n");
			printf(" .  .    .           *                 *               ''          ""'\n");
			printf(" .    .     .     *                      *              ooo________ooo'''\n");
			printf(" .      .       *                          *\n");
			printf(" .        .    *                            *\n");
			printf(" .             *                            *\n");
			printf(" .             *                            *\n");
			printf(" .             *         m        m         *\n");
			printf(" .               *       mm      mm       *        _\n");
			printf(" .                *      mmmm  mmmm      *       /{_}\\\n");
			printf(" .                 ******mmmmmmmmmm******         (|)\n");
			printf("     X                   mmmmmmmmmm               A|A\n");
			printf("    x x                 mmmmmmmmmmmm             AAAAA       MAKE YOU NATURE\n");
			printf("     X /               mmmmmmmmmmmmmm            A| |A\n");
			printf("     |/               mmmmmmmmmmmmmmmm            | |\n");
			printf("YYYYYYYYYYYYYYYYYYYYY========M M=======YYYYYYYYYYYYYYYYYYYYY\n");
			milli_delay(600);
			///////////////////////////////////////////////////////////////////////////////////
			clear();
			printf("     00                                00          \n");
			printf("   00  00                            0    0        \n");
			printf(" 00      00                          0            \n");
			printf("00        00                           0        \n");
			printf(" 00      00                               0       \n");
			printf("   00  00                             0    0       \n");
			printf("     00                                 00         \n");
			printf("_________________________________________________Copy Right___\n");
			printf("     **\n");
			printf("    **  . .                    ,,,ooo oooo,,\n");
			printf("   **                          o     o       ''''o\n");
			printf(" **    .               *********oooo,,oooooo'''                    ooo,,,oooo\n");
			printf(" .  .    .          *                 *                      ''          ""'\n");
			printf(" .    .     .     *                      *                     ooo________ooo''\n");
			printf(" .      .       *                          *\n");
			printf(" .        .    *                            *\n");
			printf(" .             *                            *\n");
			printf(" .             *                            *\n");
			printf(" .             *         m        m         *\n");
			printf(" .               *       mm      mm       *        _\n");
			printf(" .                *      mmmm  mmmm      *       /{_}\\\n");
			printf(" .                 ******mmmmmmmmmm******         (|)\n");
			printf("     X                   mmmmmmmmmm               A|A\n");
			printf("    x x                 mmmmmmmmmmmm             AAAAA       MAKE YOU NATURE\n");
			printf("     X /               mmmmmmmmmmmmmm            A| |A\n");
			printf("     |/               mmmmmmmmmmmmmmmm            | |\n");
			printf("YYYYYYYYYYYYYYYYYYYYY========M M=======YYYYYYYYYYYYYYYYYYYYY\n");
			milli_delay(600);
			///////////////////////////////////////////////////////////////////////////////////
			clear();
			printf("     00                                00          \n");
			printf("   00  00                            0    0        \n");
			printf(" 00      00                          0            \n");
			printf("00        00                           0        \n");
			printf(" 00      00                               0       \n");
			printf("   00  00                             0    0       \n");
			printf("     00                                 00         \n");
			printf("_________________________________________________Copy Right___\n");
			printf("     **\n");
			printf("    **  . .                              ,,,ooo oooo,,\n");
			printf("   **                                    o     o       ''''o\n");
			printf(" **    .               ***************    oooo,,oooooo'''          ooo,,,oooo\n");
			printf(" .  .    .           *                 *                      ''          ""'\n");
			printf(" .    .     .     *                      *                     ooo________ooo''\n");
			printf(" .      .       *                          *\n");
			printf(" .        .    *                            *\n");
			printf(" .             *                            *\n");
			printf(" .             *                            *\n");
			printf(" .             *         m        m         *\n");
			printf(" .               *       mm      mm       *        _\n");
			printf(" .                *      mmmm  mmmm      *       /{_}\\\n");
			printf(" .                 ******mmmmmmmmmm******         (|)\n");
			printf("     X                   mmmmmmmmmm               A|A\n");
			printf("    x x                 mmmmmmmmmmmm             AAAAA       MAKE YOU NATURE\n");
			printf("     X /               mmmmmmmmmmmmmm            A| |A\n");
			printf("     |/               mmmmmmmmmmmmmmmm            | |\n");
			printf("YYYYYYYYYYYYYYYYYYYYY========M M=======YYYYYYYYYYYYYYYYYYYYY\n");
			milli_delay(2000);
        }
}


int CreateProcess(int TaskID)//创建进程
{
	int i;
	t_8 privilege;
	t_8 rpl;
	int eflags;
	if(task_whole_list[TaskID].task_or_no == TRUE)
	{
		privilege = PRIVILEGE_TASK;
		rpl = RPL_TASK;
		eflags = 0x1202;
		i = 0;
	}
	else
	{
		privilege = PRIVILEGE_USER;
		rpl = RPL_USER;
		eflags = 0x202;
		i = 7;
	}
	for(i = i;i < MAX_TASKS_PROCS;++i)
	{
		if(proc_table[i].priority == 0)
		{
			break;
		}
	}

	if(i == MAX_TASKS_PROCS)
	{
		return -1;
	}	

	strcpy(proc_table[i].p_name, task_whole_list[TaskID].name);// name of the process
	proc_table[i].pid = i;// pid

	proc_table[i].ldt_sel	= SELECTOR_LDT_FIRST + 8 * i;
	memcpy(&proc_table[i].ldts[0], &gdt[SELECTOR_KERNEL_CS >> 3], sizeof(DESCRIPTOR));
	proc_table[i].ldts[0].attr1 = DA_C | privilege << 5;	// change the DPL
	memcpy(&proc_table[i].ldts[1], &gdt[SELECTOR_KERNEL_DS >> 3], sizeof(DESCRIPTOR));
	proc_table[i].ldts[1].attr1 = DA_DRW | privilege << 5;	// change the DPL
	proc_table[i].regs.cs = ((8 * 0) & SA_RPL_MASK & SA_TI_MASK) | SA_TIL | rpl;
	proc_table[i].regs.ds = ((8 * 1) & SA_RPL_MASK & SA_TI_MASK) | SA_TIL | rpl;
	proc_table[i].regs.es = ((8 * 1) & SA_RPL_MASK & SA_TI_MASK) | SA_TIL | rpl;
	proc_table[i].regs.fs = ((8 * 1) & SA_RPL_MASK & SA_TI_MASK) | SA_TIL | rpl;
	proc_table[i].regs.ss = ((8 * 1) & SA_RPL_MASK & SA_TI_MASK) | SA_TIL | rpl;
	proc_table[i].regs.gs = (SELECTOR_KERNEL_GS & SA_RPL_MASK) | rpl;
	proc_table[i].regs.eip = (t_32)task_whole_list[TaskID].initial_eip;
	proc_table[i].regs.esp = (t_32)task_stack + STACK_SIZE_TOTAL - STACK_SIZE_COMMON * i;
	proc_table[i].regs.eflags = eflags;
	proc_table[i].nr_tty = task_whole_list[TaskID].defaultTTY;
	proc_table[i].ticks = proc_table[i].priority = task_whole_list[TaskID].priority;
	proc_table[i].task_or_no = task_whole_list[TaskID].task_or_no;

	return i;
}

void KernelError()//进程出错提示
{
	disp_str("Sorry, there's something wrong with kernel!\n");
}


t_bool KillProcess(int Pid)//结束进程
{
	if(proc_table[Pid].priority == 0)
	{
		return FALSE;
	}
	proc_table[Pid].priority = 0;
	proc_table[Pid].p_name[0] = 0;
	return TRUE;
}


void ManageProcess()//进程管理器
{
	clear();
	printf("\n");
	printf("                    o(x____x)o-----------------------o(x____x)o\n");
	printf("                                  Manage Process \n");
	printf("                    o(x____x)o-----------------------o(x____x)o\n");
	do
	{
		printf("[Manage Process(add/end)]#");
		char szCmd[256];
		char szCmd_id[32];
		char szCmd_sys[32];
		int  id;
		readacommand(szCmd);
		strtolower(szCmd);
		if (!strcmp(szCmd, "end"))
		{
			printf("[Enter the ID of process]#");
			readacommand(szCmd_id);
			if (_atoi(szCmd_id,&id))
			{
				if (proc_table[id].task_or_no)
				{
					printf("It's not allowed to end system processes! \n");
				}
				else
				{
					if(KillProcess(id)==TRUE)
					printf("end successfully!\n");
					else
					printf("fail to end!\n");
				}
			}
			else
			{
				printf("something wrong with end\n",id);
			}
			
		}
		else if(!strcmp(szCmd,"add"))
		{
			printf("[Manage Process(sys/user)]#");
			readacommand(szCmd_sys);
			strtolower(szCmd_sys);
			int i;
			if(!strcmp(szCmd_sys, "sys"))
			{
				for(i = 0 ;i < 7;i ++)
				{
					if (proc_table[i].priority == 0)
					{
						break;
					}
				}
				if(i == 7)
				{
					printf("too much sys process\n");
				}
				else
				{
					CreateProcess(5);
					proc_table[i].priority=10;	
					printf("A new sys process is running on CONSOLE-3 now!\n");
				}
			}
			else if(!strcmp(szCmd_sys,"user"))
			{	
					for(i = 7;i < MAX_TASKS_PROCS;i ++)
					{
						if (proc_table[i].priority == 0)
						{
							break;
						}
					}
					if(i == MAX_TASKS_PROCS)
					{
						printf("too much user process\n");
					}
					else
					{
						CreateProcess(0);
						proc_table[i].priority=5;	
						printf("A new user process is running on CONSOLE-3 now!\n");
					}
			}
			else 
			{
				printf("something wrong with add\n");
				continue;
			}
		
		}
		else if(!strcmp(szCmd, "clear"))
		{
			clear();
			printf("\n");
			printf("                   o(x____x)o------------------------o(x____x)o\n");
			printf("                                 Manage Process \n");
			printf("                   o(x____x)o------------------------o(x____x)o\n");
		}
		else
		{
			printf("Your command is not correct!\n");
		}
		milli_delay(200);
	}
	while (1);
}


#define DA1 rea[i+1*x[k]][j+1*y[k]]
#define DA2 rea[i+2*x[k]][j+2*y[k]]
#define DA3 rea[i+3*x[k]][j+3*y[k]]
#define DA4 rea[i+4*x[k]][j+4*y[k]]
#define DA6 rea[i+1*x[7-k]][j+1*y[7-k]]
#define DA7 rea[i+2*x[7-k]][j+2*y[7-k]]

void FiveinaRow()//五子棋游戏
{
	int i,j;
	int  bfirsttime =1;
	int wix,wiy;
	int e = 0,r = 0;
	int a[19][19]={{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0}};
	int b[19][19]={{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0}};
	int x[8]={0,1,1,1,-1,-1,-1,0},c[8]={0};
	int y[8]={1,1,0,-1,1,0,-1,-1},k;
	int state[6]={0,1296,216,36,6,1};
	int row=0,colum=0,max=b[0][0];
	int icontinue=1;
	int bGameOver =0;
	int ianother=1;
	char temp1[64];
	char temp2[64];
	int itemp1;
	int itemp2;
	int rea[29][29];//这样可以不考虑边界
	do 
	{
		for (i=0;i<29;i++)
		{
			for (j=0;j<29;j++)
			{
				if (i-5<0||j-5<0||i>23||j>23)
					rea[i][j]=3;
				else rea[i][j]=a[i-5][j-5];
			}
		}
		clear();
		//printf("\n");
		printf("     o(x____x)o-------------------------o(x____x)o\n");
		printf("                			 FIVE CHESS(LOCAL)			\n");
		printf("     o(x____x)o-------------------------o(x____x)o\n");
		printf("\n");
		printf("   0  1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16 17 18 \n");
		for (i=0;i<19;i++)
		{
			printf("%2d:",i);
			for (j=0;j<19;j++)
			{
				if (j==18)
				{
					if(a[i][j]==0)
					printf("	");
					else
					printf("%d",a[i][j]);
				}
				else
				{
					if(a[i][j]==0)
					printf("	--");
					else
					printf("%d--",a[i][j]);
				}
			}
			printf("\n");
		}
		printf("Who will start first(Computer:1,You:0)\n");
		//scanf("%d",&i);
		for (wiy = 0;wiy<64;wiy++)
		{
			temp1[i]='\0';
			temp2[i]='\0';
		}
		readacommand(temp1);
		_atoi(temp1,&i);
		if (i != 1)
		{
			r = 2;
			e = 1;
			bfirsttime = 0;
			printf("Please input row and col number(exp:10 enter 9 ; quit:-1 enter-1)\n");
			//to ensure to input is all right

			for(wix =1;wix<=2;)
			{
				//scanf("%d,%d",&row,&colum);
				for (wiy = 0;wiy<64;wiy++)
				{
					temp1[i]='\0';
					temp2[i]='\0';
				}
				readacommand(temp1);
				readacommand(temp2);
				_atoi(temp1,&row);
				_atoi(temp2,&colum);
				if (row==-1||colum==-1)
				{
					icontinue = 8;
					break;
				}
				else
				{
					if (row>=0&&row<=18&&colum>=0&&colum<=18)
					{
						if (a[row][colum]==0)
						{
							wix = 8;
							a[row][colum]=e;
							rea[row+5][colum+5] = e;
						}
						else
						{
							printf("That place has been taken\n");
							wix = 2;
						}
					}
					else
					{
						printf("The Row or Column is out of range\n");
						wix =2;
					}
				}

			}

		}
		else
		{
			e = 2;//e表示人
			r = 1;//r表示电脑
		}
		while(1)
		{
			for (i=5;i<=23;i++)
			{
				for (j=5;j<=23;j++)
				{
					if (rea[i][j]!=0)continue;
					else
					{
						for (k=0;k<8;k++) 
						{
							if (DA1==e)//防守
							{
								if (DA2==e)
								{
									if (DA6==e&&DA7==0)
										b[i-5][j-5]+=state[2];
									if (DA3==e)
									{
										if (DA6==0)
											b[i-5][j-5]+=state[2];
										if(DA4==0||DA4==e||DA6==e)
											b[i-5][j-5]+=state[1];
									}
									else if (DA3==0)
									{
										if (DA4==e||DA6==e)
											b[i-5][j-5]+=state[2];
										else if (DA4==0)
											b[i-5][j-5]+=state[4];
									}
								}
								else if (DA2==0)
								{
									if(DA6==e&&DA7==0)
										b[i-5][j-5]+=state[2];
									else if (DA3==e)
									{
										if (DA4==e||DA6==e)
											b[i-5][j-5]+=state[2];
										else if (DA4==0)
											b[i-5][j-5]+=state[3];
									}
									else if (DA3==0)
									{
										if (DA6==e)
											b[i-5][j-5]+=state[3];
										else if (DA4==e)
											b[i-5][j-5]+=state[4];
										else if (DA4==0)
											b[i-5][j-5]+=state[5];
									}
								}
							}
							else if (DA1==r)//进攻
							{
								if (DA2==r)
								{
									if(DA6==DA7==0)
										b[i-5][j-5]+=2*state[4];
									if (DA3==r)
									{
										if (DA4==r||DA4==0)
											b[i-5][j-5]+=2*(state[1]);
									}
									else if (DA3==0)
									{
										if (DA6==r)
											b[i-5][j-5]+=2*(state[2]);
										else if (DA4==r)
											b[i-5][j-5]+=2*(state[2]);
										else if (DA4==0)
											b[i-5][j-5]+=2*(state[4]);
									}
								}
								else if(DA2==0)
								{
									if (DA6==r&&DA7==0)
										b[i-5][j-5]+=2*(state[2]);
									else if (DA3==r)
									{
										if (DA4==r||DA4==0)
											b[i-5][j-5]+=2*(state[3]);
									}
									else if (DA3==0)
									{
										if (DA4==r)
											b[i-5][j-5]+=2*(state[4]);
									}
								}
							}
						}
					}
				}
			}
			max=b[0][0];
			row=0,colum=0;
			if (bfirsttime==1)
			{
				a[9][9]=1;
				bfirsttime = 0;
			}
			else
			{
				for (i=0;i<19;i++)//确定和最大的地方
					for(j=0;j<19;j++)
						if(b[i][j]>max)
						{
							max=b[i][j];
							row=i;colum=j;
						}
						a[row][colum]=r;
						rea[row+5][colum+5]=r;
			}

			
			clear();
			printf("   0  1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16 17 18 \n");
			for (i=0;i<19;i++)
			{
				printf("%2d:",i);
				for (j=0;j<19;j++)
				{
					if (j==18)
					{
						if(a[i][j]==0)
						printf("	");
						else
						printf("%d",a[i][j]);
					}
					else
					{
						if(a[i][j]==0)
						printf("	--");
						else
						printf("%d--",a[i][j]);
					}
				}
				printf("\n");
			}
			//test over or not
			for (i=5;i<=23;i++)
			{
				for (j=5;j<=23;j++)
				{
					if (rea[i][j]!=r)continue;
					else 
					{
						for(k=0;k<8;k++)
						{
							if(DA1==r&&DA2==r&&DA3==r&&DA4==r)
							{	
								printf ("     ----GAME OVER----    \n");
								bGameOver = 1;
								break;
							}
						}
					}
					if (bGameOver)
					{
						break;
					}
				}
				if (bGameOver)
				{
					break;
				}
			}
			if (bGameOver)
			{
				break;
			}
			for(i=0;i<19;i++)
			{
				for(j=0;j<19;j++)
				{
					b[i][j]=0;
				}
			}
			printf("Please input row and col number(exp:10 enter 9 ; quit:-1 enter -1)\n");
			//to ensure to input is all right
			for(wix =1;wix<=2;)
			{
				//scanf("%d,%d",&row,&colum);
				for (wiy = 0;wiy<64;wiy++)
				{
					temp1[i]='\0';
					temp2[i]='\0';
				}
				readacommand(temp1);
				readacommand(temp2);
				_atoi(temp1,&row);
				_atoi(temp2,&colum);
				if (row==-1||colum==-1)
				{
					icontinue = 8;
					break;
				}
				else
				{
					if (row>=0&&row<=18&&colum>=0&&colum<=18)
					{
						if (a[row][colum]==0)
						{
							wix = 8;
							a[row][colum]=e;
							rea[row+5][colum+5]=e;
						}
						else
						{
							printf("That place has been taken\n");
							wix = 2;
						}
					}
					else
					{
						printf("The Row or Column is out of range\n");
						wix =2;
					}
				}

			}
			//test over or not
			for (i=5;i<=23;i++)
			{
				for (j=5;j<=23;j++)
				{
					if (rea[i][j]!=e)continue;
					else 
					{
						for(k=0;k<8;k++)
						{
							if(DA1==e&&DA2==e&&DA3==e&&DA4==e)
							{
								clear();
								printf("   0  1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16 17 18 \n");
								for (i=0;i<19;i++)
								{
									printf("%2d:",i);
									for (j=0;j<19;j++)
									{
										if (j==18)
										{
											if(a[i][j]==0)
											printf("	");
											else
											printf("%d",a[i][j]);
										}
										else
										{
											if(a[i][j]==0)
											printf("	--");
											else
											printf("%d--",a[i][j]);
										}
									}
									printf("\n");
								}
								printf ("----GAME OVER----\n");
								bGameOver = 1;
								break;
							}
						}
					}
					if (bGameOver)
					{
						break;
					}
				}
				if (bGameOver)
				{
					break;
				}
			}
			if (bGameOver)
			{
				break;
			}
			if (icontinue==8)
			{
				break;
			}
		}
		//reset the data
		for(i=0;i<19;i++)
		{
			for(j=0;j<19;j++)
			{
				a[i][j]=0;
			}
		}
		bfirsttime =1;
		icontinue=1;
		bGameOver =0;
		//printf("Do You Want To Play Again?(Input:1/0)\n");
		printf("------Now You Will Enter The Next Game----\n");
		milli_delay(3000);
		//scanf("%d",&ianother);
		/*for (wiy = 0;wiy<64;wiy++)
		{
			temp1[i]='\0';
		}
		readacommand(temp1);
		_atoi(temp1,&ianother);*/
	} while (1);
	//KillProcess(3);
	
}


void NewCreate2(int id)//系统进程创建提示
{
	clear();
	printf("\n");
	printf("A New System Process Has Been Created!");
	while(1);
}
void NewCreate(int id)//用户进程创建提示
{
	clear();
	printf("\n");
	printf("A new User Process is running");
	while(1);
}


void Begin()//开机函数
{
	DisPlay();
	char szCmd[256];
	int i;
	t_bool fIsRunning = TRUE;
	clear();
	printf("                 o(...)o-------------------------------o(...)o\n");
	printf("                                    Welcome To Boom \n");
	printf("                                        Created By\n");
	printf("                           Ye Kunyu,Lin Changsheng,Du Shengyu       \n");
	printf("                 o(...)o-------------------------------o(...)o\n");
	do{
                //printf("calcalator is ");
                //printf("%d",Calculator);
                // Calculator=0;
		printf("[Boom]#");
		//readacommand(szCmd);
		readMainConsole(szCmd);
		strtolower(szCmd);
		if(!strcmp(szCmd,"endsystem"))
		{
                        Calculator=0;
			break;
		}
		else if(!strcmp(szCmd,"play"))
		{
                        Calculator=0;
			CreateProcess(6);
			//proc_table[i].priority=5;	
			printf("Play is running on CONSOLE-3 now!\n");
		}
		else if(!strcmp(szCmd,"processinfo"))
		{      
                        Calculator=0;
			ProcessInfo();
		}
		else if(!strcmp(szCmd,"help"))
		{
                        Calculator=0;
			Help();
		}
                else if(!strcmp(szCmd,"calculator"))
		{
                        calculator();

		}
		else if(!strcmp(szCmd,"fiveinarow"))
		{
                        Calculator=0;
			int i;
			for(i = 0;i < MAX_TASKS_PROCS;++i)
			{
				if(!strcmp(proc_table[i].p_name, task_whole_list[3].name))
				{
					printf("FiveinaRow Had Been Created And It Is Still Running On CONSOLE-1!\n");
					break;
				}
			}
			if(i == MAX_TASKS_PROCS)
			{
				printf("FiveinaRow Has Been Created Successfully And It Is Running On CONSOLE-1\n",CreateProcess(3));
			}			
		}
		else if(!strcmp(szCmd,"manageprocess"))
		{
                        Calculator=0;
			int i;
			for(i = 0;i < MAX_TASKS_PROCS;++i)
			{
				if(!strcmp(proc_table[i].p_name, task_whole_list[4].name))
				{
					printf("\nCONSOLE-2 is running manageprocess! \n");
					break;
				}
			}
			if(i == MAX_TASKS_PROCS)
			{
				printf("\nCONSOLE-2 is running manageprocess!  \n", CreateProcess(4));
			}	
		}
		else if(!strcmp(szCmd,"clear"))
		{
                        Calculator=0;
			clear();
			printf("                 o(x____x)o-------------------------------o(x____x)o\n");
			printf("                                    Welcome To Boom \n");
			printf("                                        Created By\n");
			printf("                            Ye Kunyu,Lin Changsheng,Du Shengyu       \n");
			printf("                 o(x____x)o-------------------------------o(x____x)o\n");
		}
		else
		{
                        if(Calculator!=1){
                           printf("Your command is not correct!\n");
                        }
		}
		milli_delay(200);
	}while(TRUE);
	clear();
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("     M$$$$$$$$$$$$$$$$$$$M\n");
	printf("     M$$$$$$$$$$$$$$$$$$$M\n");
	printf("     M$$$$$$$$$$$$$$$$$$$M\n");
	printf("     M$$$$$$$$$$$$$$$$$$$M\n");
	printf("     M$$$$$$$$$$$$$$$$$$$M\n");
	printf("     M$$$$$$$$$$$$$$$$$$$M\n");
	printf("     M$$$$$$$$$$$$$$$$$$$M\n");
	printf("     M$$$$$$$$$$$$$$$$$$$M\n");
	printf("     M$$$$$$$$$$$$$$$$$$$M\n");
	printf("     M$$$$$$$$$$$$$$$$$$$M\n");
	printf("     M$$$$$$$$$$$$$$$$$$$M\n");
	printf("     M$$$$$$$$$$$$$$$$$$$M\n");
	printf("     M$$$$$$$$$$$$$$$$$$$M\n");
	printf("     M$$$$$$$$$$$$$$$$$$$M\n");
	printf("     M$$$$$$$$$$$$$$$$$$$M\n");
	printf("     M$$$$$$$$$$$$$$$$$$$M\n");
	printf("     M$$$$$$$$$$$$$$$$$$$M\n");
	printf("     M$$$$$$$$$$$$$$$$$$$M\n");
	printf("     MMMMMMMMMMMMMMMMMMMMM\n");
	printf("\n");
	milli_delay(1000);
	///////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////
	clear();
	printf("                         OO\n");
	printf("                        OO\n");
	printf("                       OO\n");
	printf("                      OO\n");
	printf("                     OO\n");
	printf("     M$$$$$$$$$$$$$$OO$$$M\n");
	printf("     M$$$$$$$$$$$$$OO$$$$M\n");
	printf("     M$$$$$$$$$$$$OO$$$$$M\n");
	printf("     M$$$$$$$$$$$OO$$$$$$M\n");
	printf("     M$$$$$$$$$$OO$$$$$$$M\n");
	printf("     M$$$$$$$$$OO$$$$$$$$M\n");
	printf("     M$$$$$$$$OO$$$$$$$$$M\n");
	printf("     M$$$$$$$OO$$$$$$$$$$M\n");
	printf("     M$$$$$$OO$$$$$$$$$$$M\n");
	printf("     M$$$$$OO$$$$$$$$$$$$M\n");
	printf("     M$$$$OO$$$$$$$$$$$$$M\n");
	printf("     M$$$OO$$$$$$$$$$$$$$M\n");
	printf("     M$$OO$$$$$$$$$$$$$$$M\n");
	printf("     M$OO$$$$$$$$$$$$$$$$M\n");
	printf("     MOO$$$$$$$$$$$$$$$$$M\n");
	printf("     M$$$$$$$$$$$$$$$$$$$M\n");
	printf("     M$$$$$$$$$$$$$$$$$$$M\n");
	printf("     M$$$$$$$$$$$$$$$$$$$M\n");
	printf("     MMMMMMMMMMMMMMMMMMMMM\n");
	milli_delay(1000);
	///////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////
	clear();
	printf("                         OO\n");
	printf("                        OO\n");
	printf("                       OO\n");
	printf("                      OO\n");
	printf("                     OO\n");
	printf("     M              OO   M\n");
	printf("     M             OO    M\n");
	printf("     M$$$$$$$$$$$$OO$$$$$M\n");
	printf("     M$$$$$$$$$$$OO$$$$$$M\n");
	printf("     M$$$$$$$$$$OO$$$$$$$M\n");
	printf("     M$$$$$$$$$OO$$$$$$$$M\n");
	printf("     M$$$$$$$$OO$$$$$$$$$M\n");
	printf("     M$$$$$$$OO$$$$$$$$$$M\n");
	printf("     M$$$$$$OO$$$$$$$$$$$M\n");
	printf("     M$$$$$OO$$$$$$$$$$$$M\n");
	printf("     M$$$$OO$$$$$$$$$$$$$M\n");
	printf("     M$$$OO$$$$$$$$$$$$$$M\n");
	printf("     M$$OO$$$$$$$$$$$$$$$M\n");
	printf("     M$OO$$$$$$$$$$$$$$$$M\n");
	printf("     MOO$$$$$$$$$$$$$$$$$M\n");
	printf("     M$$$$$$$$$$$$$$$$$$$M\n");
	printf("     M$$$$$$$$$$$$$$$$$$$M\n");
	printf("     M$$$$$$$$$$$$$$$$$$$M\n");
	printf("     MMMMMMMMMMMMMMMMMMMMM\n");
	milli_delay(1000);
	///////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////
	clear();
	printf("                         OO\n");
	printf("                        OO\n");
	printf("                       OO\n");
	printf("                      OO\n");
	printf("                     OO\n");
	printf("     M              OO   M\n");
	printf("     M             OO    M\n");
	printf("     M            OO     M\n");
	printf("     M           OO      M\n");
	printf("     M          OO       M\n");
	printf("     M         OO        M\n");
	printf("     M$$$$$$$$OO$$$$$$$$$M\n");
	printf("     M$$$$$$$OO$$$$$$$$$$M\n");
	printf("     M$$$$$$OO$$$$$$$$$$$M\n");
	printf("     M$$$$$OO$$$$$$$$$$$$M\n");
	printf("     M$$$$OO$$$$$$$$$$$$$M\n");
	printf("     M$$$OO$$$$$$$$$$$$$$M\n");
	printf("     M$$OO$$$$$$$$$$$$$$$M\n");
	printf("     M$OO$$$$$$$$$$$$$$$$M\n");
	printf("     MOO$$$$$$$$$$$$$$$$$M\n");
	printf("     M$$$$$$$$$$$$$$$$$$$M\n");
	printf("     M$$$$$$$$$$$$$$$$$$$M\n");
	printf("     M$$$$$$$$$$$$$$$$$$$M\n");
	printf("     MMMMMMMMMMMMMMMMMMMMM\n");
	milli_delay(1000);
	///////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////
	clear();
	printf("                         OO\n");
	printf("                        OO\n");
	printf("                       OO\n");
	printf("                      OO\n");
	printf("                     OO\n");
	printf("     M              OO   M\n");
	printf("     M             OO    M\n");
	printf("     M            OO     M\n");
	printf("     M           OO      M\n");
	printf("     M          OO       M\n");
	printf("     M         OO        M\n");
	printf("     M        OO         M\n");
	printf("     M       OO          M\n");
	printf("     M      OO           M\n");
	printf("     M$$$$$OO$$$$$$$$$$$$M\n");
	printf("     M$$$$OO$$$$$$$$$$$$$M\n");
	printf("     M$$$OO$$$$$$$$$$$$$$M\n");
	printf("     M$$OO$$$$$$$$$$$$$$$M\n");
	printf("     M$OO$$$$$$$$$$$$$$$$M\n");
	printf("     MOO$$$$$$$$$$$$$$$$$M\n");
	printf("     M$$$$$$$$$$$$$$$$$$$M\n");
	printf("     M$$$$$$$$$$$$$$$$$$$M\n");
	printf("     M$$$$$$$$$$$$$$$$$$$M\n");
	printf("     MMMMMMMMMMMMMMMMMMMMM\n");
	milli_delay(1000);
	///////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////
	clear();
	printf("                         OO\n");
	printf("                        OO\n");
	printf("                       OO\n");
	printf("                      OO\n");
	printf("                     OO\n");
	printf("     M              OO   M\n");
	printf("     M             OO    M\n");
	printf("     M            OO     M\n");
	printf("     M           OO      M\n");
	printf("     M          OO       M\n");
	printf("     M         OO        M\n");
	printf("     M        OO         M\n");
	printf("     M       OO          M\n");
	printf("     M      OO           M\n");
	printf("     M     OO            M\n");
	printf("     M    OO             M\n");
	printf("     M   OO              M\n");
	printf("     M  OO               M\n");
	printf("     M OO                M\n");
	printf("     MOO                 M\n");
	printf("     M$$$$$$$$$$$$$$$$$$$M\n");
	printf("     M$$$$$$$$$$$$$$$$$$$M\n");
	printf("     M$$$$$$$$$$$$$$$$$$$M\n");
	printf("     MMMMMMMMMMMMMMMMMMMMM\n");
	milli_delay(1000);
	///////////////////////////////////////////////////////////////////////////////
	clear();
	printf("                            OO\n");
	printf("                           OO\n");
	printf("                          OO\n");
	printf("                         OO\n");
	printf("                        OO\n");
	printf("     M                 OOM\n");
	printf("     M                OO M\n");
	printf("     M               OO  M\n");
	printf("     M              OO   M\n");
	printf("     M             OO    M\n");
	printf("     M            OO     M\n");
	printf("     M           OO      M\n");
	printf("     M          OO       M\n");
	printf("     M         OO        M\n");
	printf("     M        OO         M\n");
	printf("     M       OO          M\n");
	printf("     M      OO           M\n");
	printf("     M     OO            M\n");
	printf("     M    OO             M\n");
	printf("     M   OO              M\n");
	printf("     M$$OO$$$$$$$$$$$$$$$M\n");
	printf("     M$OO$$$$$$$$$$$$$$$$M\n");
	printf("     MOO$$$$$$$$$$$$$$$$$M\n");
	printf("     MMMMMMMMMMMMMMMMMMMMM\n");
	milli_delay(1000);
	///////////////////////////////////////////////////////////////////////////////
	clear();
	printf("                            OO\n");
	printf("                           OO\n");
	printf("                          OO\n");
	printf("                         OO\n");
	printf("                        OO\n");
	printf("     M                 OOM\n");
	printf("     M                OO M\n");
	printf("     M               OO  M\n");
	printf("     M              OO   M\n");
	printf("     M             OO    M\n");
	printf("     M            OO     M\n");
	printf("     M           OO      M\n");
	printf("     M          OO       M\n");
	printf("     M         OO        M\n");
	printf("     M        OO         M\n");
	printf("     M       OO          M\n");
	printf("     M      OO           M           EEEEEE MMM MMM PPPPPPP TTTTTTTT Y     Y\n");
	printf("     M     OO            M           E      M  M  M P     P    TT     Y   Y\n");
	printf("     M    OO             M           E      M  M  M P     P    TT      Y Y\n");
	printf("     M   OO              M           EEEEEE M  M  M PPPPPPP    TT       Y\n");
	printf("     M  OO               M           E      M  M  M P          TT       Y\n");
	printf("     M OO                M           E      M  M  M P          TT       Y\n");
	printf("     MOO                 M           EEEEEE M  M  M P          TT       Y\n");
	printf("     MMMMMMMMMMMMMMMMMMMMM\n");
	milli_delay(1000);
	clear();
	printf("\n\n\n\n\n\n");
	printf("                 o(x____x)o-------------------------------o(x____x)o\n");
	printf("                                     MCinix\n");
	printf("                                 Has Been Ended!\n");
	printf("                 o(x____x)o-------------------------------o(x____x)o\n");
	for(i = 0;i < 20; ++i)
	{
		milli_delay(100);
	}
	shutdown();
}

void Help()//帮助信息
{
	printf("o(x____x)o------------------------------------------------------------o(x____x)o\n");
        printf("--------------------------------------------------------------------------------\n\n");
	printf("                         HELP INFORMATION\n");
        printf("1. manageprocess---Start to manage your processes\n\n");
	printf("2. processinfo-----Show the information of your processes\n\n");
        printf("3. endsystem-------End the system\n\n");
        printf("4. fiveinarow------Play Five in a Row\n\n");
	printf("5. clear-----------Clear the screen\n\n");
        printf("6. play------------Play a cartoon\n\n");
	printf("7. help------------Show the help information\n\n");
        printf("--------------------------------------------------------------------------------\n");
	printf("o(x____x)o------------------------------------------------------------o(x____x)o\n");		
}

void calculator(){

        clear();
        printf("o(x____x)o------------------------------------------------------------o(x____x)o\n");
        printf("--------------------------A SIMPLE CALCULATOR---------------------------------\n\n");
        printf("---------------------------------BOOM-----------------------------------------\n");
	printf("o(x____x)o------------------------------------------------------------o(x____x)o\n");		

        Calculator=1;
        
}


void ProcessInfo()//显示进程信息
{
	int i;
	printf("o(x____x)o------------------------------------------------------------o(x____x)o\n");
	printf("Process ID -- Process Name --    Process Priority -- UserProc?\n");
	printf("o(x____x)o------------------------------------------------------------o(x____x)o\n");
	for ( i = 0 ; i < MAX_TASKS_PROCS ; ++i )
	{
		if ( proc_table[i].priority == 0) continue;
	printf("     %d          %s            %2d            %d\n", proc_table[i].pid, proc_table[i].p_name, proc_table[i].priority,
        proc_table[i].task_or_no);
	}
	printf("o(x____x)o------------------------------------------------------------o(x____x)o\n");
}

void sys_shutdown(PROCESS * p_proc)//关闭系统
{
	int i;
	disable_int();
	for ( i = 0 ; i < 16 ; ++i )
	{
		disable_irq(i);
	}
	while(1) {}
}

void strtolower(char * src)//大小写字母转换
{
	while (*src)
	{
		if ((*src >= 'A') && (*src <= 'Z'))
		{
			*src += 'a' - 'A';
		}
		++src;
	}
}

int strcmp(char * src, char * dst)//匹配字符串
{
	while ( *src && *dst && *src == *dst) { ++src, ++dst; };
	return *src - *dst;
}

void DisPlay()//开机动画
{
	int color = 0x7f;
	clear();
	printf("      HHHHHHHHHHHHH\n");
	printf("      HHHH     HHHH\n");
	printf("         H     H\n");
	printf("         H     H\n");
	printf("HHHHHHHHH       HHHHHHHHHH\n");
	printf("$                          H\n");
	printf("$                           H\n");
	printf("HHHHHHHHH       HHHH         H\n");
	printf("         W     W    H        H\n");
	printf("          WWWWW     H        H\n");
	printf("                    HHHHHHHHHH\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");

	printf("             Q                      Q\n");
	printf("             Q                      Q\n");
	printf("             Q                      Q\n");
	printf("             Q                      Q\n");
	printf("             Q                      Q\n");
	printf("             Q                      Q\n");
	printf("             Q                      Q\n");
	printf("             Q                      Q\n");
	printf("             Q======================Q\n");
	milli_delay(1000);
	///////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////
	clear();
	printf("      HHHHHHHHHHHHH\n");
	printf("      HHHH     HHHH\n");
	printf("         H     H\n");
	printf("         H     H\n");
	printf("HHHHHHHHH       HHHHHHHHHH\n");
	printf("$                          H\n");
	printf("$                           H\n");
	printf("HHHHHHHHH       HHHH         H\n");
	printf("         W     W    H        H\n");
	printf("          WWWWW     H        H\n");
	printf("                    HHHHHHHHHH\n");
	printf("                        AA\n");
	printf("                       AAAA\n");
	printf("                     AAAAAAAA\n");
	printf("                    AAAAAAAAAA\n");

	printf("             Q                      Q\n");
	printf("             Q                      Q\n");
	printf("             Q                      Q\n");
	printf("             Q                      Q\n");
	printf("             Q                      Q\n");
	printf("             Q                      Q\n");
	printf("             Q                      Q\n");
	printf("             Q                      Q\n");
	printf("             Q======================Q\n");

	milli_delay(1000);
	///////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////
	clear();
	printf("      HHHHHHHHHHHHH\n");
	printf("      HHHH     HHHH\n");
	printf("         H     H\n");
	printf("         H     H\n");
	printf("HHHHHHHHH       HHHHHHHHHH\n");
	printf("$                          H\n");
	printf("$                           H\n");
	printf("HHHHHHHHH       HHHH         H\n");
	printf("         W     W    H        H\n");
	printf("          WWWWW     H        H\n");
	printf("                    HHHHHHHHHH\n");
	printf("                        AA\n");
	printf("                       AAAA\n");
	printf("                     AAAAAAAA\n");
	printf("                    AAAAAAAAAA\n");

	printf("             Q                      Q\n");
	printf("             Q                      Q\n");
	printf("             Q                      Q\n");
	printf("             Q                      Q\n");
	printf("             Q                      Q\n");
	printf("             Q                      Q\n");
	printf("             Q                      Q\n");
	printf("             QAAAAAAAAAAAAAAAAAAAAAAQ\n");
	printf("             Q======================Q\n");
	milli_delay(1000);
	///////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////
	clear();
	printf("      HHHHHHHHHHHHH\n");
	printf("      HHHH     HHHH\n");
	printf("         H     H\n");
	printf("         H     H\n");
	printf("HHHHHHHHH       HHHHHHHHHH\n");
	printf("$                          H\n");
	printf("$                           H\n");
	printf("HHHHHHHHH       HHHH         H\n");
	printf("         W     W    H        H\n");
	printf("          WWWWW     H        H\n");
	printf("                    HHHHHHHHHH\n");
	printf("                        AA\n");
	printf("                       AAAA\n");
	printf("                     AAAAAAAA\n");
	printf("                    AAAAAAAAAA\n");

	printf("             Q                      Q\n");
	printf("             Q                      Q\n");
	printf("             Q                      Q\n");
	printf("             Q                      Q\n");
	printf("             Q                      Q\n");
	printf("             Q                      Q\n");
	printf("             QAAAAAAAAAAAAAAAAAAAAAAQ\n");
	printf("             QAAAAAAAAAAAAAAAAAAAAAAQ\n");
	printf("             Q======================Q\n");
	milli_delay(1000);
	///////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////
	clear();
	printf("      HHHHHHHHHHHHH\n");
	printf("      HHHH     HHHH\n");
	printf("         H     H\n");
	printf("         H     H\n");
	printf("HHHHHHHHH       HHHHHHHHHH\n");
	printf("$                          H\n");
	printf("$                           H\n");
	printf("HHHHHHHHH       HHHH         H\n");
	printf("         W     W    H        H\n");
	printf("          WWWWW     H        H\n");
	printf("                    HHHHHHHHHH\n");
	printf("                        AA\n");
	printf("                       AAAA\n");
	printf("                     AAAAAAAA\n");
	printf("                    AAAAAAAAAA\n");

	printf("             Q                      Q\n");
	printf("             Q                      Q\n");
	printf("             Q                      Q\n");
	printf("             Q                      Q\n");
	printf("             Q                      Q\n");
	printf("             QAAAAAAAAAAAAAAAAAAAAAAQ\n");
	printf("             QAAAAAAAAAAAAAAAAAAAAAAQ\n");
	printf("             QAAAAAAAAAAAAAAAAAAAAAAQ\n");
	printf("             Q======================Q\n");
	milli_delay(1000);
	///////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////
	clear();
	printf("      HHHHHHHHHHHHH\n");
	printf("      HHHH     HHHH\n");
	printf("         H     H\n");
	printf("         H     H\n");
	printf("HHHHHHHHH       HHHHHHHHHH\n");
	printf("$                          H\n");
	printf("$                           H\n");
	printf("HHHHHHHHH       HHHH         H\n");
	printf("         W     W    H        H\n");
	printf("          WWWWW     H        H\n");
	printf("                    HHHHHHHHHH\n");
	printf("                        AA\n");
	printf("                       AAAA\n");
	printf("                     AAAAAAAA\n");
	printf("                    AAAAAAAAAA\n");

	printf("             Q                      Q\n");
	printf("             Q                      Q\n");
	printf("             Q                      Q\n");
	printf("             Q                      Q\n");
	printf("             QAAAAAAAAAAAAAAAAAAAAAAQ\n");
	printf("             QAAAAAAAAAAAAAAAAAAAAAAQ\n");
	printf("             QAAAAAAAAAAAAAAAAAAAAAAQ\n");
	printf("             QAAAAAAAAAAAAAAAAAAAAAAQ\n");
	printf("             Q======================Q\n");
	milli_delay(1000);
	///////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////
	clear();
	printf("      HHHHHHHHHHHHH\n");
	printf("      HHHH     HHHH\n");
	printf("         H     H\n");
	printf("         H     H\n");
	printf("HHHHHHHHH       HHHHHHHHHH\n");
	printf("$                          H\n");
	printf("$                           H\n");
	printf("HHHHHHHHH       HHHH         H\n");
	printf("         W     W    H        H\n");
	printf("          WWWWW     H        H\n");
	printf("                    HHHHHHHHHH\n");
	printf("                        AA\n");
	printf("                       AAAA\n");
	printf("                     AAAAAAAA\n");
	printf("                    AAAAAAAAAA\n");

	printf("             Q                      Q\n");
	printf("             Q                      Q\n");
	printf("             Q                      Q\n");
	printf("             QAAAAAAAAAAAAAAAAAAAAAAQ\n");
	printf("             QAAAAAAAAAAAAAAAAAAAAAAQ\n");
	printf("             QAAAAAAAAAAAAAAAAAAAAAAQ\n");
	printf("             QAAAAAAAAAAAAAAAAAAAAAAQ\n");
	printf("             QAAAAAAAAAAAAAAAAAAAAAAQ\n");
	printf("             Q======================Q\n");
	milli_delay(1000);
	///////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////
	clear();
	printf("      HHHHHHHHHHHHH\n");
	printf("      HHHH     HHHH\n");
	printf("         H     H\n");
	printf("         H     H\n");
	printf("HHHHHHHHH       HHHHHHHHHH\n");
	printf("$                          H\n");
	printf("$                           H\n");
	printf("HHHHHHHHH       HHHH         H\n");
	printf("         W     W    H        H\n");
	printf("          WWWWW     H        H\n");
	printf("                    HHHHHHHHHH\n");
	printf("                        AA\n");
	printf("                       AAAA\n");
	printf("                     AAAAAAAA\n");
	printf("                    AAAAAAAAAA\n");

	printf("             Q                      Q\n");
	printf("             Q                      Q\n");
	printf("             QAAAAAAAAAAAAAAAAAAAAAAQ\n");
	printf("             QAAAAAAAAAAAAAAAAAAAAAAQ\n");
	printf("             QAAAAAAAAAAAAAAAAAAAAAAQ\n");
	printf("             QAAAAAAAAAAAAAAAAAAAAAAQ\n");
	printf("             QAAAAAAAAAAAAAAAAAAAAAAQ\n");
	printf("             QAAAAAAAAAAAAAAAAAAAAAAQ\n");
	printf("             Q======================Q\n");
	milli_delay(1000);
	///////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////
	clear();
	printf("      HHHHHHHHHHHHH\n");
	printf("      HHHH     HHHH\n");
	printf("         H     H\n");
	printf("         H     H\n");
	printf("HHHHHHHHH       HHHHHHHHHH\n");
	printf("$                          H\n");
	printf("$                           H\n");
	printf("HHHHHHHHH       HHHH         H\n");
	printf("         W     W    H        H\n");
	printf("          WWWWW     H        H\n");
	printf("                    HHHHHHHHHH\n");
	printf("                        AA\n");
	printf("                       AAAA\n");
	printf("                     AAAAAAAA\n");
	printf("                    AAAAAAAAAA\n");

	printf("             Q                      Q\n");
	printf("             QAAAAAAAAAAAAAAAAAAAAAAQ\n");
	printf("             QAAAAAAAAAAAAAAAAAAAAAAQ\n");
	printf("             QAAAAAAAAAAAAAAAAAAAAAAQ\n");
	printf("             QAAAAAAAAAAAAAAAAAAAAAAQ\n");
	printf("             QAAAAAAAAAAAAAAAAAAAAAAQ\n");
	printf("             QAAAAAAAAAAAAAAAAAAAAAAQ\n");
	printf("             QAAAAAAAAAAAAAAAAAAAAAAQ\n");
	printf("             Q======================Q\n");
	milli_delay(1000);
	///////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////
	clear();
	printf("      HHHHHHHHHHHHH\n");
	printf("      HHHH     HHHH\n");
	printf("         H     H\n");
	printf("         H     H\n");
	printf("HHHHHHHHH       HHHHHHHHHH\n");
	printf("$                          H\n");
	printf("$                           H\n");
	printf("HHHHHHHHH       HHHH         H\n");
	printf("         W     W    H        H\n");
	printf("          WWWWW     H        H\n");
	printf("                    HHHHHHHHHH\n");
	printf("                        AA\n");
	printf("                       AAAA\n");
	printf("                     AAAAAAAA\n");
	printf("                    AAAAAAAAAA\n");

	printf("             QAAAAAAAAAAAAAAAAAAAAAAQ\n");
	printf("             QAAAAAAAAAAAAAAAAAAAAAAQ\n");
	printf("             QAAAAAAAAAAAAAAAAAAAAAAQ\n");
	printf("             QAAAAAAAAAAAAAAAAAAAAAAQ\n");
	printf("             QAAAAAAAAAAAAAAAAAAAAAAQ\n");
	printf("             QAAAAAAAAAAAAAAAAAAAAAAQ\n");
	printf("             QAAAAAAAAAAAAAAAAAAAAAAQ\n");
	printf("             QAAAAAAAAAAAAAAAAAAAAAAQ\n");
	printf("             Q======================Q\n");
	milli_delay(1000);
	///////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////
	clear();
	printf("      HHHHHHHHHHHHH\n");
	printf("      HHHH     HHHH\n");
	printf("         H     H\n");
	printf("         H     H\n");
	printf("HHHHHHHHH       HHHHHHHHHH\n");
	printf("$                          H\n");
	printf("$                           H\n");
	printf("HHHHHHHHH       HHHH         H\n");
	printf("         W     W    H        H\n");
	printf("          WWWWW     H        H\n");
	printf("                    HHHHHHHHHH\n");
	printf("                        AA\n");
	printf("                       AAAA\n");
	printf("                     AAAAAAAA\n");
	printf("                    AAAAAAAAAA\n");

	printf("             QAAAAAAAAAAAAAAAAAAAAAAQA\n");
	printf("             QAAAAAAAAAAAAAAAAAAAAAAQAA\n");
    printf("             QAAAAAAAAAAAAAAAAAAAAAAQAAA\n");
	printf("             QAAAAAAAAAAAAAAAAAAAAAAQAAAA\n");
	printf("             QAAAAAAAAAAAAAAAAAAAAAAQAAAA\n");
	printf("             QAAAAAAAAAAAAAAAAAAAAAAQAAAA\n");
	printf("             QAAAAAAAAAAAAAAAAAAAAAAQAAAAAAA\n");
	printf("             QAAAAAAAAAAAAAAAAAAAAAAQAAAAAAAAA\n");
	printf("             Q======================QAAAAAAAAAAAAAA\n");
	milli_delay(1000);
	///////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////
	clear();
	printf("      HHHHHHHHHHHHH\n");
	printf("      HHHH     HHHH\n");
	printf("         H     H\n");
	printf("         H     H\n");
	printf("HHHHHHHHH       HHHHHHHHHH\n");
	printf("$                          H\n");
	printf("$                           H\n");
	printf("HHHHHHHHH       HHHH         H\n");
	printf("         W     W    H        H\n");
	printf("          WWWWW     H        H\n");
	printf("                    HHHHHHHHHH\n");
	printf("\n");
	
	printf("                       AA\n");
	printf("                      AAAA\n");
        printf("\n");
	printf("             QAAAAAAAAAAAAAAAAAAAAAAQ                  FFFFF U    U E     E\n");
	printf("             QAAAAAAAAAAAAAAAAAAAAAAQ                  F     U    U E     E\n");
	printf("             QAAAAAAAAAAAAAAAAAAAAAAQ                  FFFFF U    U E     E\n");
	printf("             QAAAAAAAAAAAAAAAAAAAAAAQ                  F     U    U E     E\n");
	printf("             QAAAAAAAAAAAAAAAAAAAAAAQ                  E     UUUUUU LLLLL LLLLL\n");
	printf("             QAAAAAAAAAAAAAAAAAAAAAAQ\n");
	printf("             QAAAAAAAAAAAAAAAAAAAAAAQ\n");
	printf("             QAAAAAAAAAAAAAAAAAAAAAAQAAAAAAAAAAAAAAAAAAAA\n");
	printf("             Q======================QAAAAAAAAAAAAAAAAAAAAAAAA\n");
	milli_delay(1000);
}

