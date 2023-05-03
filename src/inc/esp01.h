/*
 * esp01.h
 *
 *  Created on: 3 may. 2023
 *      Author: Carlos Lecaro
 *      Email: carlos1992@hotmail.es
 *
 */

#ifndef INC_ESP01_H_
#define INC_ESP01_H_


/*
 * ESP COMMANDS ENUMS
 */

/* WIFI_MODE_ENUM */
enum wifi_mode {
	WIFI_MODE_STA = 1,
	WIFI_MODE_AP = 2,
	WIFI_MODE_STA_AP = 3
};

enum encryption{
	OPEN = 0,
	WEP = 1,
	WPA_PSK = 2,
	WPA2_PSK = 3,
	WPA_WPA2_PSK = 4
};

enum boolean{
	FALSE = 0,
	TRUE = 1
};

enum status{
	DISABLE = 0,
	ENABLE = 1
};

enum con_status{
	GOTIP = 2,
	CONNECTED = 3,
	DISCONNECTED = 4
};

enum connection_type{
	TCP = 0,
	UDP = 1
};

enum mux_conn{
	SINGLE_CON = 0,
	MULTIPLE_CON = 1
};

enum server_opt{
	DELETE_SERVER = 0,
	CREATE_SERVER = 1
};

enum transfer_mode{
	NORMAL_MODE = 0,
	UNIVARISHED_MODE = 1
};



/*
 * ESP-01 AT COMMANDS
 */


/* Basic AT Commands */

#define TEST_CMD "AT"				/* Test AT communication */
#define ESP_RESET "AT+RST"			/* Reset module */
#define ESP_INFO "AT+GMR"			/* Get firmware version */
#define GO_SLEEP "AT+GSLP"			/* Enter device in deep sleep mode */
#define SET_ECHO "ATE"				/* Enable-Disable echo */

/* WiFi AT Commands */

#define WIFI_MODE "AT+CWMODE"		/* Set WIFI operation mode */
#define CON_AP "AT+CWJAP"			/* Connect ESP to AP */
#define LIST_AP "AT+CWLAP"			/* List the available AP */
#define DISC_AP "AT+CWQAP"			/* Disconnect ESP from AP */
#define SET_SOFTAP "AT+CWSAP"		/* Configure ESP as AP mode */
#define LIST_CLI "AT+CWLIF"			/* List clients connected to softAP */
#define SET_DHCP "AT+CWDHCP"		/* Enable-Disable DHCP */
#define SET_MAC_STA "AT+CIPSTAMAC"	/* Set MAC to ESP station */
#define SET_MAC_AP "AT+CIPAPMA"		/* Set MAC to ESP softAP */
#define SET_IP_STA "AT+CIPSTA"		/* Set IP to ESP station */
#define SET_IP_AP "AT+CIPAP"		/* Set IP to ESP softAP */

/* TCPIP AT Commands */

#define CON_STATUS "AT+CIPSTATUS"	/* Information about connection */
#define TCP_UDP_CON "AT+CIPSTART"	/* Make TCP connection or register UDP port and start connection */
#define SEND_DATA "AT+CIPSEND"		/* Send data */
#define CON_CLOSE "AT+CIPCLOSE"		/* Close TCP or UDP connection */
#define GET_IP "AT+CIFSR"			/* Get local IP address */
#define MULT_CON "AT+CIPMUX"		/* Enable multiple connections */
#define SERVER "AT+CIPSERVER"		/* Configure as a server */
#define TRANS_MODE "AT+CIPMODE"		/* Set transfer mode */
#define SRV_TIMEOUT "AT+CIPSTOP"	/* Set server timeout */
#define RCV_DATA "+IDP" 			/* Receive network data */



/*
 * Function: esp_hardware_reset
 * ----------------------------
 * Perform a reset the ESP module pulling low the reset pin
 * delay: Amount of ms pulled low the reset pin
 * return: void
 */
void esp_hardware_reset(uint8_t delay);

/*
 * Function: esp_software_reset
 * ----------------------------
 * return: 0 if the esp respond OK after send reset command
 * 		   1 if the esp not respond after send reset command
 */
uint8_t esp_software_reset(void);








#endif /* INC_ESP01_H_ */
