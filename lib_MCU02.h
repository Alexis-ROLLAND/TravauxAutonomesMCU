/**
 * @file    
 * @author 	Alexis ROLLAND
 * @date	2024-02
 * @brief 	
 *  
 *
 */
#ifndef	__LIB_MCU02_H__
#define	__LIB_MCU02_H__

#ifndef FCY
#define FCY 4000000UL
#endif

#include <libpic30.h>
#include <xc.h>

/**
 * New custom type specialy designed for software flags
 * @attention : compile with -fshort-enums for optimize data size
 */ 
typedef enum {  RESET = 0,          /**< RESET value for a soft_flag_t variable   */
                SET = 1,            /**< SET value for a soft_flag_t variable   */ 
} soft_flag_t;    

#define setSoftFlag(x)  {x = SET;};         /**< Macro designed to set a software flag  */
#define resetSoftFlag(x)  {x = RESET;};     /**< Macro designed to reset a software flag  */

//  INT1 is chosen
//  RE8 is INT1 pin
#define     BP          PORTEbits.RE8
#define     BP_TRIS     TRISEbits.TRISE8
//  Macros to IF/IE/IP bits
#define     BP_IF       IFS1bits.INT1IF       
#define     BP_IE       IEC1bits.INT1IE
#define     BP_IP       IPC5bits.INT1IP

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
 


#endif  /*  __LIB_MCU02_H__ */  



