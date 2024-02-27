/**
 * @file    lib_gpio.h 
 * @author 	Alexis ROLLAND
 * @date	2024-02
 * @brief 	Header file for GPIO low-level driver 
 *  
 *
 */

#ifndef	__LIB_GPIO_H__
#define	__LIB_GPIO_H__
#include <xc.h>

#define FUNCTION_BASED   1
#define MACRO_BASED      2
#define IMPLEMENTATION_MODE FUNCTION_BASED

typedef uint16_t*    regAddr;       /**<    Alias to uint16_t*  */

typedef enum {
            GPIO_OK = 0,        /**<    All is OK   */
            GPIO_ERROR = -1,    /**<    Unspecific error    */
} gpio_err_t;

typedef enum {
            GPIO_MODE_INPUT = 1,        /**< GPIO Pin is INPUT  */
            GPIO_MODE_OUTPUT = 0,       /**< GPIO Pin is OUTPUT  */
} gpio_mode_t;   

typedef enum { 
            GPIO_LEVEL_LOW = 0,                 /**< GPIO Low level */
            GPIO_LEVEL_HIGH = 1                 /**< GPIO High level */
} gpio_level_t;

typedef enum {
            GPIO_PORTA = 0,             /**< GPIO port is PORTA */
            GPIO_PORTB = 1,             /**< GPIO port is PORTB */
            GPIO_PORTC = 2,             /**< GPIO port is PORTC */
            GPIO_PORTD = 3,             /**< GPIO port is PORTD */
            GPIO_PORTE = 4,             /**< GPIO port is PORTF */
            GPIO_PORTF = 5,             /**< GPIO port is PORTG */        
            GPIO_PORTG = 6              /**< GPIO port is PORTG */                
} gpio_port_t;

typedef struct{
    gpio_port_t port;                       /**<    GPIO Port   */
    uint8_t     bitNumber;                  /**<    Bit of GPIO register associated with GPIO   */
} gpio_pin_t;  

/**
 * @brief  Initializes the GPIO as input or output
 * 
 * @param[OUT]  pin : address of a filled gpio_pint_t struct	
 * @param[IN]   mode : GPIO mode (input/output)  
 * 
 * @return      GPIO_OK if ok, GPIO_ERROR otherwise 
 *
 */
gpio_err_t  gpio_init(const gpio_pin_t *pin, gpio_mode_t mode);
 
 /**
 * @brief       sets the GPIO (LATx <- 1)
 * 
 * @param[IN]   pin : address of a filled gpio_pint_t struct	
 * 
 * @return      GPIO_OK if ok, GPIO_ERROR otherwise 
 *
 */
gpio_err_t  gpio_set(const gpio_pin_t *pin);
 
/**
 * @brief       clears the GPIO (LATx <- 0)
 * 
 * @param[IN]   pin : address of a filled gpio_pint_t struct	
 * 
 * @return      GPIO_OK if ok, GPIO_ERROR otherwise 
 *
 */
gpio_err_t  gpio_clear(const gpio_pin_t *pin);

/**
 * @brief       Toggles the GPIO (LATx <- ~LATx)
 * 
 * @param[IN]   pin : address of a filled gpio_pint_t struct	
 * 
 * @return      GPIO_OK if ok, GPIO_ERROR otherwise 
 *
 */
gpio_err_t  gpio_toggle(const gpio_pin_t *pin);

/**
 * @brief  
 * 
 * @param	
 * 
 * @return   
 *
 */
 gpio_err_t  gpio_write(const gpio_pin_t *pin, gpio_level_t level);
 
 /**
 * @brief   Reads the PORT bit associated with the GPIO
 * 
 * @param	
 * 
 * @return   
 *
 */
 gpio_err_t  gpio_input_read(const gpio_pin_t *pin, gpio_level_t *level);
 
 /**
 * @brief   Reads the LAT bit associated with the GPIO
 * 
 * @param	
 * 
 * @return   
 *
 */
 gpio_err_t  gpio_output_read(const gpio_pin_t *pin, gpio_level_t *level);
 
//------------------------------------------------------------------------------
 
//------------------------------------------------------------------------------
//  Low Level functions - Do not use directly
//------------------------------------------------------------------------------
 
 /**
 * @brief   gets the real address of the TRIS register associated with the port
 *          
 * @attention : Low level function, for internal use only.  
 *              Do not use directly. 
 * 
 * @param	port : the "target" port 
 * 
 * @return  Address of the TRIS register 
 *
 */
#if (IMPLEMENTATION_MODE == FUNCTION_BASED)
regAddr   getTRIS(gpio_port_t port);    /**< function based getTRIS  */
#elif (IMPLEMENTATION_MODE == MACRO_BASED)
#define getTRIS(port) {Tab_TRIS_addr[(uint8_t)port]};   /**< macro based getTRIS  */
#endif

/**
 * @brief   gets the real address of the LAT register associated with the port
 *          
 * @attention : Low level function, for internal use only.  
 *              Do not use directly. 
 * 
 * @param	port : the "target" port 
 * 
 * @return  Address of the LAT register 
 *
 */
#if (IMPLEMENTATION_MODE == FUNCTION_BASED)
regAddr   getLAT(gpio_port_t port);    /**< function based getLAT  */
#elif (IMPLEMENTATION_MODE == MACRO_BASED)
#define getLAT(port) {Tab_LAT_addr[(uint8_t)port]};   /**< macro based getLAT  */
#endif

/**
 * @brief   gets the real address of the PORT register associated with the port
 *          
 * @attention : Low level function, for internal use only.  
 *              Do not use directly. 
 * 
 * @param	port : the "target" port 
 * 
 * @return  Address of the PORT register 
 *
 */
#if (IMPLEMENTATION_MODE == FUNCTION_BASED)
regAddr   getPORT(gpio_port_t port);    /**< function based getLAT  */
#elif (IMPLEMENTATION_MODE == MACRO_BASED)
#define getPORT(port) {Tab_PORT_addr[(uint8_t)port]};   /**< macro based getPORT  */
#endif


#endif      /*  __LIB_GPIO_H__  */


