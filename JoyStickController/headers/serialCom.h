/*
 * serialCom.h
 *
 *  Created on: 18 déc. 2017
 *      Author: promet
 */

#ifndef HEADERS_SERIALCOM_H_
#define HEADERS_SERIALCOM_H_


int serialOpen();
int serialConf(void);
int serialWriteInt(int pData);
int serialWriteChar(char pData[]);
void serialClose();

#endif /* HEADERS_SERIALCOM_H_ */
