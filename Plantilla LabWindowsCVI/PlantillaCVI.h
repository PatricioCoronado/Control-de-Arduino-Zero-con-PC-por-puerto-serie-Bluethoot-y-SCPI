/**************************************************************************/
/* LabWindows/CVI User Interface Resource (UIR) Include File              */
/* Copyright (c) National Instruments 2018. All Rights Reserved.          */
/*                                                                        */
/* WARNING: Do not add to, delete from, or otherwise modify the contents  */
/*          of this include file.                                         */
/**************************************************************************/

#include <userint.h>

#ifdef __cplusplus
    extern "C" {
#endif

     /* Panels and Controls: */

#define  PRINCIPAL                        1       /* callback function: panel_principal */
#define  PRINCIPAL_IDENTIFICA             2       /* control type: command, callback function: identifica_sistema */
#define  PRINCIPAL_X_POS                  3       /* control type: numeric, callback function: (none) */
#define  PRINCIPAL_Y_POS                  4       /* control type: numeric, callback function: (none) */
#define  PRINCIPAL_SISTEMA                5       /* control type: string, callback function: (none) */
#define  PRINCIPAL_FUNCION1               6       /* control type: command, callback function: funcion1 */
#define  PRINCIPAL_PRINCIPIO_FIN          7       /* control type: command, callback function: iniciar_test */
#define  PRINCIPAL_TIMER                  8       /* control type: timer, callback function: timer */


     /* Control Arrays: */

#define  CTRLARRAY                        1

     /* Menu Bars, Menus, and Menu Items: */

#define  MENU                             1
#define  MENU_COM                         2
#define  MENU_COM_CONFIGURAR              3       /* callback function: Configurar */
#define  MENU_COM_COMUNICACION            4       /* callback function: comunicacion_menu */
#define  MENU_CONFIGURACION               5
#define  MENU_INFO                        6
#define  MENU_INFO_ABOUT                  7       /* callback function: About */


     /* Callback Prototypes: */

void CVICALLBACK About(int menubar, int menuItem, void *callbackData, int panel);
void CVICALLBACK comunicacion_menu(int menubar, int menuItem, void *callbackData, int panel);
void CVICALLBACK Configurar(int menubar, int menuItem, void *callbackData, int panel);
int  CVICALLBACK funcion1(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK identifica_sistema(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK iniciar_test(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK panel_principal(int panel, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK timer(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif
