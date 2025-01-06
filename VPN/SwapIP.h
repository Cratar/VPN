#pragma once

using namespace System;
using namespace System::IO;
using namespace System::Text;


public ref class BatFileUpdater
{
public:
    static void UpdateBatFile(String^ filePath, String^ newIP)
    {
        if (!File::Exists(filePath))
        {
            Console::WriteLine("���� �� ������: " + filePath);
            return;
        }

        // ������ ���������� ���-�����
        String^ fileContent = File::ReadAllText(filePath, Encoding::UTF8);

        // ������ ������ ��� ������
        String^ searchString = "SET IP_Vpn_Connect=\"";
        String^ currentIP = ExtractIP(fileContent, searchString);
        if (currentIP == nullptr)
        {
            Console::WriteLine("�� ������� ����� ������ � IP_Vpn_Connect.");
            return;
        }

        // ����� ������ � IP
        String^ replacement = searchString + newIP + "\"";

        // ������ ������
        fileContent = fileContent->Replace(searchString + currentIP + "\"", replacement);

        // ���������� ������� � ���-����
        File::WriteAllText(filePath, fileContent, Encoding::UTF8);

        Console::WriteLine("IP ������� �������� ��: " + newIP);
    }

private:
    static String^ ExtractIP(String^ content, String^ searchString)
    {
        int start = content->IndexOf(searchString);
        if (start == -1)
            return nullptr;

        start += searchString->Length; // ��������� � ������ IP
        int end = content->IndexOf("\"", start);
        if (end == -1)
            return nullptr;

        return content->Substring(start, end - start);
    }
};

