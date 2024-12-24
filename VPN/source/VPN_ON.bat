@echo off

:: Проверить существование VPN-подключения
PowerShell -Command "[Console]::OutputEncoding = [System.Text.Encoding]::UTF8; if (!(Get-VpnConnection -Name 'L2TP_PS' -ErrorAction SilentlyContinue)) { Add-VpnConnection -Name 'L2TP_PS' -ServerAddress '219.100.37.117' -TunnelType 'L2tp' -L2tpPsk 'vpn' -Force -EncryptionLevel 'Required' -AuthenticationMethod MSChapv2 -SplitTunneling -RememberCredential -PassThru; Write-Host 'A VPN connection has been created.' } else { Write-Host  'The VPN connection already exists.' }"

:: Отключить Split Tunneling (если требуется)
PowerShell -Command "[Console]::OutputEncoding = [System.Text.Encoding]::UTF8; if (Get-VpnConnection -Name 'L2TP_PS' -ErrorAction SilentlyContinue) { Set-VpnConnection -Name 'L2TP_PS' -SplitTunneling $false -Force; Write-Host 'Split tunneling disabled.' }"

:: Подключение к VPN
PowerShell -Command "[Console]::OutputEncoding = [System.Text.Encoding]::UTF8; rasdial 'L2TP_PS' 'vpn' 'vpn'"

pause