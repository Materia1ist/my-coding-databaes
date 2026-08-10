###############################################################################
# Makefile for project 
###############################################################################

## General options
PROJECT = 
MCU = AT89C52
COMPILER = "Keil for 8051"
TARGET = Debug
SHELL = C:\WINDOWS\system32\cmd.exe

## Tools general options
CCFLAGS=ROM(SMALL) BROWSE DEBUG CODE OBJECTEXTEND PREPRINT

## Processing Tools
CC=C51.exe
LD=BL51.exe
ASM=A51.exe
#  D:/my-coding-databaes/C51/51C语言例子/51C语言例子/实物单片机proteus源文件（20230701新/AT89C52/Debug/Debug.OMF: TOOL=LD
#     D:/my-coding-databaes/C51/51C语言例子/51C语言例子/实物单片机proteus源文件（20230701新/AT89C52/Debug/main.OBJ: TOOL=CC
#        D:/my-coding-databaes/C51/51C语言例子/51C语言例子/实物单片机proteus源文件（20230701新/AT89C52/main.c

# Build tree:
all:	Debug

Debug:	Debug.OMF

Debug.OMF:	main.OBJ 
	"C:\Users\17699\AppData\Local\Programs\Labcenter Electronics\Proteus 9 Professional\Tools\MAKE\RunTool.exe" --good-exits=0,1 --executable=$(LD) "main.OBJ" TO "Debug.OMF" $(LDFLAGS) 

main.OBJ:	../main.c 
	"C:\Users\17699\AppData\Local\Programs\Labcenter Electronics\Proteus 9 Professional\Tools\MAKE\RunTool.exe" --good-exits=0,1 --executable=$(CC) "..\main.c" $(CCFLAGS)  OBJECT("main.OBJ")

# tidy - delete all temporary files which are not involved in the target generation
tidy:
	rm -rf Debug.M51
	rm -rf ./main.lst
	rm -rf ./main.I

# cleanup - delete all generated files
clean:	tidy
	rm -rf Debug.OMF
	rm -rf main.OBJ
