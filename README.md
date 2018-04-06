# python-control-over-arduino
Capacitive touch piano using Arduino and Python.
Python: Reads serial data using Serial Library from Arduino and plays the corresponding note using laptop speaker.
Arduino: Detects data from capacitive touch unit which can then be read using serial library from the python script and the script can play beep sound corresponding to the correct frequency.

Steps to run on Ubuntu:
	sudo apt install python-pip             
	python -m pip install pyserial                
	sudo apt install beep                       
	sudo modprobe pcspkr              
