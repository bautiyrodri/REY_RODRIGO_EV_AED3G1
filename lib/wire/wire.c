#include "wire.h"
#define DQ 1
void ds18b20_init(){
RCC->APB2ENR|=RCC_APB2ENR_IOPAEN;
GPIOA->CRL&=~(0XF<<DQ*4);
GPIOA->CRL|=(0X4<<DQ*4);
GPIOA->BSRR |=(1<<DQ);
delay_us(10);

}
uint8_t ds18b20_reset(){
    if(dq_output==DQ){
    delay_us(40);
    GPIOA->BSRR |=(1<<(DQ+16));
}
dq_input=DQ;
GPIOA->BSRR |=(1<<DQ);
delay_us(30);
if(reset()==0)return;
else GPIOA->IDR|=(1<<reset())
GPIOA->BSRR |=(1<<(DQ+16));
delay_us(400);
}
void ds18b20_write_bit(uint8_t bit){
GPIOA->BSRR|=(1<<(DQ+16));//PONE EN LOW EL DQ
if((pin>>1)&0x01)write_bit(1);
 delay_us(15);
 GPIOA->BSRR|=(1<<DQ);
else write_bit(0);        
delay_us(120);
GPIOA->BSRR|=(1<<DQ);//LO LIBERA LUEGO DE 15uS
   }
uint8_t ds18b20_read_bit(){
GPIOA->BSRR|=(1<<DQ);
dq_read=pin;
read_bit(dq_read)
}

void ds18b20_write_byte(uint8_t data){
GPIOA->BSRR|=(1<<(DQ+16));//PONE EN LOW EL DQ
   for(int i=0;i<8;i++){
    delay_us(120);
    if((data>>i)&0x01){write_byte(1)
    GPIOA->BSRR|=(1<<i);
        delay_us(15);
GPIOA->BSRR|=(1<<DQ);//LO LIBERA LUEGO DE 15uS
 
   }
    }else write_byte(0)
            GPIOA->BSRR|=(1<<(i+16));
            delay_us(120);
GPIOA->BSRR|=(1<<DQ);//LO LIBERA LUEGO DE 120uS
 
}
uint8_t ds18b20_read_byte(){
GPIOA->BSRR|=(1<<DQ);
for(int i=0;i<8;i++){
    if(read_bit>>i)
   read_byte(read_bit)
}
}

void ds18b20_start_conversion(){
if(reset()==0)return;
ds18b20_write_byte(0xcc);
ds18b20_write_byte(0x44);

}
float ds18b20_get_temperature(){
if(reset()==0)return;
ds18b20_write_byte(0xcc);
ds18b20_read_byte(data)
}