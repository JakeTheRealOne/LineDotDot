# About the application
This is a Qt application that is litteraly a digital telegraph. (conversion and transmission of morse messages)

# Important message
The Windows application is not yet available, It is very unstable and major issues need to be fixed. Coming soon... (in like 20 or 30 years if I get bored of my other stuff)
# Features
- Convert any text to morse and vice versa
- Extract from file / Embed into file (coming soon)
- Send via light transmission (coming soon)
- Send via radio transmission (coming soon)
- Knowledge book (coming soon)

# Getting started
## Dependencies (Linux)
    ttf-font-awesome [AUR package]
## Run the application
### Linux
    ./LineDotDot-linux
### Windows (Not yet available)
    L̶i̶n̶e̶D̶o̶t̶D̶o̶t̶-̶w̶i̶n̶d̶o̶w̶s̶.̶e̶x̶e̶
## Rebuild from source
You need to install qt5 and git to compile the code:
#### -> on Arch Linux (btw)
    sudo pacman -S qt5-base git
#### -> on Ubuntu
    sudo apt install qt5-qmake qt5-default git
#### -> on Red Hat
    sudo dnf install qt5-qtbase-devel qt5-qmake git
Then you can recompile from source with these commands ( installed)

    git clone https://github.com/JakeTheRealOne/LineDotDot.git
    cd LineDotDot
    qmake
    make

