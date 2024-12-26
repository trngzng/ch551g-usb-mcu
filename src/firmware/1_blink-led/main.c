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
  /* Clock configuration fCLK = 6MHz  */
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
	while (ms) 
  {
		TF0 = 0;      // Clear Timer0 OVF flag
    // Timer frequency is Fsys/12 = 500kHz = 0.002ms
		TH0 = 0xA2;   // Timer counter = 500
		TL0 = 0x40;
		TR0 = 1;      // Start Timer0
		while (!TF0);
		TR0 = 0;      // Stop Timer0
		--ms;
	}
}

/* End of file -------------------------------------------------------- */
