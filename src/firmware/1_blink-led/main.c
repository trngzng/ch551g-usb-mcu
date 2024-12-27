/**
 * @file       main.c
 * @copyright  Copyright (C) 2024 GNG. All rights reserved.
 * @license    None.
 * @version    v1.0.0
 * @date       2024-12-26
 * @author     Giang Phan Truong
 *             
 * @brief      The first lesson: Blink USER led on V0 DevKit.
 *             
 * @note       For educational purpose only.
 */

/* Includes ----------------------------------------------------------- */
#include "ch552.h"
/* Private defines ---------------------------------------------------- */

/* Private enumerate/structure ---------------------------------------- */

/* Private macros ----------------------------------------------------- */

/* Public variables --------------------------------------------------- */

/* Private variables -------------------------------------------------- */

/* Private function prototypes ---------------------------------------- */
/**
 * @brief  Delay the processing using timer overflow
 *
 * @param[in]     ms  Delay time in microsecond
 *
 * @return  
 *  - none
 */
static void delay_ms(uint16_t ms);
/* Function definitions ----------------------------------------------- */
void main(void)
{
  /* Clock configuration fCLK = 24MHz  */
	SAFE_MOD = 0x55;  // Enter the safe mode
	SAFE_MOD = 0xAA;
	CLOCK_CFG = 0x86; // Write new value refer the Table in the datasheet
	SAFE_MOD = 0x00;  // Terminate the safe mode

  /* Configure P3.3: Output, push-pull */
  P3_MOD_OC &= ~(1 << 3);
	P3_DIR_PU |= (1 << 3);

  while(1)
  {
    P3 |= (1 << 3);
    delay_ms(1000);
    P3 &= ~(1 << 3);
    delay_ms(1000);
  }
}
/* Private definitions ------------------------------------------------ */
static void delay_ms(uint16_t ms)
{
	TMOD |= (1 << bT1_M0);	// 16-bit timer mode

	while (ms) 
  {
    // Timer frequency is Fsys/12 = 2Mhz = 0.5us
		TH0 = 0;   // Timer counter = 2000
		TL0 = 0;
		TR0 = 1;   // Start Timer0
		while ((TH0 << 8 | TL0) < 2000);
		TR0 = 0;   // Stop Timer0
		--ms;
	}
}

/* End of file -------------------------------------------------------- */
