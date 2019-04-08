//
// Created by Yesterday17 on 4/8.
//

#include "folder.h"
namespace Week6_4 {

File::File(std::string fileName) {
  this->fileName = fileName;
  this->size = 0;
  this->lastModified = 1554707242733;
}

std::string File::FileName() {
  return this->fileName;
}

uint64_t File::Size() {
  return this->size;
}

uint64_t File::LastModified() {
  return this->lastModified;
}

uint8_t *File::Permission() {
  return this->permission;
}

Folder::Folder(std::string folderName) {
  this->folderName = folderName;
}

void Folder::AddFile(File *file) {
  this->files.push_back(file);
}

void Folder::AddFolder(Folder *folder) {
  this->subFolders.push_back(folder);
}

bool Folder::RemoveFile(File *file) {
  auto iter = this->files.begin();
  for (; iter != this->files.end(); iter++) {
    if (*iter == file) break;
  }
  if (iter != this->files.end()) {
    this->files.erase(iter);
    return true;
  } else {
    return false;
  }
}

bool Folder::RemoveFolder(Folder *folder) {
  auto iter = this->subFolders.begin();
  for (; iter != this->subFolders.end(); iter++) {
    if (*iter == folder) break;
  }
  if (iter != this->subFolders.end()) {
    this->subFolders.erase(iter);
    return true;
  } else {
    return false;
  }
}
}