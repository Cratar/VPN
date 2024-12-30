'WScript.Sleep 2000
'Set objShell = CreateObject("WScript.Shell")
'objShell.Run "cmd /c VPN_ON.bat", 0, True

set sh=CreateObject("Wscript.Shell")
sh.Run ".\\source\\VPN_OFF.bat", 0
