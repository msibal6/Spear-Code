# Keyboard 
This is my project to handwire a keyboard

## Source Code 

I adapted this code from @huytd 's snackymini-keyboard project. Big thanks  
to them! I would not know where to start  with all the firmware stuff.  
[See the original!](https://github.com/huytd/snackymini-keyboard)

## Details  
Firmware is for a Dell-AT101 keyboard. It is a ANSI 104 keyboard.  

## Design Choices  
I chose to use a teensy 3.2 because no other controller that I was looking  
had enough digital I/O slots to support the number that I needed with  
the ANSI 104 form factor.  

## Why  

I do not think any of this stuff is particularly important but it is quite  
fun to document the process. * say this in a a British accent. *  Also  
I am now paying 5 dollars a month for large file storage so why not?  
\* insert shrugging emoticon * Also, ain't this the way to start a company  
is to hold yourself to a higher standard to others and yourself to see  
and scrutinize in order to improve.  

## Progress  

* **3/28** I have finished wiring the ROW and COL of the keyboard. Waiting  
for more hookup wire to wire them to the teensy. Finished configuration  
 of `firmware.ino` to fit my keyboard.

* **4/3** I wired the teensy to my wirings last night. Today I tested the  
firmware and now IM TYYPING ON IT!!! LETS GOO.
There were a few things that needed tweaking in  the modifier keys. I  
fixed those and now, the only thing that needs to be fixed is the solder  
connection on my 7+1 switch and this keyboard will be as good as new. I  
am excited to make my next keyboard already, and i will handwire it again 
lol 

## Helpful Links

* [Kribbit's Handwiring guide](https://geekhack.org/index.php?topic=87689.0)
* [Swillkb (Plate Generator)](http://builder.swillkb.com/)

