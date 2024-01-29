/**
 * @file 
 * @author 	Alexis ROLLAND
 * @date	
 * @brief 	
 *  
 *
 */
#ifndef	__LIB_APP_MCU01_H__
#define	__LIB_APP_MCU01_H__

//#define EXERCICE_1
#define EXERCICE_2

#ifndef FCY
#define FCY 4000000UL
#endif

#include <libpic30.h>
#include <xc.h>

#define     LED_A       LATAbits.LATA0          /**< LED_A is D3, on RA0        */
#define     TRIS_LED_A  TRISAbits.TRISA0        /**< TRIS for LED_A is TRISA0   */

#define     LED_B       LATAbits.LATA1          /**< LED_B is D4, on RA1        */
#define     TRIS_LED_B  TRISAbits.TRISA1        /**< TRIS for LED_B is TRISA1   */

#define     LED_C       LATAbits.LATA4          /**< LED_C is D7, on RA4        */
#define     TRIS_LED_C  TRISAbits.TRISA4        /**< TRIS for LED_C is TRISA4   */

#define     LED_D       LATAbits.LATA5          /**< LED_D is D8, on RA5        */
#define     TRIS_LED_D  TRISAbits.TRISA5        /**< TRIS for LED_D is TRISA5   */

#define     BP_A        PORTDbits.RD13          /**< BP_A is S4, on RD13        */
#define     TRIS_BP_A   TRISDbits.TRISD13       /**< TRIS for BP_A is TRISD13   */

#define     BP_B        PORTAbits.RA7           /**< BP_B is S5, on RA7        */
#define     TRIS_BP_B   TRISAbits.TRISA7        /**< TRIS for BP_B is TRISA7   */

#define     BP_C        PORTDbits.RD7           /**< BP_A is S6, on RD7        */
#define     TRIS_BP_C   TRISDbits.TRISD7        /**< TRIS for BP_C is TRISD7   */

#define     BP_D        PORTDbits.RD6           /**< BP_A is S3, on RD6        */
#define     TRIS_BP_D   TRISDbits.TRISD6        /**< TRIS for BP_D is TRISD6   */

typedef     enum     {  LED_OFF = 0,            /**< LED_OFF (0)    */
                        LED_ON = 1              /**< LED_ON  (1)    */
} etat_led_t;

typedef     enum    {   BP_PUSHED = 0,          /**< If BP is pushed, GPIO level is 0 (low) */
                        BP_RELEASED = 1         /**< If BP is pushed, GPIO level is 1 (high) */
} etat_bp_t;

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
 
 
 /**
 * @brief  
 * 
 * @param	
 * 
 * @return   
 *
 */
 
 /**
 * @brief  
 * 
 * @param	
 * 
 * @return   
 *
 */
 
 


#endif  /* __LIB_APP_MCU01_H__  */



