/*
 * main.c
 *
 *  Created on: 16 déc. 2017
 *      Author: promet
 */

#include "../headers/Define.h"
int i =0;



int main(void)
{
	//Init SDL to use joystick
	sdlInit();

	//get configuration information about the used controller
	getConfig();

//	if(serialOpen() ==  EXIT_SUCCESS)
//	{
//		printf("Serial Com Port : OPEN\r\n");
//	}
//	else{
//		printf("Serial Com Port : fail to open\r\n");
//		return EXIT_FAILURE;
//	}
//
//	if(serialConf() == EXIT_SUCCESS)
//	{
//		printf("Serial Com Port Config: OK\r\n");
//	}
//	else{
//		printf("Serial Com Port Config: fail to config\r\n");
//		return EXIT_FAILURE;
//	}

	//get event from controler
	getEVENT();

}
