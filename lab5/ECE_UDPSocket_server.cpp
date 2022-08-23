/*
Author: <Qingyuan Liu>
Class: ECE 6122
Last Date Modified: <2020/11/21>
Description:
It is the socket server implementation of class ECE_UDPSocket
*/
#include "ECE_UDPSocket.h"
#include<cstring>

int ECE_UDPSocket::sockInit(void)
{
#ifdef _WIN32
    WSADATA wsa_data;
    return WSAStartup(MAKEWORD(1, 1), &wsa_data);
#else
    return 0;
#endif
}
// Cross-platform socket quit
int ECE_UDPSocket::sockQuit(void)
{
#ifdef _WIN32
    return WSACleanup();
#else
    return 0;
#endif
}
// Cross-platform socket close
int ECE_UDPSocket::sockClose(void)
{

    int status = 0;

#ifdef _WIN32
    status = shutdown(sock_fd, SD_BOTH);
    if (status == 0)
    {
        status = closesocket(sock_fd);
    }
#else
    status = shutdown(sock_fd, SHUT_RDWR);
    if (status == 0)
    {
        status = close(sock_fd);
    }
#endif

    return status;
}
//compare 
bool compare(udpMessage msg1, udpMessage msg2)
{
    return msg1.lSeqNum < msg2.lSeqNum;
}

// Function called by thread
void receiveSocketMsgs(ECE_UDPSocket* pUDpSocket)
{
    // Loop that waits on incoming messages
    udpMessage inMsg;
    int n;
    sockaddr_in from;
    socklen_t fromlen;
	fromlen = sizeof(from);

    while (true)
    {
		// Insert message into list based on sequence number
        n = recvfrom(pUDpSocket->sock_fd, (char*)&inMsg, sizeof(inMsg), 0, (struct sockaddr*)&from, &pUDpSocket->fromlen);
        pUDpSocket->m_lstSources.push_back(from);
        if (n < 0)
        {
            break;
        }
        if (inMsg.nVersion == 1)
        {
            string receivedMsg;
            receivedMsg.clear();
            receivedMsg = "Received message Type:" + to_string(inMsg.nType) + ", Seq:" + to_string(inMsg.lSeqNum) + ", message:" + inMsg.chMsg;
            n = sendto(pUDpSocket->sock_fd, receivedMsg.c_str(), receivedMsg.length(), 0, (struct sockaddr*) & from, pUDpSocket->fromlen);
            pUDpSocket->getNextMessage(inMsg);
        }            
    }
#ifdef _WIN32
    std::cin.get();
#endif
    return;
}
//ini UDP SOCKET
ECE_UDPSocket::ECE_UDPSocket(unsigned short portNo)
{
    
    sockaddr_in serv_addr;
    // Setup socket
    sockInit();
    // Create the socket
    sock_fd = socket(AF_INET, SOCK_DGRAM, 0);
    // Make sure the socket was created
    if (sock_fd < 0)
        error("ERROR opening socket");
    // Zero out the variable serv_addr
    memset((char*)&serv_addr, sizeof(serv_addr), 0);
    // Initialize the serv_addr
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    // Convert port number from host to network
    serv_addr.sin_port = htons(portNo);
    if (bind(sock_fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0)
    {
        error("ERROR on binding");
    }
    fromlen = sizeof(struct sockaddr_in);

    // Starting thread that receive the messages 
  
    m_recvThread = thread(receiveSocketMsgs, this);
}
//determine the type of message
bool ECE_UDPSocket::getNextMessage(udpMessage& message)
{
    if (message.nVersion == 1)
    {
        switch (message.nType)
        {
        case 0:
            m_msgs.clear();
            break;
        case 1:
            m_msgs.clear();
            m_msgs.push_back(message);
            break;
        case 2:
            m_msgs.push_back(message);
            m_msgs.sort(compare);
            break;
        case 3:
            m_msgs.push_back(message);
            addSource();
            processMessage();
            sendCompositeMsg();
            m_msgs.clear();
            break;
        default:
            break;
        }
        return true;
    }

    return false;
}
//send message func
void ECE_UDPSocket::sendMessage(const string& strTo, unsigned short usPortNum, const udpMessage& message)
{
    struct sockaddr_in addr;
    struct hostent* server;
    const char* ipAddr = strTo.c_str();

    server = gethostbyname(ipAddr);
    memset((char*)&addr, sizeof(addr), 0);
    addr.sin_family = AF_INET;
    memmove((char*)&addr.sin_addr.s_addr, (char*)server->h_addr, server->h_length);
    addr.sin_port = htons(usPortNum);

    int n = sendto(sock_fd, (char*)&message, sizeof(message), 0, (struct sockaddr*) & addr, sizeof(addr));
    if (n < 0)
        error("ERROR writing to socket");
}
//process message to composite 
void ECE_UDPSocket::processMessage()
{

    compositeMsgs.clear();
    for (it_msgs = m_msgs.begin(); it_msgs != m_msgs.end(); ++it_msgs)
    {
        compositeMsgs += it_msgs->chMsg;
    }
    if (sizeof(compositeMsgs) > 1000)
    {
       
        for (sources = m_lstSources.begin(); sources != m_lstSources.end(); ++sources)
        {
            int n = sendto(sock_fd, (char*)&compositeMsgs, sizeof(compositeMsgs), 0, (struct sockaddr*)&sources, sizeof(struct sockaddr_in));
        }
    }

}
//add source to composite message
void ECE_UDPSocket::addSource()
{
    string::iterator it;
    for (int i = 0; i < 1000; ++i)
    {
        compositeMsgs.erase(it);
    }
}
//after finishing the composite message£¬send it
void ECE_UDPSocket::sendCompositeMsg()
{
   
    string sendMsg;
    sendMsg.clear();
    sendMsg = "Composite message: " + compositeMsgs;
    for (sources = m_lstSources.begin(); sources != m_lstSources.end(); ++sources)
    {
        int n;
        n = sendto(sock_fd, sendMsg.c_str(), sendMsg.length(), 0, (struct sockaddr*)&*sources, fromlen);
    }
};
//display composite message
void ECE_UDPSocket::display()
{
    processMessage();
    cout << "Composite message is: " << compositeMsgs << endl;
}
//clear composite message
void ECE_UDPSocket::clearCompositeMsg()
{
    m_mutex.lock();
    m_msgs.clear();
    m_mutex.unlock();

}
//close the socket 
ECE_UDPSocket::~ECE_UDPSocket()
{
    sockClose();
    sockQuit();
    m_recvThread.join();
}

// Output error message and exit
void ECE_UDPSocket::error(const char* message)
{
    perror(message);
    exit(1);
}

