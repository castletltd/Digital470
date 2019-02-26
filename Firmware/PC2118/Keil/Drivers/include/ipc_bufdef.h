/**********************************************************************
* $Id$		ipc_bufdef.h		2012-01-19
*//**
* @file		ipc_bufdef.h
* @brief	IPC Buffer Definitions
* @version	1.0
* @date		19. January. 2012
* @author	NXP MCU SW Application Team
*
* Copyright(C) 2012, NXP Semiconductor
* All rights reserved.
*
***********************************************************************
* Software that is described herein is for illustrative purposes only
* which provides customers with programming information regarding the
* products. This software is supplied "AS IS" without any warranties.
* NXP Semiconductors assumes no responsibility or liability for the
* use of the software, conveys no license or title under any patent,
* copyright, or mask work right to the product. NXP Semiconductors
* reserves the right to make changes in the software without
* notification. NXP Semiconductors also make no representation or
* warranty that such application will be suitable for the specified
* use without further testing or modification.
* Permission to use, copy, modify, and distribute this software and its
* documentation is hereby granted, under NXP Semiconductors’
* relevant copyright in the software, without fee, provided that it
* is used in conjunction with NXP Semiconductors microcontrollers.  This
* copyright, permission, and disclaimer notice must appear in all copies of
* this code.
**********************************************************************/
#ifndef __IPC_BUFDEF_H 
#define __IPC_BUFDEF_H


/* accomodate the required number of messages, on the biggest message type plus one for the ring buffer */
#define MSG_BUF_LEN (SLAVE_MSGBUF_SIZE + 1)

typedef struct msgBlock_tag {

	/* read and write pointers for accessing the command buffer */
	msgToken* msgQstartAddress;
	msgToken* msgQendAddress;
	msgToken* msgRdPtr;
	msgToken* msgWrPtr;
	
} msgBlock;

/* buffer space holding messages */
extern msgToken _hostMsgBufferData[MSG_BUF_LEN];


/* accomodate the required number of commands plus one for the ring buffer */
#define CMD_BUF_LEN (MASTER_CMDBUF_SIZE + 1)

typedef struct cmdBlock_tag {

	/* read and write pointers for accessing the command buffer */
	cmdToken* cmdQstartAddress;
	cmdToken* cmdQendAddress;
	cmdToken* cmdRdPtr;
	cmdToken* cmdWrPtr;
	
} cmdBlock;

/* buffer space holding commands */
extern cmdToken _hostCmdBufferData[CMD_BUF_LEN];

#endif /**/

