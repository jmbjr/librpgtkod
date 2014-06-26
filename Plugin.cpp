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

//															   ||
// You can have a one-line description of your plugin here.    \/ approx size limit
PLUGIN_DESCRIPTION = "A plugin for RPG Toolkit 3.10";

// You can put one of PT_RPGCODE, PT_FIGHT or PT_MENU to inform the toolkit that's what your plugin does.
PLUGIN_TYPE = PT_RPGCODE;


/*********************************************************************/
///////////////////////////////////////////////////////
// GENERAL INTERFACE
//
// For *all* plugins, you must modify:
// TKPlugBegin
// TKPlugEnd
///////////////////////////////////////////////////////

///////////////////////////////////////////////////////
//
// Function: TKPlugBegin
//
// Parameters: 
//
// Action: called when the Toolkit first
//				sets up the plugin.  Allows you to
//				perform initialisations
//
// Returns: 
//
///////////////////////////////////////////////////////
void APIENTRY TKPlugBegin()
{
}

///////////////////////////////////////////////////////
//
// Function: TKPlugEnd
//
// Parameters: 
//
// Action: called when the Toolkit unloads
//				the plugin.  Allows you to
//				perform deallocations
//
// Returns: 
//
///////////////////////////////////////////////////////
void APIENTRY TKPlugEnd()
{
}