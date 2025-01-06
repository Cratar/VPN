@echo off

:: Введите имя сетевого подключения для удаления
SET  connectionName="VIPTOP" 

:: Проверить существование подключения и удалить его
PowerShell -Command "[Console]::OutputEncoding = [System.Text.Encoding]::UTF8; if (Get-VpnConnection -Name %connectionName% -ErrorAction SilentlyContinue) { Remove-VpnConnection -Name %connectionName% -Force; Write-Host 'Сетевое подключение удалено.' } else { Write-Host 'Сетевое подключение не найдено.' }"

::pause
