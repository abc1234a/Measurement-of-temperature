#include <REGX51.H>

sbit Onewire_DQ = P3 ^ 7;//引脚定义
/**
  * @brief  单总线初始化
  * @param  无
  * @retval 从机位响应，0为响应，1为不响应
  */
unsigned char Onewire_Init(void) //初始化
{
    unsigned char i;
    unsigned char AckbBit;
    Onewire_DQ = 1;
    Onewire_DQ = 0;
    i = 247;
    while (--i)
        ; //延时500微秒
    Onewire_DQ = 1;
    i = 32;
    while (--i)
        ; //延时70微秒
    i = 247;
    while (--i); //延时500微秒
    return AckbBit;
}
/**
  * @brief  单总线发送一位
  * @param  Bit
  * @retval  无
  */
void Onewire_Sendbit(unsigned char Bit)
{
    unsigned char i;
    Onewire_DQ = 0;
    i = 4;
    while (--i); //延时10微秒
    Onewire_DQ=Bit;
    i = 24;
    while (--i) ;//延时50微秒
    Onewire_DQ = 1;
}
/**
  * @brief  单总线接收一位
  * @param  bit
  * @retval  无
  */
unsigned char OneWire_ReceivBit(void)
{
    unsigned char i;
    unsigned char Bit;
    Onewire_DQ = 0;
     i = 2;
	while (--i);//延时5微秒
    Onewire_DQ = 1;
     i = 2;
	while (--i);//延时5微秒
    Bit=Onewire_DQ;
     i = 24;
	while (--i);//延时50微秒
    return Bit;
}
/**
  * @brief  单总线发送一个字节
  * @param  byte
  * @retval  无
  */
void Onewire_Sendbyte(unsigned char Byte)
{
    unsigned char i;
    for(i=0;i<8;i++)
    {
			Onewire_Sendbit(Byte&(0x01<<i));//保留最低位，其他位不变，并向左移
    }
}
/**
  * @brief  单总线接收一个字节
  * @param  无
  * @retval  接收的一个字节
  */
unsigned char Onewire_Recivebyte(void)
{
     unsigned char i;
     unsigned char Byte=0x00;
    for(i=0;i<8;i++)
    {
         if(OneWire_ReceivBit())
         {
            Byte|=0x01<<i;//最后一位置1，并且像左移
         }
    }
    return Byte;
}