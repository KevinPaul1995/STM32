// toggle  de PB3 que es el led interno de la tarjeta stm32l432kc

#define PERIFERICOS_DIR 		(0x40000000UL)
#define AHB2_OFFSET				(0X08000000UL)
#define AHB2_DIR				(PERIFERICOS_DIR+AHB2_OFFSET)
#define GPIOB_OFFSET			(0X00000400UL)
#define GPIOB_DIR				(AHB2_DIR+GPIOB_OFFSET)
#define AHB1_OFFSET				(0x00020000UL)
#define AHB1_DIR				(PERIFERICOS_DIR+AHB1_OFFSET)
#define RCC_OFFSET				(0x00001000UL)
#define RCC_DIR					(AHB1_DIR+RCC_OFFSET)
#define RCC_AHB2ENR_OFFSET		(0x0000004CUL)
#define RCC_AHB2ENR				(*(volatile unsigned int *)(RCC_DIR+RCC_AHB2ENR_OFFSET))
#define GPIOB_ACTIVO			(1U<<1)
#define MODO_OFFSET				(0x00000000UL)
#define GPIOB_MODO				(*(volatile unsigned int *)(GPIOB_DIR+MODO_OFFSET))
#define GPIOB_SALIDAS_OFFSET 	(0x00000014UL)
#define GPIOB_SALIDAS		 	(*(volatile unsigned int *)(GPIOB_DIR+GPIOB_SALIDAS_OFFSET))
#define led						(1U<<3)

int main(void){

	RCC_AHB2ENR|=GPIOB_ACTIVO;
	GPIOB_MODO|=(1U<<6);
	GPIOB_MODO&=~(1U<<7);
	while(1){
		GPIOB_SALIDAS^=led;
		for (int i = 0; i < 300000; ++i) {

		}
	}
	return 0;
}

