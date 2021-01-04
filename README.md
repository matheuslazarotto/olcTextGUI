# olcTextGUI
A prototype for a text Guided User Interface (GUI) for the olcPixelGameEngine

## Description
This application is currently a crude version of a text GUI made from and for olcPGE programs. As now, it allows one to click in the canvas and create a text line 
box, with cursor, key and mouse click automatic handling. The code released here provides a example on how it can be used and managed from an olcPGE based application. !Currently the key input is based on ABNT2 format, but it can be easily adapted to US, requiring only a few changes in the `HandleInputKey()` function!

## Usage
To use, right click in canvas starts the text box, after selecting a fitting size, left click to setted and is ready to type. Repetting this process allows the creation of multiple text line boxes. Click inside|outside current existing boxes to activate|deactivate them.

# Credits
This application is fully develop from and for the olcPixelGameEngine, as made by Javidx9, the One Lone Coder https://github.com/OneLoneCoder/olcPixelGameEngine. The original README file can be found and further details can be found in the engine header file, as originally provided.

# Future Features
* + font styles
* color settings
* Automatic detection of keyboard format (ABNT2 / US)
* better portability and easiness of use to any olcPGE based application 
