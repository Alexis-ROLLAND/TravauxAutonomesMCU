/**
 * @file    
 * @author 	Alexis ROLLAND
 * @date	2024-02
 * @brief 	
 *  
 *
 */


#include "lib_MCU03.h" // Inclusion du fichier .h "Applicatif" renommé

/* Directives de compilation - Macros		*/


/* Déclarations des variables globales 	*/
soft_flag_t     evtTimer1 = RESET;      /**<   Software flag is RESET at startup    */
uint8_t ledPattern = 0x01;  /**<    Startting pattern is 00000001   */

/*	Implémentation du code */
void Initialiser(void)
{
    TRISA &= 0xFF00;    /**< LEDs are connected to LATA[7:0]. Let's make then GPIO ouputs   */
    LATA = 0;           /**<  All LEDs off at startup   */

    T1CON = 0x0010;     /**< Timer Mode, Clock is Fcy, Prediv by 8, timer is of  */
    PR2 = VAL_100MS;    /**< PR value to match 100ms    */
    
    TIMER1_IF = 0;      /**< Security   */
    TIMER1_IE = 1;      /**< Enable Timer 1 interrupt   */
    TIMER1_IP = 4;      /**< Interrupt priority is set to 4 (why not ?) */
    
    LATA = ledPattern;  /**< We can now start lighting the leds */
    T1CONbits.TON = 1;  /**< Start Timer 1  */
}
//------------------------------------------------------------------------------
void    main_task(void){
    if (evtTimer1 == SET){
        if (ledPattern >= 0x80)   ledPattern = 0x01;
        else ledPattern <<= 1;      /**< right to left  */
        
        LEDS = ledPattern;  /**< Assign new pattern */
        resetSoftFlag(evtTimer1);
    }
}   /* main_task    */
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
void _ISR __attribute__((no_auto_psv))  _T1Interrupt (void){
    setSoftFlag(evtTimer1);         // Set Software Flag
    TIMER1_IF = 0;                  // Reset interrupt flag / Acquittement Interruption
} /* _Timer1Interrupt   */
//------------------------------------------------------------------------------