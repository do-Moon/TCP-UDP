TCP/UDP Test

```exe
gcc -lwsock32 socket/client.c -lws2_32 -o client
gcc -lwsock32 socket/server.c -lws2_32 -o server
```