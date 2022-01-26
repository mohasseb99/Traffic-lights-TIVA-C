# Traffic-lights-TIVA-C
video: https://drive.google.com/file/d/1MDAfkZMJz7k4QnXbhxcYyTxSJ1nTe3WD/view?usp=sharing

Set the normal traffic Light
Use one of the timers to have the two car traffic lights working. The traffic light shall stay GREEN for 5 seconds, then YELLOW for 2
seconds, then turns RED. When one of the traffic lights is set to RED the other one has to go GREEN exactly after 1 second. The same
sequence then is repeated again.
GREEN : 5 seconds YELLOW: 2 seconds Then RED.
Wait 1 second, then start the sequence on the other traffic.
Implement the pedestrian Traffic Light
Use two push buttons and 4 LEDs for this system. There will be two pedestrian traffics, each with a push button and 2 LEDS: GREEN and
RED. Whenever a pedestrian presses the button, the traffic light that is green shall be interrupted, and the pedestrian traffic light will be
green for 2 seconds. Then it will be back to RED and the traffic light that was interrupted will resume from when it was paused.
Example: If the car traffic light was green for 2 seconds and interrupted it will then resume the remaining 3 seconds to finish the 5
seconds.
BONUS PART :
Handle the case if two pedestrians pushed the button together in two different traffics.
Handle the case if the same button was being pressed more than one time during the same period of pedestrian crossing. (Period of
pedestrian crossing is from when the button is pressed for the first time till the pedestrian traffic gets back to RED again.)
Handle the case to delay the request of the pedestrian to cross if the button was pressed after 1 second from the end of the Period of 
