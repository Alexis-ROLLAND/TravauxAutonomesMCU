/**
 * @file Template_lib_Appli_C.c 
 * @author 	Alexis ROLLAND
 * @date	2021-12-30
 * @brief 	Template for PIC24 main app
 *  
 *
 */


#include "lib_testADKeyboard.h" 

/* Directives de compilation - Macros		*/


/* Déclarations des variables globales 	*/



/*	Implémentation du code */
void Initialiser(void)
{
    // GPIO
    TRISA &= 0xFF00;            /**< Leds are on RA[7:0]    */
    
    // ADC
    AD1CON1bits.SSRC = 0b111;   /**< 111 = Internal (why not ?) counter ends sampling and starts conversion (auto-convert) */
    
    AD1CON3bits.ADRC = 1;       /**<    1 = A/D internal RC clock   */    
    AD1CON3bits.SAMC = 0b01010; /**<  10 Tad (why not ?)    */
    AD1CHSbits.CH0SA = 0b0001;  /**< AN1    */

    AD1PCFGbits.PCFG1 = 0;  /**<  0 = Pin configured in Analog mode */
    
    AD1CON1bits.ADON = 1;   /**< Power on ADC  */
}

