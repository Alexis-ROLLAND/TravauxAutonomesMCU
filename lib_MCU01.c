/**
 * @file 
 * @author 	Alexis ROLLAND
 * @date	
 * @brief 	
 *  
 *
 */


#include "lib_MCU01.h" // Inclusion du fichier .h "Applicatif" renommé

/* Directives de compilation - Macros		*/


/* Déclarations des variables globales 	*/



/*	Implémentation du code */
#ifdef EXERCICE_1
void Initialiser(void)
{
    TRIS_LED_A = 0;     /**< RA0 is a GPIO in output mode  */
    LED_A = LED_OFF;
    
    TRIS_BP_A = 1;      /**< RD13 is set as GPIO Input      */

}
#endif  /* EXERCICE_1   */

#ifdef EXERCICE_2
void Initialiser(void)
{
    TRIS_LED_A = 0;     /**< RA0 is a GPIO in output mode  */
    LED_A = LED_OFF;
    
    TRIS_LED_B = 0;     /**< RA1 is a GPIO in output mode  */
    LED_B = LED_OFF;
    
    TRIS_LED_C = 0;     /**< RA4 is a GPIO in output mode  */
    LED_C = LED_OFF;
    
    TRIS_LED_D = 0;     /**< RA5 is a GPIO in output mode  */
    LED_D = LED_OFF;
    
    TRIS_BP_A = 1;      /**< RD13 is set as GPIO Input      */
    TRIS_BP_B = 1;      /**< RA7 is set as GPIO Input      */
    TRIS_BP_C = 1;      /**< RD7 is set as GPIO Input      */
    TRIS_BP_D = 1;      /**< RD6 is set as GPIO Input      */

}
#endif  /* EXERCICE_2   */