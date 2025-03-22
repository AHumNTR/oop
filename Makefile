Source:= src
Include := include
Bin := bin
OutputName := build.exe


build:
	g++15 -std=gnu++26 -fmodules -o $(Bin)/$(OutputName) -I $(Include) $(wildcard $(Source)/*.cpp)
run:
	./$(Bin)/$(OutputName)
