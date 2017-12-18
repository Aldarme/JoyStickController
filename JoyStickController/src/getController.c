/*
 * getControllerConfig.c
 *
 *  Created on: 16 déc. 2017
 *      Author: promet
 */

#include "../headers/Define.h"


/*******************variable(s)********************/
SDL_Event myEvent;


/*
 * initialize SDL to use JoyStick
 */
int sdlInit()
{
	if(SDL_Init(SDL_INIT_JOYSTICK) < 0)
	{
		return EXIT_FAILURE;
	}

	//allow to activate joystick event
	SDL_JoystickEventState(SDL_ENABLE);
	return 0;
}


/*
 * get configuration information about the used controller
 */
void getConfig()
{
	//Display the number of the connected joystick
	printf("nbr of Joystick connected : %d\r\n", SDL_NumJoysticks());

	//Display the name of the current conencted joystick
	int i=0;
	for(i=0; i<SDL_NumJoysticks(); i++)
	{
		SDL_Joystick* js = SDL_JoystickOpen(i); //Open a joystick for use.

		printf("%s is connected\r\n", SDL_JoystickName(js)); //get controller name

		/*
		 * Axe informations:
		 * A stick owned 2 axes (left/right, top/bottom)
		 * In fact we find 6 axes; the last axes match with "LT/RT"
		 */
		printf("%d axe(s) are availables\r\n", SDL_JoystickNumAxes(js)); //get nbr of available axes

		printf("%d button(s) are buttons\r\n", SDL_JoystickNumButtons(js)); //get nbr of available buttons

		printf("%d hat(s) are availables\r\n", SDL_JoystickNumHats(js)); //get nbr of available hats

		printf("%d tackball(s) are availables\r\n", SDL_JoystickNumBalls(js)); //get nbr of available tackballs


	}
}


/*
 * Wait controller event
 */
void getEVENT()
{
	while(SDL_WaitEvent(&myEvent))
		{
			switch(myEvent.type)
			{
				case SDL_JOYAXISMOTION:

					if(myEvent.jaxis.axis == 0)
					{
						char StringToSend[15] = "0";

						int jAxisValue = myEvent.jaxis.value;
						char jaxisValString[12]; //use 12 bit for a 32bits int
						sprintf(jaxisValString, "%d", jAxisValue);

						strcat(StringToSend, jaxisValString);

						strcat(StringToSend, "\r\n");

						serialWriteChar(StringToSend);
						//printf(" %d axe value: %d \r\n", myEvent.jaxis.axis, myEvent.jaxis.value);
					}

					if(myEvent.jaxis.axis == 3)
					{
						char StringToSend[15] = "3";

						int jAxisValue = myEvent.jaxis.value;
						char jaxisValString[12]; //use 12 bit for a 32bits int
						sprintf(jaxisValString, "%d", jAxisValue);

						strcat(StringToSend, jaxisValString);

						strcat(StringToSend, "\r\n");

						serialWriteChar(StringToSend);
						//printf(" %d axe value: %d \r\n", myEvent.jaxis.axis, myEvent.jaxis.value);
					}

					if(myEvent.jaxis.axis == 4)
					{
						char StringToSend[15] = "4";

						int jAxisValue = myEvent.jaxis.value;
						char jaxisValString[12]; //use 12 bit for a 32bits int
						sprintf(jaxisValString, "%d", jAxisValue);

						strcat(StringToSend, jaxisValString);

						strcat(StringToSend, "\r\n");

						serialWriteChar(StringToSend);
						//printf(" %d axe value: %d \r\n", myEvent.jaxis.axis, myEvent.jaxis.value);
					}

					break;
			}
		}

}

