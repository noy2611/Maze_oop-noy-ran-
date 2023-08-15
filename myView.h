#pragma once
#include <iostream>
#include <filesystem>

#pragma once

namespace fs = std::filesystem;

class dirview
{
public:
    void displayFilesAndFolders(const std::string &path)
    {
        if (!fs::exists(path))
        {
            std::cout << "Path does not exist." << std::endl;
            return;
        }

        for (const auto &entry : fs::directory_iterator(path))
        {
            if (fs::is_directory(entry))
            {
                std::cout << "Folder: " << entry.path().filename().string() << std::endl;
            }
            else if (fs::is_regular_file(entry))
            {
                std::cout << "File: " << entry.path().filename().string() << std::endl;
            }
        }
    }
};
