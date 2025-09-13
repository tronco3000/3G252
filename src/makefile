
bin/progama : src/main.cpp include/Foco.hpp include/EstadoFoco.hpp
    c++ src/main.cpp -o bin/programa -I include

run : bin/programa
    ./bin/programa

bin/memoria : src/main.cpp 
    c++ src/memoria.cpp -o bin/memoria

runMemoria : bin/memoria
    ./bin/memoria