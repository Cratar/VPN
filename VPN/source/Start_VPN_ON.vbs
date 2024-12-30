'Set objShell = CreateObject("WScript.Shell")
'objShell.Run "cmd /c VPN_OFF.bat", 0, True

set sh=CreateObject("Wscript.Shell")
sh.Run ".\\source\\VPN_ON.bat", 0
