# This is a successful test github remote + raspberry pi remote python development
# including GitHub update and run/debug on raspberry pi

print ("Dies ist ein GPIO Test mit LEDs  siehe Raspberry PI - Kpmpendium seite 4224.")
from gpiozero import LED
from time import sleep
led = LED(18)
led.blink(0.5, 0.5, background=True)
print("Notice that control has moved away - hit Enter to continue")
input()
print("Control is now back")
led.off()
