/**
 * @file    lib_gpio.c 
 * @author 	Alexis ROLLAND
 * @date	2024-02
 * @brief 	Code for low-level gpio driver
 *  
 *
 */


#include "lib_gpio.h" // Inclusion du fichier .h  renommé

/* Directives de compilation - Macros		*/


/* Déclarations des variables globales 	*/
const   regAddr Tab_TRIS_addr[]={   (regAddr)&TRISA,
                                    (regAddr)&TRISB,
                                    (regAddr)&TRISC,
                                    (regAddr)&TRISD,
                                    (regAddr)&TRISE,
                                    (regAddr)&TRISF,
                                    (regAddr)&TRISG,    
};

const   regAddr Tab_LAT_addr[]={    (regAddr)&LATA,
                                    (regAddr)&LATB,
                                    (regAddr)&LATC,
                                    (regAddr)&LATD,
                                    (regAddr)&LATE,
                                    (regAddr)&LATF,
                                    (regAddr)&LATG,    
};

const   regAddr Tab_PORT_addr[]={   (regAddr)&PORTA,
                                    (regAddr)&PORTB,
                                    (regAddr)&PORTC,
                                    (regAddr)&PORTD,
                                    (regAddr)&PORTE,
                                    (regAddr)&PORTF,
                                    (regAddr)&PORTG,    
};
/*	Implémentation du code */
//-----------------------------------------------------------------------------
gpio_err_t  gpio_init(const gpio_pin_t *pin, gpio_mode_t mode){
    
    regAddr trisAddr = getTRIS(pin->port);
    
    if (mode == GPIO_MODE_INPUT)        *trisAddr |= ((0x0001)<<(pin->bitNumber));
    else if (mode == GPIO_MODE_OUTPUT)  *trisAddr &= ~((0x0001)<<(pin->bitNumber));
    
    return GPIO_OK;
}
//-----------------------------------------------------------------------------
gpio_err_t  gpio_set(const gpio_pin_t *pin){
    regAddr latAddr = getLAT(pin->port);
    *latAddr |= ((0x0001)<<(pin->bitNumber));
    return GPIO_OK;
}
//-----------------------------------------------------------------------------
gpio_err_t  gpio_clear(const gpio_pin_t *pin){
    regAddr latAddr = getLAT(pin->port);
    *latAddr &= ~((0x0001)<<(pin->bitNumber));
    return GPIO_OK;
}
//-----------------------------------------------------------------------------
gpio_err_t  gpio_toggle(const gpio_pin_t *pin){
    regAddr latAddr = getLAT(pin->port);
    *latAddr ^= ((0x0001)<<(pin->bitNumber));
    return GPIO_OK;
}
//-----------------------------------------------------------------------------
gpio_err_t  gpio_write(const gpio_pin_t *pin, gpio_level_t level){
    regAddr latAddr = getLAT(pin->port);
    if (level == GPIO_LEVEL_LOW) *latAddr &= ~((0x0001)<<(pin->bitNumber));
    else if (level == GPIO_LEVEL_HIGH) *latAddr |= ((0x0001)<<(pin->bitNumber));
    return GPIO_OK;
}
//-----------------------------------------------------------------------------
gpio_err_t  gpio_input_read(const gpio_pin_t *pin, gpio_level_t *level){
    regAddr portAddr = getPORT(pin->port);
    uint16_t    regValue = *portAddr;
    
    *level = (gpio_level_t)(regValue >> pin->bitNumber) & 0x0001; 
    
    return GPIO_OK;
}
//-----------------------------------------------------------------------------
gpio_err_t  gpio_output_read(const gpio_pin_t *pin, gpio_level_t *level){
    regAddr latAddr = getLAT(pin->port);
    uint16_t    regValue = *latAddr;
    
    *level = (gpio_level_t)(regValue >> pin->bitNumber) & 0x0001; 
    
    return GPIO_OK;
}
//-----------------------------------------------------------------------------
#if (IMPLEMENTATION_MODE == FUNCTION_BASED)
regAddr   getTRIS(gpio_port_t port){
    return Tab_TRIS_addr[(uint8_t)port];
}
#endif
//-----------------------------------------------------------------------------
#if (IMPLEMENTATION_MODE == FUNCTION_BASED)
regAddr   getLAT(gpio_port_t port){
    return Tab_LAT_addr[(uint8_t)port];
}
#endif
//-----------------------------------------------------------------------------
#if (IMPLEMENTATION_MODE == FUNCTION_BASED)
regAddr   getPORT(gpio_port_t port){
    return Tab_PORT_addr[(uint8_t)port];
}
#endif
//-----------------------------------------------------------------------------