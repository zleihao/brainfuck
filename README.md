# 编译

## MinGW

```c
cmake -S . -B build  -G "MinGW Makefiles"
    
cd build
    
make
```

## Mac/Linux

`````
cmake -S . -B build

cd build
    
make
`````

# 运行

```bash
./build/brainfuck ./example/helloworld.bf
```

