/**
 * @file Template_lib_Appli_C.c 
 * @author 	Alexis ROLLAND
 * @date	2021-12-30
 * @brief 	Template for PIC24 main app
 *  
 *
 */


#include "lib_vumetre.h"    // Inclusion du fichier .h "Applicatif" renommé

/* Directives de compilation - Macros		*/


/* Déclarations des variables globales 	*/



/*	Implémentation du code */
#ifdef  TEST_PILOTER_LEDS
void Initialiser(void)
{
    TRIS_LEDS &= 0xFF00;    //  RA[7:0] as GPIO output
    PORT_LEDS = 0x00;       //  All LEDs off at startup

}
#endif  /*  TEST_PILOTER_LEDS   */

