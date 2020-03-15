# Sound analysis

This is application development ver 1.1 - written by Minh Hoang, instructed by Chao Gao

This application offers a possibility to turn a Raspberry Pi into a sound device. The application comes with 2 functions: a sound collector and a test tone generator.

## 1. Configuration Instruction
	
This project is built on a Raspberry Pi3, with an external USB sound card and a microphone. Ethernet connection is required.

## 2. Installation Instruction

* Install the latest NOOBS version for Raspberry Pi. You can get it from 
    ```link
    https://www.raspberrypi.org/downloads/noobs/
    ```

* Set the external USB sound card as Default
	- Run ```lsusb``` command to check if your USB soundcard is mounted
	- Use command 
        ```bash
        sudo nano /etc/asound.conf
        ``` 
        and put following content to file

        ```
        pcm.!default {
            type plug
            slave {
            pcm "hw:1,0"
            }
        }
        ctl.!default {
            type hw
            card 1
        }
        ```

    - Go to your home directory by command ```cd $HOME```, then use ```nano .asoundrc``` and put the same content to the file
	
    - Run ```alsamixer```, you should be able to see that USB sound card is the default audio device

* Fix the bug of arecord by downgrade the alsa-utils from 1.0.28 to 1.0.25
	- Run 
        ```
        sudo apt-get update
        ```
	- Run 
        ```
        sudo aptitude versions alsa-utils
        ```
        to check if version 1.0.25 of alsa-util is available
	-  Run 
        ```
        sudo apt-get install alsa-utils=1.0.25-4
        ``` 
        to downgrade then reboot

* Install ```libcurl``` and its development API
	- Use command 

        ```bash
        ls /usr/include/curl
        ``` 

        or 
        ```bash
        ls /usr/include arm-linux-gnueabihf/curl
        ``` 
        to identify that libcurl is installed
	-  If the folder does not exist, run 
        ```bash
        sudo apt-get update
        ```
	-  Run 
        ```bash
        sudo apt-get install libcurl3
        ```
        and 
		```bash
        sudo apt-get install libcurl4-openssl-dev
        ```
        to install libcurl and its development API

## 3. Operating Instruction
Run command
    
```
make
``` 

to compile all the files and run 
```
./sound.out
``` 
for running the program. You can also open ```testcurl.txt``` for accessing the recorded results.

## 4. List of Files
* README.md : this file
* comm.c : the communication part of the project
* comm.h : the header file of comm.c
* main.c : contains the main() function
* makefile : the makefile of the project
* screen.c : the displaying part of the project
* screen.h : the header file of screen.c
* sound.c : the sound analyzing part of the project
* sound.h : the header file of the sound.c
* sound.php : the data receiving page
* testcurl.c : the communication testing module

## 5. Contact Info.
2019

Minh Hoang &copy;, e1800950@edu.vamk.fi

## 6. Credits and Acknowledgements
This project is written by me, instructed by Dr. Chao Gao, and a SD card is given by VAMK.
