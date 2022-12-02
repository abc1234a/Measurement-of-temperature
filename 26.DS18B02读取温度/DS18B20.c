#include <REGX51.H>
#include "Onewire.h"
#include "LCD1602.h"
//�궨��DS18B20ָ��
#define DS18B20_SKIP_ROM  0XCC
#define DS18B20_CONVERT_T 0X44
#define DS18B02_READ_SCRATCHPAD 0XBE
/**
  * @brief  DS18B20��ʼ�¶ȱ仯
  * @param  ��
  * @retval �� 
  */
void DS18B20_ConvertT(void)
{
    Onewire_Init();//�����߳�ʼ��
    Onewire_Sendbyte(DS18B20_SKIP_ROM);
    Onewire_Sendbyte(DS18B20_CONVERT_T);
}
/**
  * @brief DS18B20��ȡ�¶� 
  * @param  ��
  * @retval �¶���ֵ
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