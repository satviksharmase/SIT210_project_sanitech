from gpiozero import MotionSensor
from smbus import SMBus
import time

pir=MotionSensor(4)
addr=0x8
bus=SMBus(1)

while True:
    if(pir.wait_for_motion()==True):
        bus.write_byte(addr,0x1)
        time.sleep(1)
        bus.write_byte(addr,0x0)
    else:
        bus.write_byte(addr,0x0)
        time.sleep(1)