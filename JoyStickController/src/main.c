/*
 * main.c
 *
 *  Created on: 16 déc. 2017
 *      Author: promet
 */

#include "../headers/Define.h"
int i =0;

SDL_Event myEvent;

int main(void)
{

	/*
	 * Init joyStick
	 */
	if(SDL_Init(SDL_INIT_JOYSTICK) < 0)
	{
		return EXIT_FAILURE;
	}

	//allow to activate joystick event
	SDL_JoystickEventState(SDL_ENABLE);

	//get configuration information about the used controller
	getConfig();




	while(SDL_WaitEvent(&myEvent))
	{
		switch(myEvent.type)
		{
			case SDL_JOYAXISMOTION:
				if(myEvent.jaxis.axis == 0)
				{
					printf(" %d axe value \r\n", myEvent.jaxis.axis, myEvent.jaxis.value);
				}

				break;
		}
	}


}
