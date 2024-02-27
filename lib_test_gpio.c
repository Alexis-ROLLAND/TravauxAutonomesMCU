/**
 * @file    lib_test_gpio.c 
 * @author 	Alexis ROLLAND
 * @date	2024-02
 * @brief 	Code for applicative test library -> lib_gpio
 *  
 *
 */


#include "lib_test_gpio.h"
#include "lib_gpio.h" // Inclusion du fichier .h "Applicatif" renommé

/* Directives de compilation - Macros		*/

/* Déclarations des variables globales 	*/
gpio_pin_t  LedD3;
gpio_pin_t  BpS3;

/*	Implémentation du code */
void Initialiser(void)
{
    LedD3.bitNumber = 0;
    LedD3.port = GPIO_PORTA;
    
    BpS3.bitNumber = 6;
    BpS3.port = GPIO_PORTD;
    
    gpio_init(&LedD3, GPIO_MODE_OUTPUT);
    gpio_init(&BpS3, GPIO_MODE_INPUT);
    
}

void mainTask(void){
    gpio_level_t lev;
    
    __delay_ms(200);
    
    gpio_output_read(&LedD3,&lev);
    lev ^= 0x0001; 
    
    gpio_write(&LedD3,lev);
    
    
    
}
