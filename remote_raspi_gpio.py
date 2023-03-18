# This is a successful test github remote + raspberry pi remote python development
# including GitHub update and run/debug on raspberry pi

# Aktualisierung GitHub

print ("Dies ist ein GPIO Test mit LEDs  siehe Raspberry PI - Kpmpendium seite 4224.")
from gpiozero import LED
from time import sleep

# LED in connected to GPIO 18 port
led = LED(18)

while True:
    led.on()
    sleep(0.5)
    led.off()
    sleep(0.5)


#led.blink(0.5, 0.5, background=True)
#print("Notice that control has moved away - hit Enter to continue")
#input()
#print("Control is now back")
#led.off()

print ("End of LED GPIO test")
