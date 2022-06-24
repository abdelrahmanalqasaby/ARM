
#include <stdio.h>
#include <TM4C123GH6PM.h>
void Enable_all(void)
{
	//long r0 =0;
	//__asm("mov PRIMASK,0");
	//__asm("mov FAULTMASK,r0");
	//MSR PRIMASK,0;
	/*CLR PRIMASK*/
	__ASM("CPSIE i");
	__ASM("CPSIE f");
}
void Disable_all(void)
{
	//long r0 =0;
	//__asm("mov PRIMASK,0");
	//__asm("mov FAULTMASK,r0");
	//MSR PRIMASK,0;
	/*SET PRIMASK*/
	__ASM("CPSID i");
	__ASM("CPSID f");
}
void switch_to_unpri(void)
{
	__ASM("MOV R0,#1");
	__ASM ("MSR CONTROL,R0");
}
void switch_to_pri(void)
{
	__ASM("SVC #0");
}
void SVC_Handler()
{
	/*CLR first bit in CONTROL Reg*/
	__ASM("MOV R4, #0");
	__ASM("MSR CONTROL, R4");
}

int main ()
{
	while (1)
	{
		Enable_all();	
		switch_to_unpri();	
		switch_to_pri();
		Disable_all();
	}
	
	
	return 0;
}
