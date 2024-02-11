/**
 * @file Template_lib_std_C.c 
 * @author 	Alexis ROLLAND
 * @date	2021-12-30
 * @brief 	Template for PIC24 main app
 *  
 *
 */


#include "lib_ADKeyboard.h"

/* Directives de compilation - Macros		*/


/* Déclarations des variables globales 	*/



/*	Implémentation du code */
btn_id_t getBtn(float    Vbtn){
    if (Vbtn > 0.96)        return BTN_NONE;
    else if (Vbtn > 0.9)    return BTN_S5;
    else if (Vbtn > 0.86)    return BTN_S4;
    else if (Vbtn > 0.83)    return BTN_S3;
    else if (Vbtn > 0.8)        return BTN_S2;
    else if (Vbtn > 0.75)    return BTN_S1;
    else return BTN_ERROR;
}

