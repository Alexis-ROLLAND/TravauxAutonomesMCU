/**
 * @file    
 * @author 	Alexis ROLLAND
 * @date	2024-02
 * @brief 	
 *  
 *
 */
#ifndef	__LIB_MCU03_H__
#define	__LIB_MCU03_H__


#ifndef FCY
#define FCY 4000000UL
#endif

#include <libpic30.h>
#include <xc.h>

typedef enum {  RESET = 0,          /**< RESET value for a soft_flag_t variable   */
                SET = 1,            /**< SET value for a soft_flag_t variable   */ 
} soft_flag_t;    

#define setSoftFlag(x)  {x = SET;};         /**< Macro designed to set a software flag  */
#define resetSoftFlag(x)  {x = RESET;};     /**< Macro designed to reset a software flag  */

#define TIMER1_IF   IFS0bits.T1IF
#define TIMER1_IE   IEC0bits.T1IE
#define TIMER1_IP   IPC0bits.T1IP

#define VAL_100MS   50000   /**< Prédiv by 8, so Clk base is 2µs - 100ms is 50000x2µs   */

#define LEDS    LATA        /**< Macro to access LEDs on PORTA  */
/**
 * @brief Global init function/task 
 * 
 * @param	None
 * 
 * @return  Nothing 
 *
 */
void Initialiser(void);

 /**
 * @brief  
 * 
 * @param	
 * 
 * @return   
 *
 */
void    main_task(void);

#endif  /* __LIB_MCU03_H__  */



