# DHCP-Server-Scope-Monitor
A monitor which can keep watching how many ip in scope have been used and execute response activity (!!Only for Windows Server)

Attention!
----------------------------------------------------------------------
This monitor only works Windows Server because i writed it in Dos.

User Manual
--------------------
1. Use Run.bat to run the monitor. The bat will ask to get the administrator 
rights beacause only admin can read the mib information.

2. You can add response strategies in action folder. i.e. The "1.1.bat" will 
be called when the ip used or pending in first ip pool(scope) more than 10%,
the "2.5.bat" will run when the ip used or pending in second ip pool(scope) 
more than 50%.

3. This monitor just use netsh to load mib information and process the information
provided by the system then get the result.

4. I have only tested this monitor on Windows Server 2008 R2. I don't know if it
works on other version of Windows Server.



