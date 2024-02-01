/**
 * @file Template_lib_Appli_H.h 
 * @author 	Alexis ROLLAND
 * @date	2021-12-30
 * @brief 	Template for PIC24 main app
 *  
 *
 */
#ifndef	__LIB_VUMETRE_H__
#define	__LIB_VUMETRE_H__

#ifndef FCY
#define FCY 4000000UL
#endif

#include <libpic30.h>
#include <xc.h>

#define TEST_PILOTER_LEDS   /**< Unit test for "PiloterLEDs" task   */


#define PORT_LEDS   LATA
#define TRIS_LEDS   TRISA

#define PiloterLEDs(EtatLeds)   {PORT_LEDS = EtatLeds;}


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
 
 


#endif  /*  __LIB_VUMETRE_H__   */



