/*
 ********************************************************************
 * The RPG Toolkit Version 3 Plugin Libraries
 * This file copyright (C) 2003-2007  Christopher B. Matthews
 ********************************************************************
 *
 * This file is released under the AC Open License v 1.0
 * See "AC Open License.txt" for details
 */

/*
 * Includes
 */

#include "stdafx.h"
#include "sdk\tkplugin.h"
#include <string>

/*********************************************************************/
///////////////////////////////////////////////////////
// MENU SYSTEM INTERFACE
//
// If this is a Menu plugin, you must modify
// TKPlugMenu
///////////////////////////////////////////////////////

///////////////////////////////////////////////////////
//
// Function: TKPlugMenu
//
// Parameters: nRequestedMenu - the menu requested
//
// Action: This function is called when a menu request
//				is generated.  This function should display
//				and run the appropriate menu
//
// Returns: 1 (success)
//					0 (failure - requested menu not supported)
//
///////////////////////////////////////////////////////
int APIENTRY TKPlugMenu(int nRequestedMenu)
{
	return 0;
}

