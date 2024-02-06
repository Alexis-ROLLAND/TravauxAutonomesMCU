/**
 * @file    
 * @author 	Alexis ROLLAND
 * @date	2024-02
 * @brief 	
 *  
 *
 */


#include "lib_MCU02.h" // Inclusion du fichier .h "Applicatif" renommé

/* Directives de compilation - Macros		*/


/* Déclarations des variables globales 	*/
soft_flag_t evtBP = RESET;  //  Software flag is RESET at startup
uint8_t NBevents = 0;       //  Nbevents is nul at startup

/*	Implémentation du code */
void Initialiser(void){
    TRISA &= 0xFFF0;    // LEDs are connected to LATA[7:0]. Let's make then GPIO ouputs
    LATA = 0;           //  All LEDs off at startup
    
    BP_TRIS = 1;        // RE8-INT1 is configured as GPIO Input
    
    INTCON2bits.INT1EP = 0;     // Interrupt on positive edge 
    BP_IF = 0;                  // Reset interrupt flag - Security
    BP_IE = 1;                  // Enable INT1 interrupt
    BP_IP = 4;                  // INT1 priority is 4
    
}   /* Initialiser  */
//------------------------------------------------------------------------------
void    main_task(void){
    if (evtBP == SET){
        NBevents++;             /**<    Increment Nbevents  */
        LATA = NBevents;        /**<    Update LEDs values  */
        resetSoftFlag(evtBP);   /**<    Reset software flag */
    }   /* if (evtBP == SET)    */
}   /* main_task    */
//------------------------------------------------------------------------------
void _ISR __attribute__((no_auto_psv)) _INT1Interrupt (void){
    setSoftFlag(evtBP);         // Set Software Flag
    BP_IF = 0;                  // Reset interrupt flag / Acquittement Interruption
} /* _INT1Interrupt   */
//------------------------------------------------------------------------------