# olcTextGUI
A prototype for a text Guided User Interface (GUI) for the olcPixelGameEngine

## Description
This program is currently a crude version of a text GUI made for olcPGE applications. 
In its current state, it allows one to click in the canvas to create a text line 
box with adjustable size, with cursor, key and mouse handling. The code released 
here provides an example on how it can be used and managed from an olcPGE based 
application. !Currently the key input is based on ABNT2 format, but it can be 
easily adapted to US format, requiring only a few changes in `HandleInputKey()` 
function!

<img std="img/figures/app-demo.png" width=90>

## Usage
To use, a right mouse click in canvas starts an adjustable text box which is settled 
by a left click, afterwhich is ready to type. Repetting this process allows the 
creation of multiple text line boxes. A click inside(outside) a current existing 
box will activate(deactivate) it.

## Install
The makefile attached provides all flags for compilation, considering Linux OS, 
requiring only a `make` command. Although olcPGE is multiplatform, this code is 
primarily made for Linux OS, without any testing in Windows, however, it shall be 
trivially portable. 

In order to run on Linux, the application must be executed with `vblank_mode=0 ./application`, 
avoiding FPS locking. The olcPGE compilation requires basic obtainable libraries, which 
can be retrieved in Ubuntu with:

`sudo apt install build-essential libglu1-mesa-dev libpng-dev`

More information for other distros can be found at:
https://github.com/OneLoneCoder/olcPixelGameEngine/wiki/Compiling-on-Linux

# Credits
This application is fully developed from and for the olcPixelGameEngine, as provided 
by Javidx9, the One Lone Coder https://github.com/OneLoneCoder/olcPixelGameEngine. 
The original README and LICENSE files can be found attached, along with further details 
in the engine header file.

# Future Features
* + font styles
* Color settings
* Copy and paste command
* Text selection for cut and copy
* Automatic detection of keyboard format (ABNT2 / US)
* Better portability and ease of use

Author: M. Lazarotto (Last Update: 04/01/2021)
