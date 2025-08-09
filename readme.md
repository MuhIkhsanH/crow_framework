
*WSL:*

```
g++ main.cpp -std=c++17 -O2 -pthread \
  -I/mnt/c/Crowku/Crow/include \
  -I/mnt/c/Crowku/asio/asio/include \
  -o main
```


*EXE:*

```
x86_64-w64-mingw32-g++ main.cpp -std=c++17 -O2 -pthread \
-I/mnt/c/Crowku/Crow/include \
-I/mnt/c/Crowku/asio/asio/include \
-o main.exe -lws2_32 -lmswsock -static-libgcc -static-libstdc++
```
