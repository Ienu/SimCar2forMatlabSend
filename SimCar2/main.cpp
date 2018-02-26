#include "SIGService.h"
#include <iostream>
#include <conio.h>

using namespace std;

int main(int argc, char** argv)	// SimCar2 192.168.1.173 9000 h7car GO_STRAIGHT
{
	if(argc != 4)
	{
		std::cerr << "parameter error" << std::endl;
		return -1;
	}
	sigverse::SIGService srv("MyService");
	int port = atoi(argv[2]);
	srv.connect(argv[1], port);
	while(true)
	{
		char ch = _getch();
		char msg[10] = "";
		msg[0] = ch;
		msg[1] = '\0';
		srv.sendMsg(argv[3], msg);
	}
	srv.disconnect();  
	return 0;
}