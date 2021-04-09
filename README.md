# open_busy_signal
Arduino based manual control for an open/busy signal in a recording studio. 

I'm the manager of a recording studio in a bigger building. The studio room is quite "hidden" at the end of a corridor and it's impossible to tell without phisically going in if it's open or if there's someone inside.
This is a manual controlled signal that goes outside with three states:
1) **Open (green led)**: studio is open and anyone can enter
2) **Recording (red led)**: studio is open but there's a recording session in place
3) **Off**: no signal active. Studio is closed and no one's there

The three buttons activates the different states.

### Notes
The **ledStates[]** array is not useful in this project since there's no need to check or invert the current state of the leds
