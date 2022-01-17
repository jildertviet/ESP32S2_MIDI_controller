# ESP32S2_MIDI_controller
ESP32S2 based MIDI controller with 5 sliders  
It uses the internal DAC of the ESP32 which is quite unstable for this purpose.   
#### !!! So I recommend to redesign the board with an external DAC, a MCP3008 for example.  
(I've stabilized the output with a Kalman filter.)  

# Dependancies
- ESP32-S2-WROVER symbol & footprint from snapEDA  
- SimpleKalmanFilter Arduino lib  
- [midiusb.h](https://github.com/chegewara/EspTinyUSB)  
- Maybe some more symbols (ME6211?)  

# Hardware 
[Sliders used (Tinytronics.nl)](https://www.tinytronics.nl/shop/nl/componenten/weerstanden/10k%CF%89-slide-potmeter-standaard-75mm) (had to bend the pins a little bit)

<img src="/images/img.jpeg" alt="ESP32S2_MIDIController" width="500"></img>
<img src="/images/pcb.png" alt="PCB" width="500"></img>
