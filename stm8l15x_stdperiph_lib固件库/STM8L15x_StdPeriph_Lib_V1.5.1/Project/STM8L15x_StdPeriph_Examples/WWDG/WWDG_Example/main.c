/**
  ******************************************************************************
  * @file    WWDG/WWDG_Example/main.c
  * @author  MCD Application Team
  * @version V1.5.0
  * @date    13-May-2011
  * @brief   Main program body
  ******************************************************************************
  * @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2011 STMicroelectronics</center></h2>
  ******************************************************************************
  */ 

/* Includes ------------------------------------------------------------------*/
#include "stm8l15x.h"
#include "stm8_eval.h"

/** @addtogroup STM8L15x_StdPeriph_Examples
  * @{
  */

/** @addtogroup WWDG_Example
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
#define WINDOW_VALUE        97
#define COUNTER_INIT       104

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
__IO FunctionalState NonAlowedRefresh = DISABLE;
__IO FunctionalState AllowedRefresh = ENABLE;
uint8_t Index;
/* Private function prototypes -----------------------------------------------*/
static void WWDG_Config(void);
void Delay (uint16_t nCount);
/* Private functions ---------------------------------------------------------*/

/**
  * @brief  Main program.
  * @param  None
  * @retval None
  */
void main(void)
{

  /* Initialize LED1 and LED2 mounted on STM8L152X-EVAL board */
  STM_EVAL_LEDInit(LED1);
  STM_EVAL_LEDInit(LED2);

  /* Initialize Key and Joystick down push-buttons mounted on STM8L152X-EVAL board */
  STM_EVAL_PBInit(BUTTON_KEY, BUTTON_MODE_EXTI);
  STM_EVAL_PBInit(BUTTON_DOWN, BUTTON_MODE_EXTI);

  /* enable interrupts */
  enableInterrupts();

  /* Check if the MCU has resumed from WWDG reset */
  if (RST_GetFlagStatus(RST_FLAG_WWDGF) != RESET)
  {
    /* WWDGF flag set */
    /* Toggle LED1 */
    for (Index = 7; Index != 0; Index--)
    {
      STM_EVAL_LEDToggle(LED1);
      Delay(0x7FFF);
    }
    /* Clear WWDGF Flag */
    RST_ClearFlag(RST_FLAG_WWDGF);
  }

  /* WWDG Configuration */
  WWDG_Config();

  while (1)
  {
    /* Check if WWDG counter refresh is allowed in Allowed window */
    if (AllowedRefresh != DISABLE)
    {
      /* get WWDG counter value */
      /* wait until WWDG counter becomes lower than window value */
      while ((WWDG_GetCounter() & 0x7F) > WINDOW_VALUE);
      /* Refresh WWDG counter during allowed window so no MCU reset will occur */
      WWDG_SetCounter(COUNTER_INIT);
    }

    /* Check if WWDG counter refresh is allowed in non Allowed window */
    if (NonAlowedRefresh != DISABLE)
    {
      /* wait until WWDG counter becomes higher than window value */
      while ((WWDG_GetCounter() & 0x7F) < WINDOW_VALUE);
      /* Refresh WWDG counter during non allowed window so MCU reset will occur */
      WWDG_SetCounter(COUNTER_INIT);
    }
    /* Toggle LED2 */
    STM_EVAL_LEDToggle(LED2);
    Delay(0x6FFF);
  }
}

/**
  * @brief Configures the WWDG to generate a Reset if the WWDG is not refreshed 
  *         during the correct window.
  * @param  None
  * @retval None
  */

static void WWDG_Config(void) 
{
  /* WWDG configuration: WWDG is clocked by SYSCLK = 2MHz */
  /* WWDG timeout is equal to 251,9 ms */
  /* Watchdog Window = (COUNTER_INIT - 63) * 1 step
                     = 41 * (12288 / 2Mhz)
                     = 251,9 ms
  */
  /* Non Allowed Window = (COUNTER_INIT - WINDOW_VALUE) * 1 step
                        = (104 - 97) * 1 step
                        =  7 * 1 step 
                        =  7 * (12288 / 2Mhz) 
                        =  43.008 ms
   */
  /* So the non allowed window starts from 0.0 ms to 43.008 ms
  and the allowed window starts from 43.008 ms to 251,9 ms
  If refresh is done during non allowed window, a reset will occur.
  If refresh is done during allowed window, no reset will occur.
  If the WWDG down counter reaches 63, a reset will occur. */
  WWDG_Init(COUNTER_INIT, WINDOW_VALUE);
}

/**
  * @brief  Inserts a delay time.
  * @param  nCount: specifies the delay time length.
  * @retval None
  */
void Delay(__IO uint16_t nCount)
{
  /* Decrement nCount value */
  while (nCount != 0)
  {
    nCount--;
  }
}

#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *   where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* Infinite loop */
  while (1)
  {}
}
#endif

/**
  * @}
  */

/**
  * @}
  */

/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
