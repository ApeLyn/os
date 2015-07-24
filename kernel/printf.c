
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                              printf.c
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                                                    孟辰、夏欣、侯顺伟、杨苾
                                                         2008年7月
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

#include "type.h"
#include "const.h"
#include "string.h"

/******************************************************************************************
                        可变参数函数调用原理（其中涉及的数字皆为举例）
===========================================================================================

i = 0x23;
j = 0x78;
char fmt[] = "%x%d";
printf(fmt, i, j);

        push    j
        push    i
        push    fmt
        call    printf
        add     esp, 3 * 4


                ┃        HIGH        ┃                        ┃        HIGH        ┃
                ┃        ...         ┃                        ┃        ...         ┃
                ┣━━━━━━━━━━┫                        ┣━━━━━━━━━━┫
                ┃                    ┃                 0x32010┃        '\0'        ┃
                ┣━━━━━━━━━━┫                        ┣━━━━━━━━━━┫
         0x3046C┃        0x78        ┃                 0x3200c┃         d          ┃
                ┣━━━━━━━━━━┫                        ┣━━━━━━━━━━┫
   arg = 0x30468┃        0x23        ┃                 0x32008┃         %          ┃
                ┣━━━━━━━━━━┫                        ┣━━━━━━━━━━┫
         0x30464┃      0x32000 ───╂────┐       0x32004┃         x          ┃
                ┣━━━━━━━━━━┫        │              ┣━━━━━━━━━━┫
                ┃                    ┃        └──→ 0x32000┃         %          ┃
                ┣━━━━━━━━━━┫                        ┣━━━━━━━━━━┫
                ┃        ...         ┃                        ┃        ...         ┃
                ┃        LOW         ┃                        ┃        LOW         ┃

实际上，调用 vsprintf 的情形是这样的：

        vsprintf(buf, 0x32000, 0x30468);

******************************************************************************************/

/*======================================================================*
                                 printf
 *======================================================================*/
int printf(const char *fmt, ...)
{
	int i;
	char buf[256];

	va_list arg = (va_list)((char*)(&fmt) + 4);        /* 4 是参数 fmt 所占堆栈中的大小 */
	i = vsprintf(buf, fmt, arg);
	write(buf, i);

	return i;
}


/*======================================================================*
                                 vsprintf
 *======================================================================*/
int vsprintf(char * buf, const char * fmt, va_list args)
{
	char * p;
	char tmp[256];
	va_list p_next_arg = args;
	for ( p = buf ; *fmt ; fmt++ )
	{
		if ( *fmt != '%' )
		{
			*p++ = *fmt;
			continue;
		}
		
		fmt++;
		
		switch (*fmt)
		{
		case 's':
			{
				strcpy(p, *(char **)(p_next_arg));
				int iStrLen = strlen(*(char **)(p_next_arg));
				p[iStrLen]=0;
				p += iStrLen;
				p_next_arg += 4;
				break;
			}
		case 'c':
			*p++ = *p_next_arg;
			p_next_arg += 4;
			break;
		case 'd':
			{
				_itoa(tmp, *((int *)p_next_arg));		
				int iStrLen = strlen(tmp);
				strcpy(p, tmp);
				p += iStrLen;
				p_next_arg += 4;
			}
			break;
		default:
			if (*fmt>='0'&&*fmt<='9')
			{
				//先把显示多少个探清楚。
				int itotal=0;
				int itempnum;
				int i;
				int iStrLen;
				for (i=0;*fmt>='0'&&*fmt<='9';i++,fmt++)
				{
					//_atoi(&(*fmt),itempnum);
					itempnum=*fmt-48;
					itotal=itotal*10+itempnum;
				}
				itotal=itotal%20;
				if (*fmt=='d')
				{
					_itoa(tmp, *((int *)p_next_arg));		
					iStrLen = strlen(tmp);
					if (iStrLen<itotal)
					{
						for (i=0;i<itotal-iStrLen;i++)
						{
							*p=' ';
							p++;
						}
					}
					strcpy(p, tmp);
					p += iStrLen;
					p_next_arg += 4;
				}
				else if (*fmt=='c')
				{
					for (i=0;i<itotal-1;i++)
					{
						*p=' ';
						p++;
					}
					*p++ = *p_next_arg;
					p_next_arg += 4;
				}
				else if (*fmt =='s')
				{
					strcpy(p, *(char **)(p_next_arg));
					iStrLen = strlen(*(char **)(p_next_arg));
					if (iStrLen<itotal)
					{
						for (i=0;i<itotal-iStrLen;i++)
						{
							*p=' ';
							p++;
						}
					}
					p[iStrLen]=0;
					p += iStrLen;
					p_next_arg += 4;
				}
			}
			break;
		}
	}
	return (p - buf);
}

