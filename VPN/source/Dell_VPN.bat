@echo off

:: ������� ��� �������� ����������� ��� ��������
SET  connectionName="VIPTOP" 

:: ��������� ������������� ����������� � ������� ���
PowerShell -Command "[Console]::OutputEncoding = [System.Text.Encoding]::UTF8; if (Get-VpnConnection -Name %connectionName% -ErrorAction SilentlyContinue) { Remove-VpnConnection -Name %connectionName% -Force; Write-Host '������� ����������� �������.' } else { Write-Host '������� ����������� �� �������.' }"

::pause
