# This is a successful test github remote + raspberry pi remote python development
# including GitHub update and run/debug on raspberry pi

print ("Dies ist ein GPIO Test mit LEDs  siehe Raspberry PI - Kpmpendium seite 4224.")
from gpiozero import LED
from time import sleep

# LEDs are connected to GPIO 17 and GPIO 18 port
led1 = LED(4)
led2 = LED(17)

while True:
    led2.on()
    sleep(0.1)
    led2.off()
    sleep(0.1)
   
    led1.on()
    sleep(0.1)
    led1.off()
    sleep(0.1)


#led.blink(0.5, 0.5, background=True)
#print("Notice that control has moved away - hit Enter to continue")
#input()
#print("Control is now back")
#led.off()

print ("End of LED GPIO test")
