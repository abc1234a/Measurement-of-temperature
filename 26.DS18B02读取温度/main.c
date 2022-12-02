#include <REGX51.H>
#include "Delay.h"
#include "LCD1602.h"
#include "DS18B20.h"
float T;
void main()
{
	DS18B20_ConvertT();//转换温度，防止上次数值影响
	Delay(1000);//延时1秒
	LCD_Init() ;//初始化LCD1602
	LCD_ShowString(1,1,"temperature");
	while (1)
	{
	DS18B20_ConvertT();//转换温度
	T=DS18B20_Readt();//读取温度
	if (T < 0)//如果温度小于0
	{
		LCD_ShowChar(2, 1, '-');//显示负号
		T = -T;//又在把温度变成正数
	}
	else
	{
		LCD_ShowChar(2, 1, '+');//显示正号
	}
	LCD_ShowNum(2,2,T,3);//显示整数部分
	LCD_ShowChar(2,5,'.');//显示小数点
	LCD_ShowNum(2,6,(unsigned long)(T*10000)%10000,4);//显示小数部分
	}

}