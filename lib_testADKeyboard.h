/**
 * @file Template_lib_Appli_H.h 
 * @author 	Alexis ROLLAND
 * @date	2021-12-30
 * @brief 	Template for PIC24 main app
 *  
 *
 */
#ifndef	__LIB_TEST_ADKEYBOARD_H__
#define	__LIB_TEST_ADKEYBOARD_H__

#ifndef FCY
#define FCY 4000000UL
#endif

#include <libpic30.h>
#include <xc.h>

#define ADC_MAX_VALUE   1023

/**
 * @brief Global init function/task 
 * 
 * @param	None
 * 
 * @return  Nothing 
 *
 */
void Initialiser(void);

 


#endif  /*  __LIB_TEST_ADKEYBOARD_H__   */



