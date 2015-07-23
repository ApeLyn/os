
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                               tty.c
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                                                    Forrest Yu, 2005
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

#include "type.h"
#include "const.h"
#include "protect.h"
#include "string.h"
#include "proc.h"
#include "tty.h"
#include "console.h"
#include "global.h"
#include "keyboard.h"
#include "proto.h"

#define TTY_FIRST	(tty_table)
#define TTY_END		(tty_table + NR_CONSOLES)

PRIVATE void init_tty(TTY* p_tty);
PRIVATE void tty_do_read(TTY* p_tty);
PRIVATE void tty_do_write(TTY* p_tty);
PRIVATE void put_key(TTY* p_tty, u32 key);

PRIVATE char t[10]={'a','a','a','a','a','a','a','a','a','a'};
PRIVATE char temp[2]={'0','\0'};
PRIVATE	int count;
PRIVATE	int cal_count;
PRIVATE	int end_count;
PRIVATE	int first_nod;
PRIVATE	int second_nod;
/*======================================================================*
                           task_tty
 *======================================================================*/
PUBLIC void task_tty()
{
	TTY*	p_tty;

	init_keyboard();

	for (p_tty=TTY_FIRST;p_tty<TTY_END;p_tty++) {
		init_tty(p_tty);
	}
	select_console(0);
	while (1) {
		for (p_tty=TTY_FIRST;p_tty<TTY_END;p_tty++) {
			tty_do_read(p_tty);
			tty_do_write(p_tty);
		}
	}
}

/*======================================================================*
			   init_tty
 *======================================================================*/
PRIVATE void init_tty(TTY* p_tty)
{
	p_tty->inbuf_count = 0;
	p_tty->p_inbuf_head = p_tty->p_inbuf_tail = p_tty->in_buf;

	init_screen(p_tty);
}

/*======================================================================*
				in_process
 *======================================================================*/
PUBLIC void in_process(TTY* p_tty, u32 key)
{

        char output[2] = {'\0', '\0'};
        if (!(key & FLAG_EXT)) {
                output[0] = key & 0xFF;
                if(t[0]=='a'){
                  // disp_str(temp);
                   count=0;
                   cal_count=-1;
                   first_nod=-1;
                   second_nod=-1;
                }
                t[count]=output[0];
                if(output[0]=='+'){//cal
                cal_count=count;
               }else if(output[0]=='-'){
                cal_count=count;
               }else  if(output[0]=='*'){
                cal_count=count;
               }else if(output[0]=='/'){
                cal_count=count;
               }else if(output[0]=='='){
                end_count=count;
               }
                //set node count
               if(output[0]=='.'&&cal_count==-1){
                first_nod=count;
               }else if(output[0]=='.'&&cal_count!=-1){
                second_nod=count;
               }
               if(output[0]=='='){
                printf("=");
                
                if(first_nod==-1){
                  first_nod=cal_count;
                }
                if(second_nod==-1){
                  second_nod=end_count;
                }
                int first=0;
                int second=0;
                int first_n=0;
                int second_n=0;
                int first_wei=first_nod-1;
                int second_wei=second_nod-cal_count-2;
                int first_nod_wei=cal_count-first_nod-2;
                int second_nod_wei=end_count-second_nod-2;
                if(first_nod_wei==-2){
                   first_nod_wei=-1;
                }

                if(second_nod_wei==-2){
                   second_nod_wei=-1;
                }
                int mul=1;
                int i;
                int j; 
                int f_n_w=first_nod_wei;
                int s_n_w=second_nod_wei;
               //first before . num
                 for(i=0;i<first_nod;i++){
                    int num=t[i]-48;
                    mul=1;
                    for(j=0;j<first_wei;j++){
                      mul=mul*10;
                    }
                    first=first+num*mul;
                    first_wei--;
                 }
               //first after . num
                 for(i=first_nod+1;i<cal_count;i++){
                    int num=t[i]-48;
                    mul=1;
                    for(j=0;j<first_nod_wei;j++){
                      mul=mul*10;
                    }
                    first_n=first_n+num*mul;
                    first_nod_wei--;
                 }
            //  printf("first is :");
             // printf("%d",first);
            //  printf(".");
           //   printf("%d",first_n);
              // disp_str(temp);
              //second before . num
              for(i=cal_count+1;i<second_nod;i++){
                    int num=t[i]-48;
                    mul=1;
                    for(j=0;j<second_wei;j++){
                      mul=mul*10;
                    }
                    second=second+num*mul;
                    second_wei--;
                 }
              //second after . num
              for(i=second_nod+1;i<end_count;i++){
                    int num=t[i]-48;
                    mul=1;
                    for(j=0;j<second_nod_wei;j++){
                      mul=mul*10;
                    }
                    second_n=second_n+num*mul;
                    second_nod_wei--;
                 }
             // printf("second is :");
             // printf("%d",second);
             // printf(".");
            //  printf("%d",second_n);

               int result=0;
               int result_n=0;
               int wei=1;
               if(t[cal_count]=='+'){      //add
                   int max=f_n_w+1;
                   if(f_n_w>s_n_w){
                      int i=0;
                      for(i=0;i<f_n_w-s_n_w;i++){
                         second_n=second_n*10;
                      }                      
                   }else if(f_n_w<s_n_w){
                      int i=0;
                      max=s_n_w+1;
                      for(i=0;i<s_n_w-f_n_w;i++){
                         first_n=first_n*10; 
                      } 
                   }
                   int i;
                  // printf("max is");
                  // printf("%d",max);
                   for(i=0;i<max;i++){
                       wei=wei*10;
                       //printf("loop");
                   }
                   int _n=first_n+second_n;
                   int add=_n/wei;
                   //printf("wei is");
                   //printf("%d",wei);
                   //printf("add is");
                   //printf("%d",add);
                   result_n=_n%wei;
                   result=first+second+add;
               }else if(t[cal_count]=='-'){// minus
		int temp=0;
                if(first>=second){
                  
                }else{
                  temp=first;
                  first=second;
                  second=temp;
  
                  temp=first_n;
                  first_n=second_n;
                  second_n=temp;

                  temp=f_n_w;
                  f_n_w=s_n_w;
                  s_n_w=temp;
                  printf("-");
                }
                int max=f_n_w+1;
                   if(f_n_w>s_n_w){
                      int i=0;
                      for(i=0;i<f_n_w-s_n_w;i++){
                         second_n=second_n*10;
                      }                      
                   }else if(f_n_w<s_n_w){
                      int i=0;
                      max=s_n_w+1;
                      for(i=0;i<s_n_w-f_n_w;i++){
                         first_n=first_n*10; 
                      } 
                   }
                   int i;
                  // printf("max is");
                  // printf("%d",max);
                   for(i=0;i<max;i++){
                       wei=wei*10;
                       //printf("loop");
                   }
                   int _n=wei+first_n-second_n;
                   int add=_n/wei;
                   first=first-1;
                   //printf("wei is");
                   //printf("%d",wei);
                   //printf("add is");
                   //printf("%d",add);
                   result_n=_n%wei;
                   result=first-second+add;
               }else if(t[cal_count]=='*'){// mul
                   result=first*second;
                   for(i=0;i<f_n_w+1;i++){
                      first=first*10;
                   }
                   first=first+first_n;

                   for(i=0;i<s_n_w+1;i++){
                      second=second*10;
                   }
                   second=second+second_n;
                   
                   int mul=first*second;

                   for(i=0;i<f_n_w+s_n_w+2;i++){
                      wei=wei*10;
                   }

                   result=mul/wei;
                   result_n=mul%wei;
               }else if(t[cal_count]=='/'){//devide
                   
                  // result=first*second;
                   for(i=0;i<f_n_w+1;i++){
                      first=first*10;
                   }
                   first=first+first_n;

                   for(i=0;i<4;i++){
                      first=first*10;
                   }
                   for(i=0;i<s_n_w+1;i++){
                      second=second*10;
                   }
                   second=second+second_n;
                   
                   int mul=first/second;
                   int temp=0;
                  if(f_n_w>=s_n_w){
                  
                  }else{
                    temp=f_n_w;
                    f_n_w=s_n_w;
                    s_n_w=temp;
                  } 
                   for(i=0;i<f_n_w-s_n_w+4;i++){
                      wei=wei*10;
                   }

                   result=mul/wei;
                   result_n=mul%wei;
               } 
              // printf("result is:");
	       printf("%d",result);
               if(result_n!=0){
               printf(".");
               int c_wei=wei/10;
               for(i=c_wei;i>=1;i=i/10){
                   printf("%d",result_n/c_wei);
                   result_n=result_n%c_wei;
                   c_wei=c_wei/10;
               }
               }
               //array change to 'a'}
               for(i=0;i<10;i++){
                   t[i]='a';
                }
               put_key(p_tty, '\n');
               }else{
                put_key(p_tty, key);
               }
               count=count+1;
        }
        else {
                //printf("%d",2);
                int raw_code = key & MASK_RAW;
                switch(raw_code) {
                case ENTER:
			put_key(p_tty, '\n');
			break;
                case BACKSPACE:
                        count--;
                        t[count]='a';
			put_key(p_tty, '\b');
			break;
                case UP:
                        if ((key & FLAG_SHIFT_L) || (key & FLAG_SHIFT_R)) {
				scroll_screen(p_tty->p_console, SCR_DN);
                        }
			break;
		case DOWN:
			if ((key & FLAG_SHIFT_L) || (key & FLAG_SHIFT_R)) {
				scroll_screen(p_tty->p_console, SCR_UP);
			}
			break;
		case F1:
		case F2:
		case F3:
		case F4:
		case F5:
		case F6:
		case F7:
		case F8:
		case F9:
		case F10:
		case F11:
		case F12:
			/* Alt + F1~F12 */
			if ((key & FLAG_ALT_L) || (key & FLAG_ALT_R)) {
				select_console(raw_code - F1);
			}
			break;
                default:
                        break;
                }
        }
}

/*======================================================================*
			      put_key
*======================================================================*/
PRIVATE void put_key(TTY* p_tty, u32 key)
{
	if (p_tty->inbuf_count < TTY_IN_BYTES) {
		*(p_tty->p_inbuf_head) = key;
		p_tty->p_inbuf_head++;
		if (p_tty->p_inbuf_head == p_tty->in_buf + TTY_IN_BYTES) {
			p_tty->p_inbuf_head = p_tty->in_buf;
		}
		p_tty->inbuf_count++;
	}
        //int i=1234;
       // printf("%d",i);
}


/*======================================================================*
			      tty_do_read
 *======================================================================*/
PRIVATE void tty_do_read(TTY* p_tty)
{
	if (is_current_console(p_tty->p_console)) {
		keyboard_read(p_tty);
	}
}


/*======================================================================*
			      tty_do_write
 *======================================================================*/
PRIVATE void tty_do_write(TTY* p_tty)
{
	if (p_tty->inbuf_count) {
		char ch = *(p_tty->p_inbuf_tail);
		p_tty->p_inbuf_tail++;
		if (p_tty->p_inbuf_tail == p_tty->in_buf + TTY_IN_BYTES) {
			p_tty->p_inbuf_tail = p_tty->in_buf;
		}
		p_tty->inbuf_count--;

		out_char(p_tty->p_console, ch);
	}
}

/*======================================================================*
                              tty_write
*======================================================================*/
PUBLIC void tty_write(TTY* p_tty, char* buf, int len)
{
        char* p = buf;
        int i = len;

        while (i) {
                out_char(p_tty->p_console, *p++);
                i--;
        }
}

/*======================================================================*
                              sys_write
*======================================================================*/
PUBLIC int sys_write(char* buf, int len, PROCESS* p_proc)
{
        tty_write(&tty_table[p_proc->nr_tty], buf, len);
        return 0;
}

