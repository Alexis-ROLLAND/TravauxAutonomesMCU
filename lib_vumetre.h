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

//#define TEST_PILOTER_LEDS   /**< Unit test for "PiloterLEDs" task   */
//#define TEST_GENE_TIC       /**< Unit test for timer config, and periodic ISR (T = 50ms) */
//#define TEST_ACQ_VPOT       /**< Unit test for ADC config and End Of Conversion ISR */
#define TEST_TRANSCODER       /**< Unit test for Transcoder function  */

#define PORT_LEDS   LATA
#define TRIS_LEDS   TRISA

#define PiloterLEDs(EtatLeds)   {PORT_LEDS = EtatLeds;}
#define StartConversion()       {AD1CON1bits.SAMP = 0;}          // Start Conversion (force end of sample)

#define NB_TIC_50MS         25000
#define COEF_MISE_ECHELLE   ((float)(0.0087977))

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
uint8_t Transcoder(uint16_t Tension);
 
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



