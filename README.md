## Compile
To compile the source files, use the following command:

```bash
gcc -o server server.c -lczmq && gcc -o client client.c -lczmq
```

This should generate the 'server' and 'client' executables.

## Execution
First, open up a terminal and run the 'server' executable by typing `./server` and you will get the following:

```bash
Successfully bound to port 5555
```

Then, open up a new terminal and run the 'client' executable by typing `./client` and you will get the following:

```bash
Client received: Hello from server!
```

On the server terminal, you will get the following response:

```bash
Server received: Hello from client!
```


## References
1. https://youtu.be/dpXKe-dw0uk?si=1hR8a0szF14XdeOh
2. https://libzmq.readthedocs.io/en/latest/
