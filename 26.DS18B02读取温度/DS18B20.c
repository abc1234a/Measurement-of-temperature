#include <REGX51.H>
#include "Onewire.h"
#include "LCD1602.h"
//宏定义DS18B20指令
#define DS18B20_SKIP_ROM  0XCC
#define DS18B20_CONVERT_T 0X44
#define DS18B02_READ_SCRATCHPAD 0XBE
/**
  * @brief  DS18B20开始温度变化
  * @param  无
  * @retval 无 
  */
void DS18B20_ConvertT(void)
{
    Onewire_Init();//单总线初始化
    Onewire_Sendbyte(DS18B20_SKIP_ROM);
    Onewire_Sendbyte(DS18B20_CONVERT_T);
}
/**
  * @brief DS18B20读取温度 
  * @param  无
  * @retval 温度数值
  */
float DS18B20_Readt(void)
{
    unsigned  char TLSB, TMSB;
    int temp;
    float t;
     Onewire_Init();
    Onewire_Sendbyte(DS18B20_SKIP_ROM);
    Onewire_Sendbyte(DS18B02_READ_SCRATCHPAD);
    TLSB = Onewire_Recivebyte();
    TMSB = Onewire_Recivebyte();
//	  LCD_ShowBinNum(1,1,TMSB,8);
//	  LCD_ShowBinNum(1,9,TMSB,8);
    temp = (TMSB << 8) | TLSB;
    t = temp / 16.0;
    return t;
}