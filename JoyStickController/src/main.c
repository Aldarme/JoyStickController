/*
 * main.c
 *
 *  Created on: 16 déc. 2017
 *      Author: promet
 */

#include "../headers/Define.h"


int main(void)
{

	/*
	 * Init joyStick
	 */
	if(SDL_Init(SDL_INIT_JOYSTICK) < 0)
	{
		return EXIT_FAILURE;
	}

	//get configuration information about the used controller
	getConfig();



}
