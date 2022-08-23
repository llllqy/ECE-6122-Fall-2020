/*
Author: <Qingyuan Liu>
Class: ECE 6122
Last Date Modified: <2020/11/21>
Description:
According to the command, give the next step of the client.
sending messages
*/
#include<string>
#include <sstream>
#include "ECE_UDPSocket.h"
#include <vector>
#include <cstring>

using namespace std;

int main(int argc, char* argv[])
{
    string inStr;
    string in;
    udpMessage msg;
    msg.nVersion = 0;
    unsigned short clientportno = 17172;
    ECE_UDPSocket UDP(clientportno);

    unsigned short portno = atoi(argv[2]);
    bool bStop = false;
    UDPclient.clientorNot = true;//is client

    while (!bStop)
    {
        printf("Please enter a command:");
        getline(cin, inStr);
        vector<string> strings;
        istringstream f(inStr);
        string s;

        while (getline(f, s, ' ')) {
            strings.push_back(s);//process input command
        }
        if (strings.size() == 1 && strings[0].at(0) == 'q')//if command is q, close the application
        {
            bStop = true;
            UDPclient.sockClose();
            break;
        }
        else if (strings.size() == 2 && strings[0].at(0) == 'v')//if command is v, choose the version
        {
            msg.nVersion = atoi(strings[1].c_str());
        }
        else if (strings.size() > 3 && strings[0].at(0) == 't')//if command is t ,according to type to process msg
        {
            string outStr;
            msg.nType = atoi(strings[1].c_str());//transfer type
            msg.lSeqNum = atoi(strings[2].c_str());//choose sequence
            memset(msg.chMsg, 0, 1000);
            for (int ii = 3; ii < strings.size(); ++ii)//process msg
            {
                outStr += strings[ii];
                if (ii != strings.size() - 1)
                    outStr += " ";
            }
            msg.nMsgLen = outStr.length();
            memcpy(msg.chMsg, outStr.c_str(), outStr.length());
            UDPclient.sendMessage(argv[1], portno, msg);//resturn msg
        }
        
    }
    return 0;
}