
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                               tty.c
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                                                    Forrest Yu, 2005
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

#include "type.h"
#include "const.h"
#include "protect.h"
#include "proto.h"
#include "string.h"
#include "proc.h"
#include "global.h"
#include "keyboard.h"

PRIVATE char t[10]={'a','a','a','a','a','a','a','a','a','a'};
PRIVATE char temp[2]={'0','\0'};
PRIVATE	int count;
PRIVATE	int cal_count;
PRIVATE	int end_count;
/*======================================================================*
                           task_tty
 *======================================================================*/
PUBLIC void task_tty()
{
	while (1) {
		keyboard_read();
	}
}

/*======================================================================*
				in_process
 *======================================================================*/
PUBLIC void in_process(u32 key)
{
        char output[2] = {'\0', '\0'};
        if (!(key & FLAG_EXT)) {
                output[0] = key & 0xFF;
                if(t[0]=='a'){
                  // disp_str(temp);
                   count=0;
                }
                t[count]=output[0];
                disp_str(output);
                //out put
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
               int r=1234; 
               Ddisp_int(r);
               if(output[0]=='='){
                int first=0;
                int second=0;
                int first_wei=cal_count-1;
                int second_wei=end_count-cal_count-2;
                int mul=1;
                int i;
                int j; 
               //first num
                 for(i=0;i<cal_count;i++){
                    int num=t[i]-48;
                    mul=1;
                    for(j=0;j<first_wei;j++){
                      mul=mul*10;
                    }
                    first=first+num*mul;
                    first_wei--;
                 }
              
              // disp_str(temp);
               //second num
                 for(i=cal_count+1;i<end_count;i++){
                    int num=t[i]-48;
                    mul=1;
                    for(j=0;j<second_wei;j++){
                      mul=mul*10;
                    }
                    second=second+num*mul;
                    second_wei--;
                 }
              
               int result=first+second;
		//int r = result/5;
               if(result==24){
                //Ddisp_int(result);
		disp_str(result);
               }
               //temp[0]=result;
               // disp_str(temp);
               //array change to 'a'
               for(i=0;i<10;i++){
                   t[i]='a';
                }
               } 
               count=count+1;
        }
}

