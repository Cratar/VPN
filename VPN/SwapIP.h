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
            Console::WriteLine("Файл не найден: " + filePath);
            return;
        }

        // Читаем содержимое бат-файла
        String^ fileContent = File::ReadAllText(filePath, Encoding::UTF8);

        // Шаблон строки для поиска
        String^ searchString = "SET IP_Vpn_Connect=\"";
        String^ currentIP = ExtractIP(fileContent, searchString);
        if (currentIP == nullptr)
        {
            Console::WriteLine("Не удалось найти строку с IP_Vpn_Connect.");
            return;
        }

        // Новая строка с IP
        String^ replacement = searchString + newIP + "\"";

        // Замена строки
        fileContent = fileContent->Replace(searchString + currentIP + "\"", replacement);

        // Записываем обратно в бат-файл
        File::WriteAllText(filePath, fileContent, Encoding::UTF8);

        Console::WriteLine("IP успешно обновлен на: " + newIP);
    }

private:
    static String^ ExtractIP(String^ content, String^ searchString)
    {
        int start = content->IndexOf(searchString);
        if (start == -1)
            return nullptr;

        start += searchString->Length; // Смещаемся к началу IP
        int end = content->IndexOf("\"", start);
        if (end == -1)
            return nullptr;

        return content->Substring(start, end - start);
    }
};

