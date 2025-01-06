@echo off

SET nameVPN="VIPTOP"
SET IP_Vpn_Connect="119.97.247.62"
SET nameUser="vpn"
SET password="vpn"
SET openKey="vpn" 
:: ^ Хер знает за что этот параметр отвечает , надо смотреть  119.97.247.62

:: Проверить существование VPN-подключения
PowerShell -Command "[Console]::OutputEncoding = [System.Text.Encoding]::UTF8; if (!(Get-VpnConnection -Name %nameVPN% -ErrorAction SilentlyContinue)) { Add-VpnConnection -Name %nameVPN% -ServerAddress %IP_Vpn_Connect% -TunnelType 'L2tp' -L2tpPsk %openKey% -Force -EncryptionLevel 'Required' -AuthenticationMethod MSChapv2 -SplitTunneling -RememberCredential -PassThru; Write-Host 'A_VPN_connection_has_been_created.' } else { Write-Host  'The_VPN_connection_already_exists.' }"

:: Отключить Split Tunneling (если требуется)
PowerShell -Command "[Console]::OutputEncoding = [System.Text.Encoding]::UTF8; if (Get-VpnConnection -Name %nameVPN% -ErrorAction SilentlyContinue) { Set-VpnConnection -Name %nameVPN% -SplitTunneling $false -Force; Write-Host 'Split_tunneling.' } else {Write-Host 'Split_tunneling_disabled.'}"

:: Подключение к VPN
PowerShell -Command "[Console]::OutputEncoding = [System.Text.Encoding]::UTF8;if (rasdial %nameVPN% %nameUser% %password%) {Write-Host 'Connection_correct.'} else{Write-Host 'Connection_disabled.'}">VPN_ON_LOG.txt

::pause