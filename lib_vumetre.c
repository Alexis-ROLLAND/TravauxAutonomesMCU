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
const   uint8_t tabValLeds[9] = {0x00, 0x01, 0x03, 0x07, 0x0F, 0x1F, 0x3F, 0x7F, 0xFF}; 
uint16_t    Vpot = 0;
uint8_t     AcqOK = 0;

/*	Implémentation du code */
void Initialiser(void){
    TRIS_LEDS &= 0xFF00;    //  RA[7:0] as GPIO output
    PORT_LEDS = 0x00;       //  All LEDs off at startup

    // Config Timer1
    T1CON = 0x0010;     //  T1CON = 0b0000 0000 0001 0000 - Timer mode, div by 8
    TMR1 = 0;           //  Set Timer1 count register to 0
    PR1 = NB_TIC_50MS;  //  Load PR1 with "50ms" value

    IFS0bits.T1IF = 0;  //  Reset T1 Interrupt Flag (security)
    IEC0bits.T1IE = 1;  //  Enable T1 interrupt
    IPC0bits.T1IP = 4;  //  Set T1 Interrupt priority to 4 (default)
       
    // Config ADC (step by step)
    AD1CON2bits.VCFG = 0b000;     //  Vr+ = AVDD, Vr- = AVSS
    AD1CON3bits.ADRC = 1;       //  Tad is issued from internal dedicated RC oscillator (Tad = 250ns)
    AD1PCFGbits.PCFG5 = 0;      //  RB5/AN5 is an anlog input
    AD1CHSbits.CH0SA = 5;       //  MUX A input+ is AN5
    AD1CHSbits.CH0NA = 0;       //  MUX A input- is Vref-
    AD1CON2bits.ALTS = 0;       //  MUX A is the only used MUX
    AD1CON2bits.CSCNA = 0;      //  No scan
    AD1CON1bits.ASAM = 1;       //  Auto Sample (at the end of the previous conversion)
    AD1CON3bits.SAMC = 1;       //  Auto Sample time = 1 Tad            
    AD1CON1bits.SSRC = 0b000;   //  Clearing SAMP ends sampling & starts conversion
    AD1CON1bits.FORM = 0b00;    //  Data format = unsigned integer
    AD1CON2bits.SMPI = 0;       //  IRQ à chaque conversion       
    
    IFS0bits.AD1IF = 0; //  Clear IF - Security
    IEC0bits.AD1IE = 1; //  Enable Interrupt
    IPC3bits.AD1IP = 4; //  Interrupt priority = 4 (default)
        
    AD1CON1bits.ADON = 1;   // Power on ADC
    T1CONbits.TON = 1;  //  Start timer 1    
}
//-----------------------------------------------------------------------------
void    main_task(void){
    if (AcqOK){
        PiloterLEDs(Transcoder(Vpot));
        AcqOK = 0;
    }
}
//-----------------------------------------------------------------------------
uint8_t Transcoder(uint16_t Tension){
    float   tmp;
    
    tmp = (float)Tension * (COEF_MISE_ECHELLE);
    return tabValLeds[(uint8_t)tmp];
}
//-----------------------------------------------------------------------------
void _ISR __attribute__((no_auto_psv)) _T1Interrupt (void){
    StartConversion();  // Obvious...
    IFS0bits.T1IF = 0;  // Clear T1IF
}   /* _T1Interrupt */
//-----------------------------------------------------------------------------
void _ISR __attribute__((no_auto_psv)) _ADC1Interrupt (void){
    Vpot = (ADC1BUF0);     // get the result
    AcqOK = 1;              // Set software Flag
    IFS0bits.AD1IF = 0; //  Clear IF 
}   /* _ADC1Interrupt    */
//-----------------------------------------------------------------------------



