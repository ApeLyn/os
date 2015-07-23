
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                              console.h
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                                                    �ϳ�����������˳ΰ����ƃ
                                                         2008��7��
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

#ifndef	_TINIX_CONSOLE_H_
#define	_TINIX_CONSOLE_H_


/* CONSOLE */
typedef struct s_console
{
	//struct s_tty*	p_tty;
	unsigned int	current_start_addr;	/* ��ǰ��ʾ����ʲôλ��   */
	unsigned int	original_addr;		/* ��ǰ����̨��Ӧ�Դ�λ�� */
	unsigned int	v_mem_limit;		/* ��ǰ����̨ռ���Դ��С */
	unsigned int	cursor;			/* ��ǰ���λ�� */
}CONSOLE;


#define SCROLL_SCREEN_UP	1	/* scroll forward */
#define SCROLL_SCREEN_DOWN	-1	/* scroll backward */

#define SCREEN_SIZE		(80 * 25)
#define SCREEN_WIDTH		80

#define DEFAULT_CHAR_COLOR	0x07	/* 0000 0111 �ڵװ��� */


#endif /* _TINIX_CONSOLE_H_ */