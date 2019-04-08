//
// Created by t on 4/8.
//
#include <string>
#include <vector>
#include <stdint.h>

#ifndef OOPCLASSWORK_WEEK6_FOLDER_H
#define OOPCLASSWORK_WEEK6_FOLDER_H

namespace Week6_4 {
class File {
 private:
  std::string fileName; // file name
  uint64_t size = 0; // file size
  uint64_t lastModified = 0; // Timestamp of last modified
  uint8_t permission[3] = {7, 7, 7}; // permission such as 777

 public:
  File() = default;
  explicit File(std::string fileName);
  std::string FileName();
  uint64_t Size();
  uint64_t LastModified();
  uint8_t *Permission();
};

class Folder {
 private:
  std::string folderName;
  std::vector<Folder *> subFolders;
  std::vector<File *> files;
  bool shared = false;

 public:
  Folder() = default;
  explicit Folder(std::string folderName);
  void AddFile(File *file);
  void AddFolder(Folder *folder);
  bool RemoveFile(File *file);
  bool RemoveFolder(Folder *folder);
};
}

#endif //OOPCLASSWORK_WEEK6_FOLDER_H
