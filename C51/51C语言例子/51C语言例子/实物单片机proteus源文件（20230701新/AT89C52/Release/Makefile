###############################################################################
# Makefile for project 
###############################################################################

## General options
PROJECT = 
MCU = AT89C52
COMPILER = "Keil for 8051"
TARGET = Release
SHELL = C:\WINDOWS\system32\cmd.exe

## Tools general options
CCFLAGS=ROM(SMALL)

## Processing Tools
CC=C51.exe
LD=BL51.exe
ASM=A51.exe
#  D:/my-coding-databaes/C51/51C语言例子/51C语言例子/实物单片机proteus源文件（20230701新/AT89C52/Release/Release.hex: TOOL=LD
#  Post: "C:\Users\17699\AppData\Local\Keil_v5\C51\BIN\OH51.exe" ".\Release.OMF"
#     D:/my-coding-databaes/C51/51C语言例子/51C语言例子/实物单片机proteus源文件（20230701新/AT89C52/Release/main.OBJ: TOOL=CC
#        D:/my-coding-databaes/C51/51C语言例子/51C语言例子/实物单片机proteus源文件（20230701新/AT89C52/main.c

# Build tree:
all:	Release

Release:	Release.hex
	cp "Release.hex" "D:/my-coding-databaes/C51/51C语言例子/51C语言例子/实物单片机proteus源文件（20230701新/AT89C52.hex"

Release.hex:	main.OBJ 
	"C:\Users\17699\AppData\Local\Programs\Labcenter Electronics\Proteus 9 Professional\Tools\MAKE\RunTool.exe" --good-exits=0,1 --executable=$(LD) "main.OBJ" TO ".\Release.OMF" $(LDFLAGS) 
	"C:\Users\17699\AppData\Local\Keil_v5\C51\BIN\OH51.exe" ".\Release.OMF"

main.OBJ:	../main.c 
	"C:\Users\17699\AppData\Local\Programs\Labcenter Electronics\Proteus 9 Professional\Tools\MAKE\RunTool.exe" --good-exits=0,1 --executable=$(CC) "..\main.c" $(CCFLAGS)  OBJECT("main.OBJ")

# tidy - delete all temporary files which are not involved in the target generation
tidy:
	rm -rf Release.M51
	rm -rf ./main.lst
	rm -rf ./main.I

# cleanup - delete all generated files
clean:	tidy
	rm -rf Release.hex
	rm -rf main.OBJ
