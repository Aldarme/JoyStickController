/*
 * serialCom.c
 *
 *  Created on: 18 déc. 2017
 *      Author: promet
 */

#include "../headers/Define.h"

/**********variable**************/
int	fd;
struct termios	serialPortSettings;

/*
 * open serial com port
 */
int serialOpen()
{
	/* Ouverture de la liaison serie */
	if ( (fd=open("/dev/ttyUSB0",O_RDWR)) < 0 )
	{
		perror("open");
		return EXIT_FAILURE;
	}



	return EXIT_SUCCESS;


}

/*
 * configure serial com port
 */
int serialConf(void)
{
	/* Lecture des parametres courants */
	tcgetattr(fd,&serialPortSettings);

	cfsetispeed(&serialPortSettings, B115200); //def baudRate for read function
	cfsetospeed(&serialPortSettings, B115200); //def baudRate for write function

	serialPortSettings.c_cflag &= ~PARENB;	//no parity bit

	serialPortSettings.c_cflag &= ~CSTOPB;	// stop bits = 1

	serialPortSettings.c_cflag &= ~CSIZE;	//clears the mask

	serialPortSettings.c_cflag &= ~CS8;		//set the data bits = 8

	serialPortSettings.c_cflag &= ~CRTSCTS;	//Turn off hardware based flow control (RTS/CTS)

	serialPortSettings.c_cflag |= CREAD | CLOCAL; //Turn on the receiver of the serial port (CREAD),other wise reading from the serial port will not work.

	serialPortSettings.c_iflag &= ~(IXOFF); //Turn off software based flow control (XON/XOFF)

	serialPortSettings.c_iflag &= ~(ECHO);	// NON Cannonical mode is recommended, for Serial communications with outside device

	tcsetattr(fd,TCSANOW, &serialPortSettings);	// Sauvegarde des nouveaux parametres

	return EXIT_SUCCESS;
}

/*
 * write data on serial port
 */
int serialWriteInt(int pData)
{
	int write_buffer[] = {pData};
	int  bytes_written  =  0 ;

	bytes_written = write(fd,write_buffer,sizeof(write_buffer));

	return bytes_written;
}

/*
 * write data on serial port
 */
int serialWriteChar(char pData[])
{
	int dataSize = sizeof(pData) / sizeof(pData[0]);
	int  bytes_written  =  0 ;

	bytes_written = write(fd,pData,dataSize);

	return bytes_written;
}

/*
 * close serial com port
 */
void serialClose()
{
	close(fd);
}
