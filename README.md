# ESP32S2_MIDI_controller
ESP32S2 based MIDI controller with 5 sliders  
It uses the internal DAC of the ESP32 which is quite unstable for this purpose.   
So I recommend to redesign the board with an external DAC, a MCP3008 for example.   
(I've stabilized the output with a Kalman filter.)  

# Dependancies
ESP32-S2-WROVER symbol & footprint from snapEDA  
SimpleKalmanFilter Arduino lib  
[midiusb.h](https://github.com/chegewara/EspTinyUSB)  
Maybe some more things (ME6211?)

<img src="/images/img.jpg" alt="ESP32S2_MIDIController" width="500"></img>
<img src="/images/pcb.png" alt="PCB" width="500"></img>
