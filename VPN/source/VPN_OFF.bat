@echo off

SET nameVPN="VIPTOP"
PowerShell -Command "if(rasdial %nameVPN% /DISCONNECT) {Write-Host 'Disconnect_correct.'} else {Write-Host 'Disconnect_NOT_correct.'}" > VPN_OFF_LOG.txt

::pause