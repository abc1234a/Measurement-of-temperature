#ifndef __ONEWIRE_H__
#define __ONEWIRE_H__
unsigned char Onewire_Init(void) ;
void Onewire_Sendbit(unsigned char Bit);
unsigned char OneWire_ReceivBit(void);
void Onewire_Sendbyte(unsigned char Byte);
unsigned char Onewire_Recivebyte(void);
#endif