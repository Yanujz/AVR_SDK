# rawSerialMonitor
This script provides you a raw serial monitor.  

Download this repo with:
```
cd ~ && git clone https://github.com/Yanujz/rawSerialMonitor.git
```

Copy this file to you system PATH
```
sudo cp ~/rawSerialMonitor/rawSerialMonitor /usr/local/bin
```

# Help usage
```
./rawSerialMonitor -h
usage: rawMonitorSerial -p [port] -b [baudrate]
   
  -p | --port       : Specify Port name
  -b | --baudrate   : Specify baudrate
  -h | --help       : Prompt usage message
 
 Example: ./rawSerialMonitor -p /dev/ttyACM0 -b 115200

```
