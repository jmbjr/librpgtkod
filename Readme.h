/*
 This project has been preconfigured to build a simple Toolkit 3.1.0 plugin.

 To customise the plugin, open the 'Configuration Files' folder in the Solution Explorer.

 Inside of Plugin.cpp, you can change the description of your plugin and what it does.

 Inside of FightPlugin.cpp you can code handlers for a built-in battle system (like tk3fight.dll).
 Inside of MenuPlugin.cpp you can code handlers for a built-in menu system (like tk3menu.dll).
 Inside of RPGCodePlugin.cpp you can code hanlders for RPGCode commands.

 And a 'Your Files' folder is provided to put all your code in.

 Enjoy!
*/

/* HOW TO USE THE 'tkParameter.h' FILE
 *
 * Included here is a header and cpp file not in the original sources.
 * These files are in the public domain; this means you can do anything with them
 * with no restrictions whatsoever.
 *
 * Since the provided functions for parameter extraction don't work (at least for me),
 * I coded a robust parameter parser.
 *
 * To use it, first include tkParameter.h.
 *
 * Now locate TKPlugExecute (it's in RPGCodePlugin.cpp). The string that the Toolkit gives
 * you here is what you have to feed to TK::extractParameterInfo.
 *
 * If you're like me and use a C++ function for each RPGCode function then
 * you can do one of two things:
 * (a) Pass pstrCommand to the C++ function and make it extract the info. (recommended)
 *
 * (b) Use TK::extractParameterInfo on pstrCommand from inside the TKPlugExecute function
 *     and then pass the ParameterInfo to the function. (not recommended - copying std::map is slow)
 *
 * Then to get a parameter from the ParameterInfo use
 * TK::getStringParam or TK::getFloatParam functions.
 *
 * The offsets for the getParam functions are 1-based:
 * to get the first parameter use 1 as the second argument.
 *
 * If you access an out-of-range parameter the functions will throw an int.
 * Prevent a crash by encapsulating functions in a try/catch block.
 */
