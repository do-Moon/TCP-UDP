#include <stdio.h>
#include <winsock2.h>

int main()
{
    WSADATA w;
    struct sockaddr_in server;
    char buf[256];
    
    WSAStartup(MAKEWORD(2, 0), &w);

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_port = htons(9999);
    server.sin_family = AF_INET;

    connect(sock, (struct sockaddr *)&server, sizeof(server));
    strcpy(buf, "Connection completed!");
    send(sock, buf, sizeof(buf), 0);

    closesocket(sock);
    WSACleanup();

    return 0;
}