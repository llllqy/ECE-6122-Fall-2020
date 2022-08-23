/*
Author: <Qingyuan Liu>
Class: ECE 6122
Last Date Modified: <2020/11/21>
Description:
According to the command to give the next step of the server
including sending receiving and sorting messages  
*/
#include "ECE_UDPSocket.h"
#include <string>
#include <sstream>

using namespace std;

int main(int argc, char* argv[])
{
    int portNo = atoi(argv[1]);
    ECE_UDPSocket UDPserv(portNo);
    bool bStop = false;
    int num{ 0 };

    do
    {
        cout << "Please enter command:" << endl;
        cin >> num;
        switch (num)
        {
            //If command == 0 the server immediately sends to all 
            //clients the current composite message and clears out the composite message.
        case 0:
            cout << "command 0" << endl;
            UDPserv.sendCompositeMsg();
            UDPserv.clearCompositeMsg();
            break;
        case 1:
            //If command == 1 the server immediately clears out the composite message.
            cout << "command 1" << endl;
            UDPserv.clearCompositeMsg();
            break;
        case 2:
            //If command == 2 the server immediately displays to the console the composite message but takes no other actions.
            cout << "command 2" << endl;
            UDPserv.display();
            break;
        case 3:
            //If command == 3 the server application terminates.
            bStop = true;
            UDPserv.sockClose();
            break;
        }

    } while (!bStop);
   
    return 0;
}