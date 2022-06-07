#include "app_main.h"

char u8InitGLobalVar = 2;
static long int u32NonInitStaticGlobalVar;
const short int u16ConstGlobalVar = 3;
//#pragma location=".sprints";
__attribute__((section(".sprints")))
int arr[10] = {0,1,2,3,4,5,6,7,8,9};

void main(void)
{
	short int u16LocVar = 4;
	static char u8InitStaticLocVar = 5;
	if(u16ConstGlobalVar == 3)
	{
		u32NonInitStaticGlobalVar = 6;
		vidFunc(&u16LocVar);
	}
	else
	{
		u32NonInitStaticGlobalVar = 7;
	}
	while(1)
	{
	    for (int i = 0;i<10;i++ )
        {
            arr[i]+=2;
        }

	}
}
