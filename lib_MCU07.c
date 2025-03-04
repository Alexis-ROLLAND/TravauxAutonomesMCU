/**
 * @file    lib_MCU07.c 
 * @author 	Alexis ROLLAND
 * @date	2025-03
 * @brief 	
 *  
 *
 */


#include "lib_MCU07.h" // Inclusion du fichier .h "Applicatif" renommé

/* Directives de compilation - Macros		*/


/* Déclarations des variables globales 	*/



/*	Implémentation du code */
void Initialiser(void){
    /** Sets LEDs GPIO as output*/
    TRISA &= 0xFF00;    /** TRISA[7:0] cleared  */
    LEDS = 0;
    
    /** RD6, RD13 and RD7 as GPIO inputs    */
    TRISDbits.TRISD6 = 1;
    TRISDbits.TRISD13 = 1;
    TRISDbits.TRISD7 = 1;

    /** Autorisation pour CN15, CN16 et CN19 de générer une interruption */
    CNEN1bits.CN15IE = 1;
    CNEN2bits.CN16IE = 1;
    CNEN2bits.CN19IE = 1;
    
    /** Activation globale de l'interruption IC */
    IFS1bits.CNIF = 0;  /** Sécurité    */
    IEC1bits.CNIE = 1;  /** CN Interrupt Enable */
    IPC4bits.CNIP = 4;  /** Prioriy set as 4    */
    
    
}

void mainTask(void){
    
    
}

void _ISR __attribute__((no_auto_psv)) _CNInterrupt (void){
    LEDS++;
    IFS1bits.CNIF = 0;  /** Acquittement interruption   */
} // _InterruptVector

