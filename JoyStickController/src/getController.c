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

				if(myEvent.jaxis.axis == 1
						&& (myEvent.jaxis.value < -10000 || myEvent.jaxis.value > 10000 ))
				{
					char StringToSend[16] = "1";

					strcat(StringToSend, "=");

					int pval=0;
					if(myEvent.jaxis.value < 0)
					{
						pval = myEvent.jaxis.value *(-1);
					}
					else
					{
						pval = myEvent.jaxis.value*(-1);
					}

					int jAxisValue = pval-1;
					char jaxisValString[12]; //use 12 bit for a 32bits int
					sprintf(jaxisValString, "%d", jAxisValue);

					strcat(StringToSend, jaxisValString);

					strcat(StringToSend, "\n");

					serialWriteChar(StringToSend);
					printf(StringToSend);

				}

				if(myEvent.jaxis.axis == 3
						&& (myEvent.jaxis.value < -10000 || myEvent.jaxis.value > 10000 )
						&& (myEvent.jaxis.value != 32768))
				{
					char StringToSend[14] = "3";

					strcat(StringToSend, "=");

					int pval=0;
					if(myEvent.jaxis.value < 0)
					{
						pval = myEvent.jaxis.value *(-1);
					}
					else
					{
						pval = myEvent.jaxis.value*(-1);
					}

					int jAxisValue = pval;

					char jaxisValString[12]; //use 12 bit for a 32bits int
					sprintf(jaxisValString, "%d", jAxisValue);

					strcat(StringToSend, jaxisValString);

					strcat(StringToSend, "\n");

					serialWriteChar(StringToSend);
					printf(StringToSend);

				}

				if(myEvent.jaxis.axis == 4
						&& (myEvent.jaxis.value < -10000 || myEvent.jaxis.value > 10000 )
						&& (myEvent.jaxis.value != 32768))
				{
					char StringToSend[14] = "4";

					strcat(StringToSend, "=");

					int pval=0;
					if(myEvent.jaxis.value < 0)
					{
						pval = myEvent.jaxis.value *(-1);
					}
					else
					{
						pval = myEvent.jaxis.value*(-1);
					}

					int jAxisValue = pval;

					char jaxisValString[12]; //use 12 bit for a 32bits int
					sprintf(jaxisValString, "%d", jAxisValue);

					strcat(StringToSend, jaxisValString);

					strcat(StringToSend, "\n");

					serialWriteChar(StringToSend);

					printf(StringToSend);
				}

			break;
		}
	}
}

