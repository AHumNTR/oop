Source:= src
Include := include
Bin := bin
OutputName := build.exe

all: build run

build:
	g++15 -std=gnu++26 -g -fmodules -o $(Bin)/$(OutputName) -I $(Include) $(wildcard $(Source)/*.cpp)
run:
	./$(Bin)/$(OutputName)
