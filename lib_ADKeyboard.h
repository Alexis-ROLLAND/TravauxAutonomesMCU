/**
 * @file Template_lib_std_H.h 
 * @author 	Alexis ROLLAND
 * @date	2021-12-30
 * @brief 	Template for PIC24 main app
 *  
 *
 */

#ifndef	__LIB_ADKEYBOARD_H__
#define	__LIB_ADKEYBOARD_H__
#include <xc.h>

/**
 @brief     Colors definitions
 */
typedef enum {
    BTN_NONE = 0,       /**<    No button pressed    */
    BTN_S1 = 1,         /**<    S1 button pressed    */
    BTN_S2 = 2,         /**<    S2 button  pressed    */
    BTN_S3 = 3,         /**<    S3 button  pressed    */
    BTN_S4 = 4,         /**<    S4 button  pressed    */
    BTN_S5 = 5,         /**<    S5 button  pressed    */
    BTN_ERROR = -1      /**<    Error               */
} btn_id_t; 

/**
 * @brief   Transcode function Vbutton -> btn_color status
 * @param   Vbtn : normalized voltage (between 0 (Vref-) to 1 (Vref+) )  
 * @return  Button status (button color or none pressed) 
 */
btn_id_t getBtn(float    Vbtn);

#endif  /*  __LIB_ADKEYBOARD_H__    */


