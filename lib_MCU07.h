/**
 * @file    lib_MCU07.h 
 * @author 	Alexis ROLLAND
 * @date	2025-03
 * @brief 	
 *  
 *
 */
#ifndef	__LIB_MCU07_H__
#define	__LIB_MCU07_H__

#ifndef FCY
#define FCY 4000000UL
#endif

#include <libpic30.h>
#include <xc.h>

#define     BPS3_CN15   PORTDbits.RD6
#define     BPS4_CN19   PORTDbits.RD13
#define     BPS6_CN16   PORTDbits.RD7

#define     LEDS    LATA

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
void mainTask(void);
 
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
 
 


#endif  /* __LIB_MCU07_H__  */



